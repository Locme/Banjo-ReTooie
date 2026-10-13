#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080088C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080088C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800894: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800898: jal         0x800839E8
    // 0x8080089C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080089C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808008A0: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x808008A4: addiu       $t6, $zero, 0x11B
        ctx->r14 = ADD32(0, 0X11B);
            goto L_808008AC;
    }
    // 0x808008A4: addiu       $t6, $zero, 0x11B
    ctx->r14 = ADD32(0, 0X11B);
    // 0x808008A8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808008AC:
    // 0x808008AC: jal         0x80084138
    // 0x808008B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsvan_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808008B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808008B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008B8: jal         0x8009E5C8
    // 0x808008BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808008BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808008C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008C8: jr          $ra
    // 0x808008CC: nop

    return;
    // 0x808008CC: nop

;}
RECOMP_FUNC void func_808004B4_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: jal         0x80105230
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_0;
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004CC: jr          $ra
    // 0x808004D0: nop

    return;
    // 0x808004D0: nop

;}
RECOMP_FUNC void func_8080145C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801460: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801464: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801468: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080146C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801470: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801474: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80801478: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080147C: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80801480: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801484: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80801488: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080148C: bc1f        L_808014C8
    if (!c1cs) {
        // 0x80801490: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808014C8;
    }
    // 0x80801490: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80801494: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80801498: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8080149C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808014A0: nop

    // 0x808014A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_808014A8:
    // 0x808014A8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808014AC: jal         0x800849F0
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808014B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808014B4: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x808014B8: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x808014BC: nop

    // 0x808014C0: bc1tl       L_808014A8
    if (c1cs) {
        // 0x808014C4: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_808014A8;
    }
    goto skip_0;
    // 0x808014C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_808014C8:
    // 0x808014C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808014CC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808014D0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808014D4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808014D8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808014DC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808014E0: jr          $ra
    // 0x808014E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808014E4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80802468_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802468: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080246C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80802470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802474: beq         $a1, $at, L_808024D0
    if (ctx->r5 == ctx->r1) {
        // 0x80802478: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808024D0;
    }
    // 0x80802478: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080247C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80802480: beq         $a1, $at, L_808024B0
    if (ctx->r5 == ctx->r1) {
        // 0x80802484: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_808024B0;
    }
    // 0x80802484: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80802488: beq         $a1, $at, L_808024A0
    if (ctx->r5 == ctx->r1) {
        // 0x8080248C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_808024A0;
    }
    // 0x8080248C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80802490: beq         $a1, $at, L_80802540
    if (ctx->r5 == ctx->r1) {
        // 0x80802494: nop
    
            goto L_80802540;
    }
    // 0x80802494: nop

    // 0x80802498: b           L_8080255C
    // 0x8080249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080255C;
    // 0x8080249C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808024A0:
    // 0x808024A0: jal         0x80802394
    // 0x808024A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80802394_chhandcart(rdram, ctx);
        goto after_0;
    // 0x808024A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808024A8: b           L_8080255C
    // 0x808024AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080255C;
    // 0x808024AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808024B0:
    // 0x808024B0: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x808024B4: jal         0x80106790
    // 0x808024B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808024B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x808024BC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808024C0: jal         0x80802400
    // 0x808024C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80802400_chhandcart(rdram, ctx);
        goto after_2;
    // 0x808024C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808024C8: b           L_8080255C
    // 0x808024CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080255C;
    // 0x808024CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808024D0:
    // 0x808024D0: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x808024D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808024D8: jal         0x80106790
    // 0x808024DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808024DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x808024E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808024E4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x808024E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808024EC: beq         $a2, $at, L_80802508
    if (ctx->r6 == ctx->r1) {
        // 0x808024F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80802508;
    }
    // 0x808024F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808024F4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x808024F8: bne         $a2, $at, L_8080250C
    if (ctx->r6 != ctx->r1) {
        // 0x808024FC: nop
    
            goto L_8080250C;
    }
    // 0x808024FC: nop

    // 0x80802500: b           L_8080250C
    // 0x80802504: addiu       $v1, $zero, 0xF85
    ctx->r3 = ADD32(0, 0XF85);
        goto L_8080250C;
    // 0x80802504: addiu       $v1, $zero, 0xF85
    ctx->r3 = ADD32(0, 0XF85);
L_80802508:
    // 0x80802508: addiu       $v1, $zero, 0xFAF
    ctx->r3 = ADD32(0, 0XFAF);
L_8080250C:
    // 0x8080250C: beq         $v1, $zero, L_80802538
    if (ctx->r3 == 0) {
        // 0x80802510: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802538;
    }
    // 0x80802510: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802514: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80802518: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080251C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80802520: jal         0x80800858
    // 0x80802524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800858_chhandcart(rdram, ctx);
        goto after_4;
    // 0x80802524: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80802528: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080252C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80802530: jal         0x808023B4
    // 0x80802534: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_808023B4_chhandcart(rdram, ctx);
        goto after_5;
    // 0x80802534: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_5:
L_80802538:
    // 0x80802538: b           L_8080255C
    // 0x8080253C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080255C;
    // 0x8080253C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80802540:
    // 0x80802540: jal         0x80801FFC
    // 0x80802544: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801FFC_chhandcart(rdram, ctx);
        goto after_6;
    // 0x80802544: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_6:
    // 0x80802548: b           L_8080255C
    // 0x8080254C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080255C;
    // 0x8080254C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802550: b           L_8080255C
    // 0x80802554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080255C;
    // 0x80802554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080255C:
    // 0x8080255C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802564: jr          $ra
    // 0x80802568: nop

    return;
    // 0x80802568: nop

;}
RECOMP_FUNC void func_80803A24_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803A28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803A2C: beq         $a1, $at, L_80803A58
    if (ctx->r5 == ctx->r1) {
        // 0x80803A30: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80803A58;
    }
    // 0x80803A30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803A34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803A38: beq         $a1, $at, L_80803A70
    if (ctx->r5 == ctx->r1) {
        // 0x80803A3C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803A70;
    }
    // 0x80803A3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803A40: beq         $a1, $at, L_80803A90
    if (ctx->r5 == ctx->r1) {
        // 0x80803A44: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80803A90;
    }
    // 0x80803A44: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80803A48: beql        $a1, $at, L_80803AFC
    if (ctx->r5 == ctx->r1) {
        // 0x80803A4C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80803AFC;
    }
    goto skip_0;
    // 0x80803A4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80803A50: b           L_80803B08
    // 0x80803A54: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
        goto L_80803B08;
    // 0x80803A54: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
L_80803A58:
    // 0x80803A58: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80803A5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4080) << 16);
    // 0x80803A60: lwc1        $f16, 0x4080($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4080));
    // 0x80803A64: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80803A68: b           L_80803B04
    // 0x80803A6C: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
        goto L_80803B04;
    // 0x80803A6C: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
L_80803A70:
    // 0x80803A70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803A74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803A78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4084) << 16);
    // 0x80803A7C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80803A80: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80803A84: lwc1        $f8, 0x4084($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4084));
    // 0x80803A88: b           L_80803B04
    // 0x80803A8C: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
        goto L_80803B04;
    // 0x80803A8C: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
L_80803A90:
    // 0x80803A90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803A98: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803A9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X4088) << 16);
    // 0x80803AA0: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80803AA4: lwc1        $f10, 0x4088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X4088));
    // 0x80803AA8: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80803AAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803AB0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803AB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803AB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803ABC: jal         0x800F10B4
    // 0x80803AC0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80803AC0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80803AC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80803AC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803ACC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80803AD0: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80803AD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X408C) << 16);
    // 0x80803AD8: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80803ADC: bc1fl       L_80803B08
    if (!c1cs) {
        // 0x80803AE0: lbu         $t9, 0x72($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X72);
            goto L_80803B08;
    }
    goto skip_1;
    // 0x80803AE0: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
    skip_1:
    // 0x80803AE4: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80803AE8: lwc1        $f4, 0x408C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X408C));
    // 0x80803AEC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80803AF0: b           L_80803B04
    // 0x80803AF4: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
        goto L_80803B04;
    // 0x80803AF4: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80803AF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80803AFC:
    // 0x80803AFC: nop

    // 0x80803B00: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
L_80803B04:
    // 0x80803B04: lbu         $t9, 0x72($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X72);
L_80803B08:
    // 0x80803B08: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80803B0C: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80803B10: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80803B14: sb          $t1, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r9;
    // 0x80803B18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803B20: jr          $ra
    // 0x80803B24: nop

    return;
    // 0x80803B24: nop

;}
RECOMP_FUNC void func_80809CD8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809CD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809CE0: jal         0x80809CF8
    // 0x80809CE4: nop

    func_80809CF8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809CE4: nop

    after_0:
    // 0x80809CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809CF0: jr          $ra
    // 0x80809CF4: nop

    return;
    // 0x80809CF4: nop

