#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chlagoonbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1052, 0X8DC) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x8DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X8DC));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x8DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X8DC));
;}
RECOMP_FUNC void _bskazshock_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083590: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083590);
    return;
    // 0x80083594: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bsfirstp_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806DF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80806DFC: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB560) << 16);
    // 0x80806E00: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80806E04: jr          $ra
    // 0x80806E08: lw          $v0, -0x4AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB560));
    return;
    // 0x80806E08: lw          $v0, -0x4AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB560));
;}
RECOMP_FUNC void _bskazfly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833B8: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x800833B8);
    return;
    // 0x800833BC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _baeggsetup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A68: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A68);
    return;
    // 0x80084A6C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bsbabykaz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808007DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1740) << 16);
    // 0x808007E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808007E4: jr          $ra
    // 0x808007E8: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1740));
    return;
    // 0x808007E8: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1740));
;}
RECOMP_FUNC void baduo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808000B0: jr          $ra
    // 0x808000B4: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
    return;
    // 0x808000B4: lbu         $v0, 0x1($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1);
;}
RECOMP_FUNC void func_80800040_chhagstraindoorswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: jal         0x80085808
    // 0x80800050: addiu       $a1, $zero, 0x403
    ctx->r5 = ADD32(0, 0X403);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800050: addiu       $a1, $zero, 0x403
    ctx->r5 = ADD32(0, 0X403);
    after_0:
    // 0x80800054: jal         0x80085818
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_800DB9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DB9D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DB9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800DB9D8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800DB9DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DB9E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DB9E4: jal         0x800B301C
    // 0x800DB9E8: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800DB9E8: lw          $a0, -0x3820($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3820);
    after_0:
    // 0x800DB9EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DB9F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DB9F4: jr          $ra
    // 0x800DB9F8: nop

    return;
    // 0x800DB9F8: nop

;}
RECOMP_FUNC void func_808009E8_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F0: jal         0x80082FE8
    // 0x808009F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808009F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009F8: jal         0x808005DC
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
RECOMP_FUNC void func_80800228_cheggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: jal         0x8008A3A0
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _suegg_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800238: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2108, 0X3B0) << 16);
    // 0x8080023C: addiu       $a1, $a1, 0x3B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2108, 0X3B0));
    // 0x80800240: jal         0x8008A420
    // 0x80800244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _suegg_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x80800244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void chfactoryflypad_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1288, 0X250) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1288, 0X250));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x250
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1288, 0X250));
;}
RECOMP_FUNC void func_808017F4_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808017F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808017FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801800: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801804: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801808: jal         0x80110024
    // 0x8080180C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x8080180C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801810: jal         0x800894E0
    // 0x80801814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpod_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801818: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080181C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801820: jal         0x808023B4
    // 0x80801824: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_808023B4_ncpoddialog(rdram, ctx);
        goto after_2;
    // 0x80801824: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x80801828: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080182C: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x80801830: jal         0x808012A0
    // 0x80801834: addiu       $a2, $s0, 0xD0
    ctx->r6 = ADD32(ctx->r16, 0XD0);
    func_808012A0_ncpoddialog(rdram, ctx);
        goto after_3;
    // 0x80801834: addiu       $a2, $s0, 0xD0
    ctx->r6 = ADD32(ctx->r16, 0XD0);
    after_3:
    // 0x80801838: jal         0x800136E4
    // 0x8080183C: lwc1        $f12, 0xD0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD0);
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080183C: lwc1        $f12, 0xD0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD0);
    after_4:
    // 0x80801840: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x80801844: jal         0x800136E4
    // 0x80801848: lwc1        $f12, 0xD4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD4);
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80801848: lwc1        $f12, 0xD4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XD4);
    after_5:
    // 0x8080184C: swc1        $f0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->f0.u32l;
    // 0x80801850: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x80801854: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x80801858: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080185C: jal         0x800F1DF4
    // 0x80801860: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F1DF4(rdram, ctx);
        goto after_6;
    // 0x80801860: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_6:
    // 0x80801864: jal         0x800136E4
    // 0x80801868: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80801868: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x8080186C: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x80801870: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801874: jal         0x800F1828
    // 0x80801878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F1828(rdram, ctx);
        goto after_8;
    // 0x80801878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x8080187C: jal         0x800136E4
    // 0x80801880: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_9;
    // 0x80801880: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_9:
    // 0x80801884: swc1        $f0, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f0.u32l;
    // 0x80801888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080188C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801890: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801894: jr          $ra
    // 0x80801898: nop

    return;
    // 0x80801898: nop

;}
RECOMP_FUNC void func_800205D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800205D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800205D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800205D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800205DC: jal         0x8002FEC0
    // 0x800205E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800205E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800205E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800205E8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800205EC: lw          $t6, 0x11D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11D0);
    // 0x800205F0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800205F4: bne         $t6, $t7, L_8002060C
    if (ctx->r14 != ctx->r15) {
        // 0x800205F8: nop
    
            goto L_8002060C;
    }
    // 0x800205F8: nop

    // 0x800205FC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80020600: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020604: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80020608: sw          $t9, 0x11D0($at)
    MEM_W(0X11D0, ctx->r1) = ctx->r25;
L_8002060C:
    // 0x8002060C: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80020610: lw          $t0, 0x11D4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11D4);
    // 0x80020614: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80020618: bne         $t0, $t1, L_80020630
    if (ctx->r8 != ctx->r9) {
        // 0x8002061C: nop
    
            goto L_80020630;
    }
    // 0x8002061C: nop

    // 0x80020620: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80020624: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020628: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8002062C: sw          $t3, 0x11D4($at)
    MEM_W(0X11D4, ctx->r1) = ctx->r11;
L_80020630:
    // 0x80020630: jal         0x80020E74
    // 0x80020634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x80020634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80020638: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002063C: lw          $t4, 0x11D8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X11D8);
    // 0x80020640: beq         $t4, $zero, L_80020680
    if (ctx->r12 == 0) {
        // 0x80020644: nop
    
            goto L_80020680;
    }
    // 0x80020644: nop

    // 0x80020648: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8002064C: lw          $t5, 0x11D8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X11D8);
    // 0x80020650: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80020654: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80020658: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002065C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80020660: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80020664: lw          $t9, 0x11D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11D8);
    // 0x80020668: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002066C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80020670: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80020674: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020678: b           L_800206A0
    // 0x8002067C: sw          $t0, 0x11D8($at)
    MEM_W(0X11D8, ctx->r1) = ctx->r8;
        goto L_800206A0;
    // 0x8002067C: sw          $t0, 0x11D8($at)
    MEM_W(0X11D8, ctx->r1) = ctx->r8;
L_80020680:
    // 0x80020680: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80020684: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80020688: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002068C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80020690: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x80020694: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80020698: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002069C: sw          $t4, 0x11D8($at)
    MEM_W(0X11D8, ctx->r1) = ctx->r12;
L_800206A0:
    // 0x800206A0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800206A4: lbu         $t6, 0x44($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X44);
    // 0x800206A8: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800206AC: beq         $t7, $zero, L_800206C8
    if (ctx->r15 == 0) {
        // 0x800206B0: nop
    
            goto L_800206C8;
    }
    // 0x800206B0: nop

    // 0x800206B4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800206B8: lh          $t8, 0x11E0($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X11E0);
    // 0x800206BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800206C0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800206C4: sh          $t9, 0x11E0($at)
    MEM_H(0X11E0, ctx->r1) = ctx->r25;
