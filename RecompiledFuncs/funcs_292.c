#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _suautobaddies_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FB0: syscall     820
    recomp_syscall_handler(rdram, ctx, 0x80089FB0);
    return;
    // 0x80089FB4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gcmapsects_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F68: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F68);
    return;
    // 0x80087F6C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80020EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EC0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80020EC4: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x80020EC8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80020ECC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80020ED0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80020ED4: jr          $ra
    // 0x80020ED8: nop

    return;
    // 0x80020ED8: nop

;}
RECOMP_FUNC void func_8010D89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D89C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010D8A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8010D8A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8010D8A8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010D8AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8010D8B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010D8B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010D8B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010D8BC: addiu       $s2, $s2, 0x4730
    ctx->r18 = ADD32(ctx->r18, 0X4730);
    // 0x8010D8C0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8010D8C4: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
L_8010D8C8:
    // 0x8010D8C8: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8010D8CC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010D8D0: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x8010D8D4: blez        $t6, L_8010D904
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8010D8D8: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_8010D904;
    }
    // 0x8010D8D8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8010D8DC: addiu       $t8, $t8, 0x6F90
    ctx->r24 = ADD32(ctx->r24, 0X6F90);
    // 0x8010D8E0: addu        $s1, $t7, $t8
    ctx->r17 = ADD32(ctx->r15, ctx->r24);
L_8010D8E4:
    // 0x8010D8E4: jal         0x8010DA30
    // 0x8010D8E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010DA30(rdram, ctx);
        goto after_0;
    // 0x8010D8E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8010D8EC: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8010D8F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8010D8F4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8010D8F8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8010D8FC: bne         $at, $zero, L_8010D8E4
    if (ctx->r1 != 0) {
        // 0x8010D900: nop
    
            goto L_8010D8E4;
    }
    // 0x8010D900: nop

L_8010D904:
    // 0x8010D904: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8010D908: bne         $s3, $s4, L_8010D8C8
    if (ctx->r19 != ctx->r20) {
        // 0x8010D90C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8010D8C8;
    }
    // 0x8010D90C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8010D910: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010D914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010D918: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010D91C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8010D920: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010D924: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8010D928: jr          $ra
    // 0x8010D92C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010D92C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bsbanpackwhack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(37, 0X50C) << 16);
    // 0x808004A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004A8: jr          $ra
    // 0x808004AC: lw          $v0, 0x50C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(37, 0X50C));
    return;
    // 0x808004AC: lw          $v0, 0x50C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(37, 0X50C));
;}
RECOMP_FUNC void bsmum_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: jal         0x8009E6EC
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000AC: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x808000B0: bne         $v0, $at, L_80800114
    if (ctx->r2 != ctx->r1) {
        // 0x808000B4: nop
    
            goto L_80800114;
    }
    // 0x808000B4: nop

    // 0x808000B8: jal         0x8009E6F8
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C0: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x808000C4: beq         $v0, $at, L_808000E8
    if (ctx->r2 == ctx->r1) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E8;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x808000D0: beq         $v0, $at, L_808000E8
    if (ctx->r2 == ctx->r1) {
        // 0x808000D4: addiu       $at, $zero, 0xE7
        ctx->r1 = ADD32(0, 0XE7);
            goto L_808000E8;
    }
    // 0x808000D4: addiu       $at, $zero, 0xE7
    ctx->r1 = ADD32(0, 0XE7);
    // 0x808000D8: beq         $v0, $at, L_808000E8
    if (ctx->r2 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0xF7
        ctx->r1 = ADD32(0, 0XF7);
            goto L_808000E8;
    }
    // 0x808000DC: addiu       $at, $zero, 0xF7
    ctx->r1 = ADD32(0, 0XF7);
    // 0x808000E0: bne         $v0, $at, L_80800104
    if (ctx->r2 != ctx->r1) {
        // 0x808000E4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800104;
    }
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808000E8:
    // 0x808000E8: jal         0x8009E5C8
    // 0x808000EC: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808000EC: addiu       $a1, $zero, 0x11E
    ctx->r5 = ADD32(0, 0X11E);
    after_2:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x8009E830
    // 0x808000F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x808000F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000FC: b           L_80800120
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800120;
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800104:
    // 0x80800104: jal         0x8009E830
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E830(rdram, ctx);
        goto after_4;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080010C: b           L_80800120
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800120;
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800114:
    // 0x80800114: jal         0x80099B94
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_5;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800120:
    // 0x80800120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_80099A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A4C: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A50: jr          $ra
    // 0x80099A54: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    return;
    // 0x80099A54: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
;}
RECOMP_FUNC void bsbanshack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800420: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XCB0) << 16);
    // 0x80800424: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800428: jr          $ra
    // 0x8080042C: lw          $v0, 0xCB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCB0));
    return;
    // 0x8080042C: lw          $v0, 0xCB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCB0));
;}
RECOMP_FUNC void func_80800000_chlavatraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: bne         $a1, $at, L_80800024
    if (ctx->r5 != ctx->r1) {
        // 0x8080000C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800024;
    }
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $zero, 0x129
    ctx->r4 = ADD32(0, 0X129);
    // 0x80800014: jal         0x800887D8
    // 0x80800018: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_0:
    // 0x8080001C: b           L_8080002C
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080002C;
    // 0x80800020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800024:
    // 0x80800024: jal         0x80085820
    // 0x80800028: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800028: nop

    after_1:
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80800260_basquash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800264: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080026C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800270: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800274: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800278: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080027C: jal         0x80092AD8
    // 0x80800280: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    func_80092AD8(rdram, ctx);
        goto after_0;
    // 0x80800280: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    after_0:
    // 0x80800284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080028C: jal         0x800E0AF0
    // 0x80800290: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_1;
    // 0x80800290: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x80800294: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080029C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808002A0: lw          $t7, 0x11C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X11C);
    // 0x808002A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X644) << 16);
    // 0x808002A8: lwc1        $f4, 0x644($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X644));
    // 0x808002AC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002B0: lwc1        $f12, 0x8($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X8);
    // 0x808002B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808002B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808002BC: jal         0x800F1198
    // 0x808002C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1198(rdram, ctx);
        goto after_2;
    // 0x808002C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808002C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X648) << 16);
    // 0x808002C8: lwc1        $f14, 0x648($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(600, 0X648));
    // 0x808002CC: jal         0x800F0E00
    // 0x808002D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x808002D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x808002D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002DC: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808002E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808002E4: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808002E8: jal         0x80092B80
    // 0x808002EC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_80092B80(rdram, ctx);
        goto after_4;
    // 0x808002EC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x808002F0: slti        $at, $v0, 0x620
    ctx->r1 = SIGNED(ctx->r2) < 0X620 ? 1 : 0;
    // 0x808002F4: bne         $at, $zero, L_80800310
    if (ctx->r1 != 0) {
        // 0x808002F8: lwc1        $f0, 0x44($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80800310;
    }
    // 0x808002F8: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808002FC: addiu       $at, $zero, 0x83A
    ctx->r1 = ADD32(0, 0X83A);
    // 0x80800300: beql        $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800304: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800344;
    }
    goto skip_0;
    // 0x80800304: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_0:
    // 0x80800308: b           L_80800358
    // 0x8080030C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
        goto L_80800358;
    // 0x8080030C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
L_80800310:
    // 0x80800310: addiu       $t8, $v0, -0x607
    ctx->r24 = ADD32(ctx->r2, -0X607);
    // 0x80800314: sltiu       $at, $t8, 0x19
    ctx->r1 = ctx->r24 < 0X19 ? 1 : 0;
    // 0x80800318: beq         $at, $zero, L_80800354
    if (ctx->r1 == 0) {
        // 0x8080031C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800354;
    }
    // 0x8080031C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800320: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(600, 0X64C) << 16);
    // 0x80800324: addu        $at, $at, $t8
    gpr jr_addend_8080032C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800328: lw          $t8, 0x64C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(600, 0X64C));
    // 0x8080032C: jr          $t8
    // 0x80800330: nop

    switch (jr_addend_8080032C >> 2) {
        case 0: goto L_80800334; break;
        case 1: goto L_80800334; break;
        case 2: goto L_80800354; break;
        case 3: goto L_80800354; break;
        case 4: goto L_80800354; break;
        case 5: goto L_8080034C; break;
        case 6: goto L_80800354; break;
        case 7: goto L_80800354; break;
        case 8: goto L_80800354; break;
        case 9: goto L_80800354; break;
        case 10: goto L_80800354; break;
        case 11: goto L_80800354; break;
        case 12: goto L_80800354; break;
        case 13: goto L_80800354; break;
        case 14: goto L_80800354; break;
        case 15: goto L_80800354; break;
        case 16: goto L_80800354; break;
        case 17: goto L_80800354; break;
        case 18: goto L_80800354; break;
        case 19: goto L_80800354; break;
        case 20: goto L_80800354; break;
        case 21: goto L_80800340; break;
        case 22: goto L_80800354; break;
        case 23: goto L_80800354; break;
        case 24: goto L_80800334; break;
        default: switch_error(__func__, 0x8080032C, 0x8080064C);
    }
    // 0x80800330: nop

L_80800334:
    // 0x80800334: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800338: b           L_80800354
    // 0x8080033C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_80800354;
    // 0x8080033C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_80800340:
    // 0x80800340: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80800344:
    // 0x80800344: b           L_80800354
    // 0x80800348: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_80800354;
    // 0x80800348: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080034C:
    // 0x8080034C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800350: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80800354:
    // 0x80800354: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
