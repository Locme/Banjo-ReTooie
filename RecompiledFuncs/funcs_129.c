#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bskazfly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083370: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083370);
    return;
    // 0x80083374: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808009C8_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D0: jal         0x808001E0
    // 0x808009D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808009D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009E0: jal         0x808007A0
    // 0x808009E4: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808007A0_bsmum(rdram, ctx);
        goto after_1;
    // 0x808009E4: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x808009E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009F0: jr          $ra
    // 0x808009F4: nop

    return;
    // 0x808009F4: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080073C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800740: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(332, 0XB40) << 16);
    // 0x80800744: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800748: jr          $ra
    // 0x8080074C: lw          $v0, 0xB40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB40));
    return;
    // 0x8080074C: lw          $v0, 0xB40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB40));
;}
RECOMP_FUNC void _capod_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085710: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085710);
    return;
    // 0x80085714: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_8001E3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E3A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E3A8: jal         0x8001211C
    // 0x8001E3AC: nop

    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x8001E3AC: nop

    after_0:
    // 0x8001E3B0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E3B4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x8001E3B8: lw          $a2, -0x16B8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X16B8);
    // 0x8001E3BC: addiu       $a0, $a0, 0x18A8
    ctx->r4 = ADD32(ctx->r4, 0X18A8);
    // 0x8001E3C0: jal         0x8001D37C
    // 0x8001E3C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E3C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8001E3C8: jal         0x8001E2A0
    // 0x8001E3CC: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E3CC: nop

    after_2:
    // 0x8001E3D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E3D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E3D8: jr          $ra
    // 0x8001E3DC: nop

    return;
    // 0x8001E3DC: nop

;}
RECOMP_FUNC void func_808000C0_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x808000D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000D4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808000D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808000DC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808000E0: jal         0x800CE8D8
    // 0x808000E4: nop

    func_800CE8D8(rdram, ctx);
        goto after_0;
    // 0x808000E4: nop

    after_0:
    // 0x808000E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808000EC: jal         0x800CE88C
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_1;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_8009EA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EA30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EA34: jal         0x800DA298
    // 0x8009EA38: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8009EA38: addiu       $a0, $zero, 0x3EC
    ctx->r4 = ADD32(0, 0X3EC);
    after_0:
    // 0x8009EA3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EA40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EA44: jr          $ra
    // 0x8009EA48: nop

    return;
    // 0x8009EA48: nop

;}
RECOMP_FUNC void _bskazshock_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083588: syscall     66
    recomp_syscall_handler(rdram, ctx, 0x80083588);
    return;
    // 0x8008358C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800864_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80800868: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080086C: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80800870: beq         $t6, $zero, L_80800880
    if (ctx->r14 == 0) {
        // 0x80800874: nop
    
            goto L_80800880;
    }
    // 0x80800874: nop

    // 0x80800878: jr          $ra
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800880:
    // 0x80800880: jr          $ra
    // 0x80800884: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800884: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800864_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080086C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800870: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800874: jal         0x8008CABC
    // 0x80800878: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800878: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x8080087C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800880: jal         0x80800694
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsbabykaz_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080088C: jal         0x80095738
    // 0x80800890: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800890: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x80800894: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x80800898: nop
    
            goto L_808008AC;
    }
    // 0x80800898: nop

    // 0x8080089C: jal         0x8009B7C0
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008A4: b           L_808008B8
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008B8;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008AC:
    // 0x808008AC: jal         0x80800134
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800134_bsbabykaz(rdram, ctx);
        goto after_4;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008B8:
    // 0x808008B8: jal         0x8009BB24
    // 0x808008BC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x808008BC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x808008C0: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808008C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: beq         $v0, $zero, L_808008E4
    if (ctx->r2 == 0) {
        // 0x808008D0: nop
    
            goto L_808008E4;
    }
    // 0x808008D0: nop

    // 0x808008D4: beq         $v0, $at, L_80800940
    if (ctx->r2 == ctx->r1) {
        // 0x808008D8: nop
    
            goto L_80800940;
    }
    // 0x808008D8: nop

    // 0x808008DC: b           L_80800940
    // 0x808008E0: nop

        goto L_80800940;
    // 0x808008E0: nop

L_808008E4:
    // 0x808008E4: jal         0x8008DF8C
    // 0x808008E8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x808008E8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_6:
    // 0x808008EC: beq         $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x808008F0: nop
    
            goto L_80800940;
    }
    // 0x808008F0: nop

    // 0x808008F4: jal         0x8008AF24
    // 0x808008F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_reset(rdram, ctx);
        goto after_7;
    // 0x808008F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x808008FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800900: jal         0x8008AED4
    // 0x80800904: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x80800904: addiu       $a1, $zero, 0xA9
    ctx->r5 = ADD32(0, 0XA9);
    after_8:
    // 0x80800908: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x8080090C: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x80800910: jal         0x8008B24C
    // 0x80800914: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setStart(rdram, ctx);
        goto after_9;
    // 0x80800914: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80800918: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080091C: jal         0x8008B1BC
    // 0x80800920: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x80800920: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_10:
    // 0x80800924: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800928: jal         0x8008B134
    // 0x8080092C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_11;
    // 0x8080092C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800930: jal         0x8008B064
    // 0x80800934: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x80800934: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x80800938: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080093C: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800940:
    // 0x80800940: jal         0x8008E078
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_13;
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800948: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x8080094C: nop
    
            goto L_8080097C;
    }
    // 0x8080094C: nop

    // 0x80800950: jal         0x8009FE58
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_14;
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800958: jal         0x8008B284
    // 0x8080095C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_getPlaybackType(rdram, ctx);
        goto after_15;
    // 0x8080095C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_15:
    // 0x80800960: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800964: bne         $v0, $at, L_80800978
    if (ctx->r2 != ctx->r1) {
        // 0x80800968: addiu       $t8, $zero, 0x136
        ctx->r24 = ADD32(0, 0X136);
            goto L_80800978;
    }
    // 0x80800968: addiu       $t8, $zero, 0x136
    ctx->r24 = ADD32(0, 0X136);
    // 0x8080096C: addiu       $t7, $zero, 0x132
    ctx->r15 = ADD32(0, 0X132);
    // 0x80800970: b           L_8080097C
    // 0x80800974: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_8080097C;
    // 0x80800974: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800978:
    // 0x80800978: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8080097C:
    // 0x8080097C: jal         0x808000F8
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F8_bsbabykaz(rdram, ctx);
        goto after_16;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800984: beq         $v0, $zero, L_80800994
    if (ctx->r2 == 0) {
        // 0x80800988: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800994;
    }
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080098C: addiu       $t9, $zero, 0x94
    ctx->r25 = ADD32(0, 0X94);
    // 0x80800990: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800994:
    // 0x80800994: jal         0x8009E5C8
    // 0x80800998: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80800998: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x8080099C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009A8: jr          $ra
    // 0x808009AC: nop

    return;
    // 0x808009AC: nop

;}
RECOMP_FUNC void func_800E2260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2260: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E2264: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E2268: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800E226C: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x800E2270: beql        $v0, $t6, L_800E2284
    if (ctx->r2 == ctx->r14) {
        // 0x800E2274: lh          $v0, 0x2($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X2);
            goto L_800E2284;
    }
    goto skip_0;
    // 0x800E2274: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x800E2278: bnel        $v0, $zero, L_800E22CC
    if (ctx->r2 != 0) {
        // 0x800E227C: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_800E22CC;
    }
    goto skip_1;
    // 0x800E227C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x800E2280: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
L_800E2284:
    // 0x800E2284: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x800E2288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E228C: beql        $v0, $t7, L_800E22A0
    if (ctx->r2 == ctx->r15) {
        // 0x800E2290: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800E22A0;
    }
    goto skip_2;
    // 0x800E2290: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x800E2294: bnel        $v0, $zero, L_800E22CC
    if (ctx->r2 != 0) {
        // 0x800E2298: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_800E22CC;
    }
    goto skip_3;
    // 0x800E2298: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x800E229C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800E22A0:
    // 0x800E22A0: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800E22A4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800E22A8: nop

    // 0x800E22AC: bc1fl       L_800E22CC
    if (!c1cs) {
        // 0x800E22B0: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_800E22CC;
    }
    goto skip_4;
    // 0x800E22B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_4:
    // 0x800E22B4: lwc1        $f6, 0x30($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800E22B8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800E22BC: nop

    // 0x800E22C0: bc1t        L_800E22E8
    if (c1cs) {
        // 0x800E22C4: nop
    
            goto L_800E22E8;
    }
    // 0x800E22C4: nop

    // 0x800E22C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_800E22CC:
    // 0x800E22CC: lui         $t9, 0xD838
    ctx->r25 = S32(0XD838 << 16);
    // 0x800E22D0: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800E22D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800E22D8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800E22DC: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x800E22E0: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800E22E4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800E22E8:
    // 0x800E22E8: jr          $ra
    // 0x800E22EC: nop

    return;
    // 0x800E22EC: nop