L_800206C8:
    // 0x800206C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800206CC: sb          $zero, 0x45($t0)
    MEM_B(0X45, ctx->r8) = 0;
    // 0x800206D0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800206D4: lw          $t3, 0x30($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X30);
    // 0x800206D8: beq         $t3, $zero, L_80020708
    if (ctx->r11 == 0) {
        // 0x800206DC: nop
    
            goto L_80020708;
    }
    // 0x800206DC: nop

    // 0x800206E0: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800206E4: lw          $t4, 0x30($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X30);
    // 0x800206E8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800206EC: bne         $t5, $t2, L_80020700
    if (ctx->r13 != ctx->r10) {
        // 0x800206F0: nop
    
            goto L_80020700;
    }
    // 0x800206F0: nop

    // 0x800206F4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800206F8: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x800206FC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_80020700:
    // 0x80020700: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80020704: sw          $zero, 0x30($t8)
    MEM_W(0X30, ctx->r24) = 0;
L_80020708:
    // 0x80020708: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002070C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020710: jal         0x800E90A4
    // 0x80020714: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    func_800E90A4(rdram, ctx);
        goto after_2;
    // 0x80020714: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    after_2:
    // 0x80020718: jal         0x8002FEC0
    // 0x8002071C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8002071C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80020720: b           L_80020728
    // 0x80020724: nop

        goto L_80020728;
    // 0x80020724: nop

L_80020728:
    // 0x80020728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002072C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80020730: jr          $ra
    // 0x80020734: nop

    return;
    // 0x80020734: nop

;}
RECOMP_FUNC void chlagoonufoint_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(748, 0X1A90) << 16);
    // 0x8080073C: jr          $ra
    // 0x80800740: addiu       $v0, $v0, 0x1A90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1A90));
    return;
    // 0x80800740: addiu       $v0, $v0, 0x1A90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X1A90));
;}
RECOMP_FUNC void _cadbfunc_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855F0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855F0);
    return;
    // 0x800855F4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800EEEA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEEA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EEEAC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEEB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEEB4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800EEEB8: nop

    // 0x800EEEBC: bc1tl       L_800EEECC
    if (c1cs) {
        // 0x800EEEC0: sltiu       $v0, $v0, 0x1
        ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_800EEECC;
    }
    goto skip_0;
    // 0x800EEEC0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    skip_0:
    // 0x800EEEC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEEC8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800EEECC:
    // 0x800EEECC: beq         $v0, $zero, L_800EEF1C
    if (ctx->r2 == 0) {
        // 0x800EEED0: nop
    
            goto L_800EEF1C;
    }
    // 0x800EEED0: nop

    // 0x800EEED4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEEDC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800EEEE0: nop

    // 0x800EEEE4: bc1tl       L_800EEEF4
    if (c1cs) {
        // 0x800EEEE8: sltiu       $v0, $v0, 0x1
        ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_800EEEF4;
    }
    goto skip_1;
    // 0x800EEEE8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    skip_1:
    // 0x800EEEEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEEF0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800EEEF4:
    // 0x800EEEF4: beq         $v0, $zero, L_800EEF1C
    if (ctx->r2 == 0) {
        // 0x800EEEF8: nop
    
            goto L_800EEF1C;
    }
    // 0x800EEEF8: nop

    // 0x800EEEFC: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEF00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EEF04: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x800EEF08: nop

    // 0x800EEF0C: bc1tl       L_800EEF1C
    if (c1cs) {
        // 0x800EEF10: sltiu       $v0, $v0, 0x1
        ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
            goto L_800EEF1C;
    }
    goto skip_2;
    // 0x800EEF10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    skip_2:
    // 0x800EEF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEF18: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_800EEF1C:
    // 0x800EEF1C: jr          $ra
    // 0x800EEF20: nop

    return;
    // 0x800EEF20: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842D8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842D8);
    return;
    // 0x800842DC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _subaddiemulti_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A098: syscall     826
    recomp_syscall_handler(rdram, ctx, 0x8008A098);
    return;
    // 0x8008A09C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncstart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
    // 0x8080000C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800014: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80800018: jal         0x800A9C98
    // 0x8080001C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x80800028: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800044;
    }
    // 0x80800028: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080002C: blez        $a0, L_80800058
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800030: slti        $at, $a0, 0x9
        ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
            goto L_80800058;
    }
    // 0x80800030: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x80800034: beql        $at, $zero, L_8080005C
    if (ctx->r1 == 0) {
        // 0x80800038: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080005C;
    }
    goto skip_0;
    // 0x80800038: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x8080003C: b           L_80800058
    // 0x80800040: addiu       $a3, $a0, 0xAD
    ctx->r7 = ADD32(ctx->r4, 0XAD);
        goto L_80800058;
    // 0x80800040: addiu       $a3, $a0, 0xAD
    ctx->r7 = ADD32(ctx->r4, 0XAD);
L_80800044:
    // 0x80800044: blez        $a0, L_80800058
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80800048: slti        $at, $a0, 0x29
        ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
            goto L_80800058;
    }
    // 0x80800048: slti        $at, $a0, 0x29
    ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
    // 0x8080004C: beql        $at, $zero, L_8080005C
    if (ctx->r1 == 0) {
        // 0x80800050: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080005C;
    }
    goto skip_1;
    // 0x80800050: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x80800054: addiu       $a3, $a0, 0x29
    ctx->r7 = ADD32(ctx->r4, 0X29);
L_80800058:
    // 0x80800058: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8080005C:
    // 0x8080005C: jal         0x800882E8
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800064: beq         $v0, $zero, L_808000BC
    if (ctx->r2 == 0) {
        // 0x80800068: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000BC;
    }
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: jal         0x80088C00
    // 0x80800074: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800074: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800078: jal         0x80088C08
    // 0x8080007C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x8080007C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80800080: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800084: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800088: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080008C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800090: jal         0x800136E4
    // 0x80800094: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800094: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_4:
    // 0x80800098: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080009C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000A4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808000A8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808000AC: jal         0x800EFA4C
    // 0x808000B0: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x808000B0: nop

    after_5:
    // 0x808000B4: b           L_808000C0
    // 0x808000B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C0;
    // 0x808000B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000BC:
    // 0x808000BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C0:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void glsplinecs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: jal         0x800D035C
    // 0x80800018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void _idtwinklecolour_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EC8: syscall     747
    recomp_syscall_handler(rdram, ctx, 0x80088EC8);
    return;
    // 0x80088ECC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chflysaucer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C08: syscall     430
    recomp_syscall_handler(rdram, ctx, 0x80086C08);
    return;
    // 0x80086C0C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800D90_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D94: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x80800D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DA0: bne         $at, $zero, L_80800DC4
    if (ctx->r1 != 0) {
        // 0x80800DA4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800DC4;
    }
    // 0x80800DA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800DA8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800DAC: beq         $a1, $at, L_80800EF8
    if (ctx->r5 == ctx->r1) {
        // 0x80800DB0: addiu       $at, $zero, 0x97
        ctx->r1 = ADD32(0, 0X97);
            goto L_80800EF8;
    }
    // 0x80800DB0: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x80800DB4: beq         $a1, $at, L_80800F40
    if (ctx->r5 == ctx->r1) {
        // 0x80800DB8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2252, 0X1250) << 16);
            goto L_80800F40;
    }
    // 0x80800DB8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2252, 0X1250) << 16);
    // 0x80800DBC: b           L_80800F54
    // 0x80800DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F54;
    // 0x80800DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DC4:
    // 0x80800DC4: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80800DC8: bne         $at, $zero, L_80800DF0
    if (ctx->r1 != 0) {
        // 0x80800DCC: addiu       $t6, $a1, -0x38
        ctx->r14 = ADD32(ctx->r5, -0X38);
            goto L_80800DF0;
    }
    // 0x80800DCC: addiu       $t6, $a1, -0x38
    ctx->r14 = ADD32(ctx->r5, -0X38);
    // 0x80800DD0: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80800DD4: beq         $at, $zero, L_80800F50
    if (ctx->r1 == 0) {
        // 0x80800DD8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800F50;
    }
    // 0x80800DD8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800DDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2252, 0XFB0) << 16);
    // 0x80800DE0: addu        $at, $at, $t6
    gpr jr_addend_80800DE8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800DE4: lw          $t6, 0xFB0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2252, 0XFB0));
    // 0x80800DE8: jr          $t6
    // 0x80800DEC: nop

    switch (jr_addend_80800DE8 >> 2) {
        case 0: goto L_80800EE4; break;
        case 1: goto L_80800F50; break;
        case 2: goto L_80800F50; break;
        case 3: goto L_80800F50; break;
        case 4: goto L_80800F50; break;
        case 5: goto L_80800EA8; break;
        case 6: goto L_80800E10; break;
        case 7: goto L_80800E10; break;
        case 8: goto L_80800E74; break;
        default: switch_error(__func__, 0x80800DE8, 0x80800FB0);
    }
    // 0x80800DEC: nop

