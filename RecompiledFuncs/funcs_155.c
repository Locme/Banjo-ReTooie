#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void badronemem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: jr          $ra
    // 0x80800064: sw          $zero, 0x18C($a0)
    MEM_W(0X18C, ctx->r4) = 0;
    return;
    // 0x80800064: sw          $zero, 0x18C($a0)
    MEM_W(0X18C, ctx->r4) = 0;
    // 0x80800068: nop

    // 0x8080006C: nop

;}
RECOMP_FUNC void chfactoryprop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1124, 0XC68) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xC68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XC68));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xC68
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XC68));
;}
RECOMP_FUNC void _bafly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BE0: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BE0);
    return;
    // 0x80084BE4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C08: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C08);
    return;
    // 0x80083C0C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chtorpedo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080059C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808005A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808005A4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x808005A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808005AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808005B4: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x808005B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808005BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005C0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808005C4: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808005C8: jal         0x800C6A7C
    // 0x808005CC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800C6A7C(rdram, ctx);
        goto after_0;
    // 0x808005CC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x808005D0: beq         $v0, $zero, L_80800600
    if (ctx->r2 == 0) {
        // 0x808005D4: addiu       $s1, $sp, 0x20
        ctx->r17 = ADD32(ctx->r29, 0X20);
            goto L_80800600;
    }
    // 0x808005D4: addiu       $s1, $sp, 0x20
    ctx->r17 = ADD32(ctx->r29, 0X20);
    // 0x808005D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005E0: jal         0x800EFB24
    // 0x808005E4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808005E4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x808005E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005EC: jal         0x800EF368
    // 0x808005F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x808005F0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x808005F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808005F8: jal         0x800EF04C
    // 0x808005FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x808005FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80800600:
    // 0x80800600: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    // 0x80800604: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800608: jal         0x80108474
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_4;
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800610: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800614: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800618: jal         0x80100094
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800624: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800628: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080062C: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800630: jal         0x800EE7F8
    // 0x80800634: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800634: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x80800638: jal         0x80800350
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800350_chtorpedo(rdram, ctx);
        goto after_7;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800640: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x80800644: jal         0x800EE7F8
    // 0x80800648: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800648: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x8080064C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: swc1        $f6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f6.u32l;
    // 0x80800658: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8080065C: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x80800660: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800664: sw          $t7, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r15;
    // 0x80800668: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080066C: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x80800670: jal         0x8010A570
    // 0x80800674: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    func_8010A570(rdram, ctx);
        goto after_9;
    // 0x80800674: swc1        $f8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f8.u32l;
    after_9:
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x8008A768
    // 0x80800680: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumissilehome_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800680: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080068C: jal         0x8008A780
    // 0x80800690: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    _sumissilehome_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800690: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_11:
    // 0x80800694: jal         0x800EA05C
    // 0x80800698: nop

    func_800EA05C(rdram, ctx);
        goto after_12;
    // 0x80800698: nop

    after_12:
    // 0x8080069C: addiu       $at, $zero, 0x181
    ctx->r1 = ADD32(0, 0X181);
    // 0x808006A0: bne         $v0, $at, L_808006BC
    if (ctx->r2 != ctx->r1) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006BC;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006AC: jal         0x8008A770
    // 0x808006B0: addiu       $a2, $zero, 0x1C7
    ctx->r6 = ADD32(0, 0X1C7);
    _sumissilehome_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x808006B0: addiu       $a2, $zero, 0x1C7
    ctx->r6 = ADD32(0, 0X1C7);
    after_13:
    // 0x808006B4: b           L_808006DC
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808006DC;
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006BC:
    // 0x808006BC: jal         0x800EA068
    // 0x808006C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_14;
    // 0x808006C0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x808006C4: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x808006C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006D0: jal         0x8008A788
    // 0x808006D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumissilehome_entrypoint_4(rdram, ctx);
        goto after_15;
    // 0x808006D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
L_808006D8:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006DC:
    // 0x808006DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006E0: jal         0x8008A778
    // 0x808006E4: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    _sumissilehome_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x808006E4: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    after_16:
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006F0: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x808006F4: jal         0x8008A790
    // 0x808006F8: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    _sumissilehome_entrypoint_5(rdram, ctx);
        goto after_17;
    // 0x808006F8: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    after_17:
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: jal         0x808001E0
    // 0x80800704: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001E0_chtorpedo(rdram, ctx);
        goto after_18;
    // 0x80800704: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
    // 0x80800708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080070C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80800710: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080071C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808017B4_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017BC: jal         0x8010C754
    // 0x808017C0: nop

    func_8010C754(rdram, ctx);
        goto after_0;
    // 0x808017C0: nop

    after_0:
    // 0x808017C4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808017C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1E24) << 16);
    // 0x808017CC: lwc1        $f6, 0x1E24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1E24));
    // 0x808017D0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808017D4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808017D8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808017DC: nop

    // 0x808017E0: bc1t        L_80801800
    if (c1cs) {
        // 0x808017E4: nop
    
            goto L_80801800;
    }
    // 0x808017E4: nop

    // 0x808017E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808017EC: nop

    // 0x808017F0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808017F4: nop

    // 0x808017F8: bc1f        L_80801808
    if (!c1cs) {
        // 0x808017FC: nop
    
            goto L_80801808;
    }
    // 0x808017FC: nop

L_80801800:
    // 0x80801800: b           L_80801810
    // 0x80801804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801810;
    // 0x80801804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801808:
    // 0x80801808: jal         0x8010D248
    // 0x8080180C: nop

    func_8010D248(rdram, ctx);
        goto after_1;
    // 0x8080180C: nop

    after_1:
L_80801810:
    // 0x80801810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801818: jr          $ra
    // 0x8080181C: nop

    return;
    // 0x8080181C: nop

