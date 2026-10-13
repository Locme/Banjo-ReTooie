#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _gcnewoption_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DF0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DF0);
    return;
    // 0x80087DF4: addi        $t0, $zero, 0xAC
    ctx->r8 = ADD32(0, 0XAC);
;}
RECOMP_FUNC void func_808009C8_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808009CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009D4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808009D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009DC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009E0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808009E4: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x808009E8: beq         $at, $zero, L_80800AA4
    if (ctx->r1 == 0) {
        // 0x808009EC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800AA4;
    }
    // 0x808009EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808009F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2276, 0X18F0) << 16);
    // 0x808009F4: addu        $at, $at, $t8
    gpr jr_addend_808009FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808009F8: lw          $t8, 0x18F0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2276, 0X18F0));
    // 0x808009FC: jr          $t8
    // 0x80800A00: nop

    switch (jr_addend_808009FC >> 2) {
        case 0: goto L_80800A04; break;
        case 1: goto L_80800AA4; break;
        case 2: goto L_80800AA4; break;
        case 3: goto L_80800A04; break;
        case 4: goto L_80800A04; break;
        case 5: goto L_80800AA4; break;
        case 6: goto L_80800AA4; break;
        case 7: goto L_80800A50; break;
        case 8: goto L_80800A04; break;
        case 9: goto L_80800A50; break;
        case 10: goto L_80800AA4; break;
        case 11: goto L_80800AA4; break;
        case 12: goto L_80800A04; break;
        default: switch_error(__func__, 0x808009FC, 0x808018F0);
    }
    // 0x80800A00: nop

L_80800A04:
    // 0x80800A04: jal         0x800F54E4
    // 0x80800A08: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800A08: nop

    after_0:
    // 0x80800A0C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800A10: jal         0x80103EF4
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_1;
    // 0x80800A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A18: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800A1C: jal         0x80103EAC
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_2;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800A24: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A2C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A30: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800A34: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A38: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800A3C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800A40: jal         0x800F4EC8
    // 0x80800A44: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_3;
    // 0x80800A44: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800A48: b           L_80800AA8
    // 0x80800A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x80800A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A50:
    // 0x80800A50: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800A54: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80800A58: bnel        $t0, $zero, L_80800AA8
    if (ctx->r8 != 0) {
        // 0x80800A5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800AA8;
    }
    goto skip_0;
    // 0x80800A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A60: jal         0x800F54E4
    // 0x80800A64: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800A64: nop

    after_4:
    // 0x80800A68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800A6C: jal         0x80103EF4
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_5;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800A78: jal         0x80103EAC
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_6;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A80: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800A84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A88: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A8C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800A90: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800A94: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800A98: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800A9C: jal         0x800F4EC8
    // 0x80800AA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_7;
    // 0x80800AA0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
L_80800AA4:
    // 0x80800AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AA8:
    // 0x80800AA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: nop

    return;
    // 0x80800AB4: nop

;}
RECOMP_FUNC void func_80800BDC_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800BE0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BE4: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800BE8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800BEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BF0: beq         $a1, $at, L_80800C5C
    if (ctx->r5 == ctx->r1) {
        // 0x80800BF4: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80800C5C;
    }
    // 0x80800BF4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800BF8: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800BFC: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800C00: addiu       $at, $zero, 0x1371
        ctx->r1 = ADD32(0, 0X1371);
            goto L_80800C54;
    }
    // 0x80800C00: addiu       $at, $zero, 0x1371
    ctx->r1 = ADD32(0, 0X1371);
    // 0x80800C04: beq         $a1, $at, L_80800C44
    if (ctx->r5 == ctx->r1) {
        // 0x80800C08: addiu       $at, $zero, 0x1372
        ctx->r1 = ADD32(0, 0X1372);
            goto L_80800C44;
    }
    // 0x80800C08: addiu       $at, $zero, 0x1372
    ctx->r1 = ADD32(0, 0X1372);
    // 0x80800C0C: beq         $a1, $at, L_80800C28
    if (ctx->r5 == ctx->r1) {
        // 0x80800C10: addiu       $a2, $zero, 0x22
        ctx->r6 = ADD32(0, 0X22);
            goto L_80800C28;
    }
    // 0x80800C10: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800C14: addiu       $at, $zero, 0x1373
    ctx->r1 = ADD32(0, 0X1373);
    // 0x80800C18: beq         $a1, $at, L_80800C4C
    if (ctx->r5 == ctx->r1) {
        // 0x80800C1C: addiu       $at, $zero, 0x137C
        ctx->r1 = ADD32(0, 0X137C);
            goto L_80800C4C;
    }
    // 0x80800C1C: addiu       $at, $zero, 0x137C
    ctx->r1 = ADD32(0, 0X137C);
    // 0x80800C20: beq         $a1, $at, L_80800C54
    if (ctx->r5 == ctx->r1) {
        // 0x80800C24: nop
    
            goto L_80800C54;
    }
    // 0x80800C24: nop

L_80800C28:
    // 0x80800C28: jal         0x800F54E4
    // 0x80800C2C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800C2C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C34: jal         0x800F7F98
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_1;
    // 0x80800C38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800C3C: b           L_80800C60
    // 0x80800C40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
        goto L_80800C60;
    // 0x80800C40: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_80800C44:
    // 0x80800C44: b           L_80800C60
    // 0x80800C48: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
        goto L_80800C60;
    // 0x80800C48: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
L_80800C4C:
    // 0x80800C4C: b           L_80800C60
    // 0x80800C50: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
        goto L_80800C60;
    // 0x80800C50: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_80800C54:
    // 0x80800C54: b           L_80800C60
    // 0x80800C58: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
        goto L_80800C60;
    // 0x80800C58: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
L_80800C5C:
    // 0x80800C5C: addiu       $a2, $zero, 0x144
    ctx->r6 = ADD32(0, 0X144);
L_80800C60:
    // 0x80800C60: jal         0x80086B58
    // 0x80800C64: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800C64: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800C68: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800C6C: addiu       $t7, $zero, 0xA3
    ctx->r15 = ADD32(0, 0XA3);
    // 0x80800C70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C74: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800C78: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800C7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C80: jal         0x8008A208
    // 0x80800C84: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800C84: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_3:
    // 0x80800C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C90: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C94: jr          $ra
    // 0x80800C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800C98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void ncbapivot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080002C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800038: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8080003C: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800040: jal         0x801120CC
    // 0x80800044: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x80800044: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800050: jal         0x80111B8C
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x80800054: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x801124D0
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x80115858
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_3;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: jal         0x80115870
    // 0x80800078: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_4;
    // 0x80800078: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_4:
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_800C8900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8904: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C890C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8910: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8914: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8918: jal         0x800B28CC
    // 0x800C891C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C891C: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C8920: lbu         $t6, 0x17($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X17);
    // 0x800C8924: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8928: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C892C: bne         $t6, $zero, L_800C8948
    if (ctx->r14 != 0) {
        // 0x800C8930: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800C8948;
    }
    // 0x800C8930: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C8934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C8938: jal         0x800EFA88
    // 0x800C893C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA88(rdram, ctx);
        goto after_1;
    // 0x800C893C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800C8940: b           L_800C8954
    // 0x800C8944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C8954;
    // 0x800C8944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8948:
    // 0x800C8948: jal         0x800F2EE0
    // 0x800C894C: addiu       $a1, $v1, 0xA
    ctx->r5 = ADD32(ctx->r3, 0XA);
    func_800F2EE0(rdram, ctx);
        goto after_2;
    // 0x800C894C: addiu       $a1, $v1, 0xA
    ctx->r5 = ADD32(ctx->r3, 0XA);
    after_2:
    // 0x800C8950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8954:
    // 0x800C8954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8958: jr          $ra
    // 0x800C895C: nop

    return;
    // 0x800C895C: nop

;}
RECOMP_FUNC void bsdronexform_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A68: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A78: jal         0x800848F8
    // 0x80800A7C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    _badronemem_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800A7C: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_0:
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800A88: jal         0x80084650
    // 0x80800A8C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800A8C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A94: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A98: jal         0x8008CB3C
    // 0x80800A9C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800A9C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800AA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80800AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AB4: jal         0x8009FFD8
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: jal         0x8009BA9C
    // 0x80800AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80800AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x8009B94C
    // 0x80800AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_5;
    // 0x80800AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x8009BF5C
    // 0x80800ADC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_6;
    // 0x80800ADC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE4: jal         0x8009C4CC
    // 0x80800AE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80800AE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF0: jal         0x800961AC
    // 0x80800AF4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_8;
    // 0x80800AF4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x80800AF8: jal         0x80800304
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800304_bsdronexform(rdram, ctx);
        goto after_9;
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B00: jal         0x808006BC
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006BC_bsdronexform(rdram, ctx);
        goto after_10;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800B08: jal         0x800A3274
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_11;
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800B10: lw          $t7, 0x18C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18C);
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: jal         0x800A33F8
    // 0x80800B1C: sb          $v0, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r2;
    func_800A33F8(rdram, ctx);
        goto after_12;
    // 0x80800B1C: sb          $v0, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r2;
    after_12:
    // 0x80800B20: lw          $t8, 0x18C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18C);
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80800B2C: jal         0x80095760
    // 0x80800B30: sb          $v0, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r2;
    baflag_set(rdram, ctx);
        goto after_13;
    // 0x80800B30: sb          $v0, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r2;
    after_13:
    // 0x80800B34: lw          $t9, 0x18C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18C);
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800B40: jal         0x80800758
    // 0x80800B44: sb          $zero, 0x32($t9)
    MEM_B(0X32, ctx->r25) = 0;
    func_80800758_bsdronexform(rdram, ctx);
        goto after_14;
    // 0x80800B44: sb          $zero, 0x32($t9)
    MEM_B(0X32, ctx->r25) = 0;
    after_14:
    // 0x80800B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B54: jr          $ra
    // 0x80800B58: nop

    return;
    // 0x80800B58: nop