L_80800358:
    // 0x80800358: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080035C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800360: lw          $t3, 0x11C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X11C);
    // 0x80800364: lbu         $v0, 0x2($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X2);
    // 0x80800368: beq         $v0, $at, L_80800380
    if (ctx->r2 == ctx->r1) {
        // 0x8080036C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800380;
    }
    // 0x8080036C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800370: beq         $v0, $at, L_808004A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800374: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: b           L_80800554
    // 0x8080037C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800554;
    // 0x8080037C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800380:
    // 0x80800380: beq         $t4, $zero, L_808003AC
    if (ctx->r12 == 0) {
        // 0x80800384: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_808003AC;
    }
    // 0x80800384: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80800388: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080038C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80800398: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080039C: jal         0x800E0B8C
    // 0x808003A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_5;
    // 0x808003A0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x808003A4: b           L_80800554
    // 0x808003A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800554;
    // 0x808003A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003AC:
    // 0x808003AC: beq         $t5, $zero, L_808003D8
    if (ctx->r13 == 0) {
        // 0x808003B0: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_808003D8;
    }
    // 0x808003B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808003B4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808003B8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    // 0x808003C4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003C8: jal         0x800E0B8C
    // 0x808003CC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_6;
    // 0x808003CC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x808003D0: b           L_80800554
    // 0x808003D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800554;
    // 0x808003D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003D8:
    // 0x808003D8: beq         $t6, $zero, L_80800444
    if (ctx->r14 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800444;
    }
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808003E4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003F0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003F4: jal         0x800E0B8C
    // 0x808003F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_7;
    // 0x808003F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x808003FC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800400: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800404: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80800410: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800414: jal         0x800E0B8C
    // 0x80800418: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_8;
    // 0x80800418: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8080041C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800420: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800424: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800430: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800434: jal         0x800E0B8C
    // 0x80800438: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_9;
    // 0x80800438: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x8080043C: b           L_80800554
    // 0x80800440: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800554;
    // 0x80800440: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800444:
    // 0x80800444: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800448: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8080044C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800450: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800454: jal         0x800E0B8C
    // 0x80800458: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_10;
    // 0x80800458: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8080045C: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800460: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800464: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80800470: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800474: jal         0x800E0B8C
    // 0x80800478: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_11;
    // 0x80800478: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8080047C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800480: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800484: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800490: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800494: jal         0x800E0B8C
    // 0x80800498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_12;
    // 0x80800498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x8080049C: b           L_80800554
    // 0x808004A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800554;
    // 0x808004A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808004A4:
    // 0x808004A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808004A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004AC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808004B0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808004B4: jal         0x800E0B8C
    // 0x808004B8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_13;
    // 0x808004B8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x808004BC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808004C0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: bne         $t7, $zero, L_808004D8
    if (ctx->r15 != 0) {
        // 0x808004CC: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_808004D8;
    }
    // 0x808004CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808004D0: beql        $t8, $zero, L_80800554
    if (ctx->r24 == 0) {
        // 0x808004D4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800554;
    }
    goto skip_1;
    // 0x808004D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_808004D8:
    // 0x808004D8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808004DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808004E0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x808004E4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808004E8: jal         0x800E0B8C
    // 0x808004EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_14;
    // 0x808004EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x808004F0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808004F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80800500: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800504: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800508: jal         0x800E0B8C
    // 0x8080050C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_15;
    // 0x8080050C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80800510: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800514: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800520: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800524: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800528: jal         0x800E0B8C
    // 0x8080052C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_16;
    // 0x8080052C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x80800530: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800534: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80800540: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800544: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800548: jal         0x800E0B8C
    // 0x8080054C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_17;
    // 0x8080054C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x80800550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800554:
    // 0x80800554: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800558: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080055C: jr          $ra
    // 0x80800560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800560: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _anseq_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082648: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082648);
    return;
    // 0x8008264C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800F554C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F554C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5554: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F555C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5560: jal         0x80092BDC
    // 0x800F5564: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80092BDC(rdram, ctx);
        goto after_0;
    // 0x800F5564: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F556C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5570: jr          $ra
    // 0x800F5574: nop

    return;
    // 0x800F5574: nop

;}
RECOMP_FUNC void glsavegame_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800660: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800664: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800668: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080066C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800670: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800674: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800678: jal         0x80800000
    // 0x8080067C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80800000_glsavegame(rdram, ctx);
        goto after_0;
    // 0x8080067C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800680: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800684: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800688: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8080068C: addiu       $s1, $s1, 0x7618
    ctx->r17 = ADD32(ctx->r17, 0X7618);
    // 0x80800690: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80800694: addu        $v1, $s1, $t8
    ctx->r3 = ADD32(ctx->r17, ctx->r24);
    // 0x80800698: lb          $t9, 0xC($v1)
    ctx->r25 = MEM_B(ctx->r3, 0XC);
    // 0x8080069C: lb          $t0, 0xF($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XF);
    // 0x808006A0: lb          $a0, 0xC($t7)
    ctx->r4 = MEM_B(ctx->r15, 0XC);
    // 0x808006A4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808006A8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x808006AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808006B0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x808006B4: jal         0x80800020
    // 0x808006B8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_80800020_glsavegame(rdram, ctx);
        goto after_1;
    // 0x808006B8: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_1:
    // 0x808006BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006C0: jal         0x80088580
    // 0x808006C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _glgamedata_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808006C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x808006C8: jal         0x808004B8
    // 0x808006CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_808004B8_glsavegame(rdram, ctx);
        goto after_3;
    // 0x808006CC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x808006D0: jal         0x80088578
    // 0x808006D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _glgamedata_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808006D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x808006D8: jal         0x808004C4
    // 0x808006DC: nop

    func_808004C4_glsavegame(rdram, ctx);
        goto after_5;
    // 0x808006DC: nop

    after_5:
    // 0x808006E0: bne         $s0, $zero, L_808006F4
    if (ctx->r16 != 0) {
        // 0x808006E4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808006F4;
    }
    // 0x808006E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808006E8: jal         0x808002E0
    // 0x808006EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808002E0_glsavegame(rdram, ctx);
        goto after_6;
    // 0x808006EC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x808006F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808006F4:
    // 0x808006F4: bne         $s0, $zero, L_80800708
    if (ctx->r16 != 0) {
        // 0x808006F8: nop
    
            goto L_80800708;
    }
    // 0x808006F8: nop

    // 0x808006FC: jal         0x8080036C
    // 0x80800700: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8080036C_glsavegame(rdram, ctx);
        goto after_7;
    // 0x80800700: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800704: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800708:
    // 0x80800708: bne         $s0, $zero, L_80800750
    if (ctx->r16 != 0) {
        // 0x8080070C: lw          $t1, 0x30($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X30);
            goto L_80800750;
    }
    // 0x8080070C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800710: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800714: sb          $t1, 0xC($t2)
    MEM_B(0XC, ctx->r10) = ctx->r9;
    // 0x80800718: lbu         $t4, 0x10($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X10);
    // 0x8080071C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800720: beq         $t4, $zero, L_80800750
    if (ctx->r12 == 0) {
        // 0x80800724: sb          $t3, 0xF($s1)
        MEM_B(0XF, ctx->r17) = ctx->r11;
            goto L_80800750;
    }
    // 0x80800724: sb          $t3, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r11;
    // 0x80800728: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8080072C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800730: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    // 0x80800734: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800738: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080073C: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80800740: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80800744: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80800748: jal         0x8001BBC8
    // 0x8080074C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    aligned4_memcpy(rdram, ctx);
        goto after_8;
    // 0x8080074C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_8:
L_80800750:
    // 0x80800750: jal         0x8001B084
    // 0x80800754: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    heap_free(rdram, ctx);
        goto after_9;
    // 0x80800754: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80800758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080075C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800764: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800768: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080076C: jr          $ra
    // 0x80800770: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800770: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800774: nop

    // 0x80800778: nop

    // 0x8080077C: nop

;}
RECOMP_FUNC void _idwibble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E88: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E88);
    return;
    // 0x80088E8C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800A9CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9CDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9CE0: addiu       $v0, $v0, 0x7760
    ctx->r2 = ADD32(ctx->r2, 0X7760);
    // 0x800A9CE4: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x800A9CE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A9CEC: bne         $t6, $zero, L_800A9CF8
    if (ctx->r14 != 0) {
        // 0x800A9CF0: nop
    
            goto L_800A9CF8;
    }
    // 0x800A9CF0: nop

    // 0x800A9CF4: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
L_800A9CF8:
    // 0x800A9CF8: jr          $ra
    // 0x800A9CFC: nop

    return;
    // 0x800A9CFC: nop

;}
RECOMP_FUNC void func_80802158_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802158: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8080215C: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(1480, 0X9EE4) << 16);
    // 0x80802160: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802164: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80802168: jr          $ra
    // 0x8080216C: lhu         $v0, -0x611C($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9EE4));
    return;
    // 0x8080216C: lhu         $v0, -0x611C($v0)
    ctx->r2 = MEM_HU(ctx->r2, (int16_t)RELOC_LO16(1480, 0X9EE4));
;}
RECOMP_FUNC void gcnewpause_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080010C: jal         0x800D2574
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D2574(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800114: jal         0x800C0438
    // 0x80800118: nop

    func_800C0438(rdram, ctx);
        goto after_1;
    // 0x80800118: nop

    after_1:
    // 0x8080011C: jal         0x800E8A68
    // 0x80800120: nop

    func_800E8A68(rdram, ctx);
        goto after_2;
    // 0x80800120: nop

    after_2:
    // 0x80800124: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80800128: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080012C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800130: beq         $at, $zero, L_80800484
    if (ctx->r1 == 0) {
        // 0x80800134: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800484;
    }
    // 0x80800134: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800138: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1F70) << 16);
    // 0x8080013C: addu        $at, $at, $t7
    gpr jr_addend_80800144 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800140: lw          $t7, 0x1F70($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1F70));
    // 0x80800144: jr          $t7
    // 0x80800148: nop

    switch (jr_addend_80800144 >> 2) {
        case 0: goto L_8080014C; break;
        case 1: goto L_80800160; break;
        case 2: goto L_808001D0; break;
        case 3: goto L_8080049C; break;
        case 4: goto L_80800434; break;
        default: switch_error(__func__, 0x80800144, 0x80801F70);
    }
    // 0x80800148: nop

