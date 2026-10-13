#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncpoducam_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: sw          $a1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r5;
    // 0x80800140: lhu         $t6, 0x12($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X12);
    // 0x80800144: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800148: jr          $ra
    // 0x8080014C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x8080014C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void _chintrotext_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861B0: syscall     285
    recomp_syscall_handler(rdram, ctx, 0x800861B0);
    return;
    // 0x800861B4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bsbswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AFC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B00: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1E90) << 16);
    // 0x80800B04: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E90));
    return;
    // 0x80800B0C: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E90));
;}
RECOMP_FUNC void func_8080003C_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: jal         0x80085808
    // 0x80800048: nop

    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _sumultiscore_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899C8: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x800899C8);
    return;
    // 0x800899CC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _bsstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B38: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B38);
    return;
    // 0x80083B3C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chnewfreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E38: syscall     460
    recomp_syscall_handler(rdram, ctx, 0x80086E38);
    return;
    // 0x80086E3C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idwibble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080063C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800644: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800648: jal         0x800D8FF8
    // 0x8080064C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080064C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800650: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800654: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800658: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080065C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800664: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800668: jal         0x800EE7F8
    // 0x8080066C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080066C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80800670: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80800674: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800678: jal         0x800EE7F8
    // 0x8080067C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080067C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800680: lh          $t6, 0x34($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X34);
    // 0x80800684: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800688: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080068C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80800690: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800694: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800698: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8080069C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x808006A0: lh          $t7, 0x34($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X34);
    // 0x808006A4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x808006A8: nop

    // 0x808006AC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808006B0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x808006B4: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x808006B8: lbu         $t8, 0x37($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X37);
    // 0x808006BC: bne         $t8, $zero, L_808006D0
    if (ctx->r24 != 0) {
        // 0x808006C0: nop
    
            goto L_808006D0;
    }
    // 0x808006C0: nop

    // 0x808006C4: jal         0x800E3D0C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E3D0C(rdram, ctx);
        goto after_3;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808006CC: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808006D0: lui         $a2, 0x8009
        ctx->r6 = S32(0X8009 << 16);
            goto L_808006E8;
    }
L_808006D0:
    // 0x808006D0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808006D4: addiu       $a2, $a2, -0x7190
    ctx->r6 = ADD32(ctx->r6, -0X7190);
    // 0x808006D8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808006DC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808006E0: jal         0x80088660
    // 0x808006E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808006E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
L_808006E8:
    // 0x808006E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808006F4: jr          $ra
    // 0x808006F8: nop

    return;
    // 0x808006F8: nop

;}
RECOMP_FUNC void func_80800980_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800988: jal         0x800F54E4
    // 0x8080098C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080098C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800990: jal         0x800F6438
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800998: beql        $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x8080099C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009E0;
    }
    goto skip_0;
    // 0x8080099C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009A0: jal         0x800F54E4
    // 0x808009A4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808009A4: nop

    after_2:
    // 0x808009A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009AC: jal         0x800F5A00
    // 0x808009B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808009B0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x808009B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009B8: jal         0x80102D78
    // 0x808009BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_4;
    // 0x808009BC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x808009C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808009C4: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x808009C8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808009CC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808009D0: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x808009D4: jal         0x80102BF8
    // 0x808009D8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_5;
    // 0x808009D8: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_5:
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009E0:
    // 0x808009E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void _bstnt_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F60: syscall     99
    recomp_syscall_handler(rdram, ctx, 0x80083F60);
    return;
    // 0x80083F64: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bstnt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B4C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B50: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X23F8) << 16);
    // 0x80800B54: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B58: jr          $ra
    // 0x80800B5C: lw          $v0, 0x23F8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X23F8));
    return;
    // 0x80800B5C: lw          $v0, 0x23F8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X23F8));
;}
RECOMP_FUNC void func_80800AC4_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ACC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800AD4: jal         0x80100094
    // 0x80800AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800ADC: jal         0x8008A040
    // 0x80800AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800AE4: beq         $v0, $zero, L_80800B20
    if (ctx->r2 == 0) {
        // 0x80800AE8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800B20;
    }
    // 0x80800AE8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800AEC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800AF0: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80800AF4: beql        $a1, $zero, L_80800B0C
    if (ctx->r5 == 0) {
        // 0x80800AF8: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80800B0C;
    }
    goto skip_0;
    // 0x80800AF8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800AFC: jal         0x800EE7F8
    // 0x80800B00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800B00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800B04: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80800B0C:
    // 0x80800B0C: lbu         $t9, 0x65($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X65);
    // 0x80800B10: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800B14: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800B18: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800B1C: sb          $t1, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r9;
L_80800B20:
    // 0x80800B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void _chsunlightspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087418: syscall     569
    recomp_syscall_handler(rdram, ctx, 0x80087418);
    return;
    // 0x8008741C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void badata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080078C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800790: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800794: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080079C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1DD8) << 16);
    // 0x808007A0: jal         0x808006AC
    // 0x808007A4: addiu       $a1, $a1, 0x1DD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1DD8));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x808007A4: addiu       $a1, $a1, 0x1DD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1DD8));
    after_0:
    // 0x808007A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007B0: jr          $ra
    // 0x808007B4: nop

    return;
    // 0x808007B4: nop

