#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chbouncycastle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1000, 0X930) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X930));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x930
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1000, 0X930));
;}
RECOMP_FUNC void _ncba1p_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089430: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089430);
    return;
    // 0x80089434: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsdronebubbled_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: jr          $ra
    // 0x808002D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808002D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808002D4: nop

    // 0x808002D8: nop

    // 0x808002DC: nop

;}
RECOMP_FUNC void func_800904F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800904F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800904F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800904FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80090500: jal         0x800F54E4
    // 0x80090504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090504: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80090508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009050C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80090510: jal         0x800F7BC8
    // 0x80090514: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800F7BC8(rdram, ctx);
        goto after_1;
    // 0x80090514: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80090518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009051C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090520: jr          $ra
    // 0x80090524: nop

    return;
    // 0x80090524: nop

;}
RECOMP_FUNC void func_800260F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260F4: jr          $ra
    // 0x800260F8: nop

    return;
    // 0x800260F8: nop

;}
RECOMP_FUNC void bsvan_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808002E4: jal         0x800B5BE4
    // 0x808002E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808002E8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x808002EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808002F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002F4: jal         0x8009C128
    // 0x808002F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808002F8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808002FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(427, 0X1B90) << 16);
    // 0x80800300: addiu       $t6, $t6, 0x1B90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(427, 0X1B90));
    // 0x80800304: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800308: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080030C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800314: jal         0x800BABB8
    // 0x80800318: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800318: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8080031C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800320: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800324: jr          $ra
    // 0x80800328: nop

    return;
    // 0x80800328: nop

;}
RECOMP_FUNC void func_800EF5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF5A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800EF5A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EF5A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800EF5AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EF5B0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800EF5B4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800EF5B8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800EF5BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EF5C0: jal         0x800137F4
    // 0x800EF5C4: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EF5C4: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x800EF5C8: jal         0x80013788
    // 0x800EF5CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EF5CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x800EF5D0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800EF5D4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EF5D8: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800EF5DC: nop

    // 0x800EF5E0: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF5E4: nop

    // 0x800EF5E8: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800EF5EC: nop

    // 0x800EF5F0: mul.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF5F4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF5F8: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EF5FC: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800EF600: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800EF604: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800EF608: jal         0x800137F4
    // 0x800EF60C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    func_800137F4(rdram, ctx);
        goto after_2;
    // 0x800EF60C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x800EF610: jal         0x80013788
    // 0x800EF614: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_3;
    // 0x800EF614: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_3:
    // 0x800EF618: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EF61C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800EF620: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800EF624: nop

    // 0x800EF628: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF62C: nop

    // 0x800EF630: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800EF634: nop

    // 0x800EF638: mul.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF63C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF640: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800EF644: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800EF648: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800EF64C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800EF650: jal         0x800137F4
    // 0x800EF654: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    func_800137F4(rdram, ctx);
        goto after_4;
    // 0x800EF654: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    after_4:
    // 0x800EF658: jal         0x80013788
    // 0x800EF65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_80013788(rdram, ctx);
        goto after_5;
    // 0x800EF65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x800EF660: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EF664: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF668: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF66C: nop

    // 0x800EF670: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x800EF674: nop

    // 0x800EF678: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EF67C: nop

    // 0x800EF680: mul.s       $f18, $f2, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EF684: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EF688: swc1        $f14, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f14.u32l;
    // 0x800EF68C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800EF690: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800EF694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EF698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800EF69C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EF6A0: jr          $ra
    // 0x800EF6A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800EF6A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8009CFE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CFEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009CFF0: jal         0x8009EF28
    // 0x8009CFF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x8009CFF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009CFF8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8009CFFC: jal         0x800F2100
    // 0x8009D000: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8009D000: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8009D004: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D008: lwc1        $f4, 0x5350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5350);
    // 0x8009D00C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009D010: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009D014: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8009D018: nop

    // 0x8009D01C: bc1fl       L_8009D050
    if (!c1cs) {
        // 0x8009D020: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8009D050;
    }
    goto skip_0;
    // 0x8009D020: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8009D024: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009D028: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8009D02C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009D030: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8009D034: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009D038: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8009D03C: jal         0x800F1344
    // 0x8009D040: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1344(rdram, ctx);
        goto after_2;
    // 0x8009D040: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8009D044: b           L_8009D054
    // 0x8009D048: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8009D054;
    // 0x8009D048: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8009D04C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8009D050:
    // 0x8009D050: nop

L_8009D054:
    // 0x8009D054: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009D058: jal         0x8009C990
    // 0x8009D05C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_3;
    // 0x8009D05C: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8009D060: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009D064: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8009D068: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8009D06C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8009D070: jal         0x8009C914
    // 0x8009D074: nop

    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x8009D074: nop

    after_4:
    // 0x8009D078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D07C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D080: jr          $ra
    // 0x8009D084: nop

    return;
    // 0x8009D084: nop

;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835B8: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835B8);
    return;
    // 0x800835BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80101E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101E4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80101E50: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80101E54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80101E58: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80101E5C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80101E60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80101E64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80101E68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80101E6C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80101E70: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80101E74: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80101E78: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80101E7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80101E80: bc1tl       L_80101EC8
    if (c1cs) {
        // 0x80101E84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80101EC8;
    }
    goto skip_0;
    // 0x80101E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80101E88: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80101E8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80101E90:
    // 0x80101E90: jal         0x80101E14
    // 0x80101E94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80101E94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80101E98: beql        $v0, $zero, L_80101EAC
    if (ctx->r2 == 0) {
        // 0x80101E9C: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80101EAC;
    }
    goto skip_1;
    // 0x80101E9C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80101EA0: b           L_80101EC8
    // 0x80101EA4: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
        goto L_80101EC8;
    // 0x80101EA4: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x80101EA8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_80101EAC:
    // 0x80101EAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80101EB0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80101EB4: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80101EB8: nop

    // 0x80101EBC: bc1fl       L_80101E90
    if (!c1cs) {
        // 0x80101EC0: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80101E90;
    }
    goto skip_2;
    // 0x80101EC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x80101EC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101EC8:
    // 0x80101EC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80101ECC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80101ED0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80101ED4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80101ED8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80101EDC: jr          $ra
    // 0x80101EE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80101EE0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855A0: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855A0);
    return;
    // 0x800855A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800BF58C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF58C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BF590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF594: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BF598: addiu       $s0, $s0, -0x7A50
    ctx->r16 = ADD32(ctx->r16, -0X7A50);
    // 0x800BF59C: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x800BF5A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BF5A4: beql        $a0, $zero, L_800BF5BC
    if (ctx->r4 == 0) {
        // 0x800BF5A8: lw          $a0, 0x17C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X17C);
            goto L_800BF5BC;
    }
    goto skip_0;
    // 0x800BF5A8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    skip_0:
    // 0x800BF5AC: jal         0x800DC060
    // 0x800BF5B0: nop

    func_800DC060(rdram, ctx);
        goto after_0;
    // 0x800BF5B0: nop

    after_0:
    // 0x800BF5B4: sw          $v0, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->r2;
    // 0x800BF5B8: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
L_800BF5BC:
    // 0x800BF5BC: beql        $a0, $zero, L_800BF5D4
    if (ctx->r4 == 0) {
        // 0x800BF5C0: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_800BF5D4;
    }
    goto skip_1;
    // 0x800BF5C0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800BF5C4: jal         0x8001BAFC
    // 0x800BF5C8: nop

    defrag(rdram, ctx);
        goto after_1;
    // 0x800BF5C8: nop

    after_1:
    // 0x800BF5CC: sw          $v0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r2;
    // 0x800BF5D0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_800BF5D4:
    // 0x800BF5D4: beql        $a0, $zero, L_800BF5EC
    if (ctx->r4 == 0) {
        // 0x800BF5D8: lw          $a0, 0x30($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X30);
            goto L_800BF5EC;
    }
    goto skip_2;
    // 0x800BF5D8: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    skip_2:
    // 0x800BF5DC: jal         0x800EE5D8
    // 0x800BF5E0: nop

    func_800EE5D8(rdram, ctx);
        goto after_2;
    // 0x800BF5E0: nop

    after_2:
    // 0x800BF5E4: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800BF5E8: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
