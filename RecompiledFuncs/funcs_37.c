#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bamovegoto_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001CC: jr          $ra
    // 0x808001D0: sb          $a1, 0x55($t6)
    MEM_B(0X55, ctx->r14) = ctx->r5;
    return;
    // 0x808001D0: sb          $a1, 0x55($t6)
    MEM_B(0X55, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800BD8_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800BE4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800BE8: jal         0x8001210C
    // 0x80800BEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800BEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800BF0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x80800BF4: nop
    
            goto L_80800C34;
    }
    // 0x80800BF4: nop

    // 0x80800BF8: jal         0x800B5BE4
    // 0x80800BFC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800B5BE4(rdram, ctx);
        goto after_1;
    // 0x80800BFC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x80800C00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800C04: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2416, 0XEA8) << 16);
    // 0x80800C08: addiu       $t6, $t6, 0xEA8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2416, 0XEA8));
    // 0x80800C0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800C10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800C14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800C18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C20: jal         0x800BABB8
    // 0x80800C24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800C24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800C28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800C2C: jal         0x800BA22C
    // 0x80800C30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800C30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
L_80800C34:
    // 0x80800C34: jal         0x80800CA0
    // 0x80800C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800CA0_chfloaty(rdram, ctx);
        goto after_4;
    // 0x80800C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C44: jr          $ra
    // 0x80800C48: nop

    return;
    // 0x80800C48: nop

;}
RECOMP_FUNC void func_8080041C_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800424: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800428: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080042C: bgez        $t8, L_80800448
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800430: nop
    
            goto L_80800448;
    }
    // 0x80800430: nop

    // 0x80800434: jal         0x80089BD8
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080043C: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x80800440: b           L_80800458
    // 0x80800444: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
        goto L_80800458;
    // 0x80800444: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_80800448:
    // 0x80800448: jal         0x8008A160
    // 0x8080044C: nop

    _sucoaster_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080044C: nop

    after_1:
    // 0x80800450: xori        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 ^ 0X1;
    // 0x80800454: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
L_80800458:
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080045C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

;}
RECOMP_FUNC void func_800BEBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEBD4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BEBD8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEBDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEBE0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BEBE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEBE8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BEBEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEBF4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800BEBF8: jal         0x800B27A0
    // 0x800BEBFC: lw          $a0, -0x7A44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A44);
    func_800B27A0(rdram, ctx);
        goto after_0;
    // 0x800BEBFC: lw          $a0, -0x7A44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7A44);
    after_0:
    // 0x800BEC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BEC04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEC08: jr          $ra
    // 0x800BEC0C: nop

    return;
    // 0x800BEC0C: nop

;}
RECOMP_FUNC void _chgoldstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087288: syscall     542
    recomp_syscall_handler(rdram, ctx, 0x80087288);
    return;
    // 0x8008728C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800700_chtoxicroomprops(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080070C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800710: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x80800714: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800718: jal         0x800DA298
    // 0x8080071C: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080071C: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_0:
    // 0x80800720: bne         $v0, $zero, L_8080073C
    if (ctx->r2 != 0) {
        // 0x80800724: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080073C;
    }
    // 0x80800724: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800728: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080072C: jal         0x80101FDC
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800734: b           L_8080074C
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080074C;
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080073C:
    // 0x8080073C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800740: jal         0x80101FDC
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080074C:
    // 0x8080074C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800750: jr          $ra
    // 0x80800754: nop

    return;
    // 0x80800754: nop

;}
RECOMP_FUNC void chweldarbossfusebox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1380, 0X6B8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x6B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X6B8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x6B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X6B8));
;}
RECOMP_FUNC void _bahold_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D18: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D18);
    return;
    // 0x80084D1C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8009E5A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E5A4: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E5A8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8009E5AC: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x8009E5B0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8009E5B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009E5B8: jr          $ra
    // 0x8009E5BC: sh          $a2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r6;
    return;
    // 0x8009E5BC: sh          $a2, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r6;
;}
RECOMP_FUNC void func_8001546C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001546C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80015470: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80015474: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80015478: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001547C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015480: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015484: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80015488: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001548C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80015490: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80015494: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80015498: lui         $s4, 0x8008
    ctx->r20 = S32(0X8008 << 16);
    // 0x8001549C: lui         $s7, 0x8008
    ctx->r23 = S32(0X8008 << 16);
    // 0x800154A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800154A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800154A8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800154AC: addiu       $s7, $s7, -0x6FD0
    ctx->r23 = ADD32(ctx->r23, -0X6FD0);
    // 0x800154B0: addiu       $s4, $s4, -0x7030
    ctx->r20 = ADD32(ctx->r20, -0X7030);
    // 0x800154B4: addiu       $s3, $s3, -0xA30
    ctx->r19 = ADD32(ctx->r19, -0XA30);
    // 0x800154B8: addiu       $s2, $s2, -0x6EC8
    ctx->r18 = ADD32(ctx->r18, -0X6EC8);
    // 0x800154BC: addiu       $s1, $s1, -0x7030
    ctx->r17 = ADD32(ctx->r17, -0X7030);
    // 0x800154C0: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x800154C4: addiu       $s6, $zero, 0x258
    ctx->r22 = ADD32(0, 0X258);
    // 0x800154C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800154CC:
    // 0x800154CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800154D0: jal         0x8002E1F0
    // 0x800154D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800154D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800154D8: jal         0x80014A54
    // 0x800154DC: nop

    func_80014A54(rdram, ctx);
        goto after_1;
    // 0x800154DC: nop

    after_1:
    // 0x800154E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800154E4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800154E8: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x800154EC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    tooie_vi_hang_limit(rdram, ctx);
    // 0x800154F0: xor         $s0, $s6, $t7
    ctx->r16 = ctx->r22 ^ ctx->r15;
    // 0x800154F4: jal         0x8001E7C0
    // 0x800154F8: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    func_8001E7C0(rdram, ctx);
        goto after_2;
    // 0x800154F8: sltiu       $s0, $s0, 0x1
    ctx->r16 = ctx->r16 < 0X1 ? 1 : 0;
    after_2:
    // 0x800154FC: beq         $s0, $zero, L_80015524
    if (ctx->r16 == 0) {
        // 0x80015500: lw          $v1, 0x0($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X0);
            goto L_80015524;
    }
    // 0x80015500: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80015504: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80015508: beql        $t8, $zero, L_80015528
    if (ctx->r24 == 0) {
        // 0x8001550C: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80015528;
    }
    goto skip_0;
    // 0x8001550C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_0:
    // 0x80015510: beql        $v1, $zero, L_80015528
    if (ctx->r3 == 0) {
        // 0x80015514: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80015528;
    }
    goto skip_1;
    // 0x80015514: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_1:
    // 0x80015518: jal         0x8001E5DC
    // 0x8001551C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8001E5DC(rdram, ctx);
        goto after_3;
    // 0x8001551C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80015520: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_80015524:
    // 0x80015524: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80015528:
    // 0x80015528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001552C: jal         0x8002EAD0
    // 0x80015530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80015530: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80015534: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80015538: addiu       $s0, $s0, -0x7070
    ctx->r16 = ADD32(ctx->r16, -0X7070);
    // 0x8001553C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80015540:
    // 0x80015540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    tooie_vi_client_filter(rdram, ctx);
    // 0x80015544: beql        $a0, $zero, L_80015558
    if (ctx->r4 == 0) {
        // 0x80015548: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80015558;
    }
    goto skip_2;
    // 0x80015548: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_2:
    // 0x8001554C: jal         0x8002EAD0
    // 0x80015550: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    osSendMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80015550: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_5:
    tooie_vi_client_sent(rdram, ctx);
    // 0x80015554: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80015558:
    // 0x80015558: bnel        $s0, $s1, L_80015540
    if (ctx->r16 != ctx->r17) {
        // 0x8001555C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80015540;
    }
    goto skip_3;
    // 0x8001555C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80015560: b           L_800154CC
    // 0x80015564: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_800154CC;
    // 0x80015564: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80015568: nop

    // 0x8001556C: nop

    // 0x80015570: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80015574: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015578: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001557C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80015580: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80015584: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80015588: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001558C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80015590: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80015594: jr          $ra
    // 0x80015598: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80015598: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void _chhoneyb_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BA8: syscall     204
    recomp_syscall_handler(rdram, ctx, 0x80085BA8);
    return;
    // 0x80085BAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bamovespline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EB0: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EB0);
    return;
    // 0x80084EB4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800E08_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E18: jal         0x8080081C
    // 0x80800E1C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800E1C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: jal         0x8009BB24
    // 0x80800E28: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800E28: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E30: jal         0x80091A30
    // 0x80800E34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_2;
    // 0x80800E34: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x80800E38: beq         $v0, $zero, L_80800E60
    if (ctx->r2 == 0) {
        // 0x80800E3C: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80800E60;
    }
    // 0x80800E3C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800E40: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E44: nop

    // 0x80800E48: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800E4C: nop

    // 0x80800E50: bc1fl       L_80800E64
    if (!c1cs) {
        // 0x80800E54: lbu         $v0, 0x15C($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15C);
            goto L_80800E64;
    }
    goto skip_0;
    // 0x80800E54: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    skip_0:
    // 0x80800E58: jal         0x8009BC6C
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800E60:
    // 0x80800E60: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