;}
RECOMP_FUNC void func_80800FCC_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FD4: jal         0x800EA05C
    // 0x80800FD8: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800FD8: nop

    after_0:
    // 0x80800FDC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1192, 0X10A0) << 16);
    // 0x80800FE0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1192, 0X10DC) << 16);
    // 0x80800FE4: addiu       $a0, $a0, 0x10DC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1192, 0X10DC));
    // 0x80800FE8: addiu       $v1, $v1, 0x10A0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1192, 0X10A0));
    // 0x80800FEC: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
L_80800FF0:
    // 0x80800FF0: bnel        $v0, $t6, L_80801004
    if (ctx->r2 != ctx->r14) {
        // 0x80800FF4: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80801004;
    }
    goto skip_0;
    // 0x80800FF4: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_0:
    // 0x80800FF8: b           L_80801010
    // 0x80800FFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80801010;
    // 0x80800FFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801000: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_80801004:
    // 0x80801004: bnel        $v1, $a0, L_80800FF0
    if (ctx->r3 != ctx->r4) {
        // 0x80801008: lhu         $t6, 0x0($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X0);
            goto L_80800FF0;
    }
    goto skip_1;
    // 0x80801008: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    skip_1:
    // 0x8080100C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801010:
    // 0x80801010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801018: jr          $ra
    // 0x8080101C: nop

    return;
    // 0x8080101C: nop

;}
RECOMP_FUNC void func_80801508_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080150C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801510: jal         0x8010C500
    // 0x80801514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80801514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801518: beq         $v0, $zero, L_8080153C
    if (ctx->r2 == 0) {
        // 0x8080151C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080153C;
    }
    // 0x8080151C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801520: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801524: jal         0x8010C9B0
    // 0x80801528: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x80801528: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_1:
    // 0x8080152C: beq         $v0, $zero, L_8080153C
    if (ctx->r2 == 0) {
        // 0x80801530: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080153C;
    }
    // 0x80801530: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801534: jal         0x80800218
    // 0x80801538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800218_chpiranha(rdram, ctx);
        goto after_2;
    // 0x80801538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
L_8080153C:
    // 0x8080153C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801544: jr          $ra
    // 0x80801548: nop

    return;
    // 0x80801548: nop

;}
RECOMP_FUNC void _chfactorybtwmdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874F0: syscall     580
    recomp_syscall_handler(rdram, ctx, 0x800874F0);
    return;
    // 0x800874F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808015E8_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015E8: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x808015EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015F0: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x808015F4: beq         $t6, $zero, L_80801604
    if (ctx->r14 == 0) {
        // 0x808015F8: nop
    
            goto L_80801604;
    }
    // 0x808015F8: nop

    // 0x808015FC: beq         $t6, $at, L_80801604
    if (ctx->r14 == ctx->r1) {
        // 0x80801600: nop
    
            goto L_80801604;
    }
    // 0x80801600: nop

L_80801604:
    // 0x80801604: jr          $ra
    // 0x80801608: nop

    return;
    // 0x80801608: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842B0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842B0);
    return;
    // 0x800842B4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800EFB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFB8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFB90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFB94: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EFB98: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EFB9C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800EFBA0: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EFBA4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EFBA8: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EFBAC: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800EFBB0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EFBB4: bc1f        L_800EFBCC
    if (!c1cs) {
        // 0x800EFBB8: nop
    
            goto L_800EFBCC;
    }
    // 0x800EFBB8: nop

    // 0x800EFBBC: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x800EFBC0: nop

    // 0x800EFBC4: bc1tl       L_800EFBEC
    if (c1cs) {
        // 0x800EFBC8: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800EFBEC;
    }
    goto skip_0;
    // 0x800EFBC8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
L_800EFBCC:
    // 0x800EFBCC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EFBD0: nop

    // 0x800EFBD4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EFBD8: jal         0x8002DCA0
    // 0x800EFBDC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EFBDC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800EFBE0: b           L_800EFBF0
    // 0x800EFBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EFBF0;
    // 0x800EFBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFBE8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800EFBEC:
    // 0x800EFBEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EFBF0:
    // 0x800EFBF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EFBF4: jr          $ra
    // 0x800EFBF8: nop

    return;
    // 0x800EFBF8: nop

;}
RECOMP_FUNC void func_808002A0_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002AC: jal         0x8009E6EC
    // 0x808002B0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808002B0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002B4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002B8: jal         0x8008CABC
    // 0x808002BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x808002BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002C0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(348, 0X9D0) << 16);
    // 0x808002C4: addiu       $s0, $a0, 0x9D0
    ctx->r16 = ADD32(ctx->r4, (int16_t)RELOC_LO16(348, 0X9D0));
    // 0x808002C8: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x808002CC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x808002D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002D4: beq         $t6, $zero, L_80800490
    if (ctx->r14 == 0) {
        // 0x808002D8: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(348, 0X9D0) << 16);
            goto L_80800490;
    }
    // 0x808002D8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(348, 0X9D0) << 16);
    // 0x808002DC: addiu       $t7, $t7, 0x9D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(348, 0X9D0));
    // 0x808002E0: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
L_808002E4:
    // 0x808002E4: bne         $v1, $v0, L_80800480
    if (ctx->r3 != ctx->r2) {
        // 0x808002E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800480;
    }
    // 0x808002E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002EC: jal         0x8008B264
    // 0x808002F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    anctrl_getIndex(rdram, ctx);
        goto after_2;
    // 0x808002F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_2:
    // 0x808002F4: lbu         $a0, 0xA($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA);
    // 0x808002F8: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x808002FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800300: xor         $a1, $t0, $a0
    ctx->r5 = ctx->r8 ^ ctx->r4;
    // 0x80800304: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80800308: xor         $a3, $v0, $t8
    ctx->r7 = ctx->r2 ^ ctx->r24;
    // 0x8080030C: sltiu       $a3, $a3, 0x1
    ctx->r7 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x80800310: beq         $a1, $zero, L_80800328
    if (ctx->r5 == 0) {
        // 0x80800314: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80800328;
    }
    // 0x80800314: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800318: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8080031C: lw          $v1, 0x160($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X160);
    // 0x80800320: sltiu       $t1, $v1, 0x1
    ctx->r9 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800324: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80800328:
    // 0x80800328: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8080032C: beq         $a1, $zero, L_80800344
    if (ctx->r5 == 0) {
        // 0x80800330: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80800344;
    }
    // 0x80800330: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800334: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80800338: lw          $t3, 0x160($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X160);
    // 0x8080033C: xor         $v1, $t0, $t3
    ctx->r3 = ctx->r8 ^ ctx->r11;
    // 0x80800340: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
L_80800344:
    // 0x80800344: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80800348: sltiu       $v1, $a0, 0x1
    ctx->r3 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x8080034C: beq         $v1, $zero, L_80800360
    if (ctx->r3 == 0) {
        // 0x80800350: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_80800360;
    }
    // 0x80800350: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80800354: lw          $v1, 0x160($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X160);
    // 0x80800358: sltiu       $t5, $v1, 0x1
    ctx->r13 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8080035C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
L_80800360:
    // 0x80800360: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
    // 0x80800364: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800368: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080036C: xor         $v1, $t0, $t6
    ctx->r3 = ctx->r8 ^ ctx->r14;
    // 0x80800370: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800374: beq         $v1, $zero, L_808003B8
    if (ctx->r3 == 0) {
        // 0x80800378: nop
    
            goto L_808003B8;
    }
    // 0x80800378: nop

    // 0x8080037C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800380: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800384: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800388: jal         0x8008B2B4
    // 0x8080038C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_3;
    // 0x8080038C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800390: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800394: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800398: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080039C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808003A0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808003A4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808003A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808003AC: bc1f        L_808003B8
    if (!c1cs) {
        // 0x808003B0: nop
    
            goto L_808003B8;
    }
    // 0x808003B0: nop

    // 0x808003B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808003B8:
    // 0x808003B8: bne         $a2, $zero, L_808003E0
    if (ctx->r6 != 0) {
        // 0x808003BC: nop
    
            goto L_808003E0;
    }
    // 0x808003BC: nop

    // 0x808003C0: beq         $v0, $zero, L_808003D0
    if (ctx->r2 == 0) {
        // 0x808003C4: nop
    
            goto L_808003D0;
    }
    // 0x808003C4: nop

    // 0x808003C8: beq         $a3, $zero, L_808003E0
    if (ctx->r7 == 0) {
        // 0x808003CC: nop
    
            goto L_808003E0;
    }
    // 0x808003CC: nop

L_808003D0:
    // 0x808003D0: beql        $a1, $zero, L_80800470
    if (ctx->r5 == 0) {
        // 0x808003D4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800470;
    }
    goto skip_0;
    // 0x808003D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x808003D8: beql        $v1, $zero, L_80800470
    if (ctx->r3 == 0) {
        // 0x808003DC: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800470;
    }
    goto skip_1;
    // 0x808003DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_1:
L_808003E0:
    // 0x808003E0: jal         0x8008AF24
    // 0x808003E4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x808003E4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808003E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003EC: jal         0x8008AED4
    // 0x808003F0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x808003F0: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_5:
    // 0x808003F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003F8: jal         0x8008B1BC
    // 0x808003FC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    anctrl_setDuration(rdram, ctx);
        goto after_6;
    // 0x808003FC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_6:
    // 0x80800400: lbu         $t7, 0x8($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X8);
    // 0x80800404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800408: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080040C: bne         $t7, $at, L_80800424
    if (ctx->r15 != ctx->r1) {
        // 0x80800410: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800424;
    }
    // 0x80800410: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800414: jal         0x8008B134
    // 0x80800418: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800418: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x8080041C: b           L_8080043C
    // 0x80800420: nop

        goto L_8080043C;
    // 0x80800420: nop

L_80800424:
    // 0x80800424: jal         0x8008B134
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080042C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800430: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800434: jal         0x8008B1D4
    // 0x80800438: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    anctrl_setSubrange(rdram, ctx);
        goto after_9;
    // 0x80800438: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_9:
L_8080043C:
    // 0x8080043C: jal         0x8008B064
    // 0x80800440: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_10;
    // 0x80800440: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80800444: lbu         $a0, 0xA($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA);
    // 0x80800448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080044C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800450: bnel        $a0, $at, L_80800468
    if (ctx->r4 != ctx->r1) {
        // 0x80800454: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_80800468;
    }
    goto skip_2;
    // 0x80800454: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x80800458: jal         0x8009D89C
    // 0x8080045C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8009D89C(rdram, ctx);
        goto after_11;
    // 0x8080045C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x80800460: lbu         $a0, 0xA($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA);
    // 0x80800464: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_80800468:
    // 0x80800468: sw          $a0, 0x160($t8)
    MEM_W(0X160, ctx->r24) = ctx->r4;
    // 0x8080046C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80800470:
    // 0x80800470: jal         0x8009E830
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_12;
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800478: b           L_8080049C
    // 0x8080047C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080049C;
    // 0x8080047C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800480:
    // 0x80800480: lh          $v0, 0x14($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X14);
    // 0x80800484: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800488: bne         $v0, $zero, L_808002E4
    if (ctx->r2 != 0) {
        // 0x8080048C: nop
    
            goto L_808002E4;
    }
    // 0x8080048C: nop

L_80800490:
    // 0x80800490: jal         0x8080011C
    // 0x80800494: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8080011C_bsride(rdram, ctx);
        goto after_13;
    // 0x80800494: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_13:
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080049C:
    // 0x8080049C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void _subaddielink_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A040: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A040);
    return;
    // 0x8008A044: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X2380) << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: addiu       $v0, $v0, 0x2380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2380));
    return;
    // 0x80800044: addiu       $v0, $v0, 0x2380
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X2380));
;}
RECOMP_FUNC void _ncpoddialog_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089618: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089618);
    return;
    // 0x8008961C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800138_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080013C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4D68) << 16);
    // 0x80800140: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800144: jr          $ra
    // 0x80800148: lw          $v0, 0x4D68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4D68));
    return;
    // 0x80800148: lw          $v0, 0x4D68($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4D68));
;}
RECOMP_FUNC void func_80800240_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080024C: jal         0x80100094
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: jal         0x8008A2B0
    // 0x8080025C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080025C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800260: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800264: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080027C;
    }
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: jal         0x80100094
    // 0x8080026C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080026C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: jal         0x8008A2C0
    // 0x80800278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800278: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_8080027C:
    // 0x8080027C: jal         0x8008A2F8
    // 0x80800280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800280: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void chlavacolumns_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1944, 0X260) << 16);
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1944, 0X260));
    return;
    // 0x8080024C: addiu       $v0, $v0, 0x260
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1944, 0X260));
;}
RECOMP_FUNC void _bsdroneslide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083150: syscall     46
    recomp_syscall_handler(rdram, ctx, 0x80083150);
    return;
    // 0x80083154: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bswalk_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084208: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084208);
    return;
    // 0x8008420C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8009B450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B458: jal         0x800D8FF8
    // 0x8009B45C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009B45C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009B460: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8009B464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B468: lw          $v0, 0xC8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC8);
    // 0x8009B46C: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8009B470: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009B474: swc1        $f6, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f6.u32l;
    // 0x8009B478: lw          $t6, 0xC8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC8);
    // 0x8009B47C: lwc1        $f14, 0x52A8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X52A8);
    // 0x8009B480: jal         0x800F0F9C
    // 0x8009B484: lwc1        $f12, 0x4C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4C);
    func_800F0F9C(rdram, ctx);
        goto after_1;
    // 0x8009B484: lwc1        $f12, 0x4C($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4C);
    after_1:
    // 0x8009B488: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009B48C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B490: nop

    // 0x8009B494: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8009B498: jal         0x80013970
    // 0x8009B49C: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x8009B49C: nop

    after_2:
    // 0x8009B4A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8009B4A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009B4A8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009B4AC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8009B4B0: lw          $v0, 0xC8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0XC8);
    // 0x8009B4B4: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8009B4B8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8009B4BC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8009B4C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B4C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B4C8: jr          $ra
    // 0x8009B4CC: nop

    return;
    // 0x8009B4CC: nop

;}
RECOMP_FUNC void _chlaundry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087290: syscall     543
    recomp_syscall_handler(rdram, ctx, 0x80087290);
    return;
    // 0x80087294: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CF8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CF8);
    return;
    // 0x80083CFC: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_800217F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800217F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800217F8: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800217FC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80021800: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80021804: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80021808: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x8002180C: sw          $a0, 0x2C($t8)
    MEM_W(0X2C, ctx->r24) = ctx->r4;
    // 0x80021810: jr          $ra
    // 0x80021814: nop

    return;
    // 0x80021814: nop

;}
RECOMP_FUNC void func_8080002C_chfantasysafeswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800038: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080003C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800040: bnel        $t7, $at, L_80800064
    if (ctx->r15 != ctx->r1) {
        // 0x80800044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800048: jal         0x80101DDC
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x8080004C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800050: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800054: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800060;
    }
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: jal         0x80102424
    // 0x8080005C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080005C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801088: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080108C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801090: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80801094: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80801098: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080109C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808010A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808010A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808010A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808010AC: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808010B0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x808010B4: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x808010B8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808010BC: sll         $t6, $v0, 22
    ctx->r14 = S32(ctx->r2 << 22);
    // 0x808010C0: srl         $t7, $t6, 26
    ctx->r15 = S32(U32(ctx->r14) >> 26);
    // 0x808010C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808010C8: srl         $s5, $v0, 25
    ctx->r21 = S32(U32(ctx->r2) >> 25);
    // 0x808010CC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x808010D0: jal         0x801015B0
    // 0x808010D4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x808010D4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    after_0:
    // 0x808010D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808010DC: jal         0x800CC61C
    // 0x808010E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800CC61C(rdram, ctx);
        goto after_1;
    // 0x808010E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x808010E4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808010E8: blez        $v0, L_80801188
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808010EC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801188;
    }
    // 0x808010EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808010F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808010F4:
    // 0x808010F4: jal         0x800CC684
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CC684(rdram, ctx);
        goto after_2;
    // 0x808010F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808010FC: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80801100: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801104: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80801108: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080110C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801110: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801114: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801118: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8080111C: nop

    // 0x80801120: bc1fl       L_8080117C
    if (!c1cs) {
        // 0x80801124: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080117C;
    }
    goto skip_0;
    // 0x80801124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801128: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8080112C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80801130: nop

    // 0x80801134: bc1fl       L_8080117C
    if (!c1cs) {
        // 0x80801138: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080117C;
    }
    goto skip_1;
    // 0x80801138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8080113C: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80801140: addiu       $s2, $s4, 0x4
    ctx->r18 = ADD32(ctx->r20, 0X4);
    // 0x80801144: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801148: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8080114C: nop

    // 0x80801150: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801154: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801158: jal         0x800F0064
    // 0x8080115C: nop

    func_800F0064(rdram, ctx);
        goto after_3;
    // 0x8080115C: nop

    after_3:
    // 0x80801160: beq         $v0, $zero, L_80801178
    if (ctx->r2 == 0) {
        // 0x80801164: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80801178;
    }
    // 0x80801164: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801168: jal         0x800EE7F8
    // 0x8080116C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080116C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80801170: b           L_808012FC
    // 0x80801174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012FC;
    // 0x80801174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801178:
    // 0x80801178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080117C:
    // 0x8080117C: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80801180: bnel        $at, $zero, L_808010F4
    if (ctx->r1 != 0) {
        // 0x80801184: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808010F4;
    }
    goto skip_2;
    // 0x80801184: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_2:
L_80801188:
    // 0x80801188: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080118C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801190: jal         0x800CC63C
    // 0x80801194: addiu       $s2, $s4, 0x4
    ctx->r18 = ADD32(ctx->r20, 0X4);
    func_800CC63C(rdram, ctx);
        goto after_5;
    // 0x80801194: addiu       $s2, $s4, 0x4
    ctx->r18 = ADD32(ctx->r20, 0X4);
    after_5:
    // 0x80801198: lh          $t1, 0xE($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XE);
    // 0x8080119C: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808011A0: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x808011A4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x808011A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011AC: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808011B0: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808011B4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x808011B8: nop

    // 0x808011BC: bc1fl       L_8080120C
    if (!c1cs) {
        // 0x808011C0: lh          $a0, 0x0($s1)
        ctx->r4 = MEM_H(ctx->r17, 0X0);
            goto L_8080120C;
    }
    goto skip_3;
    // 0x808011C0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    skip_3:
    // 0x808011C4: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808011C8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x808011CC: nop

    // 0x808011D0: bc1fl       L_8080120C
    if (!c1cs) {
        // 0x808011D4: lh          $a0, 0x0($s1)
        ctx->r4 = MEM_H(ctx->r17, 0X0);
            goto L_8080120C;
    }
    goto skip_4;
    // 0x808011D4: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    skip_4:
    // 0x808011D8: lh          $t2, 0xC($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XC);
    // 0x808011DC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808011E0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x808011E4: nop

    // 0x808011E8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808011EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808011F0: jal         0x800F0064
    // 0x808011F4: nop

    func_800F0064(rdram, ctx);
        goto after_6;
    // 0x808011F4: nop

    after_6:
    // 0x808011F8: beql        $v0, $zero, L_8080120C
    if (ctx->r2 == 0) {
        // 0x808011FC: lh          $a0, 0x0($s1)
        ctx->r4 = MEM_H(ctx->r17, 0X0);
            goto L_8080120C;
    }
    goto skip_5;
    // 0x808011FC: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    skip_5:
    // 0x80801200: b           L_808012FC
    // 0x80801204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808012FC;
    // 0x80801204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801208: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
L_8080120C:
    // 0x8080120C: jal         0x8001B798
    // 0x80801210: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_8001B798(rdram, ctx);
        goto after_7;
    // 0x80801210: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_7:
    // 0x80801214: sll         $t3, $s5, 2
    ctx->r11 = S32(ctx->r21 << 2);
    // 0x80801218: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8080121C: jal         0x8001B798
    // 0x80801220: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    func_8001B798(rdram, ctx);
        goto after_8;
    // 0x80801220: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    after_8:
    // 0x80801224: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80801228: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8080122C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80801230: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80801234: addu        $s1, $t8, $v0
    ctx->r17 = ADD32(ctx->r24, ctx->r2);
    // 0x80801238: lbu         $s3, 0x0($s1)
    ctx->r19 = MEM_BU(ctx->r17, 0X0);
    // 0x8080123C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801240: blez        $s3, L_808012EC
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801244: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808012EC;
    }
L_80801244:
    // 0x80801244: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801248: jal         0x800CC63C
    // 0x8080124C: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800CC63C(rdram, ctx);
        goto after_9;
    // 0x8080124C: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_9:
    // 0x80801250: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80801254: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801258: lwc1        $f12, 0x8($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8080125C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80801260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801264: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801268: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080126C: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80801270: nop

    // 0x80801274: bc1fl       L_808012E4
    if (!c1cs) {
        // 0x80801278: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808012E4;
    }
    goto skip_6;
    // 0x80801278: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_6:
    // 0x8080127C: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80801280: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80801284: nop

    // 0x80801288: bc1fl       L_808012E4
    if (!c1cs) {
        // 0x8080128C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808012E4;
    }
    goto skip_7;
    // 0x8080128C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_7:
    // 0x80801290: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80801294: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801298: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8080129C: nop

    // 0x808012A0: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808012A4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808012A8: jal         0x800F0064
    // 0x808012AC: nop

    func_800F0064(rdram, ctx);
        goto after_10;
    // 0x808012AC: nop

    after_10:
    // 0x808012B0: beql        $v0, $zero, L_808012E4
    if (ctx->r2 == 0) {
        // 0x808012B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808012E4;
    }
    goto skip_8;
    // 0x808012B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_8:
    // 0x808012B8: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x808012BC: lhu         $t6, 0x72($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X72);
    // 0x808012C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808012C4: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x808012C8: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x808012CC: andi        $t5, $t4, 0x3F0
    ctx->r13 = ctx->r12 & 0X3F0;
    // 0x808012D0: andi        $t7, $t6, 0xFC0F
    ctx->r15 = ctx->r14 & 0XFC0F;
    // 0x808012D4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808012D8: b           L_808012FC
    // 0x808012DC: sh          $t8, 0x72($s4)
    MEM_H(0X72, ctx->r20) = ctx->r24;
        goto L_808012FC;
    // 0x808012DC: sh          $t8, 0x72($s4)
    MEM_H(0X72, ctx->r20) = ctx->r24;
    // 0x808012E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808012E4:
    // 0x808012E4: bne         $s0, $s3, L_80801244
    if (ctx->r16 != ctx->r19) {
        // 0x808012E8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801244;
    }
    // 0x808012E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808012EC:
    // 0x808012EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808012F0: jal         0x800EE7F8
    // 0x808012F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808012F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x808012F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012FC:
    // 0x808012FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801300: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801304: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801308: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080130C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801310: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80801314: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80801318: jr          $ra
    // 0x8080131C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080131C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsstand_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D30: jal         0x80084CC8
    // 0x80800D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafpctrl_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D38: jal         0x80082FF0
    // 0x80800D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void gclightsDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800034: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800038: jal         0x800B2D70
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x8080003C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800040: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2602, 0X560) << 16);
    // 0x80800048: addiu       $a0, $a0, 0x560
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2602, 0X560));
    // 0x8080004C: jal         0x800C8C90
    // 0x80800050: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    func_800C8C90(rdram, ctx);
        goto after_1;
    // 0x80800050: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    after_1:
    // 0x80800054: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2602, 0X56C) << 16);
    // 0x80800058: jal         0x80800528
    // 0x8080005C: addiu       $a0, $a0, 0x56C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2602, 0X56C));
    gclightsDll_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080005C: addiu       $a0, $a0, 0x56C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2602, 0X56C));
    after_2:
    // 0x80800060: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2602, 0X56C) << 16);
    // 0x80800064: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2602, 0X578) << 16);
    // 0x80800068: addiu       $a1, $a1, 0x578
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2602, 0X578));
    // 0x8080006C: jal         0x800C8F08
    // 0x80800070: addiu       $a0, $a0, 0x56C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2602, 0X56C));
    func_800C8F08(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a0, $a0, 0x56C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2602, 0X56C));
    after_3:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void baphysics_set_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009B804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009B808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009B80C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8009B810: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009B814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009B818: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009B81C: beq         $t6, $a1, L_8009B938
    if (ctx->r14 == ctx->r5) {
        // 0x8009B820: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_8009B938;
    }
    // 0x8009B820: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8009B824: addiu       $t0, $t6, -0xC
    ctx->r8 = ADD32(ctx->r14, -0XC);
    // 0x8009B828: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x8009B82C: beq         $at, $zero, L_8009B894
    if (ctx->r1 == 0) {
        // 0x8009B830: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8009B894;
    }
    // 0x8009B830: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8009B834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B838: addu        $at, $at, $t0
    gpr jr_addend_8009B840 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8009B83C: lw          $t0, 0x52FC($at)
    ctx->r8 = ADD32(ctx->r1, 0X52FC);
    // 0x8009B840: jr          $t0
    // 0x8009B844: nop

    switch (jr_addend_8009B840 >> 2) {
        case 0: goto L_8009B868; break;
        case 1: goto L_8009B848; break;
        case 2: goto L_8009B894; break;
        case 3: goto L_8009B858; break;
        case 4: goto L_8009B894; break;
        case 5: goto L_8009B894; break;
        case 6: goto L_8009B878; break;
        case 7: goto L_8009B888; break;
        default: switch_error(__func__, 0x8009B840, 0x801252FC);
    }
    // 0x8009B844: nop

L_8009B848:
    // 0x8009B848: jal         0x80084E60
    // 0x8009B84C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamoveledge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8009B84C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009B850: b           L_8009B894
    // 0x8009B854: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B894;
    // 0x8009B854: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B858:
    // 0x8009B858: jal         0x80084ED0
    // 0x8009B85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8009B85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009B860: b           L_8009B894
    // 0x8009B864: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B894;
    // 0x8009B864: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B868:
    // 0x8009B868: jal         0x80084DE0
    // 0x8009B86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8009B86C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8009B870: b           L_8009B894
    // 0x8009B874: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B894;
    // 0x8009B874: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B878:
    // 0x8009B878: jal         0x80084EA0
    // 0x8009B87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x8009B87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8009B880: b           L_8009B894
    // 0x8009B884: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
        goto L_8009B894;
    // 0x8009B884: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B888:
    // 0x8009B888: jal         0x80084E30
    // 0x8009B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovehover_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8009B88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009B890: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