;}
RECOMP_FUNC void chfirefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1104, 0X1200) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1200
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1104, 0X1200));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1200
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1104, 0X1200));
;}
RECOMP_FUNC void func_808013A4_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013AC: jal         0x808001A8
    // 0x808013B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x808013B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013B4: jal         0x800839C8
    // 0x808013B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x808013B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808013BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013C4: jr          $ra
    // 0x808013C8: nop

    return;
    // 0x808013C8: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F2C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800F30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F3C: jal         0x808000C8
    // 0x80800F40: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_808000C8_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x80800F40: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x80800F44: jal         0x8009D658
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_1;
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: jal         0x800852F0
    // 0x80800F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x80800F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800F58: jal         0x8008DF18
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_3;
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800F60: beq         $v0, $zero, L_80800FE8
    if (ctx->r2 == 0) {
        // 0x80800F64: addiu       $t6, $zero, 0x48
        ctx->r14 = ADD32(0, 0X48);
            goto L_80800FE8;
    }
    // 0x80800F64: addiu       $t6, $zero, 0x48
    ctx->r14 = ADD32(0, 0X48);
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F6C: jal         0x800963C0
    // 0x80800F70: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800963C0(rdram, ctx);
        goto after_4;
    // 0x80800F70: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80800F74: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800F78: jal         0x800F1EA4
    // 0x80800F7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1EA4(rdram, ctx);
        goto after_5;
    // 0x80800F7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F88: jal         0x8009D2F0
    // 0x80800F8C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_6;
    // 0x80800F8C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_6:
    // 0x80800F90: jal         0x8009BFD8
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_7;
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F98: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800F9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800FA0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800FA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FA8: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x80800FAC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80800FB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800FB4: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800FB8: jal         0x800F10B4
    // 0x80800FBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800FBC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800FC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FC4: jal         0x8009B9B0
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD0: jal         0x8009B9C0
    // 0x80800FD4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x80800FD4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80800FD8: jal         0x800849D0
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800FE0: b           L_80800FF0
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800FF0;
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FE8:
    // 0x80800FE8: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FF0:
    // 0x80800FF0: jal         0x80085330
    // 0x80800FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_12;
    // 0x80800FF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800FF8: beq         $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80800FFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801014;
    }
    // 0x80800FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801000: jal         0x80091A58
    // 0x80801004: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x80801004: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80801008: beq         $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x8080100C: addiu       $t7, $zero, 0x4A
        ctx->r15 = ADD32(0, 0X4A);
            goto L_80801014;
    }
    // 0x8080100C: addiu       $t7, $zero, 0x4A
    ctx->r15 = ADD32(0, 0X4A);
    // 0x80801010: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_80801014:
    // 0x80801014: jal         0x80800000
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazstilt(rdram, ctx);
        goto after_14;
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080101C: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80801020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801024: addiu       $t8, $zero, 0x160
    ctx->r24 = ADD32(0, 0X160);
    // 0x80801028: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8080102C:
    // 0x8080102C: jal         0x8009E5C8
    // 0x80801030: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x80801030: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_15:
    // 0x80801034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801038: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080103C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801040: jr          $ra
    // 0x80801044: nop

    return;
    // 0x80801044: nop

;}
RECOMP_FUNC void func_800F8B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8B64: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F8B68: jr          $ra
    // 0x800F8B6C: lbu         $v0, 0x54F9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54F9);
    return;
    // 0x800F8B6C: lbu         $v0, 0x54F9($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54F9);
;}
RECOMP_FUNC void func_8008C958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C95C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8008C960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C964: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008C968: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x8008C96C: jal         0x800EE7F8
    // 0x8008C970: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8008C970: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x8008C974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C97C: jr          $ra
    // 0x8008C980: nop

    return;
    // 0x8008C980: nop

;}
RECOMP_FUNC void func_800C3E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3E90: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C3E94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3E98: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800C3E9C: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x800C3EA0: jal         0x800C2840
    // 0x800C3EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3EA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C3EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3EAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3EB0: jr          $ra
    // 0x800C3EB4: nop

    return;
    // 0x800C3EB4: nop

;}
RECOMP_FUNC void func_8080100C_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080100C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080101C: jal         0x80088840
    // 0x80801020: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80801020: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    after_0:
    // 0x80801024: beq         $v0, $zero, L_80801060
    if (ctx->r2 == 0) {
        // 0x80801028: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80801060;
    }
    // 0x80801028: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080102C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80801030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801038: jal         0x80085708
    // 0x8080103C: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x8080103C: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    after_1:
    // 0x80801040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801044: jal         0x80101FDC
    // 0x80801048: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801048: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080104C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X13E4) << 16);
    // 0x80801050: lwc1        $f4, 0x13E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2208, 0X13E4));
    // 0x80801054: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801058: b           L_8080111C
    // 0x8080105C: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
        goto L_8080111C;
    // 0x8080105C: swc1        $f4, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f4.u32l;
L_80801060:
    // 0x80801060: jal         0x800EA090
    // 0x80801064: nop

    func_800EA090(rdram, ctx);
        goto after_3;
    // 0x80801064: nop

    after_3:
    // 0x80801068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080106C: beq         $v0, $at, L_80801084
    if (ctx->r2 == ctx->r1) {
        // 0x80801070: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801084;
    }
    // 0x80801070: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801074: beq         $v0, $at, L_808010FC
    if (ctx->r2 == ctx->r1) {
        // 0x80801078: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808010FC;
    }
    // 0x80801078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080107C: b           L_80801120
    // 0x80801080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801120;
    // 0x80801080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801084:
    // 0x80801084: jal         0x800C6E38
    // 0x80801088: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_4;
    // 0x80801088: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_4:
    // 0x8080108C: beql        $v0, $zero, L_80801120
    if (ctx->r2 == 0) {
        // 0x80801090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801120;
    }
    goto skip_0;
    // 0x80801090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801094: jal         0x800F5410
    // 0x80801098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F5410(rdram, ctx);
        goto after_5;
    // 0x80801098: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x8080109C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808010A0: bne         $v0, $at, L_8080111C
    if (ctx->r2 != ctx->r1) {
        // 0x808010A4: addiu       $a0, $zero, 0x6BA
        ctx->r4 = ADD32(0, 0X6BA);
            goto L_8080111C;
    }
    // 0x808010A4: addiu       $a0, $zero, 0x6BA
    ctx->r4 = ADD32(0, 0X6BA);
    // 0x808010A8: jal         0x800DA9E4
    // 0x808010AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x808010AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808010B0: bne         $v0, $zero, L_8080111C
    if (ctx->r2 != 0) {
        // 0x808010B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080111C;
    }
    // 0x808010B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808010B8: jal         0x80101FDC
    // 0x808010BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808010BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808010C0: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808010C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808010CC: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    // 0x808010D0: jal         0x80085708
    // 0x808010D4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x808010D4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_8:
    // 0x808010D8: jal         0x800F54E4
    // 0x808010DC: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808010DC: nop

    after_9:
    // 0x808010E0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808010E4: addiu       $a1, $a1, 0x4318
    ctx->r5 = ADD32(ctx->r5, 0X4318);
    // 0x808010E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010EC: jal         0x800F49D4
    // 0x808010F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_10;
    // 0x808010F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x808010F4: b           L_80801120
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801120;
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010FC:
    // 0x808010FC: jal         0x80101FDC
    // 0x80801100: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80801100: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80801104: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80801108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080110C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801110: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x80801114: jal         0x80085708
    // 0x80801118: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80801118: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_12:
L_8080111C:
    // 0x8080111C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801120:
    // 0x80801120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801124: jr          $ra
    // 0x80801128: nop

    return;
    // 0x80801128: nop

;}
RECOMP_FUNC void func_800F2F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2F3C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F2F40: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800F2F44: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800F2F48: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x800F2F4C: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800F2F50: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    // 0x800F2F54: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x800F2F58: jr          $ra
    // 0x800F2F5C: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
    return;
    // 0x800F2F5C: sb          $t9, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_800BA77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA77C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA784: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA78C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA790: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BA794: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA798: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800BA79C: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800BA7A0: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BA7A4: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BA7A8: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA7AC: jal         0x800EFA6C
    // 0x800BA7B0: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA7B0: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_0:
    // 0x800BA7B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA7B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA7BC: jr          $ra
    // 0x800BA7C0: nop

    return;
    // 0x800BA7C0: nop

;}
RECOMP_FUNC void badata_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800978: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8080097C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800988: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X2258) << 16);
    // 0x8080098C: jal         0x808006AC
    // 0x80800990: addiu       $a1, $a1, 0x2258
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2258));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800990: addiu       $a1, $a1, 0x2258
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X2258));
    after_0:
    // 0x80800994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080099C: jr          $ra
    // 0x808009A0: nop

    return;
    // 0x808009A0: nop

