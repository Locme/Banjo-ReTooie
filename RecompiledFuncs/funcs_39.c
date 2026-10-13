#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void scinfobar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800234: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080023C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800240: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800244: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800248: jal         0x8001ACCC
    // 0x8080024C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080024C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_0:
    // 0x80800250: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80800254: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80800258: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8080025C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800264: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x80800268: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x8080026C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800274: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80800278: sb          $zero, 0xA($v0)
    MEM_B(0XA, ctx->r2) = 0;
    // 0x8080027C: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x80800280: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80800284: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800288: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080028C: jal         0x808003E8
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scinfobar_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800290: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80800530
    // 0x8080029C: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    scinfobar_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x8080029C: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    after_2:
    // 0x808002A0: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x808002A4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x808002A8: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x808002AC: jal         0x808000B0
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B0_scinfobar(rdram, ctx);
        goto after_3;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80800000
    // 0x808002BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800000_scinfobar(rdram, ctx);
        goto after_4;
    // 0x808002BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chfantasycannon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C6C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2392, 0XD78) << 16);
    // 0x80800C70: jr          $ra
    // 0x80800C74: addiu       $v0, $v0, 0xD78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2392, 0XD78));
    return;
    // 0x80800C74: addiu       $v0, $v0, 0xD78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2392, 0XD78));
    // 0x80800C78: nop

    // 0x80800C7C: nop

;}
RECOMP_FUNC void _chufoextdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087128: syscall     519
    recomp_syscall_handler(rdram, ctx, 0x80087128);
    return;
    // 0x8008712C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80806A88_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806A88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806A90: jal         0x80088338
    // 0x80806A94: nop

    _gcstatusDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80806A94: nop

    after_0:
    // 0x80806A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806AA0: jr          $ra
    // 0x80806AA4: nop

    return;
    // 0x80806AA4: nop

;}
RECOMP_FUNC void func_80800374_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800374: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080037C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800380: jal         0x8008FE68
    // 0x80800384: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800384: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800388: lui         $at, 0x44C5
    ctx->r1 = S32(0X44C5 << 16);
    // 0x8080038C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800390: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800398: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8080039C: nop

    // 0x808003A0: bc1f        L_808003AC
    if (!c1cs) {
        // 0x808003A4: nop
    
            goto L_808003AC;
    }
    // 0x808003A4: nop

    // 0x808003A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003AC:
    // 0x808003AC: beql        $v0, $zero, L_808003C8
    if (ctx->r2 == 0) {
        // 0x808003B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003C8;
    }
    goto skip_0;
    // 0x808003B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003B4: jal         0x8008FD48
    // 0x808003B8: nop

    func_8008FD48(rdram, ctx);
        goto after_1;
    // 0x808003B8: nop

    after_1:
    // 0x808003BC: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x808003C0: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C8:
    // 0x808003C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void func_800FA934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA934: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA938: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA93C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA940: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA944: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA948: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA94C: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x800FA950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FA954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA958: beq         $a2, $zero, L_800FA96C
    if (ctx->r6 == 0) {
        // 0x800FA95C: nop
    
            goto L_800FA96C;
    }
    // 0x800FA95C: nop

    // 0x800FA960: lb          $t8, 0xE($v1)
    ctx->r24 = MEM_B(ctx->r3, 0XE);
    // 0x800FA964: beql        $a1, $t8, L_800FA978
    if (ctx->r5 == ctx->r24) {
        // 0x800FA968: lbu         $v0, 0xC($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XC);
            goto L_800FA978;
    }
    goto skip_0;
    // 0x800FA968: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
    skip_0:
L_800FA96C:
    // 0x800FA96C: b           L_800FA998
    // 0x800FA970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800FA998;
    // 0x800FA970: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800FA974: lbu         $v0, 0xC($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XC);
L_800FA978:
    // 0x800FA978: xori        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 ^ 0X2;
    // 0x800FA97C: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x800FA980: beql        $v0, $zero, L_800FA99C
    if (ctx->r2 == 0) {
        // 0x800FA984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA99C;
    }
    goto skip_1;
    // 0x800FA984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800FA988: jal         0x8008A628
    // 0x800FA98C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _scinfobar_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x800FA98C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800FA990: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x800FA994: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800FA998:
    // 0x800FA998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA99C:
    // 0x800FA99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FA9A0: jr          $ra
    // 0x800FA9A4: nop

    return;
    // 0x800FA9A4: nop

;}
RECOMP_FUNC void chcredits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080119C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1636, 0X159C) << 16);
    // 0x808011A0: jr          $ra
    // 0x808011A4: addiu       $v0, $v0, 0x159C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1636, 0X159C));
    return;
    // 0x808011A4: addiu       $v0, $v0, 0x159C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1636, 0X159C));
    // 0x808011A8: nop

    // 0x808011AC: nop

;}
RECOMP_FUNC void chfactoryworkerdirty_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C58: jal         0x80106790
    // 0x80800C5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800C5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800C60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C64: jal         0x80100094
    // 0x80800C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800C6C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800C70: jal         0x8010105C
    // 0x80800C74: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_8010105C(rdram, ctx);
        goto after_2;
    // 0x80800C74: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800C80: jal         0x80800068
    // 0x80800C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800068_chfactoryworkerdirty(rdram, ctx);
        goto after_3;
    // 0x80800C84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C90: jr          $ra
    // 0x80800C94: nop

    return;
    // 0x80800C94: nop

;}
RECOMP_FUNC void func_80800F4C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F54: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800F58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F5C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800F60: beq         $t6, $zero, L_80800F78
    if (ctx->r14 == 0) {
        // 0x80800F64: nop
    
            goto L_80800F78;
    }
    // 0x80800F64: nop

    // 0x80800F68: beq         $t6, $at, L_80800F78
    if (ctx->r14 == ctx->r1) {
        // 0x80800F6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F78;
    }
    // 0x80800F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F70: bne         $t6, $at, L_80800F88
    if (ctx->r14 != ctx->r1) {
        // 0x80800F74: nop
    
            goto L_80800F88;
    }
    // 0x80800F74: nop

L_80800F78:
    // 0x80800F78: jal         0x8008A4B0
    // 0x80800F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F80: b           L_80800F94
    // 0x80800F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F94;
    // 0x80800F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F88:
    // 0x80800F88: jal         0x8008A4B0
    // 0x80800F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800F90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F94:
    // 0x80800F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F98: jr          $ra
    // 0x80800F9C: nop

    return;
    // 0x80800F9C: nop

;}
RECOMP_FUNC void func_80800174_chfog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800180: jal         0x800EA05C
    // 0x80800184: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800184: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800188: addiu       $at, $zero, 0xDB
    ctx->r1 = ADD32(0, 0XDB);
    // 0x8080018C: beq         $v0, $at, L_808001F4
    if (ctx->r2 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0x10D
        ctx->r1 = ADD32(0, 0X10D);
            goto L_808001F4;
    }
    // 0x80800190: addiu       $at, $zero, 0x10D
    ctx->r1 = ADD32(0, 0X10D);
    // 0x80800194: beq         $v0, $at, L_808001C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800198: addiu       $a0, $zero, 0x416
        ctx->r4 = ADD32(0, 0X416);
            goto L_808001C8;
    }
    // 0x80800198: addiu       $a0, $zero, 0x416
    ctx->r4 = ADD32(0, 0X416);
    // 0x8080019C: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x808001A0: beq         $v0, $at, L_80800238
    if (ctx->r2 == ctx->r1) {
        // 0x808001A4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800238;
    }
    // 0x808001A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001A8: addiu       $at, $zero, 0x162
    ctx->r1 = ADD32(0, 0X162);
    // 0x808001AC: beq         $v0, $at, L_80800248
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800248;
    }
    // 0x808001B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001B4: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x808001B8: beq         $v0, $at, L_80800258
    if (ctx->r2 == ctx->r1) {
        // 0x808001BC: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800258;
    }
    // 0x808001BC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001C0: b           L_80800268
    // 0x808001C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
        goto L_80800268;
    // 0x808001C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_808001C8:
    // 0x808001C8: jal         0x80089C30
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808001D0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001E0;
    }
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D8: jal         0x80101870
    // 0x808001DC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x808001DC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_2:
L_808001E0:
    // 0x808001E0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808001E4: jal         0x800DF744
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808001E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001EC: b           L_80800270
    // 0x808001F0: nop

        goto L_80800270;
    // 0x808001F0: nop

L_808001F4:
    // 0x808001F4: addiu       $a0, $zero, 0x176
    ctx->r4 = ADD32(0, 0X176);
    // 0x808001F8: jal         0x80089C30
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800200: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_80800224;
    }
    // 0x80800204: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800208: jal         0x80101074
    // 0x8080020C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80101074(rdram, ctx);
        goto after_5;
    // 0x8080020C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800210: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800214: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
    // 0x80800218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080021C: jal         0x8010114C
    // 0x80800220: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_8010114C(rdram, ctx);
        goto after_6;
    // 0x80800220: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_6:
L_80800224:
    // 0x80800224: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800228: jal         0x800DF744
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800230: b           L_80800270
    // 0x80800234: nop

        goto L_80800270;
    // 0x80800234: nop

L_80800238:
    // 0x80800238: jal         0x800DF744
    // 0x8080023C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x8080023C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800240: b           L_80800270
    // 0x80800244: nop

        goto L_80800270;
    // 0x80800244: nop

L_80800248:
    // 0x80800248: jal         0x800DF744
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x8080024C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800250: b           L_80800270
    // 0x80800254: nop

        goto L_80800270;
    // 0x80800254: nop

L_80800258:
    // 0x80800258: jal         0x800DF744
    // 0x8080025C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x8080025C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800260: b           L_80800270
    // 0x80800264: nop

        goto L_80800270;
    // 0x80800264: nop

L_80800268:
    // 0x80800268: jal         0x800DF744
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x8080026C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
L_80800270:
    // 0x80800270: jal         0x800E41CC
    // 0x80800274: nop

    func_800E41CC(rdram, ctx);
        goto after_12;
    // 0x80800274: nop

    after_12:
    // 0x80800278: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080027C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800280: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x80800284: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800288: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080028C: jal         0x800EFA4C
    // 0x80800290: nop

    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x80800290: nop

    after_13:
    // 0x80800294: jal         0x800EFD24
    // 0x80800298: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_14;
    // 0x80800298: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_14:
    // 0x8080029C: jal         0x800E3BAC
    // 0x808002A0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800E3BAC(rdram, ctx);
        goto after_15;
    // 0x808002A0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x808002A4: jal         0x800E3C30
    // 0x808002A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800E3C30(rdram, ctx);
        goto after_16;
    // 0x808002A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_16:
    // 0x808002AC: jal         0x800E3CE8
    // 0x808002B0: nop

    func_800E3CE8(rdram, ctx);
        goto after_17;
    // 0x808002B0: nop

    after_17:
    // 0x808002B4: jal         0x800E44FC
    // 0x808002B8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800E44FC(rdram, ctx);
        goto after_18;
    // 0x808002B8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_18:
    // 0x808002BC: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808002C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002C4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808002C8: jal         0x80089C90
    // 0x808002CC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x808002CC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x808002D0: jal         0x800DF410
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_20;
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x808002D8: jal         0x800DF830
    // 0x808002DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_21;
    // 0x808002DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
    // 0x808002E0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x808002E4: jal         0x8010347C
    // 0x808002E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8010347C(rdram, ctx);
        goto after_22;
    // 0x808002E8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_22:
    // 0x808002EC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808002F0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808002F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808002F8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808002FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800300: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800304: jal         0x800DE448
    // 0x80800308: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800DE448(rdram, ctx);
        goto after_23;
    // 0x80800308: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_23:
    // 0x8080030C: jal         0x800E4208
    // 0x80800310: nop

    func_800E4208(rdram, ctx);
        goto after_24;
    // 0x80800310: nop

    after_24:
    // 0x80800314: jal         0x800E44FC
    // 0x80800318: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800E44FC(rdram, ctx);
        goto after_25;
    // 0x80800318: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_25:
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800320: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void func_80800170_chtnthut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800178: jal         0x80101080
    // 0x8080017C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x8080017C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800180: jal         0x80106790
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800188: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080018C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800190: jal         0x800866B8
    // 0x80800194: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800194: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x80800198: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080019C: jal         0x800866C0
    // 0x808001A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x808001A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808001A4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(908, 0X2D8) << 16);
    // 0x808001A8: addiu       $a1, $a1, 0x2D8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(908, 0X2D8));
    // 0x808001AC: jal         0x800866A8
    // 0x808001B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808001B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808001B4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808001B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(908, 0X268) << 16);
    // 0x808001C0: addiu       $t6, $t6, 0x268
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(908, 0X268));
    // 0x808001C4: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x808001C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001D0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808001D4: jal         0x800BABB8
    // 0x808001D8: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x808001D8: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_5:
    // 0x808001DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001E0: jal         0x80101FDC
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001EC: jal         0x80103110
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808001F4: jal         0x800DA544
    // 0x808001F8: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x808001F8: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_8:
    // 0x808001FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

    // 0x8080020C: nop

