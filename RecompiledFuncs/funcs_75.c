#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801724_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080172C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801730: lbu         $v0, 0x7F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7F);
    // 0x80801734: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801738: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080173C: beq         $v0, $at, L_80801760
    if (ctx->r2 == ctx->r1) {
        // 0x80801740: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801760;
    }
    // 0x80801740: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801744: bnel        $v0, $at, L_80801764
    if (ctx->r2 != ctx->r1) {
        // 0x80801748: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80801764;
    }
    goto skip_0;
    // 0x80801748: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080174C: jal         0x800F54E4
    // 0x80801750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801750: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801754: jal         0x800F4CC0
    // 0x80801758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_1;
    // 0x80801758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080175C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80801760:
    // 0x80801760: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80801764:
    // 0x80801764: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801768: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x8080176C: beq         $v0, $at, L_80801794
    if (ctx->r2 == ctx->r1) {
        // 0x80801770: sb          $t6, 0x7F($a2)
        MEM_B(0X7F, ctx->r6) = ctx->r14;
            goto L_80801794;
    }
    // 0x80801770: sb          $t6, 0x7F($a2)
    MEM_B(0X7F, ctx->r6) = ctx->r14;
    // 0x80801774: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801778: bnel        $v0, $at, L_80801798
    if (ctx->r2 != ctx->r1) {
        // 0x8080177C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801798;
    }
    goto skip_1;
    // 0x8080177C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801780: jal         0x800F54E4
    // 0x80801784: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80801784: nop

    after_2:
    // 0x80801788: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080178C: jal         0x800F4CEC
    // 0x80801790: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    func_800F4CEC(rdram, ctx);
        goto after_3;
    // 0x80801790: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_3:
L_80801794:
    // 0x80801794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801798:
    // 0x80801798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080179C: jr          $ra
    // 0x808017A0: nop

    return;
    // 0x808017A0: nop

;}
RECOMP_FUNC void func_80800024_chmole_hailfire(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void func_8001DDE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DDE0: sw          $ra, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r31;
    // 0x8001DDE4: jr          $ra
    // 0x8001DDE8: sw          $sp, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r29;
    return;
    // 0x8001DDE8: sw          $sp, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r29;
;}
RECOMP_FUNC void _badrone_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084898: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084898);
    return;
    // 0x8008489C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80800174_chmrsboggyhome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080017C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1400, 0X238) << 16);
    // 0x80800180: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1400, 0X1B0) << 16);
    // 0x80800184: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800188: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080018C: addiu       $a3, $a3, 0x1B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1400, 0X1B0));
    // 0x80800190: addiu       $a2, $a2, 0x238
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1400, 0X238));
    // 0x80800194: jal         0x8008A1F0
    // 0x80800198: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800198: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080019C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

    // 0x808001AC: nop

;}
RECOMP_FUNC void chmumboskullfakearchpanellava_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1960, 0X1E0) << 16);
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1960, 0X1E0));
    return;
    // 0x80800128: addiu       $v0, $v0, 0x1E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1960, 0X1E0));
;}
RECOMP_FUNC void _chjiggygamenew_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B40: syscall     197
    recomp_syscall_handler(rdram, ctx, 0x80085B40);
    return;
    // 0x80085B44: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800962D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800962D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800962D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800962DC: jal         0x8009C150
    // 0x800962E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x800962E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800962E4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800962E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800962EC: lw          $t7, 0x94($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X94);
    // 0x800962F0: jal         0x800C6784
    // 0x800962F4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800C6784(rdram, ctx);
        goto after_1;
    // 0x800962F4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x800962F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800962FC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80096300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096304: jr          $ra
    // 0x80096308: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x80096308: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void func_80800000_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80096544
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: beql        $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800014: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800018: jal         0x800DC0C0
    // 0x8080001C: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080001C: nop

    after_1:
    // 0x80800020: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800028: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800034: nop

    // 0x80800038: bc1f        L_80800050
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800050;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x80092C00
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800048: b           L_8080005C
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_8080005C;
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800050:
    // 0x80800050: jal         0x80092C24
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80092C24(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800058: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_8080005C:
    // 0x8080005C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800060: jal         0x8009FBB0
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009FBB0(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x80800068: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8080006C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80800070: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800074: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080007C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800080: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800084: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x80800088: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    // 0x8080008C: jal         0x800BA930
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80800094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: jal         0x800BA22C
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_80800054_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800058: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080005C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800060: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800064: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800068: jal         0x8010C908
    // 0x8080006C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8010C908(rdram, ctx);
        goto after_0;
    // 0x8080006C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800070: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800074: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800078: bltzl       $t8, L_808002C4
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080007C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808002C4;
    }
    goto skip_0;
    // 0x8080007C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80800080: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800088: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x8080008C: beq         $t9, $at, L_808000AC
    if (ctx->r25 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000AC;
    }
    // 0x80800090: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800094: beq         $t9, $at, L_8080011C
    if (ctx->r25 == ctx->r1) {
        // 0x80800098: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080011C;
    }
    // 0x80800098: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080009C: beql        $t9, $at, L_808002C4
    if (ctx->r25 == ctx->r1) {
        // 0x808000A0: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808002C4;
    }
    goto skip_1;
    // 0x808000A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808000A4: b           L_808002C4
    // 0x808000A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808002C4;
    // 0x808000A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808000AC:
    // 0x808000AC: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808000B0: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x808000B4: bgez        $t2, L_808000EC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808000B8: nop
    
            goto L_808000EC;
    }
    // 0x808000B8: nop

    // 0x808000BC: jal         0x8080064C
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlavagargoyle(rdram, ctx);
        goto after_1;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C4: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80089BD8
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000D4: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808000D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80102424
    // 0x808000E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808000E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808000E4: b           L_808002C4
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808002C4;
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808000EC:
    // 0x808000EC: jal         0x800D90A4
    // 0x808000F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x808000F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x808000F4: beql        $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x808000F8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808002C4;
    }
    goto skip_2;
    // 0x808000F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x808000FC: jal         0x8080064C
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlavagargoyle(rdram, ctx);
        goto after_5;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800104: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80102424
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800110: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800114: b           L_808002C4
    // 0x80800118: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
        goto L_808002C4;
    // 0x80800118: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8080011C:
    // 0x8080011C: jal         0x80101F24
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x80101DDC
    // 0x8080012C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_80101DDC(rdram, ctx);
        goto after_8;
    // 0x8080012C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80800130: beq         $v0, $zero, L_80800190
    if (ctx->r2 == 0) {
        // 0x80800134: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80800190;
    }
    // 0x80800134: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800138: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x8080013C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800140: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80800144: bgezl       $t5, L_80800160
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800148: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80800160;
    }
    goto skip_3;
    // 0x80800148: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_3:
    // 0x8080014C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800154: b           L_80800174
    // 0x80800158: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800174;
    // 0x80800158: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8080015C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80800160:
    // 0x80800160: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800164: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800168: jal         0x800DC178
    // 0x8080016C: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x8080016C: nop

    after_9:
    // 0x80800170: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800174:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80102424
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800180: jal         0x80089D40
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800188: b           L_8080027C
    // 0x8080018C: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
        goto L_8080027C;
    // 0x8080018C: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