;}
RECOMP_FUNC void func_80800AA0_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800AA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800AB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AB4: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800AB8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X152C) << 16);
    // 0x80800ABC: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800AC0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800AC4: addiu       $a2, $a2, 0x152C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X152C));
    // 0x80800AC8: jal         0x80089D20
    // 0x80800ACC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800ACC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80800AD0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X153C) << 16);
    // 0x80800AD4: lui         $a3, 0x3E38
    ctx->r7 = S32(0X3E38 << 16);
    // 0x80800AD8: ori         $a3, $a3, 0x51EC
    ctx->r7 = ctx->r7 | 0X51EC;
    // 0x80800ADC: addiu       $a2, $a2, 0x153C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X153C));
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE4: jal         0x80089D20
    // 0x80800AE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800AE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800AEC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X154C) << 16);
    // 0x80800AF0: lui         $a3, 0x3F3A
    ctx->r7 = S32(0X3F3A << 16);
    // 0x80800AF4: ori         $a3, $a3, 0xE148
    ctx->r7 = ctx->r7 | 0XE148;
    // 0x80800AF8: addiu       $a2, $a2, 0x154C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X154C));
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: jal         0x80089D20
    // 0x80800B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800B04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800B08: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X155C) << 16);
    // 0x80800B0C: lui         $a3, 0x3F45
    ctx->r7 = S32(0X3F45 << 16);
    // 0x80800B10: ori         $a3, $a3, 0x1EB8
    ctx->r7 = ctx->r7 | 0X1EB8;
    // 0x80800B14: addiu       $a2, $a2, 0x155C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X155C));
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: jal         0x80089D20
    // 0x80800B20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800B20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B28: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B2C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B30: jr          $ra
    // 0x80800B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800B34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800AD4_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ADC: jal         0x80085840
    // 0x80800AE0: addiu       $a1, $zero, 0x4FB
    ctx->r5 = ADD32(0, 0X4FB);
    _chswitch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800AE0: addiu       $a1, $zero, 0x4FB
    ctx->r5 = ADD32(0, 0X4FB);
    after_0:
    // 0x80800AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AEC: jr          $ra
    // 0x80800AF0: nop

    return;
    // 0x80800AF0: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DC4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1770) << 16);
    // 0x80800DC8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DCC: jr          $ra
    // 0x80800DD0: lw          $v0, 0x1770($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1770));
    return;
    // 0x80800DD0: lw          $v0, 0x1770($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1770));
;}
RECOMP_FUNC void func_808025EC_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808025F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808025F4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808025F8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808025FC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802600: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802604: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80802608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080260C: jal         0x80100094
    // 0x80802610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802614: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1332, 0X3054) << 16);
    // 0x80802618: addiu       $s0, $s0, 0x3054
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1332, 0X3054));
    // 0x8080261C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80802620: addiu       $s2, $v0, 0x3C
    ctx->r18 = ADD32(ctx->r2, 0X3C);
    // 0x80802624: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80802628: addiu       $s3, $zero, 0x48
    ctx->r19 = ADD32(0, 0X48);
L_8080262C:
    // 0x8080262C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80802630: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80802634: jal         0x8008A0E0
    // 0x80802638: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802638: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8080263C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80802640: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80802644: bne         $s1, $s3, L_8080262C
    if (ctx->r17 != ctx->r19) {
        // 0x80802648: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8080262C;
    }
    // 0x80802648: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x8080264C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80802650: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80802654: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80802658: jal         0x8008A0E0
    // 0x8080265C: addiu       $a2, $a2, 0x84
    ctx->r6 = ADD32(ctx->r6, 0X84);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080265C: addiu       $a2, $a2, 0x84
    ctx->r6 = ADD32(ctx->r6, 0X84);
    after_2:
    // 0x80802660: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802668: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080266C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802670: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80802674: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802678: jr          $ra
    // 0x8080267C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080267C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bsmumswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083900: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x80083900);
    return;
    // 0x80083904: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void baduo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800B6C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B74: jal         0x80100094
    // 0x80800B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B80: lw          $v0, 0xCC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XCC);
    // 0x80800B84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B88: jr          $ra
    // 0x80800B8C: nop

    return;
    // 0x80800B8C: nop

;}
RECOMP_FUNC void func_800B5548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5548: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B554C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5550: beq         $a0, $zero, L_800B5618
    if (ctx->r4 == 0) {
        // 0x800B5554: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800B5618;
    }
    // 0x800B5554: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B5558: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800B555C: lw          $a2, 0x7F10($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7F10);
    // 0x800B5560: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B5564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B5568: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B556C: beq         $a0, $t6, L_800B55A4
    if (ctx->r4 == ctx->r14) {
        // 0x800B5570: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800B55A4;
    }
    // 0x800B5570: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B5574: lh          $a0, 0x7F18($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7F18);
    // 0x800B5578: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x800B557C: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x800B5580: blezl       $a0, L_800B55A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800B5584: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800B55A8;
    }
    goto skip_0;
    // 0x800B5584: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x800B5588: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
L_800B558C:
    // 0x800B558C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B5590: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800B5594: beq         $a1, $t8, L_800B55A4
    if (ctx->r5 == ctx->r24) {
        // 0x800B5598: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B55A4;
    }
    // 0x800B5598: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B559C: bnel        $at, $zero, L_800B558C
    if (ctx->r1 != 0) {
        // 0x800B55A0: lw          $t8, 0x4($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X4);
            goto L_800B558C;
    }
    goto skip_1;
    // 0x800B55A0: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    skip_1:
L_800B55A4:
    // 0x800B55A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800B55A8:
    // 0x800B55A8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800B55AC: jal         0x8001BAFC
    // 0x800B55B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800B55B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B55B4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800B55B8: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x800B55BC: lw          $t2, 0x90($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X90);
    // 0x800B55C0: lw          $t5, 0x94($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X94);
    // 0x800B55C4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800B55C8: subu        $t0, $t9, $a3
    ctx->r8 = SUB32(ctx->r25, ctx->r7);
    // 0x800B55CC: subu        $t3, $t2, $a3
    ctx->r11 = SUB32(ctx->r10, ctx->r7);
    // 0x800B55D0: subu        $t6, $t5, $a3
    ctx->r14 = SUB32(ctx->r13, ctx->r7);
    // 0x800B55D4: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800B55D8: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x800B55DC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B55E0: sw          $t1, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r9;
    // 0x800B55E4: sw          $t4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r12;
    // 0x800B55E8: sw          $t7, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r15;
    // 0x800B55EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800B55F0: lh          $t8, 0x7F18($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X7F18);
    // 0x800B55F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B55F8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800B55FC: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B5600: beql        $at, $zero, L_800B561C
    if (ctx->r1 == 0) {
        // 0x800B5604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B561C;
    }
    goto skip_2;
    // 0x800B5604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800B5608: lw          $t9, 0x7F10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7F10);
    // 0x800B560C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B5610: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B5614: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_800B5618:
    // 0x800B5618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B561C:
    // 0x800B561C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B5620: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800B5624: jr          $ra
    // 0x800B5628: nop

    return;
    // 0x800B5628: nop

;}
RECOMP_FUNC void chfactoryflypad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1288, 0X298) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1288, 0X298));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x298
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1288, 0X298));
;}
RECOMP_FUNC void func_800A3404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3404: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3408: jr          $ra
    // 0x800A340C: lbu         $v0, 0x3F($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3F);
    return;
    // 0x800A340C: lbu         $v0, 0x3F($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3F);