;}
RECOMP_FUNC void func_80800788_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080078C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800790: jal         0x808001A8
    // 0x80800794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800794: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800798: jal         0x80082FE0
    // 0x8080079C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080079C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void func_80803698_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080369C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036A0: jal         0x80088568
    // 0x808036A4: nop

    _glsavegame_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808036A4: nop

    after_0:
    // 0x808036A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808036AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808036B0: jr          $ra
    // 0x808036B4: nop

    return;
    // 0x808036B4: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: jr          $ra
    // 0x808005C4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    return;
    // 0x808005C4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void ovl_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081798: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8008179C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800817A0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800817A4: addiu       $s0, $s0, 0x6730
    ctx->r16 = ADD32(ctx->r16, 0X6730);
    // 0x800817A8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800817AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800817B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800817B4: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800817B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800817BC: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x800817C0: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800817C4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800817C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800817CC: jal         0x8001E210
    // 0x800817D0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800817D0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x800817D4: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x800817D8: jal         0x8001E210
    // 0x800817DC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800817DC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x800817E0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x800817E4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800817E8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800817EC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800817F0: addu        $s1, $v1, $t8
    ctx->r17 = ADD32(ctx->r3, ctx->r24);
    // 0x800817F4: subu        $t0, $t9, $v1
    ctx->r8 = SUB32(ctx->r25, ctx->r3);
    // 0x800817F8: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x800817FC: jal         0x8001E210
    // 0x80081800: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    rom_read_word(rdram, ctx);
        goto after_2;
    // 0x80081800: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_2:
    // 0x80081804: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80081808: jal         0x8001E210
    // 0x8008180C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x8008180C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80081810: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    // 0x80081814: lbu         $t2, 0x47($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X47);
    // 0x80081818: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x8008181C: sll         $s0, $a1, 4
    ctx->r16 = S32(ctx->r5 << 4);
    // 0x80081820: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80081824: beq         $t3, $zero, L_80081858
    if (ctx->r11 == 0) {
        // 0x80081828: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80081858;
    }
    // 0x80081828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008182C: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x80081830: jal         0x8001E210
    // 0x80081834: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    rom_read_word(rdram, ctx);
        goto after_4;
    // 0x80081834: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80081838: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8008183C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80081840: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x80081844: srl         $t5, $t4, 16
    ctx->r13 = S32(U32(ctx->r12) >> 16);
    // 0x80081848: sll         $v1, $t5, 4
    ctx->r3 = S32(ctx->r13 << 4);
    // 0x8008184C: addu        $a0, $v1, $s0
    ctx->r4 = ADD32(ctx->r3, ctx->r16);
    // 0x80081850: b           L_80081860
    // 0x80081854: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
        goto L_80081860;
    // 0x80081854: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80081858:
    // 0x80081858: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008185C: addu        $a0, $t7, $a1
    ctx->r4 = ADD32(ctx->r15, ctx->r5);
L_80081860:
    // 0x80081860: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80081864: lw          $t8, 0x6CB8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6CB8);
    // 0x80081868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008186C: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80081870: beq         $t8, $zero, L_8008188C
    if (ctx->r24 == 0) {
        // 0x80081874: nop
    
            goto L_8008188C;
    }
    // 0x80081874: nop

    // 0x80081878: jal         0x8001ACEC
    // 0x8008187C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    heap_alloc_sided(rdram, ctx);
        goto after_5;
    // 0x8008187C: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_5:
    // 0x80081880: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80081884: b           L_800818C8
    // 0x80081888: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800818C8;
    // 0x80081888: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8008188C:
    // 0x8008188C: bne         $t9, $zero, L_800818A0
    if (ctx->r25 != 0) {
        // 0x80081890: lbu         $t0, 0x47($sp)
        ctx->r8 = MEM_BU(ctx->r29, 0X47);
            goto L_800818A0;
    }
    // 0x80081890: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80081894: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x80081898: beq         $t1, $zero, L_800818B8
    if (ctx->r9 == 0) {
        // 0x8008189C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800818B8;
    }
    // 0x8008189C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800818A0:
    // 0x800818A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800818A4: jal         0x8001ACEC
    // 0x800818A8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    heap_alloc_sided(rdram, ctx);
        goto after_6;
    // 0x800818A8: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_6:
    // 0x800818AC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800818B0: b           L_800818C8
    // 0x800818B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800818C8;
    // 0x800818B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800818B8:
    // 0x800818B8: jal         0x8001ACEC
    // 0x800818BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    heap_alloc_sided(rdram, ctx);
        goto after_7;
    // 0x800818BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_7:
    // 0x800818C0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800818C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800818C8:
    // 0x800818C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800818CC: jal         0x8001B3B0
    // 0x800818D0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    func_8001B3B0(rdram, ctx);
        goto after_8;
    // 0x800818D0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    after_8:
    // 0x800818D4: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800818D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800818DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800818E0: beq         $v1, $zero, L_8008195C
    if (ctx->r3 == 0) {
        // 0x800818E4: nop
    
            goto L_8008195C;
    }
    // 0x800818E4: nop

    // 0x800818E8: jal         0x8001ACCC
    // 0x800818EC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    heap_alloc(rdram, ctx);
        goto after_9;
    // 0x800818EC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_9:
    // 0x800818F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800818F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800818F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800818FC: jal         0x80012F78
    // 0x80081900: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    rom_dma_read(rdram, ctx);
        goto after_10;
    // 0x80081900: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_10:
    // 0x80081904: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80081908: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8008190C: jal         0x80031BF0
    // 0x80081910: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _bcopy(rdram, ctx);
        goto after_11;
    // 0x80081910: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_11:
    // 0x80081914: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80081918: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8008191C: jal         0x8001C2AC
    // 0x80081920: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8001C2AC(rdram, ctx);
        goto after_12;
    // 0x80081920: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_12:
    // 0x80081924: jal         0x8001C26C
    // 0x80081928: nop

    func_8001C26C(rdram, ctx);
        goto after_13;
    // 0x80081928: nop

    after_13:
    // 0x8008192C: jal         0x8001C28C
    // 0x80081930: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_8001C28C(rdram, ctx);
        goto after_14;
    // 0x80081930: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_14:
    // 0x80081934: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80081938: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x8008193C: xor         $t3, $t2, $s1
    ctx->r11 = ctx->r10 ^ ctx->r17;
    // 0x80081940: xor         $t5, $t4, $v0
    ctx->r13 = ctx->r12 ^ ctx->r2;
    // 0x80081944: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80081948: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x8008194C: jal         0x8001B084
    // 0x80081950: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    heap_free(rdram, ctx);
        goto after_15;
    // 0x80081950: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80081954: b           L_80081968
    // 0x80081958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80081968;
    // 0x80081958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008195C:
    // 0x8008195C: jal         0x80012F78
    // 0x80081960: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    rom_dma_read(rdram, ctx);
        goto after_16;
    // 0x80081960: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_16:
    // 0x80081964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80081968:
    // 0x80081968: jal         0x80082380
    // 0x8008196C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ovl_clear_bss(rdram, ctx);
        goto after_17;
    // 0x8008196C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x80081970: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80081974: addiu       $a0, $a0, 0x7C60
    ctx->r4 = ADD32(ctx->r4, 0X7C60);
    // 0x80081978: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008197C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80081980: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80081984: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80081988: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8008198C: sw          $s0, 0x6738($at)
    MEM_W(0X6738, ctx->r1) = ctx->r16;
    // 0x80081990: sh          $v1, 0x30($s0)
    MEM_H(0X30, ctx->r16) = ctx->r3;
    // 0x80081994: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80081998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008199C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800819A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800819A4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800819A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800819AC: jr          $ra
    // 0x800819B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800819B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_808036C0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808036C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808036CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808036D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808036D4: jal         0x80100094
    // 0x808036D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808036D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808036DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808036E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808036E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808036E8: bne         $t6, $at, L_8080370C
    if (ctx->r14 != ctx->r1) {
        // 0x808036EC: nop
    
            goto L_8080370C;
    }
    // 0x808036EC: nop

    // 0x808036F0: lw          $a1, 0x64($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X64);
    // 0x808036F4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808036F8: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x808036FC: jal         0x800BD268
    // 0x80803700: srl         $a1, $t8, 30
    ctx->r5 = S32(U32(ctx->r24) >> 30);
    func_800BD268(rdram, ctx);
        goto after_1;
    // 0x80803700: srl         $a1, $t8, 30
    ctx->r5 = S32(U32(ctx->r24) >> 30);
    after_1:
    // 0x80803704: b           L_80803714
    // 0x80803708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803714;
    // 0x80803708: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080370C:
    // 0x8080370C: b           L_80803714
    // 0x80803710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803714;
    // 0x80803710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803714:
    // 0x80803714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080371C: jr          $ra
    // 0x80803720: nop

    return;
    // 0x80803720: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E00: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E00);
    return;
    // 0x80084E04: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800CFC_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D0C: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800D10: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800D14: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800D18: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800D1C: beq         $t6, $zero, L_80800D40
    if (ctx->r14 == 0) {
        // 0x80800D20: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800D40;
    }
    // 0x80800D20: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80800D24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D28: beq         $t6, $at, L_80800D60
    if (ctx->r14 == ctx->r1) {
        // 0x80800D2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D60;
    }
    // 0x80800D2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D30: beql        $t6, $at, L_80800D54
    if (ctx->r14 == ctx->r1) {
        // 0x80800D34: lhu         $t7, 0x6E($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X6E);
            goto L_80800D54;
    }
    goto skip_0;
    // 0x80800D34: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
    skip_0:
    // 0x80800D38: b           L_80800D74
    // 0x80800D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D74;
    // 0x80800D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D40:
    // 0x80800D40: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800D44: jal         0x800856B0
    // 0x80800D48: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800D48: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800D4C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800D50: lhu         $t7, 0x6E($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X6E);