;}
RECOMP_FUNC void func_800E148C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E148C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800E1490: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800E1494: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800E1498: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E149C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800E14A0: addiu       $t7, $t7, -0x3070
    ctx->r15 = ADD32(ctx->r15, -0X3070);
    // 0x800E14A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E14A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800E14AC: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800E14B0: jr          $ra
    // 0x800E14B4: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
    return;
    // 0x800E14B4: swc1        $f14, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_8080800C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080800C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80808010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808014: lw          $a3, 0x188($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X188);
    // 0x80808018: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080801C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80808020: jal         0x80808100
    // 0x80808024: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80808100_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808024: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80808028: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8080802C: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x80808030: addiu       $a1, $sp, 0x2E
    ctx->r5 = ADD32(ctx->r29, 0X2E);
    // 0x80808034: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80808038: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_8080803C:
    // 0x8080803C: lh          $t7, 0x6C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6C);
    // 0x80808040: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80808044: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80808048: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080804C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80808050: mflo        $t8
    ctx->r24 = lo;
    // 0x80808054: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80808058: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x8080805C: bne         $v1, $a1, L_8080803C
    if (ctx->r3 != ctx->r5) {
        // 0x80808060: sh          $t0, 0x6A($v0)
        MEM_H(0X6A, ctx->r2) = ctx->r8;
            goto L_8080803C;
    }
    // 0x80808060: sh          $t0, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r8;
    // 0x80808064: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80808068: addiu       $a1, $a3, 0x6C
    ctx->r5 = ADD32(ctx->r7, 0X6C);
    // 0x8080806C: jal         0x808080B4
    // 0x80808070: lbu         $a2, 0x72($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X72);
    func_808080B4_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808070: lbu         $a2, 0x72($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X72);
    after_1:
    // 0x80808074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808078: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080807C: jr          $ra
    // 0x80808080: nop

    return;
    // 0x80808080: nop

;}
RECOMP_FUNC void func_80801C04_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C04: jr          $ra
    // 0x80801C08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801C08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800008_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: lw          $v0, 0x110($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X110);
    // 0x80800018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080001C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800020: lbu         $t6, 0x2D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2D);
    // 0x80800024: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80800028: bnel        $t6, $at, L_8080004C
    if (ctx->r14 != ctx->r1) {
        // 0x8080002C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x8080002C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800030: jal         0x80095774
    // 0x80800034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    baflag_clear(rdram, ctx);
        goto after_0;
    // 0x80800034: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800038: jal         0x800FC74C
    // 0x8080003C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FC74C(rdram, ctx);
        goto after_1;
    // 0x8080003C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_1:
    // 0x80800040: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: lw          $v0, 0x110($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X110);
    // 0x80800048: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080004C:
    // 0x8080004C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800054: sb          $t7, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r15;
    // 0x80800058: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: bnel        $t8, $at, L_80800078
    if (ctx->r24 != ctx->r1) {
        // 0x80800060: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800078;
    }
    goto skip_1;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800064: jal         0x80095760
    // 0x80800068: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x8080006C: jal         0x800FC660
    // 0x80800070: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800078:
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_80801034_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E94) << 16);
    // 0x80801038: lwc1        $f4, 0x3E94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E94));
    // 0x8080103C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E98) << 16);
    // 0x80801040: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80801044: lwc1        $f6, 0x3E98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E98));
    // 0x80801048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E9C) << 16);
    // 0x8080104C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80801050: lwc1        $f8, 0x3E9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E9C));
    // 0x80801054: jr          $ra
    // 0x80801058: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80801058: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_8008C9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9E4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9E8: jr          $ra
    // 0x8008C9EC: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
    return;
    // 0x8008C9EC: sb          $a1, 0xC($t6)
    MEM_B(0XC, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800338_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080033C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800348: jal         0x80100094
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800350: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800354: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800358: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080035C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800360: sltiu       $at, $t8, 0xC
    ctx->r1 = ctx->r24 < 0XC ? 1 : 0;
    // 0x80800364: beq         $at, $zero, L_80800868
    if (ctx->r1 == 0) {
        // 0x80800368: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800868;
    }
    // 0x80800368: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1280) << 16);
    // 0x80800370: addu        $at, $at, $t8
    gpr jr_addend_80800378 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800374: lw          $t8, 0x1280($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1280));
    // 0x80800378: jr          $t8
    // 0x8080037C: nop

    switch (jr_addend_80800378 >> 2) {
        case 0: goto L_80800868; break;
        case 1: goto L_80800380; break;
        case 2: goto L_808003F0; break;
        case 3: goto L_80800450; break;
        case 4: goto L_808004DC; break;
        case 5: goto L_808004A8; break;
        case 6: goto L_8080052C; break;
        case 7: goto L_80800868; break;
        case 8: goto L_80800868; break;
        case 9: goto L_80800868; break;
        case 10: goto L_80800868; break;
        case 11: goto L_80800868; break;
        default: switch_error(__func__, 0x80800378, 0x80801280);
    }
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: jal         0x80800100
    // 0x80800384: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80800100_chcrusherboulder(rdram, ctx);
        goto after_1;
    // 0x80800384: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800388: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080038C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800390: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080039C: nop

    // 0x808003A0: bc1fl       L_808003D0
    if (!c1cs) {
        // 0x808003A4: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_808003D0;
    }
    goto skip_0;
    // 0x808003A4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x808003A8: jal         0x800D8FF8
    // 0x808003AC: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808003AC: nop

    after_2:
    // 0x808003B0: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x808003B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003BC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808003C0: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x808003C4: b           L_80800868
    // 0x808003C8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
        goto L_80800868;
    // 0x808003C8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x808003CC: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_808003D0:
    // 0x808003D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808003D8: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x808003DC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808003E0: jal         0x80800A1C
    // 0x808003E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_3;
    // 0x808003E4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x808003E8: b           L_8080086C
    // 0x808003EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x808003EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003F0:
    // 0x808003F0: jal         0x80800100
    // 0x808003F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80800100_chcrusherboulder(rdram, ctx);
        goto after_4;
    // 0x808003F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808003F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808003FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800400: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800404: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    // 0x80800408: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8080040C: jal         0x800DA298
    // 0x80800410: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800410: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x80800414: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80800A1C
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_6;
    // 0x80800424: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80800428: b           L_80800438
    // 0x8080042C: nop

        goto L_80800438;
    // 0x8080042C: nop

L_80800430:
    // 0x80800430: jal         0x80800A1C
    // 0x80800434: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_7;
    // 0x80800434: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_80800438:
    // 0x80800438: jal         0x800DA544
    // 0x8080043C: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x8080043C: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    after_8:
    // 0x80800440: jal         0x800DA544
    // 0x80800444: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800444: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_9:
    // 0x80800448: b           L_8080086C
    // 0x8080044C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x8080044C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800450:
    // 0x80800450: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800454: jal         0x80800100
    // 0x80800458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    func_80800100_chcrusherboulder(rdram, ctx);
        goto after_10;
    // 0x80800458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_10:
    // 0x8080045C: jal         0x800898F0
    // 0x80800460: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_11;
    // 0x80800460: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x80800464: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12B0) << 16);
    // 0x80800468: lwc1        $f8, 0x12B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12B0));
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800474: nop

    // 0x80800478: bc1fl       L_8080086C
    if (!c1cs) {
        // 0x8080047C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080086C;
    }
    goto skip_1;
    // 0x8080047C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800480: jal         0x80089848
    // 0x80800484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x8010A800
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_13;
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x80800A1C
    // 0x8080049C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_14;
    // 0x8080049C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x808004A0: b           L_8080086C
    // 0x808004A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x808004A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004A8:
    // 0x808004A8: jal         0x800DA298
    // 0x808004AC: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808004AC: addiu       $a0, $zero, 0x4FB
    ctx->r4 = ADD32(0, 0X4FB);
    after_15:
    // 0x808004B0: beq         $v0, $zero, L_80800868
    if (ctx->r2 == 0) {
        // 0x808004B4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800868;
    }
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808004C0: jal         0x80085708
    // 0x808004C4: addiu       $a3, $zero, 0x4030
    ctx->r7 = ADD32(0, 0X4030);
    _capod_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x808004C4: addiu       $a3, $zero, 0x4030
    ctx->r7 = ADD32(0, 0X4030);
    after_16:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80800A1C
    // 0x808004D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_17;
    // 0x808004D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_17:
    // 0x808004D4: b           L_8080086C
    // 0x808004D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x808004D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004DC:
    // 0x808004DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808004E0: jal         0x80800100
    // 0x808004E4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    func_80800100_chcrusherboulder(rdram, ctx);
        goto after_18;
    // 0x808004E4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_18:
    // 0x808004E8: jal         0x800898F0
    // 0x808004EC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_19;
    // 0x808004EC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_19:
    // 0x808004F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12B4) << 16);
    // 0x808004F4: lwc1        $f16, 0x12B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12B4));
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80800500: nop

    // 0x80800504: bc1f        L_8080052C
    if (!c1cs) {
        // 0x80800508: nop
    
            goto L_8080052C;
    }
    // 0x80800508: nop

    // 0x8080050C: jal         0x80089848
    // 0x80800510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80800510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x8010A800
    // 0x8080051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_21;
    // 0x8080051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x80800A1C
    // 0x80800528: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_22;
    // 0x80800528: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
