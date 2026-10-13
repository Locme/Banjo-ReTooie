#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void idflashbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800008: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080000C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800010: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80800014: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x80800018: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8080001C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800020: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800024: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800028: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8080002C: beq         $at, $zero, L_80800098
    if (ctx->r1 == 0) {
        // 0x80800030: nop
    
            goto L_80800098;
    }
    // 0x80800030: nop

L_80800034:
    // 0x80800034: lbu         $t9, 0xC($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XC);
    // 0x80800038: addu        $a0, $t9, $v0
    ctx->r4 = ADD32(ctx->r25, ctx->r2);
    // 0x8080003C: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x80800040: bnel        $at, $zero, L_80800050
    if (ctx->r1 != 0) {
        // 0x80800044: sb          $a0, 0xC($a2)
        MEM_B(0XC, ctx->r6) = ctx->r4;
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800044: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
    skip_0:
    // 0x80800048: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8080004C: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
L_80800050:
    // 0x80800050: lbu         $t0, 0xD($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XD);
    // 0x80800054: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    // 0x80800058: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8080005C: bnel        $at, $zero, L_8080006C
    if (ctx->r1 != 0) {
        // 0x80800060: sb          $a0, 0xD($a2)
        MEM_B(0XD, ctx->r6) = ctx->r4;
            goto L_8080006C;
    }
    goto skip_1;
    // 0x80800060: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
    skip_1:
    // 0x80800064: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800068: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
L_8080006C:
    // 0x8080006C: lbu         $t1, 0xE($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XE);
    // 0x80800070: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800074: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    // 0x80800078: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x8080007C: bnel        $at, $zero, L_8080008C
    if (ctx->r1 != 0) {
        // 0x80800080: sltu        $at, $a1, $v1
        ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
            goto L_8080008C;
    }
    goto skip_2;
    // 0x80800080: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    skip_2:
    // 0x80800084: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800088: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
L_8080008C:
    // 0x8080008C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800090: bne         $at, $zero, L_80800034
    if (ctx->r1 != 0) {
        // 0x80800094: sb          $a0, -0x2($a2)
        MEM_B(-0X2, ctx->r6) = ctx->r4;
            goto L_80800034;
    }
    // 0x80800094: sb          $a0, -0x2($a2)
    MEM_B(-0X2, ctx->r6) = ctx->r4;
L_80800098:
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_800CB968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB96C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB970: jal         0x800CB8BC
    // 0x800CB974: nop

    func_800CB8BC(rdram, ctx);
        goto after_0;
    // 0x800CB974: nop

    after_0:
    // 0x800CB978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB97C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB980: jr          $ra
    // 0x800CB984: nop

    return;
    // 0x800CB984: nop

;}
RECOMP_FUNC void func_808008D4_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008E8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808008EC: bgez        $t8, L_808008FC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808008F0: nop
    
            goto L_808008FC;
    }
    // 0x808008F0: nop

    // 0x808008F4: b           L_8080096C
    // 0x808008F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080096C;
    // 0x808008F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008FC:
    // 0x808008FC: jal         0x80089F78
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800904: bne         $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x80800908: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800914;
    }
    // 0x80800908: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080090C: b           L_8080096C
    // 0x80800910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080096C;
    // 0x80800910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800914:
    // 0x80800914: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x80800918: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x8080091C: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x80800920: jal         0x8010C9FC
    // 0x80800924: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8010C9FC(rdram, ctx);
        goto after_1;
    // 0x80800924: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800928: bne         $v0, $zero, L_80800938
    if (ctx->r2 != 0) {
        // 0x8080092C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800938;
    }
    // 0x8080092C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800930: b           L_8080096C
    // 0x80800934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080096C;
    // 0x80800934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800938:
    // 0x80800938: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080093C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800940: jal         0x8010C668
    // 0x80800944: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_8010C668(rdram, ctx);
        goto after_2;
    // 0x80800944: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_2:
    // 0x80800948: bne         $v0, $zero, L_80800958
    if (ctx->r2 != 0) {
        // 0x8080094C: nop
    
            goto L_80800958;
    }
    // 0x8080094C: nop

    // 0x80800950: b           L_8080096C
    // 0x80800954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080096C;
    // 0x80800954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800958:
    // 0x80800958: jal         0x80089EF8
    // 0x8080095C: nop

    _suchase_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080095C: nop

    after_3:
    // 0x80800960: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800964: xor         $v0, $v0, $t9
    ctx->r2 = ctx->r2 ^ ctx->r25;
    // 0x80800968: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8080096C:
    // 0x8080096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800974: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void func_8080047C_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800480: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800488: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8080048C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800490: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800494: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800498: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8080049C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x808004A0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808004A4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808004A8: jal         0x80100094
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E60) << 16);
    // 0x808004B4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808004B8: lwc1        $f20, 0x1E60($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E60));
    // 0x808004BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808004C0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808004C4: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_808004C8:
    // 0x808004C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004CC: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x808004D0: addu        $s0, $s4, $s1
    ctx->r16 = ADD32(ctx->r20, ctx->r17);
    // 0x808004D4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x808004D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004DC: nop

    // 0x808004E0: bc1fl       L_8080057C
    if (!c1cs) {
        // 0x808004E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080057C;
    }
    goto skip_0;
    // 0x808004E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x808004E8: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x808004EC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x808004F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808004F4: bne         $a0, $zero, L_80800518
    if (ctx->r4 != 0) {
        // 0x808004F8: addu        $s3, $s4, $t6
        ctx->r19 = ADD32(ctx->r20, ctx->r14);
            goto L_80800518;
    }
    // 0x808004F8: addu        $s3, $s4, $t6
    ctx->r19 = ADD32(ctx->r20, ctx->r14);
    // 0x808004FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(776, 0X2010) << 16);
    // 0x80800500: addiu       $a2, $a2, 0x2010
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(776, 0X2010));
    // 0x80800504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800508: jal         0x800C4350
    // 0x8080050C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C4350(rdram, ctx);
        goto after_1;
    // 0x8080050C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80800510: sb          $v0, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r2;
    // 0x80800514: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80800518:
    // 0x80800518: lhu         $t7, 0x72($s6)
    ctx->r15 = MEM_HU(ctx->r22, 0X72);
    // 0x8080051C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800520: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800524: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800528: bne         $s5, $t8, L_8080054C
    if (ctx->r21 != ctx->r24) {
        // 0x8080052C: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_8080054C;
    }
    // 0x8080052C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800530: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800534: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800538: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080053C: jal         0x800C3224
    // 0x80800540: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C3224(rdram, ctx);
        goto after_2;
    // 0x80800540: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800544: b           L_8080055C
    // 0x80800548: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
        goto L_8080055C;
    // 0x80800548: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
L_8080054C:
    // 0x8080054C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800550: jal         0x800C3224
    // 0x80800554: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    func_800C3224(rdram, ctx);
        goto after_3;
    // 0x80800554: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    after_3:
    // 0x80800558: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
L_8080055C:
    // 0x8080055C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800560: jal         0x800C4350
    // 0x80800564: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x80800564: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800568: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080056C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800570: nop

    // 0x80800574: swc1        $f8, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f8.u32l;
    // 0x80800578: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080057C:
    // 0x8080057C: bne         $s1, $s5, L_808004C8
    if (ctx->r17 != ctx->r21) {
        // 0x80800580: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808004C8;
    }
    // 0x80800580: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800584: lhu         $v0, 0x72($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X72);
    // 0x80800588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080058C: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800590: beql        $t9, $at, L_808006FC
    if (ctx->r25 == ctx->r1) {
        // 0x80800594: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808006FC;
    }
    goto skip_1;
    // 0x80800594: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80800598: beq         $t9, $s5, L_808005B4
    if (ctx->r25 == ctx->r21) {
        // 0x8080059C: addiu       $a0, $zero, 0xF5
        ctx->r4 = ADD32(0, 0XF5);
            goto L_808005B4;
    }
    // 0x8080059C: addiu       $a0, $zero, 0xF5
    ctx->r4 = ADD32(0, 0XF5);
    // 0x808005A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808005A4: beq         $t9, $at, L_80800654
    if (ctx->r25 == ctx->r1) {
        // 0x808005A8: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_80800654;
    }
    // 0x808005A8: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x808005AC: b           L_808006FC
    // 0x808005B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808006FC;
    // 0x808005B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808005B4:
    // 0x808005B4: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x808005B8: jal         0x800D24E8
    // 0x808005BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_5;
    // 0x808005BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808005C0: lw          $t0, 0x34($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X34);
    // 0x808005C4: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x808005C8: beq         $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x808005CC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(776, 0X1E64) << 16);
            goto L_80800634;
    }
    // 0x808005CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E64) << 16);
    // 0x808005D0: jal         0x800DC298
    // 0x808005D4: lwc1        $f12, 0x1E64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E64));
    func_800DC298(rdram, ctx);
        goto after_6;
    // 0x808005D4: lwc1        $f12, 0x1E64($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E64));
    after_6:
    // 0x808005D8: beq         $v0, $zero, L_80800634
    if (ctx->r2 == 0) {
        // 0x808005DC: nop
    
            goto L_80800634;
    }
    // 0x808005DC: nop

    // 0x808005E0: jal         0x800DC0C0
    // 0x808005E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x808005E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_7:
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E68) << 16);
    // 0x808005EC: lwc1        $f10, 0x1E68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E68));
    // 0x808005F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005F4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808005F8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808005FC: nop

    // 0x80800600: bc1fl       L_80800614
    if (!c1cs) {
        // 0x80800604: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80800614;
    }
    goto skip_2;
    // 0x80800604: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x80800608: b           L_8080062C
    // 0x8080060C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_8080062C;
    // 0x8080060C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80800610: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80800614:
    // 0x80800614: nop

    // 0x80800618: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8080061C: nop

    // 0x80800620: bc1f        L_8080062C
    if (!c1cs) {
        // 0x80800624: nop
    
            goto L_8080062C;
    }
    // 0x80800624: nop

    // 0x80800628: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_8080062C:
    // 0x8080062C: jal         0x80108B04
    // 0x80800630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80108B04(rdram, ctx);
        goto after_8;
    // 0x80800630: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
L_80800634:
    // 0x80800634: jal         0x800CEAD0
    // 0x80800638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_9;
    // 0x80800638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8080063C: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x80800640: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808006F8;
    }
    // 0x80800640: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800644: jal         0x80800018
    // 0x80800648: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800018_chwaspnestgame(rdram, ctx);
        goto after_10;
    // 0x80800648: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080064C: b           L_808006FC
    // 0x80800650: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_808006FC;
    // 0x80800650: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800654:
    // 0x80800654: jal         0x800D0A9C
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_11;
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080065C: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x80800660: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_80800670;
    }
    // 0x80800660: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x80800664: jal         0x800D0B68
    // 0x80800668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_12;
    // 0x80800668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080066C: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x80800670: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_808006F8;
    }
L_80800670:
    // 0x80800670: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800674: jal         0x800D0A9C
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_13;
    // 0x80800678: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x8080067C: beq         $v0, $zero, L_80800694
    if (ctx->r2 == 0) {
        // 0x80800680: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80800694;
    }
    // 0x80800680: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800684: jal         0x800D0B68
    // 0x80800688: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0B68(rdram, ctx);
        goto after_14;
    // 0x80800688: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8080068C: beql        $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x80800690: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808006FC;
    }
    goto skip_3;
    // 0x80800690: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_3:
L_80800694:
    // 0x80800694: jal         0x800D90A4
    // 0x80800698: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_15;
    // 0x80800698: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    after_15:
    // 0x8080069C: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x808006A0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808006F8;
    }
    // 0x808006A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808006A4: jal         0x80100094
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808006AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006B0: jal         0x80090708
    // 0x808006B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_17;
    // 0x808006B4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_17:
    // 0x808006B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808006BC: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    // 0x808006C0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808006C4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808006C8: jal         0x8008A2C8
    // 0x808006CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x808006CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_18:
    // 0x808006D0: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x808006D4: addiu       $t1, $zero, 0x99
    ctx->r9 = ADD32(0, 0X99);
    // 0x808006D8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808006DC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x808006E0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808006E4: jal         0x8008A208
    // 0x808006E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808006E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_19:
    // 0x808006EC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808006F0: jal         0x80101FDC
    // 0x808006F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_20;
    // 0x808006F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_20:
L_808006F8:
    // 0x808006F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808006FC:
    // 0x808006FC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800700: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800704: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800708: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8080070C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800710: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800714: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800718: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8080071C: jr          $ra
    // 0x80800720: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800720: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _sukickball_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B28: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B28);
    return;
    // 0x80089B2C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _bstaxi_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E68: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E68);
    return;
    // 0x80083E6C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_80800814_susubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800814: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800818: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8080081C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800820: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800824: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800828: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080082C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800830: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800834: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800838: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800840: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800844: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_80800848:
    // 0x80800848: jal         0x808008DC
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_susubgame(rdram, ctx);
        goto after_0;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800850: beq         $v0, $zero, L_80800874
    if (ctx->r2 == 0) {
        // 0x80800854: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: jal         0x800A93E4
    // 0x8080085C: ori         $s1, $s2, 0x800
    ctx->r17 = ctx->r18 | 0X800;
    func_800A93E4(rdram, ctx);
        goto after_1;
    // 0x8080085C: ori         $s1, $s2, 0x800
    ctx->r17 = ctx->r18 | 0X800;
    after_1:
    // 0x80800860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800864: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80800868: lh          $a2, 0x4($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X4);
    // 0x8080086C: jal         0x80089540
    // 0x80800870: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80800870: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_2:
L_80800874:
    // 0x80800874: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800878: bne         $s0, $s4, L_80800848
    if (ctx->r16 != ctx->r20) {
        // 0x8080087C: nop
    
            goto L_80800848;
    }
    // 0x8080087C: nop

    // 0x80800880: andi        $t6, $s2, 0x800
    ctx->r14 = ctx->r18 & 0X800;
    // 0x80800884: beq         $t6, $zero, L_80800894
    if (ctx->r14 == 0) {
        // 0x80800888: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800894;
    }
    // 0x80800888: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080088C: b           L_80800898
    // 0x80800890: sb          $zero, 0x1($s5)
    MEM_B(0X1, ctx->r21) = 0;
        goto L_80800898;
    // 0x80800890: sb          $zero, 0x1($s5)
    MEM_B(0X1, ctx->r21) = 0;
L_80800894:
    // 0x80800894: sb          $t7, 0x1($s5)
    MEM_B(0X1, ctx->r21) = ctx->r15;
L_80800898:
    // 0x80800898: lbu         $t8, 0x1($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X1);
    // 0x8080089C: beql        $t8, $zero, L_808008BC
    if (ctx->r24 == 0) {
        // 0x808008A0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808008BC;
    }
    goto skip_0;
    // 0x808008A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808008A4: jal         0x800EA05C
    // 0x808008A8: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x808008A8: nop

    after_3:
    // 0x808008AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008B0: jal         0x800887D8
    // 0x808008B4: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808008B4: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
    after_4:
    // 0x808008B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008BC:
    // 0x808008BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808008CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808008D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808008D4: jr          $ra
    // 0x808008D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808008D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808024E0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024E0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808024E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808024E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808024EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808024F0: jal         0x80100094
    // 0x808024F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808024F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808024F8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808024FC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80802500: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80802504: bltzl       $t8, L_80802530
    if (SIGNED(ctx->r24) < 0) {
        // 0x80802508: lhu         $t2, 0x72($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X72);
            goto L_80802530;
    }
    goto skip_0;
    // 0x80802508: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x8080250C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80802510: jal         0x800DA298
    // 0x80802514: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80802514: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802518: beq         $v0, $zero, L_8080252C
    if (ctx->r2 == 0) {
        // 0x8080251C: lw          $a3, 0x74($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X74);
            goto L_8080252C;
    }
    // 0x8080251C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802520: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80802524: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80802528: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_8080252C:
    // 0x8080252C: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
L_80802530:
    // 0x80802530: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80802534: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80802538: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x8080253C: beq         $at, $zero, L_80802CD4
    if (ctx->r1 == 0) {
        // 0x80802540: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80802CD4;
    }
    // 0x80802540: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80802544: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4170) << 16);
    // 0x80802548: addu        $at, $at, $t4
    gpr jr_addend_80802550 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8080254C: lw          $t4, 0x4170($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4170));
    // 0x80802550: jr          $t4
    // 0x80802554: nop

    switch (jr_addend_80802550 >> 2) {
        case 0: goto L_80802558; break;
        case 1: goto L_808026EC; break;
        case 2: goto L_80802B00; break;
        case 3: goto L_80802B64; break;
        case 4: goto L_80802B88; break;
        default: switch_error(__func__, 0x80802550, 0x80804170);
    }
    // 0x80802554: nop