L_80800D54:
    // 0x80800D54: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800D58: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80800D5C: sh          $t9, 0x6E($a3)
    MEM_H(0X6E, ctx->r7) = ctx->r25;
L_80800D60:
    // 0x80800D60: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800D64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D68: jal         0x800856D0
    // 0x80800D6C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D6C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D74:
    // 0x80800D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D78: jr          $ra
    // 0x80800D7C: nop

    return;
    // 0x80800D7C: nop

;}
RECOMP_FUNC void func_808036F8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808036FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803700: jal         0x80088528
    // 0x80803704: nop

    _glsavegame_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80803704: nop

    after_0:
    // 0x80803708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080370C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803710: jr          $ra
    // 0x80803714: nop

    return;
    // 0x80803714: nop

;}
RECOMP_FUNC void func_808001F0_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800200: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800204: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800208: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x8080020C: srl         $t7, $v1, 7
    ctx->r15 = S32(U32(ctx->r3) >> 7);
    // 0x80800210: addiu       $v1, $t7, -0x32
    ctx->r3 = ADD32(ctx->r15, -0X32);
    // 0x80800214: jal         0x80800144
    // 0x80800218: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80800144_chnests(rdram, ctx);
        goto after_0;
    // 0x80800218: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8080021C: jal         0x808000E8
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000E8_chnests(rdram, ctx);
        goto after_1;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800224: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080022C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(752, 0X11DC) << 16);
    // 0x80800230: beq         $v1, $at, L_80800248
    if (ctx->r3 == ctx->r1) {
        // 0x80800234: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_80800248;
    }
    // 0x80800234: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80800238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080023C: beq         $v1, $at, L_80800248
    if (ctx->r3 == ctx->r1) {
        // 0x80800240: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800248;
    }
    // 0x80800240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800244: bne         $v1, $at, L_808002C4
    if (ctx->r3 != ctx->r1) {
        // 0x80800248: addiu       $t9, $t9, 0x11DC
        ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(752, 0X11DC));
            goto L_808002C4;
    }
L_80800248:
    // 0x80800248: addiu       $t9, $t9, 0x11DC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(752, 0X11DC));
    // 0x8080024C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80800250: lh          $t0, -0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X4);
    // 0x80800254: lh          $t1, -0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X2);
    // 0x80800258: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8080025C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800260: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800264: jal         0x800DC178
    // 0x80800268: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800268: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x8080026C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800270: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x8080027C: jal         0x8010A570
    // 0x80800280: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800280: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_3:
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: jal         0x80103110
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x8080028C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x8008A4B0
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080029C: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002A8: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808002AC: jal         0x80101FDC
    // 0x808002B0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808002B0: sw          $t5, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r13;
    after_6:
    // 0x808002B4: jal         0x80800B80
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B80_chnests(rdram, ctx);
        goto after_7;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002BC: b           L_808002D0
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002D0;
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C4:
    // 0x808002C4: jal         0x800FFA88
    // 0x808002C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x808002C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002D0:
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_808009F0_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F8: jal         0x80800270
    // 0x808009FC: nop

    func_80800270_bsswim(rdram, ctx);
        goto after_0;
    // 0x808009FC: nop

    after_0:
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
RECOMP_FUNC void bsdronelook_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80084C98
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800018: bne         $v0, $at, L_80800028
    if (ctx->r2 != ctx->r1) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800028;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: jal         0x80084CE0
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800028:
    // 0x80800028: jal         0x80084CA8
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800030: beql        $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800034: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800034: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800038: jal         0x800A4EC8
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4EC8(rdram, ctx);
        goto after_3;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800040: jal         0x80084D00
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080004C:
    // 0x8080004C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878E8: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878E8);
    return;
    // 0x800878EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chlifeforcespell_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800368: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080036C: jal         0x80106790
    // 0x80800370: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800370: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800374: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080037C: jal         0x80100094
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800384: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800388: jal         0x800DA298
    // 0x8080038C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080038C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_2:
    // 0x80800390: beq         $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x80800394: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80800424;
    }
    // 0x80800394: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800398: beq         $t6, $zero, L_80800424
    if (ctx->r14 == 0) {
        // 0x8080039C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800424;
    }
    // 0x8080039C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808003A0: jal         0x80089CD8
    // 0x808003A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808003A4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808003A8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808003AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003B0: lui         $a2, 0x3FEC
    ctx->r6 = S32(0X3FEC << 16);
    // 0x808003B4: lhu         $t7, 0x72($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X72);
    // 0x808003B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003C0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808003C4: bne         $t8, $at, L_808003FC
    if (ctx->r24 != ctx->r1) {
        // 0x808003C8: nop
    
            goto L_808003FC;
    }
    // 0x808003C8: nop

    // 0x808003CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003D0: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    // 0x808003D4: jal         0x800F10B4
    // 0x808003D8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808003D8: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x808003DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1328, 0X4C0) << 16);
    // 0x808003E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003E4: addiu       $a2, $a2, 0x4C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1328, 0X4C0));
    // 0x808003E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808003EC: jal         0x800F3214
    // 0x808003F0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F3214(rdram, ctx);
        goto after_5;
    // 0x808003F0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x808003F4: b           L_80800434
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800434;
    // 0x808003F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003FC:
    // 0x808003FC: jal         0x800898F0
    // 0x80800400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_6;
    // 0x80800400: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80800404: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1328, 0X4C0) << 16);
    // 0x80800408: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080040C: addiu       $a2, $a2, 0x4C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1328, 0X4C0));
    // 0x80800410: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800414: jal         0x800F3214
    // 0x80800418: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F3214(rdram, ctx);
        goto after_7;
    // 0x80800418: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x8080041C: b           L_80800434
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800434;
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800424:
    // 0x80800424: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800428: jal         0x80089CD8
    // 0x8080042C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x8080042C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80800430: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800434:
    // 0x80800434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800438: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

    // 0x80800444: nop

    // 0x80800448: nop

    // 0x8080044C: nop