;}
RECOMP_FUNC void func_800D66AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D66AC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D66B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D66B4: addiu       $v0, $v0, -0x41A0
    ctx->r2 = ADD32(ctx->r2, -0X41A0);
    // 0x800D66B8: addiu       $v1, $v1, -0x4800
    ctx->r3 = ADD32(ctx->r3, -0X4800);
L_800D66BC:
    // 0x800D66BC: lbu         $t1, 0xF($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XF);
    // 0x800D66C0: lhu         $t4, 0x14($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X14);
    // 0x800D66C4: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x800D66C8: lhu         $t9, 0x8($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X8);
    // 0x800D66CC: andi        $t2, $t1, 0xFFE1
    ctx->r10 = ctx->r9 & 0XFFE1;
    // 0x800D66D0: ori         $t5, $t4, 0xFFFC
    ctx->r13 = ctx->r12 | 0XFFFC;
    // 0x800D66D4: andi        $t7, $t6, 0xFFE1
    ctx->r15 = ctx->r14 & 0XFFE1;
    // 0x800D66D8: ori         $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 | 0XFFFC;
    // 0x800D66DC: lhu         $t9, 0x20($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X20);
    // 0x800D66E0: lbu         $t6, 0x1B($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1B);
    // 0x800D66E4: lhu         $t4, 0x2C($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X2C);
    // 0x800D66E8: lbu         $t1, 0x27($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X27);
    // 0x800D66EC: sh          $t5, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r13;
    // 0x800D66F0: sb          $t2, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r10;
    // 0x800D66F4: sb          $t7, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r15;
    // 0x800D66F8: sh          $t0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r8;
    // 0x800D66FC: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x800D6700: ori         $t0, $t9, 0xFFFC
    ctx->r8 = ctx->r25 | 0XFFFC;
    // 0x800D6704: andi        $t7, $t6, 0xFFE1
    ctx->r15 = ctx->r14 & 0XFFE1;
    // 0x800D6708: ori         $t5, $t4, 0xFFFC
    ctx->r13 = ctx->r12 | 0XFFFC;
    // 0x800D670C: andi        $t2, $t1, 0xFFE1
    ctx->r10 = ctx->r9 & 0XFFE1;
    // 0x800D6710: sb          $t2, -0x9($v1)
    MEM_B(-0X9, ctx->r3) = ctx->r10;
    // 0x800D6714: sh          $t5, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r13;
    // 0x800D6718: sb          $t7, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r15;
    // 0x800D671C: sh          $t0, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r8;
    // 0x800D6720: sw          $zero, -0x20($v1)
    MEM_W(-0X20, ctx->r3) = 0;
    // 0x800D6724: sw          $zero, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = 0;
    // 0x800D6728: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800D672C: bne         $v1, $v0, L_800D66BC
    if (ctx->r3 != ctx->r2) {
        // 0x800D6730: sw          $zero, -0x2C($v1)
        MEM_W(-0X2C, ctx->r3) = 0;
            goto L_800D66BC;
    }
    // 0x800D6730: sw          $zero, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = 0;
    // 0x800D6734: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800D6738: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D673C: sh          $t6, -0x46F0($at)
    MEM_H(-0X46F0, ctx->r1) = ctx->r14;
    // 0x800D6740: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6744: jr          $ra
    // 0x800D6748: sh          $zero, -0x419E($at)
    MEM_H(-0X419E, ctx->r1) = 0;
    return;
    // 0x800D6748: sh          $zero, -0x419E($at)
    MEM_H(-0X419E, ctx->r1) = 0;
;}
RECOMP_FUNC void func_8010BB5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BB5C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010BB60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010BB64: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010BB68: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8010BB6C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8010BB70: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010BB74: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8010BB78: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010BB7C: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8010BB80: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x8010BB84: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8010BB88: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8010BB8C: nop

    // 0x8010BB90: bc1fl       L_8010BBA4
    if (!c1cs) {
        // 0x8010BB94: add.s       $f8, $f2, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
            goto L_8010BBA4;
    }
    goto skip_0;
    // 0x8010BB94: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    skip_0:
    // 0x8010BB98: b           L_8010BCB4
    // 0x8010BB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010BCB4;
    // 0x8010BB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010BBA0: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
L_8010BBA4:
    // 0x8010BBA4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8010BBA8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8010BBAC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8010BBB0: nop

    // 0x8010BBB4: bc1fl       L_8010BBC8
    if (!c1cs) {
        // 0x8010BBB8: lwc1        $f10, 0x0($t8)
        ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
            goto L_8010BBC8;
    }
    goto skip_1;
    // 0x8010BBB8: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    skip_1:
    // 0x8010BBBC: b           L_8010BCB4
    // 0x8010BBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010BCB4;
    // 0x8010BBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010BBC4: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
L_8010BBC8:
    // 0x8010BBC8: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8010BBCC: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8010BBD0: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8010BBD4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010BBD8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010BBDC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8010BBE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8010BBE4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8010BBE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8010BBEC: jal         0x800EFA4C
    // 0x8010BBF0: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8010BBF0: nop

    after_0:
    // 0x8010BBF4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8010BBF8: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010BBFC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8010BC00: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8010BC04: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010BC08: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8010BC0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8010BC10: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8010BC14: add.s       $f20, $f4, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8010BC18: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8010BC1C: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x8010BC20: nop

    // 0x8010BC24: bc1f        L_8010BC34
    if (!c1cs) {
        // 0x8010BC28: nop
    
            goto L_8010BC34;
    }
    // 0x8010BC28: nop

    // 0x8010BC2C: b           L_8010BCB4
    // 0x8010BC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010BCB4;
    // 0x8010BC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010BC34:
    // 0x8010BC34: jal         0x8002DCA0
    // 0x8010BC38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8010BC38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8010BC3C: jal         0x800D8FF8
    // 0x8010BC40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8010BC40: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x8010BC44: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8010BC48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010BC4C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010BC50: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010BC54: jal         0x800F13F0
    // 0x8010BC58: sub.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f20.fl;
    func_800F13F0(rdram, ctx);
        goto after_3;
    // 0x8010BC58: sub.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f20.fl;
    after_3:
    // 0x8010BC5C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8010BC60: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8010BC64: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x8010BC68: nop

    // 0x8010BC6C: bc1fl       L_8010BC9C
    if (!c1cs) {
        // 0x8010BC70: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_8010BC9C;
    }
    goto skip_2;
    // 0x8010BC70: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    skip_2:
    // 0x8010BC74: jal         0x800DC0C0
    // 0x8010BC78: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x8010BC78: nop

    after_4:
    // 0x8010BC7C: jal         0x800DC0C0
    // 0x8010BC80: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x8010BC80: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8010BC84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010BC88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010BC8C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010BC90: jal         0x800EFA4C
    // 0x8010BC94: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x8010BC94: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x8010BC98: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
L_8010BC9C:
    // 0x8010BC9C: jal         0x800EF368
    // 0x8010BCA0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x8010BCA0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x8010BCA4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8010BCA8: jal         0x800EF04C
    // 0x8010BCAC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x8010BCAC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x8010BCB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010BCB4:
    // 0x8010BCB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010BCB8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010BCBC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010BCC0: jr          $ra
    // 0x8010BCC4: nop

    return;
    // 0x8010BCC4: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083230: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083230);
    return;
    // 0x80083234: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801044_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801044: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801048: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080104C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801050: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801054: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801058: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8080105C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801064: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801068: nop

    // 0x8080106C: bc1fl       L_8080110C
    if (!c1cs) {
        // 0x80801070: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080110C;
    }
    goto skip_0;
    // 0x80801070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801078: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080107C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801080: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801084: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801088: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080108C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801090: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801094: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80801098: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8080109C: jal         0x800F10B4
    // 0x808010A0: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808010A0: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    after_0:
    // 0x808010A4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808010A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808010AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808010B0: bne         $a0, $zero, L_808010D0
    if (ctx->r4 != 0) {
        // 0x808010B4: lui         $a2, 0x4040
        ctx->r6 = S32(0X4040 << 16);
            goto L_808010D0;
    }
    // 0x808010B4: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808010B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3E28) << 16);
    // 0x808010BC: addiu       $a2, $a2, 0x3E28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3E28));
    // 0x808010C0: jal         0x800C4350
    // 0x808010C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x808010C4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808010C8: b           L_80801108
    // 0x808010CC: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
        goto L_80801108;
    // 0x808010CC: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
L_808010D0:
    // 0x808010D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808010D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3718) << 16);
    // 0x808010D8: lwc1        $f18, 0x3718($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3718));
    // 0x808010DC: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x808010E0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808010E4: jal         0x800F10B4
    // 0x808010E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808010E8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x808010EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808010F0: jal         0x800C31DC
    // 0x808010F4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808010F4: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_3:
    // 0x808010F8: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808010FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801100: jal         0x800C4350
    // 0x80801104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x80801104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80801108:
    // 0x80801108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080110C:
    // 0x8080110C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801110: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801114: jr          $ra
    // 0x80801118: nop

    return;
    // 0x80801118: nop

;}
RECOMP_FUNC void _bsdrone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FE8: syscall     38
    recomp_syscall_handler(rdram, ctx, 0x80082FE8);
    return;
    // 0x80082FEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800FAE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAE44: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800FAE48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FAE4C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800FAE50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800FAE54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAE58: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800FAE5C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800FAE60: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FAE64: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800FAE68: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x800FAE6C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800FAE70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FAE74: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800FAE78: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800FAE7C: jal         0x800EFA4C
    // 0x800FAE80: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800FAE80: nop

    after_0:
    // 0x800FAE84: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x800FAE88: jal         0x800EE7F8
    // 0x800FAE8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800FAE8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800FAE90: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800FAE94: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800FAE98: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800FAE9C: jal         0x800C6C94
    // 0x800FAEA0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_800C6C94(rdram, ctx);
        goto after_2;
    // 0x800FAEA0: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x800FAEA4: beq         $v0, $zero, L_800FAF64
    if (ctx->r2 == 0) {
        // 0x800FAEA8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800FAF64;
    }
    // 0x800FAEA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800FAEAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FAEB0: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FAEB4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FAEB8: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800FAEBC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800FAEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FAEC4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800FAEC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800FAECC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800FAED0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FAED4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FAED8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FAEDC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FAEE0: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800FAEE4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FAEE8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FAEEC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800FAEF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FAEF4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800FAEF8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FAEFC: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FAF00: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FAF04: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800FAF08: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800FAF0C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800FAF10: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800FAF14: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800FAF18: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FAF1C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800FAF20: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FAF24: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800FAF28: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FAF2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FAF30: jal         0x800EE7F8
    // 0x800FAF34: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800FAF34: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800FAF38: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800FAF3C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800FAF40: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800FAF44: beql        $t6, $zero, L_800FAF68
    if (ctx->r14 == 0) {
        // 0x800FAF48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FAF68;
    }
    goto skip_0;
    // 0x800FAF48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800FAF4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800FAF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FAF54: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x800FAF58: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800FAF5C: jal         0x800FACA0
    // 0x800FAF60: nop

    func_800FACA0(rdram, ctx);
        goto after_4;
    // 0x800FAF60: nop

    after_4:
L_800FAF64:
    // 0x800FAF64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FAF68:
    // 0x800FAF68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FAF6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800FAF70: jr          $ra
    // 0x800FAF74: nop

    return;
    // 0x800FAF74: nop

;}
RECOMP_FUNC void chzubba_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1344, 0X178) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x178
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1344, 0X178));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x178
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1344, 0X178));
;}
RECOMP_FUNC void _bssplitup_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AF8: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AF8);
    return;
    // 0x80083AFC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80800CD0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CE0: jal         0x80100094
    // 0x80800CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800CEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CF0: jal         0x8010262C
    // 0x80800CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010262C(rdram, ctx);
        goto after_1;
    // 0x80800CF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800CF8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800CFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D04: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800D08: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800D0C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800D10: lwc1        $f10, 0x918($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X918);
    // 0x80800D14: jal         0x800136E4
    // 0x80800D18: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800D18: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_2:
    // 0x80800D1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D20: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800D24: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800D28: beq         $a0, $zero, L_80800D6C
    if (ctx->r4 == 0) {
        // 0x80800D2C: swc1        $f0, 0x918($v0)
        MEM_W(0X918, ctx->r2) = ctx->f0.u32l;
            goto L_80800D6C;
    }
    // 0x80800D2C: swc1        $f0, 0x918($v0)
    MEM_W(0X918, ctx->r2) = ctx->f0.u32l;
    // 0x80800D30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800D34: lw          $a3, 0x918($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X918);
    // 0x80800D38: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800D3C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800D40: jal         0x800E0AFC
    // 0x80800D44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800D44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800D48: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800D4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800D50: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800D54: lw          $a3, 0x918($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X918);
    // 0x80800D58: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800D5C: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800D60: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800D64: jal         0x800E0AFC
    // 0x80800D68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800D68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