L_800BF5EC:
    // 0x800BF5EC: beql        $a0, $zero, L_800BF604
    if (ctx->r4 == 0) {
        // 0x800BF5F0: lw          $a0, 0x1C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X1C);
            goto L_800BF604;
    }
    goto skip_3;
    // 0x800BF5F0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    skip_3:
    // 0x800BF5F4: jal         0x800EE5D8
    // 0x800BF5F8: nop

    func_800EE5D8(rdram, ctx);
        goto after_3;
    // 0x800BF5F8: nop

    after_3:
    // 0x800BF5FC: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x800BF600: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
L_800BF604:
    // 0x800BF604: beql        $a0, $zero, L_800BF61C
    if (ctx->r4 == 0) {
        // 0x800BF608: lw          $a0, 0x48($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X48);
            goto L_800BF61C;
    }
    goto skip_4;
    // 0x800BF608: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    skip_4:
    // 0x800BF60C: jal         0x800F9F90
    // 0x800BF610: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_800F9F90(rdram, ctx);
        goto after_4;
    // 0x800BF610: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x800BF614: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800BF618: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
L_800BF61C:
    // 0x800BF61C: beql        $a0, $zero, L_800BF634
    if (ctx->r4 == 0) {
        // 0x800BF620: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_800BF634;
    }
    goto skip_5;
    // 0x800BF620: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_5:
    // 0x800BF624: jal         0x800F9F90
    // 0x800BF628: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    func_800F9F90(rdram, ctx);
        goto after_5;
    // 0x800BF628: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    after_5:
    // 0x800BF62C: sw          $v0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r2;
    // 0x800BF630: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_800BF634:
    // 0x800BF634: beql        $a0, $zero, L_800BF64C
    if (ctx->r4 == 0) {
        // 0x800BF638: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_800BF64C;
    }
    goto skip_6;
    // 0x800BF638: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_6:
    // 0x800BF63C: jal         0x8001BAFC
    // 0x800BF640: nop

    defrag(rdram, ctx);
        goto after_6;
    // 0x800BF640: nop

    after_6:
    // 0x800BF644: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800BF648: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_800BF64C:
    // 0x800BF64C: beql        $a0, $zero, L_800BF664
    if (ctx->r4 == 0) {
        // 0x800BF650: lbu         $t6, 0x77($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X77);
            goto L_800BF664;
    }
    goto skip_7;
    // 0x800BF650: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    skip_7:
    // 0x800BF654: jal         0x8001BAFC
    // 0x800BF658: nop

    defrag(rdram, ctx);
        goto after_7;
    // 0x800BF658: nop

    after_7:
    // 0x800BF65C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x800BF660: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
L_800BF664:
    // 0x800BF664: beql        $t6, $zero, L_800BF67C
    if (ctx->r14 == 0) {
        // 0x800BF668: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BF67C;
    }
    goto skip_8;
    // 0x800BF668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x800BF66C: jal         0x8001BAFC
    // 0x800BF670: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    defrag(rdram, ctx);
        goto after_8;
    // 0x800BF670: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_8:
    // 0x800BF674: sw          $v0, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r2;
    // 0x800BF678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BF67C:
    // 0x800BF67C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BF684: jr          $ra
    // 0x800BF688: nop

    return;
    // 0x800BF688: nop

;}
RECOMP_FUNC void func_808001A0_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x808001B8: jal         0x800EFD24
    // 0x808001BC: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808001BC: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x808001C0: jal         0x800DA298
    // 0x808001C4: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808001C4: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_1:
    // 0x808001C8: bnel        $v0, $zero, L_808001E4
    if (ctx->r2 != 0) {
        // 0x808001CC: lbu         $t6, 0x79($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X79);
            goto L_808001E4;
    }
    goto skip_0;
    // 0x808001CC: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    skip_0:
    // 0x808001D0: jal         0x80088848
    // 0x808001D4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808001D4: nop

    after_2:
    // 0x808001D8: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800200;
    }
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
L_808001E4:
    // 0x808001E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001EC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x808001F0: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x808001F4: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    // 0x808001F8: b           L_80800208
    // 0x808001FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80800208;
    // 0x808001FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800200:
    // 0x80800200: jal         0x8080000C
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080000C_chlagoonufoint(rdram, ctx);
        goto after_3;
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800208:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80100094
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080021C: jal         0x8008A2A0
    // 0x80800220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800224: jal         0x8008A2F8
    // 0x80800228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void func_808008C0_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C8: jal         0x808008E0
    // 0x808008CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808008E0_chclinker(rdram, ctx);
        goto after_0;
    // 0x808008CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x808008D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008D8: jr          $ra
    // 0x808008DC: nop

    return;
    // 0x808008DC: nop

;}
RECOMP_FUNC void func_80800BD0_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BDC: jal         0x80082840
    // 0x80800BE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BE0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800BE4: jal         0x80084600
    // 0x80800BE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800BE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BEC: beq         $v0, $zero, L_80800BF8
    if (ctx->r2 == 0) {
        // 0x80800BF0: addiu       $t6, $zero, 0x85
        ctx->r14 = ADD32(0, 0X85);
            goto L_80800BF8;
    }
    // 0x80800BF0: addiu       $t6, $zero, 0x85
    ctx->r14 = ADD32(0, 0X85);
    // 0x80800BF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800BF8:
    // 0x80800BF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BFC: jal         0x8009E5C8
    // 0x80800C00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800C00: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800C04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C0C: jr          $ra
    // 0x80800C10: nop

    return;
    // 0x80800C10: nop

;}
RECOMP_FUNC void __baanim_update_scaleToVerticalVelocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C37C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008C380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008C384: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8008C388: jal         0x8009BB50
    // 0x8008C38C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_0;
    // 0x8008C38C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8008C390: jal         0x800F2100
    // 0x8008C394: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8008C394: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8008C398: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008C39C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8008C3A0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8008C3A4: lwc1        $f14, 0x24($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8008C3A8: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x8008C3AC: lw          $a3, 0x2C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2C);
    // 0x8008C3B0: jal         0x800F1198
    // 0x8008C3B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1198(rdram, ctx);
        goto after_2;
    // 0x8008C3B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8008C3B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8008C3BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8008C3C0: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8008C3C4: jal         0x800F0D50
    // 0x8008C3C8: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8008C3C8: lw          $a2, 0x20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X20);
    after_3:
    // 0x8008C3CC: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8008C3D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008C3D4: jal         0x8008B1BC
    // 0x8008C3D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x8008C3D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x8008C3DC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008C3E0: jal         0x8008ADE4
    // 0x8008C3E4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_8008ADE4(rdram, ctx);
        goto after_5;
    // 0x8008C3E4: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_5:
    // 0x8008C3E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008C3EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008C3F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008C3F4: jr          $ra
    // 0x8008C3F8: nop

    return;
    // 0x8008C3F8: nop

