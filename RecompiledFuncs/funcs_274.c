#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void gcdialogexec_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801B68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801B70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801B74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801B78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801B7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B80: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x80801B84: lbu         $t8, 0x11D($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X11D);
    // 0x80801B88: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801B8C: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80801B90: andi        $t9, $t8, 0xFF3F
    ctx->r25 = ctx->r24 & 0XFF3F;
    // 0x80801B94: sb          $t7, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r15;
    // 0x80801B98: jal         0x800C0638
    // 0x80801B9C: sb          $t9, 0x11D($a0)
    MEM_B(0X11D, ctx->r4) = ctx->r25;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x80801B9C: sb          $t9, 0x11D($a0)
    MEM_B(0X11D, ctx->r4) = ctx->r25;
    after_0:
    // 0x80801BA0: beq         $v0, $zero, L_80801BB8
    if (ctx->r2 == 0) {
        // 0x80801BA4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801BB8;
    }
    // 0x80801BA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801BA8: jal         0x80800A50
    // 0x80801BAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80801BAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80801BB0: b           L_80801C48
    // 0x80801BB4: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
        goto L_80801C48;
    // 0x80801BB4: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
L_80801BB8:
    // 0x80801BB8: lbu         $t0, 0x15C($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X15C);
    // 0x80801BBC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801BC0: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80801BC4: beq         $t0, $at, L_80801C44
    if (ctx->r8 == ctx->r1) {
        // 0x80801BC8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801C44;
    }
    // 0x80801BC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801BCC: lbu         $t1, 0x15F($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X15F);
    // 0x80801BD0: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80801BD4: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80801BD8: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x80801BDC: sb          $t2, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r10;
L_80801BE0:
    // 0x80801BE0: lbu         $t3, 0x11C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X11C);
    // 0x80801BE4: andi        $t4, $t3, 0xFF3F
    ctx->r12 = ctx->r11 & 0XFF3F;
    // 0x80801BE8: sb          $t4, 0x11C($s0)
    MEM_B(0X11C, ctx->r16) = ctx->r12;
    // 0x80801BEC: lw          $a0, 0x120($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X120);
    // 0x80801BF0: beql        $a0, $zero, L_80801C20
    if (ctx->r4 == 0) {
        // 0x80801BF4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801C20;
    }
    goto skip_0;
    // 0x80801BF4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x80801BF8: jal         0x80087BE8
    // 0x80801BFC: nop

    _gczoombox_entrypoint_33(rdram, ctx);
        goto after_2;
    // 0x80801BFC: nop

    after_2:
    // 0x80801C00: lw          $t6, 0x15C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X15C);
    // 0x80801C04: lbu         $t0, 0x15F($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X15F);
    // 0x80801C08: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x80801C0C: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x80801C10: andi        $t1, $t0, 0xFFFC
    ctx->r9 = ctx->r8 & 0XFFFC;
    // 0x80801C14: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801C18: sb          $t2, 0x15F($s3)
    MEM_B(0X15F, ctx->r19) = ctx->r10;
    // 0x80801C1C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80801C20:
    // 0x80801C20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801C24: bne         $s1, $s4, L_80801BE0
    if (ctx->r17 != ctx->r20) {
        // 0x80801C28: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80801BE0;
    }
    // 0x80801C28: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80801C2C: lw          $t3, 0x15C($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X15C);
    // 0x80801C30: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80801C34: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80801C38: beql        $t4, $zero, L_80801C48
    if (ctx->r12 == 0) {
        // 0x80801C3C: lbu         $t6, 0x161($s3)
        ctx->r14 = MEM_BU(ctx->r19, 0X161);
            goto L_80801C48;
    }
    goto skip_1;
    // 0x80801C3C: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
    skip_1:
    // 0x80801C40: sb          $t5, 0x15C($s3)
    MEM_B(0X15C, ctx->r19) = ctx->r13;
L_80801C44:
    // 0x80801C44: lbu         $t6, 0x161($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X161);
L_80801C48:
    // 0x80801C48: andi        $t8, $t6, 0xFF0F
    ctx->r24 = ctx->r14 & 0XFF0F;
    // 0x80801C4C: sb          $t8, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r24;
    // 0x80801C50: andi        $t0, $t8, 0xF0
    ctx->r8 = ctx->r24 & 0XF0;
    // 0x80801C54: sb          $t0, 0x161($s3)
    MEM_B(0X161, ctx->r19) = ctx->r8;
    // 0x80801C58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801C5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801C60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801C64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801C68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C70: jr          $ra
    // 0x80801C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801C74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsjump_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083290: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083290);
    return;
    // 0x80083294: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80809D94_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809D94: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809D98: jr          $ra
    // 0x80809D9C: lwc1        $f0, 0x25C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X25C);
    return;
    // 0x80809D9C: lwc1        $f0, 0x25C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X25C);
;}
RECOMP_FUNC void _chgoldsnakehead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085970: syscall     183
    recomp_syscall_handler(rdram, ctx, 0x80085970);
    return;
    // 0x80085974: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800090_chmole_prehist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1836, 0XC0) << 16);
    // 0x8080009C: jal         0x800899F0
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1836, 0XC0));
    _sumole_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1836, 0XC0));
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void chappearfx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006A4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808006A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808006AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808006B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808006B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808006B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006C0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006C4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x808006C8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808006CC: addiu       $a0, $a0, 0x62E8
    ctx->r4 = ADD32(ctx->r4, 0X62E8);
    // 0x808006D0: jal         0x80086D48
    // 0x808006D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808006D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x808006D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006E0: jr          $ra
    // 0x808006E4: nop

    return;
    // 0x808006E4: nop

;}
RECOMP_FUNC void func_80801B64_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B68: beq         $a1, $zero, L_80801B94
    if (ctx->r5 == 0) {
        // 0x80801B6C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801B94;
    }
    // 0x80801B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B74: beq         $a1, $at, L_80801BA4
    if (ctx->r5 == ctx->r1) {
        // 0x80801B78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801BA4;
    }
    // 0x80801B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B7C: beq         $a1, $at, L_80801BB4
    if (ctx->r5 == ctx->r1) {
        // 0x80801B80: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801BB4;
    }
    // 0x80801B80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801B84: beq         $a1, $at, L_80801BC4
    if (ctx->r5 == ctx->r1) {
        // 0x80801B88: nop
    
            goto L_80801BC4;
    }
    // 0x80801B88: nop

    // 0x80801B8C: b           L_80801BD0
    // 0x80801B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801BD0;
    // 0x80801B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801B94:
    // 0x80801B94: jal         0x80801BDC
    // 0x80801B98: nop

    func_80801BDC_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80801B98: nop

    after_0:
    // 0x80801B9C: b           L_80801BD0
    // 0x80801BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801BD0;
    // 0x80801BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BA4:
    // 0x80801BA4: jal         0x80801D30
    // 0x80801BA8: nop

    func_80801D30_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80801BA8: nop

    after_1:
    // 0x80801BAC: b           L_80801BD0
    // 0x80801BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801BD0;
    // 0x80801BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BB4:
    // 0x80801BB4: jal         0x80801C18
    // 0x80801BB8: nop

    func_80801C18_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80801BB8: nop

    after_2:
    // 0x80801BBC: b           L_80801BD0
    // 0x80801BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801BD0;
    // 0x80801BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BC4:
    // 0x80801BC4: jal         0x80801C74
    // 0x80801BC8: nop

    func_80801C74_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80801BC8: nop

    after_3:
    // 0x80801BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BD0:
    // 0x80801BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801BD4: jr          $ra
    // 0x80801BD8: nop

    return;
    // 0x80801BD8: nop