;}
RECOMP_FUNC void dbtex_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: beq         $a0, $zero, L_808000F0
    if (ctx->r4 == 0) {
        // 0x808000E4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808000F0;
    }
    // 0x808000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E8: jal         0x8001B084
    // 0x808000EC: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x808000EC: nop

    after_0:
L_808000F0:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084320: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084320);
    return;
    // 0x80084324: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085618: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085618);
    return;
    // 0x8008561C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80801494_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801498: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x8080149C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014A0: beq         $a1, $at, L_808014C4
    if (ctx->r5 == ctx->r1) {
        // 0x808014A4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808014C4;
    }
    // 0x808014A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808014A8: addiu       $at, $zero, 0x10CD
    ctx->r1 = ADD32(0, 0X10CD);
    // 0x808014AC: beq         $a1, $at, L_808014D4
    if (ctx->r5 == ctx->r1) {
        // 0x808014B0: addiu       $at, $zero, 0x10CE
        ctx->r1 = ADD32(0, 0X10CE);
            goto L_808014D4;
    }
    // 0x808014B0: addiu       $at, $zero, 0x10CE
    ctx->r1 = ADD32(0, 0X10CE);
    // 0x808014B4: beq         $a1, $at, L_808014D4
    if (ctx->r5 == ctx->r1) {
        // 0x808014B8: nop
    
            goto L_808014D4;
    }
    // 0x808014B8: nop

    // 0x808014BC: b           L_808014F4
    // 0x808014C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808014F4;
    // 0x808014C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014C4:
    // 0x808014C4: jal         0x808006A0
    // 0x808014C8: nop

    func_808006A0_chhoopswoop(rdram, ctx);
        goto after_0;
    // 0x808014C8: nop

    after_0:
    // 0x808014CC: b           L_808014F4
    // 0x808014D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808014F4;
    // 0x808014D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014D4:
    // 0x808014D4: jal         0x8008A098
    // 0x808014D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808014D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808014DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808014E0: jal         0x80101FDC
    // 0x808014E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808014E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808014E8: jal         0x80088180
    // 0x808014EC: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808014EC: nop

    after_3:
    // 0x808014F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014F4:
    // 0x808014F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014F8: jr          $ra
    // 0x808014FC: nop

    return;
    // 0x808014FC: nop

;}
RECOMP_FUNC void func_80103328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103328: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010332C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103330: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103334: lhu         $t6, 0x68($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X68);
    // 0x80103338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010333C: bnel        $t6, $zero, L_8010346C
    if (ctx->r14 != 0) {
        // 0x80103340: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010346C;
    }
    goto skip_0;
    // 0x80103340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80103344: jal         0x80103964
    // 0x80103348: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80103964(rdram, ctx);
        goto after_0;
    // 0x80103348: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8010334C: beql        $v0, $zero, L_8010346C
    if (ctx->r2 == 0) {
        // 0x80103350: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010346C;
    }
    goto skip_1;
    // 0x80103350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80103354: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80103358: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    // 0x8010335C: jal         0x800D62E4
    // 0x80103360: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D62E4(rdram, ctx);
        goto after_1;
    // 0x80103360: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80103364: jal         0x800B2840
    // 0x80103368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x80103368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8010336C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80103370: lhu         $t8, 0x12($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X12);
    // 0x80103374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103378: sh          $t8, 0x68($s0)
    MEM_H(0X68, ctx->r16) = ctx->r24;
    // 0x8010337C: lhu         $t9, 0x14($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14);
    // 0x80103380: jal         0x800B2248
    // 0x80103384: sh          $t9, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = ctx->r25;
    func_800B2248(rdram, ctx);
        goto after_3;
    // 0x80103384: sh          $t9, 0x6A($s0)
    MEM_H(0X6A, ctx->r16) = ctx->r25;
    after_3:
    // 0x80103388: sh          $v0, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r2;
    // 0x8010338C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80103390: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80103394: jal         0x800B2198
    // 0x80103398: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800B2198(rdram, ctx);
        goto after_4;
    // 0x80103398: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x8010339C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x801033A0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801033A4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x801033A8: sh          $t0, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r8;
    // 0x801033AC: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x801033B0: sh          $t1, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r9;
    // 0x801033B4: jal         0x800B237C
    // 0x801033B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800B237C(rdram, ctx);
        goto after_5;
    // 0x801033B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x801033BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801033C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801033C4: jal         0x800EE940
    // 0x801033C8: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    func_800EE940(rdram, ctx);
        goto after_6;
    // 0x801033C8: addiu       $a0, $a0, 0x1E
    ctx->r4 = ADD32(ctx->r4, 0X1E);
    after_6:
    // 0x801033CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801033D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801033D4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801033D8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801033DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801033E0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801033E4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801033E8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801033EC: nop

    // 0x801033F0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801033F4: beql        $t3, $zero, L_80103444
    if (ctx->r11 == 0) {
        // 0x801033F8: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_80103444;
    }
    goto skip_2;
    // 0x801033F8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x801033FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80103400: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80103404: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80103408: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8010340C: nop

    // 0x80103410: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80103414: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80103418: nop

    // 0x8010341C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80103420: bne         $t3, $zero, L_80103438
    if (ctx->r11 != 0) {
        // 0x80103424: nop
    
            goto L_80103438;
    }
    // 0x80103424: nop

    // 0x80103428: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8010342C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80103430: b           L_80103450
    // 0x80103434: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80103450;
    // 0x80103434: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80103438:
    // 0x80103438: b           L_80103450
    // 0x8010343C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80103450;
    // 0x8010343C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80103440: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_80103444:
    // 0x80103444: nop

    // 0x80103448: bltz        $t3, L_80103438
    if (SIGNED(ctx->r11) < 0) {
        // 0x8010344C: nop
    
            goto L_80103438;
    }
    // 0x8010344C: nop

L_80103450:
    // 0x80103450: lhu         $t7, 0x18($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X18);
    // 0x80103454: sll         $t6, $t3, 5
    ctx->r14 = S32(ctx->r11 << 5);
    // 0x80103458: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8010345C: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x80103460: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80103464: sh          $t9, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r25;
    // 0x80103468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010346C:
    // 0x8010346C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103470: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80103474: jr          $ra
    // 0x80103478: nop

    return;
    // 0x80103478: nop

;}
RECOMP_FUNC void func_800F608C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F608C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6090: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F6094: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x800F6098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F609C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800F60A0: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x800F60A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F60A8: beq         $at, $zero, L_800F6130
    if (ctx->r1 == 0) {
        // 0x800F60AC: lw          $a2, 0x5490($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X5490);
            goto L_800F6130;
    }
    // 0x800F60AC: lw          $a2, 0x5490($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5490);
    // 0x800F60B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F60B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F60B8: addu        $at, $at, $t7
    gpr jr_addend_800F60C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800F60BC: lw          $t7, 0x6070($at)
    ctx->r15 = ADD32(ctx->r1, 0X6070);
    // 0x800F60C0: jr          $t7
    // 0x800F60C4: nop

    switch (jr_addend_800F60C0 >> 2) {
        case 0: goto L_800F60C8; break;
        case 1: goto L_800F60E8; break;
        case 2: goto L_800F60FC; break;
        case 3: goto L_800F6110; break;
        case 4: goto L_800F6124; break;
        default: switch_error(__func__, 0x800F60C0, 0x80126070);
    }
    // 0x800F60C4: nop

L_800F60C8:
    // 0x800F60C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F60CC: jal         0x80084758
    // 0x800F60D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    _badata_entrypoint_35(rdram, ctx);
        goto after_0;
    // 0x800F60D0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F60D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F60D8: jal         0x8009E5C8
    // 0x800F60DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x800F60DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F60E0: b           L_800F6134
    // 0x800F60E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F6134;
    // 0x800F60E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F60E8:
    // 0x800F60E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F60EC: jal         0x800F604C
    // 0x800F60F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800F604C(rdram, ctx);
        goto after_2;
    // 0x800F60F0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x800F60F4: b           L_800F6134
    // 0x800F60F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F6134;
    // 0x800F60F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F60FC:
    // 0x800F60FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F6100: jal         0x800F604C
    // 0x800F6104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F604C(rdram, ctx);
        goto after_3;
    // 0x800F6104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x800F6108: b           L_800F6134
    // 0x800F610C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F6134;
    // 0x800F610C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F6110:
    // 0x800F6110: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F6114: jal         0x800F604C
    // 0x800F6118: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F604C(rdram, ctx);
        goto after_4;
    // 0x800F6118: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x800F611C: b           L_800F6134
    // 0x800F6120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F6134;
    // 0x800F6120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F6124:
    // 0x800F6124: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F6128: jal         0x800F604C
    // 0x800F612C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800F604C(rdram, ctx);
        goto after_5;
    // 0x800F612C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