L_80802558:
    // 0x80802558: lbu         $v0, 0x26($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X26);
    // 0x8080255C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802560: beql        $v0, $zero, L_8080257C
    if (ctx->r2 == 0) {
        // 0x80802564: lbu         $v0, 0x25($a3)
        ctx->r2 = MEM_BU(ctx->r7, 0X25);
            goto L_8080257C;
    }
    goto skip_1;
    // 0x80802564: lbu         $v0, 0x25($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X25);
    skip_1:
    // 0x80802568: beq         $v0, $at, L_808026DC
    if (ctx->r2 == ctx->r1) {
        // 0x8080256C: nop
    
            goto L_808026DC;
    }
    // 0x8080256C: nop

    // 0x80802570: b           L_80802CD4
    // 0x80802574: nop

        goto L_80802CD4;
    // 0x80802574: nop

    // 0x80802578: lbu         $v0, 0x25($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X25);
L_8080257C:
    // 0x8080257C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802580: beq         $v0, $zero, L_808025A4
    if (ctx->r2 == 0) {
        // 0x80802584: nop
    
            goto L_808025A4;
    }
    // 0x80802584: nop

    // 0x80802588: beq         $v0, $at, L_808025BC
    if (ctx->r2 == ctx->r1) {
        // 0x8080258C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808025BC;
    }
    // 0x8080258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802590: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802594: beq         $v0, $at, L_808025D8
    if (ctx->r2 == ctx->r1) {
        // 0x80802598: nop
    
            goto L_808025D8;
    }
    // 0x80802598: nop

    // 0x8080259C: b           L_80802CD4
    // 0x808025A0: nop

        goto L_80802CD4;
    // 0x808025A0: nop

L_808025A4:
    // 0x808025A4: jal         0x80801E98
    // 0x808025A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801E98_chflysaucer(rdram, ctx);
        goto after_2;
    // 0x808025A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808025AC: jal         0x80802014
    // 0x808025B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802014_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x808025B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808025B4: b           L_80802CD4
    // 0x808025B8: nop

        goto L_80802CD4;
    // 0x808025B8: nop

L_808025BC:
    // 0x808025BC: jal         0x808012A4
    // 0x808025C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_4;
    // 0x808025C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x808025C4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x808025C8: jal         0x800904F4
    // 0x808025CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_5;
    // 0x808025CC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808025D0: b           L_80802CD4
    // 0x808025D4: nop

        goto L_80802CD4;
    // 0x808025D4: nop

L_808025D8:
    // 0x808025D8: jal         0x8008FF40
    // 0x808025DC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_8008FF40(rdram, ctx);
        goto after_6;
    // 0x808025DC: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_6:
    // 0x808025E0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808025E4: jal         0x800F1DCC
    // 0x808025E8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x808025E8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    after_7:
    // 0x808025EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4184) << 16);
    // 0x808025F0: lwc1        $f6, 0x4184($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4184));
    // 0x808025F4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808025F8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x808025FC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80802600: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80802604: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80802608: jal         0x800906DC
    // 0x8080260C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    func_800906DC(rdram, ctx);
        goto after_8;
    // 0x8080260C: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80802610: jal         0x8010D254
    // 0x80802614: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_8010D254(rdram, ctx);
        goto after_9;
    // 0x80802614: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_9:
    // 0x80802618: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080261C: jal         0x800EE7F8
    // 0x80802620: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80802620: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80802624: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80802628: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080262C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802630: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80802634: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80802638: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8080263C: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80802640: jal         0x800EFB24
    // 0x80802644: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x80802644: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80802648: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x8080264C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80802650: jal         0x800EF334
    // 0x80802654: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EF334(rdram, ctx);
        goto after_12;
    // 0x80802654: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x80802658: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x8080265C: jal         0x800EF04C
    // 0x80802660: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x80802660: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_13:
    // 0x80802664: jal         0x800906B0
    // 0x80802668: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800906B0(rdram, ctx);
        goto after_14;
    // 0x80802668: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_14:
    // 0x8080266C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80802670: jal         0x800EEB40
    // 0x80802674: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EEB40(rdram, ctx);
        goto after_15;
    // 0x80802674: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_15:
    // 0x80802678: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4188) << 16);
    // 0x8080267C: lwc1        $f8, 0x4188($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4188));
    // 0x80802680: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80802684: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802688: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080268C: bc1f        L_80802CD4
    if (!c1cs) {
        // 0x80802690: nop
    
            goto L_80802CD4;
    }
    // 0x80802690: nop

    // 0x80802694: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802698: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080269C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808026A0: nop

    // 0x808026A4: bc1f        L_80802CD4
    if (!c1cs) {
        // 0x808026A8: nop
    
            goto L_80802CD4;
    }
    // 0x808026A8: nop

    // 0x808026AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808026B0: nop

    // 0x808026B4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808026B8: nop

    // 0x808026BC: bc1f        L_80802CD4
    if (!c1cs) {
        // 0x808026C0: nop
    
            goto L_80802CD4;
    }
    // 0x808026C0: nop

    // 0x808026C4: jal         0x800904C8
    // 0x808026C8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_16;
    // 0x808026C8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_16:
    // 0x808026CC: jal         0x808005FC
    // 0x808026D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005FC_chflysaucer(rdram, ctx);
        goto after_17;
    // 0x808026D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808026D4: b           L_80802CD4
    // 0x808026D8: nop

        goto L_80802CD4;
    // 0x808026D8: nop

L_808026DC:
    // 0x808026DC: jal         0x80802014
    // 0x808026E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802014_chflysaucer(rdram, ctx);
        goto after_18;
    // 0x808026E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808026E4: b           L_80802CD4
    // 0x808026E8: nop

        goto L_80802CD4;
    // 0x808026E8: nop

L_808026EC:
    // 0x808026EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026F0: jal         0x80101F24
    // 0x808026F4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80101F24(rdram, ctx);
        goto after_19;
    // 0x808026F4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_19:
    // 0x808026F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026FC: jal         0x80101DDC
    // 0x80802700: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80101DDC(rdram, ctx);
        goto after_20;
    // 0x80802700: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80802704: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802708: beq         $v0, $zero, L_8080272C
    if (ctx->r2 == 0) {
        // 0x8080270C: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8080272C;
    }
    // 0x8080270C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802718: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8080271C: jal         0x80801568
    // 0x80802720: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    func_80801568_chflysaucer(rdram, ctx);
        goto after_21;
    // 0x80802720: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_21:
    // 0x80802724: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802728: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
L_8080272C:
    // 0x8080272C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X418C) << 16);
    // 0x80802730: lwc1        $f6, 0x418C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X418C));
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802738: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8080273C: nop

    // 0x80802740: bc1f        L_80802788
    if (!c1cs) {
        // 0x80802744: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1692, 0X4190) << 16);
            goto L_80802788;
    }
    // 0x80802744: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4190) << 16);
    // 0x80802748: lwc1        $f4, 0x4190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4190));
    // 0x8080274C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4194) << 16);
    // 0x80802750: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80802754: nop

    // 0x80802758: bc1f        L_80802788
    if (!c1cs) {
        // 0x8080275C: nop
    
            goto L_80802788;
    }
    // 0x8080275C: nop

    // 0x80802760: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80802764: lwc1        $f8, 0x4194($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4194));
    // 0x80802768: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4198) << 16);
    // 0x8080276C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802770: nop

    // 0x80802774: bc1f        L_80802788
    if (!c1cs) {
        // 0x80802778: nop
    
            goto L_80802788;
    }
    // 0x80802778: nop

    // 0x8080277C: lwc1        $f14, 0x4198($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4198));
    // 0x80802780: add.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80802784: swc1        $f10, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f10.u32l;
L_80802788:
    // 0x80802788: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X419C) << 16);
    // 0x8080278C: lwc1        $f14, 0x419C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X419C));
    // 0x80802790: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41A0) << 16);
    // 0x80802794: lwc1        $f18, 0x41A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41A0));
    // 0x80802798: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41A4) << 16);
    // 0x8080279C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x808027A0: nop

    // 0x808027A4: bc1f        L_808027EC
    if (!c1cs) {
        // 0x808027A8: nop
    
            goto L_808027EC;
    }
    // 0x808027A8: nop

    // 0x808027AC: lwc1        $f6, 0x41A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41A4));
    // 0x808027B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41A8) << 16);
    // 0x808027B4: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808027B8: nop

    // 0x808027BC: bc1f        L_808027EC
    if (!c1cs) {
        // 0x808027C0: nop
    
            goto L_808027EC;
    }
    // 0x808027C0: nop

    // 0x808027C4: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x808027C8: lwc1        $f4, 0x41A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41A8));
    // 0x808027CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41AC) << 16);
    // 0x808027D0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808027D4: nop

    // 0x808027D8: bc1f        L_808027EC
    if (!c1cs) {
        // 0x808027DC: nop
    
            goto L_808027EC;
    }
    // 0x808027DC: nop

    // 0x808027E0: lwc1        $f16, 0x41AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41AC));
    // 0x808027E4: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x808027E8: swc1        $f8, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f8.u32l;
L_808027EC:
    // 0x808027EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41B0) << 16);
    // 0x808027F0: lwc1        $f16, 0x41B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41B0));
    // 0x808027F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41B4) << 16);
    // 0x808027F8: lwc1        $f10, 0x41B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41B4));
    // 0x808027FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41B8) << 16);
    // 0x80802800: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80802804: nop

    // 0x80802808: bc1f        L_80802848
    if (!c1cs) {
        // 0x8080280C: nop
    
            goto L_80802848;
    }
    // 0x8080280C: nop

    // 0x80802810: lwc1        $f18, 0x41B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41B8));
    // 0x80802814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41BC) << 16);
    // 0x80802818: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8080281C: nop

    // 0x80802820: bc1f        L_80802848
    if (!c1cs) {
        // 0x80802824: nop
    
            goto L_80802848;
    }
    // 0x80802824: nop

    // 0x80802828: lwc1        $f12, 0x41BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41BC));
    // 0x8080282C: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80802830: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80802834: nop

    // 0x80802838: bc1f        L_80802848
    if (!c1cs) {
        // 0x8080283C: nop
    
            goto L_80802848;
    }
    // 0x8080283C: nop

    // 0x80802840: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80802844: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_80802848:
    // 0x80802848: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41C0) << 16);
    // 0x8080284C: lwc1        $f12, 0x41C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41C0));
    // 0x80802850: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41C4) << 16);
    // 0x80802854: lwc1        $f4, 0x41C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41C4));
    // 0x80802858: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8080285C: nop

    // 0x80802860: bc1fl       L_8080289C
    if (!c1cs) {
        // 0x80802864: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8080289C;
    }
    goto skip_2;
    // 0x80802864: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_2:
    // 0x80802868: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8080286C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41C8) << 16);
    // 0x80802870: bc1fl       L_8080289C
    if (!c1cs) {
        // 0x80802874: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8080289C;
    }
    goto skip_3;
    // 0x80802874: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_3:
    // 0x80802878: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x8080287C: lwc1        $f8, 0x41C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41C8));
    // 0x80802880: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802884: nop

    // 0x80802888: bc1fl       L_8080289C
    if (!c1cs) {
        // 0x8080288C: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8080289C;
    }
    goto skip_4;
    // 0x8080288C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_4:
    // 0x80802890: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80802894: swc1        $f10, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f10.u32l;
    // 0x80802898: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_8080289C:
    // 0x8080289C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41CC) << 16);
    // 0x808028A0: bc1f        L_808028E0
    if (!c1cs) {
        // 0x808028A4: nop
    
            goto L_808028E0;
    }
    // 0x808028A4: nop

    // 0x808028A8: lwc1        $f18, 0x41CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41CC));
    // 0x808028AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41D0) << 16);
    // 0x808028B0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x808028B4: nop

    // 0x808028B8: bc1f        L_808028E0
    if (!c1cs) {
        // 0x808028BC: nop
    
            goto L_808028E0;
    }
    // 0x808028BC: nop

    // 0x808028C0: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x808028C4: lwc1        $f6, 0x41D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41D0));
    // 0x808028C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808028CC: nop

    // 0x808028D0: bc1f        L_808028E0
    if (!c1cs) {
        // 0x808028D4: nop
    
            goto L_808028E0;
    }
    // 0x808028D4: nop

    // 0x808028D8: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x808028DC: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
L_808028E0:
    // 0x808028E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41D4) << 16);
    // 0x808028E4: lwc1        $f8, 0x41D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41D4));
    // 0x808028E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41D8) << 16);
    // 0x808028EC: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808028F0: nop

    // 0x808028F4: bc1f        L_80802934
    if (!c1cs) {
        // 0x808028F8: nop
    
            goto L_80802934;
    }
    // 0x808028F8: nop

    // 0x808028FC: lwc1        $f10, 0x41D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41D8));
    // 0x80802900: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41DC) << 16);
    // 0x80802904: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80802908: nop

    // 0x8080290C: bc1f        L_80802934
    if (!c1cs) {
        // 0x80802910: nop
    
            goto L_80802934;
    }
    // 0x80802910: nop

    // 0x80802914: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80802918: lwc1        $f18, 0x41DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41DC));
    // 0x8080291C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80802920: nop

    // 0x80802924: bc1f        L_80802934
    if (!c1cs) {
        // 0x80802928: nop
    
            goto L_80802934;
    }
    // 0x80802928: nop

    // 0x8080292C: sub.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80802930: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_80802934:
    // 0x80802934: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41E0) << 16);
    // 0x80802938: lwc1        $f4, 0x41E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41E0));
    // 0x8080293C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41E4) << 16);
    // 0x80802940: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80802944: nop

    // 0x80802948: bc1f        L_80802988
    if (!c1cs) {
        // 0x8080294C: nop
    
            goto L_80802988;
    }
    // 0x8080294C: nop

    // 0x80802950: lwc1        $f8, 0x41E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41E4));
    // 0x80802954: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41E8) << 16);
    // 0x80802958: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8080295C: nop

    // 0x80802960: bc1f        L_80802988
    if (!c1cs) {
        // 0x80802964: nop
    
            goto L_80802988;
    }
    // 0x80802964: nop

    // 0x80802968: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x8080296C: lwc1        $f10, 0x41E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41E8));
    // 0x80802970: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80802974: nop

    // 0x80802978: bc1f        L_80802988
    if (!c1cs) {
        // 0x8080297C: nop
    
            goto L_80802988;
    }
    // 0x8080297C: nop

    // 0x80802980: add.s       $f18, $f0, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80802984: swc1        $f18, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f18.u32l;
L_80802988:
    // 0x80802988: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41EC) << 16);
    // 0x8080298C: lwc1        $f6, 0x41EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41EC));
    // 0x80802990: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41F0) << 16);
    // 0x80802994: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80802998: nop

    // 0x8080299C: bc1fl       L_808029E0
    if (!c1cs) {
        // 0x808029A0: sw          $a3, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r7;
            goto L_808029E0;
    }
    goto skip_5;
    // 0x808029A0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    skip_5:
    // 0x808029A4: lwc1        $f4, 0x41F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41F0));
    // 0x808029A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41F4) << 16);
    // 0x808029AC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x808029B0: nop

    // 0x808029B4: bc1fl       L_808029E0
    if (!c1cs) {
        // 0x808029B8: sw          $a3, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r7;
            goto L_808029E0;
    }
    goto skip_6;
    // 0x808029B8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    skip_6:
    // 0x808029BC: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x808029C0: lwc1        $f8, 0x41F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41F4));
    // 0x808029C4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808029C8: nop

    // 0x808029CC: bc1fl       L_808029E0
    if (!c1cs) {
        // 0x808029D0: sw          $a3, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r7;
            goto L_808029E0;
    }
    goto skip_7;
    // 0x808029D0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    skip_7:
    // 0x808029D4: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x808029D8: swc1        $f10, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f10.u32l;
    // 0x808029DC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