L_8080014C:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x80800534
    // 0x80800154: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800534_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80800154: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800158: b           L_808004A0
    // 0x8080015C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
        goto L_808004A0;
    // 0x8080015C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80800160:
    // 0x80800160: jal         0x80015FA0
    // 0x80800164: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_80015FA0(rdram, ctx);
        goto after_4;
    // 0x80800164: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_4:
    // 0x80800168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080016C: bne         $v0, $at, L_80800188
    if (ctx->r2 != ctx->r1) {
        // 0x80800170: addiu       $a0, $s0, 0x30
        ctx->r4 = ADD32(ctx->r16, 0X30);
            goto L_80800188;
    }
    // 0x80800170: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80800174: jal         0x80087DC0
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_5;
    // 0x80800178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080017C: beql        $v0, $zero, L_8080018C
    if (ctx->r2 == 0) {
        // 0x80800180: addiu       $t8, $s0, 0x30
        ctx->r24 = ADD32(ctx->r16, 0X30);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800180: addiu       $t8, $s0, 0x30
    ctx->r24 = ADD32(ctx->r16, 0X30);
    skip_0:
    // 0x80800184: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
L_80800188:
    // 0x80800188: addiu       $t8, $s0, 0x30
    ctx->r24 = ADD32(ctx->r16, 0X30);
L_8080018C:
    // 0x8080018C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800190: lbu         $t9, 0xE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XE);
    // 0x80800194: beql        $t9, $zero, L_808001B8
    if (ctx->r25 == 0) {
        // 0x80800198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B8;
    }
    goto skip_1;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080019C: jal         0x800D9078
    // 0x808001A0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808001A0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_6:
    // 0x808001A4: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x808001A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80801E08
    // 0x808001B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80801E08_gcnewpause(rdram, ctx);
        goto after_7;
    // 0x808001B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_7:
L_808001B4:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001B8:
    // 0x808001B8: jal         0x80800E10
    // 0x808001BC: lb          $a1, 0x3($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X3);
    func_80800E10_gcnewpause(rdram, ctx);
        goto after_8;
    // 0x808001BC: lb          $a1, 0x3($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X3);
    after_8:
    // 0x808001C0: jal         0x80087C98
    // 0x808001C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808001C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808001C8: b           L_808004A0
    // 0x808001CC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
        goto L_808004A0;
    // 0x808001CC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_808001D0:
    // 0x808001D0: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x808001D4: jal         0x80016068
    // 0x808001D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80016068(rdram, ctx);
        goto after_10;
    // 0x808001D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x808001DC: jal         0x800D9078
    // 0x808001E0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    func_800D9078(rdram, ctx);
        goto after_11;
    // 0x808001E0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_11:
    // 0x808001E4: lbu         $v1, 0xF($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XF);
    // 0x808001E8: beq         $v1, $zero, L_80800208
    if (ctx->r3 == 0) {
        // 0x808001EC: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80800208;
    }
    // 0x808001EC: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x808001F0: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x808001F4: bne         $t1, $zero, L_80800208
    if (ctx->r9 != 0) {
        // 0x808001F8: sb          $t0, 0xF($s0)
        MEM_B(0XF, ctx->r16) = ctx->r8;
            goto L_80800208;
    }
    // 0x808001F8: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
    // 0x808001FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800200: jal         0x800880D8
    // 0x80800204: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800204: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_12:
L_80800208:
    // 0x80800208: lb          $t2, 0x7($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X7);
    // 0x8080020C: bnel        $t2, $zero, L_8080031C
    if (ctx->r10 != 0) {
        // 0x80800210: lb          $t6, 0x7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X7);
            goto L_8080031C;
    }
    goto skip_2;
    // 0x80800210: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    skip_2:
    // 0x80800214: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x80800218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080021C: bnel        $t3, $at, L_8080031C
    if (ctx->r11 != ctx->r1) {
        // 0x80800220: lb          $t6, 0x7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X7);
            goto L_8080031C;
    }
    goto skip_3;
    // 0x80800220: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    skip_3:
    // 0x80800224: jal         0x80015FA0
    // 0x80800228: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_80015FA0(rdram, ctx);
        goto after_13;
    // 0x80800228: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_13:
    // 0x8080022C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800230: bne         $v0, $at, L_8080024C
    if (ctx->r2 != ctx->r1) {
        // 0x80800234: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080024C;
    }
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x808015F8
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808015F8_gcnewpause(rdram, ctx);
        goto after_14;
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800244: b           L_8080031C
    // 0x80800248: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
        goto L_8080031C;
    // 0x80800248: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
L_8080024C:
    // 0x8080024C: jal         0x80016B30
    // 0x80800250: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_80016B30(rdram, ctx);
        goto after_15;
    // 0x80800250: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_15:
    // 0x80800254: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800258: bne         $v0, $at, L_80800270
    if (ctx->r2 != ctx->r1) {
        // 0x8080025C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x808015F8
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808015F8_gcnewpause(rdram, ctx);
        goto after_16;
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800268: b           L_8080031C
    // 0x8080026C: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
        goto L_8080031C;
    // 0x8080026C: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
L_80800270:
    // 0x80800270: lbu         $t4, 0x1E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E);
    // 0x80800274: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800278: lui         $at, 0xBF40
    ctx->r1 = S32(0XBF40 << 16);
    // 0x8080027C: beql        $t4, $zero, L_808002CC
    if (ctx->r12 == 0) {
        // 0x80800280: lbu         $t5, 0x1F($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1F);
            goto L_808002CC;
    }
    goto skip_4;
    // 0x80800280: lbu         $t5, 0x1F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F);
    skip_4:
    // 0x80800284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800288: nop

    // 0x8080028C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800290: nop

    // 0x80800294: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x80800298: lbu         $t5, 0x1F($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1F);
            goto L_808002CC;
    }
    goto skip_5;
    // 0x80800298: lbu         $t5, 0x1F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F);
    skip_5:
    // 0x8080029C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808002A0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808002AC: nop

    // 0x808002B0: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x808002B4: lbu         $t5, 0x1F($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1F);
            goto L_808002CC;
    }
    goto skip_6;
    // 0x808002B4: lbu         $t5, 0x1F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F);
    skip_6:
    // 0x808002B8: jal         0x8080162C
    // 0x808002BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8080162C_gcnewpause(rdram, ctx);
        goto after_17;
    // 0x808002BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_17:
    // 0x808002C0: b           L_8080031C
    // 0x808002C4: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
        goto L_8080031C;
    // 0x808002C4: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    // 0x808002C8: lbu         $t5, 0x1F($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F);
L_808002CC:
    // 0x808002CC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808002D0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808002D4: beql        $t5, $zero, L_8080031C
    if (ctx->r13 == 0) {
        // 0x808002D8: lb          $t6, 0x7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X7);
            goto L_8080031C;
    }
    goto skip_7;
    // 0x808002D8: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    skip_7:
    // 0x808002DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002E0: nop

    // 0x808002E4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1fl       L_8080031C
    if (!c1cs) {
        // 0x808002F0: lb          $t6, 0x7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X7);
            goto L_8080031C;
    }
    goto skip_8;
    // 0x808002F0: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    skip_8:
    // 0x808002F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800304: nop

    // 0x80800308: bc1fl       L_8080031C
    if (!c1cs) {
        // 0x8080030C: lb          $t6, 0x7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X7);
            goto L_8080031C;
    }
    goto skip_9;
    // 0x8080030C: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
    skip_9:
    // 0x80800310: jal         0x8080162C
    // 0x80800314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080162C_gcnewpause(rdram, ctx);
        goto after_18;
    // 0x80800314: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800318: lb          $t6, 0x7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X7);