L_800F6130:
    // 0x800F6130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F6134:
    // 0x800F6134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F6138: jr          $ra
    // 0x800F613C: nop

    return;
    // 0x800F613C: nop

;}
RECOMP_FUNC void _chmolehill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086920: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086920);
    return;
    // 0x80086924: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086500: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x80086500);
    return;
    // 0x80086504: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsledge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A8C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A90: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X1368) << 16);
    // 0x80800A94: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A98: jr          $ra
    // 0x80800A9C: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1368));
    return;
    // 0x80800A9C: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1368));
;}
RECOMP_FUNC void func_80800024_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x80106790
    // 0x80800034: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800034: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800038: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080003C: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80800040: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800044: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800048: nop

    // 0x8080004C: bc1tl       L_808000AC
    if (c1cs) {
        // 0x80800050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800054: jal         0x8008FCC8
    // 0x80800058: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8008FCC8(rdram, ctx);
        goto after_1;
    // 0x80800058: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080005C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800060: bne         $v0, $at, L_808000A8
    if (ctx->r2 != ctx->r1) {
        // 0x80800064: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A8;
    }
    // 0x80800064: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800068: lw          $t6, 0x64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X64);
    // 0x8080006C: lbu         $t3, 0x65($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X65);
    // 0x80800070: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800074: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800078: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8080007C: xori        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 ^ 0X1;
    // 0x80800080: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800084: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800088: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8080008C: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80800090: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800094: sb          $t5, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r13;
    // 0x80800098: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A0: jal         0x80103110
    // 0x808000A4: swc1        $f8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f8.u32l;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x808000A4: swc1        $f8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f8.u32l;
    after_2:
L_808000A8:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void chboilerid_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808009B0: jal         0x80100094
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009B8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808009BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009C4: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x808009C8: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808009CC: beq         $t7, $at, L_80800AD0
    if (ctx->r15 == ctx->r1) {
        // 0x808009D0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800AD0;
    }
    // 0x808009D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009D4: beql        $t7, $at, L_80800AD4
    if (ctx->r15 == ctx->r1) {
        // 0x808009D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AD4;
    }
    goto skip_0;
    // 0x808009D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808009DC: jal         0x80800CB0
    // 0x808009E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800CB0_chboilerid(rdram, ctx);
        goto after_1;
    // 0x808009E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808009E4: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x808009E8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x808009EC: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x808009F0: addiu       $t9, $t9, 0xD00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x808009F4: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808009F8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x808009FC: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x80800A00: lh          $t1, 0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X2);
    // 0x80800A04: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800A08: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800A0C: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A18: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800A1C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800A20: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800A24: jal         0x80088FB8
    // 0x80800A28: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800A28: nop

    after_2:
    // 0x80800A2C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800A30: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1084, 0XD00) << 16);
    // 0x80800A34: addiu       $t4, $t4, 0xD00
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1084, 0XD00));
    // 0x80800A38: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80800A3C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80800A40: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x80800A44: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80800A48: lh          $t5, 0x8($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8);
    // 0x80800A4C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80800A50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800A54: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800A58: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800A5C: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x80800A60: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A64: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A68: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A6C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800A70: jal         0x80088FB8
    // 0x80800A74: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800A74: nop

    after_3:
    // 0x80800A78: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800A7C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80800A80: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x80800A84: lh          $t8, 0x12($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X12);
    // 0x80800A88: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800A8C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800A90: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800A94: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800A98: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800A9C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800AA0: jal         0x80088FB8
    // 0x80800AA4: nop

    _mlwave_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800AA4: nop

    after_4:
    // 0x80800AA8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800AAC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800AB0: lh          $t9, 0x1A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1A);
    // 0x80800AB4: sh          $t9, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r25;
    // 0x80800AB8: lh          $t0, 0x18($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X18);
    // 0x80800ABC: sh          $t0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r8;
    // 0x80800AC0: lh          $t1, 0x1C($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1C);
    // 0x80800AC4: sh          $t1, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r9;
    // 0x80800AC8: jal         0x80101FDC
    // 0x80800ACC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800ACC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
L_80800AD0:
    // 0x80800AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AD4:
    // 0x80800AD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800ADC: jr          $ra
    // 0x80800AE0: nop

    return;
    // 0x80800AE0: nop

;}
RECOMP_FUNC void _gcsectionDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088260: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088260);
    return;
    // 0x80088264: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EE55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE55C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EE560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EE564: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EE568: lw          $t6, 0x2C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X2C);
    // 0x800EE56C: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x800EE570: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800EE574: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x800EE578: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800EE57C: jal         0x8001BAFC
    // 0x800EE580: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    defrag(rdram, ctx);
        goto after_0;
    // 0x800EE580: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x800EE584: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800EE588: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
    // 0x800EE58C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE590: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800EE594: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800EE598: sw          $t1, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r9;
    // 0x800EE59C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EE5A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EE5A4: jr          $ra
    // 0x800EE5A8: nop

    return;
    // 0x800EE5A8: nop

;}
RECOMP_FUNC void func_80800398_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800398: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080039C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808003A4: jal         0x80100094
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003AC: addiu       $a0, $v0, 0x4C
    ctx->r4 = ADD32(ctx->r2, 0X4C);
    // 0x808003B0: addiu       $a1, $v0, 0x58
    ctx->r5 = ADD32(ctx->r2, 0X58);
    // 0x808003B4: jal         0x800F1828
    // 0x808003B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800F1828(rdram, ctx);
        goto after_1;
    // 0x808003B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003BC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808003C0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808003C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003C8: addiu       $a3, $v1, 0x4C
    ctx->r7 = ADD32(ctx->r3, 0X4C);
    // 0x808003CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003D0: sub.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x808003D4: addiu       $a1, $v1, 0x58
    ctx->r5 = ADD32(ctx->r3, 0X58);
    // 0x808003D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808003DC: jal         0x800F1DF4
    // 0x808003E0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x808003E0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x808003E4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003EC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808003F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808003F8: jal         0x808013E8
    // 0x808003FC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    func_808013E8_chchuffy(rdram, ctx);
        goto after_3;
    // 0x808003FC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void _idtwinklea_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EA0: syscall     746
    recomp_syscall_handler(rdram, ctx, 0x80088EA0);
    return;
    // 0x80088EA4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void inflate_dynamic_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C500: sw          $ra, 0xA44($sp)
    MEM_W(0XA44, ctx->r29) = ctx->r31;
    // 0x8001C504: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8001C508: addiu       $t5, $t5, 0x17EC
    ctx->r13 = ADD32(ctx->r13, 0X17EC);
    // 0x8001C50C: slti        $at, $fp, 0xE
    ctx->r1 = SIGNED(ctx->r30) < 0XE ? 1 : 0;
    // 0x8001C510: beq         $at, $zero, L_8001C538
    if (ctx->r1 == 0) {
        // 0x8001C514: nop
    
            goto L_8001C538;
    }
    // 0x8001C514: nop

    // 0x8001C518: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C51C:
    // 0x8001C51C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C520: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C524: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C528: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C52C: slti        $at, $fp, 0xE
    ctx->r1 = SIGNED(ctx->r30) < 0XE ? 1 : 0;
    // 0x8001C530: bnel        $at, $zero, L_8001C51C
    if (ctx->r1 != 0) {
        // 0x8001C534: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C51C;
    }
    goto skip_0;
    // 0x8001C534: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_8001C538:
    // 0x8001C538: andi        $t2, $gp, 0x1F
    ctx->r10 = ctx->r28 & 0X1F;
    // 0x8001C53C: addiu       $t2, $t2, 0x101
    ctx->r10 = ADD32(ctx->r10, 0X101);
    // 0x8001C540: andi        $t3, $gp, 0x3E0
    ctx->r11 = ctx->r28 & 0X3E0;
    // 0x8001C544: srl         $t3, $t3, 5
    ctx->r11 = S32(U32(ctx->r11) >> 5);
    // 0x8001C548: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8001C54C: andi        $t1, $gp, 0x3C00
    ctx->r9 = ctx->r28 & 0X3C00;
    // 0x8001C550: srl         $t1, $t1, 10
    ctx->r9 = S32(U32(ctx->r9) >> 10);
    // 0x8001C554: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8001C558: srl         $gp, $gp, 14
    ctx->r28 = S32(U32(ctx->r28) >> 14);
    // 0x8001C55C: addiu       $fp, $fp, -0xE
    ctx->r30 = ADD32(ctx->r30, -0XE);
    // 0x8001C560: slti        $at, $t2, 0x11F
    ctx->r1 = SIGNED(ctx->r10) < 0X11F ? 1 : 0;
    // 0x8001C564: beq         $at, $zero, L_8001C8F4
    if (ctx->r1 == 0) {
        // 0x8001C568: slti        $at, $t3, 0x1F
        ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
            goto L_8001C8F4;
    }
    // 0x8001C568: slti        $at, $t3, 0x1F
    ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
    // 0x8001C56C: beq         $at, $zero, L_8001C8F4
    if (ctx->r1 == 0) {
        // 0x8001C570: addiu       $s1, $zero, 0x0
        ctx->r17 = ADD32(0, 0X0);
            goto L_8001C8F4;
    }
    // 0x8001C570: addiu       $s1, $zero, 0x0
    ctx->r17 = ADD32(0, 0X0);