L_808029E0:
    // 0x808029E0: jal         0x80802CF0
    // 0x808029E4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_22;
    // 0x808029E4: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_22:
    // 0x808029E8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x808029EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029F0: jal         0x80802114
    // 0x808029F4: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    func_80802114_chflysaucer(rdram, ctx);
        goto after_23;
    // 0x808029F4: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    after_23:
    // 0x808029F8: lui         $a1, 0x3F1E
    ctx->r5 = S32(0X3F1E << 16);
    // 0x808029FC: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    // 0x80802A00: jal         0x80101E14
    // 0x80802A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_24;
    // 0x80802A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80802A08: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802A0C: beq         $v0, $zero, L_80802A44
    if (ctx->r2 == 0) {
        // 0x80802A10: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_80802A44;
    }
    // 0x80802A10: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802A14: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1692, 0X4260) << 16);
    // 0x80802A18: addiu       $a2, $a2, 0x4260
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1692, 0X4260));
    // 0x80802A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A20: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802A24: jal         0x80089D18
    // 0x80802A28: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80802A28: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_25:
    // 0x80802A2C: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80802A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A34: jal         0x808021C0
    // 0x80802A38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_808021C0_chflysaucer(rdram, ctx);
        goto after_26;
    // 0x80802A38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_26:
    // 0x80802A3C: b           L_80802CD4
    // 0x80802A40: nop

        goto L_80802CD4;
    // 0x80802A40: nop

L_80802A44:
    // 0x80802A44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41F8) << 16);
    // 0x80802A48: lwc1        $f18, 0x41F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41F8));
    // 0x80802A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80802A54: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80802A58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X41FC) << 16);
    // 0x80802A5C: bc1f        L_80802A74
    if (!c1cs) {
        // 0x80802A60: nop
    
            goto L_80802A74;
    }
    // 0x80802A60: nop

    // 0x80802A64: jal         0x808021C0
    // 0x80802A68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808021C0_chflysaucer(rdram, ctx);
        goto after_27;
    // 0x80802A68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80802A6C: b           L_80802CD4
    // 0x80802A70: nop

        goto L_80802CD4;
    // 0x80802A70: nop

L_80802A74:
    // 0x80802A74: lwc1        $f6, 0x41FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X41FC));
    // 0x80802A78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4200) << 16);
    // 0x80802A7C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80802A80: nop

    // 0x80802A84: bc1fl       L_80802ABC
    if (!c1cs) {
        // 0x80802A88: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80802ABC;
    }
    goto skip_8;
    // 0x80802A88: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_8:
    // 0x80802A8C: lwc1        $f4, 0x4200($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4200));
    // 0x80802A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80802A98: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80802A9C: nop

    // 0x80802AA0: bc1fl       L_80802ABC
    if (!c1cs) {
        // 0x80802AA4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80802ABC;
    }
    goto skip_9;
    // 0x80802AA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_9:
    // 0x80802AA8: jal         0x808021C0
    // 0x80802AAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808021C0_chflysaucer(rdram, ctx);
        goto after_28;
    // 0x80802AAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80802AB0: b           L_80802CD4
    // 0x80802AB4: nop

        goto L_80802CD4;
    // 0x80802AB4: nop

    // 0x80802AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80802ABC:
    // 0x80802ABC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802AC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4204) << 16);
    // 0x80802AC4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80802AC8: nop

    // 0x80802ACC: bc1f        L_80802CD4
    if (!c1cs) {
        // 0x80802AD0: nop
    
            goto L_80802CD4;
    }
    // 0x80802AD0: nop

    // 0x80802AD4: lwc1        $f10, 0x4204($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4204));
    // 0x80802AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802ADC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80802AE0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80802AE4: nop

    // 0x80802AE8: bc1f        L_80802CD4
    if (!c1cs) {
        // 0x80802AEC: nop
    
            goto L_80802CD4;
    }
    // 0x80802AEC: nop

    // 0x80802AF0: jal         0x808021C0
    // 0x80802AF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_808021C0_chflysaucer(rdram, ctx);
        goto after_29;
    // 0x80802AF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_29:
    // 0x80802AF8: b           L_80802CD4
    // 0x80802AFC: nop

        goto L_80802CD4;
    // 0x80802AFC: nop

L_80802B00:
    // 0x80802B00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4208) << 16);
    // 0x80802B04: lwc1        $f18, 0x4208($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4208));
    // 0x80802B08: lwc1        $f0, 0x18($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80802B0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X420C) << 16);
    // 0x80802B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B14: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80802B18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80802B1C: bc1f        L_80802B34
    if (!c1cs) {
        // 0x80802B20: nop
    
            goto L_80802B34;
    }
    // 0x80802B20: nop

    // 0x80802B24: lwc1        $f6, 0x420C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X420C));
    // 0x80802B28: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80802B2C: b           L_80802B40
    // 0x80802B30: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
        goto L_80802B40;
    // 0x80802B30: swc1        $f4, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f4.u32l;
L_80802B34:
    // 0x80802B34: jal         0x80801568
    // 0x80802B38: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80801568_chflysaucer(rdram, ctx);
        goto after_30;
    // 0x80802B38: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_30:
    // 0x80802B3C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
L_80802B40:
    // 0x80802B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B44: jal         0x80802CF0
    // 0x80802B48: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_31;
    // 0x80802B48: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_31:
    // 0x80802B4C: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B54: jal         0x80802114
    // 0x80802B58: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    func_80802114_chflysaucer(rdram, ctx);
        goto after_32;
    // 0x80802B58: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    after_32:
    // 0x80802B5C: b           L_80802CD4
    // 0x80802B60: nop

        goto L_80802CD4;
    // 0x80802B60: nop

L_80802B64:
    // 0x80802B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B68: jal         0x80802CF0
    // 0x80802B6C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_33;
    // 0x80802B6C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_33:
    // 0x80802B70: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B78: jal         0x80802114
    // 0x80802B7C: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    func_80802114_chflysaucer(rdram, ctx);
        goto after_34;
    // 0x80802B7C: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    after_34:
    // 0x80802B80: b           L_80802CD4
    // 0x80802B84: nop

        goto L_80802CD4;
    // 0x80802B84: nop

L_80802B88:
    // 0x80802B88: lbu         $v0, 0x25($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X25);
    // 0x80802B8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802B90: beq         $v0, $at, L_80802BA8
    if (ctx->r2 == ctx->r1) {
        // 0x80802B94: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80802BA8;
    }
    // 0x80802B94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80802B98: beq         $v0, $at, L_80802C54
    if (ctx->r2 == ctx->r1) {
        // 0x80802B9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C54;
    }
    // 0x80802B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802BA0: b           L_80802BEC
    // 0x80802BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80802BEC;
    // 0x80802BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80802BA8:
    // 0x80802BA8: jal         0x800D8FF8
    // 0x80802BAC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_35;
    // 0x80802BAC: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_35:
    // 0x80802BB0: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802BB4: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802BB8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802BBC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80802BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802BC4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x80802BC8: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80802BCC: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x80802BD0: nop

    // 0x80802BD4: bc1fl       L_80802C58
    if (!c1cs) {
        // 0x80802BD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C58;
    }
    goto skip_10;
    // 0x80802BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x80802BDC: jal         0x808005FC
    // 0x80802BE0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_808005FC_chflysaucer(rdram, ctx);
        goto after_36;
    // 0x80802BE0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_36:
    // 0x80802BE4: b           L_80802C54
    // 0x80802BE8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
        goto L_80802C54;
    // 0x80802BE8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
L_80802BEC:
    // 0x80802BEC: jal         0x80100094
    // 0x80802BF0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x80802BF0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_37:
    // 0x80802BF4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802BF8: jal         0x80089DE0
    // 0x80802BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_13(rdram, ctx);
        goto after_38;
    // 0x80802BFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_38:
    // 0x80802C00: jal         0x80089DA8
    // 0x80802C04: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _suspline_entrypoint_6(rdram, ctx);
        goto after_39;
    // 0x80802C04: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_39:
    // 0x80802C08: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802C0C: jal         0x80089DC0
    // 0x80802C10: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _suspline_entrypoint_9(rdram, ctx);
        goto after_40;
    // 0x80802C10: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_40:
    // 0x80802C14: jal         0x80800C3C
    // 0x80802C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C3C_chflysaucer(rdram, ctx);
        goto after_41;
    // 0x80802C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80802C1C: bne         $v0, $zero, L_80802C54
    if (ctx->r2 != 0) {
        // 0x80802C20: lw          $a3, 0x74($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X74);
            goto L_80802C54;
    }
    // 0x80802C20: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802C24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802C28: jal         0x80089DA8
    // 0x80802C2C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    _suspline_entrypoint_6(rdram, ctx);
        goto after_42;
    // 0x80802C2C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_42:
    // 0x80802C30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4210) << 16);
    // 0x80802C34: lwc1        $f4, 0x4210($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4210));
    // 0x80802C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C3C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80802C40: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80802C44: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80802C48: jal         0x8080013C
    // 0x80802C4C: nop

    func_8080013C_chflysaucer(rdram, ctx);
        goto after_43;
    // 0x80802C4C: nop

    after_43:
    // 0x80802C50: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
L_80802C54:
    // 0x80802C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802C58:
    // 0x80802C58: jal         0x80802CF0
    // 0x80802C5C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80802CF0_chflysaucer(rdram, ctx);
        goto after_44;
    // 0x80802C5C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_44:
    // 0x80802C60: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C68: jal         0x80802114
    // 0x80802C6C: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    func_80802114_chflysaucer(rdram, ctx);
        goto after_45;
    // 0x80802C6C: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    after_45:
    // 0x80802C70: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C78: lbu         $t6, 0x2E($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2E);
    // 0x80802C7C: bne         $t6, $zero, L_80802CB8
    if (ctx->r14 != 0) {
        // 0x80802C80: nop
    
            goto L_80802CB8;
    }
    // 0x80802C80: nop

    // 0x80802C84: jal         0x80800000
    // 0x80802C88: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_80800000_chflysaucer(rdram, ctx);
        goto after_46;
    // 0x80802C88: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_46:
    // 0x80802C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802C90: bne         $v0, $at, L_80802CB8
    if (ctx->r2 != ctx->r1) {
        // 0x80802C94: lw          $a3, 0x74($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X74);
            goto L_80802CB8;
    }
    // 0x80802C94: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802C98: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80802C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802CA0: jal         0x800D2770
    // 0x80802CA4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    func_800D2770(rdram, ctx);
        goto after_47;
    // 0x80802CA4: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_47:
    // 0x80802CA8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80802CAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802CB0: b           L_80802CCC
    // 0x80802CB4: sb          $t7, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r15;
        goto L_80802CCC;
    // 0x80802CB4: sb          $t7, 0x2E($a3)
    MEM_B(0X2E, ctx->r7) = ctx->r15;
L_80802CB8:
    // 0x80802CB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80802CBC: lh          $a1, 0x75C8($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X75C8);
    // 0x80802CC0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80802CC4: jal         0x800D24E8
    // 0x80802CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_48;
    // 0x80802CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_48:
L_80802CCC:
    // 0x80802CCC: jal         0x80802044
    // 0x80802CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802044_chflysaucer(rdram, ctx);
        goto after_49;
    // 0x80802CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
L_80802CD4:
    // 0x80802CD4: jal         0x80802290
    // 0x80802CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802290_chflysaucer(rdram, ctx);
        goto after_50;
    // 0x80802CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80802CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802CE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802CE4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80802CE8: jr          $ra
    // 0x80802CEC: nop

    return;
    // 0x80802CEC: nop

;}
RECOMP_FUNC void func_800C082C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C082C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C0830: addiu       $v0, $v0, -0x7750
    ctx->r2 = ADD32(ctx->r2, -0X7750);
    // 0x800C0834: lbu         $t9, 0x15E($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X15E);
    // 0x800C0838: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800C083C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x800C0840: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x800C0844: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800C0848: jr          $ra
    // 0x800C084C: sb          $t1, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r9;
    return;
    // 0x800C084C: sb          $t1, 0x15E($v0)
    MEM_B(0X15E, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_8008FA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FA68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008FA6C: jal         0x800F54E4
    // 0x8008FA70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FA70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008FA74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FA78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8008FA7C: jal         0x800F4BB8
    // 0x8008FA80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F4BB8(rdram, ctx);
        goto after_1;
    // 0x8008FA80: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8008FA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FA88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FA8C: jr          $ra
    // 0x8008FA90: nop

    return;
    // 0x8008FA90: nop

;}
RECOMP_FUNC void func_80090358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009035C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090360: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090364: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80090368: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8009036C: jal         0x8008F8B0
    // 0x80090370: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x80090370: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80090374: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80090378: jal         0x8008F904
    // 0x8009037C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8008F904(rdram, ctx);
        goto after_1;
    // 0x8009037C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80090380: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80090384: jal         0x8008F9C4
    // 0x80090388: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8008F9C4(rdram, ctx);
        goto after_2;
    // 0x80090388: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8009038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090394: jr          $ra
    // 0x80090398: nop

    return;
    // 0x80090398: nop

;}
RECOMP_FUNC void func_80800E08_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800E10: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800E14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E18: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1528, 0XFCC) << 16);
    // 0x80800E1C: addiu       $t7, $t7, 0xFCC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1528, 0XFCC));
    // 0x80800E20: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x80800E24: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800E28: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800E2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E34: jal         0x800BBCB8
    // 0x80800E38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800E38: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800E3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800E40: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1528, 0XFFC) << 16);
    // 0x80800E44: addiu       $t9, $t9, 0xFFC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1528, 0XFFC));
    // 0x80800E48: lw          $a2, 0x38($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X38);
    // 0x80800E4C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800E50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E58: jal         0x800BBCB8
    // 0x80800E5C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800E5C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x80800E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E68: jr          $ra
    // 0x80800E6C: nop

    return;
    // 0x80800E6C: nop

;}
RECOMP_FUNC void func_80801980_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801980: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801984: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801988: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080198C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801990: jal         0x8008CABC
    // 0x80801994: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801994: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801998: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8080199C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808019A0: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x808019A4: beq         $at, $zero, L_80801BF8
    if (ctx->r1 == 0) {
        // 0x808019A8: sw          $v1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r3;
            goto L_80801BF8;
    }
    // 0x808019A8: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
    // 0x808019AC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x808019B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X220C) << 16);
    // 0x808019B4: addu        $at, $at, $t6
    gpr jr_addend_808019BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808019B8: lw          $t6, 0x220C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(404, 0X220C));
    // 0x808019BC: jr          $t6
    // 0x808019C0: nop

    switch (jr_addend_808019BC >> 2) {
        case 0: goto L_80801BE0; break;
        case 1: goto L_808019C4; break;
        case 2: goto L_80801B48; break;
        case 3: goto L_80801B64; break;
        case 4: goto L_80801B84; break;
        default: switch_error(__func__, 0x808019BC, 0x8080220C);
    }
    // 0x808019C0: nop