L_8080052C:
    // 0x8080052C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12B8) << 16);
    // 0x80800530: lwc1        $f18, 0x12B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12B8));
    // 0x80800534: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800540: nop

    // 0x80800544: bc1f        L_80800558
    if (!c1cs) {
        // 0x80800548: nop
    
            goto L_80800558;
    }
    // 0x80800548: nop

    // 0x8080054C: jal         0x80800A1C
    // 0x80800550: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_23;
    // 0x80800550: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_23:
    // 0x80800554: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_80800558:
    // 0x80800558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12BC) << 16);
    // 0x8080055C: lwc1        $f4, 0x12BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12BC));
    // 0x80800560: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12C0) << 16);
    // 0x80800564: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800568: nop

    // 0x8080056C: bc1f        L_80800848
    if (!c1cs) {
        // 0x80800570: nop
    
            goto L_80800848;
    }
    // 0x80800570: nop

    // 0x80800574: lwc1        $f6, 0x12C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12C0));
    // 0x80800578: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080057C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800580: nop

    // 0x80800584: bc1fl       L_808005C0
    if (!c1cs) {
        // 0x80800588: lwc1        $f0, 0x34($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808005C0;
    }
    goto skip_2;
    // 0x80800588: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x8080058C: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800590: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800594: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800598: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080059C: nop

    // 0x808005A0: bc1f        L_808005E8
    if (!c1cs) {
        // 0x808005A4: nop
    
            goto L_808005E8;
    }
    // 0x808005A4: nop

    // 0x808005A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005AC: nop

    // 0x808005B0: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808005B4: b           L_808005E8
    // 0x808005B8: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
        goto L_808005E8;
    // 0x808005B8: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x808005BC: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
L_808005C0:
    // 0x808005C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808005C8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1f        L_808005E8
    if (!c1cs) {
        // 0x808005D4: nop
    
            goto L_808005E8;
    }
    // 0x808005D4: nop

    // 0x808005D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005DC: nop

    // 0x808005E0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808005E4: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_808005E8:
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12C4) << 16);
    // 0x808005EC: lwc1        $f10, 0x12C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12C4));
    // 0x808005F0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808005F4: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x808005F8: nop

    // 0x808005FC: bc1f        L_80800664
    if (!c1cs) {
        // 0x80800600: nop
    
            goto L_80800664;
    }
    // 0x80800600: nop

    // 0x80800604: jal         0x800DC0C0
    // 0x80800608: nop

    func_800DC0C0(rdram, ctx);
        goto after_24;
    // 0x80800608: nop

    after_24:
    // 0x8080060C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12C8) << 16);
    // 0x80800610: lwc1        $f16, 0x12C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12C8));
    // 0x80800614: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800618: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080061C: nop

    // 0x80800620: bc1f        L_80800664
    if (!c1cs) {
        // 0x80800624: nop
    
            goto L_80800664;
    }
    // 0x80800624: nop

    // 0x80800628: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080062C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800630: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800634: jal         0x800DC178
    // 0x80800638: nop

    func_800DC178(rdram, ctx);
        goto after_25;
    // 0x80800638: nop

    after_25:
    // 0x8080063C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800640: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800644: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800648: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8080064C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800650: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800654: jal         0x800DC178
    // 0x80800658: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_26;
    // 0x80800658: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_26:
    // 0x8080065C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80800660: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
L_80800664:
    // 0x80800664: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12CC) << 16);
    // 0x80800668: lwc1        $f8, 0x12CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12CC));
    // 0x8080066C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800670: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80800674: nop

    // 0x80800678: bc1fl       L_808006E0
    if (!c1cs) {
        // 0x8080067C: lw          $t1, 0x74($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X74);
            goto L_808006E0;
    }
    goto skip_3;
    // 0x8080067C: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    skip_3:
    // 0x80800680: jal         0x800DC0C0
    // 0x80800684: nop

    func_800DC0C0(rdram, ctx);
        goto after_27;
    // 0x80800684: nop

    after_27:
    // 0x80800688: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12D0) << 16);
    // 0x8080068C: lwc1        $f16, 0x12D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12D0));
    // 0x80800690: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800694: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800698: nop

    // 0x8080069C: bc1fl       L_808006E0
    if (!c1cs) {
        // 0x808006A0: lw          $t1, 0x74($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X74);
            goto L_808006E0;
    }
    goto skip_4;
    // 0x808006A0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    skip_4:
    // 0x808006A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808006AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006B0: jal         0x800DC178
    // 0x808006B4: nop

    func_800DC178(rdram, ctx);
        goto after_28;
    // 0x808006B4: nop

    after_28:
    // 0x808006B8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808006BC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808006C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808006C4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808006C8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808006CC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006D0: jal         0x800DC178
    // 0x808006D4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_29;
    // 0x808006D4: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_29:
    // 0x808006D8: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808006DC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
L_808006E0:
    // 0x808006E0: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x808006E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12E0) << 16);
    // 0x808006E8: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x808006EC: bgez        $t3, L_80800798
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808006F0: nop
    
            goto L_80800798;
    }
    // 0x808006F0: nop

    // 0x808006F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12D4) << 16);
    // 0x808006F8: lwc1        $f12, 0x12D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12D4));
    // 0x808006FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12D8) << 16);
    // 0x80800700: lwc1        $f14, 0x12D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12D8));
    // 0x80800704: jal         0x800DC178
    // 0x80800708: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    func_800DC178(rdram, ctx);
        goto after_30;
    // 0x80800708: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    after_30:
    // 0x8080070C: jal         0x800D8FF8
    // 0x80800710: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_31;
    // 0x80800710: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x80800714: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80800718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080071C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800720: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800724: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800728: lw          $t5, 0x70($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X70);
    // 0x8080072C: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x80800730: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1640, 0X13A0) << 16);
    // 0x80800734: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80800738: addiu       $a3, $a3, 0x13A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1640, 0X13A0));
    // 0x8080073C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800740: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80800744: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800748: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8080074C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800750: jal         0x80089D68
    // 0x80800754: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_32;
    // 0x80800754: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_32:
    // 0x80800758: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8080075C: lwl         $t7, 0x3B($sp)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r29, 0X3B);
    // 0x80800760: lwr         $t7, 0x3E($sp)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r29, 0X3E);
    // 0x80800764: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80800768: jal         0x800DC0C0
    // 0x8080076C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_33;
    // 0x8080076C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_33:
    // 0x80800770: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12DC) << 16);
    // 0x80800774: lwc1        $f10, 0x12DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12DC));
    // 0x80800778: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080077C: nop

    // 0x80800780: bc1f        L_80800800
    if (!c1cs) {
        // 0x80800784: nop
    
            goto L_80800800;
    }
    // 0x80800784: nop

    // 0x80800788: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
    // 0x8080078C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80800790: b           L_80800800
    // 0x80800794: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
        goto L_80800800;
    // 0x80800794: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_80800798:
    // 0x80800798: lwc1        $f12, 0x12E0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12E0));
    // 0x8080079C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007A4: jal         0x800DC178
    // 0x808007A8: nop

    func_800DC178(rdram, ctx);
        goto after_34;
    // 0x808007A8: nop

    after_34:
    // 0x808007AC: jal         0x800D8FF8
    // 0x808007B0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_35;
    // 0x808007B0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_35:
    // 0x808007B4: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x808007B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007BC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808007C0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808007C4: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808007C8: nop

    // 0x808007CC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808007D0: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x808007D4: jal         0x800DC0C0
    // 0x808007D8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_36;
    // 0x808007D8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_36:
    // 0x808007DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12E4) << 16);
    // 0x808007E0: lwc1        $f8, 0x12E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12E4));
    // 0x808007E4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1f        L_80800800
    if (!c1cs) {
        // 0x808007F0: nop
    
            goto L_80800800;
    }
    // 0x808007F0: nop

    // 0x808007F4: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x808007F8: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x808007FC: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
L_80800800:
    // 0x80800800: jal         0x80800F38
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F38_chcrusherboulder(rdram, ctx);
        goto after_37;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800808: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x8080080C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800810: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x80800814: bltzl       $t5, L_8080086C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800818: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080086C;
    }
    goto skip_5;
    // 0x80800818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8080081C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800820: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800824: lui         $a3, 0x40D0
    ctx->r7 = S32(0X40D0 << 16);
    // 0x80800828: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080082C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800830: jal         0x800187B4
    // 0x80800834: nop

    func_800187B4(rdram, ctx);
        goto after_38;
    // 0x80800834: nop

    after_38:
    // 0x80800838: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x8080083C: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800840: b           L_80800868
    // 0x80800844: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800868;
    // 0x80800844: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80800848:
    // 0x80800848: jal         0x800D8FF8
    // 0x8080084C: nop

    func_800D8FF8(rdram, ctx);
        goto after_39;
    // 0x8080084C: nop

    after_39:
    // 0x80800850: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80800854: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800858: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080085C: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800860: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80800864: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_80800868:
    // 0x80800868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080086C:
    // 0x8080086C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800870: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800874: jr          $ra
    // 0x80800878: nop

    return;
    // 0x80800878: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025B4: lbu         $v0, 0x82($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X82);
    // 0x808025B8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x808025BC: beq         $t6, $zero, L_808025D0
    if (ctx->r14 == 0) {
        // 0x808025C0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808025D0;
    }
    // 0x808025C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808025C4: lh          $v0, 0x74($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X74);
    // 0x808025C8: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x808025CC: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
L_808025D0:
    // 0x808025D0: jr          $ra
    // 0x808025D4: nop

    return;
    // 0x808025D4: nop