;}
RECOMP_FUNC void func_800D1218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D121C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1220: jal         0x800D0634
    // 0x800D1224: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D0634(rdram, ctx);
        goto after_0;
    // 0x800D1224: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D1228: beq         $v0, $zero, L_800D1244
    if (ctx->r2 == 0) {
        // 0x800D122C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D1244;
    }
    // 0x800D122C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D1230: jal         0x80106790
    // 0x800D1234: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x800D1234: nop

    after_1:
    // 0x800D1238: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D123C: jal         0x800EE7F8
    // 0x800D1240: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800D1240: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
L_800D1244:
    // 0x800D1244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D124C: jr          $ra
    // 0x800D1250: nop

    return;
    // 0x800D1250: nop

;}
RECOMP_FUNC void func_80802ABC_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802ABC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80802AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AC8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X49EC) << 16);
    // 0x80802ACC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80802AD0: addiu       $a2, $a2, 0x49EC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X49EC));
    // 0x80802AD4: jal         0x80089D20
    // 0x80802AD8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80802AD8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80802ADC: beq         $v0, $zero, L_80802B0C
    if (ctx->r2 == 0) {
        // 0x80802AE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802B0C;
    }
    // 0x80802AE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802AE4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80802AE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80802AEC: jal         0x800E15CC
    // 0x80802AF0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_1;
    // 0x80802AF0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_1:
    // 0x80802AF4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80802AF8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80802AFC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80802B00: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802B04: jal         0x80018820
    // 0x80802B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80802B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_80802B0C:
    // 0x80802B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802B14: jr          $ra
    // 0x80802B18: nop

    return;
    // 0x80802B18: nop

;}
RECOMP_FUNC void func_80801154_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801154: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801158: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080115C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80801160: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801164: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801168: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8080116C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801170: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801174: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801178: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080117C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80801180: jal         0x80100094
    // 0x80801184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801188: beq         $v0, $zero, L_80801228
    if (ctx->r2 == 0) {
        // 0x8080118C: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_80801228;
    }
    // 0x8080118C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80801190: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801198: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080119C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808011A0: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x808011A4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_808011A8:
    // 0x808011A8: jal         0x800EEF24
    // 0x808011AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF24(rdram, ctx);
        goto after_1;
    // 0x808011AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808011B0: beq         $v0, $zero, L_80801200
    if (ctx->r2 == 0) {
        // 0x808011B4: nop
    
            goto L_80801200;
    }
    // 0x808011B4: nop

    // 0x808011B8: beq         $s2, $s5, L_808011E4
    if (ctx->r18 == ctx->r21) {
        // 0x808011BC: addiu       $a0, $s4, 0x4
        ctx->r4 = ADD32(ctx->r20, 0X4);
            goto L_808011E4;
    }
    // 0x808011BC: addiu       $a0, $s4, 0x4
    ctx->r4 = ADD32(ctx->r20, 0X4);
    // 0x808011C0: jal         0x800EEB40
    // 0x808011C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x808011C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808011C8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808011CC: nop

    // 0x808011D0: bc1fl       L_808011F8
    if (!c1cs) {
        // 0x808011D4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808011F8;
    }
    goto skip_0;
    // 0x808011D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808011D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808011DC: b           L_808011F4
    // 0x808011E0: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
        goto L_808011F4;
    // 0x808011E0: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_808011E4:
    // 0x808011E4: jal         0x800EEB40
    // 0x808011E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x808011E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808011EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808011F0: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_808011F4:
    // 0x808011F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808011F8:
    // 0x808011F8: bne         $s0, $s3, L_808011A8
    if (ctx->r16 != ctx->r19) {
        // 0x808011FC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808011A8;
    }
    // 0x808011FC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80801200:
    // 0x80801200: beq         $s2, $s5, L_80801220
    if (ctx->r18 == ctx->r21) {
        // 0x80801204: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_80801220;
    }
    // 0x80801204: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80801208: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8080120C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80801210: subu        $t7, $t7, $s2
    ctx->r15 = SUB32(ctx->r15, ctx->r18);
    // 0x80801214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801218: jal         0x800EE7F8
    // 0x8080121C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080121C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_4:
L_80801220:
    // 0x80801220: b           L_8080122C
    // 0x80801224: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_8080122C;
    // 0x80801224: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_80801228:
    // 0x80801228: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080122C:
    // 0x8080122C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801230: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801234: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801238: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080123C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80801240: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801244: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80801248: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8080124C: jr          $ra
    // 0x80801250: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801250: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800264_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080026C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800274: jal         0x800D9078
    // 0x80800278: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800278: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8080027C: jal         0x80089F78
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800284: beql        $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x80800288: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_808002BC;
    }
    goto skip_0;
    // 0x80800288: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x8080028C: jal         0x8010D248
    // 0x80800290: nop

    func_8010D248(rdram, ctx);
        goto after_2;
    // 0x80800290: nop

    after_2:
    // 0x80800294: beql        $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x80800298: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_808002BC;
    }
    goto skip_1;
    // 0x80800298: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x8080029C: jal         0x8010C500
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002A4: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808002B8;
    }
    // 0x808002A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808002AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B0: nop

    // 0x808002B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808002B8:
    // 0x808002B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_808002BC:
    // 0x808002BC: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002C4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808002C8: nop

    // 0x808002CC: bc1f        L_808002DC
    if (!c1cs) {
        // 0x808002D0: nop
    
            goto L_808002DC;
    }
    // 0x808002D0: nop

    // 0x808002D4: b           L_808002DC
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808002DC;
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808002DC:
    // 0x808002DC: jal         0x8008A4B0
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808002E8: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002F4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x808002F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002FC: bc1f        L_80800308
    if (!c1cs) {
        // 0x80800300: nop
    
            goto L_80800308;
    }
    // 0x80800300: nop

    // 0x80800304: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800308:
    // 0x80800308: jal         0x80089D70
    // 0x8080030C: lw          $a3, 0x28($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X28);
    _subaddieaudioloop_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8080030C: lw          $a3, 0x28($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X28);
    after_5:
    // 0x80800310: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800314: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800318: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x8080031C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800320: beql        $t7, $at, L_80800350
    if (ctx->r15 == ctx->r1) {
        // 0x80800324: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_2;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800328: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080032C: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800338: nop

    // 0x8080033C: bc1fl       L_80800350
    if (!c1cs) {
        // 0x80800340: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800350;
    }
    goto skip_3;
    // 0x80800340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800344: jal         0x80101FDC
    // 0x80800348: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800348: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800350:
    // 0x80800350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void func_808000B8_chwitchyentrygates(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808000CC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000D0: bne         $t7, $at, L_80800150
    if (ctx->r15 != ctx->r1) {
        // 0x808000D4: nop
    
            goto L_80800150;
    }
    // 0x808000D4: nop

    // 0x808000D8: lw          $t8, 0x64($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X64);
    // 0x808000DC: addiu       $a0, $a1, 0x34
    ctx->r4 = ADD32(ctx->r5, 0X34);
    // 0x808000E0: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x808000E4: bltz        $t0, L_8080011C
    if (SIGNED(ctx->r8) < 0) {
        // 0x808000E8: nop
    
            goto L_8080011C;
    }
    // 0x808000E8: nop

    // 0x808000EC: lui         $a0, 0x6650
    ctx->r4 = S32(0X6650 << 16);
    // 0x808000F0: ori         $a0, $a0, 0x9D6D
    ctx->r4 = ctx->r4 | 0X9D6D;
    // 0x808000F4: jal         0x800C3F48
    // 0x808000F8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C3F48(rdram, ctx);
        goto after_0;
    // 0x808000F8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000FC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: lbu         $t2, 0x65($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X65);
    // 0x8080010C: swc1        $f4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f4.u32l;
    // 0x80800110: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800114: b           L_80800150
    // 0x80800118: sb          $t3, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r11;
        goto L_80800150;
    // 0x80800118: sb          $t3, 0x65($a1)
    MEM_B(0X65, ctx->r5) = ctx->r11;
L_8080011C:
    // 0x8080011C: jal         0x800D90A4
    // 0x80800120: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800120: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800124: beq         $v0, $zero, L_80800150
    if (ctx->r2 == 0) {
        // 0x80800128: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800150;
    }
    // 0x80800128: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080012C: lui         $a0, 0x6650
    ctx->r4 = S32(0X6650 << 16);
    // 0x80800130: ori         $a0, $a0, 0x9CA1
    ctx->r4 = ctx->r4 | 0X9CA1;
    // 0x80800134: jal         0x800C3F48
    // 0x80800138: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x80800138: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x8080013C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800140: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800148: nop

    // 0x8080014C: swc1        $f6, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f6.u32l;
L_80800150:
    // 0x80800150: jal         0x80086240
    // 0x80800154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void _baboost_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845A0: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x800845A0);
    return;
    // 0x800845A4: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_80806AF4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806AF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806AF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80806AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806B00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80806B04: bne         $a1, $at, L_80806B14
    if (ctx->r5 != ctx->r1) {
        // 0x80806B08: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80806B14;
    }
    // 0x80806B08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80806B0C: b           L_80806B18
    // 0x80806B10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80806B18;
    // 0x80806B10: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80806B14:
    // 0x80806B14: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80806B18:
    // 0x80806B18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806B1C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80806B20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80806B24: jal         0x80087D58
    // 0x80806B28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _gcnewoption_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x80806B28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80806B2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80806B30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80806B34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80806B38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806B3C: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x80806B40: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80806B44: jal         0x80087CF8
    // 0x80806B48: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80806B48: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80806B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806B50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806B54: jr          $ra
    // 0x80806B58: nop

    return;
    // 0x80806B58: nop

;}
RECOMP_FUNC void bastatetimerList_getSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091530: jr          $ra
    // 0x80091534: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x80091534: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