L_808019C4:
    // 0x808019C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2220) << 16);
    // 0x808019C8: lwc1        $f12, 0x2220($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2220));
    // 0x808019CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2224) << 16);
    // 0x808019D0: jal         0x800DC178
    // 0x808019D4: lwc1        $f14, 0x2224($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2224));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808019D4: lwc1        $f14, 0x2224($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2224));
    after_1:
    // 0x808019D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808019DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E0: addiu       $a1, $zero, 0x3F0
    ctx->r5 = ADD32(0, 0X3F0);
    // 0x808019E4: jal         0x8009DB04
    // 0x808019E8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    func_8009DB04(rdram, ctx);
        goto after_2;
    // 0x808019E8: addiu       $a3, $zero, 0x2710
    ctx->r7 = ADD32(0, 0X2710);
    after_2:
    // 0x808019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019F0: jal         0x800A2EEC
    // 0x808019F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800A2EEC(rdram, ctx);
        goto after_3;
    // 0x808019F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808019F8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808019FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801A08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801A0C: jal         0x8009FFD8
    // 0x80801A10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80801A10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80801A14: jal         0x8009EF04
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_5;
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801A1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801A20: nop

    // 0x80801A24: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80801A28: nop

    // 0x80801A2C: bc1t        L_80801A48
    if (c1cs) {
        // 0x80801A30: nop
    
            goto L_80801A48;
    }
    // 0x80801A30: nop

    // 0x80801A34: jal         0x8009EEB8
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_6;
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801A3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801A40: jal         0x8009C914
    // 0x80801A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80801A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80801A48:
    // 0x80801A48: jal         0x8009C990
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801A50: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801A54: jal         0x8009B9C0
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801A5C: jal         0x80800164
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bstnt(rdram, ctx);
        goto after_10;
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801A64: jal         0x8009C990
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_11;
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801A6C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801A70: jal         0x8009BB00
    // 0x80801A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80801A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801A78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A80: jal         0x8009BA68
    // 0x80801A84: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80801A84: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80801A88: jal         0x8009BB00
    // 0x80801A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80801A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801A90: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801A94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801A98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X2228) << 16);
    // 0x80801A9C: lwc1        $f6, 0x2228($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X2228));
    // 0x80801AA0: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x80801AA4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801AA8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801AAC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801AB0: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80801AB4: jal         0x800F10B4
    // 0x80801AB8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80801AB8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80801ABC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801AC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(404, 0X222C) << 16);
    // 0x80801AC8: lwc1        $f8, 0x222C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(404, 0X222C));
    // 0x80801ACC: lui         $a3, 0x43AD
    ctx->r7 = S32(0X43AD << 16);
    // 0x80801AD0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801AD4: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    // 0x80801AD8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801ADC: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80801AE0: jal         0x800F10B4
    // 0x80801AE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80801AE4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80801AE8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80801AEC: jal         0x8008AF24
    // 0x80801AF0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_reset(rdram, ctx);
        goto after_17;
    // 0x80801AF0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x80801AF4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801AF8: jal         0x8008AED4
    // 0x80801AFC: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    anctrl_setIndex(rdram, ctx);
        goto after_18;
    // 0x80801AFC: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    after_18:
    // 0x80801B00: lui         $a2, 0x3ECD
    ctx->r6 = S32(0X3ECD << 16);
    // 0x80801B04: ori         $a2, $a2, 0x35A8
    ctx->r6 = ctx->r6 | 0X35A8;
    // 0x80801B08: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B0C: jal         0x8008B1D4
    // 0x80801B10: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_19;
    // 0x80801B10: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_19:
    // 0x80801B14: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B18: jal         0x8008B1BC
    // 0x80801B1C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_20;
    // 0x80801B1C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x80801B20: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80801B24: jal         0x8008B134
    // 0x80801B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_21;
    // 0x80801B28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80801B2C: jal         0x8008B064
    // 0x80801B30: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_start(rdram, ctx);
        goto after_22;
    // 0x80801B30: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_22:
    // 0x80801B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B38: jal         0x8009BA58
    // 0x80801B3C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_23;
    // 0x80801B3C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_23:
    // 0x80801B40: b           L_80801BFC
    // 0x80801B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801BFC;
    // 0x80801B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801B48:
    // 0x80801B48: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80801B4C: ori         $a1, $a1, 0xA7F0
    ctx->r5 = ctx->r5 | 0XA7F0;
    // 0x80801B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B54: jal         0x8008CF1C
    // 0x80801B58: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_24;
    // 0x80801B58: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_24:
    // 0x80801B5C: b           L_80801BFC
    // 0x80801B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801BFC;
    // 0x80801B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801B64:
    // 0x80801B64: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x80801B68: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80801B6C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801B70: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80801B74: jal         0x8008CF1C
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_25;
    // 0x80801B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80801B7C: b           L_80801BFC
    // 0x80801B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801BFC;
    // 0x80801B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801B84:
    // 0x80801B84: jal         0x8009BB5C
    // 0x80801B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_26;
    // 0x80801B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801B8C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801B90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801B9C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801BA0: jal         0x8009D2D8
    // 0x80801BA4: swc1        $f16, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f16.u32l;
    func_8009D2D8(rdram, ctx);
        goto after_27;
    // 0x80801BA4: swc1        $f16, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f16.u32l;
    after_27:
    // 0x80801BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BAC: jal         0x8009B9B0
    // 0x80801BB0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x80801BB0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_28:
    // 0x80801BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BB8: jal         0x800A2FCC
    // 0x80801BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A2FCC(rdram, ctx);
        goto after_29;
    // 0x80801BBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80801BC0: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x80801BC4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80801BC8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801BCC: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80801BD0: jal         0x8008CF1C
    // 0x80801BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEndAndDuration(rdram, ctx);
        goto after_30;
    // 0x80801BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80801BD8: b           L_80801BFC
    // 0x80801BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801BFC;
    // 0x80801BDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801BE0:
    // 0x80801BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BE4: jal         0x8009BF5C
    // 0x80801BE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_31;
    // 0x80801BE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_31:
    // 0x80801BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BF0: jal         0x8009C4CC
    // 0x80801BF4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_32;
    // 0x80801BF4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_32:
L_80801BF8:
    // 0x80801BF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801BFC:
    // 0x80801BFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801C04: jr          $ra
    // 0x80801C08: nop

    return;
    // 0x80801C08: nop

;}
RECOMP_FUNC void func_80800834_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080083C: jal         0x8080064C
    // 0x80800840: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800840: nop

    after_0:
    // 0x80800844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080084C: jr          $ra
    // 0x80800850: nop

    return;
    // 0x80800850: nop

;}
RECOMP_FUNC void func_808017C8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017D0: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x808017D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808017D8: beq         $a2, $zero, L_808017EC
    if (ctx->r6 == 0) {
        // 0x808017DC: sb          $a1, 0x1($a0)
        MEM_B(0X1, ctx->r4) = ctx->r5;
            goto L_808017EC;
    }
    // 0x808017DC: sb          $a1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r5;
    // 0x808017E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808017E4: bne         $a2, $at, L_808017F8
    if (ctx->r6 != ctx->r1) {
        // 0x808017E8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808017F8;
    }
    // 0x808017E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_808017EC:
    // 0x808017EC: sb          $zero, 0x1F($a3)
    MEM_B(0X1F, ctx->r7) = 0;
    // 0x808017F0: b           L_80801834
    // 0x808017F4: sb          $zero, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = 0;
        goto L_80801834;
    // 0x808017F4: sb          $zero, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = 0;
L_808017F8:
    // 0x808017F8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808017FC: jal         0x80801718
    // 0x80801800: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80801718_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80801800: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80801804: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080180C: lbu         $a0, 0x1($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X1);
    // 0x80801810: xor         $t7, $v0, $a0
    ctx->r15 = ctx->r2 ^ ctx->r4;
    // 0x80801814: sltu        $t7, $zero, $t7
    ctx->r15 = 0 < ctx->r15 ? 1 : 0;
    // 0x80801818: jal         0x80801718
    // 0x8080181C: sb          $t7, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = ctx->r15;
    func_80801718_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x8080181C: sb          $t7, 0x1E($a3)
    MEM_B(0X1E, ctx->r7) = ctx->r15;
    after_1:
    // 0x80801820: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801824: lbu         $t8, 0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1);
    // 0x80801828: xor         $t9, $v0, $t8
    ctx->r25 = ctx->r2 ^ ctx->r24;
    // 0x8080182C: sltu        $t9, $zero, $t9
    ctx->r25 = 0 < ctx->r25 ? 1 : 0;
    // 0x80801830: sb          $t9, 0x1F($a3)
    MEM_B(0X1F, ctx->r7) = ctx->r25;
L_80801834:
    // 0x80801834: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080183C: jr          $ra
    // 0x80801840: nop

    return;
    // 0x80801840: nop

;}
RECOMP_FUNC void func_80800CD4_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800CD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CDC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800CE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800CE4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800CE8: addiu       $a0, $zero, 0x480
    ctx->r4 = ADD32(0, 0X480);
    // 0x80800CEC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800CF0: jal         0x80089C40
    // 0x80800CF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800CF4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80800CF8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80800CFC: bltz        $v1, L_80800D48
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800D00: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_80800D48;
    }
    // 0x80800D00: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80800D04: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80800D08: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80800D0C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800D10: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x80800D14: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80800D18:
    // 0x80800D18: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x80800D1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D20: jal         0x8010114C
    // 0x80800D24: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80800D24: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x80800D28: beq         $v0, $zero, L_80800D3C
    if (ctx->r2 == 0) {
        // 0x80800D2C: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_80800D3C;
    }
    // 0x80800D2C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x80800D30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800D34: b           L_80800D48
    // 0x80800D38: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
        goto L_80800D48;
    // 0x80800D38: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_80800D3C:
    // 0x80800D3C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800D40: beql        $at, $zero, L_80800D18
    if (ctx->r1 == 0) {
        // 0x80800D44: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80800D18;
    }
    goto skip_0;
    // 0x80800D44: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_0:
L_80800D48:
    // 0x80800D48: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800D4C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800D50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800D54: beq         $t0, $zero, L_80800D6C
    if (ctx->r8 == 0) {
        // 0x80800D58: nop
    
            goto L_80800D6C;
    }
    // 0x80800D58: nop

    // 0x80800D5C: jal         0x80800270
    // 0x80800D60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800270_chrainbow(rdram, ctx);
        goto after_2;
    // 0x80800D60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800D64: b           L_80800D78
    // 0x80800D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D78;
    // 0x80800D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D6C:
    // 0x80800D6C: jal         0x80800270
    // 0x80800D70: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800270_chrainbow(rdram, ctx);
        goto after_3;
    // 0x80800D70: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
    // 0x80800D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D78:
    // 0x80800D78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D80: jr          $ra
    // 0x80800D84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800D84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _baduo_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084958: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084958);
    return;
    // 0x8008495C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _vplight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FF0: syscall     755
    recomp_syscall_handler(rdram, ctx, 0x80088FF0);
    return;
    // 0x80088FF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801C9C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801CA0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801CA4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801CA8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801CAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801CB0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801CB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801CB8: jal         0x80100094
    // 0x80801CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CC0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80801CC4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801CC8: addiu       $s0, $v0, 0x568
    ctx->r16 = ADD32(ctx->r2, 0X568);
    // 0x80801CCC: addiu       $s4, $zero, 0x150
    ctx->r20 = ADD32(0, 0X150);
L_80801CD0:
    // 0x80801CD0: lw          $t6, 0x568($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X568);
    // 0x80801CD4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80801CD8: beql        $t6, $zero, L_80801D14
    if (ctx->r14 == 0) {
        // 0x80801CDC: addiu       $s3, $s3, 0x54
        ctx->r19 = ADD32(ctx->r19, 0X54);
            goto L_80801D14;
    }
    goto skip_0;
    // 0x80801CDC: addiu       $s3, $s3, 0x54
    ctx->r19 = ADD32(ctx->r19, 0X54);
    skip_0:
    // 0x80801CE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80801CE4:
    // 0x80801CE4: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    // 0x80801CE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801CEC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80801CF0: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80801CF4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80801CF8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80801CFC: jal         0x8010114C
    // 0x80801D00: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80801D00: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x80801D04: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80801D08: bnel        $t9, $zero, L_80801CE4
    if (ctx->r25 != 0) {
        // 0x80801D0C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80801CE4;
    }
    goto skip_1;
    // 0x80801D0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80801D10: addiu       $s3, $s3, 0x54
    ctx->r19 = ADD32(ctx->r19, 0X54);
L_80801D14:
    // 0x80801D14: addiu       $s2, $s2, 0x54
    ctx->r18 = ADD32(ctx->r18, 0X54);
    // 0x80801D18: bne         $s3, $s4, L_80801CD0
    if (ctx->r19 != ctx->r20) {
        // 0x80801D1C: addiu       $s0, $s0, 0x54
        ctx->r16 = ADD32(ctx->r16, 0X54);
            goto L_80801CD0;
    }
    // 0x80801D1C: addiu       $s0, $s0, 0x54
    ctx->r16 = ADD32(ctx->r16, 0X54);
    // 0x80801D20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801D24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D28: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801D30: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801D34: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801D38: jr          $ra
    // 0x80801D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801D3C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808000CC_chblink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x808000D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000D4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808000D8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808000DC: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x808000E0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x808000E4: swc1        $f12, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f12.u32l;
    // 0x808000E8: bc1tl       L_8080010C
    if (c1cs) {
        // 0x808000EC: lwc1        $f18, 0x8($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000EC: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x808000F0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808000F4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000F8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808000FC: div.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80800100: jr          $ra
    // 0x80800104: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x80800104: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x80800108: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
L_8080010C:
    // 0x8080010C: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_80801744_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801748: slti        $at, $a1, 0xCEC
    ctx->r1 = SIGNED(ctx->r5) < 0XCEC ? 1 : 0;
    // 0x8080174C: bne         $at, $zero, L_80801778
    if (ctx->r1 != 0) {
        // 0x80801750: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801778;
    }
    // 0x80801750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801754: addiu       $t6, $a1, -0x1622
    ctx->r14 = ADD32(ctx->r5, -0X1622);
    // 0x80801758: sltiu       $at, $t6, 0x16
    ctx->r1 = ctx->r14 < 0X16 ? 1 : 0;
    // 0x8080175C: beq         $at, $zero, L_80801830
    if (ctx->r1 == 0) {
        // 0x80801760: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801830;
    }
    // 0x80801760: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801764: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1240, 0X378C) << 16);
    // 0x80801768: addu        $at, $at, $t6
    gpr jr_addend_80801770 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080176C: lw          $t6, 0x378C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1240, 0X378C));
    // 0x80801770: jr          $t6
    // 0x80801774: nop

    switch (jr_addend_80801770 >> 2) {
        case 0: goto L_8080178C; break;
        case 1: goto L_8080178C; break;
        case 2: goto L_80801838; break;
        case 3: goto L_80801838; break;
        case 4: goto L_80801838; break;
        case 5: goto L_8080179C; break;
        case 6: goto L_8080178C; break;
        case 7: goto L_8080178C; break;
        case 8: goto L_8080179C; break;
        case 9: goto L_8080178C; break;
        case 10: goto L_8080178C; break;
        case 11: goto L_8080179C; break;
        case 12: goto L_80801830; break;
        case 13: goto L_808017AC; break;
        case 14: goto L_80801838; break;
        case 15: goto L_80801838; break;
        case 16: goto L_80801838; break;
        case 17: goto L_808017C8; break;
        case 18: goto L_808017F8; break;
        case 19: goto L_80801838; break;
        case 20: goto L_80801838; break;
        case 21: goto L_80801838; break;
        default: switch_error(__func__, 0x80801770, 0x8080378C);
    }
    // 0x80801774: nop

L_80801778:
    // 0x80801778: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x8080177C: beq         $a1, $at, L_80801808
    if (ctx->r5 == ctx->r1) {
        // 0x80801780: nop
    
            goto L_80801808;
    }
    // 0x80801780: nop

    // 0x80801784: b           L_80801830
    // 0x80801788: nop

        goto L_80801830;
    // 0x80801788: nop

L_8080178C:
    // 0x8080178C: jal         0x80801964
    // 0x80801790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801964_chklungo(rdram, ctx);
        goto after_0;
    // 0x80801790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80801794: b           L_8080183C
    // 0x80801798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x80801798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080179C:
    // 0x8080179C: jal         0x80801964
    // 0x808017A0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_80801964_chklungo(rdram, ctx);
        goto after_1;
    // 0x808017A0: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_1:
    // 0x808017A4: b           L_8080183C
    // 0x808017A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x808017A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017AC:
    // 0x808017AC: jal         0x80802558
    // 0x808017B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802558_chklungo(rdram, ctx);
        goto after_2;
    // 0x808017B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808017B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017B8: jal         0x80801964
    // 0x808017BC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801964_chklungo(rdram, ctx);
        goto after_3;
    // 0x808017BC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_3:
    // 0x808017C0: b           L_8080183C
    // 0x808017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x808017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017C8:
    // 0x808017C8: addiu       $a1, $zero, 0x1634
    ctx->r5 = ADD32(0, 0X1634);
    // 0x808017CC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808017D0: jal         0x80803158
    // 0x808017D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80803158_chklungo(rdram, ctx);
        goto after_4;
    // 0x808017D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x808017D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017DC: jal         0x808025CC
    // 0x808017E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808025CC_chklungo(rdram, ctx);
        goto after_5;
    // 0x808017E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808017E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017E8: jal         0x80801964
    // 0x808017EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801964_chklungo(rdram, ctx);
        goto after_6;
    // 0x808017EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808017F0: b           L_8080183C
    // 0x808017F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x808017F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017F8:
    // 0x808017F8: jal         0x80801964
    // 0x808017FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801964_chklungo(rdram, ctx);
        goto after_7;
    // 0x808017FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_7:
    // 0x80801800: b           L_8080183C
    // 0x80801804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x80801804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801808:
    // 0x80801808: blez        $a2, L_80801820
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8080180C: nop
    
            goto L_80801820;
    }
    // 0x8080180C: nop

    // 0x80801810: jal         0x80088188
    // 0x80801814: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80801814: nop

    after_8:
    // 0x80801818: b           L_8080183C
    // 0x8080181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x8080181C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801820:
    // 0x80801820: jal         0x80088180
    // 0x80801824: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x80801824: nop

    after_9:
    // 0x80801828: b           L_8080183C
    // 0x8080182C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080183C;
    // 0x8080182C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801830:
    // 0x80801830: jal         0x80801964
    // 0x80801834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801964_chklungo(rdram, ctx);
        goto after_10;
    // 0x80801834: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80801838:
    // 0x80801838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080183C:
    // 0x8080183C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801840: jr          $ra
    // 0x80801844: nop

    return;
    // 0x80801844: nop