;}
RECOMP_FUNC void func_808008D4_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008DC: jal         0x808001A8
    // 0x808008E0: nop

    func_808001A8_bsledge(rdram, ctx);
        goto after_0;
    // 0x808008E0: nop

    after_0:
    // 0x808008E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008EC: jr          $ra
    // 0x808008F0: nop

    return;
    // 0x808008F0: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A60: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A60);
    return;
    // 0x80082A64: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _chtransparentfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087400: syscall     566
    recomp_syscall_handler(rdram, ctx, 0x80087400);
    return;
    // 0x80087404: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801130_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801138: jal         0x80800E48
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800E48_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801140: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x80801144: beq         $at, $zero, L_80801294
    if (ctx->r1 == 0) {
        // 0x80801148: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80801294;
    }
    // 0x80801148: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080114C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80801150: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3F2C) << 16);
    // 0x80801154: addu        $at, $at, $t6
    gpr jr_addend_8080115C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801158: lw          $t6, 0x3F2C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3F2C));
    // 0x8080115C: jr          $t6
    // 0x80801160: nop

    switch (jr_addend_8080115C >> 2) {
        case 0: goto L_80801164; break;
        case 1: goto L_808011AC; break;
        case 2: goto L_808011D4; break;
        case 3: goto L_808011FC; break;
        case 4: goto L_80801224; break;
        case 5: goto L_80801254; break;
        default: switch_error(__func__, 0x8080115C, 0x80803F2C);
    }
    // 0x80801160: nop

L_80801164:
    // 0x80801164: addiu       $a0, $zero, 0x415
    ctx->r4 = ADD32(0, 0X415);
    // 0x80801168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080116C: jal         0x800DA9E4
    // 0x80801170: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA9E4(rdram, ctx);
        goto after_1;
    // 0x80801170: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80801174: bne         $v0, $zero, L_80801194
    if (ctx->r2 != 0) {
        // 0x80801178: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80801194;
    }
    // 0x80801178: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080117C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801180: addiu       $a1, $zero, 0x10C6
    ctx->r5 = ADD32(0, 0X10C6);
    // 0x80801184: jal         0x8080105C
    // 0x80801188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_2;
    // 0x80801188: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8080118C: b           L_80801298
    // 0x80801190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x80801190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801194:
    // 0x80801194: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801198: addiu       $a1, $zero, 0x10C7
    ctx->r5 = ADD32(0, 0X10C7);
    // 0x8080119C: jal         0x8080105C
    // 0x808011A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x808011A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808011A4: b           L_80801298
    // 0x808011A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x808011A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011AC:
    // 0x808011AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808011B0: jal         0x808012A4
    // 0x808011B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x808011B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x808011B8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x808011BC: lh          $a2, 0x75C8($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X75C8);
    // 0x808011C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808011C4: jal         0x800D2054
    // 0x808011C8: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    func_800D2054(rdram, ctx);
        goto after_5;
    // 0x808011C8: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    after_5:
    // 0x808011CC: b           L_80801298
    // 0x808011D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x808011D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011D4:
    // 0x808011D4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808011D8: jal         0x808012A4
    // 0x808011DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_6;
    // 0x808011DC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x808011E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x808011E4: lh          $a2, 0x75C8($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X75C8);
    // 0x808011E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808011EC: jal         0x800D2054
    // 0x808011F0: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    func_800D2054(rdram, ctx);
        goto after_7;
    // 0x808011F0: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    after_7:
    // 0x808011F4: b           L_80801298
    // 0x808011F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x808011F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808011FC:
    // 0x808011FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801200: jal         0x808012A4
    // 0x80801204: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_8;
    // 0x80801204: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_8:
    // 0x80801208: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8080120C: lh          $a2, 0x75C8($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X75C8);
    // 0x80801210: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801214: jal         0x800D2054
    // 0x80801218: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    func_800D2054(rdram, ctx);
        goto after_9;
    // 0x80801218: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    after_9:
    // 0x8080121C: b           L_80801298
    // 0x80801220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x80801220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801224:
    // 0x80801224: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80801228: lh          $a2, 0x75C8($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X75C8);
    // 0x8080122C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801230: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80801234: jal         0x800D2054
    // 0x80801238: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800D2054(rdram, ctx);
        goto after_10;
    // 0x80801238: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_10:
    // 0x8080123C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801240: addiu       $a1, $zero, 0x10E4
    ctx->r5 = ADD32(0, 0X10E4);
    // 0x80801244: jal         0x8080105C
    // 0x80801248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_11;
    // 0x80801248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x8080124C: b           L_80801298
    // 0x80801250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x80801250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801254:
    // 0x80801254: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    // 0x80801258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080125C: jal         0x800DA9E4
    // 0x80801260: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x80801260: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_12:
    // 0x80801264: bne         $v0, $zero, L_80801284
    if (ctx->r2 != 0) {
        // 0x80801268: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80801284;
    }
    // 0x80801268: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080126C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801270: addiu       $a1, $zero, 0x10E2
    ctx->r5 = ADD32(0, 0X10E2);
    // 0x80801274: jal         0x8080105C
    // 0x80801278: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_13;
    // 0x80801278: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x8080127C: b           L_80801298
    // 0x80801280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801298;
    // 0x80801280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801284:
    // 0x80801284: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801288: addiu       $a1, $zero, 0x10E3
    ctx->r5 = ADD32(0, 0X10E3);
    // 0x8080128C: jal         0x8080105C
    // 0x80801290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080105C_chflysaucer(rdram, ctx);
        goto after_14;
    // 0x80801290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
L_80801294:
    // 0x80801294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801298:
    // 0x80801298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080129C: jr          $ra
    // 0x808012A0: nop

    return;
    // 0x808012A0: nop

;}
RECOMP_FUNC void func_80800FE8_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800FEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FF8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800FFC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80801000: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80801004: jal         0x8008A0E0
    // 0x80801008: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801008: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080100C: beq         $v0, $zero, L_80801020
    if (ctx->r2 == 0) {
        // 0x80801010: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801020;
    }
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801014: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801018: jal         0x80085770
    // 0x8080101C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080101C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
L_80801020:
    // 0x80801020: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801028: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080102C: beq         $t6, $at, L_8080104C
    if (ctx->r14 == ctx->r1) {
        // 0x80801030: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080104C;
    }
    // 0x80801030: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801034: beq         $t6, $at, L_80801074
    if (ctx->r14 == ctx->r1) {
        // 0x80801038: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801074;
    }
    // 0x80801038: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080103C: beq         $t6, $at, L_8080109C
    if (ctx->r14 == ctx->r1) {
        // 0x80801040: nop
    
            goto L_8080109C;
    }
    // 0x80801040: nop

    // 0x80801044: b           L_808010BC
    // 0x80801048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808010BC;
    // 0x80801048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080104C:
    // 0x8080104C: jal         0x800878B0
    // 0x80801050: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801050: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80801054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801058: beq         $v0, $at, L_808010B8
    if (ctx->r2 == ctx->r1) {
        // 0x8080105C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808010B8;
    }
    // 0x8080105C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801060: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x80801064: jal         0x800F7BC8
    // 0x80801068: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F7BC8(rdram, ctx);
        goto after_3;
    // 0x80801068: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080106C: b           L_808010BC
    // 0x80801070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808010BC;
    // 0x80801070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801074:
    // 0x80801074: jal         0x80101DDC
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080107C: beq         $v0, $zero, L_808010B8
    if (ctx->r2 == 0) {
        // 0x80801080: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010B8;
    }
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801084: jal         0x80102424
    // 0x80801088: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80801088: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x8080108C: jal         0x800DA544
    // 0x80801090: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80801090: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_6:
    // 0x80801094: b           L_808010BC
    // 0x80801098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808010BC;
    // 0x80801098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080109C:
    // 0x8080109C: jal         0x800F54E4
    // 0x808010A0: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808010A0: nop

    after_7:
    // 0x808010A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010AC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x808010B0: jal         0x800F4F34
    // 0x808010B4: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800F4F34(rdram, ctx);
        goto after_8;
    // 0x808010B4: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_8:
L_808010B8:
    // 0x808010B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808010BC:
    // 0x808010BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808010C4: jr          $ra
    // 0x808010C8: nop

    return;
    // 0x808010C8: nop

;}
RECOMP_FUNC void bskazflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800380: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(232, 0X3B0) << 16);
    // 0x80800384: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800388: jr          $ra
    // 0x8080038C: lw          $v0, 0x3B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(232, 0X3B0));
    return;
    // 0x8080038C: lw          $v0, 0x3B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(232, 0X3B0));