;}
RECOMP_FUNC void func_80801AE8_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801AEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801AF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801AF4: jal         0x80100094
    // 0x80801AF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801AF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801AFC: jal         0x800C8A98
    // 0x80801B00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80801B00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80801B04: jal         0x800C8A98
    // 0x80801B08: sw          $v0, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r2;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80801B08: sw          $v0, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r2;
    after_2:
    // 0x80801B0C: sw          $v0, 0x34C($s0)
    MEM_W(0X34C, ctx->r16) = ctx->r2;
    // 0x80801B10: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    // 0x80801B14: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80801B18: jal         0x800C8E54
    // 0x80801B1C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800C8E54(rdram, ctx);
        goto after_3;
    // 0x80801B1C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_3:
    // 0x80801B20: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801B24: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80801B28: jal         0x800C8E54
    // 0x80801B2C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800C8E54(rdram, ctx);
        goto after_4;
    // 0x80801B2C: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_4:
    // 0x80801B30: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    // 0x80801B34: jal         0x800C8FE0
    // 0x80801B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_5;
    // 0x80801B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801B3C: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801B40: jal         0x800C8FE0
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_6;
    // 0x80801B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80801B48: lw          $a0, 0x348($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X348);
    // 0x80801B4C: jal         0x800C8F64
    // 0x80801B50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_7;
    // 0x80801B50: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80801B54: lw          $a0, 0x34C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34C);
    // 0x80801B58: jal         0x800C8F64
    // 0x80801B5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_8;
    // 0x80801B5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80801B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B6C: jr          $ra
    // 0x80801B70: nop

    return;
    // 0x80801B70: nop

;}
RECOMP_FUNC void func_800D91B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D91B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D91BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D91C0: jal         0x800D8FF8
    // 0x800D91C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800D91C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D91C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D91CC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D91D0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800D91D4: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800D91D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D91DC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800D91E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D91E4: jr          $ra
    // 0x800D91E8: nop

    return;
    // 0x800D91E8: nop

;}
RECOMP_FUNC void func_80800078_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080007C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800084: beq         $a0, $zero, L_808000D0
    if (ctx->r4 == 0) {
        // 0x80800088: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808000D0;
    }
    // 0x80800088: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080008C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2204, 0X25CC) << 16);
    // 0x80800090: addiu       $a1, $a1, 0x25CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X25CC));
    // 0x80800094: jal         0x800C4AF0
    // 0x80800098: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800C4AF0(rdram, ctx);
        goto after_0;
    // 0x80800098: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080009C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808000A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000AC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808000B0: nop

    // 0x808000B4: bc1tl       L_80800124
    if (c1cs) {
        // 0x808000B8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800124;
    }
    goto skip_0;
    // 0x808000B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x808000BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000C0: jal         0x800E1610
    // 0x808000C4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x808000C4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_1:
    // 0x808000C8: b           L_80800124
    // 0x808000CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
        goto L_80800124;
    // 0x808000CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808000D0:
    // 0x808000D0: jal         0x800F54E4
    // 0x808000D4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000D4: nop

    after_2:
    // 0x808000D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000DC: jal         0x800F5A00
    // 0x808000E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808000E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x808000E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2204, 0X25CC) << 16);
    // 0x808000E8: addiu       $a1, $a1, 0x25CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X25CC));
    // 0x808000EC: jal         0x800C4AF0
    // 0x808000F0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800C4AF0(rdram, ctx);
        goto after_4;
    // 0x808000F0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x808000F4: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808000F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800100: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800104: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800108: nop

    // 0x8080010C: bc1tl       L_80800124
    if (c1cs) {
        // 0x80800110: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800124;
    }
    goto skip_1;
    // 0x80800110: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_1:
    // 0x80800114: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800118: jal         0x800E1610
    // 0x8080011C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    func_800E1610(rdram, ctx);
        goto after_5;
    // 0x8080011C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x80800120: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800124:
    // 0x80800124: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080012C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80800130: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800134: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800138: jal         0x800187B4
    // 0x8080013C: nop

    func_800187B4(rdram, ctx);
        goto after_6;
    // 0x8080013C: nop

    after_6:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void _chdinofamilysick_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876F8: syscall     610
    recomp_syscall_handler(rdram, ctx, 0x800876F8);
    return;
    // 0x800876FC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bskazstill_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080070C: jal         0x8008CAEC
    // 0x80800710: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80800710: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800714: beq         $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x80800718: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800720;
    }
    // 0x80800718: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080071C: addiu       $a1, $zero, 0xBB
    ctx->r5 = ADD32(0, 0XBB);
L_80800720:
    // 0x80800720: jal         0x808001A4
    // 0x80800724: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808001A4_bskazstill(rdram, ctx);
        goto after_1;
    // 0x80800724: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800728: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080072C: jal         0x8009E5C8
    // 0x80800730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_800D8988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D898C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D8990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8994: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D8998: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D899C: lh          $a1, 0x1A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X1A);
    // 0x800D89A0: jal         0x800B301C
    // 0x800D89A4: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800D89A4: lw          $a0, -0x3FE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3FE0);
    after_0:
    // 0x800D89A8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800D89AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D89B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D89B4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800D89B8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800D89BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D89C0: jr          $ra
    // 0x800D89C4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    return;
    // 0x800D89C4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
;}
RECOMP_FUNC void func_8008DAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DAE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008DAEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DAF0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8008DAF4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008DAF8: jal         0x8009C128
    // 0x8008DAFC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008DAFC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8008DB00: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8008DB04: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8008DB08: jal         0x800F1E6C
    // 0x8008DB0C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F1E6C(rdram, ctx);
        goto after_1;
    // 0x8008DB0C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8008DB10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DB14: lwc1        $f6, 0x4AD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4AD8);
    // 0x8008DB18: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8008DB1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008DB20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008DB24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008DB28: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8008DB2C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8008DB30: nop

    // 0x8008DB34: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008DB38: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8008DB3C: nop

    // 0x8008DB40: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8008DB44: beql        $v0, $zero, L_8008DB94
    if (ctx->r2 == 0) {
        // 0x8008DB48: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_8008DB94;
    }
    goto skip_0;
    // 0x8008DB48: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8008DB4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008DB50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008DB54: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8008DB58: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8008DB5C: nop

    // 0x8008DB60: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008DB64: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8008DB68: nop

    // 0x8008DB6C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8008DB70: bne         $v0, $zero, L_8008DB88
    if (ctx->r2 != 0) {
        // 0x8008DB74: nop
    
            goto L_8008DB88;
    }
    // 0x8008DB74: nop

    // 0x8008DB78: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8008DB7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DB80: b           L_8008DBA0
    // 0x8008DB84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8008DBA0;
    // 0x8008DB84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_8008DB88:
    // 0x8008DB88: b           L_8008DBA0
    // 0x8008DB8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8008DBA0;
    // 0x8008DB8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8008DB90: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_8008DB94:
    // 0x8008DB94: nop

    // 0x8008DB98: bltz        $v0, L_8008DB88
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008DB9C: nop
    
            goto L_8008DB88;
    }
    // 0x8008DB9C: nop

L_8008DBA0:
    // 0x8008DBA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8008DBA4: jal         0x80090010
    // 0x8008DBA8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    func_80090010(rdram, ctx);
        goto after_2;
    // 0x8008DBA8: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    after_2:
    // 0x8008DBAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DBB0: lwc1        $f16, 0x4ADC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4ADC);
    // 0x8008DBB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008DBB8: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8008DBBC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8008DBC0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8008DBC4: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8008DBC8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008DBCC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008DBD0: nop

    // 0x8008DBD4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8008DBD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008DBDC: nop

    // 0x8008DBE0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8008DBE4: beql        $t9, $zero, L_8008DC34
    if (ctx->r25 == 0) {
        // 0x8008DBE8: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_8008DC34;
    }
    goto skip_1;
    // 0x8008DBE8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_1:
    // 0x8008DBEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DBF0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008DBF4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8008DBF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008DBFC: nop

    // 0x8008DC00: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008DC04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008DC08: nop

    // 0x8008DC0C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8008DC10: bne         $t9, $zero, L_8008DC28
    if (ctx->r25 != 0) {
        // 0x8008DC14: nop
    
            goto L_8008DC28;
    }
    // 0x8008DC14: nop

    // 0x8008DC18: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8008DC1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008DC20: b           L_8008DC40
    // 0x8008DC24: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8008DC40;
    // 0x8008DC24: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8008DC28:
    // 0x8008DC28: b           L_8008DC40
    // 0x8008DC2C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8008DC40;
    // 0x8008DC2C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008DC30: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_8008DC34:
    // 0x8008DC34: nop

    // 0x8008DC38: bltz        $t9, L_8008DC28
    if (SIGNED(ctx->r25) < 0) {
        // 0x8008DC3C: nop
    
            goto L_8008DC28;
    }
    // 0x8008DC3C: nop