L_8080031C:
    // 0x8080031C: lb          $v0, 0x3($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X3);
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: bne         $t6, $zero, L_8080033C
    if (ctx->r14 != 0) {
        // 0x80800328: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8080033C;
    }
    // 0x80800328: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080032C: bnel        $v0, $at, L_80800340
    if (ctx->r2 != ctx->r1) {
        // 0x80800330: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80800340;
    }
    goto skip_10;
    // 0x80800330: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    skip_10:
    // 0x80800334: b           L_80800340
    // 0x80800338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800340;
    // 0x80800338: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8080033C:
    // 0x8080033C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80800340:
    // 0x80800340: jal         0x80801330
    // 0x80800344: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_80801330_gcnewpause(rdram, ctx);
        goto after_19;
    // 0x80800344: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_19:
    // 0x80800348: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080034C: jal         0x80801580
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801580_gcnewpause(rdram, ctx);
        goto after_20;
    // 0x80800350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x8080035C: jal         0x80800F2C
    // 0x80800360: lb          $a2, 0x3($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X3);
    func_80800F2C_gcnewpause(rdram, ctx);
        goto after_21;
    // 0x80800360: lb          $a2, 0x3($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X3);
    after_21:
    // 0x80800364: lb          $t7, 0x7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X7);
    // 0x80800368: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080036C: bne         $t7, $zero, L_808003AC
    if (ctx->r15 != 0) {
        // 0x80800370: nop
    
            goto L_808003AC;
    }
    // 0x80800370: nop

    // 0x80800374: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x80800378: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080037C: bne         $t8, $at, L_808003AC
    if (ctx->r24 != ctx->r1) {
        // 0x80800380: nop
    
            goto L_808003AC;
    }
    // 0x80800380: nop

    // 0x80800384: bne         $v0, $zero, L_808003AC
    if (ctx->r2 != 0) {
        // 0x80800388: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_808003AC;
    }
    // 0x80800388: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080038C: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x80800390: sb          $zero, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = 0;
    // 0x80800394: sb          $zero, 0x1E($s0)
    MEM_B(0X1E, ctx->r16) = 0;
    // 0x80800398: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080039C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x808003A0: jal         0x800880D8
    // 0x808003A4: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x808003A4: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    after_22:
    // 0x808003A8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_808003AC:
    // 0x808003AC: bne         $v1, $zero, L_8080049C
    if (ctx->r3 != 0) {
        // 0x808003B0: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8080049C;
    }
    // 0x808003B0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808003B4: bnel        $t0, $zero, L_808004A0
    if (ctx->r8 != 0) {
        // 0x808003B8: lbu         $v0, 0x2($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X2);
            goto L_808004A0;
    }
    goto skip_11;
    // 0x808003B8: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    skip_11:
    // 0x808003BC: lb          $a1, 0x7($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X7);
    // 0x808003C0: beql        $a1, $zero, L_8080040C
    if (ctx->r5 == 0) {
        // 0x808003C4: lbu         $t2, 0x4($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X4);
            goto L_8080040C;
    }
    goto skip_12;
    // 0x808003C4: lbu         $t2, 0x4($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4);
    skip_12:
    // 0x808003C8: jal         0x80801718
    // 0x808003CC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    func_80801718_gcnewpause(rdram, ctx);
        goto after_23;
    // 0x808003CC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    after_23:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x808017C8
    // 0x808003D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808017C8_gcnewpause(rdram, ctx);
        goto after_24;
    // 0x808003D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_24:
    // 0x808003DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808003E0: sb          $zero, 0x7($s0)
    MEM_B(0X7, ctx->r16) = 0;
    // 0x808003E4: sb          $t1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r9;
    // 0x808003E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1F84) << 16);
    // 0x808003EC: lwc1        $f8, 0x1F84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1F84));
    // 0x808003F0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808003F4: addiu       $a1, $zero, 0x4650
    ctx->r5 = ADD32(0, 0X4650);
    // 0x808003F8: jal         0x800880D8
    // 0x808003FC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x808003FC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_25:
    // 0x80800400: b           L_808004A0
    // 0x80800404: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
        goto L_808004A0;
    // 0x80800404: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80800408: lbu         $t2, 0x4($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X4);
L_8080040C:
    // 0x8080040C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: beq         $t2, $zero, L_80800424
    if (ctx->r10 == 0) {
        // 0x80800418: nop
    
            goto L_80800424;
    }
    // 0x80800418: nop

    // 0x8080041C: b           L_8080049C
    // 0x80800420: sb          $t3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r11;
        goto L_8080049C;
    // 0x80800420: sb          $t3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r11;
L_80800424:
    // 0x80800424: jal         0x80800534
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800534_gcnewpause(rdram, ctx);
        goto after_26;
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x8080042C: b           L_808004A0
    // 0x80800430: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
        goto L_808004A0;
    // 0x80800430: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80800434:
    // 0x80800434: jal         0x80801CDC
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CDC_gcnewpause(rdram, ctx);
        goto after_27;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080043C: jal         0x800D9078
    // 0x80800440: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    func_800D9078(rdram, ctx);
        goto after_28;
    // 0x80800440: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_28:
    // 0x80800444: beq         $v0, $zero, L_8080049C
    if (ctx->r2 == 0) {
        // 0x80800448: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_8080049C;
    }
    // 0x80800448: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8080044C: sh          $zero, 0x2C($s0)
    MEM_H(0X2C, ctx->r16) = 0;
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800454: jal         0x800FCAE0
    // 0x80800458: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    func_800FCAE0(rdram, ctx);
        goto after_29;
    // 0x80800458: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    after_29:
    // 0x8080045C: jal         0x800FCA90
    // 0x80800460: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800FCA90(rdram, ctx);
        goto after_30;
    // 0x80800460: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_30:
    // 0x80800464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800468: jal         0x800A7AD4
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A7AD4(rdram, ctx);
        goto after_31;
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80800470: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800474: jal         0x80088198
    // 0x80800478: sb          $t4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r12;
    _gcfrontend_entrypoint_13(rdram, ctx);
        goto after_32;
    // 0x80800478: sb          $t4, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r12;
    after_32:
    // 0x8080047C: b           L_808004A0
    // 0x80800480: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
        goto L_808004A0;
    // 0x80800480: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_80800484:
    // 0x80800484: jal         0x80015FA0
    // 0x80800488: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_80015FA0(rdram, ctx);
        goto after_33;
    // 0x80800488: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_33:
    // 0x8080048C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800490: bne         $v0, $at, L_8080049C
    if (ctx->r2 != ctx->r1) {
        // 0x80800494: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8080049C;
    }
    // 0x80800494: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800498: sb          $t5, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r13;
L_8080049C:
    // 0x8080049C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_808004A0:
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004A8: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808004AC: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808004B0: jr          $ra
    // 0x808004B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808004B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80100D24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100D24: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80100D28: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80100D2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80100D30: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80100D34: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80100D38: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80100D3C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80100D40: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80100D44: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80100D48: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80100D4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100D50: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80100D54: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80100D58: jal         0x80100690
    // 0x80100D5C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_80100690(rdram, ctx);
        goto after_0;
    // 0x80100D5C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x80100D60: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80100D64: jal         0x800B2840
    // 0x80100D68: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800B2840(rdram, ctx);
        goto after_1;
    // 0x80100D68: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80100D6C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80100D70: sll         $s5, $s4, 2
    ctx->r21 = S32(ctx->r20 << 2);
    // 0x80100D74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80100D78: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80100D7C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80100D80:
    // 0x80100D80: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80100D84: beq         $at, $zero, L_80100DA8
    if (ctx->r1 == 0) {
        // 0x80100D88: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80100DA8;
    }
    // 0x80100D88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80100D8C: jal         0x800B2400
    // 0x80100D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800B2400(rdram, ctx);
        goto after_2;
    // 0x80100D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80100D94: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80100D98: lbu         $t7, 0x17($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17);
    // 0x80100D9C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80100DA0: b           L_80100DAC
    // 0x80100DA4: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
        goto L_80100DAC;
    // 0x80100DA4: sb          $t8, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r24;
L_80100DA8:
    // 0x80100DA8: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80100DAC:
    // 0x80100DAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80100DB0: bne         $s0, $s2, L_80100D80
    if (ctx->r16 != ctx->r18) {
        // 0x80100DB4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80100D80;
    }
    // 0x80100DB4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80100DB8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80100DBC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80100DC0: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80100DC4: beq         $t9, $zero, L_80100DDC
    if (ctx->r25 == 0) {
        // 0x80100DC8: lw          $a2, 0x68($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X68);
            goto L_80100DDC;
    }
    // 0x80100DC8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80100DCC: jal         0x801007B8
    // 0x80100DD0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    func_801007B8(rdram, ctx);
        goto after_3;
    // 0x80100DD0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    after_3:
    // 0x80100DD4: b           L_80100DE0
    // 0x80100DD8: sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
        goto L_80100DE0;
    // 0x80100DD8: sb          $v0, 0x8($s6)
    MEM_B(0X8, ctx->r22) = ctx->r2;
L_80100DDC:
    // 0x80100DDC: sb          $zero, 0x8($s6)
    MEM_B(0X8, ctx->r22) = 0;
L_80100DE0:
    // 0x80100DE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80100DE4: sb          $t0, 0x9($s6)
    MEM_B(0X9, ctx->r22) = ctx->r8;
    // 0x80100DE8: sb          $zero, 0xA($s6)
    MEM_B(0XA, ctx->r22) = 0;
    // 0x80100DEC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80100DF0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80100DF4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80100DF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80100DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80100E00: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80100E04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80100E08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100E0C: lh          $v0, 0x52($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X52);
    // 0x80100E10: jr          $ra
    // 0x80100E14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80100E14: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _chshockjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857A0: syscall     174
    recomp_syscall_handler(rdram, ctx, 0x800857A0);
    return;
    // 0x800857A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800134_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: jal         0x8009EF1C
    // 0x80800140: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800144: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800148: jal         0x8009EF10
    // 0x8080014C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080014C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800150: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x80800154: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080016C;
    }
    // 0x80800154: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800158: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080015C: beq         $v0, $at, L_8080017C
    if (ctx->r2 == ctx->r1) {
        // 0x80800160: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_8080017C;
    }
    // 0x80800160: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: b           L_8080019C
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080019C;
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080016C:
    // 0x8080016C: jal         0x8009B9B0
    // 0x80800170: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800170: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800174: b           L_8080019C
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080019C;
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080017C:
    // 0x8080017C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800180: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800184: jal         0x800F1214
    // 0x80800188: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800188: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_3:
    // 0x8080018C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800190: jal         0x8009B9B0
    // 0x80800194: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800194: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080019C:
    // 0x8080019C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_8008D8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D8EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D8F0: jal         0x800C6E38
    // 0x8008D8F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D8F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x8008D8F8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D8FC: beq         $t6, $zero, L_8008D914
    if (ctx->r14 == 0) {
        // 0x8008D900: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D914;
    }
    // 0x8008D900: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D904: jal         0x800A3304
    // 0x8008D908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D90C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D910: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D914:
    // 0x8008D914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D91C: jr          $ra
    // 0x8008D920: nop

    return;
    // 0x8008D920: nop