L_8009B894:
    // 0x8009B894: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B898: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009B89C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B8A0: addiu       $t3, $t2, -0xB
    ctx->r11 = ADD32(ctx->r10, -0XB);
    // 0x8009B8A4: sltiu       $at, $t3, 0x9
    ctx->r1 = ctx->r11 < 0X9 ? 1 : 0;
    // 0x8009B8A8: beq         $at, $zero, L_8009B938
    if (ctx->r1 == 0) {
        // 0x8009B8AC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_8009B938;
    }
    // 0x8009B8AC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8009B8B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009B8B4: addu        $at, $at, $t3
    gpr jr_addend_8009B8BC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8009B8B8: lw          $t3, 0x531C($at)
    ctx->r11 = ADD32(ctx->r1, 0X531C);
    // 0x8009B8BC: jr          $t3
    // 0x8009B8C0: nop

    switch (jr_addend_8009B8BC >> 2) {
        case 0: goto L_8009B8E4; break;
        case 1: goto L_8009B8C4; break;
        case 2: goto L_8009B8D4; break;
        case 3: goto L_8009B938; break;
        case 4: goto L_8009B910; break;
        case 5: goto L_8009B938; break;
        case 6: goto L_8009B938; break;
        case 7: goto L_8009B920; break;
        case 8: goto L_8009B930; break;
        default: switch_error(__func__, 0x8009B8BC, 0x8012531C);
    }
    // 0x8009B8C0: nop

L_8009B8C4:
    // 0x8009B8C4: jal         0x80084DE8
    // 0x8009B8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x8009B8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8009B8CC: b           L_8009B93C
    // 0x8009B8D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009B93C;
    // 0x8009B8D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B8D4:
    // 0x8009B8D4: jal         0x80084E68
    // 0x8009B8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamoveledge_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8009B8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8009B8DC: b           L_8009B93C
    // 0x8009B8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009B93C;
    // 0x8009B8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B8E4:
    // 0x8009B8E4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8009B8E8: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8009B8EC: beql        $t4, $t5, L_8009B93C
    if (ctx->r12 == ctx->r13) {
        // 0x8009B8F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009B93C;
    }
    goto skip_0;
    // 0x8009B8F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8009B8F4: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B8F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009B8FC: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8009B900: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x8009B904: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B908: b           L_8009B938
    // 0x8009B90C: swc1        $f6, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f6.u32l;
        goto L_8009B938;
    // 0x8009B90C: swc1        $f6, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f6.u32l;
L_8009B910:
    // 0x8009B910: jal         0x80084ED8
    // 0x8009B914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x8009B914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8009B918: b           L_8009B93C
    // 0x8009B91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009B93C;
    // 0x8009B91C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B920:
    // 0x8009B920: jal         0x80084EA8
    // 0x8009B924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x8009B924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8009B928: b           L_8009B93C
    // 0x8009B92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009B93C;
    // 0x8009B92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B930:
    // 0x8009B930: jal         0x80084E38
    // 0x8009B934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovehover_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x8009B934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8009B938:
    // 0x8009B938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009B93C:
    // 0x8009B93C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009B940: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009B944: jr          $ra
    // 0x8009B948: nop

    return;
    // 0x8009B948: nop

;}
RECOMP_FUNC void func_800C674C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C674C: jr          $ra
    // 0x800C6750: lh          $v0, 0x8C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8C);
    return;
    // 0x800C6750: lh          $v0, 0x8C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8C);
;}
RECOMP_FUNC void func_808018E0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808018E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808018E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808018F0: jal         0x80100094
    // 0x808018F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808018FC: lwc1        $f6, 0x55C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X55C);
    // 0x80801900: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801904: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80801908: nop

    // 0x8080190C: bc1tl       L_80801A7C
    if (c1cs) {
        // 0x80801910: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A7C;
    }
    goto skip_0;
    // 0x80801910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801914: jal         0x800D8FF8
    // 0x80801918: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801918: nop

    after_1:
    // 0x8080191C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801920: jal         0x800F1574
    // 0x80801924: addiu       $a0, $s0, 0x560
    ctx->r4 = ADD32(ctx->r16, 0X560);
    func_800F1574(rdram, ctx);
        goto after_2;
    // 0x80801924: addiu       $a0, $s0, 0x560
    ctx->r4 = ADD32(ctx->r16, 0X560);
    after_2:
    // 0x80801928: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080192C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801930: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X218C) << 16);
    // 0x80801934: lwc1        $f8, 0x218C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2216, 0X218C));
    // 0x80801938: lwc1        $f12, 0x560($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X560);
    // 0x8080193C: lbu         $t2, 0x558($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X558);
    // 0x80801940: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2216, 0X2190) << 16);
    // 0x80801944: mul.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80801948: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080194C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80801950: nop

    // 0x80801954: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80801958: nop

    // 0x8080195C: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80801960: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80801964: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80801968: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8080196C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80801970: nop

    // 0x80801974: sb          $t9, 0x55A($s0)
    MEM_B(0X55A, ctx->r16) = ctx->r25;
    // 0x80801978: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080197C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80801980: beq         $t2, $zero, L_80801A38
    if (ctx->r10 == 0) {
        // 0x80801984: sb          $t1, 0x55B($s0)
        MEM_B(0X55B, ctx->r16) = ctx->r9;
            goto L_80801A38;
    }
    // 0x80801984: sb          $t1, 0x55B($s0)
    MEM_B(0X55B, ctx->r16) = ctx->r9;
    // 0x80801988: jal         0x800D8FF8
    // 0x8080198C: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x8080198C: nop

    after_3:
    // 0x80801990: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x80801994: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801998: nop

    // 0x8080199C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808019A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808019A4: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x808019A8: jal         0x800D8FF8
    // 0x808019AC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x808019AC: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_4:
    // 0x808019B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808019B4: jal         0x800F1574
    // 0x808019B8: addiu       $a0, $s0, 0x564
    ctx->r4 = ADD32(ctx->r16, 0X564);
    func_800F1574(rdram, ctx);
        goto after_5;
    // 0x808019B8: addiu       $a0, $s0, 0x564
    ctx->r4 = ADD32(ctx->r16, 0X564);
    after_5:
    // 0x808019BC: beq         $v0, $zero, L_808019CC
    if (ctx->r2 == 0) {
        // 0x808019C0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808019CC;
    }
    // 0x808019C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808019C4: jal         0x80801A8C
    // 0x808019C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80801A8C_chfpsgame(rdram, ctx);
        goto after_6;
    // 0x808019C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
L_808019CC:
    // 0x808019CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808019D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808019D4: lwc1        $f0, 0x564($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X564);
    // 0x808019D8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808019DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808019E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808019E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808019E8: bc1fl       L_80801A0C
    if (!c1cs) {
        // 0x808019EC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80801A0C;
    }
    goto skip_1;
    // 0x808019EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x808019F0: lbu         $t5, 0x559($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X559);
    // 0x808019F4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x808019F8: jal         0x800F1418
    // 0x808019FC: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    func_800F1418(rdram, ctx);
        goto after_7;
    // 0x808019FC: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    after_7:
    // 0x80801A00: b           L_80801A78
    // 0x80801A04: sb          $v0, 0x559($s0)
    MEM_B(0X559, ctx->r16) = ctx->r2;
        goto L_80801A78;
    // 0x80801A04: sb          $v0, 0x559($s0)
    MEM_B(0X559, ctx->r16) = ctx->r2;
    // 0x80801A08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80801A0C:
    // 0x80801A0C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80801A10: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801A14: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80801A18: bc1fl       L_80801A7C
    if (!c1cs) {
        // 0x80801A1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A7C;
    }
    goto skip_2;
    // 0x80801A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80801A20: lbu         $t8, 0x559($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X559);
    // 0x80801A24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801A28: jal         0x800F0E28
    // 0x80801A2C: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    func_800F0E28(rdram, ctx);
        goto after_8;
    // 0x80801A2C: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    after_8:
    // 0x80801A30: b           L_80801A78
    // 0x80801A34: sb          $v0, 0x559($s0)
    MEM_B(0X559, ctx->r16) = ctx->r2;
        goto L_80801A78;
    // 0x80801A34: sb          $v0, 0x559($s0)
    MEM_B(0X559, ctx->r16) = ctx->r2;
L_80801A38:
    // 0x80801A38: lwc1        $f8, 0x2190($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2216, 0X2190));
    // 0x80801A3C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80801A40: nop

    // 0x80801A44: bc1fl       L_80801A64
    if (!c1cs) {
        // 0x80801A48: lbu         $t1, 0x55B($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X55B);
            goto L_80801A64;
    }
    goto skip_3;
    // 0x80801A48: lbu         $t1, 0x55B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X55B);
    skip_3:
    // 0x80801A4C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80801A50: jal         0x80801A8C
    // 0x80801A54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801A8C_chfpsgame(rdram, ctx);
        goto after_9;
    // 0x80801A54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80801A58: b           L_80801A7C
    // 0x80801A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801A7C;
    // 0x80801A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A60: lbu         $t1, 0x55B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X55B);
L_80801A64:
    // 0x80801A64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801A68: bnel        $t1, $zero, L_80801A7C
    if (ctx->r9 != 0) {
        // 0x80801A6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A7C;
    }
    goto skip_4;
    // 0x80801A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80801A70: jal         0x80801A8C
    // 0x80801A74: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    func_80801A8C_chfpsgame(rdram, ctx);
        goto after_10;
    // 0x80801A74: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    after_10:
L_80801A78:
    // 0x80801A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A7C:
    // 0x80801A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801A84: jr          $ra
    // 0x80801A88: nop

    return;
    // 0x80801A88: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X168C) << 16);
    // 0x808000CC: jr          $ra
    // 0x808000D0: addiu       $v0, $v0, 0x168C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X168C));
    return;
    // 0x808000D0: addiu       $v0, $v0, 0x168C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X168C));