L_80800D6C:
    // 0x80800D6C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800D70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D74: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800D78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D80: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800D84: lui         $a1, 0x4B18
    ctx->r5 = S32(0X4B18 << 16);
    // 0x80800D88: bc1f        L_80800E3C
    if (!c1cs) {
        // 0x80800D8C: nop
    
            goto L_80800E3C;
    }
    // 0x80800D8C: nop

    // 0x80800D90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D94: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D9C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800DA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800DA4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800DA8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800DAC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800DB0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800DB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800DB8: jal         0x800F10B4
    // 0x80800DBC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800DBC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    after_5:
    // 0x80800DC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800DC4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800DC8: jal         0x80101CDC
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101CDC(rdram, ctx);
        goto after_6;
    // 0x80800DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800DD0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800DD4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800DD8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DDC: bne         $a0, $zero, L_80800DFC
    if (ctx->r4 != 0) {
        // 0x80800DE0: lui         $a2, 0x4040
        ctx->r6 = S32(0X4040 << 16);
            goto L_80800DFC;
    }
    // 0x80800DE0: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80800DE4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X4DA4) << 16);
    // 0x80800DE8: addiu       $a2, $a2, 0x4DA4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X4DA4));
    // 0x80800DEC: jal         0x800C4350
    // 0x80800DF0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_7;
    // 0x80800DF0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800DF4: b           L_80800E44
    // 0x80800DF8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
        goto L_80800E44;
    // 0x80800DF8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
L_80800DFC:
    // 0x80800DFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4428) << 16);
    // 0x80800E04: lwc1        $f8, 0x4428($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4428));
    // 0x80800E08: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800E0C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800E10: jal         0x800F10B4
    // 0x80800E14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800E14: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800E18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E1C: jal         0x800C31DC
    // 0x80800E20: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x80800E20: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_9:
    // 0x80800E24: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800E28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800E2C: jal         0x800C4350
    // 0x80800E30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_10;
    // 0x80800E30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800E34: b           L_80800E48
    // 0x80800E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E48;
    // 0x80800E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E3C:
    // 0x80800E3C: jal         0x80101CDC
    // 0x80800E40: ori         $a1, $a1, 0x9680
    ctx->r5 = ctx->r5 | 0X9680;
    func_80101CDC(rdram, ctx);
        goto after_11;
    // 0x80800E40: ori         $a1, $a1, 0x9680
    ctx->r5 = ctx->r5 | 0X9680;
    after_11:
L_80800E44:
    // 0x80800E44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E48:
    // 0x80800E48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E4C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E50: jr          $ra
    // 0x80800E54: nop

    return;
    // 0x80800E54: nop

;}
RECOMP_FUNC void func_808040B8_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808040B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808040BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808040C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808040C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808040C8: jal         0x80106790
    // 0x808040CC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808040CC: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808040D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808040D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808040D8: jal         0x80100094
    // 0x808040DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808040DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808040E0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808040E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808040E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808040EC: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x808040F0: jal         0x80089AF8
    // 0x808040F4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808040F4: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x808040F8: beq         $v0, $zero, L_80804188
    if (ctx->r2 == 0) {
        // 0x808040FC: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80804188;
    }
    // 0x808040FC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80804100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804104: beq         $v0, $at, L_80804124
    if (ctx->r2 == ctx->r1) {
        // 0x80804108: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804124;
    }
    // 0x80804108: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080410C: beq         $v0, $at, L_80804168
    if (ctx->r2 == ctx->r1) {
        // 0x80804110: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80804168;
    }
    // 0x80804110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80804114: beql        $v0, $at, L_80804144
    if (ctx->r2 == ctx->r1) {
        // 0x80804118: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_80804144;
    }
    goto skip_0;
    // 0x80804118: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x8080411C: b           L_8080418C
    // 0x80804120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080418C;
    // 0x80804120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804124:
    // 0x80804124: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80804128: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8080412C: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80804130: jal         0x80089AB8
    // 0x80804134: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80804134: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80804138: b           L_8080418C
    // 0x8080413C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080418C;
    // 0x8080413C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804140: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_80804144:
    // 0x80804144: lbu         $a1, 0x39($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X39);
    // 0x80804148: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x8080414C: jal         0x80803FF4
    // 0x80804150: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80803FF4_chstoneballcontrol(rdram, ctx);
        goto after_4;
    // 0x80804150: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x80804154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804158: jal         0x8080419C
    // 0x8080415C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080419C_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x8080415C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80804160: b           L_8080418C
    // 0x80804164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080418C;
    // 0x80804164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804168:
    // 0x80804168: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080416C: lbu         $a1, 0x39($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X39);
    // 0x80804170: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x80804174: jal         0x80803FF4
    // 0x80804178: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80803FF4_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80804178: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_6:
    // 0x8080417C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804180: jal         0x80089AB8
    // 0x80804184: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80804184: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
L_80804188:
    // 0x80804188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080418C:
    // 0x8080418C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804190: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80804194: jr          $ra
    // 0x80804198: nop

    return;
    // 0x80804198: nop

;}
RECOMP_FUNC void func_800DAFCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAFCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DAFD0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800DAFD4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DAFD8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DAFDC: lwc1        $f4, -0x3860($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3860);
    // 0x800DAFE0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DAFE4: addiu       $a1, $a1, -0x3858
    ctx->r5 = ADD32(ctx->r5, -0X3858);
    // 0x800DAFE8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800DAFEC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DAFF0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DAFF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DAFF8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DAFFC: addiu       $v1, $a0, 0x4
    ctx->r3 = ADD32(ctx->r4, 0X4);
    // 0x800DB000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DB004: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800DB008: beql        $t7, $zero, L_800DB058
    if (ctx->r15 == 0) {
        // 0x800DB00C: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_800DB058;
    }
    goto skip_0;
    // 0x800DB00C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x800DB010: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DB014: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DB018: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB01C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DB020: nop

    // 0x800DB024: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800DB028: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DB02C: nop

    // 0x800DB030: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800DB034: bne         $t7, $zero, L_800DB04C
    if (ctx->r15 != 0) {
        // 0x800DB038: nop
    
            goto L_800DB04C;
    }
    // 0x800DB038: nop

    // 0x800DB03C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800DB040: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB044: b           L_800DB064
    // 0x800DB048: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800DB064;
    // 0x800DB048: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800DB04C:
    // 0x800DB04C: b           L_800DB064
    // 0x800DB050: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800DB064;
    // 0x800DB050: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800DB054: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_800DB058:
    // 0x800DB058: nop

    // 0x800DB05C: bltz        $t7, L_800DB04C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800DB060: nop
    
            goto L_800DB04C;
    }
    // 0x800DB060: nop

L_800DB064:
    // 0x800DB064: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800DB068: sra         $t0, $t7, 8
    ctx->r8 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800DB06C: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    // 0x800DB070: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DB074: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800DB078: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800DB07C: lwc1        $f8, -0x3860($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3860);
    // 0x800DB080: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB084: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DB088: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800DB08C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800DB090: nop

    // 0x800DB094: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800DB098: beql        $t2, $zero, L_800DB0E8
    if (ctx->r10 == 0) {
        // 0x800DB09C: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_800DB0E8;
    }
    goto skip_1;
    // 0x800DB09C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800DB0A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB0A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DB0A8: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DB0AC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800DB0B0: nop

    // 0x800DB0B4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800DB0B8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800DB0BC: nop

    // 0x800DB0C0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800DB0C4: bne         $t2, $zero, L_800DB0DC
    if (ctx->r10 != 0) {
        // 0x800DB0C8: nop
    
            goto L_800DB0DC;
    }
    // 0x800DB0C8: nop

    // 0x800DB0CC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800DB0D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB0D4: b           L_800DB0F4
    // 0x800DB0D8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800DB0F4;
    // 0x800DB0D8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800DB0DC:
    // 0x800DB0DC: b           L_800DB0F4
    // 0x800DB0E0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800DB0F4;
    // 0x800DB0E0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800DB0E4: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_800DB0E8:
    // 0x800DB0E8: nop

    // 0x800DB0EC: bltz        $t2, L_800DB0DC
    if (SIGNED(ctx->r10) < 0) {
        // 0x800DB0F0: nop
    
            goto L_800DB0DC;
    }
    // 0x800DB0F0: nop

L_800DB0F4:
    // 0x800DB0F4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800DB0F8: sb          $t2, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r10;
    // 0x800DB0FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DB100: lwc1        $f16, -0x385C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X385C);
    // 0x800DB104: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800DB108: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800DB10C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB110: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DB114: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800DB118: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800DB11C: nop

    // 0x800DB120: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800DB124: beql        $t6, $zero, L_800DB174
    if (ctx->r14 == 0) {
        // 0x800DB128: mfc1        $t6, $f18
        ctx->r14 = (int32_t)ctx->f18.u32l;
            goto L_800DB174;
    }
    goto skip_2;
    // 0x800DB128: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x800DB12C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800DB130: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DB134: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DB138: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800DB13C: nop

    // 0x800DB140: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800DB144: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800DB148: nop

    // 0x800DB14C: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800DB150: bne         $t6, $zero, L_800DB168
    if (ctx->r14 != 0) {
        // 0x800DB154: nop
    
            goto L_800DB168;
    }
    // 0x800DB154: nop

    // 0x800DB158: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800DB15C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB160: b           L_800DB180
    // 0x800DB164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800DB180;
    // 0x800DB164: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800DB168:
    // 0x800DB168: b           L_800DB180
    // 0x800DB16C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800DB180;
    // 0x800DB16C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800DB170: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
L_800DB174:
    // 0x800DB174: nop

    // 0x800DB178: bltz        $t6, L_800DB168
    if (SIGNED(ctx->r14) < 0) {
        // 0x800DB17C: nop
    
            goto L_800DB168;
    }
    // 0x800DB17C: nop

L_800DB180:
    // 0x800DB180: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800DB184: sra         $t9, $t6, 8
    ctx->r25 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800DB188: sb          $t9, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r25;
    // 0x800DB18C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DB190: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800DB194: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800DB198: lwc1        $f4, -0x385C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X385C);
    // 0x800DB19C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB1A0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800DB1A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800DB1A8: nop

    // 0x800DB1AC: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800DB1B0: beql        $t1, $zero, L_800DB200
    if (ctx->r9 == 0) {
        // 0x800DB1B4: mfc1        $t1, $f6
        ctx->r9 = (int32_t)ctx->f6.u32l;
            goto L_800DB200;
    }
    goto skip_3;
    // 0x800DB1B4: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x800DB1B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DB1BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DB1C0: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB1C4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800DB1C8: nop

    // 0x800DB1CC: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800DB1D0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800DB1D4: nop

    // 0x800DB1D8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800DB1DC: bne         $t1, $zero, L_800DB1F4
    if (ctx->r9 != 0) {
        // 0x800DB1E0: nop
    
            goto L_800DB1F4;
    }
    // 0x800DB1E0: nop

    // 0x800DB1E4: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800DB1E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB1EC: b           L_800DB20C
    // 0x800DB1F0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800DB20C;
    // 0x800DB1F0: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800DB1F4:
    // 0x800DB1F4: b           L_800DB20C
    // 0x800DB1F8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800DB20C;
    // 0x800DB1F8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800DB1FC: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
L_800DB200:
    // 0x800DB200: nop

    // 0x800DB204: bltz        $t1, L_800DB1F4
    if (SIGNED(ctx->r9) < 0) {
        // 0x800DB208: nop
    
            goto L_800DB1F4;
    }
    // 0x800DB208: nop

L_800DB20C:
    // 0x800DB20C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800DB210: sb          $t1, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r9;
    // 0x800DB214: addiu       $v0, $v0, -0x3828
    ctx->r2 = ADD32(ctx->r2, -0X3828);
L_800DB218:
    // 0x800DB218: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800DB21C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DB220: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800DB224: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB228: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800DB22C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB230: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800DB234: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800DB238: nop

    // 0x800DB23C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800DB240: beql        $t5, $zero, L_800DB290
    if (ctx->r13 == 0) {
        // 0x800DB244: mfc1        $t5, $f10
        ctx->r13 = (int32_t)ctx->f10.u32l;
            goto L_800DB290;
    }
    goto skip_4;
    // 0x800DB244: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x800DB248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB24C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DB250: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DB254: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800DB258: nop

    // 0x800DB25C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800DB260: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800DB264: nop

    // 0x800DB268: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800DB26C: bne         $t5, $zero, L_800DB284
    if (ctx->r13 != 0) {
        // 0x800DB270: nop
    
            goto L_800DB284;
    }
    // 0x800DB270: nop

    // 0x800DB274: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800DB278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB27C: b           L_800DB29C
    // 0x800DB280: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800DB29C;
    // 0x800DB280: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800DB284:
    // 0x800DB284: b           L_800DB29C
    // 0x800DB288: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800DB29C;
    // 0x800DB288: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800DB28C: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