L_8008DC40:
    // 0x8008DC40: subu        $v0, $v0, $t9
    ctx->r2 = SUB32(ctx->r2, ctx->r25);
    // 0x8008DC44: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x8008DC48: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8008DC4C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008DC50: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8008DC54: jal         0x800F2100
    // 0x8008DC58: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x8008DC58: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x8008DC5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008DC60: lwc1        $f10, 0x4AE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4AE0);
    // 0x8008DC64: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8008DC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DC6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DC70: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008DC74: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8008DC78: nop

    // 0x8008DC7C: bc1f        L_8008DC88
    if (!c1cs) {
        // 0x8008DC80: nop
    
            goto L_8008DC88;
    }
    // 0x8008DC80: nop

    // 0x8008DC84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DC88:
    // 0x8008DC88: jr          $ra
    // 0x8008DC8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008DC8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801C28_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C28: lbu         $v0, 0x5E($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5E);
    // 0x80801C2C: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80801C30: beql        $at, $zero, L_80801C44
    if (ctx->r1 == 0) {
        // 0x80801C34: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_80801C44;
    }
    goto skip_0;
    // 0x80801C34: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    skip_0:
    // 0x80801C38: jr          $ra
    // 0x80801C3C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    return;
    // 0x80801C3C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80801C40: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
L_80801C44:
    // 0x80801C44: beql        $at, $zero, L_80801C58
    if (ctx->r1 == 0) {
        // 0x80801C48: slti        $at, $v0, 0x13
        ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
            goto L_80801C58;
    }
    goto skip_1;
    // 0x80801C48: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    skip_1:
    // 0x80801C4C: jr          $ra
    // 0x80801C50: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    return;
    // 0x80801C50: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80801C54: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
L_80801C58:
    // 0x80801C58: beql        $at, $zero, L_80801C6C
    if (ctx->r1 == 0) {
        // 0x80801C5C: slti        $at, $v0, 0x19
        ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
            goto L_80801C6C;
    }
    goto skip_2;
    // 0x80801C5C: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    skip_2:
    // 0x80801C60: jr          $ra
    // 0x80801C64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80801C64: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80801C68: slti        $at, $v0, 0x19
    ctx->r1 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
L_80801C6C:
    // 0x80801C6C: beq         $at, $zero, L_80801C7C
    if (ctx->r1 == 0) {
        // 0x80801C70: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80801C7C;
    }
    // 0x80801C70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80801C74: jr          $ra
    // 0x80801C78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x80801C78: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801C7C:
    // 0x80801C7C: jr          $ra
    // 0x80801C80: nop

    return;
    // 0x80801C80: nop

;}
RECOMP_FUNC void bareact_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: lw          $t6, 0xEC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XEC);
    // 0x80800098: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080009C: jr          $ra
    // 0x808000A0: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    return;
    // 0x808000A0: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x808000A4: nop

    // 0x808000A8: nop

    // 0x808000AC: nop

;}
RECOMP_FUNC void func_80800270_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800274: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800278: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8080027C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800280: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1424, 0X810) << 16);
    // 0x80800284: addiu       $t7, $t7, 0x810
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1424, 0X810));
    // 0x80800288: lw          $a2, 0x38($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X38);
    // 0x8080028C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800290: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800294: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: jal         0x800BBCB8
    // 0x808002A0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808002A0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x808002A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1424, 0X84C) << 16);
    // 0x808002A8: addiu       $a3, $a3, 0x84C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1424, 0X84C));
    // 0x808002AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808002B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808002B4: jal         0x8010D930
    // 0x808002B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x808002B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_808030E0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808030E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808030E8: lw          $v1, 0x188($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X188);
    // 0x808030EC: lh          $t6, 0xE2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XE2);
    // 0x808030F0: sh          $zero, 0xD4($v1)
    MEM_H(0XD4, ctx->r3) = 0;
    // 0x808030F4: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808030F8: beql        $at, $zero, L_80803118
    if (ctx->r1 == 0) {
        // 0x808030FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803118;
    }
    goto skip_0;
    // 0x808030FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803100: sh          $a1, 0xE2($v1)
    MEM_H(0XE2, ctx->r3) = ctx->r5;
    // 0x80803104: jal         0x80802C30
    // 0x80803108: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80802C30_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80803108: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8080310C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803110: sh          $v0, 0xE8($v1)
    MEM_H(0XE8, ctx->r3) = ctx->r2;
    // 0x80803114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803118:
    // 0x80803118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080311C: jr          $ra
    // 0x80803120: nop

    return;
    // 0x80803120: nop

;}
RECOMP_FUNC void func_808016B4_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808016B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808016C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016C4: jal         0x8008CABC
    // 0x808016C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808016C8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808016CC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808016D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D4: jal         0x8009D3A8
    // 0x808016D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x808016D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808016DC: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x808016E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808016E4: beq         $v0, $zero, L_80801708
    if (ctx->r2 == 0) {
        // 0x808016E8: nop
    
            goto L_80801708;
    }
    // 0x808016E8: nop

    // 0x808016EC: beq         $v0, $at, L_808017B4
    if (ctx->r2 == ctx->r1) {
        // 0x808016F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808017B4;
    }
    // 0x808016F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808016F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016F8: beq         $v0, $at, L_808017F8
    if (ctx->r2 == ctx->r1) {
        // 0x808016FC: nop
    
            goto L_808017F8;
    }
    // 0x808016FC: nop

    // 0x80801700: b           L_80801820
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801820;
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801708:
    // 0x80801708: jal         0x808015C4
    // 0x8080170C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808015C4_bsbfly(rdram, ctx);
        goto after_2;
    // 0x8080170C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801710: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80801714: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801718: jal         0x8008B348
    // 0x8080171C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x8080171C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80801720: beq         $v0, $zero, L_80801788
    if (ctx->r2 == 0) {
        // 0x80801724: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801788;
    }
    // 0x80801724: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801728: jal         0x800F8B64
    // 0x8080172C: nop

    func_800F8B64(rdram, ctx);
        goto after_4;
    // 0x8080172C: nop

    after_4:
    // 0x80801730: beql        $v0, $zero, L_80801820
    if (ctx->r2 == 0) {
        // 0x80801734: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801820;
    }
    goto skip_0;
    // 0x80801734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801738: jal         0x800A0180
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_5;
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801744: jal         0x800A4DFC
    // 0x80801748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_6;
    // 0x80801748: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x8080174C: jal         0x800A4CA8
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_7;
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801758: jal         0x80089288
    // 0x8080175C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080175C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_8:
    // 0x80801760: jal         0x80085208
    // 0x80801764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x80801764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801768: lui         $a2, 0x404C
    ctx->r6 = S32(0X404C << 16);
    // 0x8080176C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801774: jal         0x80085338
    // 0x80801778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_10;
    // 0x80801778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8080177C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801780: b           L_8080181C
    // 0x80801784: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
        goto L_8080181C;
    // 0x80801784: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