L_80800E64:
    // 0x80800E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E68: beq         $v0, $at, L_80800E80
    if (ctx->r2 == ctx->r1) {
        // 0x80800E6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E80;
    }
    // 0x80800E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E70: beq         $v0, $at, L_80800EAC
    if (ctx->r2 == ctx->r1) {
        // 0x80800E74: nop
    
            goto L_80800EAC;
    }
    // 0x80800E74: nop

    // 0x80800E78: b           L_80800EFC
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EFC;
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E80:
    // 0x80800E80: jal         0x808004B4
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_4;
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E8C: jal         0x8008DF8C
    // 0x80800E90: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800E90: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x80800E94: beq         $v0, $zero, L_80800EF8
    if (ctx->r2 == 0) {
        // 0x80800E98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF8;
    }
    // 0x80800E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E9C: jal         0x80800BC4
    // 0x80800EA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800BC4_bstrexlarge(rdram, ctx);
        goto after_6;
    // 0x80800EA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800EA4: b           L_80800EFC
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EFC;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EAC:
    // 0x80800EAC: jal         0x808004B4
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_7;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800EB4: jal         0x80800044
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800044_bstrexlarge(rdram, ctx);
        goto after_8;
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800EBC: jal         0x8008E078
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800EC4: bne         $v0, $zero, L_80800EDC
    if (ctx->r2 != 0) {
        // 0x80800EC8: nop
    
            goto L_80800EDC;
    }
    // 0x80800EC8: nop

    // 0x80800ECC: jal         0x80800034
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800034_bstrexlarge(rdram, ctx);
        goto after_10;
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800ED4: beql        $v0, $zero, L_80800EFC
    if (ctx->r2 == 0) {
        // 0x80800ED8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EFC;
    }
    goto skip_1;
    // 0x80800ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800EDC:
    // 0x80800EDC: jal         0x800A2EAC
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_11;
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE8: jal         0x8009B9B0
    // 0x80800EEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800EEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x80800EF0: addiu       $t6, $zero, 0x147
    ctx->r14 = ADD32(0, 0X147);
    // 0x80800EF4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80800EF8:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EFC:
    // 0x80800EFC: jal         0x8009E5C8
    // 0x80800F00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800F00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x80800F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800F10: jr          $ra
    // 0x80800F14: nop

    return;
    // 0x80800F14: nop

;}
RECOMP_FUNC void func_80800C38_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C38: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800C44: jal         0x80100094
    // 0x80800C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C4C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800C50: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80800C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C58: jal         0x800D0A9C
    // 0x80800C5C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80800C5C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800C60: jal         0x800D395C
    // 0x80800C64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x80800C64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800C68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800C6C: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    // 0x80800C70: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800C74: jal         0x800D2054
    // 0x80800C78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x80800C78: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800C7C: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x80800C80: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800C84: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800C88: beq         $a1, $zero, L_80800CA4
    if (ctx->r5 == 0) {
        // 0x80800C8C: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80800CA4;
    }
    // 0x80800C8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C90: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800C94: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800C98: bnel        $a1, $zero, L_80800CA8
    if (ctx->r5 != 0) {
        // 0x80800C9C: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80800CA8;
    }
    goto skip_0;
    // 0x80800C9C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800CA0: sltu        $a1, $zero, $a3
    ctx->r5 = 0 < ctx->r7 ? 1 : 0;
L_80800CA4:
    // 0x80800CA4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800CA8:
    // 0x80800CA8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800CAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CB0: slti        $t8, $v0, 0x4B
    ctx->r24 = SIGNED(ctx->r2) < 0X4B ? 1 : 0;
    // 0x80800CB4: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80800CB8: sltu        $a1, $zero, $t8
    ctx->r5 = 0 < ctx->r24 ? 1 : 0;
    // 0x80800CBC: beq         $a1, $zero, L_80800CD4
    if (ctx->r5 == 0) {
        // 0x80800CC0: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800CD4;
    }
    // 0x80800CC0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800CC4: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800CC8: beql        $a1, $zero, L_80800CD8
    if (ctx->r5 == 0) {
        // 0x80800CCC: sw          $a1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r5;
            goto L_80800CD8;
    }
    goto skip_1;
    // 0x80800CCC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80800CD0: sltiu       $a1, $a3, 0x1
    ctx->r5 = ctx->r7 < 0X1 ? 1 : 0;