;}
RECOMP_FUNC void func_80800050_chicestationbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800060: beq         $a1, $at, L_8080007C
    if (ctx->r5 == ctx->r1) {
        // 0x80800064: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080007C;
    }
    // 0x80800064: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800068: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x8080006C: beq         $a1, $at, L_80800090
    if (ctx->r5 == ctx->r1) {
        // 0x80800070: nop
    
            goto L_80800090;
    }
    // 0x80800070: nop

    // 0x80800074: b           L_808000B4
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_808000B4;
    // 0x80800078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8080007C:
    // 0x8080007C: addiu       $a0, $zero, 0x12A
    ctx->r4 = ADD32(0, 0X12A);
    // 0x80800080: jal         0x800887D8
    // 0x80800084: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800084: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_0:
    // 0x80800088: b           L_808000C4
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C4;
    // 0x8080008C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800090:
    // 0x80800090: jal         0x800F54E4
    // 0x80800094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800094: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800098: jal         0x800F6B94
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6B94(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000A0: bne         $v0, $zero, L_808000B0
    if (ctx->r2 != 0) {
        // 0x808000A4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808000B0;
    }
    // 0x808000A4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A8: b           L_808000C4
    // 0x808000AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C4;
    // 0x808000AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B0:
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808000B4:
    // 0x808000B4: jal         0x80085820
    // 0x808000B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C4:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C8:
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_80800030_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080003C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800048: beq         $a1, $at, L_80800064
    if (ctx->r5 == ctx->r1) {
        // 0x8080004C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800064;
    }
    // 0x8080004C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800050: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800054: beq         $a1, $at, L_8080008C
    if (ctx->r5 == ctx->r1) {
        // 0x80800058: addiu       $a0, $zero, 0x49F
        ctx->r4 = ADD32(0, 0X49F);
            goto L_8080008C;
    }
    // 0x80800058: addiu       $a0, $zero, 0x49F
    ctx->r4 = ADD32(0, 0X49F);
    // 0x8080005C: b           L_808000B0
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_808000B0;
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800064:
    // 0x80800064: addiu       $a0, $zero, 0x49F
    ctx->r4 = ADD32(0, 0X49F);
    // 0x80800068: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080006C: jal         0x80101180
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800078: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080007C: jal         0x80085820
    // 0x80800080: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800080: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800084: b           L_808000C0
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080008C:
    // 0x8080008C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800090: jal         0x80101180
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800098: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080009C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000A0: jal         0x80085820
    // 0x808000A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808000A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808000A8: b           L_808000C0
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B0:
    // 0x808000B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80085820
    // 0x808000B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808000B8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C0:
    // 0x808000C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80800B54_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B5C: jal         0x800839B8
    // 0x80800B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B64: jal         0x80800164
    // 0x80800B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800164_bsbanshack(rdram, ctx);
        goto after_1;
    // 0x80800B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B74: jr          $ra
    // 0x80800B78: nop

    return;
    // 0x80800B78: nop

;}
RECOMP_FUNC void func_8080092C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080092C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800934: jal         0x80800668
    // 0x80800938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800668_bstnt(rdram, ctx);
        goto after_0;
    // 0x80800938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080093C: jal         0x80800028
    // 0x80800940: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800028_bstnt(rdram, ctx);
        goto after_1;
    // 0x80800940: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800944: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800948: jal         0x808007EC
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007EC_bstnt(rdram, ctx);
        goto after_2;
    // 0x8080094C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800958: jr          $ra
    // 0x8080095C: nop

    return;
    // 0x8080095C: nop

;}
RECOMP_FUNC void func_800C33DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C33DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C33E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C33E4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C33E8: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C33EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C33F0: beq         $t6, $zero, L_800C3408
    if (ctx->r14 == 0) {
        // 0x800C33F4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C3408;
    }
    // 0x800C33F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C33F8: jal         0x800C1414
    // 0x800C33FC: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C33FC: nop

    after_0:
    // 0x800C3400: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3404: sb          $t7, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r15;
L_800C3408:
    // 0x800C3408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C340C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3410: jr          $ra
    // 0x800C3414: nop

    return;
    // 0x800C3414: nop

;}
RECOMP_FUNC void chgameselect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801790: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X80C8) << 16);
    // 0x80801794: jr          $ra
    // 0x80801798: addiu       $v0, $v0, -0x7F38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X80C8));
    return;
    // 0x80801798: addiu       $v0, $v0, -0x7F38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X80C8));
;}
RECOMP_FUNC void func_800F56D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F56D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F56DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F56E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F56E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F56E8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F56EC: jal         0x80084D40
    // 0x800F56F0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bahold_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800F56F0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F56F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F56F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F56FC: jr          $ra
    // 0x800F5700: nop

    return;
    // 0x800F5700: nop

;}
RECOMP_FUNC void ncbadolly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800048: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: lbu         $t7, 0x21($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X21);
    // 0x80800054: bnel        $t7, $zero, L_80800178
    if (ctx->r15 != 0) {
        // 0x80800058: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800178;
    }
    goto skip_0;
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080005C: jal         0x80112524
    // 0x80800060: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_0:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x801107F0
    // 0x8080006C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x80800070: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800074: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800078: jal         0x800EFB24
    // 0x8080007C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x80800080: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800084: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800088: jal         0x800EEFFC
    // 0x8080008C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    func_800EEFFC(rdram, ctx);
        goto after_3;
    // 0x8080008C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800090: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80800094: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800098: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080009C: lwc1        $f12, 0x1C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x808000A0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x808000A4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808000A8: nop

    // 0x808000AC: bc1fl       L_808000BC
    if (!c1cs) {
        // 0x808000B0: lwc1        $f0, 0x18($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
            goto L_808000BC;
    }
    goto skip_1;
    // 0x808000B0: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    skip_1:
    // 0x808000B4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x808000B8: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
L_808000BC:
    // 0x808000BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808000C0: nop

    // 0x808000C4: bc1f        L_808000D0
    if (!c1cs) {
        // 0x808000C8: nop
    
            goto L_808000D0;
    }
    // 0x808000C8: nop

    // 0x808000CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808000D0:
    // 0x808000D0: jal         0x800EFB24
    // 0x808000D4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x808000D4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x808000D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000DC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808000E0: jal         0x800EEFFC
    // 0x808000E4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800EEFFC(rdram, ctx);
        goto after_5;
    // 0x808000E4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x808000E8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000EC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808000F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808000F4: nop

    // 0x808000F8: bc1fl       L_80800108
    if (!c1cs) {
        // 0x808000FC: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80800108;
    }
    goto skip_2;
    // 0x808000FC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x80800100: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800104: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80800108:
    // 0x80800108: jal         0x800EFA98
    // 0x8080010C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EFA98(rdram, ctx);
        goto after_6;
    // 0x8080010C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80800110: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800114: jal         0x800EF04C
    // 0x80800118: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800118: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_7:
    // 0x8080011C: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800128: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8080012C: jal         0x80111AE0
    // 0x80800130: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_80111AE0(rdram, ctx);
        goto after_8;
    // 0x80800130: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800134: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80800138: lbu         $t0, 0x20($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X20);
    // 0x8080013C: beql        $t0, $zero, L_80800150
    if (ctx->r8 == 0) {
        // 0x80800140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800150;
    }
    goto skip_3;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800144: jal         0x8011329C
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011329C(rdram, ctx);
        goto after_9;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800150:
    // 0x80800150: jal         0x80112524
    // 0x80800154: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_80112524(rdram, ctx);
        goto after_10;
    // 0x80800154: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_10:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800160: jal         0x80110A68
    // 0x80800164: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_80110A68(rdram, ctx);
        goto after_11;
    // 0x80800164: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_11:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80110790
    // 0x80800170: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_80110790(rdram, ctx);
        goto after_12;
    // 0x80800170: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x80800174: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800178:
    // 0x80800178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080017C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void func_800CE308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE308: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CE30C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800CE310: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800CE314: addiu       $s2, $s2, -0x4FE0
    ctx->r18 = ADD32(ctx->r18, -0X4FE0);
    // 0x800CE318: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CE31C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CE320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CE324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CE328: jal         0x800DAB8C
    // 0x800CE32C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DAB8C(rdram, ctx);
        goto after_0;
    // 0x800CE32C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800CE330: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800CE334: jal         0x800BE52C
    // 0x800CE338: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800BE52C(rdram, ctx);
        goto after_1;
    // 0x800CE338: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x800CE33C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800CE340: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CE344: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x800CE348: beq         $at, $zero, L_800CE3C8
    if (ctx->r1 == 0) {
        // 0x800CE34C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800CE3C8;
    }
    // 0x800CE34C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800CE350:
    // 0x800CE350: jal         0x800E9DD4
    // 0x800CE354: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    func_800E9DD4(rdram, ctx);
        goto after_2;
    // 0x800CE354: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    after_2:
    // 0x800CE358: beql        $v0, $zero, L_800CE3B4
    if (ctx->r2 == 0) {
        // 0x800CE35C: lw          $s1, 0x34($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X34);
            goto L_800CE3B4;
    }
    goto skip_0;
    // 0x800CE35C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800CE360: jal         0x800E9D68
    // 0x800CE364: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800E9D68(rdram, ctx);
        goto after_3;
    // 0x800CE364: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x800CE368: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800CE36C: jal         0x800E9D90
    // 0x800CE370: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800E9D90(rdram, ctx);
        goto after_4;
    // 0x800CE370: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_4:
    // 0x800CE374: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800CE378: beq         $at, $zero, L_800CE3B0
    if (ctx->r1 == 0) {
        // 0x800CE37C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800CE3B0;
    }
    // 0x800CE37C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CE380: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_800CE384:
    // 0x800CE384: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CE388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800CE38C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800CE390: bnel        $t8, $zero, L_800CE3A4
    if (ctx->r24 != 0) {
        // 0x800CE394: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800CE3A4;
    }
    goto skip_1;
    // 0x800CE394: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_1:
    // 0x800CE398: jal         0x800DAAF8
    // 0x800CE39C: lbu         $a1, 0xA($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA);
    func_800DAAF8(rdram, ctx);
        goto after_5;
    // 0x800CE39C: lbu         $a1, 0xA($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XA);
    after_5:
    // 0x800CE3A0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800CE3A4:
    // 0x800CE3A4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800CE3A8: bnel        $at, $zero, L_800CE384
    if (ctx->r1 != 0) {
        // 0x800CE3AC: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_800CE384;
    }
    goto skip_2;
    // 0x800CE3AC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_2:
L_800CE3B0:
    // 0x800CE3B0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
L_800CE3B4:
    // 0x800CE3B4: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800CE3B8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800CE3BC: sltu        $at, $s1, $t9
    ctx->r1 = ctx->r17 < ctx->r25 ? 1 : 0;
    // 0x800CE3C0: bnel        $at, $zero, L_800CE350
    if (ctx->r1 != 0) {
        // 0x800CE3C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800CE350;
    }
    goto skip_3;
    // 0x800CE3C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_800CE3C8:
    // 0x800CE3C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CE3CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CE3D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE3D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800CE3D8: jr          $ra
    // 0x800CE3DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CE3DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gzthread_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800044: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8080004C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80800050: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800054: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800058: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080005C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800060: bltz        $a0, L_808000A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800064: sw          $s0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r16;
            goto L_808000A0;
    }
    // 0x80800064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800068: addiu       $s1, $a0, 0x7
    ctx->r17 = ADD32(ctx->r4, 0X7);
    // 0x8080006C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800070:
    // 0x80800070: jal         0x80014ED4
    // 0x80800074: nop

    func_80014ED4(rdram, ctx);
        goto after_0;
    // 0x80800074: nop

    after_0:
    // 0x80800078: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3398, 0X3A8) << 16);
    // 0x8080007C: addiu       $a3, $a3, 0x3A8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3398, 0X3A8));
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800084: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800088: jal         0x8001DB90
    // 0x8080008C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8001DB90(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80800090: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800094: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800098: bne         $s0, $at, L_80800070
    if (ctx->r16 != ctx->r1) {
        // 0x8080009C: nop
    
            goto L_80800070;
    }
    // 0x8080009C: nop

L_808000A0:
    // 0x808000A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X300) << 16);
    // 0x808000A4: addiu       $a2, $a2, 0x300
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X300));
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000AC: jal         0x8001D3D8
    // 0x808000B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8001D3D8(rdram, ctx);
        goto after_2;
    // 0x808000B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x808000B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X308) << 16);
    // 0x808000B8: addiu       $a2, $a2, 0x308
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X308));
    // 0x808000BC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x808000C0: jal         0x8001D3D8
    // 0x808000C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8001D3D8(rdram, ctx);
        goto after_3;
    // 0x808000C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x808000C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X310) << 16);
    // 0x808000CC: addiu       $a2, $a2, 0x310
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X310));
    // 0x808000D0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x808000D4: jal         0x8001D3D8
    // 0x808000D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8001D3D8(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x808000DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X314) << 16);
    // 0x808000E0: addiu       $a2, $a2, 0x314
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X314));
    // 0x808000E4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x808000E8: jal         0x8001D3D8
    // 0x808000EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8001D3D8(rdram, ctx);
        goto after_5;
    // 0x808000EC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
    // 0x808000F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X318) << 16);
    // 0x808000F4: addiu       $a2, $a2, 0x318
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X318));
    // 0x808000F8: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x808000FC: jal         0x8001D3D8
    // 0x80800100: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8001D3D8(rdram, ctx);
        goto after_6;
    // 0x80800100: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
    // 0x80800104: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X31C) << 16);
    // 0x80800108: addiu       $a2, $a2, 0x31C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X31C));
    // 0x8080010C: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x80800110: jal         0x8001D3D8
    // 0x80800114: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8001D3D8(rdram, ctx);
        goto after_7;
    // 0x80800114: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_7:
    // 0x80800118: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3398, 0X380) << 16);
    // 0x8080011C: addiu       $s5, $s5, 0x380
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(3398, 0X380));
    // 0x80800120: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800124: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
L_80800128:
    // 0x80800128: jal         0x8001DDA4
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001DDA4(rdram, ctx);
        goto after_8;
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800130: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X324) << 16);
    // 0x80800134: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800138: addiu       $a2, $a2, 0x324
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X324));
    // 0x8080013C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800140: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800144: jal         0x8001D3D8
    // 0x80800148: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    func_8001D3D8(rdram, ctx);
        goto after_9;
    // 0x80800148: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    after_9:
    // 0x8080014C: jal         0x8001D98C
    // 0x80800150: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_8001D98C(rdram, ctx);
        goto after_10;
    // 0x80800150: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_10:
    // 0x80800154: beq         $s0, $zero, L_8080026C
    if (ctx->r16 == 0) {
        // 0x80800158: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3398, 0X370) << 16);
            goto L_8080026C;
    }
    // 0x80800158: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X370) << 16);
    // 0x8080015C: jal         0x8001E7A0
    // 0x80800160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8001E7A0(rdram, ctx);
        goto after_11;
    // 0x80800160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80800164: lhu         $v1, 0x10($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X10);
    // 0x80800168: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080016C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800170: lw          $s3, 0x11C($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X11C);
    // 0x80800174: beq         $v1, $at, L_808001A4
    if (ctx->r3 == ctx->r1) {
        // 0x80800178: lw          $s4, 0xF4($s0)
        ctx->r20 = MEM_W(ctx->r16, 0XF4);
            goto L_808001A4;
    }
    // 0x80800178: lw          $s4, 0xF4($s0)
    ctx->r20 = MEM_W(ctx->r16, 0XF4);
    // 0x8080017C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800180: beq         $v1, $at, L_808001B8
    if (ctx->r3 == ctx->r1) {
        // 0x80800184: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3398, 0X330) << 16);
            goto L_808001B8;
    }
    // 0x80800184: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X330) << 16);
    // 0x80800188: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080018C: beq         $v1, $at, L_808001C8
    if (ctx->r3 == ctx->r1) {
        // 0x80800190: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3398, 0X33C) << 16);
            goto L_808001C8;
    }
    // 0x80800190: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X33C) << 16);
    // 0x80800194: beq         $v1, $s6, L_808001D8
    if (ctx->r3 == ctx->r22) {
        // 0x80800198: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3398, 0X344) << 16);
            goto L_808001D8;
    }
    // 0x80800198: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X344) << 16);
    // 0x8080019C: b           L_808001E4
    // 0x808001A0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
        goto L_808001E4;
    // 0x808001A0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_808001A4:
    // 0x808001A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X328) << 16);
    // 0x808001A8: jal         0x8001D37C
    // 0x808001AC: addiu       $a0, $a0, 0x328
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X328));
    func_8001D37C(rdram, ctx);
        goto after_12;
    // 0x808001AC: addiu       $a0, $a0, 0x328
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X328));
    after_12:
    // 0x808001B0: b           L_808001E4
    // 0x808001B4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
        goto L_808001E4;
    // 0x808001B4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_808001B8:
    // 0x808001B8: jal         0x8001D37C
    // 0x808001BC: addiu       $a0, $a0, 0x330
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X330));
    func_8001D37C(rdram, ctx);
        goto after_13;
    // 0x808001BC: addiu       $a0, $a0, 0x330
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X330));
    after_13:
    // 0x808001C0: b           L_808001E4
    // 0x808001C4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
        goto L_808001E4;
    // 0x808001C4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_808001C8:
    // 0x808001C8: jal         0x8001D37C
    // 0x808001CC: addiu       $a0, $a0, 0x33C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X33C));
    func_8001D37C(rdram, ctx);
        goto after_14;
    // 0x808001CC: addiu       $a0, $a0, 0x33C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X33C));
    after_14:
    // 0x808001D0: b           L_808001E4
    // 0x808001D4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
        goto L_808001E4;
    // 0x808001D4: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_808001D8:
    // 0x808001D8: jal         0x8001D37C
    // 0x808001DC: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X344));
    func_8001D37C(rdram, ctx);
        goto after_15;
    // 0x808001DC: addiu       $a0, $a0, 0x344
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X344));
    after_15:
    // 0x808001E0: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