L_80800190:
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCC0) << 16);
    // 0x80800194: lwc1        $f6, 0xCC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCC0));
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808001A0: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x808001A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001A8: addiu       $a3, $zero, 0x9C4
    ctx->r7 = ADD32(0, 0X9C4);
    // 0x808001AC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2324, 0XD2C) << 16);
    // 0x808001B0: bc1f        L_80800204
    if (!c1cs) {
        // 0x808001B4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2324, 0XCC8) << 16);
            goto L_80800204;
    }
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCC8) << 16);
    // 0x808001B8: addiu       $t6, $t6, 0xD2C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2324, 0XD2C));
    // 0x808001BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001C0: jal         0x80089D58
    // 0x808001C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x808001C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_12:
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCC4) << 16);
    // 0x808001CC: lwc1        $f8, 0xCC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCC4));
    // 0x808001D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001D4: lui         $a2, 0x3EB3
    ctx->r6 = S32(0X3EB3 << 16);
    // 0x808001D8: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808001DC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808001E0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001E4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808001E8: jal         0x800F10B4
    // 0x808001EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x808001EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x808001F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F4: jal         0x80089D30
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808001FC: b           L_8080027C
    // 0x80800200: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
        goto L_8080027C;
    // 0x80800200: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
L_80800204:
    // 0x80800204: lwc1        $f10, 0xCC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCC8));
    // 0x80800208: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2324, 0XD2C) << 16);
    // 0x8080020C: addiu       $t7, $t7, 0xD2C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2324, 0XD2C));
    // 0x80800210: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080021C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800220: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800224: addiu       $a3, $zero, 0x9C4
        ctx->r7 = ADD32(0, 0X9C4);
            goto L_80800270;
    }
    // 0x80800224: addiu       $a3, $zero, 0x9C4
    ctx->r7 = ADD32(0, 0X9C4);
    // 0x80800228: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080022C: jal         0x80089D58
    // 0x80800230: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x80800230: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80800234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCCC) << 16);
    // 0x80800238: lwc1        $f14, 0xCCC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCCC));
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCD0) << 16);
    // 0x80800240: lwc1        $f16, 0xCD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCD0));
    // 0x80800244: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80800248: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080024C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800250: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800254: jal         0x800F10B4
    // 0x80800258: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800258: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x8080025C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800260: jal         0x80089D30
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800268: b           L_8080027C
    // 0x8080026C: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
        goto L_8080027C;
    // 0x8080026C: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
L_80800270:
    // 0x80800270: jal         0x80089D40
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800278: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
L_8080027C:
    // 0x8080027C: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x80800280: jal         0x80101E14
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_19;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800288: beql        $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x8080028C: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808002C4;
    }
    goto skip_4;
    // 0x8080028C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80800290: jal         0x8080064C
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlavagargoyle(rdram, ctx);
        goto after_20;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800298: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80108B04
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_21;
    // 0x808002A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808002A8: lui         $a0, 0xA63B
    ctx->r4 = S32(0XA63B << 16);
    // 0x808002AC: lui         $a2, 0xFA0
    ctx->r6 = S32(0XFA0 << 16);
    // 0x808002B0: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808002B4: ori         $a0, $a0, 0x5DD1
    ctx->r4 = ctx->r4 | 0X5DD1;
    // 0x808002B8: jal         0x800C4140
    // 0x808002BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C4140(rdram, ctx);
        goto after_22;
    // 0x808002BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_22:
L_808002C0:
    // 0x808002C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808002C4:
    // 0x808002C4: jal         0x8010262C
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010262C(rdram, ctx);
        goto after_23;
    // 0x808002C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x808002CC: beq         $v0, $zero, L_80800380
    if (ctx->r2 == 0) {
        // 0x808002D0: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_80800380;
    }
    // 0x808002D0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808002D4: jal         0x800F54E4
    // 0x808002D8: nop

    func_800F54E4(rdram, ctx);
        goto after_24;
    // 0x808002D8: nop

    after_24:
    // 0x808002DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E0: jal         0x800F5A00
    // 0x808002E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_25;
    // 0x808002E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_25:
    // 0x808002E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002EC: jal         0x800F1DF4
    // 0x808002F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1DF4(rdram, ctx);
        goto after_26;
    // 0x808002F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_26:
    // 0x808002F4: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002F8: jal         0x80013728
    // 0x808002FC: sub.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f18.fl;
    func_80013728(rdram, ctx);
        goto after_27;
    // 0x808002FC: sub.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f18.fl;
    after_27:
    // 0x80800300: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80800304: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800308: jal         0x80013728
    // 0x8080030C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_80013728(rdram, ctx);
        goto after_28;
    // 0x8080030C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_28:
    // 0x80800310: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800314: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800318: jal         0x80013728
    // 0x8080031C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80013728(rdram, ctx);
        goto after_29;
    // 0x8080031C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_29:
    // 0x80800320: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800324: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800328: jal         0x800F0D50
    // 0x8080032C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    func_800F0D50(rdram, ctx);
        goto after_30;
    // 0x8080032C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    after_30:
    // 0x80800330: jal         0x800136E4
    // 0x80800334: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_31;
    // 0x80800334: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_31:
    // 0x80800338: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8080033C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800340: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800344: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800348: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080034C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800350: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800354: jal         0x800F1FF0
    // 0x80800358: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_32;
    // 0x80800358: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_32:
    // 0x8080035C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800360: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800364: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800368: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080036C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800370: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800374: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800378: jal         0x800E0AFC
    // 0x8080037C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_33;
    // 0x8080037C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_33:
L_80800380:
    // 0x80800380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800384: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800388: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088188: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088188);
    return;
    // 0x8008818C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808002E4_chhellterskeltermouth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002EC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(976, 0X384) << 16);
    // 0x808002F0: addiu       $a3, $a3, 0x384
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(976, 0X384));
    // 0x808002F4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808002F8: jal         0x80089D50
    // 0x808002FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808002FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void func_808003D0_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: lh          $t6, 0x2C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2C);
    // 0x808003D4: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(3390, 0XA70) << 16);
    // 0x808003D8: addiu       $v1, $v1, 0xA70
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(3390, 0XA70));
    // 0x808003DC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x808003E0: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x808003E4: addiu       $t8, $a0, 0x34
    ctx->r24 = ADD32(ctx->r4, 0X34);
    // 0x808003E8: addiu       $t9, $a0, 0x38
    ctx->r25 = ADD32(ctx->r4, 0X38);
    // 0x808003EC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x808003F0: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x808003F4: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x808003F8: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x808003FC: lh          $t0, 0x8($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X8);
    // 0x80800400: addiu       $a1, $zero, -0x4
    ctx->r5 = ADD32(0, -0X4);
    // 0x80800404: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80800408: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8080040C: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80800410: addiu       $t3, $t2, 0x38
    ctx->r11 = ADD32(ctx->r10, 0X38);
    // 0x80800414: sw          $t3, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r11;
    // 0x80800418: lbu         $t5, 0xE($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XE);
    // 0x8080041C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80800420: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80800424: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x80800428: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x8080042C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80800430: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800434: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x80800438: addiu       $t4, $t2, 0x3
    ctx->r12 = ADD32(ctx->r10, 0X3);
    // 0x8080043C: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
    // 0x80800440: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x80800444: and         $t6, $t4, $a1
    ctx->r14 = ctx->r12 & ctx->r5;
    // 0x80800448: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x8080044C: lh          $t7, 0xC($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XC);
    // 0x80800450: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800454: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x80800458: addiu       $t2, $t0, 0xF
    ctx->r10 = ADD32(ctx->r8, 0XF);
    // 0x8080045C: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x80800460: sw          $t2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r10;
    // 0x80800464: and         $t4, $t2, $at
    ctx->r12 = ctx->r10 & ctx->r1;
    // 0x80800468: sw          $t4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r12;
    // 0x8080046C: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x80800470: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800474: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x80800478: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8080047C: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x80800480: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80800484: addu        $t2, $t0, $t8
    ctx->r10 = ADD32(ctx->r8, ctx->r24);
    // 0x80800488: sw          $t2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r10;
    // 0x8080048C: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80800490: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800494: addu        $t6, $t4, $t2
    ctx->r14 = ADD32(ctx->r12, ctx->r10);
    // 0x80800498: sw          $t6, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r14;
    // 0x8080049C: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x808004A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808004A4: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x808004A8: jr          $ra
    // 0x808004AC: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
    return;
    // 0x808004AC: sw          $t0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r8;
;}
RECOMP_FUNC void chfactorybattery_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801500: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2276, 0X1BA8) << 16);
    // 0x80801504: jr          $ra
    // 0x80801508: addiu       $v0, $v0, 0x1BA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2276, 0X1BA8));
    return;
    // 0x80801508: addiu       $v0, $v0, 0x1BA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2276, 0X1BA8));
;}
RECOMP_FUNC void func_80013728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013728: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001372C: lwc1        $f0, 0x16BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16BC);
    // 0x80013730: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80013734: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013738: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001373C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013740: nop

    // 0x80013744: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80013748: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001374C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80013750: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80013754: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013758: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8001375C: neg.s       $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = -ctx->f4.fl;
    // 0x80013760: bc1tl       L_80013774
    if (c1cs) {
        // 0x80013764: c.lt.s      $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
            goto L_80013774;
    }
    goto skip_0;
    // 0x80013764: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    skip_0:
    // 0x80013768: jr          $ra
    // 0x8001376C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    return;
    // 0x8001376C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80013770: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
L_80013774:
    // 0x80013774: bc1f        L_80013780
    if (!c1cs) {
        // 0x80013778: nop
    
            goto L_80013780;
    }
    // 0x80013778: nop

    // 0x8001377C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_80013780:
    // 0x80013780: jr          $ra
    // 0x80013784: nop

    return;
    // 0x80013784: nop

;}
RECOMP_FUNC void func_800E79E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E79E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E79EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E79F0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E79F4: lui         $t8, 0x12
    ctx->r24 = S32(0X12 << 16);
    // 0x800E79F8: addiu       $t8, $t8, 0x3310
    ctx->r24 = ADD32(ctx->r24, 0X3310);
    // 0x800E79FC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7A00: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7A04: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800E7A08: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E7A0C: jal         0x800E7620
    // 0x800E7A10: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    func_800E7620(rdram, ctx);
        goto after_0;
    // 0x800E7A10: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    after_0:
    // 0x800E7A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7A18: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E7A1C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E7A20: sb          $t9, -0x2A5B($at)
    MEM_B(-0X2A5B, ctx->r1) = ctx->r25;
    // 0x800E7A24: jr          $ra
    // 0x800E7A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800E7A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80803990_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803994: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803998: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080399C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808039A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808039A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808039A8: jal         0x80100094
    // 0x808039AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808039AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808039B0: jal         0x800B8C50
    // 0x808039B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800B8C50(rdram, ctx);
        goto after_1;
    // 0x808039B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808039B8: jal         0x80089C90
    // 0x808039BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808039BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808039C0: jal         0x800B8C8C
    // 0x808039C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_3;
    // 0x808039C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808039C8: jal         0x800B8C98
    // 0x808039CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800B8C98(rdram, ctx);
        goto after_4;
    // 0x808039CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x808039D0: jal         0x800B8CB0
    // 0x808039D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B8CB0(rdram, ctx);
        goto after_5;
    // 0x808039D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808039D8: jal         0x800B7F14
    // 0x808039DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B7F14(rdram, ctx);
        goto after_6;
    // 0x808039DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808039E0: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x808039E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808039E8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808039EC: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808039F0: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x808039F4: beq         $v0, $at, L_80803A30
    if (ctx->r2 == ctx->r1) {
        // 0x808039F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803A30;
    }
    // 0x808039F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808039FC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80803A00: bne         $v0, $at, L_80803A5C
    if (ctx->r2 != ctx->r1) {
        // 0x80803A04: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803A5C;
    }
    // 0x80803A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803A08: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80803A0C: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x80803A10: jal         0x800B8F88
    // 0x80803A14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800B8F88(rdram, ctx);
        goto after_7;
    // 0x80803A14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80803A18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803A1C: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
    // 0x80803A20: jal         0x800B8F88
    // 0x80803A24: addiu       $a2, $s0, 0x40
    ctx->r6 = ADD32(ctx->r16, 0X40);
    func_800B8F88(rdram, ctx);
        goto after_8;
    // 0x80803A24: addiu       $a2, $s0, 0x40
    ctx->r6 = ADD32(ctx->r16, 0X40);
    after_8:
    // 0x80803A28: b           L_80803A5C
    // 0x80803A2C: nop

        goto L_80803A5C;
    // 0x80803A2C: nop