L_80800DF0:
    // 0x80800DF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DF4: beq         $a1, $at, L_80800E88
    if (ctx->r5 == ctx->r1) {
        // 0x80800DF8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800E88;
    }
    // 0x80800DF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E00: beq         $a1, $at, L_80800E98
    if (ctx->r5 == ctx->r1) {
        // 0x80800E04: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800E98;
    }
    // 0x80800E04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E08: b           L_80800F54
    // 0x80800E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F54;
    // 0x80800E0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E10:
    // 0x80800E10: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800E14: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80800E18: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800E1C: bltzl       $t0, L_80800E44
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800E20: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_80800E44;
    }
    goto skip_0;
    // 0x80800E20: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800E24: lw          $t1, 0x78($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X78);
    // 0x80800E28: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80800E2C: sll         $t3, $t1, 29
    ctx->r11 = S32(ctx->r9 << 29);
    // 0x80800E30: bltzl       $t3, L_80800E44
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800E34: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_80800E44;
    }
    goto skip_1;
    // 0x80800E34: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800E38: jal         0x80800CD0
    // 0x80800E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_0;
    // 0x80800E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800E40: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
L_80800E44:
    // 0x80800E44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E48: lui         $a0, 0x7FEF
    ctx->r4 = S32(0X7FEF << 16);
    // 0x80800E4C: lhu         $t5, 0x72($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X72);
    // 0x80800E50: ori         $a0, $a0, 0xA417
    ctx->r4 = ctx->r4 | 0XA417;
    // 0x80800E54: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800E58: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800E5C: beq         $t6, $at, L_80800E6C
    if (ctx->r14 == ctx->r1) {
        // 0x80800E60: addiu       $a1, $t4, 0x4
        ctx->r5 = ADD32(ctx->r12, 0X4);
            goto L_80800E6C;
    }
    // 0x80800E60: addiu       $a1, $t4, 0x4
    ctx->r5 = ADD32(ctx->r12, 0X4);
    // 0x80800E64: jal         0x800C4140
    // 0x80800E68: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    func_800C4140(rdram, ctx);
        goto after_1;
    // 0x80800E68: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    after_1:
L_80800E6C:
    // 0x80800E6C: b           L_80800F54
    // 0x80800E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800E70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E74:
    // 0x80800E74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E78: jal         0x80800CD0
    // 0x80800E7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_2;
    // 0x80800E7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80800E80: b           L_80800F54
    // 0x80800E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800E84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E88:
    // 0x80800E88: jal         0x80800CD0
    // 0x80800E8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_3;
    // 0x80800E8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800E90: b           L_80800F54
    // 0x80800E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E98:
    // 0x80800E98: jal         0x80800CD0
    // 0x80800E9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_4;
    // 0x80800E9C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800EA0: b           L_80800F54
    // 0x80800EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EA8:
    // 0x80800EA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800EAC: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80800EB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800EB4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800EB8: jal         0x80108528
    // 0x80800EBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_5;
    // 0x80800EBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80800EC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EC4: jal         0x80103EF4
    // 0x80800EC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80103EF4(rdram, ctx);
        goto after_6;
    // 0x80800EC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800ECC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800ED4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800ED8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800EDC: b           L_80800F54
    // 0x80800EE0: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
        goto L_80800F54;
    // 0x80800EE0: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_80800EE4:
    // 0x80800EE4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2252, 0X1044) << 16);
    // 0x80800EE8: jal         0x80101074
    // 0x80800EEC: addiu       $a0, $a0, 0x1044
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2252, 0X1044));
    func_80101074(rdram, ctx);
        goto after_7;
    // 0x80800EEC: addiu       $a0, $a0, 0x1044
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2252, 0X1044));
    after_7:
    // 0x80800EF0: b           L_80800F54
    // 0x80800EF4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800F54;
    // 0x80800EF4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800EF8:
    // 0x80800EF8: jal         0x80089F60
    // 0x80800EFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800EFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80800F00: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800F04: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800F08: lhu         $t9, 0x76($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X76);
    // 0x80800F0C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800F10: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80800F14: bnel        $t0, $at, L_80800F30
    if (ctx->r8 != ctx->r1) {
        // 0x80800F18: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800F30;
    }
    goto skip_2;
    // 0x80800F18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x80800F1C: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x80800F20: addiu       $a1, $zero, 0x7D0
    ctx->r5 = ADD32(0, 0X7D0);
    // 0x80800F24: jal         0x80103140
    // 0x80800F28: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    func_80103140(rdram, ctx);
        goto after_9;
    // 0x80800F28: lhu         $a2, 0x16($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0X16);
    after_9:
    // 0x80800F2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800F30:
    // 0x80800F30: jal         0x80800CD0
    // 0x80800F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800CD0_chfactorydrums(rdram, ctx);
        goto after_10;
    // 0x80800F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800F38: b           L_80800F54
    // 0x80800F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F40:
    // 0x80800F40: jal         0x80101010
    // 0x80800F44: addiu       $a0, $a0, 0x1250
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2252, 0X1250));
    func_80101010(rdram, ctx);
        goto after_11;
    // 0x80800F44: addiu       $a0, $a0, 0x1250
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2252, 0X1250));
    after_11:
    // 0x80800F48: b           L_80800F54
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F54;
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F50:
    // 0x80800F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F54:
    // 0x80800F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F5C: jr          $ra
    // 0x80800F60: nop

    return;
    // 0x80800F60: nop

;}
RECOMP_FUNC void func_80800C5C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C60: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800C64: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800C68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800C74: bne         $a1, $at, L_80800D3C
    if (ctx->r5 != ctx->r1) {
        // 0x80800C78: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800D3C;
    }
    // 0x80800C78: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800C7C: jal         0x8080108C
    // 0x80800C80: nop

    func_8080108C_chvolcanobits(rdram, ctx);
        goto after_0;
    // 0x80800C80: nop

    after_0:
    // 0x80800C84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800C88: jal         0x800E1540
    // 0x80800C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E1540(rdram, ctx);
        goto after_1;
    // 0x80800C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800C90: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800C94: jal         0x800E1378
    // 0x80800C98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E1378(rdram, ctx);
        goto after_2;
    // 0x80800C98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800C9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CA0: jal         0x800E13F0
    // 0x80800CA4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800E13F0(rdram, ctx);
        goto after_3;
    // 0x80800CA4: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_3:
    // 0x80800CA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10E4) << 16);
    // 0x80800CAC: lwc1        $f6, 0x10E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10E4));
    // 0x80800CB0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800CB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CB8: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x80800CBC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800CC0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800CC4: jal         0x800E1410
    // 0x80800CC8: nop

    func_800E1410(rdram, ctx);
        goto after_4;
    // 0x80800CC8: nop

    after_4:
    // 0x80800CCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1264, 0X10E8) << 16);
    // 0x80800CD0: lwc1        $f16, 0x10E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1264, 0X10E8));
    // 0x80800CD4: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800CD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CDC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80800CE0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800CE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800CE8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800CEC: jal         0x800187B4
    // 0x80800CF0: nop

    func_800187B4(rdram, ctx);
        goto after_5;
    // 0x80800CF0: nop

    after_5:
    // 0x80800CF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CF8: jal         0x80101FDC
    // 0x80800CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80800CFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800D00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D04: jal         0x80103110
    // 0x80800D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80800D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800D0C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800D10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D18: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    // 0x80800D1C: lh          $a2, 0x8($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X8);
    // 0x80800D20: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800D24: beq         $a2, $at, L_80800D34
    if (ctx->r6 == ctx->r1) {
        // 0x80800D28: nop
    
            goto L_80800D34;
    }
    // 0x80800D28: nop

    // 0x80800D2C: jal         0x80085708
    // 0x80800D30: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x80800D30: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