L_800DB290:
    // 0x800DB290: nop

    // 0x800DB294: bltz        $t5, L_800DB284
    if (SIGNED(ctx->r13) < 0) {
        // 0x800DB298: nop
    
            goto L_800DB284;
    }
    // 0x800DB298: nop

L_800DB29C:
    // 0x800DB29C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800DB2A0: sra         $t8, $t5, 8
    ctx->r24 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800DB2A4: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800DB2A8: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800DB2AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800DB2B0: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800DB2B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB2B8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800DB2BC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800DB2C0: nop

    // 0x800DB2C4: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800DB2C8: beql        $t0, $zero, L_800DB318
    if (ctx->r8 == 0) {
        // 0x800DB2CC: mfc1        $t0, $f18
        ctx->r8 = (int32_t)ctx->f18.u32l;
            goto L_800DB318;
    }
    goto skip_5;
    // 0x800DB2CC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    skip_5:
    // 0x800DB2D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800DB2D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800DB2D8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DB2DC: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800DB2E0: nop

    // 0x800DB2E4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800DB2E8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800DB2EC: nop

    // 0x800DB2F0: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800DB2F4: bne         $t0, $zero, L_800DB30C
    if (ctx->r8 != 0) {
        // 0x800DB2F8: nop
    
            goto L_800DB30C;
    }
    // 0x800DB2F8: nop

    // 0x800DB2FC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800DB300: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB304: b           L_800DB324
    // 0x800DB308: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800DB324;
    // 0x800DB308: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800DB30C:
    // 0x800DB30C: b           L_800DB324
    // 0x800DB310: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800DB324;
    // 0x800DB310: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800DB314: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
L_800DB318:
    // 0x800DB318: nop

    // 0x800DB31C: bltz        $t0, L_800DB30C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800DB320: nop
    
            goto L_800DB30C;
    }
    // 0x800DB320: nop

L_800DB324:
    // 0x800DB324: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800DB328: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DB32C: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x800DB330: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DB334: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800DB338: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800DB33C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DB340: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB344: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800DB348: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800DB34C: nop

    // 0x800DB350: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800DB354: beql        $t4, $zero, L_800DB3A4
    if (ctx->r12 == 0) {
        // 0x800DB358: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_800DB3A4;
    }
    goto skip_6;
    // 0x800DB358: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_6:
    // 0x800DB35C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DB360: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DB364: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB368: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800DB36C: nop

    // 0x800DB370: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800DB374: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800DB378: nop

    // 0x800DB37C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800DB380: bne         $t4, $zero, L_800DB398
    if (ctx->r12 != 0) {
        // 0x800DB384: nop
    
            goto L_800DB398;
    }
    // 0x800DB384: nop

    // 0x800DB388: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800DB38C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB390: b           L_800DB3B0
    // 0x800DB394: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800DB3B0;
    // 0x800DB394: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800DB398:
    // 0x800DB398: b           L_800DB3B0
    // 0x800DB39C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800DB3B0;
    // 0x800DB39C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800DB3A0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_800DB3A4:
    // 0x800DB3A4: nop

    // 0x800DB3A8: bltz        $t4, L_800DB398
    if (SIGNED(ctx->r12) < 0) {
        // 0x800DB3AC: nop
    
            goto L_800DB398;
    }
    // 0x800DB3AC: nop

L_800DB3B0:
    // 0x800DB3B0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800DB3B4: sra         $t7, $t4, 8
    ctx->r15 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800DB3B8: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800DB3BC: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800DB3C0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800DB3C4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800DB3C8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB3CC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800DB3D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800DB3D4: nop

    // 0x800DB3D8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800DB3DC: beql        $t9, $zero, L_800DB42C
    if (ctx->r25 == 0) {
        // 0x800DB3E0: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_800DB42C;
    }
    goto skip_7;
    // 0x800DB3E0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_7:
    // 0x800DB3E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB3E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DB3EC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DB3F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800DB3F4: nop

    // 0x800DB3F8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800DB3FC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800DB400: nop

    // 0x800DB404: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800DB408: bne         $t9, $zero, L_800DB420
    if (ctx->r25 != 0) {
        // 0x800DB40C: nop
    
            goto L_800DB420;
    }
    // 0x800DB40C: nop

    // 0x800DB410: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800DB414: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB418: b           L_800DB438
    // 0x800DB41C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800DB438;
    // 0x800DB41C: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800DB420:
    // 0x800DB420: b           L_800DB438
    // 0x800DB424: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800DB438;
    // 0x800DB424: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800DB428: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_800DB42C:
    // 0x800DB42C: nop

    // 0x800DB430: bltz        $t9, L_800DB420
    if (SIGNED(ctx->r25) < 0) {
        // 0x800DB434: nop
    
            goto L_800DB420;
    }
    // 0x800DB434: nop

L_800DB438:
    // 0x800DB438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800DB43C: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x800DB440: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DB444: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800DB448: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800DB44C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800DB450: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DB454: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB458: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800DB45C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800DB460: nop

    // 0x800DB464: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800DB468: beql        $t3, $zero, L_800DB4B8
    if (ctx->r11 == 0) {
        // 0x800DB46C: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_800DB4B8;
    }
    goto skip_8;
    // 0x800DB46C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_8:
    // 0x800DB470: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800DB474: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DB478: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DB47C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800DB480: nop

    // 0x800DB484: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800DB488: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800DB48C: nop

    // 0x800DB490: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800DB494: bne         $t3, $zero, L_800DB4AC
    if (ctx->r11 != 0) {
        // 0x800DB498: nop
    
            goto L_800DB4AC;
    }
    // 0x800DB498: nop

    // 0x800DB49C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x800DB4A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB4A4: b           L_800DB4C4
    // 0x800DB4A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800DB4C4;
    // 0x800DB4A8: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800DB4AC:
    // 0x800DB4AC: b           L_800DB4C4
    // 0x800DB4B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800DB4C4;
    // 0x800DB4B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800DB4B4: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_800DB4B8:
    // 0x800DB4B8: nop

    // 0x800DB4BC: bltz        $t3, L_800DB4AC
    if (SIGNED(ctx->r11) < 0) {
        // 0x800DB4C0: nop
    
            goto L_800DB4AC;
    }
    // 0x800DB4C0: nop

L_800DB4C4:
    // 0x800DB4C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800DB4C8: sra         $t6, $t3, 8
    ctx->r14 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800DB4CC: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x800DB4D0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800DB4D4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DB4D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800DB4DC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB4E0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800DB4E4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800DB4E8: nop

    // 0x800DB4EC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800DB4F0: beql        $t8, $zero, L_800DB540
    if (ctx->r24 == 0) {
        // 0x800DB4F4: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800DB540;
    }
    goto skip_9;
    // 0x800DB4F4: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_9:
    // 0x800DB4F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DB4FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DB500: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DB504: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800DB508: nop

    // 0x800DB50C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800DB510: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800DB514: nop

    // 0x800DB518: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800DB51C: bne         $t8, $zero, L_800DB534
    if (ctx->r24 != 0) {
        // 0x800DB520: nop
    
            goto L_800DB534;
    }
    // 0x800DB520: nop

    // 0x800DB524: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800DB528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB52C: b           L_800DB54C
    // 0x800DB530: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800DB54C;
    // 0x800DB530: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800DB534:
    // 0x800DB534: b           L_800DB54C
    // 0x800DB538: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800DB54C;
    // 0x800DB538: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800DB53C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800DB540:
    // 0x800DB540: nop

    // 0x800DB544: bltz        $t8, L_800DB534
    if (SIGNED(ctx->r24) < 0) {
        // 0x800DB548: nop
    
            goto L_800DB534;
    }
    // 0x800DB548: nop

L_800DB54C:
    // 0x800DB54C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DB550: sb          $t8, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r24;
    // 0x800DB554: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DB558: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800DB55C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800DB560: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800DB564: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DB568: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB56C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800DB570: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800DB574: nop

    // 0x800DB578: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800DB57C: beql        $t2, $zero, L_800DB5CC
    if (ctx->r10 == 0) {
        // 0x800DB580: mfc1        $t2, $f10
        ctx->r10 = (int32_t)ctx->f10.u32l;
            goto L_800DB5CC;
    }
    goto skip_10;
    // 0x800DB580: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    skip_10:
    // 0x800DB584: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800DB588: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800DB58C: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800DB590: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800DB594: nop

    // 0x800DB598: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800DB59C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800DB5A0: nop

    // 0x800DB5A4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800DB5A8: bne         $t2, $zero, L_800DB5C0
    if (ctx->r10 != 0) {
        // 0x800DB5AC: nop
    
            goto L_800DB5C0;
    }
    // 0x800DB5AC: nop

    // 0x800DB5B0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800DB5B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB5B8: b           L_800DB5D8
    // 0x800DB5BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800DB5D8;
    // 0x800DB5BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800DB5C0:
    // 0x800DB5C0: b           L_800DB5D8
    // 0x800DB5C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800DB5D8;
    // 0x800DB5C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800DB5C8: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
L_800DB5CC:
    // 0x800DB5CC: nop

    // 0x800DB5D0: bltz        $t2, L_800DB5C0
    if (SIGNED(ctx->r10) < 0) {
        // 0x800DB5D4: nop
    
            goto L_800DB5C0;
    }
    // 0x800DB5D4: nop

L_800DB5D8:
    // 0x800DB5D8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800DB5DC: sra         $t5, $t2, 8
    ctx->r13 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800DB5E0: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
    // 0x800DB5E4: lwc1        $f16, 0xC($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800DB5E8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800DB5EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DB5F0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DB5F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800DB5F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800DB5FC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DB600: nop

    // 0x800DB604: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800DB608: beql        $t7, $zero, L_800DB658
    if (ctx->r15 == 0) {
        // 0x800DB60C: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_800DB658;
    }
    goto skip_11;
    // 0x800DB60C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_11:
    // 0x800DB610: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800DB614: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800DB618: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DB61C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800DB620: nop

    // 0x800DB624: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800DB628: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800DB62C: nop

    // 0x800DB630: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800DB634: bne         $t7, $zero, L_800DB64C
    if (ctx->r15 != 0) {
        // 0x800DB638: nop
    
            goto L_800DB64C;
    }
    // 0x800DB638: nop

    // 0x800DB63C: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800DB640: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DB644: b           L_800DB664
    // 0x800DB648: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800DB664;
    // 0x800DB648: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800DB64C:
    // 0x800DB64C: b           L_800DB664
    // 0x800DB650: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800DB664;
    // 0x800DB650: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800DB654: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_800DB658:
    // 0x800DB658: nop

    // 0x800DB65C: bltz        $t7, L_800DB64C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800DB660: nop
    
            goto L_800DB64C;
    }
    // 0x800DB660: nop

L_800DB664:
    // 0x800DB664: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800DB668: sb          $t7, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r15;
    // 0x800DB66C: bne         $a1, $v0, L_800DB218
    if (ctx->r5 != ctx->r2) {
        // 0x800DB670: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800DB218;
    }
    // 0x800DB670: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800DB674: jr          $ra
    // 0x800DB678: nop

    return;
    // 0x800DB678: nop

;}
RECOMP_FUNC void func_800DAB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAB8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DAB90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DAB94: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DAB98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DAB9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DABA0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800DABA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800DABA8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800DABAC: blez        $t6, L_800DABD8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800DABB0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800DABD8;
    }
    // 0x800DABB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800DABB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800DABB8:
    // 0x800DABB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800DABBC: jal         0x800DAAF8
    // 0x800DABC0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800DAAF8(rdram, ctx);
        goto after_0;
    // 0x800DABC0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x800DABC4: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800DABC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800DABCC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800DABD0: bnel        $at, $zero, L_800DABB8
    if (ctx->r1 != 0) {
        // 0x800DABD4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DABB8;
    }
    goto skip_0;
    // 0x800DABD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_800DABD8:
    // 0x800DABD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DABDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DABE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DABE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DABE8: jr          $ra
    // 0x800DABEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800DABEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800E253C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E253C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E2540: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E2544: swc1        $f12, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f12.u32l;
    // 0x800E2548: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800E254C: jr          $ra
    // 0x800E2550: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x800E2550: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_808009CC_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808009D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009DC: jal         0x80100094
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009E4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808009E8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808009EC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009F0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808009F4: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x808009F8: beq         $at, $zero, L_80800E8C
    if (ctx->r1 == 0) {
        // 0x808009FC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800E8C;
    }
    // 0x808009FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22D0) << 16);
    // 0x80800A04: addu        $at, $at, $t8
    gpr jr_addend_80800A0C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800A08: lw          $t8, 0x22D0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22D0));
    // 0x80800A0C: jr          $t8
    // 0x80800A10: nop

    switch (jr_addend_80800A0C >> 2) {
        case 0: goto L_80800A14; break;
        case 1: goto L_80800A88; break;
        case 2: goto L_80800A98; break;
        case 3: goto L_80800C44; break;
        case 4: goto L_80800C90; break;
        case 5: goto L_80800CC8; break;
        case 6: goto L_80800CF4; break;
        case 7: goto L_80800D9C; break;
        default: switch_error(__func__, 0x80800A0C, 0x808022D0);
    }
    // 0x80800A10: nop