L_8001C574:
    // 0x8001C574: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C578: beq         $at, $zero, L_8001C5A0
    if (ctx->r1 == 0) {
        // 0x8001C57C: nop
    
            goto L_8001C5A0;
    }
    // 0x8001C57C: nop

    // 0x8001C580: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C584:
    // 0x8001C584: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C588: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C58C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C590: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C594: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C598: bnel        $at, $zero, L_8001C584
    if (ctx->r1 != 0) {
        // 0x8001C59C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C584;
    }
    goto skip_1;
    // 0x8001C59C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_8001C5A0:
    // 0x8001C5A0: addu        $t8, $t5, $s1
    ctx->r24 = ADD32(ctx->r13, ctx->r17);
    // 0x8001C5A4: lbu         $t8, 0x0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X0);
    // 0x8001C5A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001C5AC: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
    // 0x8001C5B0: andi        $at, $gp, 0x7
    ctx->r1 = ctx->r28 & 0X7;
    // 0x8001C5B4: sw          $at, 0x548($t8)
    MEM_W(0X548, ctx->r24) = ctx->r1;
    // 0x8001C5B8: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x8001C5BC: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x8001C5C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001C5C4: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C5C8: bne         $at, $zero, L_8001C574
    if (ctx->r1 != 0) {
        // 0x8001C5CC: slti        $at, $s1, 0x13
        ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
            goto L_8001C574;
    }
    // 0x8001C5CC: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x8001C5D0: beq         $at, $zero, L_8001C5F4
    if (ctx->r1 == 0) {
        // 0x8001C5D4: addu        $t8, $t5, $s1
        ctx->r24 = ADD32(ctx->r13, ctx->r17);
            goto L_8001C5F4;
    }
L_8001C5D4:
    // 0x8001C5D4: addu        $t8, $t5, $s1
    ctx->r24 = ADD32(ctx->r13, ctx->r17);
    // 0x8001C5D8: lbu         $t8, 0x0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X0);
    // 0x8001C5DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001C5E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001C5E4: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
    // 0x8001C5E8: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x8001C5EC: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x8001C5F0: bne         $at, $zero, L_8001C5D4
    if (ctx->r1 != 0) {
        // 0x8001C5F4: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_8001C5D4;
    }
L_8001C5F4:
    // 0x8001C5F4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8001C5F8: sw          $t8, 0xA3C($sp)
    MEM_W(0XA3C, ctx->r29) = ctx->r24;
    // 0x8001C5FC: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x8001C600: mtc1        $t3, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r11;
    // 0x8001C604: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x8001C608: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x8001C60C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8001C610: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8001C614: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8001C618: addiu       $t8, $sp, 0xA38
    ctx->r24 = ADD32(ctx->r29, 0XA38);
    // 0x8001C61C: jal         0x8001CA6C
    // 0x8001C620: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    huft_build_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C620: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    after_0:
    // 0x8001C624: mfc1        $t2, $f0
    ctx->r10 = (int32_t)ctx->f0.u32l;
    // 0x8001C628: mfc1        $t3, $f1
    ctx->r11 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x8001C62C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001C630: addiu       $t6, $t6, 0x1750
    ctx->r14 = ADD32(ctx->r14, 0X1750);
    // 0x8001C634: lhu         $s5, 0xA38($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0XA38);
    // 0x8001C638: lw          $t0, 0xA3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA3C);
    // 0x8001C63C: addu        $s4, $t2, $t3
    ctx->r20 = ADD32(ctx->r10, ctx->r11);
    // 0x8001C640: sll         $s3, $t0, 1
    ctx->r19 = S32(ctx->r8 << 1);
    // 0x8001C644: addu        $s3, $s3, $t6
    ctx->r19 = ADD32(ctx->r19, ctx->r14);
    // 0x8001C648: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x8001C64C: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
    // 0x8001C650: slt         $at, $t9, $s4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001C654: beq         $at, $zero, L_8001C838
    if (ctx->r1 == 0) {
        // 0x8001C658: lhu         $s3, 0x0($s3)
        ctx->r19 = MEM_HU(ctx->r19, 0X0);
            goto L_8001C838;
    }
    // 0x8001C658: lhu         $s3, 0x0($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X0);
L_8001C65C:
    // 0x8001C65C: slt         $at, $fp, $t0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001C660: beq         $at, $zero, L_8001C688
    if (ctx->r1 == 0) {
        // 0x8001C664: nop
    
            goto L_8001C688;
    }
    // 0x8001C664: nop

    // 0x8001C668: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C66C:
    // 0x8001C66C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C670: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C674: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C678: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C67C: slt         $at, $fp, $t0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001C680: bnel        $at, $zero, L_8001C66C
    if (ctx->r1 != 0) {
        // 0x8001C684: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C66C;
    }
    goto skip_2;
    // 0x8001C684: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_2:
L_8001C688:
    // 0x8001C688: and         $s0, $gp, $s3
    ctx->r16 = ctx->r28 & ctx->r19;
    // 0x8001C68C: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // 0x8001C690: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8001C694: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x8001C698: lbu         $s1, 0x1($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X1);
    // 0x8001C69C: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
    // 0x8001C6A0: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x8001C6A4: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8001C6A8: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x8001C6AC: lhu         $s1, 0x2($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X2);
    // 0x8001C6B0: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x8001C6B4: beq         $at, $zero, L_8001C6D4
    if (ctx->r1 == 0) {
        // 0x8001C6B8: nop
    
            goto L_8001C6D4;
    }
    // 0x8001C6B8: nop

    // 0x8001C6BC: sll         $s2, $t9, 2
    ctx->r18 = S32(ctx->r25 << 2);
    // 0x8001C6C0: addu        $s2, $s2, $sp
    ctx->r18 = ADD32(ctx->r18, ctx->r29);
    // 0x8001C6C4: sw          $s1, 0x548($s2)
    MEM_W(0X548, ctx->r18) = ctx->r17;
    // 0x8001C6C8: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001C6CC: j           L_8001C82C
    // 0x8001C6D0: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
        goto L_8001C82C;
    // 0x8001C6D0: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_8001C6D4:
    // 0x8001C6D4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8001C6D8: bne         $s1, $at, L_8001C74C
    if (ctx->r17 != ctx->r1) {
        // 0x8001C6DC: nop
    
            goto L_8001C74C;
    }
    // 0x8001C6DC: nop

    // 0x8001C6E0: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x8001C6E4: beq         $at, $zero, L_8001C70C
    if (ctx->r1 == 0) {
        // 0x8001C6E8: nop
    
            goto L_8001C70C;
    }
    // 0x8001C6E8: nop

    // 0x8001C6EC: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C6F0:
    // 0x8001C6F0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C6F4: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C6F8: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C6FC: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C700: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x8001C704: bnel        $at, $zero, L_8001C6F0
    if (ctx->r1 != 0) {
        // 0x8001C708: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C6F0;
    }
    goto skip_3;
    // 0x8001C708: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_3:
L_8001C70C:
    // 0x8001C70C: andi        $s1, $gp, 0x3
    ctx->r17 = ctx->r28 & 0X3;
    // 0x8001C710: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x8001C714: srl         $gp, $gp, 2
    ctx->r28 = S32(U32(ctx->r28) >> 2);
    // 0x8001C718: addiu       $fp, $fp, -0x2
    ctx->r30 = ADD32(ctx->r30, -0X2);
    // 0x8001C71C: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x8001C720: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C724: bne         $at, $zero, L_8001C8F4
    if (ctx->r1 != 0) {
        // 0x8001C728: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_8001C8F4;
    }
    // 0x8001C728: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8001C72C: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_8001C730:
    // 0x8001C730: sw          $s2, 0x548($t8)
    MEM_W(0X548, ctx->r24) = ctx->r18;
    // 0x8001C734: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001C738: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8001C73C: bne         $s1, $zero, L_8001C730
    if (ctx->r17 != 0) {
        // 0x8001C740: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_8001C730;
    }
    // 0x8001C740: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8001C744: j           L_8001C82C
    // 0x8001C748: nop

        goto L_8001C82C;
    // 0x8001C748: nop

L_8001C74C:
    // 0x8001C74C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8001C750: bne         $s1, $at, L_8001C7C4
    if (ctx->r17 != ctx->r1) {
        // 0x8001C754: nop
    
            goto L_8001C7C4;
    }
    // 0x8001C754: nop

    // 0x8001C758: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C75C: beq         $at, $zero, L_8001C784
    if (ctx->r1 == 0) {
        // 0x8001C760: nop
    
            goto L_8001C784;
    }
    // 0x8001C760: nop

    // 0x8001C764: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C768:
    // 0x8001C768: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C76C: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C770: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C774: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C778: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C77C: bnel        $at, $zero, L_8001C768
    if (ctx->r1 != 0) {
        // 0x8001C780: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C768;
    }
    goto skip_4;
    // 0x8001C780: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_4:
L_8001C784:
    // 0x8001C784: andi        $s1, $gp, 0x7
    ctx->r17 = ctx->r28 & 0X7;
    // 0x8001C788: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x8001C78C: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x8001C790: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x8001C794: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x8001C798: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C79C: bne         $at, $zero, L_8001C8F4
    if (ctx->r1 != 0) {
        // 0x8001C7A0: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_8001C8F4;
    }
    // 0x8001C7A0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8001C7A4: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_8001C7A8:
    // 0x8001C7A8: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x8001C7AC: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001C7B0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8001C7B4: bne         $s1, $zero, L_8001C7A8
    if (ctx->r17 != 0) {
        // 0x8001C7B8: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_8001C7A8;
    }
    // 0x8001C7B8: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8001C7BC: j           L_8001C82C
    // 0x8001C7C0: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
        goto L_8001C82C;
    // 0x8001C7C0: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
L_8001C7C4:
    // 0x8001C7C4: slti        $at, $fp, 0x7
    ctx->r1 = SIGNED(ctx->r30) < 0X7 ? 1 : 0;
    // 0x8001C7C8: beq         $at, $zero, L_8001C7F0
    if (ctx->r1 == 0) {
        // 0x8001C7CC: nop
    
            goto L_8001C7F0;
    }
    // 0x8001C7CC: nop

    // 0x8001C7D0: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C7D4:
    // 0x8001C7D4: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C7D8: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C7DC: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C7E0: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C7E4: slti        $at, $fp, 0x7
    ctx->r1 = SIGNED(ctx->r30) < 0X7 ? 1 : 0;
    // 0x8001C7E8: bnel        $at, $zero, L_8001C7D4
    if (ctx->r1 != 0) {
        // 0x8001C7EC: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C7D4;
    }
    goto skip_5;
    // 0x8001C7EC: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_5:
L_8001C7F0:
    // 0x8001C7F0: andi        $s1, $gp, 0x7F
    ctx->r17 = ctx->r28 & 0X7F;
    // 0x8001C7F4: addiu       $s1, $s1, 0xB
    ctx->r17 = ADD32(ctx->r17, 0XB);
    // 0x8001C7F8: srl         $gp, $gp, 7
    ctx->r28 = S32(U32(ctx->r28) >> 7);
    // 0x8001C7FC: addiu       $fp, $fp, -0x7
    ctx->r30 = ADD32(ctx->r30, -0X7);
    // 0x8001C800: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x8001C804: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C808: bne         $at, $zero, L_8001C8F4
    if (ctx->r1 != 0) {
        // 0x8001C80C: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_8001C8F4;
    }
    // 0x8001C80C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8001C810: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_8001C814:
    // 0x8001C814: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x8001C818: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x8001C81C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8001C820: bne         $s1, $zero, L_8001C814
    if (ctx->r17 != 0) {
        // 0x8001C824: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_8001C814;
    }
    // 0x8001C824: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x8001C828: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
L_8001C82C:
    // 0x8001C82C: slt         $at, $t9, $s4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8001C830: bne         $at, $zero, L_8001C65C
    if (ctx->r1 != 0) {
        // 0x8001C834: nop
    
            goto L_8001C65C;
    }
    // 0x8001C834: nop

L_8001C838:
    // 0x8001C838: sh          $s5, 0xA38($sp)
    MEM_H(0XA38, ctx->r29) = ctx->r21;
    // 0x8001C83C: sh          $s0, 0xA3A($sp)
    MEM_H(0XA3A, ctx->r29) = ctx->r16;
    // 0x8001C840: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8001C844: sw          $t8, 0xA3C($sp)
    MEM_W(0XA3C, ctx->r29) = ctx->r24;
    // 0x8001C848: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x8001C84C: mtc1        $t3, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r11;
    // 0x8001C850: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x8001C854: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x8001C858: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x8001C85C: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001C860: addiu       $a3, $a3, 0x1772
    ctx->r7 = ADD32(ctx->r7, 0X1772);
    // 0x8001C864: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001C868: addiu       $t7, $t7, 0x17FF
    ctx->r15 = ADD32(ctx->r15, 0X17FF);
    // 0x8001C86C: addiu       $t8, $sp, 0xA38
    ctx->r24 = ADD32(ctx->r29, 0XA38);
    // 0x8001C870: jal         0x8001CA6C
    // 0x8001C874: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    huft_build_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C874: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    after_1:
    // 0x8001C878: mfc1        $t2, $f0
    ctx->r10 = (int32_t)ctx->f0.u32l;
    // 0x8001C87C: mfc1        $t3, $f1
    ctx->r11 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x8001C880: bne         $v0, $zero, L_8001C8F4
    if (ctx->r2 != 0) {
        // 0x8001C884: addiu       $t8, $zero, 0x6
        ctx->r24 = ADD32(0, 0X6);
            goto L_8001C8F4;
    }
    // 0x8001C884: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8001C888: sw          $t8, 0xA40($sp)
    MEM_W(0XA40, ctx->r29) = ctx->r24;
    // 0x8001C88C: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x8001C890: addu        $a0, $a0, $sp
    ctx->r4 = ADD32(ctx->r4, ctx->r29);
    // 0x8001C894: addiu       $a0, $a0, 0x548
    ctx->r4 = ADD32(ctx->r4, 0X548);
    // 0x8001C898: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8001C89C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8001C8A0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8001C8A4: addiu       $a3, $a3, 0x17B0
    ctx->r7 = ADD32(ctx->r7, 0X17B0);
    // 0x8001C8A8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8001C8AC: addiu       $t7, $t7, 0x181E
    ctx->r15 = ADD32(ctx->r15, 0X181E);
    // 0x8001C8B0: addiu       $t8, $sp, 0xA3A
    ctx->r24 = ADD32(ctx->r29, 0XA3A);
    // 0x8001C8B4: jal         0x8001CA6C
    // 0x8001C8B8: addiu       $t9, $sp, 0xA40
    ctx->r25 = ADD32(ctx->r29, 0XA40);
    huft_build_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C8B8: addiu       $t9, $sp, 0xA40
    ctx->r25 = ADD32(ctx->r29, 0XA40);
    after_2:
    // 0x8001C8BC: bne         $v0, $zero, L_8001C8F4
    if (ctx->r2 != 0) {
        // 0x8001C8C0: lhu         $a0, 0xA38($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0XA38);
            goto L_8001C8F4;
    }
    // 0x8001C8C0: lhu         $a0, 0xA38($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XA38);
    // 0x8001C8C4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8001C8C8: addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    // 0x8001C8CC: lhu         $a1, 0xA3A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0XA3A);
    // 0x8001C8D0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x8001C8D4: addu        $a1, $a1, $s6
    ctx->r5 = ADD32(ctx->r5, ctx->r22);
    // 0x8001C8D8: lw          $a2, 0xA3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA3C);
    // 0x8001C8DC: jal         0x8001CF00
    // 0x8001C8E0: lw          $a3, 0xA40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA40);
    inflate_codes_recomp(rdram, ctx);
        goto after_3;
    // 0x8001C8E0: lw          $a3, 0xA40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA40);
    after_3:
    // 0x8001C8E4: bne         $v0, $zero, L_8001C8F4
    if (ctx->r2 != 0) {
        // 0x8001C8E8: nop
    
            goto L_8001C8F4;
    }
    // 0x8001C8E8: nop

    // 0x8001C8EC: j           L_8001C8F8
    // 0x8001C8F0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_8001C8F8;
    // 0x8001C8F0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_8001C8F4:
    // 0x8001C8F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001C8F8:
    // 0x8001C8F8: lw          $ra, 0xA44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA44);
    // 0x8001C8FC: jr          $ra
    // 0x8001C900: nop

    return;
    // 0x8001C900: nop