;}
RECOMP_FUNC void _chstonedartgunhead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F28: syscall     475
    recomp_syscall_handler(rdram, ctx, 0x80086F28);
    return;
    // 0x80086F2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bastatemem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800038: jal         0x8001B084
    // 0x8080003C: lw          $a0, 0x188($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X188);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x8080003C: lw          $a0, 0x188($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x80800040: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800044: sw          $zero, 0x188($t7)
    MEM_W(0X188, ctx->r15) = 0;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_800C9310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9314: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9318: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C931C: addiu       $s0, $s0, -0x54C0
    ctx->r16 = ADD32(ctx->r16, -0X54C0);
    // 0x800C9320: lbu         $t6, 0x14($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X14);
    // 0x800C9324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9328: beql        $t6, $zero, L_800C9348
    if (ctx->r14 == 0) {
        // 0x800C932C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C9348;
    }
    goto skip_0;
    // 0x800C932C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_800C9330:
    // 0x800C9330: jal         0x800881D0
    // 0x800C9334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gctransitionDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800C9334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800C9338: lbu         $t7, 0x14($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X14);
    // 0x800C933C: bne         $t7, $zero, L_800C9330
    if (ctx->r15 != 0) {
        // 0x800C9340: nop
    
            goto L_800C9330;
    }
    // 0x800C9340: nop

    // 0x800C9344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C9348:
    // 0x800C9348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C934C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9350: jr          $ra
    // 0x800C9354: nop

    return;
    // 0x800C9354: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080154C: jr          $ra
    // 0x80801550: sb          $zero, 0x78($a0)
    MEM_B(0X78, ctx->r4) = 0;
    return;
    // 0x80801550: sb          $zero, 0x78($a0)
    MEM_B(0X78, ctx->r4) = 0;
;}
RECOMP_FUNC void func_8009ADF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ADF0: lw          $t6, 0xC4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC4);
    // 0x8009ADF4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8009ADF8: jr          $ra
    // 0x8009ADFC: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    return;
    // 0x8009ADFC: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
;}
RECOMP_FUNC void func_800BEC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEC4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEC50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEC54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BEC58: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BEC5C: jal         0x800BECE0
    // 0x800BEC60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800BECE0(rdram, ctx);
        goto after_0;
    // 0x800BEC60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800BEC64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BEC68: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BEC6C: jal         0x800E37E8
    // 0x800BEC70: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800E37E8(rdram, ctx);
        goto after_1;
    // 0x800BEC70: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800BEC74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEC78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BEC7C: addiu       $a1, $a1, -0x7A4D
    ctx->r5 = ADD32(ctx->r5, -0X7A4D);
    // 0x800BEC80: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
    // 0x800BEC84: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800BEC88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800BEC8C:
    // 0x800BEC8C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BEC90: lb          $t7, 0x5E($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5E);
    // 0x800BEC94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BEC98: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BEC9C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BECA0: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800BECA4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800BECA8: lb          $t0, 0x60($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X60);
    // 0x800BECAC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BECB0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800BECB4: bne         $v0, $a1, L_800BEC8C
    if (ctx->r2 != ctx->r5) {
        // 0x800BECB8: sw          $t1, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r9;
            goto L_800BEC8C;
    }
    // 0x800BECB8: sw          $t1, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r9;
    // 0x800BECBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BECC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BECC4: jr          $ra
    // 0x800BECC8: nop

    return;
    // 0x800BECC8: nop

;}
RECOMP_FUNC void _bamovethrust_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EF0: syscall     141
    recomp_syscall_handler(rdram, ctx, 0x80084EF0);
    return;
    // 0x80084EF4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _fxegg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088AA0: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088AA0);
    return;
    // 0x80088AA4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800008_ncbadie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: jal         0x80112524
    // 0x80800018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080001C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80800028: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080002C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80800030: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800034: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_80800524_cothemedll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080052C: beq         $a1, $zero, L_8080053C
    if (ctx->r5 == 0) {
        // 0x80800530: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8080053C;
    }
    // 0x80800530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800534: jal         0x800FC884
    // 0x80800538: nop

    func_800FC884(rdram, ctx);
        goto after_0;
    // 0x80800538: nop

    after_0:
L_8080053C:
    // 0x8080053C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800540: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800544: lh          $a0, 0x8($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X8);
    // 0x80800548: beql        $a0, $at, L_8080056C
    if (ctx->r4 == ctx->r1) {
        // 0x8080054C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080056C;
    }
    goto skip_0;
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800550: jal         0x800FCCD4
    // 0x80800554: nop

    func_800FCCD4(rdram, ctx);
        goto after_1;
    // 0x80800554: nop

    after_1:
    // 0x80800558: bnel        $v0, $zero, L_8080056C
    if (ctx->r2 != 0) {
        // 0x8080055C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080056C;
    }
    goto skip_1;
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800560: jal         0x800FE89C
    // 0x80800564: nop

    func_800FE89C(rdram, ctx);
        goto after_2;
    // 0x80800564: nop

    after_2:
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080056C:
    // 0x8080056C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800570: jr          $ra
    // 0x80800574: nop

    return;
    // 0x80800574: nop