L_80800A14:
    // 0x80800A14: jal         0x800DA298
    // 0x80800A18: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800A18: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_1:
    // 0x80800A1C: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800A20: addiu       $a0, $zero, 0x9DE
        ctx->r4 = ADD32(0, 0X9DE);
            goto L_80800E8C;
    }
    // 0x80800A20: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    // 0x80800A24: jal         0x800DA3B8
    // 0x80800A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_2;
    // 0x80800A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A38: jal         0x80085708
    // 0x80800A3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800A3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800A40: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800A44: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800A48: jal         0x80090734
    // 0x80800A4C: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    func_80090734(rdram, ctx);
        goto after_4;
    // 0x80800A4C: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_4:
    // 0x80800A50: jal         0x8080130C
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080130C_chchuffy(rdram, ctx);
        goto after_5;
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x808017D4
    // 0x80800A60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_6;
    // 0x80800A60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800A64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A68: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800A6C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800A70: addiu       $a0, $a0, 0x6D80
    ctx->r4 = ADD32(ctx->r4, 0X6D80);
    // 0x80800A74: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80800A78: jal         0x80086D30
    // 0x80800A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800A7C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800A80: b           L_80800E8C
    // 0x80800A84: nop

        goto L_80800E8C;
    // 0x80800A84: nop

L_80800A88:
    // 0x80800A88: jal         0x80800398
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chchuffy(rdram, ctx);
        goto after_8;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A90: b           L_80800E8C
    // 0x80800A94: nop

        goto L_80800E8C;
    // 0x80800A94: nop

L_80800A98:
    // 0x80800A98: jal         0x80800398
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chchuffy(rdram, ctx);
        goto after_9;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800AA0: jal         0x800DA544
    // 0x80800AA4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x80800AA4: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_10:
    // 0x80800AA8: jal         0x800DA544
    // 0x80800AAC: addiu       $a0, $zero, 0x4ED
    ctx->r4 = ADD32(0, 0X4ED);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800AAC: addiu       $a0, $zero, 0x4ED
    ctx->r4 = ADD32(0, 0X4ED);
    after_11:
    // 0x80800AB0: jal         0x80106790
    // 0x80800AB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_12;
    // 0x80800AB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_12:
    // 0x80800AB8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800ABC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80800AC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AC4: addiu       $a1, $zero, 0x87A
    ctx->r5 = ADD32(0, 0X87A);
    // 0x80800AC8: jal         0x80103140
    // 0x80800ACC: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    func_80103140(rdram, ctx);
        goto after_13;
    // 0x80800ACC: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    after_13:
    // 0x80800AD0: jal         0x8010A590
    // 0x80800AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A590(rdram, ctx);
        goto after_14;
    // 0x80800AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x80800AD8: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x80800ADC: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800AE0: jal         0x80101E14
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_15;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800AE8: bne         $v0, $zero, L_80800B00
    if (ctx->r2 != 0) {
        // 0x80800AEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B00;
    }
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF0: jal         0x80101E14
    // 0x80800AF4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_80101E14(rdram, ctx);
        goto after_16;
    // 0x80800AF4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_16:
    // 0x80800AF8: beql        $v0, $zero, L_80800B34
    if (ctx->r2 == 0) {
        // 0x80800AFC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800B34;
    }
    goto skip_0;
    // 0x80800AFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_0:
L_80800B00:
    // 0x80800B00: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800B04: lui         $a2, 0x3F26
    ctx->r6 = S32(0X3F26 << 16);
    // 0x80800B08: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800B0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800B10: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800B14: jal         0x800E1610
    // 0x80800B18: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    func_800E1610(rdram, ctx);
        goto after_17;
    // 0x80800B18: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    after_17:
    // 0x80800B1C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X2320) << 16);
    // 0x80800B20: addiu       $a2, $a2, 0x2320
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X2320));
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: jal         0x80089D18
    // 0x80800B2C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80800B2C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_18:
    // 0x80800B30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_80800B34:
    // 0x80800B34: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X2334) << 16);
    // 0x80800B38: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80800B3C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800B40: addiu       $a2, $a2, 0x2334
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X2334));
    // 0x80800B44: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800B48: jal         0x80089D20
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800B50: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X2348) << 16);
    // 0x80800B54: lui         $a3, 0x3F73
    ctx->r7 = S32(0X3F73 << 16);
    // 0x80800B58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800B5C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800B60: addiu       $a2, $a2, 0x2348
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X2348));
    // 0x80800B64: jal         0x80089D20
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800B6C: jal         0x80101F24
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_21;
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800B74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22F0) << 16);
    // 0x80800B78: lwc1        $f6, 0x22F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22F0));
    // 0x80800B7C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800B80: nop

    // 0x80800B84: bc1f        L_80800BC8
    if (!c1cs) {
        // 0x80800B88: nop
    
            goto L_80800BC8;
    }
    // 0x80800B88: nop

    // 0x80800B8C: jal         0x800DC0C0
    // 0x80800B90: nop

    func_800DC0C0(rdram, ctx);
        goto after_22;
    // 0x80800B90: nop

    after_22:
    // 0x80800B94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22F4) << 16);
    // 0x80800B98: lwc1        $f8, 0x22F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22F4));
    // 0x80800B9C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800BA8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X235C) << 16);
    // 0x80800BAC: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    // 0x80800BB0: bc1fl       L_80800C20
    if (!c1cs) {
        // 0x80800BB4: lui         $a1, 0x3F73
        ctx->r5 = S32(0X3F73 << 16);
            goto L_80800C20;
    }
    goto skip_1;
    // 0x80800BB4: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    skip_1:
    // 0x80800BB8: jal         0x80089D18
    // 0x80800BBC: addiu       $a2, $a2, 0x235C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X235C));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x80800BBC: addiu       $a2, $a2, 0x235C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X235C));
    after_23:
    // 0x80800BC0: b           L_80800C20
    // 0x80800BC4: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
        goto L_80800C20;
    // 0x80800BC4: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
L_80800BC8:
    // 0x80800BC8: jal         0x80101F24
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_24;
    // 0x80800BCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800BD0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22F8) << 16);
    // 0x80800BD4: lwc1        $f10, 0x22F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22F8));
    // 0x80800BD8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800BDC: nop

    // 0x80800BE0: bc1fl       L_80800C20
    if (!c1cs) {
        // 0x80800BE4: lui         $a1, 0x3F73
        ctx->r5 = S32(0X3F73 << 16);
            goto L_80800C20;
    }
    goto skip_2;
    // 0x80800BE4: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    skip_2:
    // 0x80800BE8: jal         0x800DC0C0
    // 0x80800BEC: nop

    func_800DC0C0(rdram, ctx);
        goto after_25;
    // 0x80800BEC: nop

    after_25:
    // 0x80800BF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22FC) << 16);
    // 0x80800BF4: lwc1        $f16, 0x22FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22FC));
    // 0x80800BF8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C00: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800C04: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X2374) << 16);
    // 0x80800C08: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    // 0x80800C0C: bc1fl       L_80800C20
    if (!c1cs) {
        // 0x80800C10: lui         $a1, 0x3F73
        ctx->r5 = S32(0X3F73 << 16);
            goto L_80800C20;
    }
    goto skip_3;
    // 0x80800C10: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    skip_3:
    // 0x80800C14: jal         0x80089D18
    // 0x80800C18: addiu       $a2, $a2, 0x2374
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X2374));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80800C18: addiu       $a2, $a2, 0x2374
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X2374));
    after_26:
    // 0x80800C1C: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
L_80800C20:
    // 0x80800C20: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800C24: jal         0x80101E14
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800C2C: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800C30: addiu       $a0, $zero, 0x9DF
        ctx->r4 = ADD32(0, 0X9DF);
            goto L_80800E8C;
    }
    // 0x80800C30: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    // 0x80800C34: jal         0x800DA3B8
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_28;
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x80800C3C: b           L_80800E8C
    // 0x80800C40: nop

        goto L_80800E8C;
    // 0x80800C40: nop

L_80800C44:
    // 0x80800C44: jal         0x80800398
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800398_chchuffy(rdram, ctx);
        goto after_29;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80800C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C50: jal         0x80100094
    // 0x80800C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_30;
    // 0x80800C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800C58: jal         0x800898F0
    // 0x80800C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_31;
    // 0x80800C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x80800C60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2300) << 16);
    // 0x80800C64: lwc1        $f18, 0x2300($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2300));
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800C70: nop

    // 0x80800C74: bc1fl       L_80800C94
    if (!c1cs) {
        // 0x80800C78: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_80800C94;
    }
    goto skip_4;
    // 0x80800C78: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80800C7C: jal         0x80089848
    // 0x80800C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_32;
    // 0x80800C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80800C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C88: jal         0x808017D4
    // 0x80800C8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_33;
    // 0x80800C8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_33:
L_80800C90:
    // 0x80800C90: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_80800C94:
    // 0x80800C94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2304) << 16);
    // 0x80800C98: lwc1        $f4, 0x2304($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2304));
    // 0x80800C9C: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80800CA0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800CA4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800CA8: nop

    // 0x80800CAC: bc1f        L_80800E8C
    if (!c1cs) {
        // 0x80800CB0: nop
    
            goto L_80800E8C;
    }
    // 0x80800CB0: nop

    // 0x80800CB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CB8: nop

    // 0x80800CBC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800CC0: b           L_80800E8C
    // 0x80800CC4: swc1        $f8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f8.u32l;
        goto L_80800E8C;
    // 0x80800CC4: swc1        $f8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f8.u32l;
L_80800CC8:
    // 0x80800CC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800CCC: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD4: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800CD8: nop

    // 0x80800CDC: bc1f        L_80800E8C
    if (!c1cs) {
        // 0x80800CE0: nop
    
            goto L_80800E8C;
    }
    // 0x80800CE0: nop

    // 0x80800CE4: jal         0x808017D4
    // 0x80800CE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_34;
    // 0x80800CE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_34:
    // 0x80800CEC: b           L_80800E8C
    // 0x80800CF0: nop

        goto L_80800E8C;
    // 0x80800CF0: nop

L_80800CF4:
    // 0x80800CF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2308) << 16);
    // 0x80800CF8: lwc1        $f18, 0x2308($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2308));
    // 0x80800CFC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800D00: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800D04: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800D08: nop

    // 0x80800D0C: bc1f        L_80800D24
    if (!c1cs) {
        // 0x80800D10: nop
    
            goto L_80800D24;
    }
    // 0x80800D10: nop

    // 0x80800D14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D18: nop

    // 0x80800D1C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800D20: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_80800D24:
    // 0x80800D24: jal         0x80101DDC
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_35;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800D2C: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800D30: addiu       $a0, $zero, 0x66B
        ctx->r4 = ADD32(0, 0X66B);
            goto L_80800E8C;
    }
    // 0x80800D30: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
    // 0x80800D34: jal         0x800DA3B8
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_36;
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x80800D3C: jal         0x800DA298
    // 0x80800D40: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    func_800DA298(rdram, ctx);
        goto after_37;
    // 0x80800D40: addiu       $a0, $zero, 0x6B7
    ctx->r4 = ADD32(0, 0X6B7);
    after_37:
    // 0x80800D44: beq         $v0, $zero, L_80800D64
    if (ctx->r2 == 0) {
        // 0x80800D48: nop
    
            goto L_80800D64;
    }
    // 0x80800D48: nop

    // 0x80800D4C: jal         0x80088830
    // 0x80800D50: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_38;
    // 0x80800D50: nop

    after_38:
    // 0x80800D54: jal         0x80085710
    // 0x80800D58: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_39;
    // 0x80800D58: nop

    after_39:
    // 0x80800D5C: b           L_80800E8C
    // 0x80800D60: nop

        goto L_80800E8C;
    // 0x80800D60: nop

L_80800D64:
    // 0x80800D64: jal         0x80800110
    // 0x80800D68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800110_chchuffy(rdram, ctx);
        goto after_40;
    // 0x80800D68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_40:
    // 0x80800D6C: jal         0x8080000C
    // 0x80800D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8080000C_chchuffy(rdram, ctx);
        goto after_41;
    // 0x80800D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x80800D74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D78: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800D7C: jal         0x80088868
    // 0x80800D80: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_42;
    // 0x80800D80: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    after_42:
    // 0x80800D84: jal         0x800FE844
    // 0x80800D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FE844(rdram, ctx);
        goto after_43;
    // 0x80800D88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_43:
    // 0x80800D8C: jal         0x800FE734
    // 0x80800D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FE734(rdram, ctx);
        goto after_44;
    // 0x80800D90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_44:
    // 0x80800D94: b           L_80800E8C
    // 0x80800D98: nop

        goto L_80800E8C;
    // 0x80800D98: nop