;}
RECOMP_FUNC void _ncbafixpos_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089348: syscall     774
    recomp_syscall_handler(rdram, ctx, 0x80089348);
    return;
    // 0x8008934C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800F28_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800F2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F30: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800F34: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800F38: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800F3C: jal         0x80100094
    // 0x80800F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F44: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800F48: addiu       $a0, $zero, 0x45B
    ctx->r4 = ADD32(0, 0X45B);
    // 0x80800F4C: jal         0x80089C30
    // 0x80800F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800F54: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800F58: lbu         $t6, 0x65($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X65);
    // 0x80800F5C: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    // 0x80800F60: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800F64: jal         0x800DA298
    // 0x80800F68: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800F68: sb          $t7, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r15;
    after_2:
    // 0x80800F6C: bnel        $v0, $zero, L_80801064
    if (ctx->r2 != 0) {
        // 0x80800F70: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801064;
    }
    goto skip_0;
    // 0x80800F70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x80800F74: jal         0x80088840
    // 0x80800F78: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800F78: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_3:
    // 0x80800F7C: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x80800F80: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800F84: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800F88: bne         $v0, $zero, L_80800FE0
    if (ctx->r2 != 0) {
        // 0x80800F8C: sw          $t8, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r24;
            goto L_80800FE0;
    }
    // 0x80800F8C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80800F90: jal         0x800DB9B0
    // 0x80800F94: nop

    func_800DB9B0(rdram, ctx);
        goto after_4;
    // 0x80800F94: nop

    after_4:
    // 0x80800F98: bnel        $v0, $zero, L_80800FE4
    if (ctx->r2 != 0) {
        // 0x80800F9C: addiu       $t9, $zero, 0x2830
        ctx->r25 = ADD32(0, 0X2830);
            goto L_80800FE4;
    }
    goto skip_1;
    // 0x80800F9C: addiu       $t9, $zero, 0x2830
    ctx->r25 = ADD32(0, 0X2830);
    skip_1:
    // 0x80800FA0: jal         0x800DA298
    // 0x80800FA4: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800FA4: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_5:
    // 0x80800FA8: beql        $v0, $zero, L_80800FEC
    if (ctx->r2 == 0) {
        // 0x80800FAC: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80800FEC;
    }
    goto skip_2;
    // 0x80800FAC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80800FB0: jal         0x800EA090
    // 0x80800FB4: nop

    func_800EA090(rdram, ctx);
        goto after_6;
    // 0x80800FB4: nop

    after_6:
    // 0x80800FB8: xori        $v1, $v0, 0xA
    ctx->r3 = ctx->r2 ^ 0XA;
    // 0x80800FBC: sltu        $a0, $zero, $v1
    ctx->r4 = 0 < ctx->r3 ? 1 : 0;
    // 0x80800FC0: beq         $a0, $zero, L_80800FD0
    if (ctx->r4 == 0) {
        // 0x80800FC4: nop
    
            goto L_80800FD0;
    }
    // 0x80800FC4: nop

    // 0x80800FC8: xori        $a0, $v0, 0x6
    ctx->r4 = ctx->r2 ^ 0X6;
    // 0x80800FCC: sltu        $a0, $zero, $a0
    ctx->r4 = 0 < ctx->r4 ? 1 : 0;
L_80800FD0:
    // 0x80800FD0: beql        $a0, $zero, L_80800FEC
    if (ctx->r4 == 0) {
        // 0x80800FD4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_80800FEC;
    }
    goto skip_3;
    // 0x80800FD4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80800FD8: b           L_80800FE8
    // 0x80800FDC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80800FE8;
    // 0x80800FDC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80800FE0:
    // 0x80800FE0: addiu       $t9, $zero, 0x2830
    ctx->r25 = ADD32(0, 0X2830);
L_80800FE4:
    // 0x80800FE4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80800FE8:
    // 0x80800FE8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_80800FEC:
    // 0x80800FEC: bnel        $t0, $zero, L_80801000
    if (ctx->r8 != 0) {
        // 0x80800FF0: lbu         $t2, 0x65($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X65);
            goto L_80801000;
    }
    goto skip_4;
    // 0x80800FF0: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
    skip_4:
    // 0x80800FF4: beql        $s0, $zero, L_80801064
    if (ctx->r16 == 0) {
        // 0x80800FF8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801064;
    }
    goto skip_5;
    // 0x80800FF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_5:
    // 0x80800FFC: lbu         $t2, 0x65($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X65);
L_80801000:
    // 0x80801000: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801004: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801008: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8080100C: jal         0x80102424
    // 0x80801010: sb          $t3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r11;
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80801010: sb          $t3, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r11;
    after_7:
    // 0x80801014: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80801018: jal         0x80101FDC
    // 0x8080101C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x8080101C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80801020: lbu         $t4, 0x65($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X65);
    // 0x80801024: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801028: addiu       $t6, $zero, 0x62
    ctx->r14 = ADD32(0, 0X62);
    // 0x8080102C: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80801030: sb          $t5, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r13;
    // 0x80801034: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801038: addiu       $a1, $zero, 0x12A0
    ctx->r5 = ADD32(0, 0X12A0);
    // 0x8080103C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801040: jal         0x8008A208
    // 0x80801044: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80801044: addiu       $a3, $s1, 0x4
    ctx->r7 = ADD32(ctx->r17, 0X4);
    after_9:
    // 0x80801048: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8080104C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801050: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80801054: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80801058: jal         0x80801D40
    // 0x8080105C: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    func_80801D40_chaliendad(rdram, ctx);
        goto after_10;
    // 0x8080105C: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_10:
    // 0x80801060: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801064:
    // 0x80801064: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80801068:
    // 0x80801068: addiu       $a0, $s0, 0x456
    ctx->r4 = ADD32(ctx->r16, 0X456);
    // 0x8080106C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801070: jal         0x80089C30
    // 0x80801074: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80801074: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_11:
    // 0x80801078: beq         $v0, $zero, L_8080108C
    if (ctx->r2 == 0) {
        // 0x8080107C: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8080108C;
    }
    // 0x8080107C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801080: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80801084: b           L_80801090
    // 0x80801088: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
        goto L_80801090;
    // 0x80801088: sw          $t8, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r24;
L_8080108C:
    // 0x8080108C: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
L_80801090:
    // 0x80801090: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801098: bne         $s0, $at, L_80801068
    if (ctx->r16 != ctx->r1) {
        // 0x8080109C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80801068;
    }
    // 0x8080109C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808010A0: lw          $t9, 0x64($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X64);
    // 0x808010A4: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808010A8: bltzl       $t1, L_80801100
    if (SIGNED(ctx->r9) < 0) {
        // 0x808010AC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801100;
    }
    goto skip_6;
    // 0x808010AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x808010B0: jal         0x800FFAB0
    // 0x808010B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x808010B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_12:
    // 0x808010B8: jal         0x800DA298
    // 0x808010BC: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    func_800DA298(rdram, ctx);
        goto after_13;
    // 0x808010BC: addiu       $a0, $zero, 0x375
    ctx->r4 = ADD32(0, 0X375);
    after_13:
    // 0x808010C0: bne         $v0, $zero, L_808010D8
    if (ctx->r2 != 0) {
        // 0x808010C4: nop
    
            goto L_808010D8;
    }
    // 0x808010C4: nop

    // 0x808010C8: jal         0x800FFAB0
    // 0x808010CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x808010CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x808010D0: b           L_80801100
    // 0x808010D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801100;
    // 0x808010D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010D8:
    // 0x808010D8: jal         0x800DA298
    // 0x808010DC: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808010DC: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    after_15:
    // 0x808010E0: bne         $v0, $zero, L_808010FC
    if (ctx->r2 != 0) {
        // 0x808010E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808010FC;
    }
    // 0x808010E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010E8: jal         0x80801324
    // 0x808010EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801324_chaliendad(rdram, ctx);
        goto after_16;
    // 0x808010EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x808010F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010F4: jal         0x80102424
    // 0x808010F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808010F8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
L_808010FC:
    // 0x808010FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801100:
    // 0x80801100: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801104: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801108: jr          $ra
    // 0x8080110C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8080110C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void chlightdemon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(920, 0X19C) << 16);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $v0, $v0, 0x19C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(920, 0X19C));
    return;
    // 0x80800120: addiu       $v0, $v0, 0x19C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(920, 0X19C));
    // 0x80800124: nop

    // 0x80800128: nop

    // 0x8080012C: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FD0: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FD0);
    return;
    // 0x80082FD4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80803770_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803770: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80803774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803778: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080377C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80803780: jal         0x80100094
    // 0x80803784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803788: lh          $v1, 0xAC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XAC);
    // 0x8080378C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803790: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803794: beq         $v1, $at, L_808038B4
    if (ctx->r3 == ctx->r1) {
        // 0x80803798: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808038B4;
    }
    // 0x80803798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080379C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808037A0: beq         $v1, $at, L_808037C4
    if (ctx->r3 == ctx->r1) {
        // 0x808037A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808037C4;
    }
    // 0x808037A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808037A8: beq         $v1, $at, L_80803830
    if (ctx->r3 == ctx->r1) {
        // 0x808037AC: addiu       $a0, $s0, 0xA4
        ctx->r4 = ADD32(ctx->r16, 0XA4);
            goto L_80803830;
    }
    // 0x808037AC: addiu       $a0, $s0, 0xA4
    ctx->r4 = ADD32(ctx->r16, 0XA4);
    // 0x808037B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808037B4: beq         $v1, $at, L_80803854
    if (ctx->r3 == ctx->r1) {
        // 0x808037B8: nop
    
            goto L_80803854;
    }
    // 0x808037B8: nop

    // 0x808037BC: b           L_808038B4
    // 0x808037C0: nop

        goto L_808038B4;
    // 0x808037C0: nop