;}
RECOMP_FUNC void chbeehive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1664, 0X374) << 16);
    // 0x808002E0: jr          $ra
    // 0x808002E4: addiu       $v0, $v0, 0x374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1664, 0X374));
    return;
    // 0x808002E4: addiu       $v0, $v0, 0x374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1664, 0X374));
    // 0x808002E8: nop

    // 0x808002EC: nop

;}
RECOMP_FUNC void func_80108A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80108A34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80108A38: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80108A3C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80108A40: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80108A44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80108A48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80108A4C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80108A50: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80108A54: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80108A58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80108A5C: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80108A60: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80108A64: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108A68: addiu       $a0, $a0, -0x7574
    ctx->r4 = ADD32(ctx->r4, -0X7574);
    // 0x80108A6C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80108A70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80108A74: jal         0x80086D58
    // 0x80108A78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80108A78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80108A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80108A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80108A84: jr          $ra
    // 0x80108A88: nop

    return;
    // 0x80108A88: nop

;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083080: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083080);
    return;
    // 0x80083084: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chanim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800050: jal         0x80106790
    // 0x80800054: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800054: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080005C: jal         0x80100094
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800064: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800070: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800074: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_8008D850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008D854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D858: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008D85C: jal         0x800C6E38
    // 0x8008D860: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D860: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_0:
    // 0x8008D864: beql        $v0, $zero, L_8008D8D4
    if (ctx->r2 == 0) {
        // 0x8008D868: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008D8D4;
    }
    goto skip_0;
    // 0x8008D868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8008D86C: jal         0x800A3304
    // 0x8008D870: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D870: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8008D874: beql        $v0, $zero, L_8008D8D4
    if (ctx->r2 == 0) {
        // 0x8008D878: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008D8D4;
    }
    goto skip_1;
    // 0x8008D878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8008D87C: jal         0x80084CA0
    // 0x8008D880: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _bafpctrl_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8008D880: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8008D884: bne         $v0, $zero, L_8008D8D0
    if (ctx->r2 != 0) {
        // 0x8008D888: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8008D8D0;
    }
    // 0x8008D888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008D88C: jal         0x8009C128
    // 0x8008D890: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8008D890: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8008D894: jal         0x800EA05C
    // 0x8008D898: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x8008D898: nop

    after_4:
    // 0x8008D89C: addiu       $at, $zero, 0x117
    ctx->r1 = ADD32(0, 0X117);
    // 0x8008D8A0: bne         $v0, $at, L_8008D8C8
    if (ctx->r2 != ctx->r1) {
        // 0x8008D8A4: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8008D8C8;
    }
    // 0x8008D8A4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8008D8A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008D8AC: lwc1        $f6, 0x4AD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4AD4);
    // 0x8008D8B0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8008D8B4: nop

    // 0x8008D8B8: bc1f        L_8008D8C8
    if (!c1cs) {
        // 0x8008D8BC: nop
    
            goto L_8008D8C8;
    }
    // 0x8008D8BC: nop

    // 0x8008D8C0: b           L_8008D8D4
    // 0x8008D8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008D8D4;
    // 0x8008D8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D8C8:
    // 0x8008D8C8: b           L_8008D8D4
    // 0x8008D8CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008D8D4;
    // 0x8008D8CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008D8D0:
    // 0x8008D8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008D8D4:
    // 0x8008D8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D8D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008D8DC: jr          $ra
    // 0x8008D8E0: nop

    return;
    // 0x8008D8E0: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F8C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800F90: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X19E0) << 16);
    // 0x80800F94: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F98: jr          $ra
    // 0x80800F9C: lw          $v0, 0x19E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19E0));
    return;
    // 0x80800F9C: lw          $v0, 0x19E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X19E0));
;}
RECOMP_FUNC void func_80804420_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804420: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804424: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804428: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080442C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804430: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80804434: jal         0x80100094
    // 0x80804438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080443C: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x80804440: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80804444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804448: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8080444C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80804450: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x80804454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804458: jal         0x8010A590
    // 0x8080445C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x8080445C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80804460: jal         0x80089AB0
    // 0x80804464: nop

    _sukickball_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80804464: nop

    after_2:
    // 0x80804468: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8080446C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80804470: bne         $t9, $at, L_808044B4
    if (ctx->r25 != ctx->r1) {
        // 0x80804474: sb          $v0, 0x14($s1)
        MEM_B(0X14, ctx->r17) = ctx->r2;
            goto L_808044B4;
    }
    // 0x80804474: sb          $v0, 0x14($s1)
    MEM_B(0X14, ctx->r17) = ctx->r2;
    // 0x80804478: jal         0x80088368
    // 0x8080447C: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080447C: nop

    after_3:
    // 0x80804480: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80804484: andi        $t0, $v1, 0x1FF
    ctx->r8 = ctx->r3 & 0X1FF;
    // 0x80804488: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x8080448C: beq         $at, $zero, L_808044B4
    if (ctx->r1 == 0) {
        // 0x80804490: nop
    
            goto L_808044B4;
    }
    // 0x80804490: nop

    // 0x80804494: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
    // 0x80804498: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x8080449C: andi        $t6, $t5, 0x18
    ctx->r14 = ctx->r13 & 0X18;
    // 0x808044A0: ori         $t7, $t2, 0x20
    ctx->r15 = ctx->r10 | 0X20;
    // 0x808044A4: andi        $t8, $t7, 0xE7
    ctx->r24 = ctx->r15 & 0XE7;
    // 0x808044A8: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
    // 0x808044AC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808044B0: sb          $t9, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r25;
L_808044B4:
    // 0x808044B4: jal         0x800BD0DC
    // 0x808044B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BD0DC(rdram, ctx);
        goto after_4;
    // 0x808044B8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x808044BC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x808044C0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808044C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808044C8: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x808044CC: jal         0x800BD268
    // 0x808044D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800BD268(rdram, ctx);
        goto after_5;
    // 0x808044D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_5:
    // 0x808044D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808044D8: jal         0x800BD28C
    // 0x808044DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BD28C(rdram, ctx);
        goto after_6;
    // 0x808044DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808044E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808044E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808044E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808044EC: jr          $ra
    // 0x808044F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808044F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void idworld_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: jal         0x80800000
    // 0x808000B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800000_idworld(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x808000B4: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000C4;
    }
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
        goto L_808000C8;
    // 0x808000C0: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
L_808000C4:
    // 0x808000C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000C8:
    // 0x808000C8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000CC: jr          $ra
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800CA174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA174: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CA178: lw          $a0, -0x54A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X54A0);
    // 0x800CA17C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA184: beql        $a0, $zero, L_800CA1A0
    if (ctx->r4 == 0) {
        // 0x800CA188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CA1A0;
    }
    goto skip_0;
    // 0x800CA188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CA18C: jal         0x800B2F58
    // 0x800CA190: nop

    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800CA190: nop

    after_0:
    // 0x800CA194: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CA198: sw          $v0, -0x54A0($at)
    MEM_W(-0X54A0, ctx->r1) = ctx->r2;
    // 0x800CA19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CA1A0:
    // 0x800CA1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA1A4: jr          $ra
    // 0x800CA1A8: nop

    return;
    // 0x800CA1A8: nop

    // 0x800CA1AC: nop

;}
RECOMP_FUNC void _bsstatue_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BC0: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BC0);
    return;
    // 0x80083BC4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800A72A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A72A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A72A8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A72AC: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x800A72B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A72B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A72B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A72BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A72C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A72C4: jal         0x80088268
    // 0x800A72C8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800A72C8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x800A72CC: jal         0x800E96E0
    // 0x800A72D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800E96E0(rdram, ctx);
        goto after_1;
    // 0x800A72D0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A72D4: jal         0x80088250
    // 0x800A72D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcsectionDll_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x800A72D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800A72DC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800A72E0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800A72E4: bne         $t7, $zero, L_800A7300
    if (ctx->r15 != 0) {
        // 0x800A72E8: nop
    
            goto L_800A7300;
    }
    // 0x800A72E8: nop

    // 0x800A72EC: bne         $t8, $zero, L_800A7300
    if (ctx->r24 != 0) {
        // 0x800A72F0: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_800A7300;
    }
    // 0x800A72F0: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800A72F4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800A72F8: beql        $t9, $t0, L_800A7334
    if (ctx->r25 == ctx->r8) {
        // 0x800A72FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A7334;
    }
    goto skip_0;
    // 0x800A72FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_800A7300:
    // 0x800A7300: jal         0x80088228
    // 0x800A7304: nop

    _gclevel_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x800A7304: nop

    after_3:
    // 0x800A7308: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800A730C: beql        $t1, $zero, L_800A7328
    if (ctx->r9 == 0) {
        // 0x800A7310: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A7328;
    }
    goto skip_1;
    // 0x800A7310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x800A7314: jal         0x80087A48
    // 0x800A7318: nop

    _gcgame_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x800A7318: nop

    after_4:
    // 0x800A731C: jal         0x80087A40
    // 0x800A7320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcgame_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x800A7320: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800A7324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800A7328:
    // 0x800A7328: jal         0x80088220
    // 0x800A732C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gclevel_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x800A732C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x800A7330: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800A7334:
    // 0x800A7334: jal         0x80088248
    // 0x800A7338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _gcsectionDll_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x800A7338: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x800A733C: jal         0x801101C0
    // 0x800A7340: nop

    func_801101C0(rdram, ctx);
        goto after_8;
    // 0x800A7340: nop

    after_8:
    // 0x800A7344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A7348: jal         0x800A8D70
    // 0x800A734C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A8D70(rdram, ctx);
        goto after_9;
    // 0x800A734C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x800A7350: jal         0x80081724
    // 0x800A7354: nop

    func_80081724(rdram, ctx);
        goto after_10;
    // 0x800A7354: nop

    after_10:
    // 0x800A7358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A735C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A7360: jal         0x800EA0CC
    // 0x800A7364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800EA0CC(rdram, ctx);
        goto after_11;
    // 0x800A7364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800A7368: jal         0x800A718C
    // 0x800A736C: nop

    func_800A718C(rdram, ctx);
        goto after_12;
    // 0x800A736C: nop

    after_12:
    // 0x800A7370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7374: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7378: jr          $ra
    // 0x800A737C: nop

    return;
    // 0x800A737C: nop