L_80800CD4:
    // 0x80800CD4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800CD8:
    // 0x80800CD8: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80800CDC: jal         0x800FDC28
    // 0x80800CE0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FDC28(rdram, ctx);
        goto after_4;
    // 0x80800CE0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800CE4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800CE8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800CEC: bne         $a1, $zero, L_80800CFC
    if (ctx->r5 != 0) {
        // 0x80800CF0: nop
    
            goto L_80800CFC;
    }
    // 0x80800CF0: nop

    // 0x80800CF4: beq         $v1, $zero, L_80800D04
    if (ctx->r3 == 0) {
        // 0x80800CF8: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800D04;
    }
    // 0x80800CF8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_80800CFC:
    // 0x80800CFC: b           L_80800D04
    // 0x80800D00: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_80800D04;
    // 0x80800D00: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80800D04:
    // 0x80800D04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800D08: jal         0x800FC6B0
    // 0x80800D0C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800FC6B0(rdram, ctx);
        goto after_5;
    // 0x80800D0C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x80800D10: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800D14: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800D18: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800D1C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80800D20: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800D24: beq         $t3, $zero, L_80800D34
    if (ctx->r11 == 0) {
        // 0x80800D28: nop
    
            goto L_80800D34;
    }
    // 0x80800D28: nop

    // 0x80800D2C: b           L_80800D90
    // 0x80800D30: addiu       $v1, $zero, 0x17FA
    ctx->r3 = ADD32(0, 0X17FA);
        goto L_80800D90;
    // 0x80800D30: addiu       $v1, $zero, 0x17FA
    ctx->r3 = ADD32(0, 0X17FA);
L_80800D34:
    // 0x80800D34: beq         $v1, $zero, L_80800D44
    if (ctx->r3 == 0) {
        // 0x80800D38: nop
    
            goto L_80800D44;
    }
    // 0x80800D38: nop

    // 0x80800D3C: b           L_80800D90
    // 0x80800D40: addiu       $v1, $zero, 0x17F7
    ctx->r3 = ADD32(0, 0X17F7);
        goto L_80800D90;
    // 0x80800D40: addiu       $v1, $zero, 0x17F7
    ctx->r3 = ADD32(0, 0X17F7);
L_80800D44:
    // 0x80800D44: jal         0x800D395C
    // 0x80800D48: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x80800D48: nop

    after_6:
    // 0x80800D4C: bne         $v0, $zero, L_80800D84
    if (ctx->r2 != 0) {
        // 0x80800D50: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_80800D84;
    }
    // 0x80800D50: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800D54: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80800D58: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D5C: beq         $t4, $zero, L_80800D7C
    if (ctx->r12 == 0) {
        // 0x80800D60: nop
    
            goto L_80800D7C;
    }
    // 0x80800D60: nop

    // 0x80800D64: bne         $t5, $zero, L_80800D74
    if (ctx->r13 != 0) {
        // 0x80800D68: nop
    
            goto L_80800D74;
    }
    // 0x80800D68: nop

    // 0x80800D6C: b           L_80800D90
    // 0x80800D70: addiu       $v1, $zero, 0x1809
    ctx->r3 = ADD32(0, 0X1809);
        goto L_80800D90;
    // 0x80800D70: addiu       $v1, $zero, 0x1809
    ctx->r3 = ADD32(0, 0X1809);
L_80800D74:
    // 0x80800D74: b           L_80800D90
    // 0x80800D78: addiu       $v1, $zero, 0x1808
    ctx->r3 = ADD32(0, 0X1808);
        goto L_80800D90;
    // 0x80800D78: addiu       $v1, $zero, 0x1808
    ctx->r3 = ADD32(0, 0X1808);
L_80800D7C:
    // 0x80800D7C: b           L_80800D90
    // 0x80800D80: addiu       $v1, $zero, 0x1807
    ctx->r3 = ADD32(0, 0X1807);
        goto L_80800D90;
    // 0x80800D80: addiu       $v1, $zero, 0x1807
    ctx->r3 = ADD32(0, 0X1807);
L_80800D84:
    // 0x80800D84: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80800D88: addiu       $v1, $zero, 0xCEB
    ctx->r3 = ADD32(0, 0XCEB);
    // 0x80800D8C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800D90:
    // 0x80800D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800D98: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void func_8080000C_chfactoryposter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x800DA298
    // 0x8080001C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_0:
    // 0x80800020: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800024: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80800044;
    }
    // 0x80800024: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800028: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080002C: jal         0x800BF744
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800034: jal         0x800FFAB0
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080003C: b           L_80800050
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800050;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: jal         0x800BF744
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_80800000_sueggmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080000C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800010: jal         0x800D8FF8
    // 0x80800014: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8080001C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800020: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800024: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x80800028: lwc1        $f4, 0x2C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x8080002C: lwc1        $f16, 0x54($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80800030: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800034: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800038: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8080003C: swc1        $f10, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f10.u32l;
    // 0x80800040: lwc1        $f18, 0x2C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80800044: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80800048: nop

    // 0x8080004C: bc1fl       L_8080005C
    if (!c1cs) {
        // 0x80800050: mfc1        $a2, $f12
        ctx->r6 = (int32_t)ctx->f12.u32l;
            goto L_8080005C;
    }
    goto skip_0;
    // 0x80800050: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    skip_0:
    // 0x80800054: swc1        $f2, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f2.u32l;
    // 0x80800058: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
L_8080005C:
    // 0x8080005C: jal         0x800EFA20
    // 0x80800060: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a1, $a3, 0x28
    ctx->r5 = ADD32(ctx->r7, 0X28);
    after_1:
    // 0x80800064: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800068: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080006C: jal         0x800EE780
    // 0x80800070: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083708: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083708);
    return;
    // 0x8008370C: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void defrag_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B870: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001B874: lw          $t6, -0x390C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390C);
    // 0x8001B878: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001B87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B880: bne         $a0, $t6, L_8001B890
    if (ctx->r4 != ctx->r14) {
        // 0x8001B884: lui         $t3, 0x8008
        ctx->r11 = S32(0X8008 << 16);
            goto L_8001B890;
    }
    // 0x8001B884: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8001B888: b           L_8001B9AC
    // 0x8001B88C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8001B9AC;
    // 0x8001B88C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001B890:
    // 0x8001B890: lw          $t7, -0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, -0XC);
    // 0x8001B894: addiu       $t3, $t3, -0x3910
    ctx->r11 = ADD32(ctx->r11, -0X3910);
    // 0x8001B898: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x8001B89C: subu        $a2, $t7, $a0
    ctx->r6 = SUB32(ctx->r15, ctx->r4);
    // 0x8001B8A0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B8A4: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8001B8A8: ori         $at, $at, 0x4240
    ctx->r1 = ctx->r1 | 0X4240;
    // 0x8001B8AC: addu        $t0, $t8, $a2
    ctx->r8 = ADD32(ctx->r24, ctx->r6);
    // 0x8001B8B0: slt         $at, $t0, $at
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001B8B4: bne         $at, $zero, L_8001B8C4
    if (ctx->r1 != 0) {
        // 0x8001B8B8: addiu       $a1, $a0, -0x10
        ctx->r5 = ADD32(ctx->r4, -0X10);
            goto L_8001B8C4;
    }
    // 0x8001B8B8: addiu       $a1, $a0, -0x10
    ctx->r5 = ADD32(ctx->r4, -0X10);
    // 0x8001B8BC: b           L_8001B9AC
    // 0x8001B8C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8001B9AC;
    // 0x8001B8C0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001B8C4:
    // 0x8001B8C4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8001B8C8: lbu         $t9, 0xF($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF);
    // 0x8001B8CC: srl         $t4, $t9, 6
    ctx->r12 = S32(U32(ctx->r25) >> 6);
    // 0x8001B8D0: bne         $t4, $zero, L_8001B8F4
    if (ctx->r12 != 0) {
        // 0x8001B8D4: nop
    
            goto L_8001B8F4;
    }
    // 0x8001B8D4: nop

    // 0x8001B8D8: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8001B8DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B8E0: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x8001B8E4: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x8001B8E8: sltiu       $at, $t7, 0x74
    ctx->r1 = ctx->r15 < 0X74 ? 1 : 0;
    // 0x8001B8EC: beq         $at, $zero, L_8001B8FC
    if (ctx->r1 == 0) {
        // 0x8001B8F0: nop
    
            goto L_8001B8FC;
    }
    // 0x8001B8F0: nop