L_808037C4:
    // 0x808037C4: jal         0x800D90A4
    // 0x808037C8: addiu       $a0, $s0, 0xA8
    ctx->r4 = ADD32(ctx->r16, 0XA8);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x808037C8: addiu       $a0, $s0, 0xA8
    ctx->r4 = ADD32(ctx->r16, 0XA8);
    after_1:
    // 0x808037CC: addiu       $a0, $s0, 0x88
    ctx->r4 = ADD32(ctx->r16, 0X88);
    // 0x808037D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808037D4: jal         0x80088FA8
    // 0x808037D8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808037D8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x808037DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808037E0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808037E4: jal         0x80088FC8
    // 0x808037E8: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808037E8: lui         $a2, 0x437F
    ctx->r6 = S32(0X437F << 16);
    after_3:
    // 0x808037EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808037F0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x808037F4: nop

    // 0x808037F8: sh          $t7, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r15;
    // 0x808037FC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80803800: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80803804: beq         $t8, $zero, L_80803828
    if (ctx->r24 == 0) {
        // 0x80803808: nop
    
            goto L_80803828;
    }
    // 0x80803808: nop

    // 0x8080380C: jal         0x80088FE0
    // 0x80803810: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    _mlwave_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80803810: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_4:
    // 0x80803814: beq         $v0, $zero, L_80803828
    if (ctx->r2 == 0) {
        // 0x80803818: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80803828;
    }
    // 0x80803818: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8080381C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80803820: sh          $t9, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r25;
    // 0x80803824: sh          $t0, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r8;
L_80803828:
    // 0x80803828: b           L_808038B4
    // 0x8080382C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808038B4;
    // 0x8080382C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80803830:
    // 0x80803830: jal         0x800D90A4
    // 0x80803834: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x80803834: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_5:
    // 0x80803838: beq         $v0, $zero, L_808038B4
    if (ctx->r2 == 0) {
        // 0x8080383C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_808038B4;
    }
    // 0x8080383C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80803840: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80803844: jal         0x808038F8
    // 0x80803848: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_808038F8_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x80803848: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_6:
    // 0x8080384C: b           L_808038B4
    // 0x80803850: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
        goto L_808038B4;
    // 0x80803850: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_80803854:
    // 0x80803854: jal         0x800D90A4
    // 0x80803858: addiu       $a0, $s0, 0xA8
    ctx->r4 = ADD32(ctx->r16, 0XA8);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80803858: addiu       $a0, $s0, 0xA8
    ctx->r4 = ADD32(ctx->r16, 0XA8);
    after_7:
    // 0x8080385C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80803860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803864: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80803868: lwc1        $f12, 0xA8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x8080386C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803870: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80803874: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80803878: jal         0x800F10B4
    // 0x8080387C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8080387C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80803880: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803884: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80803888: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080388C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803890: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80803894: nop

    // 0x80803898: sh          $t2, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r10;
    // 0x8080389C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x808038A0: beql        $t3, $zero, L_808038B4
    if (ctx->r11 == 0) {
        // 0x808038A4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808038B4;
    }
    goto skip_0;
    // 0x808038A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
    // 0x808038A8: jal         0x800BF744
    // 0x808038AC: sh          $t4, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r12;
    func_800BF744(rdram, ctx);
        goto after_9;
    // 0x808038AC: sh          $t4, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r12;
    after_9:
    // 0x808038B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808038B4:
    // 0x808038B4: beql        $a1, $zero, L_808038E8
    if (ctx->r5 == 0) {
        // 0x808038B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808038E8;
    }
    goto skip_1;
    // 0x808038B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808038BC: jal         0x800BEA88
    // 0x808038C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_10;
    // 0x808038C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x808038C4: beq         $v0, $zero, L_808038E4
    if (ctx->r2 == 0) {
        // 0x808038C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808038E4;
    }
    // 0x808038C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808038CC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x808038D0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808038D4: addiu       $a2, $a2, 0x65F0
    ctx->r6 = ADD32(ctx->r6, 0X65F0);
    // 0x808038D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808038DC: jal         0x80088660
    // 0x808038E0: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808038E0: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    after_11:
L_808038E4:
    // 0x808038E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808038E8:
    // 0x808038E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808038EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808038F0: jr          $ra
    // 0x808038F4: nop

    return;
    // 0x808038F4: nop

;}
RECOMP_FUNC void scinfobar_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800314: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800318: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080031C: jal         0x800D8FF8
    // 0x80800320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800320: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800324: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x80800328: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8080032C: beq         $v0, $at, L_808003D0
    if (ctx->r2 == ctx->r1) {
        // 0x80800330: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_808003D0;
    }
    // 0x80800330: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80800334: beq         $v0, $at, L_80800354
    if (ctx->r2 == ctx->r1) {
        // 0x80800338: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_80800354;
    }
    // 0x80800338: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x8080033C: beq         $v0, $at, L_808003D0
    if (ctx->r2 == ctx->r1) {
        // 0x80800340: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_808003D0;
    }
    // 0x80800340: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80800344: beql        $v0, $at, L_8080039C
    if (ctx->r2 == ctx->r1) {
        // 0x80800348: lwc1        $f4, 0x18($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8080039C;
    }
    goto skip_0;
    // 0x80800348: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x8080034C: b           L_808003D4
    // 0x80800350: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
        goto L_808003D4;
    // 0x80800350: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_80800354:
    // 0x80800354: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800358: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8080035C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800360: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800370: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80800374: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800378: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8080037C: nop

    // 0x80800380: bc1fl       L_808003D4
    if (!c1cs) {
        // 0x80800384: sb          $zero, 0xA($s0)
        MEM_B(0XA, ctx->r16) = 0;
            goto L_808003D4;
    }
    goto skip_1;
    // 0x80800384: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    skip_1:
    // 0x80800388: jal         0x80800144
    // 0x8080038C: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    func_80800144_scinfobar(rdram, ctx);
        goto after_1;
    // 0x8080038C: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    after_1:
    // 0x80800390: b           L_808003D4
    // 0x80800394: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
        goto L_808003D4;
    // 0x80800394: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x80800398: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
L_8080039C:
    // 0x8080039C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808003A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808003A4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808003B0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x808003B4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808003B8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808003BC: nop

    // 0x808003C0: bc1fl       L_808003D4
    if (!c1cs) {
        // 0x808003C4: sb          $zero, 0xA($s0)
        MEM_B(0XA, ctx->r16) = 0;
            goto L_808003D4;
    }
    goto skip_2;
    // 0x808003C4: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    skip_2:
    // 0x808003C8: jal         0x80800144
    // 0x808003CC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_80800144_scinfobar(rdram, ctx);
        goto after_2;
    // 0x808003CC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_2:
L_808003D0:
    // 0x808003D0: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_808003D4:
    // 0x808003D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E0: jr          $ra
    // 0x808003E4: nop

    return;
    // 0x808003E4: nop

;}
RECOMP_FUNC void func_800F7AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7AFC: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x800F7B00: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800F7B04: jal         0x800F7B1C
    // 0x800F7B08: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F7B1C(rdram, ctx);
        goto after_0;
    // 0x800F7B08: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_0:
    // 0x800F7B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7B14: jr          $ra
    // 0x800F7B18: nop

    return;
    // 0x800F7B18: nop

;}
RECOMP_FUNC void func_808003E4_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808003E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003EC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x808003F0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808003F4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808003F8: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x808003FC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800400: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800404: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800408: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080040C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800410: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800414: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800418: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8080041C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800420: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800424: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800428: jal         0x8008FE94
    // 0x8080042C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_8008FE94(rdram, ctx);
        goto after_0;
    // 0x8080042C: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80800430: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800434: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800438: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080043C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800440: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800444: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800448: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080044C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80800450: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800454: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800458: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8080045C: lwc1        $f8, 0x1C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80800460: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80800464: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80800468: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080046C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800470: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80800474: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80800478: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8080047C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80800480: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800484: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80800488: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800490: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80800494: bc1f        L_808004F8
    if (!c1cs) {
        // 0x80800498: swc1        $f10, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
            goto L_808004F8;
    }
    // 0x80800498: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8080049C: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x808004A0: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808004A4: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004AC: nop

    // 0x808004B0: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808004B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_0;
    // 0x808004B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004B8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808004BC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004C0: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808004C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_1;
    // 0x808004C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808004C8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808004CC: nop

    // 0x808004D0: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808004D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_2;
    // 0x808004D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808004D8: lbu         $t7, 0x65($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X65);
    // 0x808004DC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808004E0: jal         0x80090150
    // 0x808004E4: sb          $t8, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r24;
    func_80090150(rdram, ctx);
        goto after_1;
    // 0x808004E4: sb          $t8, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r24;
    after_1:
    // 0x808004E8: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_3;
    // 0x808004EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808004F0: jal         0x800904C8
    // 0x808004F4: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    func_800904C8(rdram, ctx);
        goto after_2;
    // 0x808004F4: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    after_2:
L_808004F8:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004FC:
    // 0x808004FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void func_800E4C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E4C80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E4C84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E4C88: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E4C8C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800E4C90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E4C94: addiu       $s1, $s1, -0x2A90
    ctx->r17 = ADD32(ctx->r17, -0X2A90);
    // 0x800E4C98: addiu       $s0, $s0, -0x2AA0
    ctx->r16 = ADD32(ctx->r16, -0X2AA0);
    // 0x800E4C9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800E4CA0:
    // 0x800E4CA0: beql        $a0, $zero, L_800E4CB8
    if (ctx->r4 == 0) {
        // 0x800E4CA4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800E4CB8;
    }
    goto skip_0;
    // 0x800E4CA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800E4CA8: jal         0x8001BAFC
    // 0x800E4CAC: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800E4CAC: nop

    after_0:
    // 0x800E4CB0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800E4CB4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800E4CB8:
    // 0x800E4CB8: bnel        $s0, $s1, L_800E4CA0
    if (ctx->r16 != ctx->r17) {
        // 0x800E4CBC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_800E4CA0;
    }
    goto skip_1;
    // 0x800E4CBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800E4CC0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800E4CC4: addiu       $s0, $s0, -0x2A90
    ctx->r16 = ADD32(ctx->r16, -0X2A90);
    // 0x800E4CC8: jal         0x8001BAFC
    // 0x800E4CCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    defrag(rdram, ctx);
        goto after_1;
    // 0x800E4CCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800E4CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E4CD4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800E4CD8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E4CDC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E4CE0: jr          $ra
    // 0x800E4CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E4CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800DE1C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE1C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DE1C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DE1CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DE1D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800DE1D4: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800DE1D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DE1DC: jal         0x80018BA8
    // 0x800DE1E0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    mlMtx_get_stack_pointer(rdram, ctx);
        goto after_0;
    // 0x800DE1E0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_0:
    // 0x800DE1E4: jal         0x80018BB4
    // 0x800DE1E8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80018BB4(rdram, ctx);
        goto after_1;
    // 0x800DE1E8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x800DE1EC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800DE1F0: lh          $t7, 0xE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XE);
    // 0x800DE1F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800DE1F8: beq         $t7, $zero, L_800DE244
    if (ctx->r15 == 0) {
        // 0x800DE1FC: nop
    
            goto L_800DE244;
    }
    // 0x800DE1FC: nop

    // 0x800DE200: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800DE204: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x800DE208: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x800DE20C: beq         $t0, $zero, L_800DE244
    if (ctx->r8 == 0) {
        // 0x800DE210: nop
    
            goto L_800DE244;
    }
    // 0x800DE210: nop

    // 0x800DE214: lh          $a2, 0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XA);
    // 0x800DE218: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800DE21C: beql        $a2, $zero, L_800DE230
    if (ctx->r6 == 0) {
        // 0x800DE220: lh          $a2, 0xC($s0)
        ctx->r6 = MEM_H(ctx->r16, 0XC);
            goto L_800DE230;
    }
    goto skip_0;
    // 0x800DE220: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    skip_0:
    // 0x800DE224: jal         0x8010F070
    // 0x800DE228: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8010F070(rdram, ctx);
        goto after_2;
    // 0x800DE228: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x800DE22C: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
L_800DE230:
    // 0x800DE230: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800DE234: beq         $a2, $zero, L_800DE244
    if (ctx->r6 == 0) {
        // 0x800DE238: nop
    
            goto L_800DE244;
    }
    // 0x800DE238: nop

    // 0x800DE23C: jal         0x8010F070
    // 0x800DE240: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8010F070(rdram, ctx);
        goto after_3;
    // 0x800DE240: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
L_800DE244:
    // 0x800DE244: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DE248: lw          $v0, -0x313C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X313C);
    // 0x800DE24C: beql        $v0, $zero, L_800DE294
    if (ctx->r2 == 0) {
        // 0x800DE250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DE294;
    }
    goto skip_1;
    // 0x800DE250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DE254: lh          $a2, 0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XA);
    // 0x800DE258: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800DE25C: beql        $a2, $zero, L_800DE270
    if (ctx->r6 == 0) {
        // 0x800DE260: lh          $a2, 0xC($s0)
        ctx->r6 = MEM_H(ctx->r16, 0XC);
            goto L_800DE270;
    }
    goto skip_2;
    // 0x800DE260: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    skip_2:
    // 0x800DE264: jalr        $v0
    // 0x800DE268: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x800DE268: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x800DE26C: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
L_800DE270:
    // 0x800DE270: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DE274: beql        $a2, $zero, L_800DE294
    if (ctx->r6 == 0) {
        // 0x800DE278: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DE294;
    }
    goto skip_3;
    // 0x800DE278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800DE27C: lw          $t9, -0x313C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X313C);
    // 0x800DE280: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800DE284: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800DE288: jalr        $t9
    // 0x800DE28C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800DE28C: nop

    after_5:
    // 0x800DE290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DE294:
    // 0x800DE294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DE298: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800DE29C: jr          $ra
    // 0x800DE2A0: nop

    return;
    // 0x800DE2A0: nop

;}
RECOMP_FUNC void chfactoryworkerdirty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B78: jal         0x80106790
    // 0x80800B7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800B7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800B80: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B8C: beq         $a1, $at, L_80800BB4
    if (ctx->r5 == ctx->r1) {
        // 0x80800B90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800BB4;
    }
    // 0x80800B90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800B94: beq         $a1, $at, L_80800BC4
    if (ctx->r5 == ctx->r1) {
        // 0x80800B98: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800BC4;
    }
    // 0x80800B98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B9C: beq         $a1, $at, L_80800BD4
    if (ctx->r5 == ctx->r1) {
        // 0x80800BA0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800BD4;
    }
    // 0x80800BA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800BA4: beq         $a1, $at, L_80800BE4
    if (ctx->r5 == ctx->r1) {
        // 0x80800BA8: nop
    
            goto L_80800BE4;
    }
    // 0x80800BA8: nop

    // 0x80800BAC: b           L_80800BF0
    // 0x80800BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF0;
    // 0x80800BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BB4:
    // 0x80800BB4: jal         0x808000AC
    // 0x80800BB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800BB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800BBC: b           L_80800BF0
    // 0x80800BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF0;
    // 0x80800BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BC4:
    // 0x80800BC4: jal         0x808000AC
    // 0x80800BC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_2;
    // 0x80800BC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800BCC: b           L_80800BF0
    // 0x80800BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF0;
    // 0x80800BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BD4:
    // 0x80800BD4: jal         0x808000AC
    // 0x80800BD8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_3;
    // 0x80800BD8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800BDC: b           L_80800BF0
    // 0x80800BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800BF0;
    // 0x80800BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BE4:
    // 0x80800BE4: jal         0x808000AC
    // 0x80800BE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_4;
    // 0x80800BE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x80800BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800BF0:
    // 0x80800BF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: nop

    return;
    // 0x80800BF8: nop

;}
RECOMP_FUNC void chterryteeth_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2008, 0X1A4) << 16);
    // 0x80800140: jr          $ra
    // 0x80800144: addiu       $v0, $v0, 0x1A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2008, 0X1A4));
    return;
    // 0x80800144: addiu       $v0, $v0, 0x1A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2008, 0X1A4));
;}
RECOMP_FUNC void _bskazglide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833F0: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x800833F0);
    return;
    // 0x800833F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bstntswim_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800984: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800988: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(408, 0X9F0) << 16);
    // 0x8080098C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800990: jr          $ra
    // 0x80800994: lw          $v0, 0x9F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9F0));
    return;
    // 0x80800994: lw          $v0, 0x9F0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(408, 0X9F0));
    // 0x80800998: nop

    // 0x8080099C: nop

;}
RECOMP_FUNC void _chdippy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086480: syscall     327
    recomp_syscall_handler(rdram, ctx, 0x80086480);
    return;
    // 0x80086484: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chdiggerbossshell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867F8: syscall     380
    recomp_syscall_handler(rdram, ctx, 0x800867F8);
    return;
    // 0x800867FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_chlightfader(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808019EC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019F4: jal         0x800A4D40
    // 0x808019F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4D40(rdram, ctx);
        goto after_0;
    // 0x808019F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808019FC: beql        $v0, $zero, L_80801A28
    if (ctx->r2 == 0) {
        // 0x80801A00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A28;
    }
    goto skip_0;
    // 0x80801A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801A04: jal         0x800A5090
    // 0x80801A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A5090(rdram, ctx);
        goto after_1;
    // 0x80801A08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801A0C: beql        $v0, $zero, L_80801A28
    if (ctx->r2 == 0) {
        // 0x80801A10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A28;
    }
    goto skip_1;
    // 0x80801A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801A14: jal         0x808019B0
    // 0x80801A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808019B0_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80801A18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801A1C: jal         0x8080175C
    // 0x80801A20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080175C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80801A20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A28:
    // 0x80801A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A2C: jr          $ra
    // 0x80801A30: nop

    return;
    // 0x80801A30: nop

;}
RECOMP_FUNC void _chjamjarsdummy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086958: syscall     399
    recomp_syscall_handler(rdram, ctx, 0x80086958);
    return;
    // 0x8008695C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801870_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801874: andi        $t6, $a3, 0x1
    ctx->r14 = ctx->r7 & 0X1;
    // 0x80801878: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8080187C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801884: or          $a1, $t7, $a1
    ctx->r5 = ctx->r15 | ctx->r5;
    // 0x80801888: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080188C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801890: jal         0x800BEA88
    // 0x80801894: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x80801894: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801898: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080189C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808018A0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808018A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808018A8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808018AC: subu        $a1, $t9, $t0
    ctx->r5 = SUB32(ctx->r25, ctx->r8);
    // 0x808018B0: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
    // 0x808018B4: addiu       $a2, $a2, 0x75B0
    ctx->r6 = ADD32(ctx->r6, 0X75B0);
    // 0x808018B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808018BC: jal         0x80088660
    // 0x808018C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808018C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808018C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018CC: jr          $ra
    // 0x808018D0: nop

    return;
    // 0x808018D0: nop

;}