;}
RECOMP_FUNC void func_80094644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094648: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009464C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094650: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80094654: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80094658: jal         0x80094370
    // 0x8009465C: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    func_80094370(rdram, ctx);
        goto after_0;
    // 0x8009465C: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    after_0:
    // 0x80094660: jal         0x8009E964
    // 0x80094664: nop

    func_8009E964(rdram, ctx);
        goto after_1;
    // 0x80094664: nop

    after_1:
    // 0x80094668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009466C: jal         0x80094574
    // 0x80094670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80094574(rdram, ctx);
        goto after_2;
    // 0x80094670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80094674: jal         0x8009E970
    // 0x80094678: nop

    func_8009E970(rdram, ctx);
        goto after_3;
    // 0x80094678: nop

    after_3:
    // 0x8009467C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80094680: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80094684: nop

    // 0x80094688: beql        $v1, $zero, L_800946AC
    if (ctx->r3 == 0) {
        // 0x8009468C: lw          $t8, 0x64($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X64);
            goto L_800946AC;
    }
    goto skip_0;
    // 0x8009468C: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80094690: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80094694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094698: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009469C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800946A0: jal         0x80094430
    // 0x800946A4: nop

    func_80094430(rdram, ctx);
        goto after_4;
    // 0x800946A4: nop

    after_4:
    // 0x800946A8: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
L_800946AC:
    // 0x800946AC: sb          $zero, 0x3($t8)
    MEM_B(0X3, ctx->r24) = 0;
    // 0x800946B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800946B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800946B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800946BC: jr          $ra
    // 0x800946C0: nop

    return;
    // 0x800946C0: nop

;}
RECOMP_FUNC void func_800C90F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C90F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C90F8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C90FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9100: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C9104: jal         0x80087E98
    // 0x800C9108: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    _gclightsDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800C9108: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    after_0:
    // 0x800C910C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9114: jr          $ra
    // 0x800C9118: nop

    return;
    // 0x800C9118: nop

;}
RECOMP_FUNC void func_8080000C_chdoubloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80800074
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    chdoubloon_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: jal         0x80103110
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_800D8808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8808: beq         $a0, $zero, L_800D8830
    if (ctx->r4 == 0) {
        // 0x800D880C: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800D8830;
    }
    // 0x800D880C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D8810: lw          $t6, -0x3FEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3FEC);
    // 0x800D8814: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800D8818: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800D881C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D8820: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D8824: lb          $t8, -0xC($v0)
    ctx->r24 = MEM_B(ctx->r2, -0XC);
    // 0x800D8828: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x800D882C: sb          $t9, -0xC($v0)
    MEM_B(-0XC, ctx->r2) = ctx->r25;
L_800D8830:
    // 0x800D8830: jr          $ra
    // 0x800D8834: nop

    return;
    // 0x800D8834: nop

    // 0x800D8838: nop

    // 0x800D883C: nop

;}
RECOMP_FUNC void func_80800CC8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80800CCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CD4: jal         0x801022E4
    // 0x80800CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800CDC: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    // 0x80800CE0: jal         0x80101F24
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800CE8: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80800CEC: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80800CF0: sw          $zero, 0x94($sp)
    MEM_W(0X94, ctx->r29) = 0;
    // 0x80800CF4: addiu       $t7, $t6, -0x2CD
    ctx->r15 = ADD32(ctx->r14, -0X2CD);
    // 0x80800CF8: sltiu       $at, $t7, 0x16
    ctx->r1 = ctx->r15 < 0X16 ? 1 : 0;
    // 0x80800CFC: beq         $at, $zero, L_8080114C
    if (ctx->r1 == 0) {
        // 0x80800D00: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080114C;
    }
    // 0x80800D00: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800D04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1096, 0X17A0) << 16);
    // 0x80800D08: addu        $at, $at, $t7
    gpr jr_addend_80800D10 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800D0C: lw          $t7, 0x17A0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1096, 0X17A0));
    // 0x80800D10: jr          $t7
    // 0x80800D14: nop

    switch (jr_addend_80800D10 >> 2) {
        case 0: goto L_80800D18; break;
        case 1: goto L_80800E44; break;
        case 2: goto L_80800DB0; break;
        case 3: goto L_80800EC8; break;
        case 4: goto L_80800EC8; break;
        case 5: goto L_80800EC8; break;
        case 6: goto L_80800FD4; break;
        case 7: goto L_80800FB0; break;
        case 8: goto L_8080114C; break;
        case 9: goto L_80800F6C; break;
        case 10: goto L_8080114C; break;
        case 11: goto L_8080114C; break;
        case 12: goto L_8080114C; break;
        case 13: goto L_8080114C; break;
        case 14: goto L_8080114C; break;
        case 15: goto L_8080114C; break;
        case 16: goto L_8080114C; break;
        case 17: goto L_8080114C; break;
        case 18: goto L_8080114C; break;
        case 19: goto L_8080114C; break;
        case 20: goto L_80801110; break;
        case 21: goto L_80800FF8; break;
        default: switch_error(__func__, 0x80800D10, 0x808017A0);
    }
    // 0x80800D14: nop

L_80800D18:
    // 0x80800D18: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800D1C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800D20: jal         0x80101E14
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800D28: beq         $v0, $zero, L_80800DA4
    if (ctx->r2 == 0) {
        // 0x80800D2C: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800DA4;
    }
    // 0x80800D2C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800D30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800D34: jal         0x8008A0E0
    // 0x80800D38: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800D38: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    after_3:
    // 0x80800D3C: beq         $v0, $zero, L_80800D90
    if (ctx->r2 == 0) {
        // 0x80800D40: addiu       $a0, $sp, 0x7C
        ctx->r4 = ADD32(ctx->r29, 0X7C);
            goto L_80800D90;
    }
    // 0x80800D40: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80800D44: jal         0x800EE7F8
    // 0x80800D48: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800D48: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    after_4:
    // 0x80800D4C: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80800D50: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800D54: jal         0x800EF1B8
    // 0x80800D58: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x80800D58: lui         $a2, 0xC248
    ctx->r6 = S32(0XC248 << 16);
    after_5:
    // 0x80800D5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800D60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D64: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800D68: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1096, 0X1BC0) << 16);
    // 0x80800D6C: addiu       $t8, $t8, 0x1BC0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1096, 0X1BC0));
    // 0x80800D70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800D74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D7C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80800D80: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80800D84: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x80800D88: jal         0x800BABB8
    // 0x80800D8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800D8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
L_80800D90:
    // 0x80800D90: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1CA0) << 16);
    // 0x80800D94: addiu       $a2, $a2, 0x1CA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1CA0));
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D9C: jal         0x80089D18
    // 0x80800DA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800DA0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
L_80800DA4:
    // 0x80800DA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800DA8: b           L_8080114C
    // 0x80800DAC: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
        goto L_8080114C;
    // 0x80800DAC: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
L_80800DB0:
    // 0x80800DB0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800DB4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1CB8) << 16);
    // 0x80800DB8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1CD0) << 16);
    // 0x80800DBC: addiu       $a3, $a3, 0x1CD0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1CD0));
    // 0x80800DC0: addiu       $a2, $a2, 0x1CB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1CB8));
    // 0x80800DC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800DC8: jal         0x80089D28
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800DD0: beq         $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800DD4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1096, 0X17F8) << 16);
            goto L_80800E18;
    }
    // 0x80800DD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1096, 0X17F8) << 16);
    // 0x80800DD8: jal         0x800DC298
    // 0x80800DDC: lwc1        $f12, 0x17F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1096, 0X17F8));
    func_800DC298(rdram, ctx);
        goto after_9;
    // 0x80800DDC: lwc1        $f12, 0x17F8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1096, 0X17F8));
    after_9:
    // 0x80800DE0: beq         $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800DE4: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800E18;
    }
    // 0x80800DE4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800DE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800DEC: jal         0x8008A0E0
    // 0x80800DF0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800DF0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_10:
    // 0x80800DF4: beq         $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800DF8: addiu       $a0, $sp, 0x70
        ctx->r4 = ADD32(ctx->r29, 0X70);
            goto L_80800E18;
    }
    // 0x80800DF8: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80800DFC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1096, 0X1BEC) << 16);
    // 0x80800E00: addiu       $t0, $t0, 0x1BEC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1096, 0X1BEC));
    // 0x80800E04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800E08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E0C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800E10: jal         0x800BBCB8
    // 0x80800E14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x80800E14: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_11:
L_80800E18:
    // 0x80800E18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1096, 0X17FC) << 16);
    // 0x80800E1C: lwc1        $f10, 0x17FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1096, 0X17FC));
    // 0x80800E20: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80800E24: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80800E28: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800E2C: nop

    // 0x80800E30: bc1f        L_80800E3C
    if (!c1cs) {
        // 0x80800E34: nop
    
            goto L_80800E3C;
    }
    // 0x80800E34: nop

    // 0x80800E38: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80800E3C:
    // 0x80800E3C: b           L_8080114C
    // 0x80800E40: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
        goto L_8080114C;
    // 0x80800E40: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