L_8001B8F4:
    // 0x8001B8F4: b           L_8001B9AC
    // 0x8001B8F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8001B9AC;
    // 0x8001B8F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001B8FC:
    // 0x8001B8FC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001B900: sw          $t8, -0x3908($at)
    MEM_W(-0X3908, ctx->r1) = ctx->r24;
    // 0x8001B904: sw          $t0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r8;
    // 0x8001B908: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8001B90C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8001B910: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x8001B914: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8001B918: subu        $a3, $v1, $a2
    ctx->r7 = SUB32(ctx->r3, ctx->r6);
    // 0x8001B91C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001B920: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8001B924: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001B928: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8001B92C: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x8001B930: jal         0x8001BC68
    // 0x8001B934: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    aligned4_memmove(rdram, ctx);
        goto after_0;
    // 0x8001B934: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_0:
    // 0x8001B938: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8001B93C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001B940: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B944: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8001B948: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8001B94C: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // 0x8001B950: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x8001B954: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x8001B958: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8001B95C: sw          $a0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r4;
    // 0x8001B960: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8001B964: sw          $t2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r10;
    // 0x8001B968: sw          $a0, 0x10($t2)
    MEM_W(0X10, ctx->r10) = ctx->r4;
    // 0x8001B96C: lbu         $t9, 0xF($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XF);
    // 0x8001B970: andi        $t5, $t9, 0xFF3F
    ctx->r13 = ctx->r25 & 0XFF3F;
    // 0x8001B974: andi        $t7, $t5, 0xF7
    ctx->r15 = ctx->r13 & 0XF7;
    // 0x8001B978: sb          $t5, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r13;
    // 0x8001B97C: andi        $t8, $t7, 0xFB
    ctx->r24 = ctx->r15 & 0XFB;
    // 0x8001B980: sb          $t7, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r15;
    // 0x8001B984: sb          $t8, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r24;
    // 0x8001B988: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001B98C: srl         $t9, $v0, 8
    ctx->r25 = S32(U32(ctx->r2) >> 8);
    // 0x8001B990: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x8001B994: xor         $t5, $t4, $v0
    ctx->r13 = ctx->r12 ^ ctx->r2;
    // 0x8001B998: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x8001B99C: jal         0x8001A6EC
    // 0x8001B9A0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    heap_update_empty_block(rdram, ctx);
        goto after_1;
    // 0x8001B9A0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001B9A4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B9A8: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
L_8001B9AC:
    // 0x8001B9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B9B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001B9B4: jr          $ra
    // 0x8001B9B8: nop

    return;
    // 0x8001B9B8: nop

;}
RECOMP_FUNC void gcsectionDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080014C: jal         0x808000F0
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808000F0_gcsectionDll(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800154: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2666, 0X210) << 16);
    // 0x80800158: addiu       $t6, $t6, 0x210
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2666, 0X210));
    // 0x8080015C: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x80800160: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800164: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80800168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080016C: mflo        $v0
    ctx->r2 = lo;
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void _ncbaspiral_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089170: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089170);
    return;
    // 0x80089174: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void gspropmarker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808000D4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x808000D8: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x808000DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E0: bne         $a3, $zero, L_808000F0
    if (ctx->r7 != 0) {
        // 0x808000E4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_808000F0;
    }
    // 0x808000E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808000E8: b           L_808001D8
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001D8;
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000F0:
    // 0x808000F0: beql        $a0, $zero, L_808001D8
    if (ctx->r4 == 0) {
        // 0x808000F4: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_808001D8;
    }
    goto skip_0;
    // 0x808000F4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_0:
    // 0x808000F8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808000FC: jal         0x800E9DC4
    // 0x80800100: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_800E9DC4(rdram, ctx);
        goto after_0;
    // 0x80800100: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800104: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x80800108: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_808001D4;
    }
    // 0x80800108: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080010C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800110: jal         0x800E9D68
    // 0x80800114: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    func_800E9D68(rdram, ctx);
        goto after_1;
    // 0x80800114: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800118: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080011C: jal         0x800E9D90
    // 0x80800120: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800E9D90(rdram, ctx);
        goto after_2;
    // 0x80800120: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800124: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800128: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8080012C: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80800130: beql        $at, $zero, L_808001D8
    if (ctx->r1 == 0) {
        // 0x80800134: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_808001D8;
    }
    goto skip_1;
    // 0x80800134: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    skip_1:
    // 0x80800138: blez        $s1, L_808001D4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8080013C: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_808001D4;
    }
    // 0x8080013C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80800140: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800144: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800148: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080014C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
L_80800150:
    // 0x80800150: andi        $a0, $v1, 0x1
    ctx->r4 = ctx->r3 & 0X1;
    // 0x80800154: beq         $t1, $a0, L_80800170
    if (ctx->r9 == ctx->r4) {
        // 0x80800158: sll         $t8, $v1, 25
        ctx->r24 = S32(ctx->r3 << 25);
            goto L_80800170;
    }
    // 0x80800158: sll         $t8, $v1, 25
    ctx->r24 = S32(ctx->r3 << 25);
    // 0x8080015C: bnel        $a0, $zero, L_808001C0
    if (ctx->r4 != 0) {
        // 0x80800160: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_808001C0;
    }
    goto skip_2;
    // 0x80800160: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    skip_2:
    // 0x80800164: lbu         $t6, 0x12($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X12);
    // 0x80800168: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8080016C: bne         $t2, $t7, L_808001BC
    if (ctx->r10 != ctx->r15) {
        // 0x80800170: srl         $t9, $t8, 26
        ctx->r25 = S32(U32(ctx->r24) >> 26);
            goto L_808001BC;
    }