;}
RECOMP_FUNC void func_80800EB4_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EBC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800EC0: jal         0x80101870
    // 0x80800EC4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800EC4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EC8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800ECC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800ED0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800ED4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800ED8: beq         $t6, $at, L_80800F30
    if (ctx->r14 == ctx->r1) {
        // 0x80800EDC: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80800F30;
    }
    // 0x80800EDC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800EE0: beq         $t6, $at, L_80800F30
    if (ctx->r14 == ctx->r1) {
        // 0x80800EE4: addiu       $t7, $sp, 0x24
        ctx->r15 = ADD32(ctx->r29, 0X24);
            goto L_80800F30;
    }
    // 0x80800EE4: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80800EE8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2360, 0X1004) << 16);
    // 0x80800EEC: addiu       $t8, $t8, 0x1004
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2360, 0X1004));
    // 0x80800EF0: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800EF4: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800EF8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800EFC: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80800F00: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80800F04: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80800F08: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800F0C: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x80800F10: jal         0x800F1214
    // 0x80800F14: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    func_800F1214(rdram, ctx);
        goto after_1;
    // 0x80800F14: lwc1        $f12, 0x34($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X34);
    after_1:
    // 0x80800F18: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800F1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800F20: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800F24: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800F28: jal         0x800B99CC
    // 0x80800F2C: nop

    func_800B99CC(rdram, ctx);
        goto after_2;
    // 0x80800F2C: nop

    after_2:
L_80800F30:
    // 0x80800F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800F38: jr          $ra
    // 0x80800F3C: nop

    return;
    // 0x80800F3C: nop

;}
RECOMP_FUNC void func_808019C4_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808019C8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808019CC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808019D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808019D4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808019D8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808019DC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808019E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808019E4: jal         0x80100094
    // 0x808019E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808019EC: lbu         $t6, 0xC2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC2);
    // 0x808019F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808019F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808019F8: blez        $t6, L_80801A20
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808019FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801A20;
    }
    // 0x808019FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801A00:
    // 0x80801A00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801A04: jal         0x80801A3C
    // 0x80801A08: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80801A3C_chdodgemcontrol(rdram, ctx);
        goto after_1;
    // 0x80801A08: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x80801A0C: lbu         $t7, 0xC2($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0XC2);
    // 0x80801A10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801A14: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801A18: bnel        $at, $zero, L_80801A00
    if (ctx->r1 != 0) {
        // 0x80801A1C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801A00;
    }
    goto skip_0;
    // 0x80801A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80801A20:
    // 0x80801A20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801A28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801A2C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A30: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801A34: jr          $ra
    // 0x80801A38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801A38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085680: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085680);
    return;
    // 0x80085684: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void cadbfunc_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080080C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800814: jal         0x80800798
    // 0x80800818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800798_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800818: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080081C: bne         $v0, $zero, L_8080082C
    if (ctx->r2 != 0) {
        // 0x80800820: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080082C;
    }
    // 0x80800820: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800824: b           L_8080083C
    // 0x80800828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080083C;
    // 0x80800828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080082C:
    // 0x8080082C: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80800830: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800838: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
L_8080083C:
    // 0x8080083C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800844: jr          $ra
    // 0x80800848: nop

    return;
    // 0x80800848: nop

;}
RECOMP_FUNC void gldialog_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808000E0: lw          $a0, 0x7604($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7604);
    // 0x808000E4: jal         0x800D721C
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D721C(rdram, ctx);
        goto after_0;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808000F0: lw          $a0, 0x7604($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7604);
    // 0x808000F4: jal         0x800D70F8
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800100: jal         0x800D6CEC
    // 0x80800104: lw          $a0, 0x7604($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7604);
    func_800D6CEC(rdram, ctx);
        goto after_2;
    // 0x80800104: lw          $a0, 0x7604($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7604);
    after_2:
    // 0x80800108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080010C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800110: addiu       $v0, $v0, 0x7600
    ctx->r2 = ADD32(ctx->r2, 0X7600);
    // 0x80800114: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800118: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8080011C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80800120: jr          $ra
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: nop

    // 0x8080012C: nop