L_80803A30:
    // 0x80803A30: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    // 0x80803A34: jal         0x800B8F88
    // 0x80803A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800B8F88(rdram, ctx);
        goto after_9;
    // 0x80803A38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x80803A3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803A40: addiu       $a1, $zero, 0xC2
    ctx->r5 = ADD32(0, 0XC2);
    // 0x80803A44: jal         0x800B8F88
    // 0x80803A48: addiu       $a2, $s0, 0x40
    ctx->r6 = ADD32(ctx->r16, 0X40);
    func_800B8F88(rdram, ctx);
        goto after_10;
    // 0x80803A48: addiu       $a2, $s0, 0x40
    ctx->r6 = ADD32(ctx->r16, 0X40);
    after_10:
    // 0x80803A4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803A50: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
    // 0x80803A54: jal         0x800B8F88
    // 0x80803A58: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    func_800B8F88(rdram, ctx);
        goto after_11;
    // 0x80803A58: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    after_11:
L_80803A5C:
    // 0x80803A5C: jal         0x800B811C
    // 0x80803A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800B811C(rdram, ctx);
        goto after_12;
    // 0x80803A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80803A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803A68: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803A6C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803A70: jr          $ra
    // 0x80803A74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803A74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840E8: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840E8);
    return;
    // 0x800840EC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _bafpctrl_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CE8: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CE8);
    return;
    // 0x80084CEC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _chswitch_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085820: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085820);
    return;
    // 0x80085824: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bskazshock_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800470: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(272, 0X7A4) << 16);
    // 0x80800474: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800478: jr          $ra
    // 0x8080047C: lw          $v0, 0x7A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(272, 0X7A4));
    return;
    // 0x8080047C: lw          $v0, 0x7A4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(272, 0X7A4));
;}
RECOMP_FUNC void func_808008F4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800900: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800904: jal         0x800C429C
    // 0x80800908: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800C429C(rdram, ctx);
        goto after_0;
    // 0x80800908: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8080090C: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x80800910: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800914: jal         0x800C3418
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_1;
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080091C: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800920: jal         0x800C34CC
    // 0x80800924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C34CC(rdram, ctx);
        goto after_2;
    // 0x80800924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800928: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080092C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80800930: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800934: lh          $v0, 0x172($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X172);
    // 0x80800938: beq         $v0, $at, L_80800948
    if (ctx->r2 == ctx->r1) {
        // 0x8080093C: addiu       $at, $zero, 0xBB
        ctx->r1 = ADD32(0, 0XBB);
            goto L_80800948;
    }
    // 0x8080093C: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80800940: bnel        $v0, $at, L_80800954
    if (ctx->r2 != ctx->r1) {
        // 0x80800944: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800954;
    }
    goto skip_0;
    // 0x80800944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800948:
    // 0x80800948: jal         0x800C32C4
    // 0x8080094C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C32C4(rdram, ctx);
        goto after_3;
    // 0x8080094C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800954:
    // 0x80800954: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80800958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080095C: jr          $ra
    // 0x80800960: nop

    return;
    // 0x80800960: nop

;}
RECOMP_FUNC void func_808007DC_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E4: jal         0x800839B8
    // 0x808007E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808007E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007EC: jal         0x800832E8
    // 0x808007F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808007F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007FC: jr          $ra
    // 0x80800800: nop

    return;
    // 0x80800800: nop

;}
RECOMP_FUNC void func_800D7E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7E38: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800D7E3C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800D7E40: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800D7E44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800D7E48: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800D7E4C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800D7E50: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D7E54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7E58: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800D7E5C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800D7E60: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800D7E64: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800D7E68: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800D7E6C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800D7E70: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800D7E74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D7E78: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800D7E7C: jal         0x8001B798
    // 0x800D7E80: lh          $a0, -0x400A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400A);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D7E80: lh          $a0, -0x400A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400A);
    after_0:
    // 0x800D7E84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D7E88: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D7E8C: jal         0x80105494
    // 0x800D7E90: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    func_80105494(rdram, ctx);
        goto after_1;
    // 0x800D7E90: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_1:
    // 0x800D7E94: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x800D7E98: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800D7E9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D7EA0: jal         0x8001B798
    // 0x800D7EA4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x800D7EA4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_2:
    // 0x800D7EA8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800D7EAC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x800D7EB0: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x800D7EB4: bne         $a1, $zero, L_800D7EC4
    if (ctx->r5 != 0) {
        // 0x800D7EB8: addiu       $a2, $zero, -0x270F
        ctx->r6 = ADD32(0, -0X270F);
            goto L_800D7EC4;
    }
    // 0x800D7EB8: addiu       $a2, $zero, -0x270F
    ctx->r6 = ADD32(0, -0X270F);
    // 0x800D7EBC: b           L_800D803C
    // 0x800D7EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D803C;
    // 0x800D7EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D7EC4:
    // 0x800D7EC4: bne         $s2, $a2, L_800D7ED4
    if (ctx->r18 != ctx->r6) {
        // 0x800D7EC8: addiu       $a3, $zero, 0x14
        ctx->r7 = ADD32(0, 0X14);
            goto L_800D7ED4;
    }
    // 0x800D7EC8: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800D7ECC: b           L_800D7ED8
    // 0x800D7ED0: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
        goto L_800D7ED8;
    // 0x800D7ED0: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