L_80800170:
    // 0x80800170: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x80800174: bnel        $t3, $t9, L_808001C0
    if (ctx->r11 != ctx->r25) {
        // 0x80800178: addiu       $a3, $a3, 0x14
        ctx->r7 = ADD32(ctx->r7, 0X14);
            goto L_808001C0;
    }
    goto skip_3;
    // 0x80800178: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    skip_3:
    // 0x8080017C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800180: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80800184: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80800188: beq         $a2, $t4, L_808001BC
    if (ctx->r6 == ctx->r12) {
        // 0x8080018C: addu        $t6, $s2, $t5
        ctx->r14 = ADD32(ctx->r18, ctx->r13);
            goto L_808001BC;
    }
    // 0x8080018C: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x80800190: lhu         $a1, 0x8($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X8);
    // 0x80800194: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_80800198:
    // 0x80800198: bnel        $a1, $a0, L_808001B0
    if (ctx->r5 != ctx->r4) {
        // 0x8080019C: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_808001B0;
    }
    goto skip_4;
    // 0x8080019C: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_4:
    // 0x808001A0: sw          $a3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r7;
    // 0x808001A4: b           L_808001BC
    // 0x808001A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_808001BC;
    // 0x808001A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x808001AC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_808001B0:
    // 0x808001B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001B4: bne         $a2, $a0, L_80800198
    if (ctx->r6 != ctx->r4) {
        // 0x808001B8: nop
    
            goto L_80800198;
    }
    // 0x808001B8: nop

L_808001BC:
    // 0x808001BC: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
L_808001C0:
    // 0x808001C0: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x808001C4: beq         $at, $zero, L_808001D4
    if (ctx->r1 == 0) {
        // 0x808001C8: slt         $at, $t0, $s1
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_808001D4;
    }
    // 0x808001C8: slt         $at, $t0, $s1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808001CC: bnel        $at, $zero, L_80800150
    if (ctx->r1 != 0) {
        // 0x808001D0: lw          $v1, 0x4($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X4);
            goto L_80800150;
    }
    goto skip_5;
    // 0x808001D0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    skip_5:
L_808001D4:
    // 0x808001D4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808001D8:
    // 0x808001D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808001E8: jr          $ra
    // 0x808001EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808001EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chlightfader_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863E0: syscall     321
    recomp_syscall_handler(rdram, ctx, 0x800863E0);
    return;
    // 0x800863E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsstonehead_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011D4: jal         0x80800060
    // 0x808011D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808011D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808011E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808011E8: jal         0x80084468
    // 0x808011EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808011EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808011F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011F4: jal         0x800845D8
    // 0x808011F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808011F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808011FC: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80801200: ori         $a2, $a2, 0x75F7
    ctx->r6 = ctx->r6 | 0X75F7;
    // 0x80801204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801208: jal         0x800845E0
    // 0x8080120C: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x8080120C: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    after_3:
    // 0x80801210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801218: jr          $ra
    // 0x8080121C: nop

    return;
    // 0x8080121C: nop

;}
RECOMP_FUNC void func_80800018_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800024: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800028: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080002C: addiu       $t7, $zero, 0x9B
    ctx->r15 = ADD32(0, 0X9B);
    // 0x80800030: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800034: jal         0x8008A208
    // 0x80800038: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8080003C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800040: jal         0x80102424
    // 0x80800044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_808007E4_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808007EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007F8: bne         $a1, $at, L_80800814
    if (ctx->r5 != ctx->r1) {
        // 0x808007FC: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800814;
    }
    // 0x808007FC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800800: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80800804: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x80800808: jal         0x800887D8
    // 0x8080080C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080080C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800810: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800814:
    // 0x80800814: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800818: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080081C: jal         0x80085820
    // 0x80800820: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800820: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void bscarry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(132, 0X7B0) << 16);
    // 0x808003CC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003D0: jr          $ra
    // 0x808003D4: lw          $v0, 0x7B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7B0));
    return;
    // 0x808003D4: lw          $v0, 0x7B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7B0));
;}
RECOMP_FUNC void func_800C3FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3FC0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3FC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3FC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3FCC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C3FD0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C3FD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3FD8: jal         0x800C2840
    // 0x800C3FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C3FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3FE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3FE8: jr          $ra
    // 0x800C3FEC: nop

    return;
    // 0x800C3FEC: nop

;}
RECOMP_FUNC void func_80800068_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080006C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080007C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1336, 0X4DC) << 16);
    // 0x80800080: addiu       $a3, $a3, 0x4DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1336, 0X4DC));
    // 0x80800084: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800088: jal         0x80089D50
    // 0x8080008C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080008C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800090: jal         0x800D8FF8
    // 0x80800094: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800094: nop

    after_1:
    // 0x80800098: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080009C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000A0: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808000A4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808000A8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000B4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808000B8: bne         $t7, $at, L_80800140
    if (ctx->r15 != ctx->r1) {
        // 0x808000BC: swc1        $f10, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
            goto L_80800140;
    }
    // 0x808000BC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x808000C0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808000C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000C8: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808000D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808000D8: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x808000DC: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000E0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808000E4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808000E8: jal         0x800C8E54
    // 0x808000EC: nop

    func_800C8E54(rdram, ctx);
        goto after_2;
    // 0x808000EC: nop

    after_2:
    // 0x808000F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1336, 0X4F4) << 16);
    // 0x808000F4: addiu       $a1, $a1, 0x4F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1336, 0X4F4));
    // 0x808000F8: jal         0x800C8E84
    // 0x808000FC: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    after_3:
    // 0x80800100: lw          $a0, 0x54($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X54);
    // 0x80800104: jal         0x800C8CB8
    // 0x80800108: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80800108: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x8080010C: jal         0x8080021C
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_changlerbossflare(rdram, ctx);
        goto after_5;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800114: jal         0x808003A4
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003A4_changlerbossflare(rdram, ctx);
        goto after_6;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080011C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800120: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x80800124: jal         0x8010B990
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_7;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080012C: andi        $t8, $v0, 0x20
    ctx->r24 = ctx->r2 & 0X20;
    // 0x80800130: beql        $t8, $zero, L_80800144
    if (ctx->r24 == 0) {
        // 0x80800134: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800144;
    }
    goto skip_0;
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800138: jal         0x80800190
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800190_changlerbossflare(rdram, ctx);
        goto after_8;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800140:
    // 0x80800140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800144:
    // 0x80800144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080014C: jr          $ra
    // 0x80800150: nop

    return;
    // 0x80800150: nop

;}
RECOMP_FUNC void func_80800440_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080044C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800450: addiu       $a1, $zero, 0x93F
    ctx->r5 = ADD32(0, 0X93F);
    // 0x80800454: jal         0x80800394
    // 0x80800458: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800394_chballoonbomb(rdram, ctx);
        goto after_0;
    // 0x80800458: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $a1, $zero, 0x940
    ctx->r5 = ADD32(0, 0X940);
    // 0x80800464: jal         0x80800394
    // 0x80800468: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80800394_chballoonbomb(rdram, ctx);
        goto after_1;
    // 0x80800468: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: addiu       $a1, $zero, 0x941
    ctx->r5 = ADD32(0, 0X941);
    // 0x80800474: jal         0x80800394
    // 0x80800478: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800394_chballoonbomb(rdram, ctx);
        goto after_2;
    // 0x80800478: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8080047C: jal         0x80800400
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800400_chballoonbomb(rdram, ctx);
        goto after_3;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800484: jal         0x80800354
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800354_chballoonbomb(rdram, ctx);
        goto after_4;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080048C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800498: jr          $ra
    // 0x8080049C: nop

    return;
    // 0x8080049C: nop