;}
RECOMP_FUNC void func_80801080_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801088: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X126C) << 16);
    // 0x8080108C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1112, 0X1438) << 16);
    // 0x80801090: addiu       $a3, $a3, 0x1438
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1112, 0X1438));
    // 0x80801094: addiu       $a2, $a2, 0x126C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X126C));
    // 0x80801098: jal         0x80089D28
    // 0x8080109C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080109C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808010A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010A8: jr          $ra
    // 0x808010AC: nop

    return;
    // 0x808010AC: nop

;}
RECOMP_FUNC void func_800C5BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5BC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5BCC: jal         0x8001BAFC
    // 0x800C5BD0: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800C5BD0: nop

    after_0:
    // 0x800C5BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5BDC: jr          $ra
    // 0x800C5BE0: nop

    return;
    // 0x800C5BE0: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EA8: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089EA8);
    return;
    // 0x80089EAC: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80800E0C_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800E18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800E1C: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
    // 0x80800E20: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80800E24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E28: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x80800E2C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800E30: bne         $t7, $t8, L_80800F98
    if (ctx->r15 != ctx->r24) {
        // 0x80800E34: nop
    
            goto L_80800F98;
    }
    // 0x80800E34: nop

    // 0x80800E38: jal         0x80106790
    // 0x80800E3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800E3C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800E40: lw          $t9, 0x78($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X78);
    // 0x80800E44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800E48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1294) << 16);
    // 0x80800E4C: sll         $t1, $t9, 29
    ctx->r9 = S32(ctx->r25 << 29);
    // 0x80800E50: bltzl       $t1, L_80800FA4
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800E54: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800FA4;
    }
    goto skip_0;
    // 0x80800E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800E58: lwc1        $f4, 0x1294($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1294));
    // 0x80800E5C: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80800E60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800E64: nop

    // 0x80800E68: bc1fl       L_80800FA4
    if (!c1cs) {
        // 0x80800E6C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800FA4;
    }
    goto skip_1;
    // 0x80800E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800E70: lhu         $t2, 0x72($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X72);
    // 0x80800E74: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800E78: addiu       $t4, $t3, -0x2
    ctx->r12 = ADD32(ctx->r11, -0X2);
    // 0x80800E7C: sltiu       $at, $t4, 0x6
    ctx->r1 = ctx->r12 < 0X6 ? 1 : 0;
    // 0x80800E80: beq         $at, $zero, L_80800FA0
    if (ctx->r1 == 0) {
        // 0x80800E84: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80800FA0;
    }
    // 0x80800E84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800E88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X1298) << 16);
    // 0x80800E8C: addu        $at, $at, $t4
    gpr jr_addend_80800E94 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800E90: lw          $t4, 0x1298($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2332, 0X1298));
    // 0x80800E94: jr          $t4
    // 0x80800E98: nop

    switch (jr_addend_80800E94 >> 2) {
        case 0: goto L_80800E9C; break;
        case 1: goto L_80800E9C; break;
        case 2: goto L_80800ED8; break;
        case 3: goto L_80800ED8; break;
        case 4: goto L_80800F38; break;
        case 5: goto L_80800F38; break;
        default: switch_error(__func__, 0x80800E94, 0x80801298);
    }
    // 0x80800E98: nop

L_80800E9C:
    // 0x80800E9C: jal         0x80101F24
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_1;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800EA4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800EA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800EAC: nop

    // 0x80800EB0: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800EB4: jal         0x80013970
    // 0x80800EB8: nop

    func_80013970(rdram, ctx);
        goto after_2;
    // 0x80800EB8: nop

    after_2:
    // 0x80800EBC: lwc1        $f2, 0x38($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800EC0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80800EC4: sb          $t5, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r13;
    // 0x80800EC8: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800ECC: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80800ED0: b           L_80800F88
    // 0x80800ED4: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
        goto L_80800F88;
    // 0x80800ED4: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
L_80800ED8:
    // 0x80800ED8: jal         0x80101F24
    // 0x80800EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101F24(rdram, ctx);
        goto after_3;
    // 0x80800EDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800EE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2332, 0X12B0) << 16);
    // 0x80800EE4: lwc1        $f18, 0x12B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2332, 0X12B0));
    // 0x80800EE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800EEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800EF0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800EF4: nop

    // 0x80800EF8: bc1fl       L_80800F30
    if (!c1cs) {
        // 0x80800EFC: addiu       $t6, $zero, 0xFF
        ctx->r14 = ADD32(0, 0XFF);
            goto L_80800F30;
    }
    goto skip_2;
    // 0x80800EFC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    skip_2:
    // 0x80800F00: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F04: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800F08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800F10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F14: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800F18: jal         0x800F10B4
    // 0x80800F1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800F1C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800F20: lwc1        $f6, 0x38($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800F24: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800F28: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x80800F2C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
L_80800F30:
    // 0x80800F30: b           L_80800F88
    // 0x80800F34: sb          $t6, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r14;
        goto L_80800F88;
    // 0x80800F34: sb          $t6, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r14;
L_80800F38:
    // 0x80800F38: lbu         $t7, 0x9B($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X9B);
    // 0x80800F3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800F40: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80800F44: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80800F48: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800F4C: bgez        $t7, L_80800F64
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800F50: cvt.s.w     $f12, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800F64;
    }
    // 0x80800F50: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800F54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800F58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800F5C: nop

    // 0x80800F60: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
L_80800F64:
    // 0x80800F64: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800F68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F6C: jal         0x800F10B4
    // 0x80800F70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800F70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80800F74: lwc1        $f18, 0x38($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800F78: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800F7C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80800F80: lbu         $t8, 0x9B($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X9B);
    // 0x80800F84: sb          $t8, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r24;
L_80800F88:
    // 0x80800F88: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F8C: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80800F90: b           L_80800FA0
    // 0x80800F94: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800FA0;
    // 0x80800F94: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80800F98:
    // 0x80800F98: jal         0x800FFA88
    // 0x80800F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_6;
    // 0x80800F9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
L_80800FA0:
    // 0x80800FA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FA4:
    // 0x80800FA4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FA8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800FAC: jr          $ra
    // 0x80800FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _baflameline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B90: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B90);
    return;
    // 0x80084B94: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800A7C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A84: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800A88: jal         0x80100094
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A90: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80800A94: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x80800A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A9C: jal         0x800D0A9C
    // 0x80800AA0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80800AA0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800AA4: jal         0x800D395C
    // 0x80800AA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x80800AA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800AAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AB0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80800AB4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800AB8: jal         0x800D2054
    // 0x80800ABC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x80800ABC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800AC0: xori        $v1, $v0, 0x1
    ctx->r3 = ctx->r2 ^ 0X1;
    // 0x80800AC4: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800AC8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800ACC: beq         $a1, $zero, L_80800AE8
    if (ctx->r5 == 0) {
        // 0x80800AD0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80800AE8;
    }
    // 0x80800AD0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800AD8: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800ADC: bnel        $a1, $zero, L_80800AEC
    if (ctx->r5 != 0) {
        // 0x80800AE0: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80800AEC;
    }
    goto skip_0;
    // 0x80800AE0: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800AE4: sltu        $a1, $zero, $a3
    ctx->r5 = 0 < ctx->r7 ? 1 : 0;
L_80800AE8:
    // 0x80800AE8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80800AEC:
    // 0x80800AEC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800AF4: slti        $t8, $v0, 0x32
    ctx->r24 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x80800AF8: xori        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 ^ 0X1;
    // 0x80800AFC: sltu        $a1, $zero, $t8
    ctx->r5 = 0 < ctx->r24 ? 1 : 0;
    // 0x80800B00: beq         $a1, $zero, L_80800B18
    if (ctx->r5 == 0) {
        // 0x80800B04: lw          $v0, 0x24($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X24);
            goto L_80800B18;
    }
    // 0x80800B04: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800B08: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800B0C: beql        $a1, $zero, L_80800B1C
    if (ctx->r5 == 0) {
        // 0x80800B10: sw          $a1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r5;
            goto L_80800B1C;
    }
    goto skip_1;
    // 0x80800B10: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    skip_1:
    // 0x80800B14: sltiu       $a1, $a3, 0x1
    ctx->r5 = ctx->r7 < 0X1 ? 1 : 0;
L_80800B18:
    // 0x80800B18: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
L_80800B1C:
    // 0x80800B1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x80800B20: jal         0x800FDC28
    // 0x80800B24: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FDC28(rdram, ctx);
        goto after_4;
    // 0x80800B24: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800B28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800B2C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800B30: bne         $a1, $zero, L_80800B40
    if (ctx->r5 != 0) {
        // 0x80800B34: nop
    
            goto L_80800B40;
    }
    // 0x80800B34: nop

    // 0x80800B38: beq         $v1, $zero, L_80800B48
    if (ctx->r3 == 0) {
        // 0x80800B3C: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80800B48;
    }
    // 0x80800B3C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
L_80800B40:
    // 0x80800B40: b           L_80800B48
    // 0x80800B44: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_80800B48;
    // 0x80800B44: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_80800B48:
    // 0x80800B48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800B4C: jal         0x800FC6B0
    // 0x80800B50: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_800FC6B0(rdram, ctx);
        goto after_5;
    // 0x80800B50: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_5:
    // 0x80800B54: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800B58: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800B5C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800B60: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80800B64: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80800B68: beq         $t3, $zero, L_80800B78
    if (ctx->r11 == 0) {
        // 0x80800B6C: nop
    
            goto L_80800B78;
    }
    // 0x80800B6C: nop

    // 0x80800B70: b           L_80800BD4
    // 0x80800B74: addiu       $v1, $zero, 0x10D2
    ctx->r3 = ADD32(0, 0X10D2);
        goto L_80800BD4;
    // 0x80800B74: addiu       $v1, $zero, 0x10D2
    ctx->r3 = ADD32(0, 0X10D2);
L_80800B78:
    // 0x80800B78: beq         $v1, $zero, L_80800B88
    if (ctx->r3 == 0) {
        // 0x80800B7C: nop
    
            goto L_80800B88;
    }
    // 0x80800B7C: nop

    // 0x80800B80: b           L_80800BD4
    // 0x80800B84: addiu       $v1, $zero, 0x10C0
    ctx->r3 = ADD32(0, 0X10C0);
        goto L_80800BD4;
    // 0x80800B84: addiu       $v1, $zero, 0x10C0
    ctx->r3 = ADD32(0, 0X10C0);
L_80800B88:
    // 0x80800B88: jal         0x800D395C
    // 0x80800B8C: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x80800B8C: nop

    after_6:
    // 0x80800B90: bne         $v0, $zero, L_80800BC8
    if (ctx->r2 != 0) {
        // 0x80800B94: lw          $t7, 0x44($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X44);
            goto L_80800BC8;
    }
    // 0x80800B94: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800B98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80800B9C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BA0: beq         $t4, $zero, L_80800BC0
    if (ctx->r12 == 0) {
        // 0x80800BA4: nop
    
            goto L_80800BC0;
    }
    // 0x80800BA4: nop

    // 0x80800BA8: bne         $t5, $zero, L_80800BB8
    if (ctx->r13 != 0) {
        // 0x80800BAC: nop
    
            goto L_80800BB8;
    }
    // 0x80800BAC: nop

    // 0x80800BB0: b           L_80800BD4
    // 0x80800BB4: addiu       $v1, $zero, 0x10FA
    ctx->r3 = ADD32(0, 0X10FA);
        goto L_80800BD4;
    // 0x80800BB4: addiu       $v1, $zero, 0x10FA
    ctx->r3 = ADD32(0, 0X10FA);
L_80800BB8:
    // 0x80800BB8: b           L_80800BD4
    // 0x80800BBC: addiu       $v1, $zero, 0x10F9
    ctx->r3 = ADD32(0, 0X10F9);
        goto L_80800BD4;
    // 0x80800BBC: addiu       $v1, $zero, 0x10F9
    ctx->r3 = ADD32(0, 0X10F9);
L_80800BC0:
    // 0x80800BC0: b           L_80800BD4
    // 0x80800BC4: addiu       $v1, $zero, 0x10F8
    ctx->r3 = ADD32(0, 0X10F8);
        goto L_80800BD4;
    // 0x80800BC4: addiu       $v1, $zero, 0x10F8
    ctx->r3 = ADD32(0, 0X10F8);
L_80800BC8:
    // 0x80800BC8: addiu       $t6, $zero, 0x46
    ctx->r14 = ADD32(0, 0X46);
    // 0x80800BCC: addiu       $v1, $zero, 0xCEB
    ctx->r3 = ADD32(0, 0XCEB);
    // 0x80800BD0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_80800BD4:
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800BDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800BE0: jr          $ra
    // 0x80800BE4: nop

    return;
    // 0x80800BE4: nop

;}
RECOMP_FUNC void func_808001A8_ncpodfixpos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B4: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x808001B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001BC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x808001C0: beq         $t6, $zero, L_80800264
    if (ctx->r14 == 0) {
        // 0x808001C4: andi        $t1, $v0, 0x40
        ctx->r9 = ctx->r2 & 0X40;
            goto L_80800264;
    }
    // 0x808001C4: andi        $t1, $v0, 0x40
    ctx->r9 = ctx->r2 & 0X40;
    // 0x808001C8: lw          $a0, 0x18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X18);
    // 0x808001CC: jal         0x80800000
    // 0x808001D0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    func_80800000_ncpodfixpos(rdram, ctx);
        goto after_0;
    // 0x808001D0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_0:
    // 0x808001D4: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x808001D8: nop
    
            goto L_8080025C;
    }
    // 0x808001D8: nop

    // 0x808001DC: jal         0x80106790
    // 0x808001E0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808001E0: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_1:
    // 0x808001E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001E8: jal         0x80103DFC
    // 0x808001EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80103DFC(rdram, ctx);
        goto after_2;
    // 0x808001EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x808001F0: lh          $t7, 0x2C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2C);
    // 0x808001F4: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x808001F8: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x808001FC: beq         $t8, $zero, L_8080024C
    if (ctx->r24 == 0) {
        // 0x80800200: nop
    
            goto L_8080024C;
    }
    // 0x80800200: nop

    // 0x80800204: lbu         $t9, 0x42($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X42);
    // 0x80800208: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8080020C: addiu       $a2, $s0, 0x20
    ctx->r6 = ADD32(ctx->r16, 0X20);
    // 0x80800210: beq         $t9, $zero, L_8080024C
    if (ctx->r25 == 0) {
        // 0x80800214: nop
    
            goto L_8080024C;
    }
    // 0x80800214: nop

    // 0x80800218: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080021C: jal         0x800EFB24
    // 0x80800220: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800220: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800224: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800228: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080022C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800230: jal         0x800EF334
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800238: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080023C: jal         0x800EF04C
    // 0x80800240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800240: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800244: b           L_80800320
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x80800248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: jal         0x800EE7F8
    // 0x80800250: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800250: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_6:
    // 0x80800254: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800258: sb          $t0, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r8;