;}
RECOMP_FUNC void func_80093528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093528: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009352C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093530: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093534: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80093538: sb          $zero, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = 0;
    // 0x8009353C: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x80093540: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80093544: jal         0x800DBEB0
    // 0x80093548: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DBEB0(rdram, ctx);
        goto after_0;
    // 0x80093548: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009354C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80093550: lw          $t8, 0x50($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X50);
    // 0x80093554: sb          $zero, 0x16($t8)
    MEM_B(0X16, ctx->r24) = 0;
    // 0x80093558: lw          $t9, 0x50($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X50);
    // 0x8009355C: sb          $zero, 0xA5($t9)
    MEM_B(0XA5, ctx->r25) = 0;
    // 0x80093560: lw          $v0, 0x50($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X50);
    // 0x80093564: lbu         $v1, 0xA5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XA5);
    // 0x80093568: sb          $v1, 0xA1($v0)
    MEM_B(0XA1, ctx->r2) = ctx->r3;
    // 0x8009356C: lw          $t0, 0x50($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X50);
    // 0x80093570: sb          $v1, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r3;
    // 0x80093574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009357C: jr          $ra
    // 0x80093580: nop

    return;
    // 0x80093580: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FC0: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083FC0);
    return;
    // 0x80083FC4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800DBB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBB24: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DBB28: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    // 0x800DBB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBB34: beql        $a0, $zero, L_800DBB50
    if (ctx->r4 == 0) {
        // 0x800DBB38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DBB50;
    }
    goto skip_0;
    // 0x800DBB38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DBB3C: jal         0x800B3248
    // 0x800DBB40: nop

    freelist_free(rdram, ctx);
        goto after_0;
    // 0x800DBB40: nop

    after_0:
    // 0x800DBB44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DBB48: sw          $zero, -0x3820($at)
    MEM_W(-0X3820, ctx->r1) = 0;
    // 0x800DBB4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DBB50:
    // 0x800DBB50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBB54: jr          $ra
    // 0x800DBB58: nop

    return;
    // 0x800DBB58: nop