;}
RECOMP_FUNC void gcnewoption_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080196C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801970: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801974: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801978: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x8080197C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801980: beql        $a2, $zero, L_808019C0
    if (ctx->r6 == 0) {
        // 0x80801984: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808019C0;
    }
    goto skip_0;
    // 0x80801984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801988: jal         0x80087BE0
    // 0x8080198C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_0;
    // 0x8080198C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80801990: lw          $a0, 0x23C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X23C);
    // 0x80801994: jal         0x80088720
    // 0x80801998: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801998: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_1:
    // 0x8080199C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x808019A0: jal         0x80087B20
    // 0x808019A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808019A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808019A8: lbu         $t7, 0x1D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1D);
    // 0x808019AC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808019B0: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x808019B4: sb          $t8, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r24;
    // 0x808019B8: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x808019BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808019C0:
    // 0x808019C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808019C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808019C8: jr          $ra
    // 0x808019CC: nop

    return;
    // 0x808019CC: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883A8: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x800883A8);
    return;
    // 0x800883AC: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80800EE0_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800EE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EEC: jal         0x8009E6EC
    // 0x80800EF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800EF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800EF4: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80800EF8: bne         $v0, $at, L_80800F40
    if (ctx->r2 != ctx->r1) {
        // 0x80800EFC: nop
    
            goto L_80800F40;
    }
    // 0x80800EFC: nop

    // 0x80800F00: jal         0x80099A34
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A34(rdram, ctx);
        goto after_1;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800F08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F0C: jal         0x8009BDAC
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BDAC(rdram, ctx);
        goto after_2;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F18: jal         0x80093370
    // 0x80800F1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_3;
    // 0x80800F1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F24: jal         0x8009E5C8
    // 0x80800F28: addiu       $a1, $zero, 0x131
    ctx->r5 = ADD32(0, 0X131);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800F28: addiu       $a1, $zero, 0x131
    ctx->r5 = ADD32(0, 0X131);
    after_4:
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F30: jal         0x8009E830
    // 0x80800F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_5;
    // 0x80800F34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800F38: b           L_80800F4C
    // 0x80800F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800F4C;
    // 0x80800F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F40:
    // 0x80800F40: jal         0x80085258
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F4C:
    // 0x80800F4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F54: jr          $ra
    // 0x80800F58: nop

    return;
    // 0x80800F58: nop

;}
RECOMP_FUNC void func_8080005C_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x8080022C
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080022C_chbottlesparty(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800074: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800078: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080007C: bnel        $t7, $at, L_80800090
    if (ctx->r15 != ctx->r1) {
        // 0x80800080: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800090;
    }
    goto skip_0;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800084: jal         0x80800170
    // 0x80800088: nop

    func_80800170_chbottlesparty(rdram, ctx);
        goto after_1;
    // 0x80800088: nop

    after_1:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800090:
    // 0x80800090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void bsdie_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800764: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080076C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800770: jal         0x8008CABC
    // 0x80800774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800778: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080077C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80800780: jal         0x80085228
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: jal         0x8009B9B0
    // 0x80800790: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800790: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x80800794: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800798: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: beq         $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007A4: nop
    
            goto L_808007C8;
    }
    // 0x808007A4: nop

    // 0x808007A8: beq         $v0, $at, L_808007F8
    if (ctx->r2 == ctx->r1) {
        // 0x808007AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808007F8;
    }
    // 0x808007AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007B0: beq         $v0, $at, L_80800860
    if (ctx->r2 == ctx->r1) {
        // 0x808007B4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800860;
    }
    // 0x808007B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007B8: beq         $v0, $at, L_808008C4
    if (ctx->r2 == ctx->r1) {
        // 0x808007BC: nop
    
            goto L_808008C4;
    }
    // 0x808007BC: nop

    // 0x808007C0: b           L_808008C4
    // 0x808007C4: nop

        goto L_808008C4;
    // 0x808007C4: nop

L_808007C8:
    // 0x808007C8: jal         0x8008DF8C
    // 0x808007CC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8008DF8C(rdram, ctx);
        goto after_3;
    // 0x808007CC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_3:
    // 0x808007D0: beq         $v0, $zero, L_808008C4
    if (ctx->r2 == 0) {
        // 0x808007D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C4;
    }
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: lui         $a1, 0x3E48
    ctx->r5 = S32(0X3E48 << 16);
    // 0x808007DC: lui         $a2, 0x4046
    ctx->r6 = S32(0X4046 << 16);
    // 0x808007E0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808007E4: jal         0x8008CF1C
    // 0x808007E8: ori         $a1, $a1, 0xCE70
    ctx->r5 = ctx->r5 | 0XCE70;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_4;
    // 0x808007E8: ori         $a1, $a1, 0xCE70
    ctx->r5 = ctx->r5 | 0XCE70;
    after_4:
    // 0x808007EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808007F0: b           L_808008C4
    // 0x808007F4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808008C4;
    // 0x808007F4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808007F8:
    // 0x808007F8: jal         0x8008E078
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800800: beq         $v0, $zero, L_808008C4
    if (ctx->r2 == 0) {
        // 0x80800804: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C4;
    }
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    // 0x8080080C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800810: jal         0x8009DF18
    // 0x80800814: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80800814: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_6:
    // 0x80800818: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080081C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800820: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800824: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800828: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080082C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800830: jal         0x80085490
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800838: jal         0x80800000
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsdie(rdram, ctx);
        goto after_8;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800840: jal         0x8009E058
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E058(rdram, ctx);
        goto after_9;
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: jal         0x8008CED4
    // 0x80800850: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_10;
    // 0x80800850: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_10:
    // 0x80800854: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800858: b           L_808008C4
    // 0x8080085C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808008C4;
    // 0x8080085C: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800860:
    // 0x80800860: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800864: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800868: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080086C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800870: jal         0x800F0E00
    // 0x80800874: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_11;
    // 0x80800874: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_11:
    // 0x80800878: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8080087C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800880: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800884: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1f        L_8080089C
    if (!c1cs) {
        // 0x80800890: nop
    
            goto L_8080089C;
    }
    // 0x80800890: nop

    // 0x80800894: jal         0x80084A10
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8080089C:
    // 0x8080089C: jal         0x8008B324
    // 0x808008A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_13;
    // 0x808008A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808008A4: beq         $v0, $zero, L_808008C4
    if (ctx->r2 == 0) {
        // 0x808008A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C4;
    }
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: jal         0x8008CED4
    // 0x808008B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_14;
    // 0x808008B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x808008B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808008B8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808008BC: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x808008C0: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