L_80800D34:
    // 0x80800D34: b           L_80800D58
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D58;
    // 0x80800D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D3C:
    // 0x80800D3C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800D40: bne         $a1, $at, L_80800D58
    if (ctx->r5 != ctx->r1) {
        // 0x80800D44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800D58;
    }
    // 0x80800D44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D48: jal         0x80800EF0
    // 0x80800D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800EF0_chvolcanobits(rdram, ctx);
        goto after_9;
    // 0x80800D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80800D50: b           L_80800D58
    // 0x80800D54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D58;
    // 0x80800D54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D58:
    // 0x80800D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D64: jr          $ra
    // 0x80800D68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808013DC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808013E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013E4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808013E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013EC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808013F0: jal         0x80100094
    // 0x808013F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013F8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808013FC: jal         0x800F53D0
    // 0x80801400: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80801400: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x80801404: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80801408: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080140C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80801410: beq         $at, $zero, L_808015C0
    if (ctx->r1 == 0) {
        // 0x80801414: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808015C0;
    }
    // 0x80801414: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2174) << 16);
    // 0x8080141C: addu        $at, $at, $t6
    gpr jr_addend_80801424 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801420: lw          $t6, 0x2174($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2174));
    // 0x80801424: jr          $t6
    // 0x80801428: nop

    switch (jr_addend_80801424 >> 2) {
        case 0: goto L_80801570; break;
        case 1: goto L_8080142C; break;
        case 2: goto L_80801474; break;
        case 3: goto L_808014BC; break;
        case 4: goto L_80801584; break;
        default: switch_error(__func__, 0x80801424, 0x80802174);
    }
    // 0x80801428: nop

L_8080142C:
    // 0x8080142C: jal         0x800A4C68
    // 0x80801430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x80801430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801438: jal         0x800C968C
    // 0x8080143C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_800C968C(rdram, ctx);
        goto after_3;
    // 0x8080143C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_3:
    // 0x80801440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801448: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080144C: jal         0x800854E8
    // 0x80801450: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _bainvisible_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80801450: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80801454: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80801458: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8080145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801464: jal         0x800854E8
    // 0x80801468: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _bainvisible_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80801468: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x8080146C: b           L_808015C4
    // 0x80801470: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_808015C4;
    // 0x80801470: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80801474:
    // 0x80801474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080147C: jal         0x800A38F0
    // 0x80801480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A38F0(rdram, ctx);
        goto after_6;
    // 0x80801480: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80801484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801488: jal         0x800F44DC
    // 0x8080148C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F44DC(rdram, ctx);
        goto after_7;
    // 0x8080148C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801494: jal         0x80093370
    // 0x80801498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80093370(rdram, ctx);
        goto after_8;
    // 0x80801498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8080149C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x808014A0: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x808014A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808014A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014AC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808014B0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808014B4: b           L_808015C0
    // 0x808014B8: swc1        $f4, 0x534($t0)
    MEM_W(0X534, ctx->r8) = ctx->f4.u32l;
        goto L_808015C0;
    // 0x808014B8: swc1        $f4, 0x534($t0)
    MEM_W(0X534, ctx->r8) = ctx->f4.u32l;
L_808014BC:
    // 0x808014BC: jal         0x800A4C68
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_9;
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808014C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808014C8: jal         0x800C968C
    // 0x808014CC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_800C968C(rdram, ctx);
        goto after_10;
    // 0x808014CC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_10:
    // 0x808014D0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808014D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808014D8: jal         0x8008A370
    // 0x808014DC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _sudeathmatch_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808014DC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x808014E0: beq         $v0, $zero, L_808014FC
    if (ctx->r2 == 0) {
        // 0x808014E4: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_808014FC;
    }
    // 0x808014E4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808014E8: jal         0x800F832C
    // 0x808014EC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F832C(rdram, ctx);
        goto after_12;
    // 0x808014EC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_12:
    // 0x808014F0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808014F4: jal         0x800F8294
    // 0x808014F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F8294(rdram, ctx);
        goto after_13;
    // 0x808014F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_13:
L_808014FC:
    // 0x808014FC: jal         0x800A1760
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1760(rdram, ctx);
        goto after_14;
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801508: jal         0x800A1870
    // 0x8080150C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A1870(rdram, ctx);
        goto after_15;
    // 0x8080150C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801518: jal         0x800A38F0
    // 0x8080151C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_16;
    // 0x8080151C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80801520: jal         0x800854C0
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bainvisible_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80801524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080152C: jal         0x80093370
    // 0x80801530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80093370(rdram, ctx);
        goto after_18;
    // 0x80801530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80801534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801538: jal         0x8009337C
    // 0x8080153C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_19;
    // 0x8080153C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80801540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801544: jal         0x800F44DC
    // 0x80801548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F44DC(rdram, ctx);
        goto after_20;
    // 0x80801548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8080154C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801550: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80801554: jal         0x800F7C0C
    // 0x80801558: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_21;
    // 0x80801558: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_21:
    // 0x8080155C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801560: jal         0x800F7F98
    // 0x80801564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_22;
    // 0x80801564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80801568: b           L_808015C4
    // 0x8080156C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_808015C4;
    // 0x8080156C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80801570:
    // 0x80801570: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80801574: jal         0x800F7F98
    // 0x80801578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_23;
    // 0x80801578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x8080157C: b           L_808015C4
    // 0x80801580: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_808015C4;
    // 0x80801580: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80801584:
    // 0x80801584: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80801588: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8080158C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801590: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80801594: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80801598: lw          $v0, 0x530($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X530);
    // 0x8080159C: beq         $v0, $zero, L_808015AC
    if (ctx->r2 == 0) {
        // 0x808015A0: nop
    
            goto L_808015AC;
    }
    // 0x808015A0: nop

    // 0x808015A4: bnel        $v0, $at, L_808015C4
    if (ctx->r2 != ctx->r1) {
        // 0x808015A8: lw          $t8, 0x4C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X4C);
            goto L_808015C4;
    }
    goto skip_0;
    // 0x808015A8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_808015AC:
    // 0x808015AC: jal         0x800A4C68
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_24;
    // 0x808015B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808015B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808015B8: jal         0x800C968C
    // 0x808015BC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_800C968C(rdram, ctx);
        goto after_25;
    // 0x808015BC: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_25:
L_808015C0:
    // 0x808015C0: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_808015C4:
    // 0x808015C4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808015C8: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x808015CC: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x808015D0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x808015D4: sw          $t5, 0x530($t9)
    MEM_W(0X530, ctx->r25) = ctx->r13;
    // 0x808015D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808015E0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808015E4: jr          $ra
    // 0x808015E8: nop

    return;
    // 0x808015E8: nop