L_80800E44:
    // 0x80800E44: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1096, 0X1B8C) << 16);
    // 0x80800E48: addiu       $t2, $t2, 0x1B8C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1096, 0X1B8C));
    // 0x80800E4C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800E50: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    // 0x80800E54: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C60) << 16);
    // 0x80800E58: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x80800E5C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80800E60: addiu       $a2, $a2, 0x1C60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C60));
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E68: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x80800E6C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800E70: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800E74: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x80800E78: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80800E7C: sw          $t5, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r13;
    // 0x80800E80: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80800E84: sw          $at, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r1;
    // 0x80800E88: lw          $t5, 0x14($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X14);
    // 0x80800E8C: sw          $t5, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r13;
    // 0x80800E90: lw          $at, 0x18($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X18);
    // 0x80800E94: jal         0x80089D28
    // 0x80800E98: sw          $at, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r1;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800E98: sw          $at, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r1;
    after_12:
    // 0x80800E9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1096, 0X1800) << 16);
    // 0x80800EA0: lwc1        $f4, 0x1800($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1096, 0X1800));
    // 0x80800EA4: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80800EA8: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80800EAC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800EB0: nop

    // 0x80800EB4: bc1f        L_80800EC0
    if (!c1cs) {
        // 0x80800EB8: nop
    
            goto L_80800EC0;
    }
    // 0x80800EB8: nop

    // 0x80800EBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80800EC0:
    // 0x80800EC0: b           L_8080114C
    // 0x80800EC4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
        goto L_8080114C;
    // 0x80800EC4: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
L_80800EC8:
    // 0x80800EC8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1096, 0X1D1C) << 16);
    // 0x80800ECC: addiu       $a1, $a1, 0x1D1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1096, 0X1D1C));
    // 0x80800ED0: jal         0x80101E4C
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_13;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800ED8: beq         $v0, $zero, L_80800EFC
    if (ctx->r2 == 0) {
        // 0x80800EDC: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800EFC;
    }
    // 0x80800EDC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800EE0: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800EE4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1CEC) << 16);
    // 0x80800EE8: addiu       $a3, $a3, 0x1CEC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1CEC));
    // 0x80800EEC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80800EF0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80800EF4: jal         0x8010D930
    // 0x80800EF8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_14;
    // 0x80800EF8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_14:
L_80800EFC:
    // 0x80800EFC: lui         $a1, 0x3F54
    ctx->r5 = S32(0X3F54 << 16);
    // 0x80800F00: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x80800F04: jal         0x80101E14
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800F0C: beq         $v0, $zero, L_80800F30
    if (ctx->r2 == 0) {
        // 0x80800F10: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800F30;
    }
    // 0x80800F10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800F14: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800F18: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1CF4) << 16);
    // 0x80800F1C: addiu       $a3, $a3, 0x1CF4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1CF4));
    // 0x80800F20: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x80800F24: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80800F28: jal         0x8010D930
    // 0x80800F2C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_16;
    // 0x80800F2C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_16:
L_80800F30:
    // 0x80800F30: lui         $a1, 0x3DA3
    ctx->r5 = S32(0X3DA3 << 16);
    // 0x80800F34: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800F38: jal         0x80101E14
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800F40: beq         $v0, $zero, L_8080114C
    if (ctx->r2 == 0) {
        // 0x80800F44: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_8080114C;
    }
    // 0x80800F44: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800F48: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800F4C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1D08) << 16);
    // 0x80800F50: addiu       $a3, $a3, 0x1D08
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1D08));
    // 0x80800F54: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x80800F58: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80800F5C: jal         0x8010D930
    // 0x80800F60: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_8010D930(rdram, ctx);
        goto after_18;
    // 0x80800F60: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800F64: b           L_8080114C
    // 0x80800F68: nop

        goto L_8080114C;
    // 0x80800F68: nop

L_80800F6C:
    // 0x80800F6C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800F70: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1D28) << 16);
    // 0x80800F74: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80800F78: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800F7C: addiu       $a2, $a2, 0x1D28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1D28));
    // 0x80800F80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800F84: jal         0x80089D20
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800F8C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1D38) << 16);
    // 0x80800F90: lui         $a3, 0x3E23
    ctx->r7 = S32(0X3E23 << 16);
    // 0x80800F94: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800F98: addiu       $a2, $a2, 0x1D38
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1D38));
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: jal         0x80089D20
    // 0x80800FA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80800FA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x80800FA8: b           L_8080114C
    // 0x80800FAC: nop

        goto L_8080114C;
    // 0x80800FAC: nop

L_80800FB0:
    // 0x80800FB0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1D48) << 16);
    // 0x80800FB4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1D5C) << 16);
    // 0x80800FB8: addiu       $a3, $a3, 0x1D5C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1D5C));
    // 0x80800FBC: addiu       $a2, $a2, 0x1D48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1D48));
    // 0x80800FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC4: jal         0x80089D28
    // 0x80800FC8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800FC8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_21:
    // 0x80800FCC: b           L_8080114C
    // 0x80800FD0: nop

        goto L_8080114C;
    // 0x80800FD0: nop

L_80800FD4:
    // 0x80800FD4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C60) << 16);
    // 0x80800FD8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1D70) << 16);
    // 0x80800FDC: addiu       $a3, $a3, 0x1D70
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1D70));
    // 0x80800FE0: addiu       $a2, $a2, 0x1C60
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C60));
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE8: jal         0x80089D28
    // 0x80800FEC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80800FEC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x80800FF0: b           L_8080114C
    // 0x80800FF4: nop

        goto L_8080114C;
    // 0x80800FF4: nop

L_80800FF8:
    // 0x80800FF8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800FFC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C8C) << 16);
    // 0x80801000: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1DA8) << 16);
    // 0x80801004: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x80801008: addiu       $a3, $a3, 0x1DA8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1DA8));
    // 0x8080100C: addiu       $a2, $a2, 0x1C8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C8C));
    // 0x80801010: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801014: jal         0x80089D28
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8080101C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C78) << 16);
    // 0x80801020: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80801024: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80801028: addiu       $a2, $a2, 0x1C78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C78));
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: jal         0x80089D20
    // 0x80801034: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x80801034: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_24:
    // 0x80801038: beq         $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x8080103C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801050;
    }
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801044: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80801048: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8080104C: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80801050:
    // 0x80801050: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1D94) << 16);
    // 0x80801054: lui         $a3, 0x3F57
    ctx->r7 = S32(0X3F57 << 16);
    // 0x80801058: ori         $a3, $a3, 0xA3D
    ctx->r7 = ctx->r7 | 0XA3D;
    // 0x8080105C: addiu       $a2, $a2, 0x1D94
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1D94));
    // 0x80801060: jal         0x80089D20
    // 0x80801064: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80801064: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_25:
    // 0x80801068: beq         $v0, $zero, L_8080107C
    if (ctx->r2 == 0) {
        // 0x8080106C: lw          $a1, 0x4C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X4C);
            goto L_8080107C;
    }
    // 0x8080106C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801070: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801074: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x80801078: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_8080107C:
    // 0x8080107C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80801080: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80801084: beq         $t3, $zero, L_8080114C
    if (ctx->r11 == 0) {
        // 0x80801088: nop
    
            goto L_8080114C;
    }
    // 0x80801088: nop

    // 0x8080108C: jal         0x8008A0E0
    // 0x80801090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80801090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_26:
    // 0x80801094: beq         $v0, $zero, L_8080114C
    if (ctx->r2 == 0) {
        // 0x80801098: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_8080114C;
    }
    // 0x80801098: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080109C: jal         0x800EE7F8
    // 0x808010A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x808010A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_27:
    // 0x808010A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808010A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808010AC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808010B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808010B4: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    // 0x808010B8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808010BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808010C0: jal         0x800EF1B8
    // 0x808010C4: nop

    func_800EF1B8(rdram, ctx);
        goto after_28;
    // 0x808010C4: nop

    after_28:
    // 0x808010C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808010CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808010D0: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808010D4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808010D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808010DC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808010E0: jal         0x800DC128
    // 0x808010E4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_800DC128(rdram, ctx);
        goto after_29;
    // 0x808010E4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_29:
    // 0x808010E8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1096, 0X1C1C) << 16);
    // 0x808010EC: addiu       $t2, $t2, 0x1C1C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1096, 0X1C1C));
    // 0x808010F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808010F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808010F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808010FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801100: jal         0x800BBCB8
    // 0x80801104: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800BBCB8(rdram, ctx);
        goto after_30;
    // 0x80801104: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_30:
    // 0x80801108: b           L_8080114C
    // 0x8080110C: nop

        goto L_8080114C;
    // 0x8080110C: nop

L_80801110:
    // 0x80801110: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C8C) << 16);
    // 0x80801118: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1DB8) << 16);
    // 0x8080111C: addiu       $a3, $a3, 0x1DB8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1DB8));
    // 0x80801120: addiu       $a2, $a2, 0x1C8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C8C));
    // 0x80801124: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801128: jal         0x80089D28
    // 0x8080112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_31;
    // 0x8080112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80801130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1C78) << 16);
    // 0x80801134: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80801138: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080113C: addiu       $a2, $a2, 0x1C78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1C78));
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801144: jal         0x80089D20
    // 0x80801148: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x80801148: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_32:
L_8080114C:
    // 0x8080114C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1096, 0X1BA8) << 16);
    // 0x80801150: addiu       $a3, $a3, 0x1BA8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1096, 0X1BA8));
    // 0x80801154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801158: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080115C: jal         0x80089D50
    // 0x80801160: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_33;
    // 0x80801160: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    after_33:
    // 0x80801164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801168: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080116C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80801170: jr          $ra
    // 0x80801174: nop

    return;
    // 0x80801174: nop