;}
RECOMP_FUNC void func_8080000C_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: lbu         $t6, 0x64($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X64);
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800024: jal         0x80800828
    // 0x80800028: sb          $t7, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r15;
    func_80800828_chcablespark(rdram, ctx);
        goto after_0;
    // 0x80800028: sb          $t7, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r15;
    after_0:
    // 0x8080002C: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    // 0x80800038: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x8080003C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(968, 0XBD0) << 16);
    // 0x80800040: srl         $t1, $a2, 10
    ctx->r9 = S32(U32(ctx->r6) >> 10);
    // 0x80800044: xori        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 ^ 0X3;
    // 0x80800048: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8080004C: sb          $t0, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r8;
    // 0x80800050: sltiu       $a2, $t2, 0x1
    ctx->r6 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x80800054: addiu       $a3, $a3, 0xBD0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(968, 0XBD0));
    // 0x80800058: jal         0x80089D50
    // 0x8080005C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080005C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800060: jal         0x800D90A4
    // 0x80800064: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800068: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080006C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800074: srl         $t3, $v1, 10
    ctx->r11 = S32(U32(ctx->r3) >> 10);
    // 0x80800078: beq         $t3, $at, L_80800098
    if (ctx->r11 == ctx->r1) {
        // 0x8080007C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800098;
    }
    // 0x8080007C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800080: beq         $t3, $at, L_80800130
    if (ctx->r11 == ctx->r1) {
        // 0x80800084: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800130;
    }
    // 0x80800084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800088: beql        $t3, $at, L_8080016C
    if (ctx->r11 == ctx->r1) {
        // 0x8080008C: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x8080008C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800090: b           L_8080023C
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800098:
    // 0x80800098: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x8080009C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x808000A0: bgez        $t6, L_808000DC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808000A4: nop
    
            goto L_808000DC;
    }
    // 0x808000A4: nop

    // 0x808000A8: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x808000AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80089BD8
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000BC: bne         $v0, $at, L_80800238
    if (ctx->r2 != ctx->r1) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80101FDC
    // 0x808000C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000CC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808000D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000D4: b           L_80800238
    // 0x808000D8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800238;
    // 0x808000D8: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808000DC:
    // 0x808000DC: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x808000E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080023C;
    }
    goto skip_1;
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808000E4: jal         0x808007B8
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B8_chcablespark(rdram, ctx);
        goto after_5;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000EC: bne         $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80101FDC
    // 0x808000F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808000F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB50) << 16);
    // 0x80800100: lwc1        $f12, 0xB50($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB50));
    // 0x80800104: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB54) << 16);
    // 0x80800108: jal         0x800DC178
    // 0x8080010C: lwc1        $f14, 0xB54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB54));
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080010C: lwc1        $f14, 0xB54($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB54));
    after_7:
    // 0x80800110: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800114: jal         0x80800668
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800668_chcablespark(rdram, ctx);
        goto after_8;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080011C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800120: jal         0x800C8FE0
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_9;
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800128: b           L_8080023C
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x80800134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80101FDC
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x8080013C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800144: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x80800668
    // 0x80800150: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80800668_chcablespark(rdram, ctx);
        goto after_11;
    // 0x80800150: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_11:
    // 0x80800154: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800158: jal         0x800C8FE0
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_12;
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800160: b           L_8080023C
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_8080016C:
    // 0x8080016C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800170: bgez        $t9, L_80800180
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800174: nop
    
            goto L_80800180;
    }
    // 0x80800174: nop

    // 0x80800178: b           L_8080018C
    // 0x8080017C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
        goto L_8080018C;
    // 0x8080017C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80800180:
    // 0x80800180: jal         0x808007B8
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B8_chcablespark(rdram, ctx);
        goto after_13;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800188: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8080018C:
    // 0x8080018C: jal         0x80800970
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800970_chcablespark(rdram, ctx);
        goto after_14;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB58) << 16);
    // 0x80800198: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080019C: jal         0x800DC298
    // 0x808001A0: lwc1        $f12, 0xB58($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB58));
    func_800DC298(rdram, ctx);
        goto after_15;
    // 0x808001A0: lwc1        $f12, 0xB58($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB58));
    after_15:
    // 0x808001A4: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x808001A8: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x808001AC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(968, 0XB70) << 16);
    // 0x808001B0: addiu       $t1, $t1, 0xB70
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(968, 0XB70));
    // 0x808001B4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808001B8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x808001BC: jal         0x800C8E84
    // 0x808001C0: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    func_800C8E84(rdram, ctx);
        goto after_16;
    // 0x808001C0: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    after_16:
    // 0x808001C4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: bne         $t2, $zero, L_808001E8
    if (ctx->r10 != 0) {
        // 0x808001D4: nop
    
            goto L_808001E8;
    }
    // 0x808001D4: nop

    // 0x808001D8: bne         $t3, $zero, L_808001E8
    if (ctx->r11 != 0) {
        // 0x808001DC: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_808001E8;
    }
    // 0x808001DC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: beql        $t4, $zero, L_8080023C
    if (ctx->r12 == 0) {
        // 0x808001E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080023C;
    }
    goto skip_2;
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_808001E8:
    // 0x808001E8: jal         0x80101FDC
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808001F0: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x808001F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808001F8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x808001FC: bgezl       $t7, L_80800224
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800200: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800224;
    }
    goto skip_3;
    // 0x80800200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80800204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB5C) << 16);
    // 0x80800208: lwc1        $f12, 0xB5C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB5C));
    // 0x8080020C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(968, 0XB60) << 16);
    // 0x80800210: jal         0x800DC178
    // 0x80800214: lwc1        $f14, 0xB60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB60));
    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x80800214: lwc1        $f14, 0xB60($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(968, 0XB60));
    after_18:
    // 0x80800218: b           L_8080022C
    // 0x8080021C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_8080022C;
    // 0x8080021C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800220: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800224:
    // 0x80800224: nop

    // 0x80800228: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_8080022C:
    // 0x8080022C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80800230: jal         0x800C8FE0
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_19;
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
L_80800238:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080023C:
    // 0x8080023C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800240: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_808034C8_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808034CC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808034D0: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x808034D4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808034D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808034DC: beq         $a1, $at, L_80803508
    if (ctx->r5 == ctx->r1) {
        // 0x808034E0: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80803508;
    }
    // 0x808034E0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808034E4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808034E8: beq         $a1, $at, L_80803530
    if (ctx->r5 == ctx->r1) {
        // 0x808034EC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80803530;
    }
    // 0x808034EC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808034F0: bne         $a1, $at, L_8080358C
    if (ctx->r5 != ctx->r1) {
        // 0x808034F4: nop
    
            goto L_8080358C;
    }
    // 0x808034F4: nop

    // 0x808034F8: jal         0x8080300C
    // 0x808034FC: nop

    func_8080300C_chevilmumbo(rdram, ctx);
        goto after_0;
    // 0x808034FC: nop

    after_0:
    // 0x80803500: b           L_80803598
    // 0x80803504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803598;
    // 0x80803504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803508:
    // 0x80803508: jal         0x80106790
    // 0x8080350C: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080350C: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    after_1:
    // 0x80803510: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x80803514: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80803518: bgez        $t8, L_80803528
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080351C: nop
    
            goto L_80803528;
    }
    // 0x8080351C: nop

    // 0x80803520: b           L_80803598
    // 0x80803524: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80803598;
    // 0x80803524: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80803528:
    // 0x80803528: b           L_80803598
    // 0x8080352C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803598;
    // 0x8080352C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803530:
    // 0x80803530: jal         0x801040D0
    // 0x80803534: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_801040D0(rdram, ctx);
        goto after_2;
    // 0x80803534: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_2:
    // 0x80803538: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080353C: jal         0x801015D0
    // 0x80803540: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_801015D0(rdram, ctx);
        goto after_3;
    // 0x80803540: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x80803544: jal         0x800DF41C
    // 0x80803548: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DF41C(rdram, ctx);
        goto after_4;
    // 0x80803548: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x8080354C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80803550: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80803554: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80803558: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080355C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80803560: jal         0x800EFA4C
    // 0x80803564: lw          $a1, 0x18($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X18);
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80803564: lw          $a1, 0x18($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X18);
    after_5:
    // 0x80803568: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080356C: jal         0x800D93A0
    // 0x80803570: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800D93A0(rdram, ctx);
        goto after_6;
    // 0x80803570: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80803574: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80803578: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080357C: jal         0x800DFF2C
    // 0x80803580: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800DFF2C(rdram, ctx);
        goto after_7;
    // 0x80803580: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_7:
    // 0x80803584: b           L_80803598
    // 0x80803588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803598;
    // 0x80803588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080358C:
    // 0x8080358C: b           L_80803598
    // 0x80803590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803598;
    // 0x80803590: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803594: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803598:
    // 0x80803598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080359C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808035A0: jr          $ra
    // 0x808035A4: nop

    return;
    // 0x808035A4: nop