L_80800D9C:
    // 0x80800D9C: jal         0x80101F24
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_45;
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800DA4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800DA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800DAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X230C) << 16);
    // 0x80800DB0: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80800DB4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800DB8: nop

    // 0x80800DBC: bc1fl       L_80800DF4
    if (!c1cs) {
        // 0x80800DC0: lw          $t3, 0x74($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X74);
            goto L_80800DF4;
    }
    goto skip_5;
    // 0x80800DC0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    skip_5:
    // 0x80800DC4: lwc1        $f0, 0x4($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80800DC8: lwc1        $f10, 0x230C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X230C));
    // 0x80800DCC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800DD0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800DD4: nop

    // 0x80800DD8: bc1fl       L_80800DF4
    if (!c1cs) {
        // 0x80800DDC: lw          $t3, 0x74($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X74);
            goto L_80800DF4;
    }
    goto skip_6;
    // 0x80800DDC: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    skip_6:
    // 0x80800DE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800DE4: nop

    // 0x80800DE8: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800DEC: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
    // 0x80800DF0: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
L_80800DF4:
    // 0x80800DF4: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x80800DF8: bgez        $t5, L_80800E64
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800DFC: nop
    
            goto L_80800E64;
    }
    // 0x80800DFC: nop

    // 0x80800E00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E04: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E08: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800E0C: nop

    // 0x80800E10: bc1f        L_80800E30
    if (!c1cs) {
        // 0x80800E14: nop
    
            goto L_80800E30;
    }
    // 0x80800E14: nop

    // 0x80800E18: jal         0x800D8FF8
    // 0x80800E1C: nop

    func_800D8FF8(rdram, ctx);
        goto after_46;
    // 0x80800E1C: nop

    after_46:
    // 0x80800E20: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E24: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800E28: b           L_80800E8C
    // 0x80800E2C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800E8C;
    // 0x80800E2C: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800E30:
    // 0x80800E30: jal         0x808016D0
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016D0_chchuffy(rdram, ctx);
        goto after_47;
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800E38: bnel        $v0, $zero, L_80800E54
    if (ctx->r2 != 0) {
        // 0x80800E3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E54;
    }
    goto skip_7;
    // 0x80800E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x80800E40: jal         0x80088830
    // 0x80800E44: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_48;
    // 0x80800E44: nop

    after_48:
    // 0x80800E48: jal         0x80085710
    // 0x80800E4C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_49;
    // 0x80800E4C: nop

    after_49:
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E54:
    // 0x80800E54: jal         0x808017D4
    // 0x80800E58: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808017D4_chchuffy(rdram, ctx);
        goto after_50;
    // 0x80800E58: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_50:
    // 0x80800E5C: b           L_80800E8C
    // 0x80800E60: nop

        goto L_80800E8C;
    // 0x80800E60: nop

L_80800E64:
    // 0x80800E64: jal         0x80101DDC
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_51;
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800E6C: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800E70: nop
    
            goto L_80800E8C;
    }
    // 0x80800E70: nop

    // 0x80800E74: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800E78: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800E7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E80: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800E84: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x80800E88: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800E8C:
    // 0x80800E8C: jal         0x801022E4
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_52;
    // 0x80800E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80800E94: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x80800E98: beq         $v0, $at, L_80800EB0
    if (ctx->r2 == ctx->r1) {
        // 0x80800E9C: addiu       $at, $zero, 0x9A
        ctx->r1 = ADD32(0, 0X9A);
            goto L_80800EB0;
    }
    // 0x80800E9C: addiu       $at, $zero, 0x9A
    ctx->r1 = ADD32(0, 0X9A);
    // 0x80800EA0: beq         $v0, $at, L_80800EC0
    if (ctx->r2 == ctx->r1) {
        // 0x80800EA4: nop
    
            goto L_80800EC0;
    }
    // 0x80800EA4: nop

    // 0x80800EA8: b           L_80800EC8
    // 0x80800EAC: nop

        goto L_80800EC8;
    // 0x80800EAC: nop

L_80800EB0:
    // 0x80800EB0: jal         0x8080115C
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080115C_chchuffy(rdram, ctx);
        goto after_53;
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80800EB8: b           L_80800EC8
    // 0x80800EBC: nop

        goto L_80800EC8;
    // 0x80800EBC: nop

L_80800EC0:
    // 0x80800EC0: jal         0x80800FBC
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FBC_chchuffy(rdram, ctx);
        goto after_54;
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
L_80800EC8:
    // 0x80800EC8: jal         0x800D8FF8
    // 0x80800ECC: nop

    func_800D8FF8(rdram, ctx);
        goto after_55;
    // 0x80800ECC: nop

    after_55:
    // 0x80800ED0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800ED4: lwc1        $f18, 0x38($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X38);
    // 0x80800ED8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80800EDC: swc1        $f4, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f4.u32l;
    // 0x80800EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800EEC: jr          $ra
    // 0x80800EF0: nop

    return;
    // 0x80800EF0: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A638: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A638);
    return;
    // 0x8008A63C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void func_80800D00_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D08: jal         0x800839B8
    // 0x80800D0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800D0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D10: jal         0x80800198
    // 0x80800D14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800D14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D20: jr          $ra
    // 0x80800D24: nop

    return;
    // 0x80800D24: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005D0: jal         0x8080051C
    // 0x808005D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x808005D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808005D8: bne         $v0, $zero, L_808005E8
    if (ctx->r2 != 0) {
        // 0x808005DC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808005E8;
    }
    // 0x808005DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: b           L_808005F4
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F4;
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005E8:
    // 0x808005E8: jal         0x80800230
    // 0x808005EC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    gsmaker_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808005EC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808005F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F4:
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005FC: jr          $ra
    // 0x80800600: nop

    return;
    // 0x80800600: nop

;}
RECOMP_FUNC void _idworld_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EF8: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088EF8);
    return;
    // 0x80088EFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chexploder_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808016F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808016F4: jal         0x80100094
    // 0x808016F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016FC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801700: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801704: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80801708: nop

    // 0x8080170C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80801710: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801714: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801718: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080171C: nop

    // 0x80801720: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80801724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080172C: jr          $ra
    // 0x80801730: nop

    return;
    // 0x80801730: nop

;}
RECOMP_FUNC void func_80800BF0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800BF4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800BF8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800BFC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800C00: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800C04: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800C08: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800C0C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800C10: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800C14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800C18: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800C1C: jal         0x80100094
    // 0x80800C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C24: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x80800C28: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800C2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C30: blez        $t6, L_80800CD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800C34: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800CD0;
    }
    // 0x80800C34: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800C38: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800C3C: addiu       $s2, $sp, 0x44
    ctx->r18 = ADD32(ctx->r29, 0X44);
    // 0x80800C40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800C44:
    // 0x80800C44: jal         0x80089AC8
    // 0x80800C48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800C48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800C4C: beq         $v0, $zero, L_80800C88
    if (ctx->r2 == 0) {
        // 0x80800C50: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800C88;
    }
    // 0x80800C50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: jal         0x800F5A00
    // 0x80800C5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800C5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80800C60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800C68: jal         0x800F0064
    // 0x80800C6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x80800C6C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x80800C70: beq         $v0, $zero, L_80800CBC
    if (ctx->r2 == 0) {
        // 0x80800C74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CBC;
    }
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: jal         0x800F7B9C
    // 0x80800C7C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    func_800F7B9C(rdram, ctx);
        goto after_4;
    // 0x80800C7C: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_4:
    // 0x80800C80: b           L_80800CC0
    // 0x80800C84: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
        goto L_80800CC0;
    // 0x80800C84: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
L_80800C88:
    // 0x80800C88: jal         0x80089AD8
    // 0x80800C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800C90: jal         0x80106790
    // 0x80800C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800C98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800C9C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800CA0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800CA4: jal         0x800F0064
    // 0x80800CA8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F0064(rdram, ctx);
        goto after_7;
    // 0x80800CA8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_7:
    // 0x80800CAC: beql        $v0, $zero, L_80800CC0
    if (ctx->r2 == 0) {
        // 0x80800CB0: lbu         $t7, 0x3A($s5)
        ctx->r15 = MEM_BU(ctx->r21, 0X3A);
            goto L_80800CC0;
    }
    goto skip_0;
    // 0x80800CB0: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
    skip_0:
    // 0x80800CB4: jal         0x80800B5C
    // 0x80800CB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800B5C_chcollballcontrol(rdram, ctx);
        goto after_8;
    // 0x80800CB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_80800CBC:
    // 0x80800CBC: lbu         $t7, 0x3A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X3A);
L_80800CC0:
    // 0x80800CC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CC4: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800CC8: bnel        $at, $zero, L_80800C44
    if (ctx->r1 != 0) {
        // 0x80800CCC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800C44;
    }
    goto skip_1;
    // 0x80800CCC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
L_80800CD0:
    // 0x80800CD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800CD4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800CD8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CDC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800CE0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800CE4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800CE8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CEC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800CF0: jr          $ra
    // 0x80800CF4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800CF4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800330_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800334: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800338: slti        $at, $a1, 0x90
    ctx->r1 = SIGNED(ctx->r5) < 0X90 ? 1 : 0;
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800344: bne         $at, $zero, L_80800368
    if (ctx->r1 != 0) {
        // 0x80800348: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800368;
    }
    // 0x80800348: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080034C: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x80800350: beq         $a1, $at, L_80800510
    if (ctx->r5 == ctx->r1) {
        // 0x80800354: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800510;
    }
    // 0x80800354: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800358: beq         $a1, $at, L_808003C4
    if (ctx->r5 == ctx->r1) {
        // 0x8080035C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: b           L_8080055C
    // 0x80800364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080055C;
    // 0x80800364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800368:
    // 0x80800368: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x8080036C: bne         $at, $zero, L_80800388
    if (ctx->r1 != 0) {
        // 0x80800370: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80800388;
    }
    // 0x80800370: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80800374: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800378: beq         $a1, $at, L_808004A4
    if (ctx->r5 == ctx->r1) {
        // 0x8080037C: lw          $t9, 0x48($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X48);
            goto L_808004A4;
    }
    // 0x8080037C: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80800380: b           L_8080055C
    // 0x80800384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080055C;
    // 0x80800384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800388:
    // 0x80800388: sltiu       $at, $t6, 0x40
    ctx->r1 = ctx->r14 < 0X40 ? 1 : 0;
    // 0x8080038C: beq         $at, $zero, L_80800550
    if (ctx->r1 == 0) {
        // 0x80800390: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800550;
    }
    // 0x80800390: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800394: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XE1C) << 16);
    // 0x80800398: addu        $at, $at, $t6
    gpr jr_addend_808003A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080039C: lw          $t6, 0xE1C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1516, 0XE1C));
    // 0x808003A0: jr          $t6
    // 0x808003A4: nop

    switch (jr_addend_808003A0 >> 2) {
        case 0: goto L_80800558; break;
        case 1: goto L_808004BC; break;
        case 2: goto L_80800550; break;
        case 3: goto L_80800550; break;
        case 4: goto L_80800550; break;
        case 5: goto L_80800550; break;
        case 6: goto L_80800550; break;
        case 7: goto L_80800550; break;
        case 8: goto L_80800550; break;
        case 9: goto L_80800550; break;
        case 10: goto L_80800550; break;
        case 11: goto L_80800550; break;
        case 12: goto L_80800550; break;
        case 13: goto L_80800550; break;
        case 14: goto L_80800460; break;
        case 15: goto L_80800550; break;
        case 16: goto L_80800550; break;
        case 17: goto L_80800550; break;
        case 18: goto L_80800550; break;
        case 19: goto L_80800550; break;
        case 20: goto L_80800550; break;
        case 21: goto L_80800550; break;
        case 22: goto L_80800550; break;
        case 23: goto L_80800550; break;
        case 24: goto L_80800550; break;
        case 25: goto L_80800550; break;
        case 26: goto L_80800550; break;
        case 27: goto L_80800550; break;
        case 28: goto L_80800550; break;
        case 29: goto L_80800550; break;
        case 30: goto L_808003A8; break;
        case 31: goto L_80800550; break;
        case 32: goto L_80800550; break;
        case 33: goto L_80800550; break;
        case 34: goto L_80800550; break;
        case 35: goto L_80800550; break;
        case 36: goto L_80800550; break;
        case 37: goto L_80800550; break;
        case 38: goto L_80800550; break;
        case 39: goto L_80800550; break;
        case 40: goto L_80800550; break;
        case 41: goto L_80800550; break;
        case 42: goto L_80800550; break;
        case 43: goto L_80800550; break;
        case 44: goto L_80800550; break;
        case 45: goto L_80800550; break;
        case 46: goto L_80800550; break;
        case 47: goto L_80800550; break;
        case 48: goto L_80800550; break;
        case 49: goto L_80800550; break;
        case 50: goto L_80800550; break;
        case 51: goto L_80800550; break;
        case 52: goto L_80800550; break;
        case 53: goto L_80800550; break;
        case 54: goto L_80800550; break;
        case 55: goto L_80800500; break;
        case 56: goto L_80800550; break;
        case 57: goto L_80800550; break;
        case 58: goto L_80800550; break;
        case 59: goto L_80800550; break;
        case 60: goto L_80800550; break;
        case 61: goto L_80800550; break;
        case 62: goto L_80800550; break;
        case 63: goto L_80800410; break;
        default: switch_error(__func__, 0x808003A0, 0x80800E1C);
    }
    // 0x808003A4: nop