L_808008C4:
    // 0x808008C4: jal         0x80085238
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808008CC: beq         $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008DC;
    }
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: addiu       $t9, $zero, 0x54
    ctx->r25 = ADD32(0, 0X54);
    // 0x808008D8: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_808008DC:
    // 0x808008DC: jal         0x8009E5C8
    // 0x808008E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x808008E0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
    // 0x808008E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void idflash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: jr          $ra
    // 0x808000A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000A4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800008: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080000C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800010: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800018: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x80800024: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80800028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080002C: jal         0x800EE7F8
    // 0x80800030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800034: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800040: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800044: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80800048: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8080004C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800050: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800054: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800058: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080005C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80800060: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800064: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800068: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080006C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800070: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800074: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800078: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_80801A3C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801A48: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801A4C: jal         0x80100094
    // 0x80801A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A54: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80801A5C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80801A60: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80801A64: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80801A68: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x80801A6C: beql        $t8, $zero, L_80801A80
    if (ctx->r24 == 0) {
        // 0x80801A70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A80;
    }
    goto skip_0;
    // 0x80801A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801A74: jal         0x808042A4
    // 0x80801A78: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_808042A4_chdodgemcontrol(rdram, ctx);
        goto after_1;
    // 0x80801A78: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x80801A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A80:
    // 0x80801A80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A84: jr          $ra
    // 0x80801A88: nop

    return;
    // 0x80801A88: nop

;}
RECOMP_FUNC void func_80800118_chsecreteggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080011C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: lhu         $a2, 0x72($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X72);
    // 0x80800128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080012C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800130: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x80800134: beq         $t6, $at, L_80800150
    if (ctx->r14 == ctx->r1) {
        // 0x80800138: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(2472, 0X4EC) << 16);
            goto L_80800150;
    }
    // 0x80800138: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2472, 0X4EC) << 16);
    // 0x8080013C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800140: beq         $t6, $at, L_80800230
    if (ctx->r14 == ctx->r1) {
        // 0x80800144: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800230;
    }
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: b           L_80800318
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800318;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800150:
    // 0x80800150: addiu       $t7, $t7, 0x4EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2472, 0X4EC));
    // 0x80800154: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800158: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8080015C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2472, 0X500) << 16);
    // 0x80800160: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800164: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80800168: addiu       $t1, $t1, 0x500
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2472, 0X500));
    // 0x8080016C: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x80800170: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800174: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800180: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x80800184: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x80800188: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x8080018C: sw          $at, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r1;
    // 0x80800190: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800194: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80800198: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8080019C: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808001A0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x808001A4: jal         0x80101E4C
    // 0x808001A8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_0:
    // 0x808001AC: beq         $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D4;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: lui         $a0, 0xF2EF
    ctx->r4 = S32(0XF2EF << 16);
    // 0x808001B8: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808001BC: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808001C0: ori         $a0, $a0, 0xA53F
    ctx->r4 = ctx->r4 | 0XA53F;
    // 0x808001C4: jal         0x800C4140
    // 0x808001C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_1;
    // 0x808001C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808001CC: b           L_808001FC
    // 0x808001D0: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
        goto L_808001FC;
    // 0x808001D0: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_808001D4:
    // 0x808001D4: jal         0x80101E4C
    // 0x808001D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80101E4C(rdram, ctx);
        goto after_2;
    // 0x808001D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x808001DC: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001E0: lui         $a0, 0xBFCF
        ctx->r4 = S32(0XBFCF << 16);
            goto L_808001F8;
    }
    // 0x808001E0: lui         $a0, 0xBFCF
    ctx->r4 = S32(0XBFCF << 16);
    // 0x808001E4: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x808001E8: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x808001EC: ori         $a0, $a0, 0xA53D
    ctx->r4 = ctx->r4 | 0XA53D;
    // 0x808001F0: jal         0x800C4140
    // 0x808001F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_3;
    // 0x808001F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
L_808001F8:
    // 0x808001F8: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
L_808001FC:
    // 0x808001FC: sll         $t6, $t4, 26
    ctx->r14 = S32(ctx->r12 << 26);
    // 0x80800200: bgezl       $t6, L_80800318
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800204: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800318;
    }
    goto skip_0;
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800208: jal         0x800878B0
    // 0x8080020C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080020C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800210: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800214: beq         $v0, $at, L_80800314
    if (ctx->r2 == ctx->r1) {
        // 0x80800218: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800314;
    }
    // 0x80800218: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080021C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x80800220: jal         0x800F7BC8
    // 0x80800224: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_5;
    // 0x80800224: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80800228: b           L_80800318
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800318;
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x80800234: jal         0x80101E14
    // 0x80800238: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    func_80101E14(rdram, ctx);
        goto after_6;
    // 0x80800238: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_6:
    // 0x8080023C: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800240: lui         $a0, 0x7FFF
        ctx->r4 = S32(0X7FFF << 16);
            goto L_80800258;
    }
    // 0x80800240: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800244: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800248: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080024C: ori         $a0, $a0, 0x4561
    ctx->r4 = ctx->r4 | 0X4561;
    // 0x80800250: jal         0x800C4140
    // 0x80800254: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_7;
    // 0x80800254: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
L_80800258:
    // 0x80800258: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080025C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800260: jal         0x80101E14
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_8;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800268: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x8080026C: nop
    
            goto L_808002AC;
    }
    // 0x8080026C: nop

    // 0x80800270: jal         0x80800000
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chsecreteggs(rdram, ctx);
        goto after_9;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800278: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x8080027C: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x80800280: sll         $t9, $t8, 26
    ctx->r25 = S32(ctx->r24 << 26);
    // 0x80800284: bgezl       $t9, L_80800318
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800288: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800318;
    }
    goto skip_1;
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080028C: jal         0x800F54E4
    // 0x80800290: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800290: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    after_10:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8080029C: jal         0x800F7700
    // 0x808002A0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F7700(rdram, ctx);
        goto after_11;
    // 0x808002A0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808002A4: b           L_80800318
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800318;
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002AC:
    // 0x808002AC: jal         0x80101DDC
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_12;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002B4: beql        $v0, $zero, L_80800318
    if (ctx->r2 == 0) {
        // 0x808002B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800318;
    }
    goto skip_2;
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808002BC: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x808002C0: sll         $t3, $t0, 26
    ctx->r11 = S32(ctx->r8 << 26);
    // 0x808002C4: bgez        $t3, L_8080030C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808002C8: nop
    
            goto L_8080030C;
    }
    // 0x808002C8: nop

    // 0x808002CC: jal         0x800DA298
    // 0x808002D0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x808002D0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_13:
    // 0x808002D4: bne         $v0, $zero, L_8080030C
    if (ctx->r2 != 0) {
        // 0x808002D8: nop
    
            goto L_8080030C;
    }
    // 0x808002D8: nop

    // 0x808002DC: jal         0x800DA544
    // 0x808002E0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x808002E0: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_14:
    // 0x808002E4: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
    // 0x808002E8: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    // 0x808002EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002F0: sll         $t6, $t4, 26
    ctx->r14 = S32(ctx->r12 << 26);
    // 0x808002F4: bgez        $t6, L_80800304
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808002F8: nop
    
            goto L_80800304;
    }
    // 0x808002F8: nop

    // 0x808002FC: b           L_80800304
    // 0x80800300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x80800300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: jal         0x80101180
    // 0x80800308: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80101180(rdram, ctx);
        goto after_15;
    // 0x80800308: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_15:
L_8080030C:
    // 0x8080030C: jal         0x80089CA8
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800314:
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800318:
    // 0x80800318: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085040: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085040);
    return;
    // 0x80085044: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void ncpoducam_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801528: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080152C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80801530: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80801534: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801538: jal         0x808000F0
    // 0x8080153C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    ncpoducam_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080153C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801540: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80801544: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801548: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080154C: beq         $v1, $zero, L_8080163C
    if (ctx->r3 == 0) {
        // 0x80801550: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8080163C;
    }
    // 0x80801550: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801554: beq         $v1, $at, L_80801578
    if (ctx->r3 == ctx->r1) {
        // 0x80801558: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801578;
    }
    // 0x80801558: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080155C: beq         $v1, $at, L_8080160C
    if (ctx->r3 == ctx->r1) {
        // 0x80801560: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080160C;
    }
    // 0x80801560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801564: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801568: beql        $v1, $at, L_80801640
    if (ctx->r3 == ctx->r1) {
        // 0x8080156C: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_80801640;
    }
    goto skip_0;
    // 0x8080156C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    skip_0:
    // 0x80801570: b           L_80801640
    // 0x80801574: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80801640;
    // 0x80801574: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80801578:
    // 0x80801578: jal         0x808007D0
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007D0_ncpoducam(rdram, ctx);
        goto after_1;
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801584: jal         0x80800854
    // 0x80801588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800854_ncpoducam(rdram, ctx);
        goto after_2;
    // 0x80801588: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8080158C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801590: bnel        $v0, $at, L_808015A4
    if (ctx->r2 != ctx->r1) {
        // 0x80801594: lh          $t8, 0x48($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X48);
            goto L_808015A4;
    }
    goto skip_1;
    // 0x80801594: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    skip_1:
    // 0x80801598: b           L_80801644
    // 0x8080159C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801644;
    // 0x8080159C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015A0: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
L_808015A4:
    // 0x808015A4: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x808015A8: beql        $t9, $zero, L_808015D8
    if (ctx->r25 == 0) {
        // 0x808015AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015D8;
    }
    goto skip_2;
    // 0x808015AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808015B0: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x808015B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808015B8: beql        $t0, $zero, L_808015D4
    if (ctx->r8 == 0) {
        // 0x808015BC: sb          $t1, 0x64($s0)
        MEM_B(0X64, ctx->r16) = ctx->r9;
            goto L_808015D4;
    }
    goto skip_3;
    // 0x808015BC: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    skip_3:
    // 0x808015C0: jal         0x80800944
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800944_ncpoducam(rdram, ctx);
        goto after_3;
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808015C8: b           L_808015D8
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808015D8;
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D0: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
L_808015D4:
    // 0x808015D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015D8:
    // 0x808015D8: jal         0x80800A94
    // 0x808015DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800A94_ncpoducam(rdram, ctx);
        goto after_4;
    // 0x808015DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808015E0: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x808015E4: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x808015E8: bnel        $t3, $zero, L_808015FC
    if (ctx->r11 != 0) {
        // 0x808015EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015FC;
    }
    goto skip_4;
    // 0x808015EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x808015F0: jal         0x80800944
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800944_ncpoducam(rdram, ctx);
        goto after_5;
    // 0x808015F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808015FC:
    // 0x808015FC: jal         0x80800B74
    // 0x80801600: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800B74_ncpoducam(rdram, ctx);
        goto after_6;
    // 0x80801600: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80801604: b           L_8080163C
    // 0x80801608: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8080163C;
    // 0x80801608: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8080160C:
    // 0x8080160C: jal         0x80800854
    // 0x80801610: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800854_ncpoducam(rdram, ctx);
        goto after_7;
    // 0x80801610: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80801614: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801618: bne         $v0, $at, L_80801628
    if (ctx->r2 != ctx->r1) {
        // 0x8080161C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80801628;
    }
    // 0x8080161C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801620: b           L_80801644
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801644;
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801628:
    // 0x80801628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080162C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801630: jal         0x80800A94
    // 0x80801634: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800A94_ncpoducam(rdram, ctx);
        goto after_8;
    // 0x80801634: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x80801638: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_8080163C:
    // 0x8080163C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80801640:
    // 0x80801640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801644:
    // 0x80801644: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801648: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080164C: jr          $ra
    // 0x80801650: nop

    return;
    // 0x80801650: nop

;}
RECOMP_FUNC void func_80800990_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800998: jal         0x80800068
    // 0x8080099C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800068_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x8080099C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009A0: jal         0x80082FE0
    // 0x808009A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808009A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B0: jr          $ra
    // 0x808009B4: nop

    return;
    // 0x808009B4: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800878: jal         0x80082FE8
    // 0x8080087C: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080087C: nop

    after_0:
    // 0x80800880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void _bssub_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D68: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D68);
    return;
    // 0x80083D6C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800FBEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBEC8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FBECC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800FBED0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800FBED4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800FBED8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800FBEDC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FBEE0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FBEE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FBEE8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FBEEC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FBEF0: jal         0x800B3034
    // 0x800FBEF4: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    freelist_capacity(rdram, ctx);
        goto after_0;
    // 0x800FBEF4: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x800FBEF8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800FBEFC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800FBF00: addiu       $s1, $zero, 0x7FFF
    ctx->r17 = ADD32(0, 0X7FFF);
    // 0x800FBF04: lui         $s2, 0x4000
    ctx->r18 = S32(0X4000 << 16);
    // 0x800FBF08: bne         $at, $zero, L_800FBF6C
    if (ctx->r1 != 0) {
        // 0x800FBF0C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800FBF6C;
    }
    // 0x800FBF0C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800FBF10: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
L_800FBF14:
    // 0x800FBF14: jal         0x800B31B8
    // 0x800FBF18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_is_element_alive(rdram, ctx);
        goto after_1;
    // 0x800FBF18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800FBF1C: beq         $v0, $zero, L_800FBF5C
    if (ctx->r2 == 0) {
        // 0x800FBF20: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800FBF5C;
    }
    // 0x800FBF20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FBF24: jal         0x800B301C
    // 0x800FBF28: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    freelist_at(rdram, ctx);
        goto after_2;
    // 0x800FBF28: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    after_2:
    // 0x800FBF2C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800FBF30: slt         $at, $v1, $s1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800FBF34: bnel        $at, $zero, L_800FBF58
    if (ctx->r1 != 0) {
        // 0x800FBF38: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_800FBF58;
    }
    goto skip_0;
    // 0x800FBF38: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    skip_0:
    // 0x800FBF3C: bnel        $s1, $v1, L_800FBF60
    if (ctx->r17 != ctx->r3) {
        // 0x800FBF40: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800FBF60;
    }
    goto skip_1;
    // 0x800FBF40: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800FBF44: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800FBF48: slt         $at, $t6, $s2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800FBF4C: beql        $at, $zero, L_800FBF60
    if (ctx->r1 == 0) {
        // 0x800FBF50: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800FBF60;
    }
    goto skip_2;
    // 0x800FBF50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800FBF54: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800FBF58:
    // 0x800FBF58: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
L_800FBF5C:
    // 0x800FBF5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800FBF60:
    // 0x800FBF60: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800FBF64: bnel        $at, $zero, L_800FBF14
    if (ctx->r1 != 0) {
        // 0x800FBF68: lw          $a0, 0x38($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X38);
            goto L_800FBF14;
    }
    goto skip_3;
    // 0x800FBF68: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    skip_3:
L_800FBF6C:
    // 0x800FBF6C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FBF70: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x800FBF74: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800FBF78: sw          $s2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r18;
    // 0x800FBF7C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800FBF80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800FBF84: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800FBF88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FBF8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FBF90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FBF94: jr          $ra
    // 0x800FBF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800FBF98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void boot___ll_rshift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002AA4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80002AA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002AAC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80002AB0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80002AB4: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x80002AB8: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002ABC: dsrav       $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) >> (ctx->r15 & 63);
    // 0x80002AC0: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80002AC4: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80002AC8: jr          $ra
    // 0x80002ACC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80002ACC: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8080000C_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80088848
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: beq         $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x80800024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800038;
    }
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: jal         0x80102424
    // 0x8080002C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800030: b           L_8080005C
    // 0x80800034: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
        goto L_8080005C;
    // 0x80800034: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
L_80800038:
    // 0x80800038: jal         0x800DA298
    // 0x8080003C: addiu       $a0, $zero, 0x186
    ctx->r4 = ADD32(0, 0X186);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a0, $zero, 0x186
    ctx->r4 = ADD32(0, 0X186);
    after_2:
    // 0x80800040: beql        $v0, $zero, L_8080005C
    if (ctx->r2 == 0) {
        // 0x80800044: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_8080005C;
    }
    goto skip_0;
    // 0x80800044: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    skip_0:
    // 0x80800048: jal         0x800FFAB0
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800050: b           L_808000C4
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C4;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
L_8080005C:
    // 0x8080005C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800060: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080006C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800070: jal         0x80102FDC
    // 0x80800074: nop

    func_80102FDC(rdram, ctx);
        goto after_4;
    // 0x80800074: nop

    after_4:
    // 0x80800078: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080007C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800080: jal         0x800EE7F8
    // 0x80800084: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800084: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800088: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080008C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800090: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800098: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8080009C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808000A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808000A4: jal         0x800EF1B8
    // 0x808000A8: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808000A8: nop

    after_6:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80105A9C
    // 0x808000B4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_80105A9C(rdram, ctx);
        goto after_7;
    // 0x808000B4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_7:
    // 0x808000B8: jal         0x80105BAC
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_8;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_80800290_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800298: jal         0x80800548
    // 0x8080029C: nop

    func_80800548_chmrsboggy(rdram, ctx);
        goto after_0;
    // 0x8080029C: nop

    after_0:
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void func_80801AB4_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801AB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801ABC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801AC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801AC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AC8: jal         0x80100094
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801AD0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801AD4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801AD8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_80801ADC:
    // 0x80801ADC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80801AE0: beq         $a0, $zero, L_80801AF0
    if (ctx->r4 == 0) {
        // 0x80801AE4: nop
    
            goto L_80801AF0;
    }
    // 0x80801AE4: nop

    // 0x80801AE8: jal         0x800C8B84
    // 0x80801AEC: nop

    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x80801AEC: nop

    after_1:
L_80801AF0:
    // 0x80801AF0: jal         0x80089D48
    // 0x80801AF4: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801AF4: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    after_2:
    // 0x80801AF8: lbu         $t6, 0x10($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X10);
    // 0x80801AFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801B00: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80801B04: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x80801B08: sb          $v0, -0xC($s0)
    MEM_B(-0XC, ctx->r16) = ctx->r2;
    // 0x80801B0C: bne         $s1, $s2, L_80801ADC
    if (ctx->r17 != ctx->r18) {
        // 0x80801B10: sb          $t7, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = ctx->r15;
            goto L_80801ADC;
    }
    // 0x80801B10: sb          $t7, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r15;
    // 0x80801B14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801B24: jr          $ra
    // 0x80801B28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801B28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801084_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080108C: jal         0x80800104
    // 0x80801090: nop

    func_80800104_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80801090: nop

    after_0:
    // 0x80801094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080109C: jr          $ra
    // 0x808010A0: nop

    return;
    // 0x808010A0: nop

;}
RECOMP_FUNC void func_800A18C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A18C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A18CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A18D0: jal         0x800F9F74
    // 0x800A18D4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F9F74(rdram, ctx);
        goto after_0;
    // 0x800A18D4: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x800A18D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A18DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A18E0: jr          $ra
    // 0x800A18E4: nop

    return;
    // 0x800A18E4: nop

;}
RECOMP_FUNC void func_80109F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109F20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80109F24: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80109F28: jal         0x8010114C
    // 0x80109F2C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80109F2C: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80109F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109F38: jr          $ra
    // 0x80109F3C: nop

    return;
    // 0x80109F3C: nop

;}
RECOMP_FUNC void func_800D5FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5FDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5FE0: jr          $ra
    // 0x800D5FE4: sw          $a0, -0x4818($at)
    MEM_W(-0X4818, ctx->r1) = ctx->r4;
    return;
    // 0x800D5FE4: sw          $a0, -0x4818($at)
    MEM_W(-0X4818, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sujiggy_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080087C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800880: jal         0x80800854
    // 0x80800884: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sujiggy_entrypoint_24(rdram, ctx);
        goto after_0;
    // 0x80800884: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800888: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080088C: bne         $a1, $zero, L_8080089C
    if (ctx->r5 != 0) {
        // 0x80800890: nop
    
            goto L_8080089C;
    }
    // 0x80800890: nop

    // 0x80800894: b           L_808008D0
    // 0x80800898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008D0;
    // 0x80800898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080089C:
    // 0x8080089C: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808008A0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_808008A8;
    }
    // 0x808008A0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808008A4: beq         $at, $zero, L_808008BC
    if (ctx->r1 == 0) {
        // 0x808008A8: addiu       $a0, $zero, 0xC0D
        ctx->r4 = ADD32(0, 0XC0D);
            goto L_808008BC;
    }
L_808008A8:
    // 0x808008A8: addiu       $a0, $zero, 0xC0D
    ctx->r4 = ADD32(0, 0XC0D);
    // 0x808008AC: jal         0x800DA7A8
    // 0x808008B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x808008B0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x808008B4: b           L_808008D0
    // 0x808008B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808008D0;
    // 0x808008B8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808008BC:
    // 0x808008BC: bnel        $v0, $a1, L_808008D0
    if (ctx->r2 != ctx->r5) {
        // 0x808008C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808008D0;
    }
    goto skip_0;
    // 0x808008C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808008C4: b           L_808008D0
    // 0x808008C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008D0;
    // 0x808008C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008D0:
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008D8: jr          $ra
    // 0x808008DC: nop

    return;
    // 0x808008DC: nop

;}
RECOMP_FUNC void func_800C3D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3D7C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3D80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3D84: sltu        $v1, $zero, $t6
    ctx->r3 = 0 < ctx->r14 ? 1 : 0;
    // 0x800C3D88: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3D8C: bne         $v1, $zero, L_800C3D9C
    if (ctx->r3 != 0) {
        // 0x800C3D90: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3D9C;
    }
    // 0x800C3D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3D94: b           L_800C3DF0
    // 0x800C3D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C3DF0;
    // 0x800C3D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3D9C:
    // 0x800C3D9C: jal         0x800C1414
    // 0x800C3DA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3DA0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x800C3DA4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800C3DA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3DAC: beq         $v1, $zero, L_800C3DF0
    if (ctx->r3 == 0) {
        // 0x800C3DB0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800C3DF0;
    }
    // 0x800C3DB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C3DB4: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x800C3DB8: sll         $t7, $v0, 19
    ctx->r15 = S32(ctx->r2 << 19);
    // 0x800C3DBC: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x800C3DC0: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x800C3DC4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800C3DC8: beql        $v0, $zero, L_800C3DF4
    if (ctx->r2 == 0) {
        // 0x800C3DCC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3DF4;
    }
    goto skip_0;
    // 0x800C3DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C3DD0: lbu         $v1, 0x79($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X79);
    // 0x800C3DD4: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x800C3DD8: beql        $v0, $zero, L_800C3DF4
    if (ctx->r2 == 0) {
        // 0x800C3DDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C3DF4;
    }
    goto skip_1;
    // 0x800C3DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C3DE0: jal         0x800C1448
    // 0x800C3DE4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    func_800C1448(rdram, ctx);
        goto after_1;
    // 0x800C3DE4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_1:
    // 0x800C3DE8: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C3DEC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800C3DF0:
    // 0x800C3DF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C3DF4:
    // 0x800C3DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3DF8: jr          $ra
    // 0x800C3DFC: nop

    return;
    // 0x800C3DFC: nop