L_80801788:
    // 0x80801788: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x8080178C: jal         0x8008B348
    // 0x80801790: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80801790: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    after_11:
    // 0x80801794: beq         $v0, $zero, L_8080181C
    if (ctx->r2 == 0) {
        // 0x80801798: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080181C;
    }
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080179C: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    // 0x808017A0: jal         0x8008CCBC
    // 0x808017A4: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_12;
    // 0x808017A4: lui         $a2, 0x4010
    ctx->r6 = S32(0X4010 << 16);
    after_12:
    // 0x808017A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808017AC: b           L_8080181C
    // 0x808017B0: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
        goto L_8080181C;
    // 0x808017B0: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
L_808017B4:
    // 0x808017B4: lui         $a1, 0x3F21
    ctx->r5 = S32(0X3F21 << 16);
    // 0x808017B8: jal         0x8008B348
    // 0x808017BC: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x808017BC: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_13:
    // 0x808017C0: beq         $v0, $zero, L_808017CC
    if (ctx->r2 == 0) {
        // 0x808017C4: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_808017CC;
    }
    // 0x808017C4: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x808017C8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808017CC:
    // 0x808017CC: jal         0x8008B324
    // 0x808017D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_14;
    // 0x808017D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x808017D4: beq         $v0, $zero, L_808017E0
    if (ctx->r2 == 0) {
        // 0x808017D8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808017E0;
    }
    // 0x808017D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808017DC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808017E0:
    // 0x808017E0: jal         0x8008DD04
    // 0x808017E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_15;
    // 0x808017E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808017E8: beq         $v0, $zero, L_8080181C
    if (ctx->r2 == 0) {
        // 0x808017EC: addiu       $t0, $zero, 0x2F
        ctx->r8 = ADD32(0, 0X2F);
            goto L_8080181C;
    }
    // 0x808017EC: addiu       $t0, $zero, 0x2F
    ctx->r8 = ADD32(0, 0X2F);
    // 0x808017F0: b           L_8080181C
    // 0x808017F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
        goto L_8080181C;
    // 0x808017F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808017F8:
    // 0x808017F8: jal         0x808015C4
    // 0x808017FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808015C4_bsbfly(rdram, ctx);
        goto after_16;
    // 0x808017FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801804: jal         0x800852F0
    // 0x80801808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_17;
    // 0x80801808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8080180C: beql        $v0, $zero, L_80801820
    if (ctx->r2 == 0) {
        // 0x80801810: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801820;
    }
    goto skip_1;
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801814: jal         0x80085200
    // 0x80801818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x80801818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_8080181C:
    // 0x8080181C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801820:
    // 0x80801820: jal         0x8009E5C8
    // 0x80801824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80801824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x80801828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080182C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801830: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801834: jr          $ra
    // 0x80801838: nop

    return;
    // 0x80801838: nop

;}
RECOMP_FUNC void func_800EFA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFA88: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800EFA8C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800EFA90: jr          $ra
    // 0x800EFA94: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
    return;
    // 0x800EFA94: sw          $a3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_800E3C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800E3C60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3C64: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800E3C68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3C6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800E3C70: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3C74: jal         0x800CA688
    // 0x800E3C78: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800CA688(rdram, ctx);
        goto after_0;
    // 0x800E3C78: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800E3C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3C84: jr          $ra
    // 0x800E3C88: nop

    return;
    // 0x800E3C88: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836D8: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x800836D8);
    return;
    // 0x800836DC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808064E8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808064E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808064EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808064F0: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x808064F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808064F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808064FC: beq         $a3, $at, L_80806528
    if (ctx->r7 == ctx->r1) {
        // 0x80806500: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80806528;
    }
    // 0x80806500: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80806504: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80806508: beq         $a3, $at, L_80806530
    if (ctx->r7 == ctx->r1) {
        // 0x8080650C: addiu       $at, $zero, 0xFE
        ctx->r1 = ADD32(0, 0XFE);
            goto L_80806530;
    }
    // 0x8080650C: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80806510: bnel        $a3, $at, L_80806534
    if (ctx->r7 != ctx->r1) {
        // 0x80806514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80806534;
    }
    goto skip_0;
    // 0x80806514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806518: jal         0x800AA054
    // 0x8080651C: nop

    func_800AA054(rdram, ctx);
        goto after_0;
    // 0x8080651C: nop

    after_0:
    // 0x80806520: b           L_80806534
    // 0x80806524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80806534;
    // 0x80806524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806528:
    // 0x80806528: jal         0x800AA074
    // 0x8080652C: nop

    func_800AA074(rdram, ctx);
        goto after_1;
    // 0x8080652C: nop

    after_1:
L_80806530:
    // 0x80806530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806534:
    // 0x80806534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806538: jr          $ra
    // 0x8080653C: nop

    return;
    // 0x8080653C: nop

;}
RECOMP_FUNC void func_80801508_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801508: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080150C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801510: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801518: jal         0x80100094
    // 0x8080151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080151C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801520: jal         0x800DC0C0
    // 0x80801524: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80801524: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801528: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28EC) << 16);
    // 0x8080152C: lwc1        $f4, 0x28EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28EC));
    // 0x80801530: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801534: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801538: nop

    // 0x8080153C: bc1fl       L_80801694
    if (!c1cs) {
        // 0x80801540: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801694;
    }
    goto skip_0;
    // 0x80801540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801544: jal         0x800DC128
    // 0x80801548: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80801548: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x8080154C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80801550: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80801554: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80801558: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8080155C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801560: addu        $s0, $t6, $t8
    ctx->r16 = ADD32(ctx->r14, ctx->r24);
    // 0x80801564: jal         0x800DC0C0
    // 0x80801568: sb          $v0, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80801568: sb          $v0, 0x19($s0)
    MEM_B(0X19, ctx->r16) = ctx->r2;
    after_3:
    // 0x8080156C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28F0) << 16);
    // 0x80801570: lwc1        $f6, 0x28F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28F0));
    // 0x80801574: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28F4) << 16);
    // 0x80801578: lwc1        $f10, 0x28F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28F4));
    // 0x8080157C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801584: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801588: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080158C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801590: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801594: jal         0x800DC178
    // 0x80801598: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801598: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x8080159C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x808015A0: jal         0x800DC0C0
    // 0x808015A4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x808015A4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x808015A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808015AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808015B0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x808015B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808015B8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808015BC: nop

    // 0x808015C0: bc1fl       L_808015D4
    if (!c1cs) {
        // 0x808015C4: sb          $t0, 0x18($s0)
        MEM_B(0X18, ctx->r16) = ctx->r8;
            goto L_808015D4;
    }
    goto skip_1;
    // 0x808015C4: sb          $t0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r8;
    skip_1:
    // 0x808015C8: b           L_808015D4
    // 0x808015CC: sb          $t9, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r25;
        goto L_808015D4;
    // 0x808015CC: sb          $t9, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r25;
    // 0x808015D0: sb          $t0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r8;
L_808015D4:
    // 0x808015D4: jal         0x800DC0C0
    // 0x808015D8: nop

    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x808015D8: nop

    after_6:
    // 0x808015DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28F8) << 16);
    // 0x808015E0: lwc1        $f4, 0x28F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28F8));
    // 0x808015E4: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x808015E8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808015EC: nop

    // 0x808015F0: bc1fl       L_80801654
    if (!c1cs) {
        // 0x808015F4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80801654;
    }
    goto skip_2;
    // 0x808015F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x808015F8: jal         0x800F54E4
    // 0x808015FC: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808015FC: nop

    after_7:
    // 0x80801600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801604: jal         0x800F5A00
    // 0x80801608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F5A00(rdram, ctx);
        goto after_8;
    // 0x80801608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x8080160C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80801610: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801614: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801618: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080161C: jal         0x800DC178
    // 0x80801620: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80801620: nop

    after_9:
    // 0x80801624: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801628: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080162C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801630: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80801634: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801638: jal         0x800DC178
    // 0x8080163C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x8080163C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x80801640: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801644: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80801648: b           L_80801690
    // 0x8080164C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
        goto L_80801690;
    // 0x8080164C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80801650: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80801654:
    // 0x80801654: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X28FC) << 16);
    // 0x80801658: jal         0x800DC178
    // 0x8080165C: lwc1        $f14, 0x28FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28FC));
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x8080165C: lwc1        $f14, 0x28FC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2284, 0X28FC));
    after_11:
    // 0x80801660: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x80801664: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801668: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080166C: jal         0x800DC178
    // 0x80801670: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80801670: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    after_12:
    // 0x80801674: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80801678: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080167C: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80801680: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801684: jal         0x800DC178
    // 0x80801688: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80801688: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    after_13:
    // 0x8080168C: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_80801690:
    // 0x80801690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801694:
    // 0x80801694: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801698: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080169C: jr          $ra
    // 0x808016A0: nop

    return;
    // 0x808016A0: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C1C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XFC8) << 16);
    // 0x80800C24: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C28: jr          $ra
    // 0x80800C2C: lw          $v0, 0xFC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFC8));
    return;
    // 0x80800C2C: lw          $v0, 0xFC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFC8));