;}
RECOMP_FUNC void func_80800000_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80100094
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080000C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800018: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8080001C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800020: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80800024: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800028: swc1        $f0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f0.u32l;
    // 0x8080002C: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80800030: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x80800034: swc1        $f0, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f0.u32l;
L_80800038:
    // 0x80800038: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080003C: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80800040: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80800044: swc1        $f0, 0x98($v1)
    MEM_W(0X98, ctx->r3) = ctx->f0.u32l;
    // 0x80800048: swc1        $f0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f0.u32l;
    // 0x8080004C: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80800050: swc1        $f0, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->f0.u32l;
    // 0x80800054: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80800058: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8080005C: swc1        $f0, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = ctx->f0.u32l;
    // 0x80800060: swc1        $f0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f0.u32l;
    // 0x80800064: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80800068: swc1        $f0, 0xC0($v1)
    MEM_W(0XC0, ctx->r3) = ctx->f0.u32l;
    // 0x8080006C: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80800070: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80800074: swc1        $f0, 0xA0($v1)
    MEM_W(0XA0, ctx->r3) = ctx->f0.u32l;
    // 0x80800078: swc1        $f0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f0.u32l;
    // 0x8080007C: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80800080: swc1        $f0, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f0.u32l;
    // 0x80800084: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800088: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x8080008C: swc1        $f0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80800090: swc1        $f0, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->f0.u32l;
    // 0x80800094: swc1        $f0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f0.u32l;
    // 0x80800098: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x8080009C: bne         $a0, $a1, L_80800038
    if (ctx->r4 != ctx->r5) {
        // 0x808000A0: swc1        $f0, 0xA8($v1)
        MEM_W(0XA8, ctx->r3) = ctx->f0.u32l;
            goto L_80800038;
    }
    // 0x808000A0: swc1        $f0, 0xA8($v1)
    MEM_W(0XA8, ctx->r3) = ctx->f0.u32l;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void mlMtxRotRoll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001907C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80019084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019088: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8001908C: nop

    // 0x80019090: bc1tl       L_80019104
    if (c1cs) {
        // 0x80019094: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019104;
    }
    goto skip_0;
    // 0x80019094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80019098: jal         0x800137F4
    // 0x8001909C: nop

    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x8001909C: nop

    after_0:
    // 0x800190A0: jal         0x80013788
    // 0x800190A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800190A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800190A8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x800190AC: lw          $v0, -0x4350($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4350);
    // 0x800190B0: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800190B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800190B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800190BC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
L_800190C0:
    // 0x800190C0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800190C4: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800190C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800190CC: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800190D0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800190D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800190D8: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800190DC: nop

    // 0x800190E0: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800190E4: nop

    // 0x800190E8: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800190EC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800190F0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x800190F4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800190F8: bne         $a0, $a1, L_800190C0
    if (ctx->r4 != ctx->r5) {
        // 0x800190FC: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_800190C0;
    }
    // 0x800190FC: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80019100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019104:
    // 0x80019104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019108: jr          $ra
    // 0x8001910C: nop

    return;
    // 0x8001910C: nop

;}
RECOMP_FUNC void func_80115618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115618: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8011561C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80115624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80115628: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8011562C: jal         0x80110840
    // 0x80115630: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80115630: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    after_0:
    // 0x80115634: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80115638: jal         0x800F6C5C
    // 0x8011563C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_1;
    // 0x8011563C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80115640: beq         $v0, $zero, L_8011573C
    if (ctx->r2 == 0) {
        // 0x80115644: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_8011573C;
    }
    // 0x80115644: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80115648: jal         0x800F5680
    // 0x8011564C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F5680(rdram, ctx);
        goto after_2;
    // 0x8011564C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x80115650: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80115654: lwc1        $f4, 0x6610($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6610);
    // 0x80115658: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8011565C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80115660: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80115664: nop

    // 0x80115668: bc1fl       L_80115740
    if (!c1cs) {
        // 0x8011566C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115740;
    }
    goto skip_0;
    // 0x8011566C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80115670: jal         0x801107B0
    // 0x80115674: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_801107B0(rdram, ctx);
        goto after_3;
    // 0x80115674: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80115678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011567C: jal         0x801107F0
    // 0x80115680: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_801107F0(rdram, ctx);
        goto after_4;
    // 0x80115680: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80115684: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80115688: jal         0x800EF3DC
    // 0x8011568C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF3DC(rdram, ctx);
        goto after_5;
    // 0x8011568C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80115690: jal         0x800EF2A0
    // 0x80115694: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EF2A0(rdram, ctx);
        goto after_6;
    // 0x80115694: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x80115698: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8011569C: jal         0x800EEAA4
    // 0x801156A0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EEAA4(rdram, ctx);
        goto after_7;
    // 0x801156A0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_7:
    // 0x801156A4: jal         0x80013A7C
    // 0x801156A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013A7C(rdram, ctx);
        goto after_8;
    // 0x801156A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x801156AC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801156B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801156B4: jal         0x800F1DCC
    // 0x801156B8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_9;
    // 0x801156B8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_9:
    // 0x801156BC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801156C0: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801156C4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801156C8: jal         0x80013728
    // 0x801156CC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    func_80013728(rdram, ctx);
        goto after_10;
    // 0x801156CC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_10:
    // 0x801156D0: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x801156D4: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x801156D8: beql        $t6, $zero, L_80115704
    if (ctx->r14 == 0) {
        // 0x801156DC: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80115704;
    }
    goto skip_1;
    // 0x801156DC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_1:
    // 0x801156E0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801156E4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x801156E8: nop

    // 0x801156EC: bc1fl       L_80115718
    if (!c1cs) {
        // 0x801156F0: lbu         $t9, 0x12($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X12);
            goto L_80115718;
    }
    goto skip_2;
    // 0x801156F0: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    skip_2:
    // 0x801156F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801156F8: b           L_80115714
    // 0x801156FC: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
        goto L_80115714;
    // 0x801156FC: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80115700: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80115704:
    // 0x80115704: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80115708: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8011570C: sb          $t7, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r15;
    // 0x80115710: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
L_80115714:
    // 0x80115714: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