;}
RECOMP_FUNC void func_800F7874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7874: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7878: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F787C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7880: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7884: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F788C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7890: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7894: jal         0x8009AD44
    // 0x800F7898: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD44(rdram, ctx);
        goto after_0;
    // 0x800F7898: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F789C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F78A0: jal         0x8009AD14
    // 0x800F78A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009AD14(rdram, ctx);
        goto after_1;
    // 0x800F78A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F78A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F78AC: jal         0x8009E7C8
    // 0x800F78B0: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F78B0: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    after_2:
    // 0x800F78B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F78B8: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F78BC: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F78C0: jr          $ra
    // 0x800F78C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F78C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _bsvan_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084170: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084170);
    return;
    // 0x80084174: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _bsrebound_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083940: syscall     83
    recomp_syscall_handler(rdram, ctx, 0x80083940);
    return;
    // 0x80083944: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E8D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8D34: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800E8D38: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800E8D3C: jal         0x800E8CB0
    // 0x800E8D40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E8CB0(rdram, ctx);
        goto after_0;
    // 0x800E8D40: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E8D44: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800E8D48: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800E8D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8D54: jr          $ra
    // 0x800E8D58: nop

    return;
    // 0x800E8D58: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844B0: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844B0);
    return;
    // 0x800844B4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808007F4_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007FC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800800: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800808: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080080C: jal         0x8008CB10
    // 0x80800810: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800810: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80800814: beq         $v0, $zero, L_80800844
    if (ctx->r2 == 0) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800844;
    }
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800820: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800824: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x80800828: addiu       $t7, $zero, 0x4E20
    ctx->r15 = ADD32(0, 0X4E20);
    // 0x8080082C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800830: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800834: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800838: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080083C: jal         0x8009DEC0
    // 0x80800840: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    func_8009DEC0(rdram, ctx);
        goto after_1;
    // 0x80800840: addiu       $a1, $zero, 0x583
    ctx->r5 = ADD32(0, 0X583);
    after_1:
L_80800844:
    // 0x80800844: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800848: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080084C: jal         0x8008CB10
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800854: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800858: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800884;
    }
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800860: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800864: addiu       $t8, $zero, 0x2EE0
    ctx->r24 = ADD32(0, 0X2EE0);
    // 0x80800868: addiu       $t9, $zero, 0x2EE0
    ctx->r25 = ADD32(0, 0X2EE0);
    // 0x8080086C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800870: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800874: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800878: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080087C: jal         0x8009DEC0
    // 0x80800880: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DEC0(rdram, ctx);
        goto after_3;
    // 0x80800880: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_3:
L_80800884:
    // 0x80800884: jal         0x808004D8
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D8_bsledge(rdram, ctx);
        goto after_4;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080088C: jal         0x8008CAEC
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800894: beq         $v0, $zero, L_808008A4
    if (ctx->r2 == 0) {
        // 0x80800898: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A4;
    }
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808008A0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808008A4:
    // 0x808008A4: jal         0x8009E5C8
    // 0x808008A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808008A8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808008AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808008B8: jr          $ra
    // 0x808008BC: nop

    return;
    // 0x808008BC: nop

;}
RECOMP_FUNC void func_808009A0_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009A4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808009A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009AC: beq         $a1, $at, L_808009D0
    if (ctx->r5 == ctx->r1) {
        // 0x808009B0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808009D0;
    }
    // 0x808009B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808009B4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808009B8: bne         $a1, $at, L_80800A1C
    if (ctx->r5 != ctx->r1) {
        // 0x808009BC: nop
    
            goto L_80800A1C;
    }
    // 0x808009BC: nop

    // 0x808009C0: jal         0x8080058C
    // 0x808009C4: nop

    func_8080058C_chmolehill(rdram, ctx);
        goto after_0;
    // 0x808009C4: nop

    after_0:
    // 0x808009C8: b           L_80800A28
    // 0x808009CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A28;
    // 0x808009CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009D0:
    // 0x808009D0: jal         0x801015D0
    // 0x808009D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801015D0(rdram, ctx);
        goto after_1;
    // 0x808009D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808009D8: jal         0x80800884
    // 0x808009DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800884_chmolehill(rdram, ctx);
        goto after_2;
    // 0x808009DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808009E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808009E4: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x808009E8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x808009EC: bltz        $t9, L_80800A04
    if (SIGNED(ctx->r25) < 0) {
        // 0x808009F0: nop
    
            goto L_80800A04;
    }
    // 0x808009F0: nop

    // 0x808009F4: jal         0x80088848
    // 0x808009F8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x808009F8: nop

    after_3:
    // 0x808009FC: beq         $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x80800A00: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800A0C;
    }
    // 0x80800A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800A04:
    // 0x80800A04: b           L_80800A0C
    // 0x80800A08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800A0C;
    // 0x80800A08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800A0C:
    // 0x80800A0C: jal         0x800DF744
    // 0x80800A10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800A10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80800A14: b           L_80800A28
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A28;
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A1C:
    // 0x80800A1C: b           L_80800A28
    // 0x80800A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A28;
    // 0x80800A20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A28:
    // 0x80800A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A30: jr          $ra
    // 0x80800A34: nop

    return;
    // 0x80800A34: nop

;}
RECOMP_FUNC void func_800EC5C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC5C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EC5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC5C8: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800EC5CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800EC5D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC5D4: lw          $t6, 0x18($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X18);
    // 0x800EC5D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EC5DC: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x800EC5E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800EC5E4: bgez        $t7, L_800EC5F8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EC5E8: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800EC5F8;
    }
    // 0x800EC5E8: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EC5EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800EC5F0: nop

    // 0x800EC5F4: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_800EC5F8:
    // 0x800EC5F8: c.eq.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl == ctx->f8.fl;
    // 0x800EC5FC: nop

    // 0x800EC600: bc1fl       L_800EC6CC
    if (!c1cs) {
        // 0x800EC604: lhu         $t5, 0x18($a2)
        ctx->r13 = MEM_HU(ctx->r6, 0X18);
            goto L_800EC6CC;
    }
    goto skip_0;
    // 0x800EC604: lhu         $t5, 0x18($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X18);
    skip_0:
    // 0x800EC608: jalr        $a1
    // 0x800EC60C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x800EC60C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EC610: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800EC614: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC618: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800EC61C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC620: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800EC624: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800EC628: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800EC62C: nop

    // 0x800EC630: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800EC634: beql        $v0, $zero, L_800EC684
    if (ctx->r2 == 0) {
        // 0x800EC638: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_800EC684;
    }
    goto skip_1;
    // 0x800EC638: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800EC63C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EC640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC644: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800EC648: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x800EC64C: nop

    // 0x800EC650: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800EC654: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x800EC658: nop

    // 0x800EC65C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x800EC660: bne         $v0, $zero, L_800EC678
    if (ctx->r2 != 0) {
        // 0x800EC664: nop
    
            goto L_800EC678;
    }
    // 0x800EC664: nop

    // 0x800EC668: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800EC66C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EC670: b           L_800EC690
    // 0x800EC674: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_800EC690;
    // 0x800EC674: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_800EC678:
    // 0x800EC678: b           L_800EC690
    // 0x800EC67C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800EC690;
    // 0x800EC67C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EC680: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_800EC684:
    // 0x800EC684: nop

    // 0x800EC688: bltz        $v0, L_800EC678
    if (SIGNED(ctx->r2) < 0) {
        // 0x800EC68C: nop
    
            goto L_800EC678;
    }
    // 0x800EC68C: nop