;}
RECOMP_FUNC void idflasha_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800130: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800134: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800138: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080013C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800140: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80800144: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80800148: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8080014C: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80800150: jal         0x80800038
    // 0x80800154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800038_idflasha(rdram, ctx);
        goto after_0;
    // 0x80800154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void _gcfrontend_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088160: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088160);
    return;
    // 0x80088164: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800F31FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F31FC: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x800F3200: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x800F3204: sb          $a3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r7;
    // 0x800F3208: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800F320C: jr          $ra
    // 0x800F3210: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
    return;
    // 0x800F3210: sb          $t6, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void _sueggmove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A458: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A458);
    return;
    // 0x8008A45C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8001DCB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DCB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DCB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001DCB8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001DCBC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8001DCC0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8001DCC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8001DCC8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8001DCCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001DCD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001DCD4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8001DCD8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001DCDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001DCE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001DCE4: jal         0x80031810
    // 0x8001DCE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8001DCE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8001DCEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001DCF0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DCF4: beq         $s0, $zero, L_8001DD08
    if (ctx->r16 == 0) {
        // 0x8001DCF8: sw          $s0, 0x1C($a0)
        MEM_W(0X1C, ctx->r4) = ctx->r16;
            goto L_8001DD08;
    }
    // 0x8001DCF8: sw          $s0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r16;
    // 0x8001DCFC: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8001DD00: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8001DD04: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_8001DD08:
    // 0x8001DD08: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8001DD0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001DD10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001DD14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001DD18: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8001DD1C: sw          $a0, -0x27E0($at)
    MEM_W(-0X27E0, ctx->r1) = ctx->r4;
    // 0x8001DD20: jr          $ra
    // 0x8001DD24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001DD24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800288C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800288C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800288C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800288C8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800288CC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800288D0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800288D4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800288D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800288DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800288E0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800288E4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800288E8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800288EC: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800288F0: nop

    // 0x800288F4: bc1f        L_80028910
    if (!c1cs) {
        // 0x800288F8: nop
    
            goto L_80028910;
    }
    // 0x800288F8: nop

    // 0x800288FC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80028900: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80028904: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80028908: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8002890C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80028910:
    // 0x80028910: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028914: lwc1        $f4, 0x1D10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1D10);
    // 0x80028918: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002891C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80028920: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80028924: jal         0x80013C48
    // 0x80028928: nop

    func_80013C48(rdram, ctx);
        goto after_0;
    // 0x80028928: nop

    after_0:
    // 0x8002892C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80028930: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80028934: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80028938: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8002893C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80028940: lwc1        $f6, 0x1D14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1D14);
    // 0x80028944: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80028948: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002894C: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80028950: div.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80028954: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80028958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002895C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80028960: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80028964: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80028968: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002896C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80028970: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80028974: div.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80028978: swc1        $f10, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f10.u32l;
    // 0x8002897C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80028980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80028984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80028988: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002898C: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80028990: swc1        $f8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f8.u32l;
    // 0x80028994: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80028998: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8002899C: swc1        $f18, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f18.u32l;
    // 0x800289A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800289A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800289A8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800289AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800289B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800289B4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800289B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800289BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800289C0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800289C4: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800289C8: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800289CC: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800289D0: add.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800289D4: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800289D8: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x800289DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800289E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800289E4: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800289E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800289EC: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800289F0: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800289F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800289F8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800289FC: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80028A00: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80028A04: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80028A08: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x80028A0C: b           L_80028A14
    // 0x80028A10: nop

        goto L_80028A14;
    // 0x80028A10: nop

L_80028A14:
    // 0x80028A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028A18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80028A1C: jr          $ra
    // 0x80028A20: nop

    return;
    // 0x80028A20: nop

;}
RECOMP_FUNC void func_8080027C_chwallsnakebaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800280: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800284: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800288: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080028C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800290: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800294: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800298: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080029C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808002A4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808002A8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808002AC: beq         $t6, $at, L_808002C0
    if (ctx->r14 == ctx->r1) {
        // 0x808002B0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808002C0;
    }
    // 0x808002B0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808002B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808002B8: bne         $t6, $at, L_808002C8
    if (ctx->r14 != ctx->r1) {
        // 0x808002BC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808002C8;
    }
    // 0x808002BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808002C0:
    // 0x808002C0: b           L_808002C8
    // 0x808002C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_808002C8;
    // 0x808002C4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_808002C8:
    // 0x808002C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002CC: beq         $v0, $at, L_808002E4
    if (ctx->r2 == ctx->r1) {
        // 0x808002D0: nop
    
            goto L_808002E4;
    }
    // 0x808002D0: nop

    // 0x808002D4: jal         0x801072A8
    // 0x808002D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_801072A8(rdram, ctx);
        goto after_0;
    // 0x808002D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x808002DC: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002E0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808002EC;
    }
    // 0x808002E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808002E4:
    // 0x808002E4: b           L_808002EC
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808002EC;
    // 0x808002E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808002EC:
    // 0x808002EC: jal         0x800DF744
    // 0x808002F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808002F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x808002F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808002F8: jal         0x800DF744
    // 0x808002FC: xori        $a1, $s0, 0x1
    ctx->r5 = ctx->r16 ^ 0X1;
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808002FC: xori        $a1, $s0, 0x1
    ctx->r5 = ctx->r16 ^ 0X1;
    after_2:
    // 0x80800300: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800304: jal         0x800DF744
    // 0x80800308: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800308: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8080030C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800310: jal         0x80101870
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800318: lw          $t7, 0x7C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X7C);
    // 0x8080031C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800320: bgezl       $t9, L_808004E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800324: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808004E0;
    }
    goto skip_0;
    // 0x80800324: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800328: lw          $v0, 0x64($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X64);
    // 0x8080032C: sll         $t1, $v0, 11
    ctx->r9 = S32(ctx->r2 << 11);
    // 0x80800330: bgezl       $t1, L_8080042C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800334: sll         $t2, $v0, 12
        ctx->r10 = S32(ctx->r2 << 12);
            goto L_8080042C;
    }
    goto skip_1;
    // 0x80800334: sll         $t2, $v0, 12
    ctx->r10 = S32(ctx->r2 << 12);
    skip_1:
    // 0x80800338: lbu         $t2, 0x65($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X65);
    // 0x8080033C: andi        $t5, $t2, 0xFFEF
    ctx->r13 = ctx->r10 & 0XFFEF;
    // 0x80800340: sb          $t5, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r13;
    // 0x80800344: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80800348: jal         0x80104130
    // 0x8080034C: sb          $t6, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r14;
    func_80104130(rdram, ctx);
        goto after_5;
    // 0x8080034C: sb          $t6, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r14;
    after_5:
    // 0x80800350: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x80800354: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080035C: jal         0x800DBEFC
    // 0x80800360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_6;
    // 0x80800360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800364: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1856, 0X75C) << 16);
    // 0x80800368: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1856, 0X750) << 16);
    // 0x8080036C: addiu       $s1, $s1, 0x750
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1856, 0X750));
    // 0x80800370: addiu       $s0, $s0, 0x75C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1856, 0X75C));