L_80115718:
    // 0x80115718: beql        $t9, $zero, L_80115740
    if (ctx->r25 == 0) {
        // 0x8011571C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115740;
    }
    goto skip_3;
    // 0x8011571C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80115720: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80115724: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80115728: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8011572C: nop

    // 0x80115730: bc1fl       L_80115740
    if (!c1cs) {
        // 0x80115734: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115740;
    }
    goto skip_4;
    // 0x80115734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80115738: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_8011573C:
    // 0x8011573C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80115740:
    // 0x80115740: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80115744: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80115748: jr          $ra
    // 0x8011574C: nop

    return;
    // 0x8011574C: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888F0: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x800888F0);
    return;
    // 0x800888F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AAEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAEF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800AAEF8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800AAEFC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800AAF00: mul.s       $f20, $f12, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800AAF04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800AAF08: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800AAF0C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800AAF10: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800AAF14: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800AAF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AAF1C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800AAF20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800AAF24: jal         0x800AADEC
    // 0x800AAF28: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800AADEC(rdram, ctx);
        goto after_0;
    // 0x800AAF28: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800AAF2C: bne         $v0, $zero, L_800AAF3C
    if (ctx->r2 != 0) {
        // 0x800AAF30: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_800AAF3C;
    }
    // 0x800AAF30: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x800AAF34: b           L_800AAFD8
    // 0x800AAF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AAFD8;
    // 0x800AAF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AAF3C:
    // 0x800AAF3C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AAF40: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800AAF44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AAF48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800AAF4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AAF50: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800AAF54: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800AAF58: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800AAF5C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AAF60: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AAF64: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800AAF68: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800AAF6C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800AAF70: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800AAF74: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AAF78: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800AAF7C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AAF80: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800AAF84: jal         0x800EFA4C
    // 0x800AAF88: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800AAF88: nop

    after_1:
    // 0x800AAF8C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800AAF90: jal         0x800EEB40
    // 0x800AAF94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x800AAF94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x800AAF98: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800AAF9C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800AAFA0: jal         0x800EEB40
    // 0x800AAFA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x800AAFA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800AAFA8: add.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f20.fl;
    // 0x800AAFAC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AAFB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AAFB4: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800AAFB8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800AAFBC: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800AAFC0: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x800AAFC4: nop

    // 0x800AAFC8: bc1f        L_800AAFD8
    if (!c1cs) {
        // 0x800AAFCC: nop
    
            goto L_800AAFD8;
    }
    // 0x800AAFCC: nop

    // 0x800AAFD0: b           L_800AAFD8
    // 0x800AAFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AAFD8;
    // 0x800AAFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AAFD8:
    // 0x800AAFD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AAFDC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800AAFE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800AAFE4: jr          $ra
    // 0x800AAFE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800AAFE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void chflysaucer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E18: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1692, 0X470C) << 16);
    // 0x80803E1C: jr          $ra
    // 0x80803E20: addiu       $v0, $v0, 0x470C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1692, 0X470C));
    return;
    // 0x80803E20: addiu       $v0, $v0, 0x470C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1692, 0X470C));
    // 0x80803E24: nop

    // 0x80803E28: nop

    // 0x80803E2C: nop

;}
RECOMP_FUNC void _bskazflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083360: syscall     56
    recomp_syscall_handler(rdram, ctx, 0x80083360);
    return;
    // 0x80083364: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808009EC_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808009F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808009F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808009FC: jal         0x8008CABC
    // 0x80800A00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800A04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A08: jal         0x8080055C
    // 0x80800A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bsbabykaz_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800A10: jal         0x8008AF24
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: jal         0x8008AED4
    // 0x80800A20: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800A20: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_3:
    // 0x80800A24: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800A28: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800A2C: jal         0x8008B1BC
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A34: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800A38: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800A3C: jal         0x8008B1C8
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A44: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800A48: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800A4C: jal         0x8008B24C
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A54: lui         $a2, 0x3F01
    ctx->r6 = S32(0X3F01 << 16);
    // 0x80800A58: ori         $a2, $a2, 0x1340
    ctx->r6 = ctx->r6 | 0X1340;
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A60: jal         0x8008B1D4
    // 0x80800A64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x80800A64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x8008B134
    // 0x80800A70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800A70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800A74: jal         0x8008B064
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800A7C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800A80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A90: jal         0x8009FFD8
    // 0x80800A94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x80800A94: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x80800A98: jal         0x8009EF04
    // 0x80800A9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x80800A9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800AA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800AA4: nop

    // 0x80800AA8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800AAC: nop

    // 0x80800AB0: bc1t        L_80800ACC
    if (c1cs) {
        // 0x80800AB4: nop
    
            goto L_80800ACC;
    }
    // 0x80800AB4: nop

    // 0x80800AB8: jal         0x8009EEB8
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x80800ABC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80800AC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AC4: jal         0x8009C914
    // 0x80800AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x80800AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
L_80800ACC:
    // 0x80800ACC: jal         0x8009C990
    // 0x80800AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x80800AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80800AD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AD8: jal         0x8009B9C0
    // 0x80800ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x80800ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800AE0: jal         0x80800134
    // 0x80800AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800134_bsbabykaz(rdram, ctx);
        goto after_16;
    // 0x80800AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x80800AE8: jal         0x8009C990
    // 0x80800AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80800AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800AF0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800AF4: jal         0x8009BB00
    // 0x80800AF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800AF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800AFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800B00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B04: jal         0x8009BA68
    // 0x80800B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800B08: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x80800B0C: lui         $a1, 0x43ED
    ctx->r5 = S32(0X43ED << 16);
    // 0x80800B10: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800B14: jal         0x8009BA58
    // 0x80800B18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80800B18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80800B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B20: jal         0x8009BCB4
    // 0x80800B24: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80800B24: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_21:
    // 0x80800B28: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800B2C: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800B30: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800B34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B38: jal         0x8009DE38
    // 0x80800B3C: addiu       $a1, $zero, 0x432
    ctx->r5 = ADD32(0, 0X432);
    func_8009DE38(rdram, ctx);
        goto after_22;
    // 0x80800B3C: addiu       $a1, $zero, 0x432
    ctx->r5 = ADD32(0, 0X432);
    after_22:
    // 0x80800B40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B44: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B48: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800B4C: jr          $ra
    // 0x80800B50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800B50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void suspline_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800858: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080085C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800860: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800864: jal         0x808000F4
    // 0x80800868: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    suspline_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800868: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080086C: bnel        $v0, $zero, L_808008CC
    if (ctx->r2 != 0) {
        // 0x80800870: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008CC;
    }
    goto skip_0;
    // 0x80800870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800874: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800878: lwc1        $f6, 0x64($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8080087C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80800880: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x80800884: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1tl       L_808008CC
    if (c1cs) {
        // 0x80800890: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008CC;
    }
    goto skip_1;
    // 0x80800890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800894: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800898: jal         0x800EECE0
    // 0x8080089C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EECE0(rdram, ctx);
        goto after_1;
    // 0x8080089C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x808008A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008A4: bne         $v0, $zero, L_808008C8
    if (ctx->r2 != 0) {
        // 0x808008A8: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808008C8;
    }
    // 0x808008A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008AC: jal         0x800EEAD4
    // 0x808008B0: nop

    func_800EEAD4(rdram, ctx);
        goto after_2;
    // 0x808008B0: nop

    after_2:
    // 0x808008B4: lwc1        $f10, 0x64($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
    // 0x808008B8: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808008BC: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808008C0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808008C4: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