L_808003A8:
    // 0x808003A8: jal         0x801015D0
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808003B0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808003B4: jal         0x800DF744
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808003B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003BC: b           L_8080055C
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003C8: jal         0x800897C0
    // 0x808003CC: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808003CC: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    after_2:
    // 0x808003D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808003D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D8: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x808003DC: jal         0x800897E8
    // 0x808003E0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808003E0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_3:
    // 0x808003E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808003EC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808003F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003F8: jal         0x800897F8
    // 0x808003FC: nop

    _suexpression_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x808003FC: nop

    after_4:
    // 0x80800400: jal         0x80089F60
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800408: b           L_8080055C
    // 0x8080040C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x8080040C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800410:
    // 0x80800410: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080041C: jal         0x80086E28
    // 0x80800420: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chskeletonexplode_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800420: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_6:
    // 0x80800424: jal         0x8010A570
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080042C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1516, 0XFFC) << 16);
    // 0x80800430: addiu       $a2, $a2, 0xFFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1516, 0XFFC));
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800438: jal         0x80089D18
    // 0x8080043C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080043C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800448: jal         0x80089BF8
    // 0x8080044C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    _subaddiejoy_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x8080044C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_9:
    // 0x80800450: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x80800454: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800458: b           L_80800558
    // 0x8080045C: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
        goto L_80800558;
    // 0x8080045C: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
L_80800460:
    // 0x80800460: jal         0x80101080
    // 0x80800464: nop

    func_80101080(rdram, ctx);
        goto after_10;
    // 0x80800464: nop

    after_10:
    // 0x80800468: jal         0x80106790
    // 0x8080046C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_11;
    // 0x8080046C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80800470: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800474: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800478: jal         0x80086E00
    // 0x8080047C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x8080047C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_12:
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x80107070
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_13;
    // 0x80800488: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8080048C: bnel        $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x80800490: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080055C;
    }
    goto skip_0;
    // 0x80800490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800494: jal         0x800FFAB0
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080049C: b           L_8080055C
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x808004A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004A4:
    // 0x808004A4: bne         $t9, $zero, L_80800558
    if (ctx->r25 != 0) {
        // 0x808004A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800558;
    }
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: jal         0x808006B0
    // 0x808004B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808006B0_chnewshovel(rdram, ctx);
        goto after_15;
    // 0x808004B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808004B4: b           L_8080055C
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004BC:
    // 0x808004BC: jal         0x8008A4A8
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808004C4: bne         $v0, $zero, L_808004F0
    if (ctx->r2 != 0) {
        // 0x808004C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004F0;
    }
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x80107070
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_17;
    // 0x808004D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808004D8: bnel        $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x808004DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080055C;
    }
    goto skip_1;
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808004E0: jal         0x80089CA8
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808004E8: b           L_8080055C
    // 0x808004EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x808004EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004F0:
    // 0x808004F0: jal         0x808006B0
    // 0x808004F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808006B0_chnewshovel(rdram, ctx);
        goto after_19;
    // 0x808004F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_19:
    // 0x808004F8: b           L_8080055C
    // 0x808004FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x808004FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800500:
    // 0x80800500: jal         0x80800DC8
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DC8_chnewshovel(rdram, ctx);
        goto after_20;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800508: b           L_80800560
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800560;
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800510:
    // 0x80800510: jal         0x80089828
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_21;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800518: bne         $v0, $zero, L_80800528
    if (ctx->r2 != 0) {
        // 0x8080051C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800528;
    }
    // 0x8080051C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800520: b           L_8080055C
    // 0x80800524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080055C;
    // 0x80800524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800528:
    // 0x80800528: jal         0x800EFD24
    // 0x8080052C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_22;
    // 0x8080052C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_22:
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800538: jal         0x800897F0
    // 0x8080053C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    _suexpression_entrypoint_13(rdram, ctx);
        goto after_23;
    // 0x8080053C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_23:
    // 0x80800540: jal         0x80101010
    // 0x80800544: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_80101010(rdram, ctx);
        goto after_24;
    // 0x80800544: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_24:
    // 0x80800548: b           L_8080055C
    // 0x8080054C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080055C;
    // 0x8080054C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800550:
    // 0x80800550: b           L_8080055C
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080055C;
    // 0x80800554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800558:
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080055C:
    // 0x8080055C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800560:
    // 0x80800560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800564: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800568: jr          $ra
    // 0x8080056C: nop

    return;
    // 0x8080056C: nop

;}
RECOMP_FUNC void _chmole_hailfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E80: syscall     464
    recomp_syscall_handler(rdram, ctx, 0x80086E80);
    return;
    // 0x80086E84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _mlwave_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FE8: syscall     754
    recomp_syscall_handler(rdram, ctx, 0x80088FE8);
    return;
    // 0x80088FEC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _ncbabee_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896D0: syscall     787
    recomp_syscall_handler(rdram, ctx, 0x800896D0);
    return;
    // 0x800896D4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazjump_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800944: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080094C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800950: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800954: jal         0x8008CABC
    // 0x80800958: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800958: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x8080095C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800964: jal         0x8009BB24
    // 0x80800968: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x80800968: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8080096C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800970: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800978: beq         $v0, $at, L_80800990
    if (ctx->r2 == ctx->r1) {
        // 0x8080097C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800990;
    }
    // 0x8080097C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800980: beq         $v0, $at, L_808009CC
    if (ctx->r2 == ctx->r1) {
        // 0x80800984: nop
    
            goto L_808009CC;
    }
    // 0x80800984: nop

    // 0x80800988: b           L_808009CC
    // 0x8080098C: nop

        goto L_808009CC;
    // 0x8080098C: nop

L_80800990:
    // 0x80800990: jal         0x8008DF8C
    // 0x80800994: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_2;
    // 0x80800994: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x80800998: beq         $v0, $zero, L_808009CC
    if (ctx->r2 == 0) {
        // 0x8080099C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808009CC;
    }
    // 0x8080099C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808009A4: jal         0x8008B1D4
    // 0x808009A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_3;
    // 0x808009A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x808009AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009B0: jal         0x8008B1BC
    // 0x808009B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x808009B4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x808009B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009BC: jal         0x8008B134
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808009C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808009C8: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808009CC:
    // 0x808009CC: jal         0x8008E078
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_6;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009D4: beq         $v0, $zero, L_808009E4
    if (ctx->r2 == 0) {
        // 0x808009D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009E4;
    }
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: addiu       $t7, $zero, 0xBB
    ctx->r15 = ADD32(0, 0XBB);
    // 0x808009E0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808009E4:
    // 0x808009E4: jal         0x8009E5C8
    // 0x808009E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808009E8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x808009EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009F4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009F8: jr          $ra
    // 0x808009FC: nop

    return;
    // 0x808009FC: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802058: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080205C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2EC0) << 16);
    // 0x80802060: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802064: jr          $ra
    // 0x80802068: lw          $v0, 0x2EC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EC0));
    return;
    // 0x80802068: lw          $v0, 0x2EC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EC0));
;}
RECOMP_FUNC void func_80013A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013A60: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80013A64: jal         0x80013ABC
    // 0x80013A68: lwc1        $f14, 0x1700($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1700);
    func_80013ABC(rdram, ctx);
        goto after_0;
    // 0x80013A68: lwc1        $f14, 0x1700($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1700);
    after_0:
    // 0x80013A6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013A70: lwc1        $f2, 0x1704($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1704);
    // 0x80013A74: jr          $a3
    // 0x80013A78: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    LOOKUP_FUNC(ctx->r7)(rdram, ctx);
    return;
    // 0x80013A78: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
;}
RECOMP_FUNC void chlavafall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1512, 0XB0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1512, 0XB0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1512, 0XB0));
;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808030AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808030B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808030B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808030B8: jal         0x80106790
    // 0x808030BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808030BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808030C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808030C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808030C8: jal         0x80100094
    // 0x808030CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808030CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808030D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808030D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808030D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808030DC: beq         $a0, $at, L_808030FC
    if (ctx->r4 == ctx->r1) {
        // 0x808030E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808030FC;
    }
    // 0x808030E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808030E4: bne         $a0, $at, L_80803138
    if (ctx->r4 != ctx->r1) {
        // 0x808030E8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80803138;
    }
    // 0x808030E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808030EC: jal         0x80801944
    // 0x808030F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x808030F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808030F4: b           L_8080313C
    // 0x808030F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080313C;
    // 0x808030F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808030FC:
    // 0x808030FC: jal         0x800D8FF8
    // 0x80803100: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80803100: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x80803104: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80803108: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8080310C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80803110: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80803114: bgez        $t6, L_80803128
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80803118: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80803128;
    }
    // 0x80803118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080311C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803120: nop

    // 0x80803124: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80803128:
    // 0x80803128: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080312C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80803130: jal         0x80803538
    // 0x80803134: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80803538_chstoneballcontrol(rdram, ctx);
        goto after_4;
    // 0x80803134: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
L_80803138:
    // 0x80803138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080313C:
    // 0x8080313C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803140: jr          $ra
    // 0x80803144: nop

    return;
    // 0x80803144: nop

;}
RECOMP_FUNC void func_80800B10_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B18: jal         0x808004CC
    // 0x80800B1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800B1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B28: jal         0x80800A24
    // 0x80800B2C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800A24_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x80800B2C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_808009B0_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808009C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808009C8: jal         0x80100094
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808009D4: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x808009D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808009DC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x808009E0: beq         $v1, $zero, L_80800A00
    if (ctx->r3 == 0) {
        // 0x808009E4: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800A00;
    }
    // 0x808009E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009E8: beq         $v1, $at, L_80800A08
    if (ctx->r3 == ctx->r1) {
        // 0x808009EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A08;
    }
    // 0x808009EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009F0: beql        $v1, $at, L_80800A48
    if (ctx->r3 == ctx->r1) {
        // 0x808009F4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800A48;
    }
    goto skip_0;
    // 0x808009F4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808009F8: b           L_80800A54
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A54;
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A00:
    // 0x80800A00: jal         0x800856B0
    // 0x80800A04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800A04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
L_80800A08:
    // 0x80800A08: jal         0x800856E0
    // 0x80800A0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800A0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800A10: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800A14: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800A18: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(892, 0XFBC) << 16);
    // 0x80800A1C: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x80800A20: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80800A24: jal         0x80088090
    // 0x80800A28: addiu       $a0, $a0, 0xFBC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0XFBC));
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800A28: addiu       $a0, $a0, 0xFBC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0XFBC));
    after_3:
    // 0x80800A2C: jal         0x80088098
    // 0x80800A30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800A30: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x80800A34: jal         0x800880A0
    // 0x80800A38: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800A38: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x80800A3C: jal         0x800880B8
    // 0x80800A40: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800A40: nop

    after_6:
    // 0x80800A44: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80800A48:
    // 0x80800A48: jal         0x800856D8
    // 0x80800A4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _capod_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800A4C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A54:
    // 0x80800A54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A5C: jr          $ra
    // 0x80800A60: nop

    return;
    // 0x80800A60: nop

;}
RECOMP_FUNC void func_8080016C_chscreenadjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800170: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800174: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800178: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: bne         $a1, $at, L_808001CC
    if (ctx->r5 != ctx->r1) {
        // 0x80800184: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808001CC;
    }
    // 0x80800184: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800188: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080018C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jal         0x800886E8
    // 0x80800194: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _glglobalsettings_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800194: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800198: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080019C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808001A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001A4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808001A8: nop

    // 0x808001AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001B0: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x808001B4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808001B8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x808001BC: nop

    // 0x808001C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001C4: b           L_808001D0
    // 0x808001C8: swc1        $f10, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f10.u32l;
        goto L_808001D0;
    // 0x808001C8: swc1        $f10, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f10.u32l;