;}
RECOMP_FUNC void func_80801318_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80801318_chtntmineshoot");
    // 0x80801318: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080131C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801324: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801328: jal         0x80100094
    // 0x8080132C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080132C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801330: jal         0x800F54E4
    // 0x80801334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80801334: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80801338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080133C: jal         0x800F5A00
    // 0x80801340: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80801340: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80801344: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80801348: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080134C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801350: beq         $v0, $zero, L_80801380
    if (ctx->r2 == 0) {
        // 0x80801354: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80801380;
    }
    // 0x80801354: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801358: beq         $v0, $at, L_808013C4
    if (ctx->r2 == ctx->r1) {
        // 0x8080135C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808013C4;
    }
    // 0x8080135C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801360: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801364: beq         $v0, $at, L_80801404
    if (ctx->r2 == ctx->r1) {
        // 0x80801368: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801404;
    }
    // 0x80801368: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080136C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801370: beq         $v0, $at, L_80801444
    if (ctx->r2 == ctx->r1) {
        // 0x80801374: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801444;
    }
    // 0x80801374: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801378: b           L_8080145C
    // 0x8080137C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080145C;
    // 0x8080137C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801380:
    // 0x80801380: jal         0x800C35E8
    // 0x80801384: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_800C35E8(rdram, ctx);
        goto after_3;
    // 0x80801384: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_3:
    // 0x80801388: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x8080138C: jal         0x800C301C
    // 0x80801390: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    func_800C301C(rdram, ctx);
        goto after_4;
    // 0x80801390: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    after_4:
    // 0x80801394: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80801398: jal         0x800C3058
    // 0x8080139C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x8080139C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_5:
    // 0x808013A0: jal         0x800C3BDC
    // 0x808013A4: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x808013A4: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_6:
    // 0x808013A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808013AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808013B0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808013B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808013B8: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x808013BC: b           L_80801458
    // 0x808013C0: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
        goto L_80801458;
    // 0x808013C0: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_808013C4:
    // 0x808013C4: jal         0x800D9078
    // 0x808013C8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x808013C8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_7:
    // 0x808013CC: beql        $v0, $zero, L_8080145C
    if (ctx->r2 == 0) {
        // 0x808013D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080145C;
    }
    goto skip_0;
    // 0x808013D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808013D4: jal         0x800C3CE8
    // 0x808013D8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_800C3CE8(rdram, ctx);
        goto after_8;
    // 0x808013D8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_8:
    // 0x808013DC: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x808013E0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808013E4: jal         0x80101180
    // 0x808013E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x808013E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808013EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808013F0: jal         0x80801974
    // 0x808013F4: addiu       $a1, $zero, 0xFA3
    ctx->r5 = ADD32(0, 0XFA3);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_10;
    // 0x808013F4: addiu       $a1, $zero, 0xFA3
    ctx->r5 = ADD32(0, 0XFA3);
    after_10:
    // 0x808013F8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808013FC: b           L_80801458
    // 0x80801400: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
        goto L_80801458;
    // 0x80801400: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
L_80801404:
    // 0x80801404: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80801408: jal         0x80800078
    // 0x8080140C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_11;
    // 0x8080140C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_11:
    // 0x80801410: jal         0x80800188
    // 0x80801414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800188_chtntmineshoot(rdram, ctx);
        goto after_12;
    // 0x80801414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80801418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24D0) << 16);
    // 0x8080141C: lwc1        $f12, 0x24D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24D0));
    // 0x80801420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801424: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801428: jal         0x800DC178
    // 0x8080142C: nop

    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x8080142C: nop

    after_13:
    // 0x80801430: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80801434: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80801438: swc1        $f0, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f0.u32l;
    // 0x8080143C: b           L_80801458
    // 0x80801440: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
        goto L_80801458;
    // 0x80801440: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
L_80801444:
    // 0x80801444: jal         0x800D9078
    // 0x80801448: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x80801448: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_14:
    // 0x8080144C: beq         $v0, $zero, L_80801458
    if (ctx->r2 == 0) {
        // 0x80801450: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80801458;
    }
    // 0x80801450: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80801454: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
L_80801458:
    // 0x80801458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080145C:
    // 0x8080145C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801464: jr          $ra
    // 0x80801468: nop

    return;
    // 0x80801468: nop

;}
RECOMP_FUNC void func_800C6E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C6E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6E40: jal         0x800DA298
    // 0x800C6E44: addiu       $a0, $a0, 0xED
    ctx->r4 = ADD32(ctx->r4, 0XED);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800C6E44: addiu       $a0, $a0, 0xED
    ctx->r4 = ADD32(ctx->r4, 0XED);
    after_0:
    // 0x800C6E48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6E4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6E50: jr          $ra
    // 0x800C6E54: nop

    return;
    // 0x800C6E54: nop

;}
RECOMP_FUNC void func_8080040C_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800410: addiu       $at, $zero, 0x1140
    ctx->r1 = ADD32(0, 0X1140);
    // 0x80800414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800418: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080041C: beq         $a1, $at, L_80800440
    if (ctx->r5 == ctx->r1) {
        // 0x80800420: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800440;
    }
    // 0x80800420: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800424: addiu       $at, $zero, 0x1141
    ctx->r1 = ADD32(0, 0X1141);
    // 0x80800428: beq         $a1, $at, L_80800460
    if (ctx->r5 == ctx->r1) {
        // 0x8080042C: addiu       $at, $zero, 0x115B
        ctx->r1 = ADD32(0, 0X115B);
            goto L_80800460;
    }
    // 0x8080042C: addiu       $at, $zero, 0x115B
    ctx->r1 = ADD32(0, 0X115B);
    // 0x80800430: beq         $a1, $at, L_808004A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800434: addiu       $at, $zero, 0x115C
        ctx->r1 = ADD32(0, 0X115C);
            goto L_808004A8;
    }
    // 0x80800434: addiu       $at, $zero, 0x115C
    ctx->r1 = ADD32(0, 0X115C);
    // 0x80800438: bne         $a1, $at, L_80800488
    if (ctx->r5 != ctx->r1) {
        // 0x8080043C: nop
    
            goto L_80800488;
    }
    // 0x8080043C: nop

L_80800440:
    // 0x80800440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800444: jal         0x80100094
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080044C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800450: jal         0x8008A2C0
    // 0x80800454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800458: b           L_808004AC
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004AC;
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800460:
    // 0x80800460: jal         0x800F54E4
    // 0x80800464: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800464: nop

    after_2:
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080046C: jal         0x800F7F98
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x80800470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800474: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800478: jal         0x80101FDC
    // 0x8080047C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080047C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800480: b           L_808004AC
    // 0x80800484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004AC;
    // 0x80800484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800488:
    // 0x80800488: jal         0x800F54E4
    // 0x8080048C: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x8080048C: nop

    after_5:
    // 0x80800490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800494: jal         0x800F7F98
    // 0x80800498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_6;
    // 0x80800498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080049C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004A0: jal         0x80101FDC
    // 0x808004A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808004A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_808004A8:
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004AC:
    // 0x808004AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B0: jr          $ra
    // 0x808004B4: nop

    return;
    // 0x808004B4: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DA0: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DA0);
    return;
    // 0x80082DA4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F49A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F49A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F49AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F49B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F49B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F49B8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F49BC: jal         0x80084838
    // 0x800F49C0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x800F49C0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F49C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F49C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F49CC: jr          $ra
    // 0x800F49D0: nop

    return;
    // 0x800F49D0: nop