L_808008C8:
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008CC:
    // 0x808008CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008D4: jr          $ra
    // 0x808008D8: nop

    return;
    // 0x808008D8: nop

;}
RECOMP_FUNC void chbounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800628: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8080062C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800630: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80800634: lwc1        $f4, 0x48($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80800638: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(712, 0X1000) << 16);
    // 0x80800640: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800644: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800648: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8080064C: jal         0x80800190
    // 0x80800650: swc1        $f4, 0x1000($at)
    MEM_W((int16_t)RELOC_LO16(712, 0X1000), ctx->r1) = ctx->f4.u32l;
    func_80800190_chbounce(rdram, ctx);
        goto after_0;
    // 0x80800650: swc1        $f4, 0x1000($at)
    MEM_W((int16_t)RELOC_LO16(712, 0X1000), ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893F0: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893F0);
    return;
    // 0x800893F4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chbaddiesetup_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808005DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808005E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808005E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808005E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005EC: jal         0x80108454
    // 0x808005F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80108454(rdram, ctx);
        goto after_0;
    // 0x808005F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void chmolehill_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800868: jal         0x80100094
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080086C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800874: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80800878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080087C: jr          $ra
    // 0x80800880: nop

    return;
    // 0x80800880: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834F8: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834F8);
    return;
    // 0x800834FC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800554_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800558: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080055C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800560: jal         0x8009C128
    // 0x80800564: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800564: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800568: jal         0x800A4C48
    // 0x8080056C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x8080056C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800574: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800578: jal         0x800CA3F4
    // 0x8080057C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800CA3F4(rdram, ctx);
        goto after_2;
    // 0x8080057C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x80800580: jal         0x800B5BE4
    // 0x80800584: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_3;
    // 0x80800584: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_3:
    // 0x80800588: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(404, 0X2328) << 16);
    // 0x8080058C: addiu       $t6, $t6, 0x2328
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(404, 0X2328));
    // 0x80800590: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800594: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800598: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080059C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808005A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005A4: jal         0x800BABB8
    // 0x808005A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808005A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x808005AC: jal         0x800A4C48
    // 0x808005B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A4C48(rdram, ctx);
        goto after_5;
    // 0x808005B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x808005B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005B8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808005BC: jal         0x800CA3F4
    // 0x808005C0: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800CA3F4(rdram, ctx);
        goto after_6;
    // 0x808005C0: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_6:
    // 0x808005C4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(404, 0X23C8) << 16);
    // 0x808005C8: addiu       $t7, $t7, 0x23C8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(404, 0X23C8));
    // 0x808005CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808005D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808005D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005DC: jal         0x800BABB8
    // 0x808005E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x808005E0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x808005E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005EC: jr          $ra
    // 0x808005F0: nop

    return;
    // 0x808005F0: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BD8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BD8);
    return;
    // 0x80087BDC: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084088: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x80084088);
    return;
    // 0x8008408C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800C0C_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C10: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800C14: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C1C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80800C20: jal         0x8009C128
    // 0x80800C24: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800C24: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80800C28: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800C2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C30: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C38: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800C3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800C40: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    // 0x80800C44: jal         0x8009FBB0
    // 0x80800C48: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_1;
    // 0x80800C48: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800C4C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80800C50: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80800C54: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80800C58: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800C5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80800C60: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800C64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C6C: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800C70: addiu       $a2, $zero, -0x32
    ctx->r6 = ADD32(0, -0X32);
    // 0x80800C74: jal         0x800BA930
    // 0x80800C78: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    func_800BA930(rdram, ctx);
        goto after_2;
    // 0x80800C78: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    after_2:
    // 0x80800C7C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800C80: jal         0x800BA22C
    // 0x80800C84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800C84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800C88: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800C8C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800C90: jal         0x8008CB10
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800C98: beq         $v0, $zero, L_80800CA8
    if (ctx->r2 == 0) {
        // 0x80800C9C: nop
    
            goto L_80800CA8;
    }
    // 0x80800C9C: nop

    // 0x80800CA0: jal         0x800951B4
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_5;
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800CA8:
    // 0x80800CA8: jal         0x8008CABC
    // 0x80800CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_6;
    // 0x80800CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800CB0: jal         0x8008B324
    // 0x80800CB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800CB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800CB8: beq         $v0, $zero, L_80800CC8
    if (ctx->r2 == 0) {
        // 0x80800CBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CC8;
    }
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC0: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x80800CC4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
L_80800CC8:
    // 0x80800CC8: jal         0x8009E5C8
    // 0x80800CCC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800CCC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x80800CD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CD4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800CD8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800CDC: jr          $ra
    // 0x80800CE0: nop

    return;
    // 0x80800CE0: nop

;}
RECOMP_FUNC void func_8010CCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CCEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010CCF0: addiu       $a1, $a1, 0x6F68
    ctx->r5 = ADD32(ctx->r5, 0X6F68);
    // 0x8010CCF4: lw          $v1, 0x24($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X24);
    // 0x8010CCF8: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x8010CCFC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8010CD00: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8010CD04: bne         $at, $zero, L_8010CD14
    if (ctx->r1 != 0) {
        // 0x8010CD08: addu        $t8, $a1, $t7
        ctx->r24 = ADD32(ctx->r5, ctx->r15);
            goto L_8010CD14;
    }
    // 0x8010CD08: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8010CD0C: jr          $ra
    // 0x8010CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8010CD10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010CD14:
    // 0x8010CD14: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8010CD18: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8010CD1C: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
    // 0x8010CD20: jr          $ra
    // 0x8010CD24: nop

    return;
    // 0x8010CD24: nop

;}
RECOMP_FUNC void func_80800418_chdinofamilymissing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800420: jal         0x80101F24
    // 0x80800424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800424: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800428: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2260, 0X6AC) << 16);
    // 0x8080042C: addiu       $a1, $a1, 0x6AC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2260, 0X6AC));
    // 0x80800430: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800434: jal         0x800F3780
    // 0x80800438: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x80800438: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8080043C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800444: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800448: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080044C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800450: bne         $t7, $at, L_80800464
    if (ctx->r15 != ctx->r1) {
        // 0x80800454: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80800464;
    }
    // 0x80800454: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800458: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080045C: b           L_80800474
    // 0x80800460: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
        goto L_80800474;
    // 0x80800460: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80800464:
    // 0x80800464: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800468: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080046C: nop

    // 0x80800470: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80800474:
    // 0x80800474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800478: nop

    // 0x8080047C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800480: nop

    // 0x80800484: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800488: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080048C: jal         0x80105A9C
    // 0x80800490: nop

    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80800490: nop

    after_2:
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void func_800AE0B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE0B8: beq         $a0, $zero, L_800AE0C8
    if (ctx->r4 == 0) {
        // 0x800AE0BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800AE0C8;
    }
    // 0x800AE0BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800AE0C0: jr          $ra
    // 0x800AE0C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    return;
    // 0x800AE0C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800AE0C8:
    // 0x800AE0C8: jr          $ra
    // 0x800AE0CC: nop

    return;
    // 0x800AE0CC: nop

;}