;}
RECOMP_FUNC void func_80094348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094348: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8009434C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80094350: lbu         $t7, 0x2($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2);
    // 0x80094354: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x80094358: beq         $t8, $zero, L_80094368
    if (ctx->r24 == 0) {
        // 0x8009435C: nop
    
            goto L_80094368;
    }
    // 0x8009435C: nop

    // 0x80094360: jr          $ra
    // 0x80094364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80094364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094368:
    // 0x80094368: jr          $ra
    // 0x8009436C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8009436C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _fxspgold_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AC0: syscall     721
    recomp_syscall_handler(rdram, ctx, 0x80088AC0);
    return;
    // 0x80088AC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000AC_chpumproomgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(992, 0X128) << 16);
    // 0x808000B8: addiu       $a2, $a2, 0x128
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(992, 0X128));
    // 0x808000BC: jal         0x80089D18
    // 0x808000C0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808000C0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808000C4: jal         0x800DA544
    // 0x808000C8: addiu       $a0, $zero, 0x162
    ctx->r4 = ADD32(0, 0X162);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808000C8: addiu       $a0, $zero, 0x162
    ctx->r4 = ADD32(0, 0X162);
    after_1:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

    // 0x808000DC: nop

;}
RECOMP_FUNC void func_808000F4_chghostdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800104: beq         $a1, $at, L_80800120
    if (ctx->r5 == ctx->r1) {
        // 0x80800108: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800120;
    }
    // 0x80800108: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080010C: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x80800110: beq         $a1, $at, L_80800164
    if (ctx->r5 == ctx->r1) {
        // 0x80800114: nop
    
            goto L_80800164;
    }
    // 0x80800114: nop

    // 0x80800118: b           L_80800178
    // 0x8080011C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_80800178;
    // 0x8080011C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800120:
    // 0x80800120: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800124: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800128: addiu       $v0, $zero, 0x783
    ctx->r2 = ADD32(0, 0X783);
    // 0x8080012C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800130: bne         $t7, $at, L_80800140
    if (ctx->r15 != ctx->r1) {
        // 0x80800134: nop
    
            goto L_80800140;
    }
    // 0x80800134: nop

    // 0x80800138: b           L_80800140
    // 0x8080013C: addiu       $v0, $zero, 0x782
    ctx->r2 = ADD32(0, 0X782);
        goto L_80800140;
    // 0x8080013C: addiu       $v0, $zero, 0x782
    ctx->r2 = ADD32(0, 0X782);
L_80800140:
    // 0x80800140: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800144: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800148: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x8080014C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800150: jal         0x80103140
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080015C: b           L_80800174
    // 0x80800160: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_80800174;
    // 0x80800160: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800164:
    // 0x80800164: jal         0x800FFAB0
    // 0x80800168: nop

    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800168: nop

    after_1:
    // 0x8080016C: b           L_80800180
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800180;
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800174:
    // 0x80800174: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800178:
    // 0x80800178: jal         0x80086248
    // 0x8080017C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080017C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
L_80800180:
    // 0x80800180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_80800000_sudialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80800004: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800008: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8080000C: bltzl       $t6, L_80800040
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800010: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800040;
    }
    goto skip_0;
    // 0x80800010: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80800014: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
L_80800018:
    // 0x80800018: bnel        $a1, $a2, L_8080002C
    if (ctx->r5 != ctx->r6) {
        // 0x8080001C: lh          $a2, 0x4($v0)
        ctx->r6 = MEM_H(ctx->r2, 0X4);
            goto L_8080002C;
    }
    goto skip_1;
    // 0x8080001C: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    skip_1:
    // 0x80800020: jr          $ra
    // 0x80800024: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800024: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800028: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
L_8080002C:
    // 0x8080002C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800030: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800034: bgez        $a2, L_80800018
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80800038: nop
    
            goto L_80800018;
    }
    // 0x80800038: nop

    // 0x8080003C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800040:
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_80801038_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080103C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801040: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801044: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080104C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801050: bgez        $t8, L_80801090
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801054: lui         $a1, 0x4234
        ctx->r5 = S32(0X4234 << 16);
            goto L_80801090;
    }
    // 0x80801054: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80801058: addiu       $a2, $zero, 0x2D
    ctx->r6 = ADD32(0, 0X2D);
    // 0x8080105C: jal         0x800CE8D8
    // 0x80801060: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800CE8D8(rdram, ctx);
        goto after_0;
    // 0x80801060: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801064: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801068: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080106C: addiu       $a1, $a1, 0x7520
    ctx->r5 = ADD32(ctx->r5, 0X7520);
    // 0x80801070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801074: jal         0x800CE928
    // 0x80801078: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    func_800CE928(rdram, ctx);
        goto after_1;
    // 0x80801078: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    after_1:
    // 0x8080107C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801080: jal         0x800CE88C
    // 0x80801084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80801084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801088: b           L_808010A0
    // 0x8080108C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808010A0;
    // 0x8080108C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801090:
    // 0x80801090: lbu         $t0, 0x65($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X65);
    // 0x80801094: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80801098: sb          $t1, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r9;
    // 0x8080109C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010A0:
    // 0x808010A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010A4: jr          $ra
    // 0x808010A8: nop

    return;
    // 0x808010A8: nop

;}
RECOMP_FUNC void func_80800A64_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A74: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A78: jal         0x80100094
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A80: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80800A84: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800A88: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800A8C: beq         $v1, $zero, L_80800AB0
    if (ctx->r3 == 0) {
        // 0x80800A90: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_80800AB0;
    }
    // 0x80800A90: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A98: beq         $v1, $at, L_80800ACC
    if (ctx->r3 == ctx->r1) {
        // 0x80800A9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800ACC;
    }
    // 0x80800A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AA0: beql        $v1, $at, L_80800AC8
    if (ctx->r3 == ctx->r1) {
        // 0x80800AA4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800AC8;
    }
    goto skip_0;
    // 0x80800AA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_0:
    // 0x80800AA8: b           L_80800AE4
    // 0x80800AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800AE4;
    // 0x80800AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AB0:
    // 0x80800AB0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800AB4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800AB8: jal         0x800856B0
    // 0x80800ABC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800ABC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800AC0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800AC8:
    // 0x80800AC8: sw          $t7, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r15;
L_80800ACC:
    // 0x80800ACC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800AD0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800AD4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800AD8: jal         0x800856D0
    // 0x80800ADC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800ADC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x80800AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800AE4:
    // 0x80800AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void func_808016B4_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808016B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016BC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808016C0: addiu       $a0, $zero, 0x482
    ctx->r4 = ADD32(0, 0X482);
    // 0x808016C4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808016C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808016CC: jal         0x80089C40
    // 0x808016D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808016D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x808016D4: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x808016D8: bltz        $a0, L_8080171C
    if (SIGNED(ctx->r4) < 0) {
        // 0x808016DC: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8080171C;
    }
    // 0x808016DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808016E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808016E4: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x808016E8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808016EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808016F0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_808016F4:
    // 0x808016F4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x808016F8: lhu         $t9, 0x72($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X72);
    // 0x808016FC: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80801700: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x80801704: beql        $at, $zero, L_80801714
    if (ctx->r1 == 0) {
        // 0x80801708: sltu        $at, $v0, $a0
        ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
            goto L_80801714;
    }
    goto skip_0;
    // 0x80801708: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    skip_0:
    // 0x8080170C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801710: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