L_808001CC:
    // 0x808001CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001D0:
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_80800190_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080019C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A0: jal         0x8008CABC
    // 0x808001A4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x808001A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8009BCB4
    // 0x808001B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x808001B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x808001B8: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x808001BC: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x808001C0: jal         0x8009BCC4
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x800961AC
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x8009BC5C
    // 0x808001DC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_4;
    // 0x808001DC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x808001E0: jal         0x800A046C
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_5;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001E8: jal         0x800A3298
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3298(rdram, ctx);
        goto after_6;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001F0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808001F4: jal         0x8008AF24
    // 0x808001F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_7;
    // 0x808001F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x808001FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800200: jal         0x8008AED4
    // 0x80800204: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x80800204: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    after_8:
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080020C: jal         0x8008B134
    // 0x80800210: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x80800210: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800214: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80800218: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080021C: jal         0x8008B1BC
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_10;
    // 0x80800220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800224: lui         $a1, 0x3F24
    ctx->r5 = S32(0X3F24 << 16);
    // 0x80800228: ori         $a1, $a1, 0x25AF
    ctx->r5 = ctx->r5 | 0X25AF;
    // 0x8080022C: jal         0x8008B24C
    // 0x80800230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800234: jal         0x8008B064
    // 0x80800238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x80800238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8080023C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800240: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800244: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80800248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080024C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800250: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800254: lui         $a3, 0xC396
    ctx->r7 = S32(0XC396 << 16);
    // 0x80800258: jal         0x800F10B4
    // 0x8080025C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x8080025C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x80800260: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800264: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800268: jal         0x8009BA58
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800270: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800274: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800280: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800284: jal         0x8009FFD8
    // 0x80800288: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_15;
    // 0x80800288: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_15:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800294: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800298: jr          $ra
    // 0x8080029C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080029C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800968_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080096C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800970: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800974: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800978: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080097C: jal         0x80100094
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800984: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800988: jal         0x80800734
    // 0x8080098C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800734_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x8080098C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800990: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800994: lbu         $t7, 0xFA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XFA);
    // 0x80800998: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8080099C: beq         $at, $zero, L_808009E4
    if (ctx->r1 == 0) {
        // 0x808009A0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808009E4;
    }
    // 0x808009A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808009A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X36BC) << 16);
    // 0x808009A8: addu        $at, $at, $t7
    gpr jr_addend_808009B0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808009AC: lw          $t7, 0x36BC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X36BC));
    // 0x808009B0: jr          $t7
    // 0x808009B4: nop

    switch (jr_addend_808009B0 >> 2) {
        case 0: goto L_808009B8; break;
        case 1: goto L_808009C4; break;
        case 2: goto L_808009C4; break;
        case 3: goto L_808009D0; break;
        case 4: goto L_808009C4; break;
        default: switch_error(__func__, 0x808009B0, 0x808036BC);
    }
    // 0x808009B4: nop

L_808009B8:
    // 0x808009B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009BC: jal         0x80800700
    // 0x808009C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800700_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x808009C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_808009C4:
    // 0x808009C4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808009CC: sb          $t8, 0xFA($t9)
    MEM_B(0XFA, ctx->r25) = ctx->r24;
L_808009D0:
    // 0x808009D0: jal         0x800856E0
    // 0x808009D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808009D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808009D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009DC: jal         0x80800240
    // 0x808009E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800240_chclockworkmouse(rdram, ctx);
        goto after_4;
    // 0x808009E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
L_808009E4:
    // 0x808009E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009EC: jr          $ra
    // 0x808009F0: nop

    return;
    // 0x808009F0: nop

;}
RECOMP_FUNC void func_800F549C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F549C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F54A0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F54A4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800F54A8: lw          $a2, 0x5490($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5490);
    // 0x800F54AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F54B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F54B4: beql        $a2, $zero, L_800F54D0
    if (ctx->r6 == 0) {
        // 0x800F54B8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800F54D0;
    }
    goto skip_0;
    // 0x800F54B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x800F54BC: jal         0x80091538
    // 0x800F54C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    bastatetimer_get(rdram, ctx);
        goto after_0;
    // 0x800F54C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800F54C4: b           L_800F54D8
    // 0x800F54C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F54D8;
    // 0x800F54C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F54CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800F54D0:
    // 0x800F54D0: nop

    // 0x800F54D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F54D8:
    // 0x800F54D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F54DC: jr          $ra
    // 0x800F54E0: nop

    return;
    // 0x800F54E0: nop

;}
RECOMP_FUNC void func_80113FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113FF0: lbu         $t6, 0x50($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X50);
    // 0x80113FF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80113FF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80113FFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80114000: beq         $t6, $zero, L_80114010
    if (ctx->r14 == 0) {
        // 0x80114004: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80114010;
    }
    // 0x80114004: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80114008: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8011400C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80114010:
    // 0x80114010: lbu         $t7, 0x5C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5C);
    // 0x80114014: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80114018: beql        $t7, $zero, L_80114044
    if (ctx->r15 == 0) {
        // 0x8011401C: lbu         $t8, 0x68($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X68);
            goto L_80114044;
    }
    goto skip_0;
    // 0x8011401C: lbu         $t8, 0x68($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X68);
    skip_0:
    // 0x80114020: beq         $v1, $a2, L_80114038
    if (ctx->r3 == ctx->r6) {
        // 0x80114024: lwc1        $f2, 0x58($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X58);
            goto L_80114038;
    }
    // 0x80114024: lwc1        $f2, 0x58($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80114028: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8011402C: nop

    // 0x80114030: bc1fl       L_80114044
    if (!c1cs) {
        // 0x80114034: lbu         $t8, 0x68($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X68);
            goto L_80114044;
    }
    goto skip_1;
    // 0x80114034: lbu         $t8, 0x68($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X68);
    skip_1:
L_80114038:
    // 0x80114038: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8011403C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80114040: lbu         $t8, 0x68($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X68);
L_80114044:
    // 0x80114044: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80114048: beql        $t8, $zero, L_80114074
    if (ctx->r24 == 0) {
        // 0x8011404C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80114074;
    }
    goto skip_2;
    // 0x8011404C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_2:
    // 0x80114050: beq         $v1, $a2, L_80114068
    if (ctx->r3 == ctx->r6) {
        // 0x80114054: lwc1        $f2, 0x64($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X64);
            goto L_80114068;
    }
    // 0x80114054: lwc1        $f2, 0x64($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X64);
    // 0x80114058: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8011405C: nop

    // 0x80114060: bc1fl       L_80114074
    if (!c1cs) {
        // 0x80114064: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80114074;
    }
    goto skip_3;
    // 0x80114064: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_3:
L_80114068:
    // 0x80114068: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8011406C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80114070: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80114074:
    // 0x80114074: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80114078: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8011407C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80114080: addu        $a1, $a0, $t9
    ctx->r5 = ADD32(ctx->r4, ctx->r25);
    // 0x80114084: lbu         $t0, 0x50($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X50);
    // 0x80114088: beql        $t0, $zero, L_801140B8
    if (ctx->r8 == 0) {
        // 0x8011408C: lbu         $t1, 0x5C($a1)
        ctx->r9 = MEM_BU(ctx->r5, 0X5C);
            goto L_801140B8;
    }
    goto skip_4;
    // 0x8011408C: lbu         $t1, 0x5C($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X5C);
    skip_4:
    // 0x80114090: beql        $v1, $a2, L_801140B0
    if (ctx->r3 == ctx->r6) {
        // 0x80114094: lwc1        $f0, 0x4C($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X4C);
            goto L_801140B0;
    }
    goto skip_5;
    // 0x80114094: lwc1        $f0, 0x4C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4C);
    skip_5:
    // 0x80114098: lwc1        $f4, 0x4C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x8011409C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801140A0: nop

    // 0x801140A4: bc1fl       L_801140B8
    if (!c1cs) {
        // 0x801140A8: lbu         $t1, 0x5C($a1)
        ctx->r9 = MEM_BU(ctx->r5, 0X5C);
            goto L_801140B8;
    }
    goto skip_6;
    // 0x801140A8: lbu         $t1, 0x5C($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X5C);
    skip_6:
    // 0x801140AC: lwc1        $f0, 0x4C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4C);
L_801140B0:
    // 0x801140B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801140B4: lbu         $t1, 0x5C($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X5C);
L_801140B8:
    // 0x801140B8: beql        $t1, $zero, L_801140E4
    if (ctx->r9 == 0) {
        // 0x801140BC: lbu         $t2, 0x68($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X68);
            goto L_801140E4;
    }
    goto skip_7;
    // 0x801140BC: lbu         $t2, 0x68($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X68);
    skip_7:
    // 0x801140C0: beq         $v1, $a2, L_801140D8
    if (ctx->r3 == ctx->r6) {
        // 0x801140C4: lwc1        $f2, 0x58($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X58);
            goto L_801140D8;
    }
    // 0x801140C4: lwc1        $f2, 0x58($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X58);
    // 0x801140C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801140CC: nop

    // 0x801140D0: bc1fl       L_801140E4
    if (!c1cs) {
        // 0x801140D4: lbu         $t2, 0x68($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X68);
            goto L_801140E4;
    }
    goto skip_8;
    // 0x801140D4: lbu         $t2, 0x68($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X68);
    skip_8:
L_801140D8:
    // 0x801140D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801140DC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x801140E0: lbu         $t2, 0x68($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X68);
L_801140E4:
    // 0x801140E4: beql        $t2, $zero, L_80114110
    if (ctx->r10 == 0) {
        // 0x801140E8: lbu         $t3, 0x74($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X74);
            goto L_80114110;
    }
    goto skip_9;
    // 0x801140E8: lbu         $t3, 0x74($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X74);
    skip_9:
    // 0x801140EC: beq         $v1, $a2, L_80114104
    if (ctx->r3 == ctx->r6) {
        // 0x801140F0: lwc1        $f2, 0x64($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X64);
            goto L_80114104;
    }
    // 0x801140F0: lwc1        $f2, 0x64($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X64);
    // 0x801140F4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801140F8: nop

    // 0x801140FC: bc1fl       L_80114110
    if (!c1cs) {
        // 0x80114100: lbu         $t3, 0x74($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X74);
            goto L_80114110;
    }
    goto skip_10;
    // 0x80114100: lbu         $t3, 0x74($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X74);
    skip_10:
L_80114104:
    // 0x80114104: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80114108: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x8011410C: lbu         $t3, 0x74($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X74);
L_80114110:
    // 0x80114110: beq         $t3, $zero, L_80114134
    if (ctx->r11 == 0) {
        // 0x80114114: nop
    
            goto L_80114134;
    }
    // 0x80114114: nop

    // 0x80114118: beq         $v1, $a2, L_80114130
    if (ctx->r3 == ctx->r6) {
        // 0x8011411C: lwc1        $f2, 0x70($a1)
        ctx->f2.u32l = MEM_W(ctx->r5, 0X70);
            goto L_80114130;
    }
    // 0x8011411C: lwc1        $f2, 0x70($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X70);
    // 0x80114120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80114124: nop

    // 0x80114128: bc1f        L_80114134
    if (!c1cs) {
        // 0x8011412C: nop
    
            goto L_80114134;
    }
    // 0x8011412C: nop

L_80114130:
    // 0x80114130: addiu       $v1, $v0, 0x3
    ctx->r3 = ADD32(ctx->r2, 0X3);
L_80114134:
    // 0x80114134: jr          $ra
    // 0x80114138: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80114138: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bsjump_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832A8: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832A8);
    return;
    // 0x800832AC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void do_crc_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EAB4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001EAB8: addiu       $a0, $a0, -0x164C
    ctx->r4 = ADD32(ctx->r4, -0X164C);
    // 0x8001EABC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8001EAC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001EAC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001EAC8: sltu        $t6, $zero, $v1
    ctx->r14 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001EACC: beq         $t6, $zero, L_8001EAE8
    if (ctx->r14 == 0) {
        // 0x8001EAD0: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8001EAE8;
    }
    // 0x8001EAD0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8001EAD4: jal         0x8001E8E4
    // 0x8001EAD8: nop

    advance_crc_check(rdram, ctx);
        goto after_0;
    // 0x8001EAD8: nop

    after_0:
    // 0x8001EADC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001EAE0: addiu       $a0, $a0, -0x164C
    ctx->r4 = ADD32(ctx->r4, -0X164C);
    // 0x8001EAE4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_8001EAE8:
    // 0x8001EAE8: bne         $v1, $zero, L_8001EAF8
    if (ctx->r3 != 0) {
        // 0x8001EAEC: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_8001EAF8;
    }
    // 0x8001EAEC: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_8001EAF0:
    // 0x8001EAF0: b           L_8001EAF0
    pause_self(rdram);
    // 0x8001EAF4: nop

L_8001EAF8:
    // 0x8001EAF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001EAFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001EB00: jr          $ra
    // 0x8001EB04: nop

    return;
    // 0x8001EB04: nop

;}
RECOMP_FUNC void gcdialogexec_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801C7C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80801C80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801C84: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801C88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801C8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80801C90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801C94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801C98: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80801C9C: addiu       $a1, $a1, 0xE06
    ctx->r5 = ADD32(ctx->r5, 0XE06);
    // 0x80801CA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801CA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80801CA8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80801CAC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80801CB0: jal         0x808016A0
    // 0x80801CB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    gcdialogexec_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801CB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80801CB8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801CBC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80801CC0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80801CC4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80801CC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80801CCC: jal         0x808011A4
    // 0x80801CD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_808011A4_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x80801CD0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80801CD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801CD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801CDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801CE0: jr          $ra
    // 0x80801CE4: nop

    return;
    // 0x80801CE4: nop

;}