;}
RECOMP_FUNC void func_808009C0_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009D4: jal         0x8009E53C
    // 0x808009D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E53C(rdram, ctx);
        goto after_0;
    // 0x808009D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009E4: jal         0x8009E5A4
    // 0x808009E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_1;
    // 0x808009E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009F4: jal         0x8009E55C
    // 0x808009F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_2;
    // 0x808009F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_2:
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: jal         0x80095774
    // 0x80800A04: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x80800A04: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_3:
    // 0x80800A08: jal         0x80800130
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800130_bsstatue(rdram, ctx);
        goto after_4;
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void sumissilehome_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800094: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800098: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808000A4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808000A8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808000AC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x808000B0: lbu         $v0, 0x8($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X8);
    // 0x808000B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808000B8: bne         $v0, $zero, L_808000CC
    if (ctx->r2 != 0) {
        // 0x808000BC: nop
    
            goto L_808000CC;
    }
    // 0x808000BC: nop

    // 0x808000C0: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x808000C4: beql        $t7, $zero, L_80800168
    if (ctx->r15 == 0) {
        // 0x808000C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800168;
    }
    goto skip_0;
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_808000CC:
    // 0x808000CC: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x808000D0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80800114;
    }
    // 0x808000D0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808000D4: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x808000D8: addiu       $a0, $t8, 0x4
    ctx->r4 = ADD32(ctx->r24, 0X4);
    // 0x808000DC: addiu       $a1, $t8, 0x28
    ctx->r5 = ADD32(ctx->r24, 0X28);
    // 0x808000E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x808000E4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808000E8: jal         0x8010A01C
    // 0x808000EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8010A01C(rdram, ctx);
        goto after_0;
    // 0x808000EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x808000F0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x808000F4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808000F8: jal         0x8008A028
    // 0x808000FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800100: jal         0x8008A040
    // 0x80800104: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800104: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800108: bnel        $v0, $zero, L_80800118
    if (ctx->r2 != 0) {
        // 0x8080010C: lbu         $t0, 0x9($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X9);
            goto L_80800118;
    }
    goto skip_1;
    // 0x8080010C: lbu         $t0, 0x9($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9);
    skip_1:
    // 0x80800110: sb          $zero, 0x8($s0)
    MEM_B(0X8, ctx->r16) = 0;
L_80800114:
    // 0x80800114: lbu         $t0, 0x9($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9);
L_80800118:
    // 0x80800118: beql        $t0, $zero, L_80800168
    if (ctx->r8 == 0) {
        // 0x8080011C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800168;
    }
    goto skip_2;
    // 0x8080011C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800120: lbu         $t1, 0x8($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X8);
    // 0x80800124: bnel        $t1, $zero, L_80800160
    if (ctx->r9 != 0) {
        // 0x80800128: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80800160;
    }
    goto skip_3;
    // 0x80800128: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x8080012C: jal         0x800EA068
    // 0x80800130: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_800EA068(rdram, ctx);
        goto after_3;
    // 0x80800130: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_3:
    // 0x80800134: beq         $v0, $zero, L_8080015C
    if (ctx->r2 == 0) {
        // 0x80800138: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_8080015C;
    }
    // 0x80800138: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8080013C: lb          $t3, 0x0($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X0);
    // 0x80800140: addiu       $a0, $t2, 0x4
    ctx->r4 = ADD32(ctx->r10, 0X4);
    // 0x80800144: addiu       $a1, $t2, 0x28
    ctx->r5 = ADD32(ctx->r10, 0X28);
    // 0x80800148: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8080014C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800150: jal         0x8010D490
    // 0x80800154: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8010D490(rdram, ctx);
        goto after_4;
    // 0x80800154: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x80800158: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_8080015C:
    // 0x8080015C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80800160:
    // 0x80800160: sb          $t4, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r12;
    // 0x80800164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800168:
    // 0x80800168: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080016C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_800EB860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB860: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EB864: addiu       $v0, $v0, 0x2EA0
    ctx->r2 = ADD32(ctx->r2, 0X2EA0);
    // 0x800EB868: sw          $a0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r4;
    // 0x800EB86C: jr          $ra
    // 0x800EB870: sw          $a1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r5;
    return;
    // 0x800EB870: sw          $a1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80804CD0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804CD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804CD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804CD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804CDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804CE0: lui         $a3, 0x4544
    ctx->r7 = S32(0X4544 << 16);
    // 0x80804CE4: ori         $a3, $a3, 0xE000
    ctx->r7 = ctx->r7 | 0XE000;
    // 0x80804CE8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80804CEC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80804CF0: jal         0x800EFA4C
    // 0x80804CF4: lui         $a2, 0xC3FA
    ctx->r6 = S32(0XC3FA << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80804CF4: lui         $a2, 0xC3FA
    ctx->r6 = S32(0XC3FA << 16);
    after_0:
    // 0x80804CF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80804CFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804D00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5390) << 16);
    // 0x80804D04: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x80804D08: lwc1        $f6, 0x5390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5390));
    // 0x80804D0C: jal         0x800EA05C
    // 0x80804D10: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x80804D10: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80804D14: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x80804D18: bnel        $v0, $at, L_80804D34
    if (ctx->r2 != ctx->r1) {
        // 0x80804D1C: lbu         $t9, 0x7A($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X7A);
            goto L_80804D34;
    }
    goto skip_0;
    // 0x80804D1C: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    skip_0:
    // 0x80804D20: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804D24: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80804D28: b           L_80804D3C
    // 0x80804D2C: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
        goto L_80804D3C;
    // 0x80804D2C: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
    // 0x80804D30: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
L_80804D34:
    // 0x80804D34: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x80804D38: sb          $t0, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r8;
L_80804D3C:
    // 0x80804D3C: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804D40: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80804D44: beq         $t1, $zero, L_80804D68
    if (ctx->r9 == 0) {
        // 0x80804D48: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80804D68;
    }
    // 0x80804D48: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80804D4C: jal         0x800DA298
    // 0x80804D50: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80804D50: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    after_2:
    // 0x80804D54: beql        $v0, $zero, L_80804D80
    if (ctx->r2 == 0) {
        // 0x80804D58: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80804D80;
    }
    goto skip_1;
    // 0x80804D58: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    skip_1:
    // 0x80804D5C: lbu         $v0, 0x7A($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804D60: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80804D64: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80804D68:
    // 0x80804D68: bnel        $v0, $zero, L_80804DA0
    if (ctx->r2 != 0) {
        // 0x80804D6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804DA0;
    }
    goto skip_2;
    // 0x80804D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80804D70: jal         0x800DA298
    // 0x80804D74: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80804D74: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_3:
    // 0x80804D78: bne         $v0, $zero, L_80804D9C
    if (ctx->r2 != 0) {
        // 0x80804D7C: addiu       $a0, $zero, 0x377
        ctx->r4 = ADD32(0, 0X377);
            goto L_80804D9C;
    }
    // 0x80804D7C: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
L_80804D80:
    // 0x80804D80: jal         0x80089C30
    // 0x80804D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80804D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80804D88: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80804D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804D90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804D94: jal         0x80103110
    // 0x80804D98: sw          $t3, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r11;
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x80804D98: sw          $t3, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r11;
    after_5:
L_80804D9C:
    // 0x80804D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804DA0:
    // 0x80804DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804DA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804DA8: jr          $ra
    // 0x80804DAC: nop

    return;
    // 0x80804DAC: nop

;}
RECOMP_FUNC void func_800C0984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C098C: jal         0x800A8184
    // 0x800C0990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A8184(rdram, ctx);
        goto after_0;
    // 0x800C0990: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C0994: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C0998: beq         $v0, $at, L_800C09C4
    if (ctx->r2 == ctx->r1) {
        // 0x800C099C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800C09C4;
    }
    // 0x800C099C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C09A0: lw          $t6, -0x5830($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5830);
    // 0x800C09A4: bnel        $t6, $zero, L_800C09B8
    if (ctx->r14 != 0) {
        // 0x800C09A8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800C09B8;
    }
    goto skip_0;
    // 0x800C09A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x800C09AC: jal         0x800C1044
    // 0x800C09B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C1044(rdram, ctx);
        goto after_1;
    // 0x800C09B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800C09B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_800C09B8:
    // 0x800C09B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C09BC: b           L_800C0A1C
    // 0x800C09C0: sw          $t7, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r15;
        goto L_800C0A1C;
    // 0x800C09C0: sw          $t7, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = ctx->r15;