L_800D7ED4:
    // 0x800D7ED4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800D7ED8:
    // 0x800D7ED8: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D7EDC: lw          $s2, 0x7C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X7C);
    // 0x800D7EE0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800D7EE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D7EE8: sll         $t2, $s2, 2
    ctx->r10 = S32(ctx->r18 << 2);
    // 0x800D7EEC: addu        $t2, $t2, $s2
    ctx->r10 = ADD32(ctx->r10, ctx->r18);
    // 0x800D7EF0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800D7EF4: sll         $s2, $t2, 2
    ctx->r18 = S32(ctx->r10 << 2);
    // 0x800D7EF8: addiu       $s6, $s6, -0x46E0
    ctx->r22 = ADD32(ctx->r22, -0X46E0);
    // 0x800D7EFC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800D7F00: mflo        $t8
    ctx->r24 = lo;
    // 0x800D7F04: addu        $s0, $t8, $v0
    ctx->r16 = ADD32(ctx->r24, ctx->r2);
    // 0x800D7F08: bne         $s3, $a2, L_800D7F18
    if (ctx->r19 != ctx->r6) {
        // 0x800D7F0C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800D7F18;
    }
    // 0x800D7F0C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800D7F10: b           L_800D7F18
    // 0x800D7F14: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
        goto L_800D7F18;
    // 0x800D7F14: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
L_800D7F18:
    // 0x800D7F18: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D7F1C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800D7F20: mflo        $a1
    ctx->r5 = lo;
    // 0x800D7F24: addu        $t0, $a1, $v0
    ctx->r8 = ADD32(ctx->r5, ctx->r2);
    // 0x800D7F28: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x800D7F2C: beq         $s0, $t1, L_800D8008
    if (ctx->r16 == ctx->r9) {
        // 0x800D7F30: addu        $s4, $a1, $s7
        ctx->r20 = ADD32(ctx->r5, ctx->r23);
            goto L_800D8008;
    }
    // 0x800D7F30: addu        $s4, $a1, $s7
    ctx->r20 = ADD32(ctx->r5, ctx->r23);
    // 0x800D7F34: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800D7F38: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800D7F3C: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
L_800D7F40:
    // 0x800D7F40: bne         $at, $zero, L_800D7F58
    if (ctx->r1 != 0) {
        // 0x800D7F44: nop
    
            goto L_800D7F58;
    }
    // 0x800D7F44: nop

    // 0x800D7F48: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800D7F4C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800D7F50: beql        $t4, $zero, L_800D7F74
    if (ctx->r12 == 0) {
        // 0x800D7F54: lw          $t7, 0x0($s6)
        ctx->r15 = MEM_W(ctx->r22, 0X0);
            goto L_800D7F74;
    }
    goto skip_0;
    // 0x800D7F54: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    skip_0:
L_800D7F58:
    // 0x800D7F58: bgezl       $s2, L_800D7FF8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800D7F5C: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_800D7FF8;
    }
    goto skip_1;
    // 0x800D7F5C: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    skip_1:
    // 0x800D7F60: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x800D7F64: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800D7F68: bnel        $s5, $t6, L_800D7FF8
    if (ctx->r21 != ctx->r14) {
        // 0x800D7F6C: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_800D7FF8;
    }
    goto skip_2;
    // 0x800D7F6C: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    skip_2:
    // 0x800D7F70: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
L_800D7F74:
    // 0x800D7F74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7F78: addiu       $a0, $a0, -0x4190
    ctx->r4 = ADD32(ctx->r4, -0X4190);
    // 0x800D7F7C: bne         $s3, $t7, L_800D7F8C
    if (ctx->r19 != ctx->r15) {
        // 0x800D7F80: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_800D7F8C;
    }
    // 0x800D7F80: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800D7F84: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800D7F88: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_800D7F8C:
    // 0x800D7F8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800D7F90: jal         0x800884F8
    // 0x800D7F94: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    _glsplinenode_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x800D7F94: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_3:
    // 0x800D7F98: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x800D7F9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7FA0: c.eq.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl == ctx->f2.fl;
    // 0x800D7FA4: nop

    // 0x800D7FA8: bc1fl       L_800D7FC8
    if (!c1cs) {
        // 0x800D7FAC: lwc1        $f0, 0xC($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
            goto L_800D7FC8;
    }
    goto skip_3;
    // 0x800D7FAC: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    skip_3:
    // 0x800D7FB0: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800D7FB4: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x800D7FB8: nop

    // 0x800D7FBC: bc1tl       L_800D7FF8
    if (c1cs) {
        // 0x800D7FC0: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_800D7FF8;
    }
    goto skip_4;
    // 0x800D7FC0: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    skip_4:
    // 0x800D7FC4: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
L_800D7FC8:
    // 0x800D7FC8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800D7FCC: nop

    // 0x800D7FD0: bc1fl       L_800D7FF0
    if (!c1cs) {
        // 0x800D7FD4: swc1        $f20, 0x38($s1)
        MEM_W(0X38, ctx->r17) = ctx->f20.u32l;
            goto L_800D7FF0;
    }
    goto skip_5;
    // 0x800D7FD4: swc1        $f20, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f20.u32l;
    skip_5:
    // 0x800D7FD8: lwc1        $f8, 0x3C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800D7FDC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800D7FE0: nop

    // 0x800D7FE4: bc1tl       L_800D7FF8
    if (c1cs) {
        // 0x800D7FE8: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_800D7FF8;
    }
    goto skip_6;
    // 0x800D7FE8: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    skip_6:
    // 0x800D7FEC: swc1        $f20, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f20.u32l;
L_800D7FF0:
    // 0x800D7FF0: swc1        $f20, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f20.u32l;
    // 0x800D7FF4: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
L_800D7FF8:
    // 0x800D7FF8: beq         $s0, $s4, L_800D8008
    if (ctx->r16 == ctx->r20) {
        // 0x800D7FFC: nop
    
            goto L_800D8008;
    }
    // 0x800D7FFC: nop

    // 0x800D8000: bnel        $v1, $s3, L_800D7F40
    if (ctx->r3 != ctx->r19) {
        // 0x800D8004: slti        $at, $s2, 0x14
        ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
            goto L_800D7F40;
    }
    goto skip_7;
    // 0x800D8004: slti        $at, $s2, 0x14
    ctx->r1 = SIGNED(ctx->r18) < 0X14 ? 1 : 0;
    skip_7:
L_800D8008:
    // 0x800D8008: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800D800C: addiu       $s6, $s6, -0x46E0
    ctx->r22 = ADD32(ctx->r22, -0X46E0);
    // 0x800D8010: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800D8014: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800D8018: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D801C: bne         $s3, $t8, L_800D803C
    if (ctx->r19 != ctx->r24) {
        // 0x800D8020: nop
    
            goto L_800D803C;
    }
    // 0x800D8020: nop

    // 0x800D8024: bne         $v1, $s3, L_800D803C
    if (ctx->r3 != ctx->r19) {
        // 0x800D8028: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800D803C;
    }
    // 0x800D8028: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D802C: lwc1        $f10, 0x5CEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5CEC);
    // 0x800D8030: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800D8034: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800D8038: swc1        $f18, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f18.u32l;
L_800D803C:
    // 0x800D803C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800D8040: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800D8044: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D8048: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800D804C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800D8050: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800D8054: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800D8058: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800D805C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800D8060: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800D8064: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800D8068: jr          $ra
    // 0x800D806C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800D806C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800F9ADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9AE4: jal         0x800F9488
    // 0x800F9AE8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800F9488(rdram, ctx);
        goto after_0;
    // 0x800F9AE8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x800F9AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F9AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9AF4: jr          $ra
    // 0x800F9AF8: nop

    return;
    // 0x800F9AF8: nop

;}
RECOMP_FUNC void chcablecar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(972, 0XEB0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xEB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(972, 0XEB0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xEB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(972, 0XEB0));
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A530: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A530);
    return;
    // 0x8008A534: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800C54_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800C60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800C64: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80800C68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800C6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C70: blez        $t6, L_80800CA0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800C74: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800CA0;
    }
    // 0x80800C74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800C78:
    // 0x80800C78: jal         0x808003F4
    // 0x80800C7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808003F4_gcmapsects(rdram, ctx);
        goto after_0;
    // 0x80800C7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C84: jal         0x8080035C
    // 0x80800C88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080035C_gcmapsects(rdram, ctx);
        goto after_1;
    // 0x80800C88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800C8C: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    // 0x80800C90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800C94: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800C98: bnel        $at, $zero, L_80800C78
    if (ctx->r1 != 0) {
        // 0x80800C9C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800C78;
    }
    goto skip_0;
    // 0x80800C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80800CA0:
    // 0x80800CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800CA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800CAC: jr          $ra
    // 0x80800CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808001B4_bsbreegullbash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: jal         0x80084538
    // 0x808001C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _babackpack_set_state(rdram, ctx);
        goto after_0;
    // 0x808001C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void cheggproximity_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D0: jal         0x80106790
    // 0x808002D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808002DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002E0: jal         0x80100094
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002E8: lh          $t6, 0x3A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3A);
    // 0x808002EC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808002F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808002F4: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    // 0x808002F8: srl         $t8, $a0, 22
    ctx->r24 = S32(U32(ctx->r4) >> 22);
    // 0x808002FC: jal         0x800883B8
    // 0x80800300: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _gcegg_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800300: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80800304: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800308: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080030C: jal         0x80087340
    // 0x80800310: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _cheggsplode_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800310: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80800314: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800318: jal         0x8008A398
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suegg_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_80800074_suspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: bgez        $a1, L_80800084
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80800078: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_80800084;
    }
    // 0x80800078: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8080007C: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80800080: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_80800084:
    // 0x80800084: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800088: lbu         $t8, 0x7E($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X7E);
    // 0x8080008C: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x80800090: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800094: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80800098: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x8080009C: beq         $t2, $zero, L_808000AC
    if (ctx->r10 == 0) {
        // 0x808000A0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808000AC;
    }
    // 0x808000A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000A4: jr          $ra
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000AC:
    // 0x808000AC: jr          $ra
    // 0x808000B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800000_bsbflip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800020: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800038;
    }
    // 0x80800020: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800030: b           L_80800058
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800040: jal         0x800F1214
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_3:
    // 0x80800048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_800FC7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC7C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC7C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC7CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC7D0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC7D4: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FC7D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC7DC: addiu       $s1, $s1, 0x59B0
    ctx->r17 = ADD32(ctx->r17, 0X59B0);
    // 0x800FC7E0: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC7E4: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
L_800FC7E8:
    // 0x800FC7E8: bltzl       $t6, L_800FC7FC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800FC7EC: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC7FC;
    }
    goto skip_0;
    // 0x800FC7EC: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC7F0: jal         0x800FB774
    // 0x800FC7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB774(rdram, ctx);
        goto after_0;
    // 0x800FC7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FC7F8: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC7FC:
    // 0x800FC7FC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800FC800: bnel        $at, $zero, L_800FC7E8
    if (ctx->r1 != 0) {
        // 0x800FC804: lh          $t6, 0x28($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X28);
            goto L_800FC7E8;
    }
    goto skip_1;
    // 0x800FC804: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    skip_1:
    // 0x800FC808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC80C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC814: jr          $ra
    // 0x800FC818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8009CFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFD8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009CFDC: lw          $t6, 0xFC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XFC);
    // 0x8009CFE0: jr          $ra
    // 0x8009CFE4: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009CFE4: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void bskazmove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A8: jal         0x8009EF1C
    // 0x808000AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000B4: jal         0x8009EF10
    // 0x808000B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808000B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808000BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000C0: jal         0x8008E39C
    // 0x808000C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8008E39C(rdram, ctx);
        goto after_2;
    // 0x808000C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x808000C8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808000CC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D4: beql        $v1, $zero, L_808000F8
    if (ctx->r3 == 0) {
        // 0x808000D8: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_808000F8;
    }
    goto skip_0;
    // 0x808000D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x808000DC: beq         $v1, $at, L_80800108
    if (ctx->r3 == ctx->r1) {
        // 0x808000E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800108;
    }
    // 0x808000E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E4: beq         $v1, $at, L_80800154
    if (ctx->r3 == ctx->r1) {
        // 0x808000E8: nop
    
            goto L_80800154;
    }
    // 0x808000E8: nop

    // 0x808000EC: b           L_808001A0
    // 0x808000F0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
        goto L_808001A0;
    // 0x808000F0: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808000F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_808000F8:
    // 0x808000F8: nop

    // 0x808000FC: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80800100: b           L_8080019C
    // 0x80800104: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
        goto L_8080019C;
    // 0x80800104: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