L_8080025C:
    // 0x8080025C: b           L_80800320
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x80800260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800264:
    // 0x80800264: beq         $t1, $zero, L_80800310
    if (ctx->r9 == 0) {
        // 0x80800268: andi        $t6, $v0, 0x80
        ctx->r14 = ctx->r2 & 0X80;
            goto L_80800310;
    }
    // 0x80800268: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8080026C: jal         0x800F54E4
    // 0x80800270: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800270: nop

    after_7:
    // 0x80800274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800278: jal         0x800F5BC4
    // 0x8080027C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5BC4(rdram, ctx);
        goto after_8;
    // 0x8080027C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x80800280: jal         0x800F54E4
    // 0x80800284: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800284: nop

    after_9:
    // 0x80800288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080028C: jal         0x800F5A00
    // 0x80800290: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F5A00(rdram, ctx);
        goto after_10;
    // 0x80800290: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_10:
    // 0x80800294: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800298: jal         0x800EF04C
    // 0x8080029C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x8080029C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_11:
    // 0x808002A0: lh          $t2, 0x2C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2C);
    // 0x808002A4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808002A8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x808002AC: andi        $t3, $t2, 0x400
    ctx->r11 = ctx->r10 & 0X400;
    // 0x808002B0: beq         $t3, $zero, L_80800300
    if (ctx->r11 == 0) {
        // 0x808002B4: addiu       $a1, $sp, 0x54
        ctx->r5 = ADD32(ctx->r29, 0X54);
            goto L_80800300;
    }
    // 0x808002B4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808002B8: lbu         $t4, 0x42($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X42);
    // 0x808002BC: addiu       $a2, $s0, 0x20
    ctx->r6 = ADD32(ctx->r16, 0X20);
    // 0x808002C0: beq         $t4, $zero, L_80800300
    if (ctx->r12 == 0) {
        // 0x808002C4: nop
    
            goto L_80800300;
    }
    // 0x808002C4: nop

    // 0x808002C8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808002CC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808002D0: jal         0x800EFB24
    // 0x808002D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x808002D4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_12:
    // 0x808002D8: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x808002DC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808002E0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808002E4: jal         0x800EF334
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_13;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002F0: jal         0x800EF04C
    // 0x808002F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x808002F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x808002F8: b           L_80800320
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x808002FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800300:
    // 0x80800300: jal         0x800EE7F8
    // 0x80800304: sb          $t5, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r13;
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800304: sb          $t5, 0x42($s0)
    MEM_B(0X42, ctx->r16) = ctx->r13;
    after_15:
    // 0x80800308: b           L_80800320
    // 0x8080030C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x8080030C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800310:
    // 0x80800310: beq         $t6, $zero, L_80800320
    if (ctx->r14 == 0) {
        // 0x80800314: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800320;
    }
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800318: b           L_80800320
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800320:
    // 0x80800320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800324: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080032C: jr          $ra
    // 0x80800330: nop

    return;
    // 0x80800330: nop

;}
RECOMP_FUNC void func_80800118_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080011C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: jal         0x80100094
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800130: jal         0x800D8FF8
    // 0x80800134: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800134: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800138: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080013C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800140: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800144: bltzl       $t8, L_808001E8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800148: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001E8;
    }
    goto skip_0;
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080014C: jal         0x800DA298
    // 0x80800150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800154: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x80800158: nop
    
            goto L_8080016C;
    }
    // 0x80800158: nop

    // 0x8080015C: jal         0x80800294
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800294_chballoonbomb(rdram, ctx);
        goto after_3;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800164: b           L_808001E8
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001E8;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: jal         0x800DA298
    // 0x80800170: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_4:
    // 0x80800174: bnel        $v0, $zero, L_808001E8
    if (ctx->r2 != 0) {
        // 0x80800178: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001E8;
    }
    goto skip_1;
    // 0x80800178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080017C: jal         0x8008FF18
    // 0x80800180: nop

    func_8008FF18(rdram, ctx);
        goto after_5;
    // 0x80800180: nop

    after_5:
    // 0x80800184: bne         $v0, $zero, L_808001E4
    if (ctx->r2 != 0) {
        // 0x80800188: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_808001E4;
    }
    // 0x80800188: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080018C: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800190: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800194: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800198: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080019C: jal         0x800136E4
    // 0x808001A0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x808001A0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_6:
    // 0x808001A4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808001A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x80800230
    // 0x808001B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800230_chballoonbomb(rdram, ctx);
        goto after_7;
    // 0x808001B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808001B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(836, 0X4A0) << 16);
    // 0x808001BC: lwc1        $f14, 0x4A0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(836, 0X4A0));
    // 0x808001C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808001C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001C8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808001CC: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808001D0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808001D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808001D8: jal         0x800F15F8
    // 0x808001DC: nop

    func_800F15F8(rdram, ctx);
        goto after_8;
    // 0x808001DC: nop

    after_8:
    // 0x808001E0: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_808001E4:
    // 0x808001E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001E8:
    // 0x808001E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_80800408_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080040C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800410: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80800414: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800418: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080041C: sll         $t7, $t6, 20
    ctx->r15 = S32(ctx->r14 << 20);
    // 0x80800420: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x80800424: beql        $t8, $zero, L_80800448
    if (ctx->r24 == 0) {
        // 0x80800428: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800448;
    }
    goto skip_0;
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080042C: jal         0x800856B8
    // 0x80800430: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800430: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800434: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800438: lbu         $t9, 0x7A($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7A);
    // 0x8080043C: andi        $t0, $t9, 0xFFF1
    ctx->r8 = ctx->r25 & 0XFFF1;
    // 0x80800440: sb          $t0, 0x7A($a1)
    MEM_B(0X7A, ctx->r5) = ctx->r8;
    // 0x80800444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800448:
    // 0x80800448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080044C: jr          $ra
    // 0x80800450: nop

    return;
    // 0x80800450: nop

;}
RECOMP_FUNC void func_80102EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102ED0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102ED4: lw          $v1, 0x70($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X70);
    // 0x80102ED8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80102EDC: srl         $a3, $v1, 25
    ctx->r7 = S32(U32(ctx->r3) >> 25);
    // 0x80102EE0: sltiu       $v0, $a3, 0x1
    ctx->r2 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x80102EE4: bne         $v0, $zero, L_80102F04
    if (ctx->r2 != 0) {
        // 0x80102EE8: addiu       $a1, $a3, -0x1
        ctx->r5 = ADD32(ctx->r7, -0X1);
            goto L_80102F04;
    }
    // 0x80102EE8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // 0x80102EEC: sll         $a2, $v1, 22
    ctx->r6 = S32(ctx->r3 << 22);
    // 0x80102EF0: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x80102EF4: jal         0x800CC338
    // 0x80102EF8: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x80102EF8: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x80102EFC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80102F00: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_80102F04:
    // 0x80102F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102F08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102F0C: jr          $ra
    // 0x80102F10: nop

    return;
    // 0x80102F10: nop

;}
RECOMP_FUNC void bstnt_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808020DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X25BC) << 16);
    // 0x808020E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808020E4: jr          $ra
    // 0x808020E8: lw          $v0, 0x25BC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25BC));
    return;
    // 0x808020E8: lw          $v0, 0x25BC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25BC));
;}
RECOMP_FUNC void func_800E24A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E24A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E24AC: jr          $ra
    // 0x800E24B0: swc1        $f12, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800E24B0: swc1        $f12, -0x2B5C($at)
    MEM_W(-0X2B5C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800F64_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F64: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800F68: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800F6C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800F70: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800F74: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800F78: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800F7C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800F80: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800F84: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800F88: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800F8C: lbu         $a1, 0x60($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X60);
    // 0x80800F90: lh          $a0, 0x58($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X58);
    // 0x80800F94: jal         0x80800CB8
    // 0x80800F98: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    func_80800CB8_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80800F98: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800F9C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800FA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800FA8: jal         0x80089E08
    // 0x80800FAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _suspline_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800FAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800FB4: jal         0x8001B668
    // 0x80800FB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x80800FB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800FBC: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80800FC0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80800FC4: jal         0x8001B798
    // 0x80800FC8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x80800FC8: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_3:
    // 0x80800FCC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800FD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800FD4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800FD8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800FDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800FE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FE4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800FE8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800FEC: jal         0x80089E10
    // 0x80800FF0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _suspline_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800FF0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_4:
    // 0x80800FF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800FF8: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
L_80800FFC:
    // 0x80800FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801000: jal         0x80089DC8
    // 0x80801004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80801004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80801008: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8080100C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801010: sll         $t0, $s0, 16
    ctx->r8 = S32(ctx->r16 << 16);
    // 0x80801014: sra         $s0, $t0, 16
    ctx->r16 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80801018: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8080101C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80801020: bne         $at, $zero, L_80800FFC
    if (ctx->r1 != 0) {
        // 0x80801024: sw          $v0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r2;
            goto L_80800FFC;
    }
    // 0x80801024: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80801028: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080102C: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
L_80801030:
    // 0x80801030: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801034: jal         0x80089DD0
    // 0x80801038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80801038: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8080103C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x80801040: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801044: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80801048: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8080104C: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80801050: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80801054: bne         $at, $zero, L_80801030
    if (ctx->r1 != 0) {
        // 0x80801058: sw          $v0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r2;
            goto L_80801030;
    }
    // 0x80801058: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8080105C: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x80801060: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801064: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801068: lh          $t7, 0x58($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X58);
    // 0x8080106C: beq         $t7, $at, L_80801144
    if (ctx->r15 == ctx->r1) {
        // 0x80801070: sh          $t7, 0x5E($sp)
        MEM_H(0X5E, ctx->r29) = ctx->r15;
            goto L_80801144;
    }
    // 0x80801070: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x80801074: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801078: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080107C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_80801080:
    // 0x80801080: jal         0x800A5800
    // 0x80801084: nop

    func_800A5800(rdram, ctx);
        goto after_7;
    // 0x80801084: nop

    after_7:
    // 0x80801088: jal         0x80085580
    // 0x8080108C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x8080108C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_8:
    // 0x80801090: jal         0x80085590
    // 0x80801094: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801094: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_9:
    // 0x80801098: jal         0x800855D0
    // 0x8080109C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    _cadbfunc_entrypoint_10(rdram, ctx);
        goto after_10;
    // 0x8080109C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_10:
    // 0x808010A0: jal         0x800855E0
    // 0x808010A4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _cadbfunc_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808010A4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_11:
    // 0x808010A8: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x808010AC: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    // 0x808010B0: jal         0x80085610
    // 0x808010B4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    _cadbfunc_entrypoint_18(rdram, ctx);
        goto after_12;
    // 0x808010B4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    after_12:
    // 0x808010B8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x808010BC: jal         0x80085668
    // 0x808010C0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _cadbfunc_entrypoint_29(rdram, ctx);
        goto after_13;
    // 0x808010C0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_13:
    // 0x808010C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808010CC: jal         0x80089D78
    // 0x808010D0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    _suspline_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x808010D0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_14:
    // 0x808010D4: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x808010D8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x808010DC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x808010E0: addiu       $t0, $t9, 0xC
    ctx->r8 = ADD32(ctx->r25, 0XC);
    // 0x808010E4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808010E8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x808010EC: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x808010F0: sw          $t0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r8;
    // 0x808010F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010F8: addiu       $t2, $t1, 0xC
    ctx->r10 = ADD32(ctx->r9, 0XC);
    // 0x808010FC: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80801100: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80801104: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80801108: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8080110C: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80801110: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    // 0x80801114: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x80801118: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8080111C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80801120: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x80801124: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80801128: jal         0x80085600
    // 0x8080112C: addiu       $a0, $sp, 0x5E
    ctx->r4 = ADD32(ctx->r29, 0X5E);
    _cadbfunc_entrypoint_16(rdram, ctx);
        goto after_15;
    // 0x8080112C: addiu       $a0, $sp, 0x5E
    ctx->r4 = ADD32(ctx->r29, 0X5E);
    after_15:
    // 0x80801130: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x80801134: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801138: bne         $a0, $at, L_80801080
    if (ctx->r4 != ctx->r1) {
        // 0x8080113C: nop
    
            goto L_80801080;
    }
    // 0x8080113C: nop

    // 0x80801140: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801144:
    // 0x80801144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801148: jal         0x80089DC8
    // 0x8080114C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_10(rdram, ctx);
        goto after_16;
    // 0x8080114C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80801150: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80801154: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801158: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x8080115C: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80801160: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x80801164: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80801168: bne         $at, $zero, L_80801144
    if (ctx->r1 != 0) {
        // 0x8080116C: sw          $v0, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r2;
            goto L_80801144;
    }
    // 0x8080116C: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80801170: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80801174:
    // 0x80801174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801178: jal         0x80089DD0
    // 0x8080117C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suspline_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x8080117C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_17:
    // 0x80801180: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80801184: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801188: sll         $t9, $s0, 16
    ctx->r25 = S32(ctx->r16 << 16);
    // 0x8080118C: sra         $s0, $t9, 16
    ctx->r16 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80801190: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80801194: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x80801198: bne         $at, $zero, L_80801174
    if (ctx->r1 != 0) {
        // 0x8080119C: sw          $v0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r2;
            goto L_80801174;
    }
    // 0x8080119C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x808011A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808011A4: jal         0x800F0EF0
    // 0x808011A8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    func_800F0EF0(rdram, ctx);
        goto after_18;
    // 0x808011A8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    after_18:
    // 0x808011AC: blez        $s4, L_8080124C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x808011B0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080124C;
    }
    // 0x808011B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808011B4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808011B8: nop

L_808011BC:
    // 0x808011BC: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x808011C0: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x808011C4: lwc1        $f4, 0x8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X8);
    // 0x808011C8: lwc1        $f20, 0x0($t1)
    ctx->f20.u32l = MEM_W(ctx->r9, 0X0);
    // 0x808011CC: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x808011D0: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x808011D4: jal         0x800EE7F8
    // 0x808011D8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x808011D8: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    after_19:
    // 0x808011DC: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x808011E0: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x808011E4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808011E8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x808011EC: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x808011F0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x808011F4: jal         0x800EF4E4
    // 0x808011F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_20;
    // 0x808011F8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_20:
    // 0x808011FC: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80801200: jal         0x800EF04C
    // 0x80801204: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_21;
    // 0x80801204: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_21:
    // 0x80801208: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8080120C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80801210: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80801214: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80801218: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080121C: sll         $t1, $s0, 16
    ctx->r9 = S32(ctx->r16 << 16);
    // 0x80801220: sra         $s0, $t1, 16
    ctx->r16 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80801224: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80801228: addiu       $t5, $t4, 0xC
    ctx->r13 = ADD32(ctx->r12, 0XC);
    // 0x8080122C: addiu       $t7, $t6, 0xC
    ctx->r15 = ADD32(ctx->r14, 0XC);
    // 0x80801230: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80801234: addiu       $t2, $t0, 0x4
    ctx->r10 = ADD32(ctx->r8, 0X4);
    // 0x80801238: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8080123C: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x80801240: sw          $t9, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r25;
    // 0x80801244: bne         $at, $zero, L_808011BC
    if (ctx->r1 != 0) {
        // 0x80801248: sw          $t2, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r10;
            goto L_808011BC;
    }
    // 0x80801248: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
L_8080124C:
    // 0x8080124C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801250: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801254: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801258: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8080125C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801260: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80801264: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80801268: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8080126C: jr          $ra
    // 0x80801270: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80801270: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800D965C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D965C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800D9660: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800D9664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D9668: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D966C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800D9670: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D9674: bc1fl       L_800D968C
    if (!c1cs) {
        // 0x800D9678: lwc1        $f0, 0x4($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
            goto L_800D968C;
    }
    goto skip_0;
    // 0x800D9678: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800D967C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D9680: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800D9684: nop

    // 0x800D9688: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