;}
RECOMP_FUNC void func_80800084_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: lui         $t6, 0x4B48
    ctx->r14 = S32(0X4B48 << 16);
    // 0x80800088: ori         $t6, $t6, 0x4A43
    ctx->r14 = ctx->r14 | 0X4A43;
    // 0x8080008C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80800090: jr          $ra
    // 0x80800094: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800094: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chcheatomenu_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C50: syscall     434
    recomp_syscall_handler(rdram, ctx, 0x80086C50);
    return;
    // 0x80086C54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddieitem_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FD0: syscall     821
    recomp_syscall_handler(rdram, ctx, 0x80089FD0);
    return;
    // 0x80089FD4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D7488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7488: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D748C: addiu       $v1, $v1, -0x4190
    ctx->r3 = ADD32(ctx->r3, -0X4190);
    // 0x800D7490: lw          $t6, 0x188($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X188);
    // 0x800D7494: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D7498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D749C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D74A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D74A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D74A8: sw          $t7, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->r15;
    // 0x800D74AC: sll         $a1, $t7, 1
    ctx->r5 = S32(ctx->r15 << 1);
    // 0x800D74B0: jal         0x8001B710
    // 0x800D74B4: lh          $a0, 0x184($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X184);
    func_8001B710(rdram, ctx);
        goto after_0;
    // 0x800D74B4: lh          $a0, 0x184($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X184);
    after_0:
    // 0x800D74B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D74BC: addiu       $v1, $v1, -0x4190
    ctx->r3 = ADD32(ctx->r3, -0X4190);
    // 0x800D74C0: lw          $a1, 0x188($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X188);
    // 0x800D74C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D74C8: lh          $a0, 0x186($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X186);
    // 0x800D74CC: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x800D74D0: jal         0x8001B710
    // 0x800D74D4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800D74D4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_1:
    // 0x800D74D8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D74DC: addiu       $v1, $v1, -0x4190
    ctx->r3 = ADD32(ctx->r3, -0X4190);
    // 0x800D74E0: lw          $t2, 0x188($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X188);
    // 0x800D74E4: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800D74E8: lh          $t0, 0x22($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X22);
    // 0x800D74EC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D74F0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D74F4: sh          $t0, -0x2($t4)
    MEM_H(-0X2, ctx->r12) = ctx->r8;
    // 0x800D74F8: lw          $t6, 0x188($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X188);
    // 0x800D74FC: lh          $t5, 0x26($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X26);
    // 0x800D7500: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800D7504: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800D7508: sh          $t5, -0x2($t8)
    MEM_H(-0X2, ctx->r24) = ctx->r13;
    // 0x800D750C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7510: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // 0x800D7514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D7518: jr          $ra
    // 0x800D751C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    return;
    // 0x800D751C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
;}
RECOMP_FUNC void _chfactoryentrydoors_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870D8: syscall     512
    recomp_syscall_handler(rdram, ctx, 0x800870D8);
    return;
    // 0x800870DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008FE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FE9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FEA0: jal         0x800F54E4
    // 0x8008FEA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FEA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008FEA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FEAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FEB0: jal         0x800F5A2C
    // 0x8008FEB4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F5A2C(rdram, ctx);
        goto after_1;
    // 0x8008FEB4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008FEB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FEBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FEC0: jr          $ra
    // 0x8008FEC4: nop

    return;
    // 0x8008FEC4: nop

;}
RECOMP_FUNC void func_80800178_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800184: jal         0x80100094
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080018C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800190: jal         0x8008A2F8
    // 0x80800194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800198: jal         0x800FCCD4
    // 0x8080019C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x8080019C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_2:
    // 0x808001A0: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001A4: addiu       $a0, $zero, 0x53
        ctx->r4 = ADD32(0, 0X53);
            goto L_808001BC;
    }
    // 0x808001A4: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001AC: jal         0x800FCAE0
    // 0x808001B0: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x808001B0: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_3:
    // 0x808001B4: jal         0x800FCA90
    // 0x808001B8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800FCA90(rdram, ctx);
        goto after_4;
    // 0x808001B8: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_4:
L_808001BC:
    // 0x808001BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C4: addiu       $a1, $a1, 0xB0
    ctx->r5 = ADD32(ctx->r5, 0XB0);
    // 0x808001C8: jal         0x8008A2B0
    // 0x808001CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808001CC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x808001D0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001D4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808001E0;
    }
    // 0x808001D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808001D8: jal         0x8008A2C0
    // 0x808001DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808001DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_808001E0:
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_80800000_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x8080000C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800010: beq         $v0, $at, L_80800028
    if (ctx->r2 == ctx->r1) {
        // 0x80800014: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800028;
    }
    // 0x80800014: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800018: beql        $v0, $at, L_80800044
    if (ctx->r2 == ctx->r1) {
        // 0x8080001C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800044;
    }
    goto skip_0;
    // 0x8080001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80800020: b           L_80800058
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_80800058;
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800028:
    // 0x80800028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080002C: jal         0x80800148
    // 0x80800030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800148_bsdronegoto(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: b           L_80800054
    // 0x8080003C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_80800054;
    // 0x8080003C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80800044:
    // 0x80800044: jal         0x8080032C
    // 0x80800048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8080032C_bsdronegoto(rdram, ctx);
        goto after_1;
    // 0x80800048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800054:
    // 0x80800054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800058:
    // 0x80800058: beq         $a1, $at, L_80800074
    if (ctx->r5 == ctx->r1) {
        // 0x8080005C: sw          $a1, 0x190($a0)
        MEM_W(0X190, ctx->r4) = ctx->r5;
            goto L_80800074;
    }
    // 0x8080005C: sw          $a1, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->r5;
    // 0x80800060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800064: beq         $a1, $at, L_80800084
    if (ctx->r5 == ctx->r1) {
        // 0x80800068: nop
    
            goto L_80800084;
    }
    // 0x80800068: nop

    // 0x8080006C: b           L_80800090
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800090;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: jal         0x808000C0
    // 0x80800078: nop

    func_808000C0_bsdronegoto(rdram, ctx);
        goto after_2;
    // 0x80800078: nop

    after_2:
    // 0x8080007C: b           L_80800090
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800090;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800084:
    // 0x80800084: jal         0x80800150
    // 0x80800088: nop

    func_80800150_bsdronegoto(rdram, ctx);
        goto after_3;
    // 0x80800088: nop

    after_3:
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
RECOMP_FUNC void _bamovegoto_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E10: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E10);
    return;
    // 0x80084E14: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void gcfrontend_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003FC: jal         0x800AA074
    // 0x80800400: nop

    func_800AA074(rdram, ctx);
        goto after_0;
    // 0x80800400: nop

    after_0:
    // 0x80800404: jal         0x800AA00C
    // 0x80800408: nop

    func_800AA00C(rdram, ctx);
        goto after_1;
    // 0x80800408: nop

    after_1:
    // 0x8080040C: jal         0x8080039C
    // 0x80800410: nop

    gcfrontend_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800410: nop

    after_2:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_8001D6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D6C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001D6C4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8001D6C8: sll         $t7, $a2, 5
    ctx->r15 = S32(ctx->r6 << 5);
    // 0x8001D6CC: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x8001D6D0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8001D6D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001D6D8: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8001D6DC: addu        $t7, $t7, $a2
    ctx->r15 = ADD32(ctx->r15, ctx->r6);
    // 0x8001D6E0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8001D6E4: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x8001D6E8: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8001D6EC: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x8001D6F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001D6F4: addu        $t2, $t2, $t6
    ctx->r10 = ADD32(ctx->r10, ctx->r14);
    // 0x8001D6F8: addiu       $t0, $t9, 0x260
    ctx->r8 = ADD32(ctx->r25, 0X260);
    // 0x8001D6FC: addiu       $t3, $t2, -0xA0
    ctx->r11 = ADD32(ctx->r10, -0XA0);
    // 0x8001D700: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001D704: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001D708: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001D70C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001D710: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001D714: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8001D718: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8001D71C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001D720: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001D724: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001D728: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001D72C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001D730: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8001D734: addu        $fp, $a0, $t1
    ctx->r30 = ADD32(ctx->r4, ctx->r9);
    // 0x8001D738: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x8001D73C: addiu       $s4, $zero, 0x11
    ctx->r20 = ADD32(0, 0X11);
    // 0x8001D740: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x8001D744: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8001D748: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8001D74C:
    // 0x8001D74C: sll         $t5, $s6, 1
    ctx->r13 = S32(ctx->r22 << 1);
    // 0x8001D750: addu        $s2, $t5, $fp
    ctx->r18 = ADD32(ctx->r13, ctx->r30);
    // 0x8001D754: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001D758: jal         0x8002E6E0
    // 0x8001D75C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D75C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8001D760: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8001D764: sll         $t6, $s7, 1
    ctx->r14 = S32(ctx->r23 << 1);
    // 0x8001D768: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001D76C: addiu       $t9, $t9, -0x888
    ctx->r25 = ADD32(ctx->r25, -0X888);
    // 0x8001D770: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D774: addu        $s3, $t8, $t9
    ctx->r19 = ADD32(ctx->r24, ctx->r25);
    // 0x8001D778: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001D77C: addu        $t0, $s3, $s0
    ctx->r8 = ADD32(ctx->r19, ctx->r16);