L_80800108:
    // 0x80800108: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x8080010C: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_8080013C;
    }
    // 0x8080010C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800110: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800114: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800118: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8080011C: jal         0x80800000
    // 0x80800120: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80800000_bskazmove(rdram, ctx);
        goto after_3;
    // 0x80800120: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80800124: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800128: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080012C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800130: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80800134: b           L_808001A0
    // 0x80800138: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
        goto L_808001A0;
    // 0x80800138: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
L_8080013C:
    // 0x8080013C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800140: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800148: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8080014C: b           L_8080019C
    // 0x80800150: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
        goto L_8080019C;
    // 0x80800150: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80800154:
    // 0x80800154: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x80800158: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80800188;
    }
    // 0x80800158: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080015C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800160: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800164: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800168: jal         0x80800000
    // 0x8080016C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80800000_bskazmove(rdram, ctx);
        goto after_4;
    // 0x8080016C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80800170: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800178: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080017C: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80800180: b           L_8080019C
    // 0x80800184: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
        goto L_8080019C;
    // 0x80800184: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
L_80800188:
    // 0x80800188: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080018C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800190: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800194: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80800198: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_8080019C:
    // 0x8080019C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
L_808001A0:
    // 0x808001A0: jal         0x800F1214
    // 0x808001A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x808001A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808001A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001AC: jal         0x8009B9B0
    // 0x808001B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808001B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void func_8010E924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E924: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010E928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E92C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8010E930: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8010E934: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010E938: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8010E93C: jal         0x800C8800
    // 0x8010E940: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800C8800(rdram, ctx);
        goto after_0;
    // 0x8010E940: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8010E944: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8010E948: jal         0x800C883C
    // 0x8010E94C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800C883C(rdram, ctx);
        goto after_1;
    // 0x8010E94C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8010E950: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8010E954: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010E958: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010E95C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8010E960: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010E964: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010E968: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8010E96C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8010E970: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010E974: mul.s       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8010E978: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8010E97C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8010E980: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010E984: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8010E988: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8010E98C: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8010E990: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8010E994: jal         0x8002DCA0
    // 0x8010E998: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8010E998: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x8010E99C: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010E9A0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8010E9A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8010E9A8: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8010E9AC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8010E9B0: nop

    // 0x8010E9B4: bc1f        L_8010E9C4
    if (!c1cs) {
        // 0x8010E9B8: nop
    
            goto L_8010E9C4;
    }
    // 0x8010E9B8: nop

    // 0x8010E9BC: b           L_8010EABC
    // 0x8010E9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010EABC;
    // 0x8010E9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010E9C4:
    // 0x8010E9C4: jal         0x8010E81C
    // 0x8010E9C8: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_8010E81C(rdram, ctx);
        goto after_3;
    // 0x8010E9C8: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x8010E9CC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8010E9D0: bne         $v0, $zero, L_8010E9E0
    if (ctx->r2 != 0) {
        // 0x8010E9D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010E9E0;
    }
    // 0x8010E9D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010E9D8: b           L_8010EABC
    // 0x8010E9DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010EABC;
    // 0x8010E9DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010E9E0:
    // 0x8010E9E0: swc1        $f12, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f12.u32l;
    // 0x8010E9E4: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8010E9E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8010E9EC: jal         0x800193C4
    // 0x8010E9F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800193C4(rdram, ctx);
        goto after_4;
    // 0x8010E9F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x8010E9F4: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010E9F8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8010E9FC: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8010EA00: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8010EA04: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8010EA08: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x8010EA0C: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8010EA10: nop

    // 0x8010EA14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8010EA18: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010EA1C: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010EA20: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8010EA24: nop

    // 0x8010EA28: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8010EA2C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010EA30: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8010EA34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010EA38: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8010EA3C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8010EA40: nop

    // 0x8010EA44: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x8010EA48: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010EA4C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010EA50: div.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8010EA54: div.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010EA58: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8010EA5C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8010EA60: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8010EA64: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x8010EA68: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8010EA6C: nop

    // 0x8010EA70: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8010EA74: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010EA78: mul.s       $f18, $f6, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8010EA7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010EA80: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010EA84: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8010EA88: nop

    // 0x8010EA8C: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x8010EA90: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010EA94: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010EA98: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8010EA9C: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8010EAA0: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010EAA4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8010EAA8: nop

    // 0x8010EAAC: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
    // 0x8010EAB0: jal         0x800C8900
    // 0x8010EAB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800C8900(rdram, ctx);
        goto after_5;
    // 0x8010EAB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8010EAB8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_8010EABC:
    // 0x8010EABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010EAC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8010EAC4: jr          $ra
    // 0x8010EAC8: nop

    return;
    // 0x8010EAC8: nop

;}
RECOMP_FUNC void _sutempleboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A368: syscall     839
    recomp_syscall_handler(rdram, ctx, 0x8008A368);
    return;
    // 0x8008A36C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chsabreman_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086370: syscall     314
    recomp_syscall_handler(rdram, ctx, 0x80086370);
    return;
    // 0x80086374: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chtorpedo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2160, 0X95C) << 16);
    // 0x80800830: jr          $ra
    // 0x80800834: addiu       $v0, $v0, 0x95C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2160, 0X95C));
    return;
    // 0x80800834: addiu       $v0, $v0, 0x95C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2160, 0X95C));
    // 0x80800838: nop

    // 0x8080083C: nop

;}
RECOMP_FUNC void func_8080183C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080183C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801844: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080184C: jal         0x80100094
    // 0x80801850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801854: lbu         $t6, 0x494($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X494);
    // 0x80801858: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080185C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801860: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80801864: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80801868: beq         $t8, $zero, L_80801878
    if (ctx->r24 == 0) {
        // 0x8080186C: sb          $t7, 0x494($v0)
        MEM_B(0X494, ctx->r2) = ctx->r15;
            goto L_80801878;
    }
    // 0x8080186C: sb          $t7, 0x494($v0)
    MEM_B(0X494, ctx->r2) = ctx->r15;
    // 0x80801870: b           L_8080187C
    // 0x80801874: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8080187C;
    // 0x80801874: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80801878:
    // 0x80801878: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