;}
RECOMP_FUNC void _chbubble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087748: syscall     617
    recomp_syscall_handler(rdram, ctx, 0x80087748);
    return;
    // 0x8008774C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808027F4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808027F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808027FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802800: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802804: jal         0x80100094
    // 0x80802808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080280C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802810: jal         0x80802248
    // 0x80802814: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80802814: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80802818: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080281C: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80802820: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802824: beql        $t6, $zero, L_8080283C
    if (ctx->r14 == 0) {
        // 0x80802828: lh          $t7, 0x8($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X8);
            goto L_8080283C;
    }
    goto skip_0;
    // 0x80802828: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    skip_0:
    // 0x8080282C: jal         0x800F7F98
    // 0x80802830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_2;
    // 0x80802830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802834: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80802838: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
L_8080283C:
    // 0x8080283C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802840: beq         $t7, $zero, L_80802864
    if (ctx->r15 == 0) {
        // 0x80802844: nop
    
            goto L_80802864;
    }
    // 0x80802844: nop

    // 0x80802848: jal         0x800856B8
    // 0x8080284C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080284C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80802850: jal         0x800878F8
    // 0x80802854: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80802854: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80802858: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8080285C: b           L_80802864
    // 0x80802860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802864;
    // 0x80802860: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802864:
    // 0x80802864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080286C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802870: jr          $ra
    // 0x80802874: nop

    return;
    // 0x80802874: nop

;}
RECOMP_FUNC void _bsjig_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083228: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083228);
    return;
    // 0x8008322C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80801020_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801028: jal         0x800EA05C
    // 0x8080102C: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080102C: nop

    after_0:
    // 0x80801030: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1192, 0X10A0) << 16);
    // 0x80801034: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1192, 0X10DC) << 16);
    // 0x80801038: addiu       $a0, $a0, 0x10DC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1192, 0X10DC));
    // 0x8080103C: addiu       $v1, $v1, 0x10A0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1192, 0X10A0));
    // 0x80801040: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
L_80801044:
    // 0x80801044: bnel        $v0, $t6, L_80801058
    if (ctx->r2 != ctx->r14) {
        // 0x80801048: addiu       $v1, $v1, 0x14
        ctx->r3 = ADD32(ctx->r3, 0X14);
            goto L_80801058;
    }
    goto skip_0;
    // 0x80801048: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    skip_0:
    // 0x8080104C: b           L_80801064
    // 0x80801050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80801064;
    // 0x80801050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801054: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
L_80801058:
    // 0x80801058: bnel        $v1, $a0, L_80801044
    if (ctx->r3 != ctx->r4) {
        // 0x8080105C: lhu         $t6, 0x2($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0X2);
            goto L_80801044;
    }
    goto skip_1;
    // 0x8080105C: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    skip_1:
    // 0x80801060: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801064:
    // 0x80801064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080106C: jr          $ra
    // 0x80801070: nop

    return;
    // 0x80801070: nop

    // 0x80801074: nop

    // 0x80801078: nop

    // 0x8080107C: nop

;}
RECOMP_FUNC void chbanjoctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800500: jal         0x800F54E4
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800508: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080050C: jal         0x800F7B9C
    // 0x80800510: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80800510: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_1:
    // 0x80800514: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800518: bne         $v0, $at, L_80800530
    if (ctx->r2 != ctx->r1) {
        // 0x8080051C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800530;
    }
    // 0x8080051C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800520: jal         0x80086448
    // 0x80800524: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chhotwaterpoolbits_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800524: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800528: b           L_80800534
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800534;
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800530:
    // 0x80800530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800534:
    // 0x80800534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080053C: jr          $ra
    // 0x80800540: nop

    return;
    // 0x80800540: nop

;}
RECOMP_FUNC void _fxegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A68: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A68);
    return;
    // 0x80088A6C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089900: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089900);
    return;
    // 0x80089904: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_808000B4_suspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: bgez        $a1, L_808000C4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x808000B8: sra         $t6, $a1, 3
        ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
            goto L_808000C4;
    }
    // 0x808000B8: sra         $t6, $a1, 3
    ctx->r14 = S32(SIGNED(ctx->r5) >> 3);
    // 0x808000BC: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x808000C0: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_808000C4:
    // 0x808000C4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x808000C8: lbu         $t8, 0x87($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X87);
    // 0x808000CC: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x808000D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808000D4: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x808000D8: and         $t2, $t8, $t1
    ctx->r10 = ctx->r24 & ctx->r9;
    // 0x808000DC: beq         $t2, $zero, L_808000EC
    if (ctx->r10 == 0) {
        // 0x808000E0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808000EC;
    }
    // 0x808000E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000EC:
    // 0x808000EC: jr          $ra
    // 0x808000F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808000F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8008FBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FBE8: jal         0x800A1624
    // 0x8008FBEC: nop

    func_800A1624(rdram, ctx);
        goto after_0;
    // 0x8008FBEC: nop

    after_0:
    // 0x8008FBF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FBF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FBF8: jr          $ra
    // 0x8008FBFC: nop

    return;
    // 0x8008FBFC: nop

;}
RECOMP_FUNC void ncbaspiral_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: jal         0x80800028
    // 0x808000D0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80800028_ncbaspiral(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x801107F0
    // 0x808000DC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x808000DC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x808000E0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808000E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808000E8: jal         0x800EFB24
    // 0x808000EC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808000EC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x808000F0: jal         0x800EEF94
    // 0x808000F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x808000F4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x808000F8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808000FC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800100: jal         0x800F1A88
    // 0x80800104: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x80800104: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80115358
    // 0x80800110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115358(rdram, ctx);
        goto after_5;
    // 0x80800110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800114: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80115750
    // 0x80800120: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80115750(rdram, ctx);
        goto after_6;
    // 0x80800120: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800124: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x8080012C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800130: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80800134: jal         0x800F1E6C
    // 0x80800138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1E6C(rdram, ctx);
        goto after_7;
    // 0x80800138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x8080013C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800140: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800144: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800150: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800154: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80800158: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8080015C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800160: jal         0x80112D08
    // 0x80800164: nop

    func_80112D08(rdram, ctx);
        goto after_8;
    // 0x80800164: nop

    after_8:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80112C3C
    // 0x80800170: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80112C3C(rdram, ctx);
        goto after_9;
    // 0x80800170: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x80800174: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800178: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080017C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800180: jal         0x800EEBF0
    // 0x80800184: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EEBF0(rdram, ctx);
        goto after_10;
    // 0x80800184: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800188: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080018C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800190: jal         0x800EE780
    // 0x80800194: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x80800194: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80111CC8
    // 0x808001A0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80111CC8(rdram, ctx);
        goto after_12;
    // 0x808001A0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_12:
    // 0x808001A4: beql        $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    goto skip_0;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001AC: jal         0x801138A0
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_13;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001B4: bne         $v0, $zero, L_808001CC
    if (ctx->r2 != 0) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80115580
    // 0x808001C0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80115580(rdram, ctx);
        goto after_14;
    // 0x808001C0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_14:
    // 0x808001C4: beql        $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    goto skip_1;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808001CC:
    // 0x808001CC: jal         0x801138F4
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_15;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001D4: beql        $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001E8;
    }
    goto skip_2;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808001DC: jal         0x80110F44
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_16;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001E8:
    // 0x808001E8: jal         0x80800008
    // 0x808001EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80800008_ncbaspiral(rdram, ctx);
        goto after_17;
    // 0x808001EC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_17:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808001F8: jal         0x80110A68
    // 0x808001FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80110A68(rdram, ctx);
        goto after_18;
    // 0x808001FC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_18:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80110790
    // 0x80800208: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_80110790(rdram, ctx);
        goto after_19;
    // 0x80800208: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_19:
    // 0x8080020C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800214: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800218: jr          $ra
    // 0x8080021C: nop

    return;
    // 0x8080021C: nop