L_80800374:
    // 0x80800374: jal         0x800B53A4
    // 0x80800378: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800B53A4(rdram, ctx);
        goto after_7;
    // 0x80800378: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_7:
    // 0x8080037C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800380: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800384: jal         0x800BA670
    // 0x80800388: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    func_800BA670(rdram, ctx);
        goto after_8;
    // 0x80800388: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    after_8:
    // 0x8080038C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1856, 0X764) << 16);
    // 0x80800390: addiu       $t7, $t7, 0x764
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1856, 0X764));
    // 0x80800394: lw          $a3, 0x38($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X38);
    // 0x80800398: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080039C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003A4: jal         0x800BABB8
    // 0x808003A8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800BABB8(rdram, ctx);
        goto after_9;
    // 0x808003A8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x808003AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808003B0: jal         0x800BA22C
    // 0x808003B4: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x808003B4: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    after_10:
    // 0x808003B8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1856, 0X75A) << 16);
    // 0x808003BC: addiu       $t8, $t8, 0x75A
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1856, 0X75A));
    // 0x808003C0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808003C4: bne         $s1, $t8, L_80800374
    if (ctx->r17 != ctx->r24) {
        // 0x808003C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800374;
    }
    // 0x808003C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808003CC: jal         0x800B53A4
    // 0x808003D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B53A4(rdram, ctx);
        goto after_11;
    // 0x808003D0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_11:
    // 0x808003D4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1856, 0X720) << 16);
    // 0x808003D8: addiu       $t9, $t9, 0x720
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1856, 0X720));
    // 0x808003DC: lw          $a3, 0x38($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X38);
    // 0x808003E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808003E4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808003E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003F0: jal         0x800BABB8
    // 0x808003F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_12;
    // 0x808003F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x808003F8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1856, 0X78C) << 16);
    // 0x808003FC: addiu       $t0, $t0, 0x78C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1856, 0X78C));
    // 0x80800400: lw          $a3, 0x38($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X38);
    // 0x80800404: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080040C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800410: jal         0x800BABB8
    // 0x80800414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x80800414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080041C: jal         0x800BA22C
    // 0x80800420: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800BA22C(rdram, ctx);
        goto after_14;
    // 0x80800420: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x80800424: lw          $v0, 0x64($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X64);
    // 0x80800428: sll         $t2, $v0, 12
    ctx->r10 = S32(ctx->r2 << 12);
L_8080042C:
    // 0x8080042C: bgez        $t2, L_808004DC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800430: addiu       $s3, $sp, 0x54
        ctx->r19 = ADD32(ctx->r29, 0X54);
            goto L_808004DC;
    }
    // 0x80800430: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x80800434: jal         0x801072A8
    // 0x80800438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_801072A8(rdram, ctx);
        goto after_15;
    // 0x80800438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x8080043C: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x80800440: nop
    
            goto L_80800450;
    }
    // 0x80800440: nop

    // 0x80800444: lbu         $t3, 0x65($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X65);
    // 0x80800448: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x8080044C: sb          $t4, 0x65($s4)
    MEM_B(0X65, ctx->r20) = ctx->r12;
L_80800450:
    // 0x80800450: jal         0x80104130
    // 0x80800454: nop

    func_80104130(rdram, ctx);
        goto after_16;
    // 0x80800454: nop

    after_16:
    // 0x80800458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080045C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800460: jal         0x800DBEFC
    // 0x80800464: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800DBEFC(rdram, ctx);
        goto after_17;
    // 0x80800464: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_17:
    // 0x80800468: jal         0x8001211C
    // 0x8080046C: nop

    func_8001211C(rdram, ctx);
        goto after_18;
    // 0x8080046C: nop

    after_18:
    // 0x80800470: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x80800474: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800478: bnel        $t5, $at, L_808004E0
    if (ctx->r13 != ctx->r1) {
        // 0x8080047C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808004E0;
    }
    goto skip_2;
    // 0x8080047C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800480: jal         0x800B53A4
    // 0x80800484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_19;
    // 0x80800484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80800488: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1856, 0X69C) << 16);
    // 0x8080048C: lwc1        $f6, 0x69C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1856, 0X69C));
    // 0x80800490: lwc1        $f4, 0x38($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X38);
    // 0x80800494: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1856, 0X720) << 16);
    // 0x80800498: addiu       $t6, $t6, 0x720
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1856, 0X720));
    // 0x8080049C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808004A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808004B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004B4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808004B8: jal         0x800BABB8
    // 0x808004BC: nop

    func_800BABB8(rdram, ctx);
        goto after_20;
    // 0x808004BC: nop

    after_20:
    // 0x808004C0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1856, 0X798) << 16);
    // 0x808004C4: addiu       $a1, $a1, 0x798
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1856, 0X798));
    // 0x808004C8: jal         0x800BAB80
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BAB80(rdram, ctx);
        goto after_21;
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x800BA22C
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_22;
    // 0x808004D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