L_800C09C4:
    // 0x800C09C4: jal         0x800A8178
    // 0x800C09C8: nop

    func_800A8178(rdram, ctx);
        goto after_2;
    // 0x800C09C8: nop

    after_2:
    // 0x800C09CC: bne         $v0, $zero, L_800C0A1C
    if (ctx->r2 != 0) {
        // 0x800C09D0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800C0A1C;
    }
    // 0x800C09D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800C09D4: lw          $t8, -0x5830($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5830);
    // 0x800C09D8: beq         $t8, $zero, L_800C09FC
    if (ctx->r24 == 0) {
        // 0x800C09DC: nop
    
            goto L_800C09FC;
    }
    // 0x800C09DC: nop

    // 0x800C09E0: jal         0x800D58CC
    // 0x800C09E4: nop

    func_800D58CC(rdram, ctx);
        goto after_3;
    // 0x800C09E4: nop

    after_3:
    // 0x800C09E8: jal         0x800C0F8C
    // 0x800C09EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C0F8C(rdram, ctx);
        goto after_4;
    // 0x800C09EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x800C09F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C09F4: b           L_800C0A04
    // 0x800C09F8: sw          $zero, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = 0;
        goto L_800C0A04;
    // 0x800C09F8: sw          $zero, -0x5830($at)
    MEM_W(-0X5830, ctx->r1) = 0;
L_800C09FC:
    // 0x800C09FC: jal         0x800C0FD8
    // 0x800C0A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C0FD8(rdram, ctx);
        goto after_5;
    // 0x800C0A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
L_800C0A04:
    // 0x800C0A04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C0A08: lw          $a1, -0x7510($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7510);
    // 0x800C0A0C: beql        $a1, $zero, L_800C0A20
    if (ctx->r5 == 0) {
        // 0x800C0A10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C0A20;
    }
    goto skip_1;
    // 0x800C0A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800C0A14: jal         0x80088210
    // 0x800C0A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _gcnewpause_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x800C0A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
L_800C0A1C:
    // 0x800C0A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C0A20:
    // 0x800C0A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0A24: jr          $ra
    // 0x800C0A28: nop

    return;
    // 0x800C0A28: nop

;}
RECOMP_FUNC void func_8080000C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800014: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: jal         0x80016BDC
    // 0x80800028: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80016BDC(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x8080002C: jal         0x800D395C
    // 0x80800030: nop

    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x80800030: nop

    after_1:
    // 0x80800034: jal         0x80088130
    // 0x80800038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    _gcfrontend_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x8080003C: jal         0x800AA0B8
    // 0x80800040: nop

    func_800AA0B8(rdram, ctx);
        goto after_3;
    // 0x80800040: nop

    after_3:
    // 0x80800044: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800048: nop
    
            goto L_80800070;
    }
    // 0x80800048: nop

    // 0x8080004C: lbu         $t6, 0x79($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X79);
    // 0x80800050: lhu         $t9, 0x6E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6E);
    // 0x80800054: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800058: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x8080005C: ori         $t8, $t7, 0x50
    ctx->r24 = ctx->r15 | 0X50;
    // 0x80800060: ori         $t1, $t0, 0x5
    ctx->r9 = ctx->r8 | 0X5;
    // 0x80800064: sb          $t8, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r24;
    // 0x80800068: b           L_808000C4
    // 0x8080006C: sh          $t1, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r9;
        goto L_808000C4;
    // 0x8080006C: sh          $t1, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r9;
L_80800070:
    // 0x80800070: beql        $s0, $zero, L_808000A8
    if (ctx->r16 == 0) {
        // 0x80800074: lhu         $t0, 0x6E($s2)
        ctx->r8 = MEM_HU(ctx->r18, 0X6E);
            goto L_808000A8;
    }
    goto skip_0;
    // 0x80800074: lhu         $t0, 0x6E($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6E);
    skip_0:
    // 0x80800078: lbu         $t2, 0x79($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X79);
    // 0x8080007C: lhu         $t5, 0x6E($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6E);
    // 0x80800080: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80800084: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800088: ori         $t4, $t3, 0x70
    ctx->r12 = ctx->r11 | 0X70;
    // 0x8080008C: ori         $t7, $t6, 0x7
    ctx->r15 = ctx->r14 | 0X7;
    // 0x80800090: sb          $t4, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r12;
    // 0x80800094: jal         0x800AA00C
    // 0x80800098: sh          $t7, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r15;
    func_800AA00C(rdram, ctx);
        goto after_4;
    // 0x80800098: sh          $t7, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r15;
    after_4:
    // 0x8080009C: b           L_808000C4
    // 0x808000A0: nop

        goto L_808000C4;
    // 0x808000A0: nop

    // 0x808000A4: lhu         $t0, 0x6E($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X6E);
L_808000A8:
    // 0x808000A8: lbu         $t8, 0x79($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X79);
    // 0x808000AC: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x808000B0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x808000B4: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x808000B8: sb          $t9, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r25;
    // 0x808000BC: jal         0x800AA00C
    // 0x808000C0: sh          $t2, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r10;
    func_800AA00C(rdram, ctx);
        goto after_5;
    // 0x808000C0: sh          $t2, 0x6E($s2)
    MEM_H(0X6E, ctx->r18) = ctx->r10;
    after_5:
L_808000C4:
    // 0x808000C4: jal         0x80803638
    // 0x808000C8: nop

    func_80803638_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808000C8: nop

    after_6:
    // 0x808000CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000D0: jal         0x80108B04
    // 0x808000D4: addiu       $a1, $zero, 0x4AB
    ctx->r5 = ADD32(0, 0X4AB);
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x808000D4: addiu       $a1, $zero, 0x4AB
    ctx->r5 = ADD32(0, 0X4AB);
    after_7:
    // 0x808000D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000DC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x808000E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808000E4:
    // 0x808000E4: jal         0x80108B04
    // 0x808000E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_8;
    // 0x808000E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808000EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000F0: bnel        $s0, $s1, L_808000E4
    if (ctx->r16 != ctx->r17) {
        // 0x808000F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000E4;
    }
    goto skip_1;
    // 0x808000F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x808000F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000FC: jal         0x80108B04
    // 0x80800100: addiu       $a1, $zero, 0x4AA
    ctx->r5 = ADD32(0, 0X4AA);
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x80800100: addiu       $a1, $zero, 0x4AA
    ctx->r5 = ADD32(0, 0X4AA);
    after_9:
    // 0x80800104: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800108: jal         0x80108B04
    // 0x8080010C: addiu       $a1, $zero, 0x4A9
    ctx->r5 = ADD32(0, 0X4A9);
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x8080010C: addiu       $a1, $zero, 0x4A9
    ctx->r5 = ADD32(0, 0X4A9);
    after_10:
    // 0x80800110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800114: jal         0x80108B04
    // 0x80800118: addiu       $a1, $zero, 0x4AC
    ctx->r5 = ADD32(0, 0X4AC);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800118: addiu       $a1, $zero, 0x4AC
    ctx->r5 = ADD32(0, 0X4AC);
    after_11:
    // 0x8080011C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800120: jal         0x80108B04
    // 0x80800124: addiu       $a1, $zero, 0x4B9
    ctx->r5 = ADD32(0, 0X4B9);
    func_80108B04(rdram, ctx);
        goto after_12;
    // 0x80800124: addiu       $a1, $zero, 0x4B9
    ctx->r5 = ADD32(0, 0X4B9);
    after_12:
    // 0x80800128: sw          $zero, 0x34($s2)
    MEM_W(0X34, ctx->r18) = 0;
    // 0x8080012C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C40) << 16);
    // 0x80800130: lwc1        $f4, 0x7C40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C40));
    // 0x80800134: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80800138: jal         0x8001ACCC
    // 0x8080013C: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    heap_alloc(rdram, ctx);
        goto after_13;
    // 0x8080013C: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
    after_13:
    // 0x80800140: sw          $v0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r2;
    // 0x80800144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800148: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chcollballcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EA0: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086EA0);
    return;
    // 0x80086EA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sccustom_big_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A918: syscall     856
    recomp_syscall_handler(rdram, ctx, 0x8008A918);
    return;
    // 0x8008A91C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808048A4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808048A4: jr          $ra
    // 0x808048A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808048A8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _basnowball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850E0: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x800850E0);
    return;
    // 0x800850E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008C1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008C1E8: jr          $ra
    // 0x8008C1EC: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008C1EC: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsclaw_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EC8: syscall     33
    recomp_syscall_handler(rdram, ctx, 0x80082EC8);
    return;
    // 0x80082ECC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800DC0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC0C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DC0C4: addiu       $v0, $v0, -0x3810
    ctx->r2 = ADD32(ctx->r2, -0X3810);
    // 0x800DC0C8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800DC0CC: lui         $at, 0x19
    ctx->r1 = S32(0X19 << 16);
    // 0x800DC0D0: ori         $at, $at, 0x660D
    ctx->r1 = ctx->r1 | 0X660D;
    // 0x800DC0D4: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DC0D8: lui         $at, 0x3C6E
    ctx->r1 = S32(0X3C6E << 16);
    // 0x800DC0DC: ori         $at, $at, 0xF35F
    ctx->r1 = ctx->r1 | 0XF35F;
    // 0x800DC0E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800DC0E4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800DC0E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800DC0EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800DC0F0: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800DC0F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800DC0F8: lw          $t9, -0x465C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X465C);
    // 0x800DC0FC: lw          $t2, -0x4660($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4660);
    // 0x800DC100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DC104: and         $t1, $t9, $t8
    ctx->r9 = ctx->r25 & ctx->r24;
    // 0x800DC108: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x800DC10C: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800DC110: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800DC114: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DC118: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800DC11C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC120: jr          $ra
    // 0x800DC124: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800DC124: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void chstadiumdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1652, 0X280) << 16);
    // 0x80800268: jr          $ra
    // 0x8080026C: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1652, 0X280));
    return;
    // 0x8080026C: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1652, 0X280));