;}
RECOMP_FUNC void chprisonbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1932, 0X10A8) << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x10A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X10A8));
    return;
    // 0x80800038: addiu       $v0, $v0, 0x10A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1932, 0X10A8));
;}
RECOMP_FUNC void _chbottlesdead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087090: syscall     506
    recomp_syscall_handler(rdram, ctx, 0x80087090);
    return;
    // 0x80087094: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddieDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4B8: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4B8);
    return;
    // 0x8008A4BC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800815C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800815C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800815C4: jr          $ra
    // 0x800815C8: sw          $a0, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r4;
    return;
    // 0x800815C8: sw          $a0, 0x6CB8($at)
    MEM_W(0X6CB8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800BDD24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDD24: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800BDD28: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BDD2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDD30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BDD34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BDD38: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BDD3C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800BDD40: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800BDD44: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800BDD48: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800BDD4C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BDD50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BDD54: addiu       $v0, $v0, -0x7BF0
    ctx->r2 = ADD32(ctx->r2, -0X7BF0);
    // 0x800BDD58: lwc1        $f2, -0x7BB0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7BB0);
    // 0x800BDD5C: addiu       $a0, $a0, -0x7BE4
    ctx->r4 = ADD32(ctx->r4, -0X7BE4);
    // 0x800BDD60: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
L_800BDD64:
    // 0x800BDD64: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800BDD68: bltzl       $v1, L_800BDD8C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800BDD6C: mtc1        $v1, $f8
        ctx->f8.u32l = ctx->r3;
            goto L_800BDD8C;
    }
    goto skip_0;
    // 0x800BDD6C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    skip_0:
    // 0x800BDD70: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800BDD74: nop

    // 0x800BDD78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BDD7C: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BDD80: b           L_800BDDA0
    // 0x800BDD84: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
        goto L_800BDDA0;
    // 0x800BDD84: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800BDD88: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_800BDD8C:
    // 0x800BDD8C: nop

    // 0x800BDD90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BDD94: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BDD98: nop

    // 0x800BDD9C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_800BDDA0:
    // 0x800BDDA0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BDDA4: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800BDDA8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800BDDAC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BDDB0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BDDB4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BDDB8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800BDDBC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BDDC0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800BDDC4: bne         $at, $zero, L_800BDD64
    if (ctx->r1 != 0) {
        // 0x800BDDC8: sw          $t8, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r24;
            goto L_800BDD64;
    }
    // 0x800BDDC8: sw          $t8, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r24;
    // 0x800BDDCC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800BDDD0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BDDD4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BDDD8: blez        $t9, L_800BDF10
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BDDDC: addiu       $s2, $s2, -0x7BF0
        ctx->r18 = ADD32(ctx->r18, -0X7BF0);
            goto L_800BDF10;
    }
    // 0x800BDDDC: addiu       $s2, $s2, -0x7BF0
    ctx->r18 = ADD32(ctx->r18, -0X7BF0);
    // 0x800BDDE0: lw          $t0, 0x28($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X28);
    // 0x800BDDE4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x800BDDE8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800BDDEC: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BDDF0: beql        $at, $zero, L_800BDF14
    if (ctx->r1 == 0) {
        // 0x800BDDF4: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BDF14;
    }
    goto skip_1;
    // 0x800BDDF4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x800BDDF8: blezl       $t2, L_800BDF14
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800BDDFC: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BDF14;
    }
    goto skip_2;
    // 0x800BDDFC: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_2:
    // 0x800BDE00: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
    // 0x800BDE04: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BDE08: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800BDE0C: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800BDE10: beql        $at, $zero, L_800BDF14
    if (ctx->r1 == 0) {
        // 0x800BDE14: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BDF14;
    }
    goto skip_3;
    // 0x800BDE14: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_3:
    // 0x800BDE18: blezl       $a0, L_800BDF14
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BDE1C: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BDF14;
    }
    goto skip_4;
    // 0x800BDE1C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_4:
    // 0x800BDE20: lw          $t5, 0x30($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X30);
    // 0x800BDE24: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800BDE28: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BDE2C: beql        $at, $zero, L_800BDF14
    if (ctx->r1 == 0) {
        // 0x800BDE30: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800BDF14;
    }
    goto skip_5;
    // 0x800BDE30: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_5:
    // 0x800BDE34: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800BDE38: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BDE3C: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
    // 0x800BDE40: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDE44: addiu       $t1, $t2, -0x1
    ctx->r9 = ADD32(ctx->r10, -0X1);
    // 0x800BDE48: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BDE4C: addiu       $s4, $s4, -0x7BA8
    ctx->r20 = ADD32(ctx->r20, -0X7BA8);
    // 0x800BDE50: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800BDE54: mflo        $t8
    ctx->r24 = lo;
    // 0x800BDE58: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BDE5C: nop

    // 0x800BDE60: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDE64: mflo        $t3
    ctx->r11 = lo;
    // 0x800BDE68: addu        $s5, $t0, $t3
    ctx->r21 = ADD32(ctx->r8, ctx->r11);
    // 0x800BDE6C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800BDE70: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
L_800BDE74:
    // 0x800BDE74: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
L_800BDE78:
    // 0x800BDE78: slti        $at, $zero, 0x3
    ctx->r1 = SIGNED(0) < 0X3 ? 1 : 0;
    // 0x800BDE7C: beq         $at, $zero, L_800BDECC
    if (ctx->r1 == 0) {
        // 0x800BDE80: sw          $zero, 0x54($sp)
        MEM_W(0X54, ctx->r29) = 0;
            goto L_800BDECC;
    }
    // 0x800BDE80: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_800BDE84:
    // 0x800BDE84: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800BDE88: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x800BDE8C: jal         0x800E9DC4
    // 0x800BDE90: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    func_800E9DC4(rdram, ctx);
        goto after_0;
    // 0x800BDE90: addu        $a0, $s0, $t4
    ctx->r4 = ADD32(ctx->r16, ctx->r12);
    after_0:
    // 0x800BDE94: beq         $v0, $zero, L_800BDEB0
    if (ctx->r2 == 0) {
        // 0x800BDE98: sll         $t7, $s3, 2
        ctx->r15 = S32(ctx->r19 << 2);
            goto L_800BDEB0;
    }
    // 0x800BDE98: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x800BDE9C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800BDEA0: addu        $t8, $s4, $t7
    ctx->r24 = ADD32(ctx->r20, ctx->r15);
    // 0x800BDEA4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BDEA8: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x800BDEAC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800BDEB0:
    // 0x800BDEB0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x800BDEB4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800BDEB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BDEBC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800BDEC0: bne         $at, $zero, L_800BDE84
    if (ctx->r1 != 0) {
        // 0x800BDEC4: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_800BDE84;
    }
    // 0x800BDEC4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BDEC8: lw          $v1, 0x1C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1C);