L_8080187C:
    // 0x8080187C: jal         0x8008A4F0
    // 0x80801880: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _subaddieDll_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80801880: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80801884: lh          $t9, 0x28($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X28);
    // 0x80801888: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8080188C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80801890: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80801894: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801898: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080189C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808018A0: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x808018A4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808018A8: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x808018AC: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x808018B0: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x808018B4: nop

    // 0x808018B8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808018BC: jal         0x800DC178
    // 0x808018C0: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808018C0: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    after_2:
    // 0x808018C4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808018C8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808018CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808018D0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808018D4: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808018D8: jal         0x800DC178
    // 0x808018DC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808018DC: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x808018E0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808018E4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x808018E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808018EC: sb          $t1, 0x497($v1)
    MEM_B(0X497, ctx->r3) = ctx->r9;
    // 0x808018F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808018FC: jr          $ra
    // 0x80801900: nop

    return;
    // 0x80801900: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C00: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C00);
    return;
    // 0x80083C04: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80803678_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080367C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803680: jal         0x800D37C0
    // 0x80803684: nop

    func_800D37C0(rdram, ctx);
        goto after_0;
    // 0x80803684: nop

    after_0:
    // 0x80803688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080368C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803690: jr          $ra
    // 0x80803694: nop

    return;
    // 0x80803694: nop

;}
RECOMP_FUNC void baphysics_get_target_horizontal_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB00: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BB04: jr          $ra
    // 0x8009BB08: lwc1        $f0, 0x3C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X3C);
    return;
    // 0x8009BB08: lwc1        $f0, 0x3C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X3C);
;}
RECOMP_FUNC void chscreenadjust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(788, 0X430) << 16);
    // 0x80800418: jr          $ra
    // 0x8080041C: addiu       $v0, $v0, 0x430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(788, 0X430));
    return;
    // 0x8080041C: addiu       $v0, $v0, 0x430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(788, 0X430));
;}
RECOMP_FUNC void _bamovegoto_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DD8: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DD8);
    return;
    // 0x80084DDC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80803424_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803424: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803428: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080342C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80803430: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80803434: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803438: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080343C: jal         0x808033A0
    // 0x80803440: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_808033A0_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80803440: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80803444: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80803448: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080344C: jal         0x800DC128
    // 0x80803450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80803450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80803454: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80803458: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080345C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80803460: blez        $a2, L_808034C0
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80803464: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808034C0;
    }
    // 0x80803464: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80803468:
    // 0x80803468: jal         0x80803524
    // 0x8080346C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80803524_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080346C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80803470: bne         $v0, $zero, L_808034A4
    if (ctx->r2 != 0) {
        // 0x80803474: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_808034A4;
    }
    // 0x80803474: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80803478: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080347C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803480: jal         0x80803558
    // 0x80803484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803558_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80803484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80803488: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080348C: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(1480, 0X9F28) << 16);
    // 0x80803490: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80803494: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80803498: lhu         $t8, -0x60D8($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(1480, 0X9F28));
    // 0x8080349C: b           L_8080350C
    // 0x808034A0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
        goto L_8080350C;
    // 0x808034A0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
L_808034A4:
    // 0x808034A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808034A8: bne         $s0, $a2, L_808034B4
    if (ctx->r16 != ctx->r6) {
        // 0x808034AC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808034B4;
    }
    // 0x808034AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808034B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808034B4:
    // 0x808034B4: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808034B8: bnel        $at, $zero, L_80803468
    if (ctx->r1 != 0) {
        // 0x808034BC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803468;
    }
    goto skip_0;
    // 0x808034BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_808034C0:
    // 0x808034C0: addiu       $a1, $a2, 0x7
    ctx->r5 = ADD32(ctx->r6, 0X7);
    // 0x808034C4: sra         $t9, $a1, 3
    ctx->r25 = S32(SIGNED(ctx->r5) >> 3);
    // 0x808034C8: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x808034CC: jal         0x8002D6E0
    // 0x808034D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _bzero(rdram, ctx);
        goto after_4;
    // 0x808034D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x808034D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808034D8: jal         0x800DC128
    // 0x808034DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x808034DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808034E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808034E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808034E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808034EC: jal         0x80803558
    // 0x808034F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803558_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808034F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808034F4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808034F8: lui         $t2, 0x8081
    ctx->r10 = S32(RELOC_HI16(1480, 0X9F28) << 16);
    // 0x808034FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80803500: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80803504: lhu         $t2, -0x60D8($t2)
    ctx->r10 = MEM_HU(ctx->r10, (int16_t)RELOC_LO16(1480, 0X9F28));
    // 0x80803508: addu        $v0, $t2, $s0
    ctx->r2 = ADD32(ctx->r10, ctx->r16);
L_8080350C:
    // 0x8080350C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803514: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80803518: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080351C: jr          $ra
    // 0x80803520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80803520: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800A1694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1694: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800A1698: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A169C: jr          $ra
    // 0x800A16A0: sb          $t6, 0x7097($at)
    MEM_B(0X7097, ctx->r1) = ctx->r14;
    return;
    // 0x800A16A0: sb          $t6, 0x7097($at)
    MEM_B(0X7097, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_808034A0_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808034A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808034A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808034AC: jal         0x80100094
    // 0x808034B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808034B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808034B4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808034B8: lbu         $t6, 0x64($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X64);
    // 0x808034BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808034C0: beq         $t6, $zero, L_80803518
    if (ctx->r14 == 0) {
        // 0x808034C4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80803518;
    }
    // 0x808034C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808034C8: jal         0x800EE7F8
    // 0x808034CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808034CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x808034D0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808034D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808034D8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808034DC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808034E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808034E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808034E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808034EC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x808034F0: jal         0x80087900
    // 0x808034F4: lh          $a0, 0x78($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X78);
    _plcamera_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808034F4: lh          $a0, 0x78($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X78);
    after_2:
    // 0x808034F8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808034FC: jal         0x800F5EF8
    // 0x80803500: lh          $a0, 0x78($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X78);
    func_800F5EF8(rdram, ctx);
        goto after_3;
    // 0x80803500: lh          $a0, 0x78($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X78);
    after_3:
    // 0x80803504: jal         0x80110014
    // 0x80803508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_4;
    // 0x80803508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8080350C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803510: jal         0x80116088
    // 0x80803514: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80116088(rdram, ctx);
        goto after_5;
    // 0x80803514: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
L_80803518:
    // 0x80803518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080351C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803520: jr          $ra
    // 0x80803524: nop

    return;
    // 0x80803524: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087900: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087900);
    return;
    // 0x80087904: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bstnt_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FC8: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FC8);
    return;
    // 0x80083FCC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