L_8001D780:
    // 0x8001D780: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x8001D784: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x8001D788: addu        $t1, $s2, $s0
    ctx->r9 = ADD32(ctx->r18, ctx->r16);
    // 0x8001D78C: beq         $s4, $v0, L_8001D79C
    if (ctx->r20 == ctx->r2) {
        // 0x8001D790: nop
    
            goto L_8001D79C;
    }
    // 0x8001D790: nop

    // 0x8001D794: b           L_8001D7A8
    // 0x8001D798: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
        goto L_8001D7A8;
    // 0x8001D798: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
L_8001D79C:
    // 0x8001D79C: jal         0x8001D450
    // 0x8001D7A0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    func_8001D450(rdram, ctx);
        goto after_1;
    // 0x8001D7A0: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    after_1:
    // 0x8001D7A4: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8001D7A8:
    // 0x8001D7A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8001D7AC: bnel        $s0, $s5, L_8001D780
    if (ctx->r16 != ctx->r21) {
        // 0x8001D7B0: addu        $t0, $s3, $s0
        ctx->r8 = ADD32(ctx->r19, ctx->r16);
            goto L_8001D780;
    }
    goto skip_0;
    // 0x8001D7B0: addu        $t0, $s3, $s0
    ctx->r8 = ADD32(ctx->r19, ctx->r16);
    skip_0:
    // 0x8001D7B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001D7B8: jal         0x8002E660
    // 0x8001D7BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x8001D7BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x8001D7C0: addiu       $s6, $s6, 0x130
    ctx->r22 = ADD32(ctx->r22, 0X130);
    // 0x8001D7C4: addiu       $at, $zero, 0x850
    ctx->r1 = ADD32(0, 0X850);
    // 0x8001D7C8: bne         $s6, $at, L_8001D74C
    if (ctx->r22 != ctx->r1) {
        // 0x8001D7CC: addiu       $s7, $s7, 0x1DC
        ctx->r23 = ADD32(ctx->r23, 0X1DC);
            goto L_8001D74C;
    }
    // 0x8001D7CC: addiu       $s7, $s7, 0x1DC
    ctx->r23 = ADD32(ctx->r23, 0X1DC);
    // 0x8001D7D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001D7D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001D7D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D7DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001D7E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001D7E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001D7E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001D7EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001D7F0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001D7F4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001D7F8: jr          $ra
    // 0x8001D7FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001D7FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sumumbofx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: lh          $t6, 0x58($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X58);
    // 0x8080036C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800370: addiu       $v0, $a0, 0x64
    ctx->r2 = ADD32(ctx->r4, 0X64);
    // 0x80800374: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800378: blez        $t6, L_808003B0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080037C: swc1        $f4, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
            goto L_808003B0;
    }
    // 0x8080037C: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80800380: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800384: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800388: nop

L_8080038C:
    // 0x8080038C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80800390: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800394: lh          $t7, 0x58($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X58);
    // 0x80800398: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080039C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808003A0: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808003A4: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x808003A8: bne         $at, $zero, L_8080038C
    if (ctx->r1 != 0) {
        // 0x808003AC: swc1        $f8, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
            goto L_8080038C;
    }
    // 0x808003AC: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_808003B0:
    // 0x808003B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808003BC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808003C0: nop

    // 0x808003C4: bc1t        L_808003DC
    if (c1cs) {
        // 0x808003C8: nop
    
            goto L_808003DC;
    }
    // 0x808003C8: nop

    // 0x808003CC: lbu         $t9, 0x60($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X60);
    // 0x808003D0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x808003D4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x808003D8: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
L_808003DC:
    // 0x808003DC: jr          $ra
    // 0x808003E0: nop

    return;
    // 0x808003E0: nop

;}
RECOMP_FUNC void func_80803658_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080365C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803660: jal         0x80088560
    // 0x80803664: nop

    _glsavegame_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80803664: nop

    after_0:
    // 0x80803668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080366C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803670: jr          $ra
    // 0x80803674: nop

    return;
    // 0x80803674: nop

;}
RECOMP_FUNC void func_80807C8C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807C8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807C94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807C98: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80807C9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807CA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80807CA4: jal         0x8009E74C
    // 0x80807CA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x80807CA8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80807CAC: bne         $v0, $zero, L_80807D34
    if (ctx->r2 != 0) {
        // 0x80807CB0: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80807D34;
    }
    // 0x80807CB0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80807CB4: lw          $a0, 0x68($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X68);
    // 0x80807CB8: bltz        $a0, L_80807CD4
    if (SIGNED(ctx->r4) < 0) {
        // 0x80807CBC: nop
    
            goto L_80807CD4;
    }
    // 0x80807CBC: nop

    // 0x80807CC0: jal         0x800F7B9C
    // 0x80807CC4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80807CC4: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_1:
    // 0x80807CC8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80807CCC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80807CD0: sw          $t8, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->r24;