L_808004DC:
    // 0x808004DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808004E0:
    // 0x808004E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808004E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808004EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808004F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808004F4: jr          $ra
    // 0x808004F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808004F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800000_chmole_factory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1832, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1832, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1832, 0XC0));
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void _glidmake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088878: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x80088878);
    return;
    // 0x8008887C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D5950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5950: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D5954: lw          $t6, -0x4700($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4700);
    // 0x800D5958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D595C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5960: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800D5964: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5968: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D596C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D5970: jal         0x8001E210
    // 0x800D5974: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    rom_read_word(rdram, ctx);
        goto after_0;
    // 0x800D5974: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_0:
    // 0x800D5978: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D597C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800D5980: lw          $t7, -0x4700($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4700);
    // 0x800D5984: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5988: addiu       $a1, $a1, -0x4BBC
    ctx->r5 = ADD32(ctx->r5, -0X4BBC);
    // 0x800D598C: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    // 0x800D5990: jal         0x8001E210
    // 0x800D5994: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800D5994: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x800D5998: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D599C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800D59A0: lw          $t0, -0x4BC0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4BC0);
    // 0x800D59A4: lw          $t8, -0x4BBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BBC);
    // 0x800D59A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D59AC: srl         $t1, $t0, 6
    ctx->r9 = S32(U32(ctx->r8) >> 6);
    // 0x800D59B0: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x800D59B4: subu        $v0, $t9, $t1
    ctx->r2 = SUB32(ctx->r25, ctx->r9);
    // 0x800D59B8: jr          $ra
    // 0x800D59BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D59BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80115460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115460: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80115464: jr          $ra
    // 0x80115468: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    return;
    // 0x80115468: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_8009EC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009EC0C: addiu       $a2, $a2, 0x7040
    ctx->r6 = ADD32(ctx->r6, 0X7040);
    // 0x8009EC10: lh          $v1, 0x10($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X10);
    // 0x8009EC14: beql        $v1, $zero, L_8009EC34
    if (ctx->r3 == 0) {
        // 0x8009EC18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009EC34;
    }
    goto skip_0;
    // 0x8009EC18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8009EC1C: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x8009EC20: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    // 0x8009EC24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009EC28: jr          $ra
    // 0x8009EC2C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    return;
    // 0x8009EC2C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8009EC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009EC34:
    // 0x8009EC34: jr          $ra
    // 0x8009EC38: nop

    return;
    // 0x8009EC38: nop

;}
RECOMP_FUNC void func_80800B10_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B10: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800B14: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800B18: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800B1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B20: jal         0x80100094
    // 0x80800B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B28: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1628, 0X1508) << 16);
    // 0x80800B2C: addiu       $t6, $t6, 0x1508
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1628, 0X1508));
    // 0x80800B30: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800B34: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800B38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800B48: jal         0x800BBCB8
    // 0x80800B4C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800B4C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800B50: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B54: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B58: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800B5C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800B60: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x80800B64: beq         $at, $zero, L_80800DFC
    if (ctx->r1 == 0) {
        // 0x80800B68: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800DFC;
    }
    // 0x80800B68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800B6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X137C) << 16);
    // 0x80800B70: addu        $at, $at, $t9
    gpr jr_addend_80800B78 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800B74: lw          $t9, 0x137C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1628, 0X137C));
    // 0x80800B78: jr          $t9
    // 0x80800B7C: nop

    switch (jr_addend_80800B78 >> 2) {
        case 0: goto L_80800DEC; break;
        case 1: goto L_80800DFC; break;
        case 2: goto L_80800BA4; break;
        case 3: goto L_80800B80; break;
        case 4: goto L_80800C4C; break;
        case 5: goto L_80800D48; break;
        case 6: goto L_80800DD8; break;
        default: switch_error(__func__, 0x80800B78, 0x8080137C);
    }
    // 0x80800B7C: nop

L_80800B80:
    // 0x80800B80: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B88: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80800B8C: bgezl       $t2, L_80800E00
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800B90: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800E00;
    }
    goto skip_0;
    // 0x80800B90: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800B94: jal         0x80101FDC
    // 0x80800B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800B9C: b           L_80800E00
    // 0x80800BA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800E00;
    // 0x80800BA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800BA4:
    // 0x80800BA4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800BA8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800BAC: jal         0x800F1DF4
    // 0x80800BB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x80800BB0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800BB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800BB8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800BBC: jal         0x800EFB8C
    // 0x80800BC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800EFB8C(rdram, ctx);
        goto after_4;
    // 0x80800BC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800BC4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800BC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BCC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80800BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BD4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BDC: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80800BE0: jal         0x80801258
    // 0x80800BE4: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_80801258_chglowbo(rdram, ctx);
        goto after_5;
    // 0x80800BE4: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80800BE8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800BEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800BF0: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800BF4: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800BF8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800BFC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800C00: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800C04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C08: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x80800C0C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80800C10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X1398) << 16);
    // 0x80800C14: lwc1        $f18, 0x1398($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X1398));
    // 0x80800C18: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80800C1C: addiu       $a1, $zero, 0x4DE
    ctx->r5 = ADD32(0, 0X4DE);
    // 0x80800C20: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C24: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    // 0x80800C28: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80800C2C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80800C30: jal         0x800C9C70
    // 0x80800C34: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800C9C70(rdram, ctx);
        goto after_6;
    // 0x80800C34: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_6:
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C3C: jal         0x80101FDC
    // 0x80800C40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800C40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80800C44: b           L_80800E00
    // 0x80800C48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800E00;
    // 0x80800C48: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800C4C:
    // 0x80800C4C: jal         0x80801258
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801258_chglowbo(rdram, ctx);
        goto after_8;
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800C54: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800C58: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800C5C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800C60: nop

    // 0x80800C64: bc1t        L_80800C84
    if (c1cs) {
        // 0x80800C68: nop
    
            goto L_80800C84;
    }
    // 0x80800C68: nop

    // 0x80800C6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800C70: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800C74: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800C78: nop

    // 0x80800C7C: bc1fl       L_80800CE8
    if (!c1cs) {
        // 0x80800C80: lw          $t3, 0x64($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X64);
            goto L_80800CE8;
    }
    goto skip_1;
    // 0x80800C80: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    skip_1:
L_80800C84:
    // 0x80800C84: jal         0x800D8FF8
    // 0x80800C88: nop

    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x80800C88: nop

    after_9:
    // 0x80800C8C: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800C90: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800C94: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x80800C98: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800C9C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800CA0: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80800CA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800CA8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800CAC: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800CB0: jal         0x800EFCD8
    // 0x80800CB4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_800EFCD8(rdram, ctx);
        goto after_10;
    // 0x80800CB4: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_10:
    // 0x80800CB8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800CBC: jal         0x800EF04C
    // 0x80800CC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800CC0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80800CC4: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800CC8: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800CCC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800CD0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800CD4: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800CD8: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800CDC: b           L_80800D24
    // 0x80800CE0: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_80800D24;
    // 0x80800CE0: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x80800CE4: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
L_80800CE8:
    // 0x80800CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CEC: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800CF0: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800CF4: bgezl       $t5, L_80800D10
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800CF8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800D10;
    }
    goto skip_2;
    // 0x80800CF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_2:
    // 0x80800CFC: jal         0x80101FDC
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800D04: b           L_80800D28
    // 0x80800D08: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
        goto L_80800D28;
    // 0x80800D08: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800D0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800D10:
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D14: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800D18: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800D1C: jal         0x80101FDC
    // 0x80800D20: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800D20: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_13:
L_80800D24:
    // 0x80800D24: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
L_80800D28:
    // 0x80800D28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D2C: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D34: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800D38: jal         0x80800000
    // 0x80800D3C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_80800000_chglowbo(rdram, ctx);
        goto after_14;
    // 0x80800D3C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_14:
    // 0x80800D40: b           L_80800E00
    // 0x80800D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800E00;
    // 0x80800D44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800D48:
    // 0x80800D48: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x80800D4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D54: jal         0x800C8FB0
    // 0x80800D58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_15;
    // 0x80800D58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x80800D5C: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    // 0x80800D60: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80800D64: bne         $at, $zero, L_80800D70
    if (ctx->r1 != 0) {
        // 0x80800D68: addiu       $t6, $v0, -0xF
        ctx->r14 = ADD32(ctx->r2, -0XF);
            goto L_80800D70;
    }
    // 0x80800D68: addiu       $t6, $v0, -0xF
    ctx->r14 = ADD32(ctx->r2, -0XF);
    // 0x80800D6C: sb          $t6, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r14;
L_80800D70:
    // 0x80800D70: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800D74: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800D78: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80800D7C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800D80: nop

    // 0x80800D84: bc1fl       L_80800DA4
    if (!c1cs) {
        // 0x80800D88: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80800DA4;
    }
    goto skip_3;
    // 0x80800D88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x80800D8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D90: nop

    // 0x80800D94: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800D98: b           L_80800DFC
    // 0x80800D9C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80800DFC;
    // 0x80800D9C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800DA0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80800DA4:
    // 0x80800DA4: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: bc1f        L_80800DC8
    if (!c1cs) {
        // 0x80800DB0: nop
    
            goto L_80800DC8;
    }
    // 0x80800DB0: nop

    // 0x80800DB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800DB8: nop

    // 0x80800DBC: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800DC0: b           L_80800DFC
    // 0x80800DC4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80800DFC;
    // 0x80800DC4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80800DC8:
    // 0x80800DC8: jal         0x80101FDC
    // 0x80800DCC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x80800DCC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
    // 0x80800DD0: b           L_80800E00
    // 0x80800DD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800E00;
    // 0x80800DD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800DD8:
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: jal         0x80101FDC
    // 0x80800DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x80800DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800DE4: b           L_80800E00
    // 0x80800DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800E00;
    // 0x80800DE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800DEC:
    // 0x80800DEC: jal         0x800C8B84
    // 0x80800DF0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    func_800C8B84(rdram, ctx);
        goto after_18;
    // 0x80800DF0: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_18:
    // 0x80800DF4: jal         0x800FFAB0
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_19;
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80800DFC:
    // 0x80800DFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800E00:
    // 0x80800E00: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800E04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800E08: jr          $ra
    // 0x80800E0C: nop

    return;
    // 0x80800E0C: nop

;}
RECOMP_FUNC void chfaircoin_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2128, 0X15C) << 16);
    // 0x80800130: jr          $ra
    // 0x80800134: addiu       $v0, $v0, 0x15C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2128, 0X15C));
    return;
    // 0x80800134: addiu       $v0, $v0, 0x15C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2128, 0X15C));
    // 0x80800138: nop

    // 0x8080013C: nop