L_808001E4:
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X34C) << 16);
    // 0x808001E8: addiu       $a2, $a2, 0x34C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X34C));
    // 0x808001EC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x808001F0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808001F4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808001F8: jal         0x8001D3D8
    // 0x808001FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8001D3D8(rdram, ctx);
        goto after_16;
    // 0x808001FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_16:
    // 0x80800200: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X354) << 16);
    // 0x80800204: addiu       $a2, $a2, 0x354
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X354));
    // 0x80800208: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8080020C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800210: jal         0x8001D3D8
    // 0x80800214: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_8001D3D8(rdram, ctx);
        goto after_17;
    // 0x80800214: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_17:
    // 0x80800218: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X35C) << 16);
    // 0x8080021C: addiu       $a2, $a2, 0x35C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X35C));
    // 0x80800220: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80800224: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800228: jal         0x8001D3D8
    // 0x8080022C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8001D3D8(rdram, ctx);
        goto after_18;
    // 0x8080022C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_18:
    // 0x80800230: lhu         $t9, 0x10($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X10);
    // 0x80800234: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800238: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3398, 0X364) << 16);
    // 0x8080023C: bne         $s6, $t9, L_8080025C
    if (ctx->r22 != ctx->r25) {
        // 0x80800240: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3398, 0X36C) << 16);
            goto L_8080025C;
    }
    // 0x80800240: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3398, 0X36C) << 16);
    // 0x80800244: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x80800248: addiu       $a2, $a2, 0x364
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3398, 0X364));
    // 0x8080024C: jal         0x8001D3D8
    // 0x80800250: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    func_8001D3D8(rdram, ctx);
        goto after_19;
    // 0x80800250: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_19:
    // 0x80800254: b           L_80800278
    // 0x80800258: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80800278;
    // 0x80800258: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080025C:
    // 0x8080025C: jal         0x8001D37C
    // 0x80800260: addiu       $a0, $a0, 0x36C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X36C));
    func_8001D37C(rdram, ctx);
        goto after_20;
    // 0x80800260: addiu       $a0, $a0, 0x36C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X36C));
    after_20:
    // 0x80800264: b           L_80800278
    // 0x80800268: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80800278;
    // 0x80800268: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080026C:
    // 0x8080026C: jal         0x8001D37C
    // 0x80800270: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X370));
    func_8001D37C(rdram, ctx);
        goto after_21;
    // 0x80800270: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3398, 0X370));
    after_21:
    // 0x80800274: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800278:
    // 0x80800278: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080027C: bne         $s1, $at, L_80800128
    if (ctx->r17 != ctx->r1) {
        // 0x80800280: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_80800128;
    }
    // 0x80800280: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80800284: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800288: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800294: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080029C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808002A0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808002A4: jr          $ra
    // 0x808002A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808002A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002AC: nop

;}
RECOMP_FUNC void func_800C70F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C70F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C70F4: lw          $t6, -0x5520($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5520);
    // 0x800C70F8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C70FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C7100: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C7104: jr          $ra
    // 0x800C7108: sw          $t6, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r14;
    return;
    // 0x800C7108: sw          $t6, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8008D964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D96C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D970: jal         0x800C6E38
    // 0x8008D974: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D974: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_0:
    // 0x8008D978: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D97C: beq         $t6, $zero, L_8008D994
    if (ctx->r14 == 0) {
        // 0x8008D980: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D994;
    }
    // 0x8008D980: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D984: jal         0x800A3304
    // 0x8008D988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D98C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D990: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D994:
    // 0x8008D994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D99C: jr          $ra
    // 0x8008D9A0: nop

    return;
    // 0x8008D9A0: nop

;}
RECOMP_FUNC void func_80800078_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800084: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800088: lh          $a1, 0x10($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X10);
    // 0x8080008C: beq         $a1, $zero, L_808000B0
    if (ctx->r5 == 0) {
        // 0x80800090: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_808000B0;
    }
    // 0x80800090: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80800094: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800098: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8080009C: jal         0x800ADFE0
    // 0x808000A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800ADFE0(rdram, ctx);
        goto after_0;
    // 0x808000A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000A8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x808000AC: sh          $zero, 0x10($t8)
    MEM_H(0X10, ctx->r24) = 0;
L_808000B0:
    // 0x808000B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void chswitch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800604: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800608: jal         0x800DA298
    // 0x8080060C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080060C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800610: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800614: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800618: beq         $v0, $zero, L_8080063C
    if (ctx->r2 == 0) {
        // 0x8080061C: sw          $t6, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->r14;
            goto L_8080063C;
    }
    // 0x8080061C: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x80800620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080062C: jal         0x80102424
    // 0x80800630: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800630: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800634: b           L_80800658
    // 0x80800638: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800658;
    // 0x80800638: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8080063C:
    // 0x8080063C: lui         $at, 0x3EC0
    ctx->r1 = S32(0X3EC0 << 16);
    // 0x80800640: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080064C: jal         0x80102424
    // 0x80800650: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800650: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80800654: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80800658:
    // 0x80800658: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x8080065C: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80800660: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80800664: jal         0x80102E08
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102E08(rdram, ctx);
        goto after_3;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080066C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800670: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800674: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800678: jr          $ra
    // 0x8080067C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080067C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808002DC_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002E0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002E4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808002E8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808002EC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808002F0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808002F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808002F8: jal         0x800EA05C
    // 0x808002FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808002FC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80800300: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1648, 0X8C0) << 16);
    // 0x80800304: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1648, 0X8C4) << 16);
    // 0x80800308: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080030C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800310: addiu       $s1, $s1, 0x8C4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1648, 0X8C4));
    // 0x80800314: addiu       $s0, $s0, 0x8C0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1648, 0X8C0));
    // 0x80800318: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_8080031C:
    // 0x8080031C: bnel        $s2, $t6, L_80800330
    if (ctx->r18 != ctx->r14) {
        // 0x80800320: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800330;
    }
    goto skip_0;
    // 0x80800320: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800324: jal         0x800885E0
    // 0x80800328: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    _glintrosyncDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800328: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8080032C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80800330:
    // 0x80800330: bnel        $s0, $s1, L_8080031C
    if (ctx->r16 != ctx->r17) {
        // 0x80800334: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_8080031C;
    }
    goto skip_1;
    // 0x80800334: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80800338: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080033C: jal         0x808000B0
    // 0x80800340: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808000B0_chintroticker(rdram, ctx);
        goto after_2;
    // 0x80800340: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80800344: bne         $v0, $zero, L_8080035C
    if (ctx->r2 != 0) {
        // 0x80800348: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080035C;
    }
    // 0x80800348: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080034C: jal         0x800FFAB0
    // 0x80800350: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800350: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800354: b           L_808003A0
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003A0;
    // 0x80800358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080035C:
    // 0x8080035C: jal         0x80800188
    // 0x80800360: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80800188_chintroticker(rdram, ctx);
        goto after_4;
    // 0x80800360: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x80800364: jal         0x80088838
    // 0x80800368: nop

    _glcutDll_entrypoint_18(rdram, ctx);
        goto after_5;
    // 0x80800368: nop

    after_5:
    // 0x8080036C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80800370: bne         $v0, $at, L_80800384
    if (ctx->r2 != ctx->r1) {
        // 0x80800374: nop
    
            goto L_80800384;
    }
    // 0x80800374: nop

    // 0x80800378: lbu         $t8, 0x65($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X65);
    // 0x8080037C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80800380: sb          $t9, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r25;
L_80800384:
    // 0x80800384: jal         0x80800000
    // 0x80800388: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800000_chintroticker(rdram, ctx);
        goto after_6;
    // 0x80800388: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8080038C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800390: nop

    // 0x80800394: swc1        $f0, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f0.u32l;
    // 0x80800398: swc1        $f0, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f0.u32l;
    // 0x8080039C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003A0:
    // 0x808003A0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808003A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808003B0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808003B4: jr          $ra
    // 0x808003B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808003B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80098BA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098BAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80098BB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80098BB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80098BB8: jal         0x80091E80
    // 0x80098BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80091E80(rdram, ctx);
        goto after_0;
    // 0x80098BBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80098BC0: beq         $v0, $zero, L_80098BD0
    if (ctx->r2 == 0) {
        // 0x80098BC4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80098BD0;
    }
    // 0x80098BC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80098BC8: jal         0x80092444
    // 0x80098BCC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80092444(rdram, ctx);
        goto after_1;
    // 0x80098BCC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80098BD0:
    // 0x80098BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098BD8: jr          $ra
    // 0x80098BDC: nop

    return;
    // 0x80098BDC: nop

;}
RECOMP_FUNC void func_80800D20_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D28: jal         0x8009E6EC
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D30: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x80800D34: bne         $v0, $at, L_80800D6C
    if (ctx->r2 != ctx->r1) {
        // 0x80800D38: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D6C;
    }
    // 0x80800D38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D3C: jal         0x80099A58
    // 0x80800D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80099A58(rdram, ctx);
        goto after_1;
    // 0x80800D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800D44: addiu       $at, $zero, 0x11E8
    ctx->r1 = ADD32(0, 0X11E8);
    // 0x80800D48: bne         $v0, $at, L_80800D5C
    if (ctx->r2 != ctx->r1) {
        // 0x80800D4C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D5C;
    }
    // 0x80800D4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D50: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x80800D54: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800D58: sw          $t7, 0x164($a0)
    MEM_W(0X164, ctx->r4) = ctx->r15;
L_80800D5C:
    // 0x80800D5C: jal         0x8009E830
    // 0x80800D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80800D60: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800D64: b           L_80800D78
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D78;
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D6C:
    // 0x80800D6C: jal         0x808003B4
    // 0x80800D70: nop

    func_808003B4_bsstatue(rdram, ctx);
        goto after_3;
    // 0x80800D70: nop

    after_3:
    // 0x80800D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D78:
    // 0x80800D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D7C: jr          $ra
    // 0x80800D80: nop

    return;
    // 0x80800D80: nop

;}