L_80807CD4:
    // 0x80807CD4: jal         0x80807A70
    // 0x80807CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807A70_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80807CDC: jal         0x80801AEC
    // 0x80807CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AEC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80807CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80807CE4: jal         0x80805F68
    // 0x80807CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80805F68_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80807CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80807CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807CF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80807CF4: jal         0x80098140
    // 0x80807CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_5;
    // 0x80807CF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80807CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807D00: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80807D04: jal         0x800947EC
    // 0x80807D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_6;
    // 0x80807D08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80807D0C: jal         0x80809CB4
    // 0x80807D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809CB4_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80807D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80807D14: jal         0x80803B04
    // 0x80807D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803B04_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x80807D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80807D1C: jal         0x808018E0
    // 0x80807D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808018E0_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80807D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80807D24: jal         0x80808084
    // 0x80807D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808084_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x80807D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80807D2C: jal         0x80800040
    // 0x80807D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_bsfirstp(rdram, ctx);
        goto after_11;
    // 0x80807D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80807D34:
    // 0x80807D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80807D38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807D3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80807D40: jr          $ra
    // 0x80807D44: nop

    return;
    // 0x80807D44: nop

;}
RECOMP_FUNC void func_80800700_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: jal         0x808009E4
    // 0x8080070C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808009E4_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x8080070C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800710: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x80800714: addiu       $t6, $zero, 0x1350
        ctx->r14 = ADD32(0, 0X1350);
            goto L_80800724;
    }
    // 0x80800714: addiu       $t6, $zero, 0x1350
    ctx->r14 = ADD32(0, 0X1350);
    // 0x80800718: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0X100C) << 16);
    // 0x8080071C: b           L_80800750
    // 0x80800720: sh          $t6, 0x100C($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0X100C), ctx->r1) = ctx->r14;
        goto L_80800750;
    // 0x80800720: sh          $t6, 0x100C($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0X100C), ctx->r1) = ctx->r14;
L_80800724:
    // 0x80800724: jal         0x80800A54
    // 0x80800728: nop

    func_80800A54_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800728: nop

    after_1:
    // 0x8080072C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800730: bne         $v0, $at, L_80800748
    if (ctx->r2 != ctx->r1) {
        // 0x80800734: addiu       $t8, $zero, 0x134E
        ctx->r24 = ADD32(0, 0X134E);
            goto L_80800748;
    }
    // 0x80800734: addiu       $t8, $zero, 0x134E
    ctx->r24 = ADD32(0, 0X134E);
    // 0x80800738: addiu       $t7, $zero, 0x134F
    ctx->r15 = ADD32(0, 0X134F);
    // 0x8080073C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0X100C) << 16);
    // 0x80800740: b           L_80800750
    // 0x80800744: sh          $t7, 0x100C($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0X100C), ctx->r1) = ctx->r15;
        goto L_80800750;
    // 0x80800744: sh          $t7, 0x100C($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0X100C), ctx->r1) = ctx->r15;
L_80800748:
    // 0x80800748: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2168, 0X100C) << 16);
    // 0x8080074C: sh          $t8, 0x100C($at)
    MEM_H((int16_t)RELOC_LO16(2168, 0X100C), ctx->r1) = ctx->r24;
L_80800750:
    // 0x80800750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800754: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2168, 0X1008) << 16);
    // 0x80800758: addiu       $a2, $a2, 0x1008
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2168, 0X1008));
    // 0x8080075C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800760: jal         0x8008A1E8
    // 0x80800764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800768: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x8080076C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800778;
    }
    // 0x8080076C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800770: jal         0x80090734
    // 0x80800774: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_3;
    // 0x80800774: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
L_80800778:
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080077C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void func_800A1240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A1244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A1248: jal         0x800D5210
    // 0x800A124C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D5210(rdram, ctx);
        goto after_0;
    // 0x800A124C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A1250: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A1254: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1258: addiu       $v1, $v1, 0x7090
    ctx->r3 = ADD32(ctx->r3, 0X7090);
    // 0x800A125C: sb          $v0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r2;
    // 0x800A1260: addiu       $a0, $zero, 0xCF
    ctx->r4 = ADD32(0, 0XCF);
    // 0x800A1264: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x800A1268: jal         0x800D2748
    // 0x800A126C: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
    func_800D2748(rdram, ctx);
        goto after_1;
    // 0x800A126C: sb          $t6, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r14;
    after_1:
    // 0x800A1270: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1274: addiu       $v1, $v1, 0x7090
    ctx->r3 = ADD32(ctx->r3, 0X7090);
    // 0x800A1278: lbu         $a1, 0x9($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X9);
    // 0x800A127C: jal         0x800D2748
    // 0x800A1280: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    func_800D2748(rdram, ctx);
        goto after_2;
    // 0x800A1280: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    after_2:
    // 0x800A1284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A1288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A128C: jr          $ra
    // 0x800A1290: nop

    return;
    // 0x800A1290: nop

;}
RECOMP_FUNC void chfactoryroofbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2280, 0X974) << 16);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0X974));
    return;
    // 0x80800158: addiu       $v0, $v0, 0x974
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2280, 0X974));
;}
RECOMP_FUNC void func_800C13B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13B0: lhu         $t6, 0x7C($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X7C);
    // 0x800C13B4: nor         $t7, $a1, $zero
    ctx->r15 = ~(ctx->r5 | 0);
    // 0x800C13B8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x800C13BC: jr          $ra
    // 0x800C13C0: sh          $t8, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r24;
    return;
    // 0x800C13C0: sh          $t8, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void _bskazshock_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083580: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083580);
    return;
    // 0x80083584: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chhotwaterpoolbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086430: syscall     323
    recomp_syscall_handler(rdram, ctx, 0x80086430);
    return;
    // 0x80086434: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void suexpression_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: jr          $ra
    // 0x80800424: sb          $zero, 0x12($a0)
    MEM_B(0X12, ctx->r4) = 0;
    return;
    // 0x80800424: sb          $zero, 0x12($a0)
    MEM_B(0X12, ctx->r4) = 0;
;}
RECOMP_FUNC void gczoombox_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803CF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80803CF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803CFC: nop

    // 0x80803D00: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80803D04: jr          $ra
    // 0x80803D08: swc1        $f6, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80803D08: swc1        $f6, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void _sumumbofx_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898D0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898D0);
    return;
    // 0x800898D4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void chintrocam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800900: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1736, 0XA20) << 16);
    // 0x80800904: jr          $ra
    // 0x80800908: addiu       $v0, $v0, 0xA20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1736, 0XA20));
    return;
    // 0x80800908: addiu       $v0, $v0, 0xA20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1736, 0XA20));
    // 0x8080090C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080053C: jr          $ra
    // 0x80800540: sb          $a0, 0x75F6($at)
    MEM_B(0X75F6, ctx->r1) = ctx->r4;
    return;
    // 0x80800540: sb          $a0, 0x75F6($at)
    MEM_B(0X75F6, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_808004A8_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004B4: jal         0x80800040
    // 0x808004B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80800040_bsledge(rdram, ctx);
        goto after_0;
    // 0x808004B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808004BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004C0: jal         0x8009BA9C
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009BA9C(rdram, ctx);
        goto after_1;
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