L_800BDECC:
    // 0x800BDECC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800BDED0: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x800BDED4: addiu       $s1, $s1, -0x3
    ctx->r17 = ADD32(ctx->r17, -0X3);
    // 0x800BDED8: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800BDEDC: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800BDEE0: bne         $at, $zero, L_800BDE78
    if (ctx->r1 != 0) {
        // 0x800BDEE4: sw          $t2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r10;
            goto L_800BDE78;
    }
    // 0x800BDEE4: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800BDEE8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800BDEEC: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800BDEF0: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x800BDEF4: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x800BDEF8: addu        $s5, $s5, $v0
    ctx->r21 = ADD32(ctx->r21, ctx->r2);
    // 0x800BDEFC: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800BDF00: bne         $at, $zero, L_800BDE74
    if (ctx->r1 != 0) {
        // 0x800BDF04: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800BDE74;
    }
    // 0x800BDF04: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800BDF08: b           L_800BE064
    // 0x800BDF0C: nop

        goto L_800BE064;
    // 0x800BDF0C: nop

L_800BDF10:
    // 0x800BDF10: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
L_800BDF14:
    // 0x800BDF14: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BDF18: addiu       $s2, $s2, -0x7BF0
    ctx->r18 = ADD32(ctx->r18, -0X7BF0);
    // 0x800BDF1C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800BDF20: addiu       $v0, $t3, 0x2
    ctx->r2 = ADD32(ctx->r11, 0X2);
    // 0x800BDF24: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BDF28: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BDF2C: beq         $at, $zero, L_800BE064
    if (ctx->r1 == 0) {
        // 0x800BDF30: sw          $t4, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r12;
            goto L_800BE064;
    }
    // 0x800BDF30: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800BDF34: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BDF38: addiu       $s4, $s4, -0x7BA8
    ctx->r20 = ADD32(ctx->r20, -0X7BA8);
L_800BDF3C:
    // 0x800BDF3C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800BDF40: bltzl       $t5, L_800BE054
    if (SIGNED(ctx->r13) < 0) {
        // 0x800BDF44: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_800BE054;
    }
    goto skip_6;
    // 0x800BDF44: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x800BDF48: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x800BDF4C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800BDF50: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BDF54: beq         $at, $zero, L_800BE050
    if (ctx->r1 == 0) {
        // 0x800BDF58: addiu       $t8, $t6, -0x1
        ctx->r24 = ADD32(ctx->r14, -0X1);
            goto L_800BE050;
    }
    // 0x800BDF58: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x800BDF5C: addiu       $v1, $t6, 0x2
    ctx->r3 = ADD32(ctx->r14, 0X2);
    // 0x800BDF60: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BDF64: beq         $at, $zero, L_800BE050
    if (ctx->r1 == 0) {
        // 0x800BDF68: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800BE050;
    }
    // 0x800BDF68: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
L_800BDF6C:
    // 0x800BDF6C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800BDF70: bltzl       $t9, L_800BE038
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BDF74: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800BE038;
    }
    goto skip_7;
    // 0x800BDF74: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_7:
    // 0x800BDF78: lw          $t2, 0x2C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X2C);
    // 0x800BDF7C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800BDF80: addiu       $t1, $a0, 0x2
    ctx->r9 = ADD32(ctx->r4, 0X2);
    // 0x800BDF84: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BDF88: beq         $at, $zero, L_800BE034
    if (ctx->r1 == 0) {
        // 0x800BDF8C: slt         $at, $v0, $t1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800BE034;
    }
    // 0x800BDF8C: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BDF90: beql        $at, $zero, L_800BE038
    if (ctx->r1 == 0) {
        // 0x800BDF94: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_800BE038;
    }
    goto skip_8;
    // 0x800BDF94: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    skip_8:
L_800BDF98:
    // 0x800BDF98: bltz        $v0, L_800BE010
    if (SIGNED(ctx->r2) < 0) {
        // 0x800BDF9C: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_800BE010;
    }
    // 0x800BDF9C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BDFA0: lw          $t0, 0x30($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X30);
    // 0x800BDFA4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BDFA8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BDFAC: beql        $at, $zero, L_800BE014
    if (ctx->r1 == 0) {
        // 0x800BDFB0: lw          $v0, 0x54($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X54);
            goto L_800BE014;
    }
    goto skip_9;
    // 0x800BDFB0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    skip_9:
    // 0x800BDFB4: lw          $t3, 0x20($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X20);
    // 0x800BDFB8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800BDFBC: lw          $t8, 0x1C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X1C);
    // 0x800BDFC0: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDFC4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800BDFC8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800BDFCC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800BDFD0: mflo        $t4
    ctx->r12 = lo;
    // 0x800BDFD4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800BDFD8: nop

    // 0x800BDFDC: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDFE0: mflo        $t9
    ctx->r25 = lo;
    // 0x800BDFE4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDFE8: sll         $s0, $s1, 3
    ctx->r16 = S32(ctx->r17 << 3);
    // 0x800BDFEC: jal         0x800E9DC4
    // 0x800BDFF0: addu        $a0, $s0, $t2
    ctx->r4 = ADD32(ctx->r16, ctx->r10);
    func_800E9DC4(rdram, ctx);
        goto after_1;
    // 0x800BDFF0: addu        $a0, $s0, $t2
    ctx->r4 = ADD32(ctx->r16, ctx->r10);
    after_1:
    // 0x800BDFF4: beq         $v0, $zero, L_800BE010
    if (ctx->r2 == 0) {
        // 0x800BDFF8: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_800BE010;
    }
    // 0x800BDFF8: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x800BDFFC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800BE000: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x800BE004: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BE008: addu        $t0, $s0, $t1
    ctx->r8 = ADD32(ctx->r16, ctx->r9);
    // 0x800BE00C: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
L_800BE010:
    // 0x800BE010: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
L_800BE014:
    // 0x800BE014: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800BE018: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BE01C: addiu       $t5, $a0, 0x2
    ctx->r13 = ADD32(ctx->r4, 0X2);
    // 0x800BE020: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BE024: bne         $at, $zero, L_800BDF98
    if (ctx->r1 != 0) {
        // 0x800BE028: nop
    
            goto L_800BDF98;
    }
    // 0x800BE028: nop

    // 0x800BE02C: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800BE030: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_800BE034:
    // 0x800BE034: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
L_800BE038:
    // 0x800BE038: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BE03C: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE040: bne         $at, $zero, L_800BDF6C
    if (ctx->r1 != 0) {
        // 0x800BE044: sw          $t8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r24;
            goto L_800BDF6C;
    }
    // 0x800BE044: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800BE048: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x800BE04C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
L_800BE050:
    // 0x800BE050: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_800BE054:
    // 0x800BE054: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800BE058: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BE05C: bne         $at, $zero, L_800BDF3C
    if (ctx->r1 != 0) {
        // 0x800BE060: sw          $t9, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r25;
            goto L_800BDF3C;
    }
    // 0x800BE060: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_800BE064:
    // 0x800BE064: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800BE068: addiu       $v0, $s4, -0x7BA8
    ctx->r2 = ADD32(ctx->r20, -0X7BA8);
    // 0x800BE06C: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800BE070: addu        $t1, $v0, $t2
    ctx->r9 = ADD32(ctx->r2, ctx->r10);
    // 0x800BE074: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800BE078: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE07C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800BE080: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800BE084: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800BE088: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE08C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BE090: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BE094: jr          $ra
    // 0x800BE098: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800BE098: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _chbottlesfamily_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864C8: syscall     331
    recomp_syscall_handler(rdram, ctx, 0x800864C8);
    return;
    // 0x800864CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