;}
RECOMP_FUNC void func_8080083C_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080083C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800844: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800848: addiu       $a0, $zero, 0x3FC
    ctx->r4 = ADD32(0, 0X3FC);
    // 0x8080084C: jal         0x80089C30
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800854: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800858: jal         0x800EE7F8
    // 0x8080085C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080085C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80800860: jal         0x800F54E4
    // 0x80800864: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800864: nop

    after_2:
    // 0x80800868: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080086C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800870: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800874: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800878: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8080087C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800880: jal         0x800F4EC8
    // 0x80800884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F4EC8(rdram, ctx);
        goto after_3;
    // 0x80800884: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080088C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
RECOMP_FUNC void func_80801614_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080161C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801624: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80801628: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x8080162C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801630: jal         0x80091290
    // 0x80801634: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    func_80091290(rdram, ctx);
        goto after_0;
    // 0x80801634: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_0:
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: jal         0x8008CB10
    // 0x80801640: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x80801640: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x80801644: beq         $v0, $zero, L_80801654
    if (ctx->r2 == 0) {
        // 0x80801648: nop
    
            goto L_80801654;
    }
    // 0x80801648: nop

    // 0x8080164C: jal         0x800951B4
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x80801650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80801654:
    // 0x80801654: jal         0x8008CAEC
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_3;
    // 0x80801658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080165C: beq         $v0, $zero, L_8080166C
    if (ctx->r2 == 0) {
        // 0x80801660: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080166C;
    }
    // 0x80801660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801664: addiu       $t6, $zero, 0x154
    ctx->r14 = ADD32(0, 0X154);
    // 0x80801668: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_8080166C:
    // 0x8080166C: jal         0x8009E5C8
    // 0x80801670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80801670: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80801674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080167C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801680: jr          $ra
    // 0x80801684: nop

    return;
    // 0x80801684: nop

;}
RECOMP_FUNC void func_8010C550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C550: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010C554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C558: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x8010C55C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010C560: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010C564: srl         $t7, $t6, 25
    ctx->r15 = S32(U32(ctx->r14) >> 25);
    // 0x8010C568: bne         $t7, $zero, L_8010C578
    if (ctx->r15 != 0) {
        // 0x8010C56C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8010C578;
    }
    // 0x8010C56C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8010C570: b           L_8010C5B0
    // 0x8010C574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010C5B0;
    // 0x8010C574: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8010C578:
    // 0x8010C578: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8010C57C: jal         0x800F5A00
    // 0x8010C580: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x8010C580: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010C584: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8010C588: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8010C58C: lw          $v0, 0x70($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X70);
    // 0x8010C590: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x8010C594: srl         $t8, $a2, 26
    ctx->r24 = S32(U32(ctx->r6) >> 26);
    // 0x8010C598: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x8010C59C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8010C5A0: jal         0x800CC338
    // 0x8010C5A4: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    func_800CC338(rdram, ctx);
        goto after_1;
    // 0x8010C5A4: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    after_1:
    // 0x8010C5A8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8010C5AC: sltu        $v0, $zero, $t9
    ctx->r2 = 0 < ctx->r25 ? 1 : 0;
L_8010C5B0:
    // 0x8010C5B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C5B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010C5B8: jr          $ra
    // 0x8010C5BC: nop

    return;
    // 0x8010C5BC: nop

;}
RECOMP_FUNC void func_800A3298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A329C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A32A0: jal         0x800964DC
    // 0x800A32A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x800A32A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A32A8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800A32AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A32B0: lw          $t7, 0xA0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XA0);
    // 0x800A32B4: lwc1        $f4, 0x48($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X48);
    // 0x800A32B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A32BC: jr          $ra
    // 0x800A32C0: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x800A32C0: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void func_80800048_ncbapan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800054: jal         0x801107F0
    // 0x80800058: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80800058: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8080005C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800060: jal         0x80800028
    // 0x80800064: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80800028_ncbapan(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800068: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080006C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800070: jal         0x800EFB24
    // 0x80800074: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80800078: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080007C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800080: jal         0x800F1EA4
    // 0x80800084: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    func_800F1EA4(rdram, ctx);
        goto after_3;
    // 0x80800084: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_3:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_80800680_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800684: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800688: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080068C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800690: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800694: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800698: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080069C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006A0: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x808006A4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808006A8: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808006AC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808006B0: bc1f        L_808006EC
    if (!c1cs) {
        // 0x808006B4: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808006EC;
    }
    // 0x808006B4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808006B8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808006BC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x808006C0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808006C4: nop

    // 0x808006C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_808006CC:
    // 0x808006CC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808006D0: jal         0x800849F0
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808006D8: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x808006DC: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x808006E0: nop

    // 0x808006E4: bc1tl       L_808006CC
    if (c1cs) {
        // 0x808006E8: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_808006CC;
    }
    goto skip_0;
    // 0x808006E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_808006EC:
    // 0x808006EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808006F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808006F4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808006F8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808006FC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800700: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800704: jr          $ra
    // 0x80800708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800708: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chblackeye_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1796, 0X104C) << 16);
    // 0x80800DB8: jr          $ra
    // 0x80800DBC: addiu       $v0, $v0, 0x104C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1796, 0X104C));
    return;
    // 0x80800DBC: addiu       $v0, $v0, 0x104C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1796, 0X104C));
;}