;}
RECOMP_FUNC void func_8080090C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800914: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800918: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080091C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800920: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800924: jal         0x80100094
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080092C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800930: jal         0x808007F0
    // 0x80800934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808007F0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800938: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080093C: lbu         $t7, 0x8F4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8F4);
    // 0x80800940: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800944: beq         $at, $zero, L_80800988
    if (ctx->r1 == 0) {
        // 0x80800948: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800988;
    }
    // 0x80800948: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080094C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X43EC) << 16);
    // 0x80800950: addu        $at, $at, $t7
    gpr jr_addend_80800958 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800954: lw          $t7, 0x43EC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X43EC));
    // 0x80800958: jr          $t7
    // 0x8080095C: nop

    switch (jr_addend_80800958 >> 2) {
        case 0: goto L_80800960; break;
        case 1: goto L_80800978; break;
        case 2: goto L_8080096C; break;
        case 3: goto L_8080096C; break;
        case 4: goto L_8080096C; break;
        default: switch_error(__func__, 0x80800958, 0x808043EC);
    }
    // 0x8080095C: nop

L_80800960:
    // 0x80800960: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800964: jal         0x808007BC
    // 0x80800968: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808007BC_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800968: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8080096C:
    // 0x8080096C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800970: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800974: sb          $t8, 0x8F4($t9)
    MEM_B(0X8F4, ctx->r25) = ctx->r24;
L_80800978:
    // 0x80800978: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080097C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800980: jal         0x800856D0
    // 0x80800984: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800984: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80800988:
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080098C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800F24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800F28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F2C: jal         0x80800120
    // 0x80800F30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_80800120_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80800F30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80800F34: jal         0x80800DF4
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DF4_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800F3C: jal         0x808004B4
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F44: jal         0x80800DC4
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DC4_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: jal         0x808002A4
    // 0x80800F54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808002A4_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80800F54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x8009D3A8
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D3A8(rdram, ctx);
        goto after_5;
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800F64: jal         0x80800438
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_6;
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800F6C: jal         0x808008D0
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D0_bsbtrot(rdram, ctx);
        goto after_7;
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F74: jal         0x8009EF10
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_8;
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800F7C: bne         $v0, $zero, L_80800F98
    if (ctx->r2 != 0) {
        // 0x80800F80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F98;
    }
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: jal         0x8009BCD4
    // 0x80800F88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_9;
    // 0x80800F88: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_9:
    // 0x80800F8C: beq         $v0, $zero, L_80800F98
    if (ctx->r2 == 0) {
        // 0x80800F90: nop
    
            goto L_80800F98;
    }
    // 0x80800F90: nop

    // 0x80800F94: addiu       $s1, $zero, 0x15
    ctx->r17 = ADD32(0, 0X15);
L_80800F98:
    // 0x80800F98: jal         0x8008DD04
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_10;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800FA0: beq         $v0, $zero, L_80800FAC
    if (ctx->r2 == 0) {
        // 0x80800FA4: nop
    
            goto L_80800FAC;
    }
    // 0x80800FA4: nop

    // 0x80800FA8: addiu       $s1, $zero, 0x71
    ctx->r17 = ADD32(0, 0X71);
L_80800FAC:
    // 0x80800FAC: jal         0x80800710
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800710_bsbtrot(rdram, ctx);
        goto after_11;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800FB4: beq         $v0, $zero, L_80800FC0
    if (ctx->r2 == 0) {
        // 0x80800FB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC0;
    }
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
L_80800FC0:
    // 0x80800FC0: jal         0x80091A58
    // 0x80800FC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_12;
    // 0x80800FC4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80800FC8: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800FCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FDC;
    }
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: jal         0x8080075C
    // 0x80800FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_13;
    // 0x80800FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x80800FD8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80800FDC:
    // 0x80800FDC: jal         0x8008DF18
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_14;
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800FE4: beq         $v0, $zero, L_80800FF0
    if (ctx->r2 == 0) {
        // 0x80800FE8: nop
    
            goto L_80800FF0;
    }
    // 0x80800FE8: nop

    // 0x80800FEC: addiu       $s1, $zero, 0x45
    ctx->r17 = ADD32(0, 0X45);
L_80800FF0:
    // 0x80800FF0: jal         0x8008E35C
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x80800FF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800FF8: beq         $v0, $zero, L_80801004
    if (ctx->r2 == 0) {
        // 0x80800FFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801004;
    }
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801000: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80801004:
    // 0x80801004: jal         0x800A02DC
    // 0x80801008: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A02DC(rdram, ctx);
        goto after_16;
    // 0x80801008: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801010: jal         0x8009E5C8
    // 0x80801014: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80801014: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80801018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080101C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801020: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801024: jr          $ra
    // 0x80801028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void anctrl_isStopped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B32C: jal         0x8008B284
    // 0x8008B330: nop

    anctrl_getPlaybackType(rdram, ctx);
        goto after_0;
    // 0x8008B330: nop

    after_0:
    // 0x8008B334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B338: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x8008B33C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008B340: jr          $ra
    // 0x8008B344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008B344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _ncpod_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089580: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089580);
    return;
    // 0x80089584: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80801044_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801044: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801048: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080104C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801050: jal         0x8080055C
    // 0x80801054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80801054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080105C: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x80801060: jal         0x8008CB3C
    // 0x80801064: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801064: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_1:
    // 0x80801068: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080106C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801078: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080107C: jal         0x8009FFD8
    // 0x80801080: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801080: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801088: jal         0x8009B9B0
    // 0x8080108C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080108C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801090: jal         0x800909CC
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_4;
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080109C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010A4: jr          $ra
    // 0x808010A8: nop

    return;
    // 0x808010A8: nop

;}
RECOMP_FUNC void func_808003A0_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A0: jr          $ra
    // 0x808003A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808003A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chjiggypost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(796, 0X380) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X380));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(796, 0X380));
;}
RECOMP_FUNC void _capod_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856C0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856C0);
    return;
    // 0x800856C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bskazstilt_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DD8: jal         0x8009BC6C
    // 0x80800DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800DDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DE0: jal         0x80800234
    // 0x80800DE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800234_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x80800DE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DF0: jr          $ra
    // 0x80800DF4: nop

    return;
    // 0x80800DF4: nop

;}
RECOMP_FUNC void func_80800098_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x8080009C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808000A0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808000A4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2730, 0X4F0) << 16);
    // 0x808000A8: addiu       $t8, $t8, 0x4F0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2730, 0X4F0));
    // 0x808000AC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000B0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x808000B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x808000B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000C0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000CC: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000D0: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_808000F8;
    }
    // 0x808000D0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808000D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808000D8: sb          $t6, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r14;
    // 0x808000DC: jalr        $v0
    // 0x808000E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x808000E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000E4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E8: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x808000EC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: b           L_808000FC
    // 0x808000F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_808000FC;
    // 0x808000F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808000F8:
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808000FC:
    // 0x808000FC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80800100: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800104: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80800108: sb          $a2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r6;
    // 0x8080010C: sb          $a1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r5;
    // 0x80800110: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80800114: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800118: beql        $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x8080011C: lw          $t1, 0x0($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X0);
            goto L_80800138;
    }
    goto skip_0;
    // 0x8080011C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80800120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800124: jalr        $v0
    // 0x80800128: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x80800128: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080012C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800130: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800134: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
L_80800138:
    // 0x80800138: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x8080013C: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x80800140: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void _gsattract_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C70: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C70);
    return;
    // 0x80088C74: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8008C984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C984: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C988: jr          $ra
    // 0x8008C98C: sh          $a1, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r5;
    return;
    // 0x8008C98C: sh          $a1, 0xE($t6)
    MEM_H(0XE, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_8008C124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C12C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C130: sb          $a1, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r5;
    // 0x8008C134: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008C138: jal         0x8008C1B8
    // 0x8008C13C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C1B8(rdram, ctx);
        goto after_0;
    // 0x8008C13C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008C140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C144: jal         0x8008C1C0
    // 0x8008C148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8008C1C0(rdram, ctx);
        goto after_1;
    // 0x8008C148: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x8008C14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C150: jal         0x8008C1E4
    // 0x8008C154: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008C1E4(rdram, ctx);
        goto after_2;
    // 0x8008C154: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8008C158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008C15C: jal         0x8008C1D4
    // 0x8008C160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008C1D4(rdram, ctx);
        goto after_3;
    // 0x8008C160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8008C164: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C168: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x8008C16C: sb          $t6, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r14;
    // 0x8008C170: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x8008C174: jal         0x8008B8E0
    // 0x8008C178: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    func_8008B8E0(rdram, ctx);
        goto after_4;
    // 0x8008C178: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
    after_4:
    // 0x8008C17C: jal         0x8008B8E0
    // 0x8008C180: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    func_8008B8E0(rdram, ctx);
        goto after_5;
    // 0x8008C180: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    after_5:
    // 0x8008C184: lbu         $t7, 0x1C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1C);
    // 0x8008C188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008C18C: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x8008C190: bnel        $t7, $at, L_8008C1A8
    if (ctx->r15 != ctx->r1) {
        // 0x8008C194: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C1A8;
    }
    goto skip_0;
    // 0x8008C194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008C198: jal         0x8008B8E0
    // 0x8008C19C: nop

    func_8008B8E0(rdram, ctx);
        goto after_6;
    // 0x8008C19C: nop

    after_6:
    // 0x8008C1A0: sh          $v0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r2;
    // 0x8008C1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C1A8:
    // 0x8008C1A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C1AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008C1B0: jr          $ra
    // 0x8008C1B4: nop

    return;
    // 0x8008C1B4: nop

;}