L_800D968C:
    // 0x800D968C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800D9690: lwc1        $f20, 0xC($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800D9694: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D9698: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D969C: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800D96A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D96A4: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800D96A8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D96AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D96B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D96B4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D96B8: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800D96BC: mul.s       $f18, $f2, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D96C0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x800D96C4: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800D96C8: nop

    // 0x800D96CC: mul.s       $f14, $f12, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800D96D0: nop

    // 0x800D96D4: mul.s       $f6, $f20, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800D96D8: nop

    // 0x800D96DC: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800D96E0: nop

    // 0x800D96E4: mul.s       $f10, $f20, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f14.fl);
    // 0x800D96E8: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800D96EC: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800D96F0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D96F4: mul.s       $f6, $f2, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800D96F8: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800D96FC: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800D9700: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x800D9704: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800D9708: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800D970C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800D9710: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800D9714: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800D9718: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D971C: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800D9720: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800D9724: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D9728: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800D972C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800D9730: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800D9734: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D9738: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D973C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800D9740: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800D9744: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9748: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D974C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D9750: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x800D9754: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D9758: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D975C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800D9760: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x800D9764: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800D9768: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D976C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800D9770: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800D9774: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800D9778: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800D977C: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x800D9780: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800D9784: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x800D9788: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800D978C: swc1        $f10, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f10.u32l;
    // 0x800D9790: sub.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800D9794: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800D9798: swc1        $f4, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f4.u32l;
    // 0x800D979C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800D97A0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D97A4: swc1        $f10, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f10.u32l;
    // 0x800D97A8: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D97AC: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x800D97B0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D97B4: swc1        $f16, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f16.u32l;
    // 0x800D97B8: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x800D97BC: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800D97C0: swc1        $f0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f0.u32l;
    // 0x800D97C4: swc1        $f0, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f0.u32l;
    // 0x800D97C8: swc1        $f0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f0.u32l;
    // 0x800D97CC: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800D97D0: swc1        $f0, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f0.u32l;
    // 0x800D97D4: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x800D97D8: swc1        $f4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f4.u32l;
    // 0x800D97DC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800D97E0: jr          $ra
    // 0x800D97E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800D97E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800048_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080004C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800054: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080005C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800060: jal         0x80100094
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800068: jal         0x800F54E4
    // 0x8080006C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800070: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800074: jal         0x80088368
    // 0x80800078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800078: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_2:
    // 0x8080007C: blez        $v0, L_808000C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800080: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_808000C8;
    }
    // 0x80800080: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80800084: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800088: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8080008C: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80800090: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800094: addu        $s0, $v0, $t7
    ctx->r16 = ADD32(ctx->r2, ctx->r15);
    // 0x80800098: addu        $s2, $v0, $t6
    ctx->r18 = ADD32(ctx->r2, ctx->r14);
    // 0x8080009C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_808000A0:
    // 0x808000A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808000A4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808000A8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808000AC: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x808000B0: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x808000B4: jal         0x80088368
    // 0x808000B8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000B8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    after_3:
    // 0x808000BC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808000C0: bnel        $at, $zero, L_808000A0
    if (ctx->r1 != 0) {
        // 0x808000C4: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_808000A0;
    }
    goto skip_0;
    // 0x808000C4: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_0:
L_808000C8:
    // 0x808000C8: jal         0x800F53D0
    // 0x808000CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F53D0(rdram, ctx);
        goto after_4;
    // 0x808000CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D4: jal         0x800946C4
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_5;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808000E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000E8: jal         0x8008A2A0
    // 0x808000EC: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808000EC: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_6:
    // 0x808000F0: jal         0x8008A2F8
    // 0x808000F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808000F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808000F8: jal         0x800A16BC
    // 0x808000FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_8;
    // 0x808000FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800100: jal         0x800F5410
    // 0x80800104: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5410(rdram, ctx);
        goto after_9;
    // 0x80800104: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80800108: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080010C: beq         $v0, $at, L_80800170
    if (ctx->r2 == ctx->r1) {
        // 0x80800110: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80800170;
    }
    // 0x80800110: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80800114: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800118: beq         $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80800140;
    }
    // 0x8080011C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80800120: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800124: beq         $v0, $at, L_80800150
    if (ctx->r2 == ctx->r1) {
        // 0x80800128: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80800150;
    }
    // 0x80800128: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8080012C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800130: beq         $v0, $at, L_80800160
    if (ctx->r2 == ctx->r1) {
        // 0x80800134: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80800160;
    }
    // 0x80800134: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80800138: b           L_80800180
    // 0x8080013C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
        goto L_80800180;
    // 0x8080013C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
L_80800140:
    // 0x80800140: jal         0x800D2748
    // 0x80800144: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    func_800D2748(rdram, ctx);
        goto after_10;
    // 0x80800144: addiu       $a1, $zero, 0x57
    ctx->r5 = ADD32(0, 0X57);
    after_10:
    // 0x80800148: b           L_8080018C
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: jal         0x800D2748
    // 0x80800154: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    func_800D2748(rdram, ctx);
        goto after_11;
    // 0x80800154: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    after_11:
    // 0x80800158: b           L_8080018C
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800160:
    // 0x80800160: jal         0x800D2748
    // 0x80800164: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_800D2748(rdram, ctx);
        goto after_12;
    // 0x80800164: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_12:
    // 0x80800168: b           L_8080018C
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x8080016C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800170:
    // 0x80800170: jal         0x800D2748
    // 0x80800174: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800D2748(rdram, ctx);
        goto after_13;
    // 0x80800174: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x80800178: b           L_8080018C
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080018C;
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: jal         0x800D2748
    // 0x80800184: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    func_800D2748(rdram, ctx);
        goto after_14;
    // 0x80800184: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_14:
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080018C:
    // 0x8080018C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800194: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800198: jr          $ra
    // 0x8080019C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080019C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _fxripple_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889A0: syscall     715
    recomp_syscall_handler(rdram, ctx, 0x800889A0);
    return;
    // 0x800889A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BD138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BD13C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_800BD140:
    // 0x800BD140: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BD144: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x800BD148: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD14C: sb          $zero, 0x7($v1)
    MEM_B(0X7, ctx->r3) = 0;
    // 0x800BD150: bne         $at, $zero, L_800BD140
    if (ctx->r1 != 0) {
        // 0x800BD154: sb          $zero, 0x15($v1)
        MEM_B(0X15, ctx->r3) = 0;
            goto L_800BD140;
    }
    // 0x800BD154: sb          $zero, 0x15($v1)
    MEM_B(0X15, ctx->r3) = 0;
    // 0x800BD158: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800BD15C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BD160: addiu       $v1, $a0, 0x24
    ctx->r3 = ADD32(ctx->r4, 0X24);
    // 0x800BD164: blez        $t6, L_800BD25C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BD168: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BD25C;
    }
    // 0x800BD168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BD16C: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x800BD170: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
L_800BD174:
    // 0x800BD174: lbu         $t6, 0x7($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X7);
    // 0x800BD178: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800BD17C: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x800BD180: sb          $t8, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r24;
    // 0x800BD184: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800BD188: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x800BD18C: sb          $t7, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r15;
    // 0x800BD190: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800BD194: srl         $t9, $t0, 1
    ctx->r25 = S32(U32(ctx->r8) >> 1);
    // 0x800BD198: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800BD19C: srl         $t8, $t1, 1
    ctx->r24 = S32(U32(ctx->r9) >> 1);
    // 0x800BD1A0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BD1A4: xor         $t5, $t4, $t0
    ctx->r13 = ctx->r12 ^ ctx->r8;
    // 0x800BD1A8: xor         $t4, $t9, $t1
    ctx->r12 = ctx->r25 ^ ctx->r9;
    // 0x800BD1AC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800BD1B0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800BD1B4: addiu       $a2, $v1, 0x8
    ctx->r6 = ADD32(ctx->r3, 0X8);
L_800BD1B8:
    // 0x800BD1B8: lbu         $t5, 0x3($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X3);
    // 0x800BD1BC: lbu         $t4, 0x7($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X7);
    // 0x800BD1C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BD1C4: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x800BD1C8: sb          $t6, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r14;
    // 0x800BD1CC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800BD1D0: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x800BD1D4: sb          $t5, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r13;
    // 0x800BD1D8: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x800BD1DC: srl         $t7, $a3, 1
    ctx->r15 = S32(U32(ctx->r7) >> 1);
    // 0x800BD1E0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800BD1E4: xor         $t9, $t8, $a3
    ctx->r25 = ctx->r24 ^ ctx->r7;
    // 0x800BD1E8: srl         $t6, $t0, 1
    ctx->r14 = S32(U32(ctx->r8) >> 1);
    // 0x800BD1EC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800BD1F0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800BD1F4: lbu         $t9, 0xB($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XB);
    // 0x800BD1F8: xor         $t8, $t7, $t0
    ctx->r24 = ctx->r15 ^ ctx->r8;
    // 0x800BD1FC: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800BD200: lbu         $t8, 0xF($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XF);
    // 0x800BD204: andi        $t4, $t9, 0xFFFE
    ctx->r12 = ctx->r25 & 0XFFFE;
    // 0x800BD208: sb          $t4, 0xB($a2)
    MEM_B(0XB, ctx->r6) = ctx->r12;
    // 0x800BD20C: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x800BD210: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x800BD214: sb          $t9, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r25;
    // 0x800BD218: lw          $t2, 0xC($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XC);
    // 0x800BD21C: srl         $t5, $t1, 1
    ctx->r13 = S32(U32(ctx->r9) >> 1);
    // 0x800BD220: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800BD224: srl         $t4, $t2, 1
    ctx->r12 = S32(U32(ctx->r10) >> 1);
    // 0x800BD228: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800BD22C: xor         $t7, $t6, $t1
    ctx->r15 = ctx->r14 ^ ctx->r9;
    // 0x800BD230: xor         $t6, $t5, $t2
    ctx->r14 = ctx->r13 ^ ctx->r10;
    // 0x800BD234: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x800BD238: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x800BD23C: bne         $a1, $t3, L_800BD1B8
    if (ctx->r5 != ctx->r11) {
        // 0x800BD240: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800BD1B8;
    }
    // 0x800BD240: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800BD244: lbu         $t7, 0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X4);
    // 0x800BD248: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BD24C: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800BD250: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD254: bnel        $at, $zero, L_800BD174
    if (ctx->r1 != 0) {
        // 0x800BD258: lbu         $t7, 0x3($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X3);
            goto L_800BD174;
    }
    goto skip_0;
    // 0x800BD258: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    skip_0:
L_800BD25C:
    // 0x800BD25C: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800BD260: jr          $ra
    // 0x800BD264: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x800BD264: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8080000C_chcamwaypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8080001C: addiu       $a3, $a0, 0x18
    ctx->r7 = ADD32(ctx->r4, 0X18);
    // 0x80800020: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800024: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80800028: addiu       $a1, $t6, 0x44
    ctx->r5 = ADD32(ctx->r14, 0X44);
    // 0x8080002C: jal         0x800EEBF0
    // 0x80800030: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800EEBF0(rdram, ctx);
        goto after_0;
    // 0x80800030: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800038: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080003C: jal         0x800EEAA4
    // 0x80800040: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800044: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_80800A50_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A58: jal         0x80082FE8
    // 0x80800A5C: nop

    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800A5C: nop

    after_0:
    // 0x80800A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A68: jr          $ra
    // 0x80800A6C: nop

    return;
    // 0x80800A6C: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844E0: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844E0);
    return;
    // 0x800844E4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_801018D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801018D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801018DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801018E0: lhu         $t6, 0x94($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X94);
    // 0x801018E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801018E8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801018EC: beq         $t7, $zero, L_80101904
    if (ctx->r15 == 0) {
        // 0x801018F0: nop
    
            goto L_80101904;
    }
    // 0x801018F0: nop

    // 0x801018F4: jal         0x80101918
    // 0x801018F8: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    func_80101918(rdram, ctx);
        goto after_0;
    // 0x801018F8: lwc1        $f12, 0x38($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x801018FC: b           L_80101904
    // 0x80101900: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80101904;
    // 0x80101900: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80101904:
    // 0x80101904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010190C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101910: jr          $ra
    // 0x80101914: nop

    return;
    // 0x80101914: nop

;}
RECOMP_FUNC void func_80800000_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080001C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800020: lwc1        $f6, 0x14C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14C);
    // 0x80800024: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800028: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8080002C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800030: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800034: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x80800038: bc1f        L_80800060
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800060;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x800FCCD4
    // 0x80800044: lbu         $a0, 0x144($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X144);
    func_800FCCD4(rdram, ctx);
        goto after_0;
    // 0x80800044: lbu         $a0, 0x144($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X144);
    after_0:
    // 0x80800048: beql        $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x8080004C: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80800090;
    }
    goto skip_0;
    // 0x8080004C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_0:
    // 0x80800050: jal         0x800FC74C
    // 0x80800054: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    func_800FC74C(rdram, ctx);
        goto after_1;
    // 0x80800054: lbu         $a0, 0x144($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X144);
    after_1:
    // 0x80800058: b           L_80800090
    // 0x8080005C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80800090;
    // 0x8080005C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80800060:
    // 0x80800060: lbu         $a0, 0x144($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X144);
    // 0x80800064: beql        $a0, $zero, L_80800084
    if (ctx->r4 == 0) {
        // 0x80800068: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800084;
    }
    goto skip_1;
    // 0x80800068: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8080006C: jal         0x800C2FDC
    // 0x80800070: nop

    func_800C2FDC(rdram, ctx);
        goto after_2;
    // 0x80800070: nop

    after_2:
    // 0x80800074: lbu         $t6, 0x178($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X178);
    // 0x80800078: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080007C: sb          $t7, 0x178($s2)
    MEM_B(0X178, ctx->r18) = ctx->r15;
    // 0x80800080: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800084:
    // 0x80800084: bne         $s1, $s3, L_80800060
    if (ctx->r17 != ctx->r19) {
        // 0x80800088: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800060;
    }
    // 0x80800088: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080008C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80800090:
    // 0x80800090: sb          $zero, 0x144($s2)
    MEM_B(0X144, ctx->r18) = 0;
    // 0x80800094: addu        $s0, $s2, $s1
    ctx->r16 = ADD32(ctx->r18, ctx->r17);
    // 0x80800098: sb          $zero, 0x145($s0)
    MEM_B(0X145, ctx->r16) = 0;
    // 0x8080009C: sb          $zero, 0x146($s0)
    MEM_B(0X146, ctx->r16) = 0;
    // 0x808000A0: sb          $zero, 0x147($s0)
    MEM_B(0X147, ctx->r16) = 0;
    // 0x808000A4: sb          $zero, 0x144($s0)
    MEM_B(0X144, ctx->r16) = 0;
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: jr          $ra
    // 0x808000C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chboilerbossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1416, 0XF0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1416, 0XF0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1416, 0XF0));
;}
RECOMP_FUNC void _bsrest_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083948: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083948);
    return;
    // 0x8008394C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800508_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080050C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800510: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800514: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800518: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080051C: lw          $s0, 0x28($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X28);
    // 0x80800520: jal         0x80100094
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800528: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8080052C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1204, 0X910) << 16);
    // 0x80800530: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800534: lhu         $a1, 0x910($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1204, 0X910));
    // 0x80800538: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8080053C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800540: bne         $a1, $at, L_8080055C
    if (ctx->r5 != ctx->r1) {
        // 0x80800544: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080055C;
    }
    // 0x80800544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800548: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080054C: jal         0x8080043C
    // 0x80800550: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8080043C_chmrsicecube(rdram, ctx);
        goto after_1;
    // 0x80800550: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800554: b           L_80800568
    // 0x80800558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80800568;
    // 0x80800558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080055C:
    // 0x8080055C: jal         0x8080048C
    // 0x80800560: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_8080048C_chmrsicecube(rdram, ctx);
        goto after_2;
    // 0x80800560: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800564: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800568:
    // 0x80800568: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x8080056C: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_8080061C;
    }
    // 0x8080056C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800570: jal         0x800EEB40
    // 0x80800574: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80800574: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1204, 0X8E8) << 16);
    // 0x8080057C: lwc1        $f4, 0x8E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1204, 0X8E8));
    // 0x80800580: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800584: nop

    // 0x80800588: bc1fl       L_80800620
    if (!c1cs) {
        // 0x8080058C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800620;
    }
    goto skip_0;
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800590: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800594: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x808005A0: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x808005A4: jal         0x8010A570
    // 0x808005A8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808005A8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_4:
    // 0x808005AC: jal         0x8010A624
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_5;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B8: jal         0x80102190
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102190(rdram, ctx);
        goto after_6;
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C4: jal         0x80103110
    // 0x808005C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x808005C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808005CC: lbu         $t1, 0x64($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X64);
    // 0x808005D0: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808005D4: lbu         $t5, 0x75($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X75);
    // 0x808005D8: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808005DC: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808005E0: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x808005E4: sb          $t2, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r10;
    // 0x808005E8: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x808005EC: sb          $t6, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r14;
    // 0x808005F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005F4: jal         0x8080066C
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8080066C_chmrsicecube(rdram, ctx);
        goto after_8;
    // 0x808005F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808005FC: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800600: sll         $t9, $t7, 26
    ctx->r25 = S32(ctx->r15 << 26);
    // 0x80800604: bgez        $t9, L_80800614
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800608: nop
    
            goto L_80800614;
    }
    // 0x80800608: nop

    // 0x8080060C: jal         0x80103014
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_9;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800614:
    // 0x80800614: b           L_80800620
    // 0x80800618: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80800620;
    // 0x80800618: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8080061C:
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800620:
    // 0x80800620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800624: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800628: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800630: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800DD8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DE0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800DE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800DE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800DEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800DF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800DF4: jal         0x80100094
    // 0x80800DF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800E00: sb          $zero, 0x3C($v0)
    MEM_B(0X3C, ctx->r2) = 0;
    // 0x80800E04: jal         0x80090178
    // 0x80800E08: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090178(rdram, ctx);
        goto after_1;
    // 0x80800E08: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_1:
    // 0x80800E0C: bne         $v0, $zero, L_80800E24
    if (ctx->r2 != 0) {
        // 0x80800E10: addiu       $a0, $zero, 0x65A
        ctx->r4 = ADD32(0, 0X65A);
            goto L_80800E24;
    }
    // 0x80800E10: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    // 0x80800E14: jal         0x800FFAB0
    // 0x80800E18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800E18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800E1C: b           L_80801020
    // 0x80800E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801020;
    // 0x80800E20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E24:
    // 0x80800E24: jal         0x800DA3B8
    // 0x80800E28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_3;
    // 0x80800E28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800E2C: jal         0x80089AB0
    // 0x80800E30: nop

    _sukickball_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800E30: nop

    after_4:
    // 0x80800E34: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800E38: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E3C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1840, 0X4D7C) << 16);
    // 0x80800E40: sb          $v0, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r2;
    // 0x80800E44: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800E48: lw          $t7, 0x4D7C($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(1840, 0X4D7C));
    // 0x80800E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E50: beq         $a0, $zero, L_80800E7C
    if (ctx->r4 == 0) {
        // 0x80800E54: sb          $t7, 0x3A($s3)
        MEM_B(0X3A, ctx->r19) = ctx->r15;
            goto L_80800E7C;
    }
    // 0x80800E54: sb          $t7, 0x3A($s3)
    MEM_B(0X3A, ctx->r19) = ctx->r15;
    // 0x80800E58: beq         $a0, $at, L_80800E9C
    if (ctx->r4 == ctx->r1) {
        // 0x80800E5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E9C;
    }
    // 0x80800E5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E60: beq         $a0, $at, L_80800EBC
    if (ctx->r4 == ctx->r1) {
        // 0x80800E64: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800EBC;
    }
    // 0x80800E64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E6C: beq         $a0, $at, L_80800EDC
    if (ctx->r4 == ctx->r1) {
        // 0x80800E70: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800EDC;
    }
    // 0x80800E70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800E74: b           L_80800F14
    // 0x80800E78: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
        goto L_80800F14;
    // 0x80800E78: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