L_800EC690:
    // 0x800EC690: lhu         $t2, 0x18($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X18);
    // 0x800EC694: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x800EC698: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800EC69C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800EC6A0: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x800EC6A4: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800EC6A8: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x800EC6AC: sh          $t4, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r12;
    // 0x800EC6B0: bgez        $t9, L_800EC6C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800EC6B4: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800EC6C8;
    }
    // 0x800EC6B4: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EC6B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EC6BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EC6C0: nop

    // 0x800EC6C4: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800EC6C8:
    // 0x800EC6C8: lhu         $t5, 0x18($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X18);
L_800EC6CC:
    // 0x800EC6CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EC6D0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800EC6D4: beql        $t6, $zero, L_800EC6F8
    if (ctx->r14 == 0) {
        // 0x800EC6D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EC6F8;
    }
    goto skip_2;
    // 0x800EC6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800EC6DC: jal         0x80106790
    // 0x800EC6E0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x800EC6E0: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800EC6E4: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800EC6E8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800EC6EC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800EC6F0: nop

    // 0x800EC6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC6F8:
    // 0x800EC6F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EC6FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800EC700: jr          $ra
    // 0x800EC704: nop

    return;
    // 0x800EC704: nop

;}
RECOMP_FUNC void func_80804BA4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804BA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804BAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804BB0: jal         0x80807D48
    // 0x80804BB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80804BB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804BB8: jal         0x80809D24
    // 0x80804BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809D24_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80804BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804BC0: jal         0x800A3404
    // 0x80804BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3404(rdram, ctx);
        goto after_2;
    // 0x80804BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804BC8: bne         $v0, $zero, L_80804CC8
    if (ctx->r2 != 0) {
        // 0x80804BCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804CC8;
    }
    // 0x80804BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BD0: lui         $a1, 0x3DDD
    ctx->r5 = S32(0X3DDD << 16);
    // 0x80804BD4: jal         0x8008CB10
    // 0x80804BD8: ori         $a1, $a1, 0x6388
    ctx->r5 = ctx->r5 | 0X6388;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80804BD8: ori         $a1, $a1, 0x6388
    ctx->r5 = ctx->r5 | 0X6388;
    after_3:
    // 0x80804BDC: beq         $v0, $zero, L_80804BEC
    if (ctx->r2 == 0) {
        // 0x80804BE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804BEC;
    }
    // 0x80804BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BE4: jal         0x800936E8
    // 0x80804BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800936E8(rdram, ctx);
        goto after_4;
    // 0x80804BE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80804BEC:
    // 0x80804BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BF0: jal         0x8008CB10
    // 0x80804BF4: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80804BF4: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_5:
    // 0x80804BF8: beq         $v0, $zero, L_80804C10
    if (ctx->r2 == 0) {
        // 0x80804BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C10;
    }
    // 0x80804BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C00: lui         $a2, 0x3F8E
    ctx->r6 = S32(0X3F8E << 16);
    // 0x80804C04: ori         $a2, $a2, 0xF9DB
    ctx->r6 = ctx->r6 | 0XF9DB;
    // 0x80804C08: jal         0x8009DE38
    // 0x80804C0C: addiu       $a1, $zero, 0x442E
    ctx->r5 = ADD32(0, 0X442E);
    func_8009DE38(rdram, ctx);
        goto after_6;
    // 0x80804C0C: addiu       $a1, $zero, 0x442E
    ctx->r5 = ADD32(0, 0X442E);
    after_6:
L_80804C10:
    // 0x80804C10: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80804C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C18: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80804C1C: bnel        $t6, $zero, L_80804C40
    if (ctx->r14 != 0) {
        // 0x80804C20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C40;
    }
    goto skip_0;
    // 0x80804C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80804C24: jal         0x8008CB10
    // 0x80804C28: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_7;
    // 0x80804C28: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_7:
    // 0x80804C2C: beql        $v0, $zero, L_80804C40
    if (ctx->r2 == 0) {
        // 0x80804C30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C40;
    }
    goto skip_1;
    // 0x80804C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80804C34: jal         0x80801A34
    // 0x80804C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A34_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80804C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80804C3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804C40:
    // 0x80804C40: jal         0x8008CB10
    // 0x80804C44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_9;
    // 0x80804C44: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_9:
    // 0x80804C48: beq         $v0, $zero, L_80804C60
    if (ctx->r2 == 0) {
        // 0x80804C4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C60;
    }
    // 0x80804C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C50: addiu       $a1, $zero, 0x4639
    ctx->r5 = ADD32(0, 0X4639);
    // 0x80804C54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804C58: jal         0x8009DB04
    // 0x80804C5C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_10;
    // 0x80804C5C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_10:
L_80804C60:
    // 0x80804C60: lui         $a1, 0x3F1C
    ctx->r5 = S32(0X3F1C << 16);
    // 0x80804C64: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x80804C68: jal         0x8008CB10
    // 0x80804C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_11;
    // 0x80804C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80804C70: beq         $v0, $zero, L_80804C88
    if (ctx->r2 == 0) {
        // 0x80804C74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C88;
    }
    // 0x80804C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C78: addiu       $a1, $zero, 0x463A
    ctx->r5 = ADD32(0, 0X463A);
    // 0x80804C7C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804C80: jal         0x8009DB04
    // 0x80804C84: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_12;
    // 0x80804C84: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_12:
L_80804C88:
    // 0x80804C88: lw          $t7, 0x15C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X15C);
    // 0x80804C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804C90: bnel        $t7, $at, L_80804CF4
    if (ctx->r15 != ctx->r1) {
        // 0x80804C94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804CF4;
    }
    goto skip_2;
    // 0x80804C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80804C98: jal         0x8008CAEC
    // 0x80804C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x80804C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80804CA0: beq         $v0, $zero, L_80804CB8
    if (ctx->r2 == 0) {
        // 0x80804CA4: nop
    
            goto L_80804CB8;
    }
    // 0x80804CA4: nop

    // 0x80804CA8: jal         0x80804A3C
    // 0x80804CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804A3C_bsfirstp(rdram, ctx);
        goto after_14;
    // 0x80804CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80804CB0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80804CB4: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80804CB8:
    // 0x80804CB8: jal         0x80801928
    // 0x80804CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_15;
    // 0x80804CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80804CC0: b           L_80804CF4
    // 0x80804CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804CF4;
    // 0x80804CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804CC8:
    // 0x80804CC8: jal         0x80801928
    // 0x80804CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801928_bsfirstp(rdram, ctx);
        goto after_16;
    // 0x80804CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80804CD0: jal         0x808008B0
    // 0x80804CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_bsfirstp(rdram, ctx);
        goto after_17;
    // 0x80804CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80804CD8: bne         $v0, $zero, L_80804CF0
    if (ctx->r2 != 0) {
        // 0x80804CDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804CF0;
    }
    // 0x80804CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804CE0: jal         0x8009E5C8
    // 0x80804CE4: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80804CE4: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
    after_18:
    // 0x80804CE8: jal         0x80804A3C
    // 0x80804CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804A3C_bsfirstp(rdram, ctx);
        goto after_19;
    // 0x80804CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80804CF0:
    // 0x80804CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804CF4:
    // 0x80804CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804CF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804CFC: jr          $ra
    // 0x80804D00: nop

    return;
    // 0x80804D00: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084ED0: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084ED0);
    return;
    // 0x80084ED4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