;}
RECOMP_FUNC void _chgruntyfireball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867F0: syscall     379
    recomp_syscall_handler(rdram, ctx, 0x800867F0);
    return;
    // 0x800867F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazshoesspringjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: jal         0x800832E0
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: jal         0x80085000
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800164: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080016C: jal         0x80800000
    // 0x80800170: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_80800000_bskazshoesspringjump(rdram, ctx);
        goto after_2;
    // 0x80800170: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_2:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void func_808001A8_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B8: jal         0x8009E77C
    // 0x808001BC: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808001BC: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_0:
    // 0x808001C0: bnel        $v0, $zero, L_8080029C
    if (ctx->r2 != 0) {
        // 0x808001C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080029C;
    }
    goto skip_0;
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C8: jal         0x80085400
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001D8: jal         0x8009BFE4
    // 0x808001DC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x808001DC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_2:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808001E8: jal         0x8009C554
    // 0x808001EC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_3;
    // 0x808001EC: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_3:
    // 0x808001F0: jal         0x8009EFA8
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_4;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001F8: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x808001FC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x8009F1C8
    // 0x80800208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800214: jal         0x8009F1C8
    // 0x80800218: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_6;
    // 0x80800218: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800224: jal         0x800959C8
    // 0x80800228: lui         $a2, 0x4250
    ctx->r6 = S32(0X4250 << 16);
    func_800959C8(rdram, ctx);
        goto after_7;
    // 0x80800228: lui         $a2, 0x4250
    ctx->r6 = S32(0X4250 << 16);
    after_7:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x80095964
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095964(rdram, ctx);
        goto after_8;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800238: jal         0x8009E4AC
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_9;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800248: jal         0x8009E55C
    // 0x8080024C: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8009E55C(rdram, ctx);
        goto after_10;
    // 0x8080024C: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_10:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800258: jal         0x8009E55C
    // 0x8080025C: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    func_8009E55C(rdram, ctx);
        goto after_11;
    // 0x8080025C: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    after_11:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80095760
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_12;
    // 0x80800268: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80095760
    // 0x80800274: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_set(rdram, ctx);
        goto after_13;
    // 0x80800274: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800280: jal         0x800947EC
    // 0x80800284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_14;
    // 0x80800284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x80800288: lui         $a1, 0x3FE6
    ctx->r5 = S32(0X3FE6 << 16);
    // 0x8080028C: ori         $a1, $a1, 0x6600
    ctx->r5 = ctx->r5 | 0X6600;
    // 0x80800290: jal         0x80092864
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_15;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080029C:
    // 0x8080029C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void badata_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EFC: jal         0x8009EA64
    // 0x80800F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA64(rdram, ctx);
        goto after_0;
    // 0x80800F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F04: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x80800F08: beq         $v0, $at, L_80800F3C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F3C;
    }
    // 0x80800F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F10: addiu       $at, $zero, 0x2A2
    ctx->r1 = ADD32(0, 0X2A2);
    // 0x80800F14: beq         $v0, $at, L_80800F44
    if (ctx->r2 == ctx->r1) {
        // 0x80800F18: addiu       $at, $zero, 0x305
        ctx->r1 = ADD32(0, 0X305);
            goto L_80800F44;
    }
    // 0x80800F18: addiu       $at, $zero, 0x305
    ctx->r1 = ADD32(0, 0X305);
    // 0x80800F1C: beq         $v0, $at, L_80800F34
    if (ctx->r2 == ctx->r1) {
        // 0x80800F20: addiu       $at, $zero, 0x38A
        ctx->r1 = ADD32(0, 0X38A);
            goto L_80800F34;
    }
    // 0x80800F20: addiu       $at, $zero, 0x38A
    ctx->r1 = ADD32(0, 0X38A);
    // 0x80800F24: beq         $v0, $at, L_80800F4C
    if (ctx->r2 == ctx->r1) {
        // 0x80800F28: nop
    
            goto L_80800F4C;
    }
    // 0x80800F28: nop

    // 0x80800F2C: b           L_80800F54
    // 0x80800F30: addiu       $v0, $zero, 0xB7
    ctx->r2 = ADD32(0, 0XB7);
        goto L_80800F54;
    // 0x80800F30: addiu       $v0, $zero, 0xB7
    ctx->r2 = ADD32(0, 0XB7);
L_80800F34:
    // 0x80800F34: b           L_80800F54
    // 0x80800F38: addiu       $v0, $zero, 0x12A
    ctx->r2 = ADD32(0, 0X12A);
        goto L_80800F54;
    // 0x80800F38: addiu       $v0, $zero, 0x12A
    ctx->r2 = ADD32(0, 0X12A);
L_80800F3C:
    // 0x80800F3C: b           L_80800F54
    // 0x80800F40: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
        goto L_80800F54;
    // 0x80800F40: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
L_80800F44:
    // 0x80800F44: b           L_80800F54
    // 0x80800F48: addiu       $v0, $zero, 0x12B
    ctx->r2 = ADD32(0, 0X12B);
        goto L_80800F54;
    // 0x80800F48: addiu       $v0, $zero, 0x12B
    ctx->r2 = ADD32(0, 0X12B);
L_80800F4C:
    // 0x80800F4C: b           L_80800F54
    // 0x80800F50: addiu       $v0, $zero, 0xB7
    ctx->r2 = ADD32(0, 0XB7);
        goto L_80800F54;
    // 0x80800F50: addiu       $v0, $zero, 0xB7
    ctx->r2 = ADD32(0, 0XB7);
L_80800F54:
    // 0x80800F54: jr          $ra
    // 0x80800F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8002D694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D69C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002D6A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002D6A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002D6A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002D6AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D6B0: jal         0x8002CC9C
    // 0x8002D6B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8002CC9C(rdram, ctx);
        goto after_0;
    // 0x8002D6B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8002D6B8: b           L_8002D6C8
    // 0x8002D6BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002D6C8;
    // 0x8002D6BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002D6C0: b           L_8002D6C8
    // 0x8002D6C4: nop

        goto L_8002D6C8;
    // 0x8002D6C4: nop

L_8002D6C8:
    // 0x8002D6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D6CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D6D0: jr          $ra
    // 0x8002D6D4: nop

    return;
    // 0x8002D6D4: nop

    // 0x8002D6D8: nop

    // 0x8002D6DC: nop

;}