L_80801714:
    // 0x80801714: beql        $at, $zero, L_808016F4
    if (ctx->r1 == 0) {
        // 0x80801718: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_808016F4;
    }
    goto skip_1;
    // 0x80801718: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_8080171C:
    // 0x8080171C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80801720: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801728: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080172C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801730: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801734: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801738: jr          $ra
    // 0x8080173C: nop

    return;
    // 0x8080173C: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D88: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082D88);
    return;
    // 0x80082D8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800770_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800778: jal         0x8080021C
    // 0x8080077C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x8080077C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800780: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800788: jal         0x808005DC
    // 0x8080078C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_808005DC_bsbanshack(rdram, ctx);
        goto after_1;
    // 0x8080078C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800798: jr          $ra
    // 0x8080079C: nop

    return;
    // 0x8080079C: nop

;}
RECOMP_FUNC void func_80800688_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800688: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080068C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800690: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800694: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800698: jal         0x800E3A58
    // 0x8080069C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800E3A58(rdram, ctx);
        goto after_0;
    // 0x8080069C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x808006A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808006A4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808006A8: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    // 0x808006AC: jal         0x80101870
    // 0x808006B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808006B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x808006B4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808006B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808006BC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808006C0: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x808006C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006C8: nop

    // 0x808006CC: bc1f        L_808006F4
    if (!c1cs) {
        // 0x808006D0: nop
    
            goto L_808006F4;
    }
    // 0x808006D0: nop

    // 0x808006D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006D8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(784, 0XA50) << 16);
    // 0x808006DC: addiu       $a1, $a1, 0xA50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(784, 0XA50));
    // 0x808006E0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808006E4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808006E8: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x808006EC: jal         0x8008A8F0
    // 0x808006F0: nop

    _sufade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808006F0: nop

    after_2:
L_808006F4:
    // 0x808006F4: jal         0x800E3980
    // 0x808006F8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x808006F8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x808006FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800700: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800704: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80800708: jal         0x800F1E6C
    // 0x8080070C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1E6C(rdram, ctx);
        goto after_4;
    // 0x8080070C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800710: beq         $v0, $zero, L_80800774
    if (ctx->r2 == 0) {
        // 0x80800714: lwc1        $f12, 0x30($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80800774;
    }
    // 0x80800714: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800718: jal         0x800F1DCC
    // 0x8080071C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x8080071C: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80800720: jal         0x800F2100
    // 0x80800724: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x80800724: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80800728: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080072C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800730: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800734: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800738: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080073C: div.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800740: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80800744: nop

    // 0x80800748: bc1fl       L_80800778
    if (!c1cs) {
        // 0x8080074C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800778;
    }
    goto skip_0;
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800750: sub.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80800754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800758: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(784, 0XA50) << 16);
    // 0x8080075C: addiu       $a1, $a1, 0xA50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(784, 0XA50));
    // 0x80800760: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800764: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800768: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8080076C: jal         0x8008A8F0
    // 0x80800770: nop

    _sufade_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800770: nop

    after_7:
L_80800774:
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800778:
    // 0x80800778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080077C: jr          $ra
    // 0x80800780: nop

    return;
    // 0x80800780: nop

;}
RECOMP_FUNC void func_800F4AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4AC0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F4AC4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4ACC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4AD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4AD4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4AD8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F4ADC: jal         0x80084868
    // 0x800F4AE0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x800F4AE0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4AEC: jr          $ra
    // 0x800F4AF0: nop

    return;
    // 0x800F4AF0: nop

;}
RECOMP_FUNC void func_8080220C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080220C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080221C: jal         0x80100094
    // 0x80802220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802224: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x80802228: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080222C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80802230: beq         $at, $zero, L_80802308
    if (ctx->r1 == 0) {
        // 0x80802234: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80802308;
    }
    // 0x80802234: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802238: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X3874) << 16);
    // 0x8080223C: addu        $at, $at, $t6
    gpr jr_addend_80802244 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80802240: lw          $t6, 0x3874($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X3874));
    // 0x80802244: jr          $t6
    // 0x80802248: nop

    switch (jr_addend_80802244 >> 2) {
        case 0: goto L_80802308; break;
        case 1: goto L_8080224C; break;
        case 2: goto L_80802274; break;
        case 3: goto L_808022A0; break;
        case 4: goto L_808022C8; break;
        case 5: goto L_808022E8; break;
        default: switch_error(__func__, 0x80802244, 0x80803874);
    }
    // 0x80802248: nop

L_8080224C:
    // 0x8080224C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802250: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802254: jal         0x8080231C
    // 0x80802258: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_8080231C_chklungo(rdram, ctx);
        goto after_1;
    // 0x80802258: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_1:
    // 0x8080225C: beq         $v0, $zero, L_80802308
    if (ctx->r2 == 0) {
        // 0x80802260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802308;
    }
    // 0x80802260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802264: jal         0x808020F0
    // 0x80802268: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808020F0_chklungo(rdram, ctx);
        goto after_2;
    // 0x80802268: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080226C: b           L_8080230C
    // 0x80802270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080230C;
    // 0x80802270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802274:
    // 0x80802274: jal         0x800D9078
    // 0x80802278: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x80802278: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    after_3:
    // 0x8080227C: beql        $v0, $zero, L_8080230C
    if (ctx->r2 == 0) {
        // 0x80802280: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080230C;
    }
    goto skip_0;
    // 0x80802280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802284: jal         0x80802F58
    // 0x80802288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802F58_chklungo(rdram, ctx);
        goto after_4;
    // 0x80802288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802290: jal         0x808020F0
    // 0x80802294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808020F0_chklungo(rdram, ctx);
        goto after_5;
    // 0x80802294: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80802298: b           L_8080230C
    // 0x8080229C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080230C;
    // 0x8080229C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022A0:
    // 0x808022A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022A4: lui         $a1, 0x4240
    ctx->r5 = S32(0X4240 << 16);
    // 0x808022A8: jal         0x808023A4
    // 0x808022AC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_808023A4_chklungo(rdram, ctx);
        goto after_6;
    // 0x808022AC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_6:
    // 0x808022B0: beq         $v0, $zero, L_80802308
    if (ctx->r2 == 0) {
        // 0x808022B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802308;
    }
    // 0x808022B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022B8: jal         0x808020F0
    // 0x808022BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808020F0_chklungo(rdram, ctx);
        goto after_7;
    // 0x808022BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x808022C0: b           L_8080230C
    // 0x808022C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080230C;
    // 0x808022C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022C8:
    // 0x808022C8: jal         0x800D9078
    // 0x808022CC: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808022CC: addiu       $a0, $v1, 0x14
    ctx->r4 = ADD32(ctx->r3, 0X14);
    after_8:
    // 0x808022D0: beq         $v0, $zero, L_80802308
    if (ctx->r2 == 0) {
        // 0x808022D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802308;
    }
    // 0x808022D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022D8: jal         0x808020F0
    // 0x808022DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808020F0_chklungo(rdram, ctx);
        goto after_9;
    // 0x808022DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808022E0: b           L_8080230C
    // 0x808022E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080230C;
    // 0x808022E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022E8:
    // 0x808022E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808022EC: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x808022F0: jal         0x808023A4
    // 0x808022F4: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_808023A4_chklungo(rdram, ctx);
        goto after_10;
    // 0x808022F4: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_10:
    // 0x808022F8: beq         $v0, $zero, L_80802308
    if (ctx->r2 == 0) {
        // 0x808022FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802308;
    }
    // 0x808022FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802300: jal         0x808020F0
    // 0x80802304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808020F0_chklungo(rdram, ctx);
        goto after_11;
    // 0x80802304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_80802308:
    // 0x80802308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080230C:
    // 0x8080230C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802314: jr          $ra
    // 0x80802318: nop

    return;
    // 0x80802318: nop

;}