L_80800E7C:
    // 0x80800E7C: jal         0x800DA298
    // 0x80800E80: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800E80: addiu       $a0, $zero, 0x368
    ctx->r4 = ADD32(0, 0X368);
    after_5:
    // 0x80800E84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800E88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E8C: jal         0x80800D60
    // 0x80800E90: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800D60_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x80800E90: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_6:
    // 0x80800E94: b           L_80800F14
    // 0x80800E98: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
        goto L_80800F14;
    // 0x80800E98: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
L_80800E9C:
    // 0x80800E9C: jal         0x800DA298
    // 0x80800EA0: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800EA0: addiu       $a0, $zero, 0x369
    ctx->r4 = ADD32(0, 0X369);
    after_7:
    // 0x80800EA4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800EA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800EAC: jal         0x80800D60
    // 0x80800EB0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800D60_chcollballcontrol(rdram, ctx);
        goto after_8;
    // 0x80800EB0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_8:
    // 0x80800EB4: b           L_80800F14
    // 0x80800EB8: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
        goto L_80800F14;
    // 0x80800EB8: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
L_80800EBC:
    // 0x80800EBC: jal         0x800D0A9C
    // 0x80800EC0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    func_800D0A9C(rdram, ctx);
        goto after_9;
    // 0x80800EC0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_9:
    // 0x80800EC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800EC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800ECC: jal         0x80800D60
    // 0x80800ED0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    func_80800D60_chcollballcontrol(rdram, ctx);
        goto after_10;
    // 0x80800ED0: lbu         $a2, 0x39($s3)
    ctx->r6 = MEM_BU(ctx->r19, 0X39);
    after_10:
    // 0x80800ED4: b           L_80800F14
    // 0x80800ED8: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
        goto L_80800F14;
    // 0x80800ED8: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
L_80800EDC:
    // 0x80800EDC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80800EE0:
    // 0x80800EE0: jal         0x800F6438
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_11;
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800EE8: beq         $v0, $zero, L_80800EF8
    if (ctx->r2 == 0) {
        // 0x80800EEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF8;
    }
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF0: jal         0x800F4CEC
    // 0x80800EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F4CEC(rdram, ctx);
        goto after_12;
    // 0x80800EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
L_80800EF8:
    // 0x80800EF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800EFC: bne         $s0, $s1, L_80800EE0
    if (ctx->r16 != ctx->r17) {
        // 0x80800F00: nop
    
            goto L_80800EE0;
    }
    // 0x80800F00: nop

    // 0x80800F04: jal         0x80088368
    // 0x80800F08: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800F08: nop

    after_13:
    // 0x80800F0C: sb          $v0, 0x3A($s3)
    MEM_B(0X3A, ctx->r19) = ctx->r2;
    // 0x80800F10: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
L_80800F14:
    // 0x80800F14: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800F18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800F1C: blezl       $t8, L_80800F60
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800F20: lbu         $t2, 0x39($s3)
        ctx->r10 = MEM_BU(ctx->r19, 0X39);
            goto L_80800F60;
    }
    goto skip_0;
    // 0x80800F20: lbu         $t2, 0x39($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X39);
    skip_0:
    // 0x80800F24: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800F28:
    // 0x80800F28: jal         0x80100094
    // 0x80800F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80800F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800F30: addu        $t9, $v0, $s1
    ctx->r25 = ADD32(ctx->r2, ctx->r17);
    // 0x80800F34: sb          $zero, 0x34($t9)
    MEM_B(0X34, ctx->r25) = 0;
    // 0x80800F38: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
    // 0x80800F3C: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x80800F40: lbu         $t1, 0x3A($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X3A);
    // 0x80800F44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800F48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800F4C: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800F50: bnel        $at, $zero, L_80800F28
    if (ctx->r1 != 0) {
        // 0x80800F54: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800F28;
    }
    goto skip_1;
    // 0x80800F54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80800F58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800F5C: lbu         $t2, 0x39($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X39);
L_80800F60:
    // 0x80800F60: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F64: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800F68: bne         $t2, $at, L_80800F7C
    if (ctx->r10 != ctx->r1) {
        // 0x80800F6C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800F7C;
    }
    // 0x80800F6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800F70: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800F74: b           L_80800F84
    // 0x80800F78: sb          $t3, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r11;
        goto L_80800F84;
    // 0x80800F78: sb          $t3, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r11;
L_80800F7C:
    // 0x80800F7C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800F80: sb          $t4, 0xA($s3)
    MEM_B(0XA, ctx->r19) = ctx->r12;
L_80800F84:
    // 0x80800F84: lbu         $t8, 0x3A($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3A);
    // 0x80800F88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800F8C: sb          $t5, 0xB($s3)
    MEM_B(0XB, ctx->r19) = ctx->r13;
    // 0x80800F90: sb          $t6, 0xC($s3)
    MEM_B(0XC, ctx->r19) = ctx->r14;
    // 0x80800F94: blez        $t8, L_8080100C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800F98: sb          $t7, 0xD($s3)
        MEM_B(0XD, ctx->r19) = ctx->r15;
            goto L_8080100C;
    }
    // 0x80800F98: sb          $t7, 0xD($s3)
    MEM_B(0XD, ctx->r19) = ctx->r15;
    // 0x80800F9C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800FA0: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
L_80800FA4:
    // 0x80800FA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FA8: addiu       $a0, $zero, 0x19F
    ctx->r4 = ADD32(0, 0X19F);
    // 0x80800FAC: beq         $v1, $at, L_80800FC8
    if (ctx->r3 == ctx->r1) {
        // 0x80800FB0: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80800FC8;
    }
    // 0x80800FB0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800FB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800FB8: beql        $v1, $at, L_80800FEC
    if (ctx->r3 == ctx->r1) {
        // 0x80800FBC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800FEC;
    }
    goto skip_2;
    // 0x80800FBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80800FC0: b           L_80800FEC
    // 0x80800FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80800FEC;
    // 0x80800FC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800FC8:
    // 0x80800FC8: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x80800FCC: jal         0x801084B0
    // 0x80800FD0: addu        $s2, $s3, $t9
    ctx->r18 = ADD32(ctx->r19, ctx->r25);
    func_801084B0(rdram, ctx);
        goto after_15;
    // 0x80800FD0: addu        $s2, $s3, $t9
    ctx->r18 = ADD32(ctx->r19, ctx->r25);
    after_15:
    // 0x80800FD4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80800FD8: sw          $t0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r8;
    // 0x80800FDC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800FE0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80800FE4: sw          $t2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r10;
    // 0x80800FE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800FEC:
    // 0x80800FEC: jal         0x80801108
    // 0x80800FF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80801108_chcollballcontrol(rdram, ctx);
        goto after_16;
    // 0x80800FF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x80800FF4: lbu         $t3, 0x3A($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X3A);
    // 0x80800FF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800FFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801000: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80801004: bnel        $at, $zero, L_80800FA4
    if (ctx->r1 != 0) {
        // 0x80801008: lbu         $v1, 0xA($s0)
        ctx->r3 = MEM_BU(ctx->r16, 0XA);
            goto L_80800FA4;
    }
    goto skip_3;
    // 0x80801008: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    skip_3:
L_8080100C:
    // 0x8080100C: jal         0x80089B28
    // 0x80801010: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _sukickball_entrypoint_18(rdram, ctx);
        goto after_17;
    // 0x80801010: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x80801014: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801018: sb          $t4, 0x3C($s3)
    MEM_B(0X3C, ctx->r19) = ctx->r12;
    // 0x8080101C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801020:
    // 0x80801020: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801024: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801028: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080102C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801030: jr          $ra
    // 0x80801034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801034: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080340C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080340C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803414: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803418: jal         0x80100094
    // 0x8080341C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080341C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803420: lbu         $t6, 0x64($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X64);
    // 0x80803424: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80803428: bne         $t6, $zero, L_80803448
    if (ctx->r14 != 0) {
        // 0x8080342C: nop
    
            goto L_80803448;
    }
    // 0x8080342C: nop

    // 0x80803430: lh          $a0, 0x78($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X78);
    // 0x80803434: jal         0x800F4AF4
    // 0x80803438: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F4AF4(rdram, ctx);
        goto after_1;
    // 0x80803438: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080343C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803440: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80803444: sb          $t7, 0x64($v1)
    MEM_B(0X64, ctx->r3) = ctx->r15;
L_80803448:
    // 0x80803448: jal         0x808034A0
    // 0x8080344C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808034A0_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x8080344C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80803450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803454: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803458: jr          $ra
    // 0x8080345C: nop

    return;
    // 0x8080345C: nop

;}
RECOMP_FUNC void func_800C4C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4C34: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800C4C38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4C3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C4C40: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800C4C44: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800C4C48: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800C4C4C: jal         0x800A8984
    // 0x800C4C50: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    func_800A8984(rdram, ctx);
        goto after_0;
    // 0x800C4C50: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C4C54: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C4C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C4C5C: jal         0x800CA7E4
    // 0x800C4C60: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800CA7E4(rdram, ctx);
        goto after_1;
    // 0x800C4C60: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x800C4C64: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800C4C68: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800C4C6C: jal         0x800EFB24
    // 0x800C4C70: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800C4C70: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x800C4C74: jal         0x800CA7AC
    // 0x800C4C78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800CA7AC(rdram, ctx);
        goto after_3;
    // 0x800C4C78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x800C4C7C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800C4C80: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C4C84: jal         0x800F23D0
    // 0x800C4C88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F23D0(rdram, ctx);
        goto after_4;
    // 0x800C4C88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800C4C8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C4C90: lwc1        $f6, 0x5894($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5894);
    // 0x800C4C94: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C4C98: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x800C4C9C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x800C4CA0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800C4CA4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800C4CA8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800C4CAC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    // 0x800C4CB0: bc1f        L_800C4CBC
    if (!c1cs) {
        // 0x800C4CB4: addiu       $t8, $sp, 0x3C
        ctx->r24 = ADD32(ctx->r29, 0X3C);
            goto L_800C4CBC;
    }
    // 0x800C4CB4: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x800C4CB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800C4CBC:
    // 0x800C4CBC: bne         $t6, $zero, L_800C4CD8
    if (ctx->r14 != 0) {
        // 0x800C4CC0: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C4CD8;
    }
    // 0x800C4CC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C4CC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C4CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C4CCC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800C4CD0: b           L_800C4E44
    // 0x800C4CD4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_800C4E44;
    // 0x800C4CD4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_800C4CD8:
    // 0x800C4CD8: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800C4CDC: jal         0x800A8A04
    // 0x800C4CE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800A8A04(rdram, ctx);
        goto after_5;
    // 0x800C4CE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x800C4CE4: jal         0x800CA79C
    // 0x800C4CE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800CA79C(rdram, ctx);
        goto after_6;
    // 0x800C4CE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x800C4CEC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4CF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C4CF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C4CF8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800C4CFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C4D00: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800C4D04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4D08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C4D0C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800C4D10: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800C4D14: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C4D18: mul.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C4D1C: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x800C4D20: jal         0x800CA6FC
    // 0x800C4D24: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    func_800CA6FC(rdram, ctx);
        goto after_7;
    // 0x800C4D24: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x800C4D28: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800C4D2C: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4D30: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C4D34: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C4D38: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800C4D3C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C4D40: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4D44: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800C4D48: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800C4D4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C4D50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C4D54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4D58: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C4D5C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800C4D60: div.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800C4D64: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800C4D68: nop

    // 0x800C4D6C: mul.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800C4D70: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800C4D74: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800C4D78: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C4D7C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4D80: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C4D84: mul.s       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800C4D88: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800C4D8C: nop

    // 0x800C4D90: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C4D94: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C4D98: nop

    // 0x800C4D9C: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800C4DA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C4DA4: nop

    // 0x800C4DA8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800C4DAC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800C4DB0: bc1t        L_800C4E10
    if (c1cs) {
        // 0x800C4DB4: swc1        $f10, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
            goto L_800C4E10;
    }
    // 0x800C4DB4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800C4DB8: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800C4DBC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800C4DC0: nop

    // 0x800C4DC4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4DC8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x800C4DCC: nop

    // 0x800C4DD0: bc1t        L_800C4E10
    if (c1cs) {
        // 0x800C4DD4: nop
    
            goto L_800C4E10;
    }
    // 0x800C4DD4: nop

    // 0x800C4DD8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C4DDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C4DE0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800C4DE4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800C4DE8: nop

    // 0x800C4DEC: bc1t        L_800C4E10
    if (c1cs) {
        // 0x800C4DF0: nop
    
            goto L_800C4E10;
    }
    // 0x800C4DF0: nop

    // 0x800C4DF4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800C4DF8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800C4DFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C4E00: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800C4E04: nop

    // 0x800C4E08: bc1fl       L_800C4E1C
    if (!c1cs) {
        // 0x800C4E0C: mtc1        $t5, $f8
        ctx->f8.u32l = ctx->r13;
            goto L_800C4E1C;
    }
    goto skip_0;
    // 0x800C4E0C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    skip_0:
L_800C4E10:
    // 0x800C4E10: b           L_800C4E44
    // 0x800C4E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C4E44;
    // 0x800C4E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C4E18: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
L_800C4E1C:
    // 0x800C4E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C4E20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C4E24: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800C4E28: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x800C4E2C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800C4E30: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800C4E34: nop

    // 0x800C4E38: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C4E3C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800C4E40: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
L_800C4E44:
    // 0x800C4E44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4E48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C4E4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x800C4E50: jr          $ra
    // 0x800C4E54: nop

    return;
    // 0x800C4E54: nop

;}
RECOMP_FUNC void func_800A5BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5BBC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5BC0: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5BC4: jr          $ra
    // 0x800A5BC8: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
    return;
    // 0x800A5BC8: lbu         $v0, 0xA($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XA);
;}
