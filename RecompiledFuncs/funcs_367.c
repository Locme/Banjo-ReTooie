#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncpod_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008BC: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x808008C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808008C4: beql        $a1, $t7, L_8080094C
    if (ctx->r5 == ctx->r15) {
        // 0x808008C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080094C;
    }
    goto skip_0;
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008CC: beql        $a1, $zero, L_80800910
    if (ctx->r5 == 0) {
        // 0x808008D0: lw          $a0, 0x38($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X38);
            goto L_80800910;
    }
    goto skip_1;
    // 0x808008D0: lw          $a0, 0x38($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X38);
    skip_1:
    // 0x808008D4: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    // 0x808008D8: jal         0x800A940C
    // 0x808008DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800A940C(rdram, ctx);
        goto after_0;
    // 0x808008DC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808008E0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808008E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008EC: beq         $t9, $zero, L_808008FC
    if (ctx->r25 == 0) {
        // 0x808008F0: nop
    
            goto L_808008FC;
    }
    // 0x808008F0: nop

    // 0x808008F4: b           L_808008FC
    // 0x808008F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_808008FC;
    // 0x808008F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_808008FC:
    // 0x808008FC: jal         0x800C52F4
    // 0x80800900: nop

    func_800C52F4(rdram, ctx);
        goto after_1;
    // 0x80800900: nop

    after_1:
    // 0x80800904: b           L_80800940
    // 0x80800908: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_80800940;
    // 0x80800908: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8080090C: lw          $a0, 0x38($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X38);
L_80800910:
    // 0x80800910: jal         0x800A940C
    // 0x80800914: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800A940C(rdram, ctx);
        goto after_2;
    // 0x80800914: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800918: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8080091C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800924: beq         $t0, $zero, L_80800934
    if (ctx->r8 == 0) {
        // 0x80800928: nop
    
            goto L_80800934;
    }
    // 0x80800928: nop

    // 0x8080092C: b           L_80800934
    // 0x80800930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800934;
    // 0x80800930: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800934:
    // 0x80800934: jal         0x800C53EC
    // 0x80800938: nop

    func_800C53EC(rdram, ctx);
        goto after_3;
    // 0x80800938: nop

    after_3:
    // 0x8080093C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80800940:
    // 0x80800940: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800944: sb          $t1, 0x3E($t2)
    MEM_B(0X3E, ctx->r10) = ctx->r9;
    // 0x80800948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080094C:
    // 0x8080094C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800950: jr          $ra
    // 0x80800954: nop

    return;
    // 0x80800954: nop

;}
RECOMP_FUNC void func_800C8198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8198: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800C819C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800C81A0: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800C81A4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800C81A8: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x800C81AC: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x800C81B0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C81B4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800C81B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C81BC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800C81C0: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x800C81C4: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x800C81C8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800C81CC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800C81D0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800C81D4: jal         0x800F0E00
    // 0x800C81D8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x800C81D8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x800C81DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C81E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C81E4: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x800C81E8: jal         0x800F13F0
    // 0x800C81EC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F13F0(rdram, ctx);
        goto after_1;
    // 0x800C81EC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x800C81F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C81F4: mov.s       $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.fl = ctx->f26.fl;
    // 0x800C81F8: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x800C81FC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800C8200: lwc1        $f24, 0x5920($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5920);
    // 0x800C8204: lwc1        $f26, 0x90($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800C8208: addiu       $s1, $sp, 0x74
    ctx->r17 = ADD32(ctx->r29, 0X74);
    // 0x800C820C: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
L_800C8210:
    // 0x800C8210: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_800C8214:
    // 0x800C8214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C8218: jal         0x800C7A68
    // 0x800C821C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C7A68(rdram, ctx);
        goto after_2;
    // 0x800C821C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800C8220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C8224: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C8228: jal         0x800EFB24
    // 0x800C822C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800C822C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x800C8230: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800C8234: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800C8238: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800C823C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C8240: nop

    // 0x800C8244: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800C8248: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C824C: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C8250: add.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800C8254: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x800C8258: nop

    // 0x800C825C: bc1f        L_800C826C
    if (!c1cs) {
        // 0x800C8260: nop
    
            goto L_800C826C;
    }
    // 0x800C8260: nop

    // 0x800C8264: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
    // 0x800C8268: mov.s       $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    ctx->f28.fl = ctx->f20.fl;
L_800C826C:
    // 0x800C826C: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x800C8270: nop

    // 0x800C8274: bc1tl       L_800C829C
    if (c1cs) {
        // 0x800C8278: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_800C829C;
    }
    goto skip_0;
    // 0x800C8278: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x800C827C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x800C8280: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x800C8284: nop

    // 0x800C8288: bc1fl       L_800C8214
    if (!c1cs) {
        // 0x800C828C: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800C8214;
    }
    goto skip_1;
    // 0x800C828C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x800C8290: b           L_800C8210
    // 0x800C8294: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
        goto L_800C8210;
    // 0x800C8294: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x800C8298: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800C829C:
    // 0x800C829C: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    // 0x800C82A0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x800C82A4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C82A8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800C82AC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800C82B0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x800C82B4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x800C82B8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800C82BC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x800C82C0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x800C82C4: jr          $ra
    // 0x800C82C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800C82C8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80800220_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800224: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080022C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800230: lbu         $v0, 0x15C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15C);
    // 0x80800234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080023C: beq         $v0, $at, L_80800264
    if (ctx->r2 == ctx->r1) {
        // 0x80800240: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800264;
    }
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800248: beq         $v0, $at, L_8080037C
    if (ctx->r2 == ctx->r1) {
        // 0x8080024C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080037C;
    }
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800254: beq         $v0, $at, L_808003F8
    if (ctx->r2 == ctx->r1) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F8;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: b           L_80800454
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800454;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800264:
    // 0x80800264: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80800268: jal         0x8008CB10
    // 0x8080026C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x8080026C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_0:
    // 0x80800270: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x8080027C: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800280: addiu       $t6, $zero, 0x6590
    ctx->r14 = ADD32(0, 0X6590);
    // 0x80800284: addiu       $t7, $zero, 0x6590
    ctx->r15 = ADD32(0, 0X6590);
    // 0x80800288: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080028C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800290: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800294: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800298: jal         0x8009DEC0
    // 0x8080029C: addiu       $a1, $zero, 0x459A
    ctx->r5 = ADD32(0, 0X459A);
    func_8009DEC0(rdram, ctx);
        goto after_1;
    // 0x8080029C: addiu       $a1, $zero, 0x459A
    ctx->r5 = ADD32(0, 0X459A);
    after_1:
L_808002A0:
    // 0x808002A0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808002A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002A8: jal         0x8008CB10
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002B0: beq         $v0, $zero, L_808002E0
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E0;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808002BC: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x808002C0: addiu       $t8, $zero, 0x6590
    ctx->r24 = ADD32(0, 0X6590);
    // 0x808002C4: addiu       $t9, $zero, 0x6590
    ctx->r25 = ADD32(0, 0X6590);
    // 0x808002C8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808002CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002D0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808002D4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808002D8: jal         0x8009DEC0
    // 0x808002DC: addiu       $a1, $zero, 0x459B
    ctx->r5 = ADD32(0, 0X459B);
    func_8009DEC0(rdram, ctx);
        goto after_3;
    // 0x808002DC: addiu       $a1, $zero, 0x459B
    ctx->r5 = ADD32(0, 0X459B);
    after_3:
L_808002E0:
    // 0x808002E0: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808002E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808002E8: jal         0x8008CB10
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002F0: beq         $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x808002F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800320;
    }
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F8: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808002FC: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800300: addiu       $t0, $zero, 0x6590
    ctx->r8 = ADD32(0, 0X6590);
    // 0x80800304: addiu       $t1, $zero, 0x6590
    ctx->r9 = ADD32(0, 0X6590);
    // 0x80800308: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8080030C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800310: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800314: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800318: jal         0x8009DEC0
    // 0x8080031C: addiu       $a1, $zero, 0x459C
    ctx->r5 = ADD32(0, 0X459C);
    func_8009DEC0(rdram, ctx);
        goto after_5;
    // 0x8080031C: addiu       $a1, $zero, 0x459C
    ctx->r5 = ADD32(0, 0X459C);
    after_5:
L_80800320:
    // 0x80800320: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x80800324: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80800328: jal         0x8008CB10
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800330: beql        $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800454;
    }
    goto skip_0;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800338: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x8080033C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80800340: beql        $a0, $zero, L_8080036C
    if (ctx->r4 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    goto skip_1;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800348: jal         0x8010114C
    // 0x8080034C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8010114C(rdram, ctx);
        goto after_7;
    // 0x8080034C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80800350: bgtz        $v0, L_80800368
    if (SIGNED(ctx->r2) > 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800368;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80800000
    // 0x8080035C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bskazhatch(rdram, ctx);
        goto after_8;
    // 0x8080035C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800360: b           L_80800454
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800454;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800368:
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080036C:
    // 0x8080036C: jal         0x80800000
    // 0x80800370: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_bskazhatch(rdram, ctx);
        goto after_9;
    // 0x80800370: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800374: b           L_80800454
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800454;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080037C:
    // 0x8080037C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800380: jal         0x8008CB10
    // 0x80800384: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x80800384: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_10:
    // 0x80800388: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003B8;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800394: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800398: addiu       $t2, $zero, 0x6590
    ctx->r10 = ADD32(0, 0X6590);
    // 0x8080039C: addiu       $t3, $zero, 0x6590
    ctx->r11 = ADD32(0, 0X6590);
    // 0x808003A0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808003A4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808003A8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808003AC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808003B0: jal         0x8009DEC0
    // 0x808003B4: addiu       $a1, $zero, 0x4599
    ctx->r5 = ADD32(0, 0X4599);
    func_8009DEC0(rdram, ctx);
        goto after_11;
    // 0x808003B4: addiu       $a1, $zero, 0x4599
    ctx->r5 = ADD32(0, 0X4599);
    after_11:
L_808003B8:
    // 0x808003B8: jal         0x8008CAEC
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_12;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808003C0: beq         $v0, $zero, L_80800450
    if (ctx->r2 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x8009B800
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_13;
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x808003D0: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x808003D4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x808003D8: jal         0x8010114C
    // 0x808003DC: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_8010114C(rdram, ctx);
        goto after_14;
    // 0x808003DC: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_14:
    // 0x808003E0: bgtzl       $v0, L_80800460
    if (SIGNED(ctx->r2) > 0) {
        // 0x808003E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800460;
    }
    goto skip_2;
    // 0x808003E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808003E8: jal         0x808001E4
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_bskazhatch(rdram, ctx);
        goto after_15;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808003F0: b           L_80800450
    // 0x808003F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80800450;
    // 0x808003F4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_808003F8:
    // 0x808003F8: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808003FC: jal         0x8008CB10
    // 0x80800400: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x80800400: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_16:
    // 0x80800404: beq         $v0, $zero, L_80800434
    if (ctx->r2 == 0) {
        // 0x80800408: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800434;
    }
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800410: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80800414: addiu       $t4, $zero, 0x6590
    ctx->r12 = ADD32(0, 0X6590);
    // 0x80800418: addiu       $t5, $zero, 0x6590
    ctx->r13 = ADD32(0, 0X6590);
    // 0x8080041C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800420: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800424: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800428: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080042C: jal         0x8009DEC0
    // 0x80800430: addiu       $a1, $zero, 0x459D
    ctx->r5 = ADD32(0, 0X459D);
    func_8009DEC0(rdram, ctx);
        goto after_17;
    // 0x80800430: addiu       $a1, $zero, 0x459D
    ctx->r5 = ADD32(0, 0X459D);
    after_17:
L_80800434:
    // 0x80800434: jal         0x8008CAEC
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080043C: beql        $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x80800440: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800454;
    }
    goto skip_3;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800444: jal         0x808001E4
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_bskazhatch(rdram, ctx);
        goto after_19;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080044C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80800450:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800454:
    // 0x80800454: jal         0x8009E5C8
    // 0x80800458: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_20;
    // 0x80800458: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_20:
    // 0x8080045C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800460:
    // 0x80800460: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800464: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800468: jr          $ra
    // 0x8080046C: nop

    return;
    // 0x8080046C: nop

;}
RECOMP_FUNC void func_80012F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012F38: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80012F3C: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012F44: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80012F48: jal         0x80021AD0
    // 0x80012F4C: sh          $a1, -0x5E32($at)
    MEM_H(-0X5E32, ctx->r1) = ctx->r5;
    func_80021AD0(rdram, ctx);
        goto after_0;
    // 0x80012F4C: sh          $a1, -0x5E32($at)
    MEM_H(-0X5E32, ctx->r1) = ctx->r5;
    after_0:
    // 0x80012F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012F58: jr          $ra
    // 0x80012F5C: nop

    return;
    // 0x80012F5C: nop

;}
RECOMP_FUNC void func_808001E0_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2710, 0X270) << 16);
    // 0x808001EC: addiu       $a1, $a1, 0x270
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2710, 0X270));
    // 0x808001F0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x808001F4: jal         0x80088508
    // 0x808001F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _gleeprom_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001F8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x808001FC: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x80800200: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800208;
    }
    // 0x80800200: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800204: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800208:
    // 0x80800208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080020C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800210: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_8080092C_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080092C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800934: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XC20) << 16);
    // 0x80800938: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8080093C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800940: addiu       $a2, $a2, 0xC20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XC20));
    // 0x80800944: jal         0x80089D20
    // 0x80800948: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800948: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080094C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800954: jr          $ra
    // 0x80800958: nop

    return;
    // 0x80800958: nop

;}
RECOMP_FUNC void func_808001F4_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808001FC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800200: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800204: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800208: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080020C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800210: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800218: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x8080021C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800220: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800224: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800228: blez        $t6, L_808002CC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080022C: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_808002CC;
    }
    // 0x8080022C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800230: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(780, 0X1344) << 16);
    // 0x80800234: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x80800238: addiu       $s5, $s5, 0x10B0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(780, 0X10B0));
    // 0x8080023C: addiu       $s6, $s6, 0x1344
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(780, 0X1344));
    // 0x80800240: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800244:
    // 0x80800244: jal         0x80800064
    // 0x80800248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800064_chwarppad(rdram, ctx);
        goto after_0;
    // 0x80800248: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8080024C: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808002B8;
    }
    // 0x80800250: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800254: addiu       $a2, $s0, 0x9
    ctx->r6 = ADD32(ctx->r16, 0X9);
    // 0x80800258: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x8080025C: subu        $s2, $s2, $s0
    ctx->r18 = SUB32(ctx->r18, ctx->r16);
    // 0x80800260: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800264: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800268: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8080026C: jal         0x80087CF8
    // 0x80800270: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800270: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800274: lw          $t9, 0x28($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X28);
    // 0x80800278: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8080027C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80800280: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800284: addu        $t1, $s5, $t0
    ctx->r9 = ADD32(ctx->r21, ctx->r8);
    // 0x80800288: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8080028C: jal         0x80090178
    // 0x80800290: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    func_80090178(rdram, ctx);
        goto after_2;
    // 0x80800290: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    after_2:
    // 0x80800294: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x80800298: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808002B4;
    }
    // 0x80800298: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080029C: jal         0x80087D50
    // 0x808002A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gcnewoption_entrypoint_23(rdram, ctx);
        goto after_3;
    // 0x808002A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808002A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808002A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808002AC: jal         0x80087D00
    // 0x808002B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808002B0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
L_808002B4:
    // 0x808002B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808002B8:
    // 0x808002B8: lw          $t3, 0x1C($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X1C);
    // 0x808002BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808002C0: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x808002C4: beql        $at, $zero, L_80800244
    if (ctx->r1 == 0) {
        // 0x808002C8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800244;
    }
    goto skip_0;
    // 0x808002C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808002D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808002DC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808002E0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808002E4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808002E8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808002EC: jr          $ra
    // 0x808002F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808002F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800B2C_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B34: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(800, 0X10D0) << 16);
    // 0x80800B38: addiu       $a3, $a3, 0x10D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(800, 0X10D0));
    // 0x80800B3C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800B40: jal         0x80089D50
    // 0x80800B44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800B44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B50: jr          $ra
    // 0x80800B54: nop

    return;
    // 0x80800B54: nop

;}
RECOMP_FUNC void func_80802148_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080214C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802154: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080215C: lbu         $a3, 0x9B($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X9B);
    // 0x80802160: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    // 0x80802164: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x80802168: jal         0x800DF5D8
    // 0x8080216C: lbu         $a0, 0x98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X98);
    func_800DF5D8(rdram, ctx);
        goto after_0;
    // 0x8080216C: lbu         $a0, 0x98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X98);
    after_0:
    // 0x80802170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802174: jal         0x80101870
    // 0x80802178: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80802178: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080217C: jal         0x80802320
    // 0x80802180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802320_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x80802180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080218C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802190: jr          $ra
    // 0x80802194: nop

    return;
    // 0x80802194: nop

;}
RECOMP_FUNC void _babounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845E8: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845E8);
    return;
    // 0x800845EC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80806D98_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806D98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806DA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80806DA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80806DA8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80806DAC: jal         0x80100094
    // 0x80806DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806DB4: lw          $t6, 0x6C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X6C);
    // 0x80806DB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80806DBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80806DC0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80806DC4: beql        $t7, $zero, L_80806E00
    if (ctx->r15 == 0) {
        // 0x80806DC8: lhu         $t0, 0x72($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X72);
            goto L_80806E00;
    }
    goto skip_0;
    // 0x80806DC8: lhu         $t0, 0x72($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X72);
    skip_0:
    // 0x80806DCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80806DD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80806DD4:
    // 0x80806DD4: jal         0x80087B00
    // 0x80806DD8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    _gczoombox_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80806DD8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806DDC: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
    // 0x80806DE0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80806DE4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80806DE8: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80806DEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80806DF0: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x80806DF4: bnel        $at, $zero, L_80806DD4
    if (ctx->r1 != 0) {
        // 0x80806DF8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80806DD4;
    }
    goto skip_1;
    // 0x80806DF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80806DFC: lhu         $t0, 0x72($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X72);
L_80806E00:
    // 0x80806E00: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80806E04: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80806E08: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80806E0C: beq         $at, $zero, L_80806F98
    if (ctx->r1 == 0) {
        // 0x80806E10: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80806F98;
    }
    // 0x80806E10: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80806E14: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7D78) << 16);
    // 0x80806E18: addu        $at, $at, $t2
    gpr jr_addend_80806E20 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80806E1C: lw          $t2, 0x7D78($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7D78));
    // 0x80806E20: jr          $t2
    // 0x80806E24: nop

    switch (jr_addend_80806E20 >> 2) {
        case 0: goto L_80806E28; break;
        case 1: goto L_80806E58; break;
        case 2: goto L_80806EAC; break;
        case 3: goto L_80806ED0; break;
        case 4: goto L_80806F10; break;
        case 5: goto L_80806F70; break;
        default: switch_error(__func__, 0x80806E20, 0x80807D78);
    }
    // 0x80806E24: nop

L_80806E28:
    // 0x80806E28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806E2C: jal         0x80807790
    // 0x80806E30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80807790_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80806E30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80806E34: beql        $v0, $zero, L_80806F9C
    if (ctx->r2 == 0) {
        // 0x80806E38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806F9C;
    }
    goto skip_2;
    // 0x80806E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80806E3C: jal         0x80803CA0
    // 0x80806E40: nop

    func_80803CA0_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80806E40: nop

    after_3:
    // 0x80806E44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806E48: jal         0x808075D0
    // 0x80806E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808075D0_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80806E4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80806E50: b           L_80806F9C
    // 0x80806E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806E58:
    // 0x80806E58: jal         0x80807824
    // 0x80806E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80807824_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80806E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80806E60: jal         0x800D9078
    // 0x80806E64: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80806E64: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_6:
    // 0x80806E68: bne         $v0, $zero, L_80806E80
    if (ctx->r2 != 0) {
        // 0x80806E6C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80806E80;
    }
    // 0x80806E6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80806E70: jal         0x80016B30
    // 0x80806E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B30(rdram, ctx);
        goto after_7;
    // 0x80806E74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80806E78: beql        $v0, $zero, L_80806F9C
    if (ctx->r2 == 0) {
        // 0x80806E7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806F9C;
    }
    goto skip_3;
    // 0x80806E7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_80806E80:
    // 0x80806E80: jal         0x800AA0D0
    // 0x80806E84: nop

    func_800AA0D0(rdram, ctx);
        goto after_8;
    // 0x80806E84: nop

    after_8:
    // 0x80806E88: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80806E8C: bne         $at, $zero, L_80806E9C
    if (ctx->r1 != 0) {
        // 0x80806E90: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_80806E9C;
    }
    // 0x80806E90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80806E94: b           L_80806E9C
    // 0x80806E98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80806E9C;
    // 0x80806E98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80806E9C:
    // 0x80806E9C: jal         0x808075D0
    // 0x80806EA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808075D0_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80806EA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80806EA4: b           L_80806F9C
    // 0x80806EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806EAC:
    // 0x80806EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806EB0: jal         0x80807790
    // 0x80806EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80807790_chgameselect(rdram, ctx);
        goto after_10;
    // 0x80806EB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80806EB8: beq         $v0, $zero, L_80806F98
    if (ctx->r2 == 0) {
        // 0x80806EBC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80806F98;
    }
    // 0x80806EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806EC0: jal         0x808075D0
    // 0x80806EC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808075D0_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80806EC4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80806EC8: b           L_80806F9C
    // 0x80806ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806ED0:
    // 0x80806ED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806ED4: jal         0x80807790
    // 0x80806ED8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80807790_chgameselect(rdram, ctx);
        goto after_12;
    // 0x80806ED8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80806EDC: beql        $v0, $zero, L_80806F9C
    if (ctx->r2 == 0) {
        // 0x80806EE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806F9C;
    }
    goto skip_4;
    // 0x80806EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80806EE4: lw          $t3, 0x64($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X64);
    // 0x80806EE8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80806EEC: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x80806EF0: bgez        $t5, L_80806F00
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80806EF4: nop
    
            goto L_80806F00;
    }
    // 0x80806EF4: nop

    // 0x80806EF8: b           L_80806F00
    // 0x80806EFC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80806F00;
    // 0x80806EFC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80806F00:
    // 0x80806F00: jal         0x808075D0
    // 0x80806F04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808075D0_chgameselect(rdram, ctx);
        goto after_13;
    // 0x80806F04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80806F08: b           L_80806F9C
    // 0x80806F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806F0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806F10:
    // 0x80806F10: jal         0x80807824
    // 0x80806F14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80807824_chgameselect(rdram, ctx);
        goto after_14;
    // 0x80806F14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x80806F18: jal         0x800D9078
    // 0x80806F1C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_15;
    // 0x80806F1C: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_15:
    // 0x80806F20: bne         $v0, $zero, L_80806F3C
    if (ctx->r2 != 0) {
        // 0x80806F24: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80806F3C;
    }
    // 0x80806F24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80806F28: jal         0x80016B30
    // 0x80806F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B30(rdram, ctx);
        goto after_16;
    // 0x80806F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80806F30: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80806F34: bne         $v0, $s0, L_80806F50
    if (ctx->r2 != ctx->r16) {
        // 0x80806F38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80806F50;
    }
    // 0x80806F38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80806F3C:
    // 0x80806F3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806F40: jal         0x808075D0
    // 0x80806F44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808075D0_chgameselect(rdram, ctx);
        goto after_17;
    // 0x80806F44: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80806F48: b           L_80806F9C
    // 0x80806F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806F50:
    // 0x80806F50: jal         0x80016B30
    // 0x80806F54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80016B30(rdram, ctx);
        goto after_18;
    // 0x80806F54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x80806F58: bne         $v0, $s0, L_80806F98
    if (ctx->r2 != ctx->r16) {
        // 0x80806F5C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80806F98;
    }
    // 0x80806F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806F60: jal         0x808075D0
    // 0x80806F64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808075D0_chgameselect(rdram, ctx);
        goto after_19;
    // 0x80806F64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x80806F68: b           L_80806F9C
    // 0x80806F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806F9C;
    // 0x80806F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806F70:
    // 0x80806F70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80806F74: jal         0x80807790
    // 0x80806F78: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80807790_chgameselect(rdram, ctx);
        goto after_20;
    // 0x80806F78: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_20:
    // 0x80806F7C: beq         $v0, $zero, L_80806F98
    if (ctx->r2 == 0) {
        // 0x80806F80: addiu       $a1, $zero, 0x23
        ctx->r5 = ADD32(0, 0X23);
            goto L_80806F98;
    }
    // 0x80806F80: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80806F84: lw          $a0, 0x3C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X3C);
    // 0x80806F88: jal         0x8010114C
    // 0x80806F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_21;
    // 0x80806F8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80806F90: jal         0x800FFAB0
    // 0x80806F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_22;
    // 0x80806F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
L_80806F98:
    // 0x80806F98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806F9C:
    // 0x80806F9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80806FA0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80806FA4: jr          $ra
    // 0x80806FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80806FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A7D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7D84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7D8C: jal         0x800D8FF8
    // 0x800A7D90: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800A7D90: nop

    after_0:
    // 0x800A7D94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7D98: addiu       $v1, $v1, 0x7630
    ctx->r3 = ADD32(ctx->r3, 0X7630);
    // 0x800A7D9C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800A7DA0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A7DA4: jal         0x800C9510
    // 0x800A7DA8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    func_800C9510(rdram, ctx);
        goto after_1;
    // 0x800A7DA8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    after_1:
    // 0x800A7DAC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7DB0: bne         $v0, $zero, L_800A7E28
    if (ctx->r2 != 0) {
        // 0x800A7DB4: addiu       $v1, $v1, 0x7630
        ctx->r3 = ADD32(ctx->r3, 0X7630);
            goto L_800A7E28;
    }
    // 0x800A7DB4: addiu       $v1, $v1, 0x7630
    ctx->r3 = ADD32(ctx->r3, 0X7630);
    // 0x800A7DB8: lbu         $v0, 0x12($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X12);
    // 0x800A7DBC: sb          $zero, 0x12($v1)
    MEM_B(0X12, ctx->r3) = 0;
    // 0x800A7DC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7DC4: beql        $v0, $zero, L_800A7E2C
    if (ctx->r2 == 0) {
        // 0x800A7DC8: lbu         $v0, 0x1A($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0X1A);
            goto L_800A7E2C;
    }
    goto skip_0;
    // 0x800A7DC8: lbu         $v0, 0x1A($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1A);
    skip_0:
    // 0x800A7DCC: beq         $v0, $at, L_800A7DEC
    if (ctx->r2 == ctx->r1) {
        // 0x800A7DD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A7DEC;
    }
    // 0x800A7DD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A7DD4: beq         $v0, $at, L_800A7DFC
    if (ctx->r2 == ctx->r1) {
        // 0x800A7DD8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A7DFC;
    }
    // 0x800A7DD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7DDC: beql        $v0, $at, L_800A7E10
    if (ctx->r2 == ctx->r1) {
        // 0x800A7DE0: lh          $a0, 0x10($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X10);
            goto L_800A7E10;
    }
    goto skip_1;
    // 0x800A7DE0: lh          $a0, 0x10($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X10);
    skip_1:
    // 0x800A7DE4: b           L_800A7E2C
    // 0x800A7DE8: lbu         $v0, 0x1A($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1A);
        goto L_800A7E2C;
    // 0x800A7DE8: lbu         $v0, 0x1A($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1A);
L_800A7DEC:
    // 0x800A7DEC: jal         0x800A76F4
    // 0x800A7DF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800A76F4(rdram, ctx);
        goto after_2;
    // 0x800A7DF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x800A7DF4: b           L_800A7FA4
    // 0x800A7DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A7FA4;
    // 0x800A7DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A7DFC:
    // 0x800A7DFC: jal         0x800A76F4
    // 0x800A7E00: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    func_800A76F4(rdram, ctx);
        goto after_3;
    // 0x800A7E00: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    after_3:
    // 0x800A7E04: b           L_800A7FA4
    // 0x800A7E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A7FA4;
    // 0x800A7E08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A7E0C: lh          $a0, 0x10($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X10);
L_800A7E10:
    // 0x800A7E10: jal         0x800A9924
    // 0x800A7E14: lbu         $a1, 0x13($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X13);
    func_800A9924(rdram, ctx);
        goto after_4;
    // 0x800A7E14: lbu         $a1, 0x13($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X13);
    after_4:
    // 0x800A7E18: jal         0x800A76F4
    // 0x800A7E1C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800A76F4(rdram, ctx);
        goto after_5;
    // 0x800A7E1C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x800A7E20: b           L_800A7FA4
    // 0x800A7E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A7FA4;
    // 0x800A7E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A7E28:
    // 0x800A7E28: lbu         $v0, 0x1A($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1A);
L_800A7E2C:
    // 0x800A7E2C: beq         $v0, $zero, L_800A7E48
    if (ctx->r2 == 0) {
        // 0x800A7E30: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_800A7E48;
    }
    // 0x800A7E30: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800A7E34: jal         0x800A759C
    // 0x800A7E38: lbu         $a1, 0x1B($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1B);
    func_800A759C(rdram, ctx);
        goto after_6;
    // 0x800A7E38: lbu         $a1, 0x1B($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1B);
    after_6:
    // 0x800A7E3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7E40: addiu       $v1, $v1, 0x7630
    ctx->r3 = ADD32(ctx->r3, 0X7630);
    // 0x800A7E44: sb          $zero, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = 0;
L_800A7E48:
    // 0x800A7E48: jal         0x800EA170
    // 0x800A7E4C: nop

    func_800EA170(rdram, ctx);
        goto after_7;
    // 0x800A7E4C: nop

    after_7:
    // 0x800A7E50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A7E54: lw          $t6, -0x5C0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5C0C);
    // 0x800A7E58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800A7E5C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7E60: beq         $t6, $zero, L_800A7E7C
    if (ctx->r14 == 0) {
        // 0x800A7E64: nop
    
            goto L_800A7E7C;
    }
    // 0x800A7E64: nop

    // 0x800A7E68: lw          $t7, -0x5C10($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C10);
    // 0x800A7E6C: bne         $t7, $zero, L_800A7E7C
    if (ctx->r15 != 0) {
        // 0x800A7E70: nop
    
            goto L_800A7E7C;
    }
    // 0x800A7E70: nop

    // 0x800A7E74: jal         0x800A8278
    // 0x800A7E78: nop

    func_800A8278(rdram, ctx);
        goto after_8;
    // 0x800A7E78: nop

    after_8:
L_800A7E7C:
    // 0x800A7E7C: jal         0x800C7900
    // 0x800A7E80: nop

    func_800C7900(rdram, ctx);
        goto after_9;
    // 0x800A7E80: nop

    after_9:
    // 0x800A7E84: jal         0x800C427C
    // 0x800A7E88: nop

    func_800C427C(rdram, ctx);
        goto after_10;
    // 0x800A7E88: nop

    after_10:
    // 0x800A7E8C: jal         0x800FB968
    // 0x800A7E90: nop

    func_800FB968(rdram, ctx);
        goto after_11;
    // 0x800A7E90: nop

    after_11:
    // 0x800A7E94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7E98: addiu       $v1, $v1, 0x7630
    ctx->r3 = ADD32(ctx->r3, 0X7630);
    // 0x800A7E9C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800A7EA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A7EA4: beq         $v0, $at, L_800A7ECC
    if (ctx->r2 == ctx->r1) {
        // 0x800A7EA8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800A7ECC;
    }
    // 0x800A7EA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A7EAC: beq         $v0, $at, L_800A7F44
    if (ctx->r2 == ctx->r1) {
        // 0x800A7EB0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A7F44;
    }
    // 0x800A7EB0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A7EB4: bne         $v0, $at, L_800A7F80
    if (ctx->r2 != ctx->r1) {
        // 0x800A7EB8: nop
    
            goto L_800A7F80;
    }
    // 0x800A7EB8: nop

    // 0x800A7EBC: jal         0x800A9A14
    // 0x800A7EC0: nop

    func_800A9A14(rdram, ctx);
        goto after_12;
    // 0x800A7EC0: nop

    after_12:
    // 0x800A7EC4: b           L_800A7F80
    // 0x800A7EC8: nop

        goto L_800A7F80;
    // 0x800A7EC8: nop

L_800A7ECC:
    // 0x800A7ECC: jal         0x800D8FF8
    // 0x800A7ED0: nop

    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x800A7ED0: nop

    after_13:
    // 0x800A7ED4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7ED8: addiu       $v1, $v1, 0x7630
    ctx->r3 = ADD32(ctx->r3, 0X7630);
    // 0x800A7EDC: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800A7EE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7EE4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A7EE8: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x800A7EEC: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800A7EF0: lwc1        $f16, 0x55F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X55F8);
    // 0x800A7EF4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800A7EF8: nop

    // 0x800A7EFC: bc1fl       L_800A7F28
    if (!c1cs) {
        // 0x800A7F00: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_800A7F28;
    }
    goto skip_2;
    // 0x800A7F00: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800A7F04: jal         0x800C0A34
    // 0x800A7F08: nop

    func_800C0A34(rdram, ctx);
        goto after_14;
    // 0x800A7F08: nop

    after_14:
    // 0x800A7F0C: beq         $v0, $zero, L_800A7F24
    if (ctx->r2 == 0) {
        // 0x800A7F10: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_800A7F24;
    }
    // 0x800A7F10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A7F14: jal         0x800A759C
    // 0x800A7F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A759C(rdram, ctx);
        goto after_15;
    // 0x800A7F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A7F1C: b           L_800A7F80
    // 0x800A7F20: nop

        goto L_800A7F80;
    // 0x800A7F20: nop

L_800A7F24:
    // 0x800A7F24: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_800A7F28:
    // 0x800A7F28: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A7F2C: bne         $t8, $zero, L_800A7F80
    if (ctx->r24 != 0) {
        // 0x800A7F30: nop
    
            goto L_800A7F80;
    }
    // 0x800A7F30: nop

    // 0x800A7F34: jal         0x800A759C
    // 0x800A7F38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A759C(rdram, ctx);
        goto after_16;
    // 0x800A7F38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x800A7F3C: b           L_800A7F80
    // 0x800A7F40: nop

        goto L_800A7F80;
    // 0x800A7F40: nop

L_800A7F44:
    // 0x800A7F44: jal         0x800C0948
    // 0x800A7F48: nop

    func_800C0948(rdram, ctx);
        goto after_17;
    // 0x800A7F48: nop

    after_17:
    // 0x800A7F4C: beq         $v0, $zero, L_800A7F80
    if (ctx->r2 == 0) {
        // 0x800A7F50: nop
    
            goto L_800A7F80;
    }
    // 0x800A7F50: nop

    // 0x800A7F54: jal         0x800EA334
    // 0x800A7F58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA334(rdram, ctx);
        goto after_18;
    // 0x800A7F58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x800A7F5C: jal         0x800EA34C
    // 0x800A7F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA34C(rdram, ctx);
        goto after_19;
    // 0x800A7F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800A7F64: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A7F68: jal         0x800A759C
    // 0x800A7F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A759C(rdram, ctx);
        goto after_20;
    // 0x800A7F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x800A7F70: jal         0x800FFC14
    // 0x800A7F74: nop

    func_800FFC14(rdram, ctx);
        goto after_21;
    // 0x800A7F74: nop

    after_21:
    // 0x800A7F78: jal         0x800F8850
    // 0x800A7F7C: nop

    func_800F8850(rdram, ctx);
        goto after_22;
    // 0x800A7F7C: nop

    after_22:
L_800A7F80:
    // 0x800A7F80: jal         0x800A819C
    // 0x800A7F84: nop

    func_800A819C(rdram, ctx);
        goto after_23;
    // 0x800A7F84: nop

    after_23:
    // 0x800A7F88: beq         $v0, $zero, L_800A7F98
    if (ctx->r2 == 0) {
        // 0x800A7F8C: nop
    
            goto L_800A7F98;
    }
    // 0x800A7F8C: nop

    // 0x800A7F90: jal         0x800CA0A8
    // 0x800A7F94: nop

    func_800CA0A8(rdram, ctx);
        goto after_24;
    // 0x800A7F94: nop

    after_24:
L_800A7F98:
    // 0x800A7F98: jal         0x800C92A8
    // 0x800A7F9C: nop

    func_800C92A8(rdram, ctx);
        goto after_25;
    // 0x800A7F9C: nop

    after_25:
    // 0x800A7FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A7FA4:
    // 0x800A7FA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7FA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7FAC: jr          $ra
    // 0x800A7FB0: nop

    return;
    // 0x800A7FB0: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005F8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808005FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800600: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800604: jal         0x8008CDB8
    // 0x80800608: addiu       $a1, $zero, 0x292
    ctx->r5 = ADD32(0, 0X292);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800608: addiu       $a1, $zero, 0x292
    ctx->r5 = ADD32(0, 0X292);
    after_0:
    // 0x8080060C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800610: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080061C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800620: jal         0x8009FFD8
    // 0x80800624: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800624: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x8009B94C
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_2;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800634: jal         0x8009C984
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080063C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x8009BA68
    // 0x80800648: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800648: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_4:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x800A0CF4
    // 0x80800654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800654: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x80800660: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800664: jal         0x8009DF18
    // 0x80800668: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x80800668: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_6:
    // 0x8080066C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800670: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800674: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800678: jr          $ra
    // 0x8080067C: nop

    return;
    // 0x8080067C: nop

;}
RECOMP_FUNC void func_8009DBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DBF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009DBF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009DBF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8009DBFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8009DC00: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8009DC04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8009DC08: jal         0x8009DAAC
    // 0x8009DC0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8009DAAC(rdram, ctx);
        goto after_0;
    // 0x8009DC0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8009DC10: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8009DC14: jal         0x8009C128
    // 0x8009DC18: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x8009DC18: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8009DC1C: jal         0x8009D3D8
    // 0x8009DC20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8009D3D8(rdram, ctx);
        goto after_2;
    // 0x8009DC20: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8009DC24: beq         $v0, $zero, L_8009DC60
    if (ctx->r2 == 0) {
        // 0x8009DC28: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8009DC60;
    }
    // 0x8009DC28: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8009DC2C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8009DC30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009DC34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC38: lwc1        $f6, 0x5398($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5398);
    // 0x8009DC3C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8009DC40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8009DC44: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x8009DC48: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8009DC4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8009DC50: jal         0x800C4208
    // 0x8009DC54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C4208(rdram, ctx);
        goto after_3;
    // 0x8009DC54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8009DC58: b           L_8009DC8C
    // 0x8009DC5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009DC8C;
    // 0x8009DC5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC60:
    // 0x8009DC60: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8009DC64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009DC68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009DC6C: lwc1        $f10, 0x539C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X539C);
    // 0x8009DC70: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8009DC74: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    // 0x8009DC78: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x8009DC7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8009DC80: jal         0x800C4244
    // 0x8009DC84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800C4244(rdram, ctx);
        goto after_4;
    // 0x8009DC84: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8009DC88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009DC8C:
    // 0x8009DC8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009DC90: jr          $ra
    // 0x8009DC94: nop

    return;
    // 0x8009DC94: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D08: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D08);
    return;
    // 0x80087D0C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void ncba1p_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080087C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800880: jr          $ra
    // 0x80800884: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
    return;
    // 0x80800884: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
;}
RECOMP_FUNC void _chfireicestorm_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086858: syscall     389
    recomp_syscall_handler(rdram, ctx, 0x80086858);
    return;
    // 0x8008685C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_glidmake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8080000C: jal         0x800EEEA8
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EEEA8(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800024
    if (ctx->r2 == 0) {
        // 0x80800018: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800024;
    }
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: b           L_80800028
    // 0x80800020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800028;
    // 0x80800020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800024:
    // 0x80800024: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80800028:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800030: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_80800504_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080050C: jal         0x801018A4
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801018A4(rdram, ctx);
        goto after_0;
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800514: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800518: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x8080051C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800520: bgezl       $t9, L_80800548
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800524: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800548;
    }
    goto skip_0;
    // 0x80800524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800528: jal         0x80104130
    // 0x8080052C: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x8080052C: nop

    after_1:
    // 0x80800530: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800534: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080053C: jal         0x800DBEFC
    // 0x80800540: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800540: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x80800544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800548:
    // 0x80800548: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

;}
RECOMP_FUNC void func_800E3A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3A58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3A5C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3A64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3A68: jal         0x800CA9D8
    // 0x800E3A6C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA9D8(rdram, ctx);
        goto after_0;
    // 0x800E3A6C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3A78: jr          $ra
    // 0x800E3A7C: nop

    return;
    // 0x800E3A7C: nop

;}
RECOMP_FUNC void _bscrashout_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F40: syscall     35
    recomp_syscall_handler(rdram, ctx, 0x80082F40);
    return;
    // 0x80082F44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800644_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080064C: jal         0x8080050C
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080050C_chfootwear(rdram, ctx);
        goto after_0;
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void chstonedartgunhead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1872, 0XFB0) << 16);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: addiu       $v0, $v0, 0xFB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1872, 0XFB0));
    return;
    // 0x80800DA8: addiu       $v0, $v0, 0xFB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1872, 0XFB0));
    // 0x80800DAC: nop

;}
RECOMP_FUNC void func_8080000C_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80101FDC
    // 0x80800020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800024: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800028: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: beq         $a1, $at, L_8080004C
    if (ctx->r5 == ctx->r1) {
        // 0x80800034: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8080004C;
    }
    // 0x80800034: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80800038: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080003C: beq         $a1, $at, L_808000C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800040: nop
    
            goto L_808000C0;
    }
    // 0x80800040: nop

    // 0x80800044: b           L_808000F0
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F0;
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080004C:
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800050: jal         0x80089840
    // 0x80800054: addiu       $a3, $zero, 0x9E4
    ctx->r7 = ADD32(0, 0X9E4);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a3, $zero, 0x9E4
    ctx->r7 = ADD32(0, 0X9E4);
    after_1:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: jal         0x80100094
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800064: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800068: jal         0x80089850
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800070: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800074: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800078: jal         0x80089900
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800080: jal         0x80089860
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80089858
    // 0x80800090: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    _sumumbofx_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800090: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    after_6:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x800898B8
    // 0x8080009C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_7;
    // 0x8080009C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_7:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x800898F8
    // 0x808000A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sumumbofx_entrypoint_23(rdram, ctx);
        goto after_8;
    // 0x808000A8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x800898D8
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x808000B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808000B8: b           L_808000F0
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F0;
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C0:
    // 0x808000C0: jal         0x800DA524
    // 0x808000C4: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    func_800DA524(rdram, ctx);
        goto after_10;
    // 0x808000C4: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    after_10:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80100094
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: jal         0x800898C0
    // 0x808000DC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _sumumbofx_entrypoint_16(rdram, ctx);
        goto after_12;
    // 0x808000DC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_12:
    // 0x808000E0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808000E4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808000E8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_8080170C_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080170C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801718: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080171C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801720: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801724: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80801728: jal         0x80100094
    // 0x8080172C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080172C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801730: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80801734: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801738: slti        $at, $a3, 0xCEC
    ctx->r1 = SIGNED(ctx->r7) < 0XCEC ? 1 : 0;
    // 0x8080173C: bne         $at, $zero, L_80801764
    if (ctx->r1 != 0) {
        // 0x80801740: addiu       $t6, $a3, -0x1027
        ctx->r14 = ADD32(ctx->r7, -0X1027);
            goto L_80801764;
    }
    // 0x80801740: addiu       $t6, $a3, -0x1027
    ctx->r14 = ADD32(ctx->r7, -0X1027);
    // 0x80801744: sltiu       $at, $t6, 0x18
    ctx->r1 = ctx->r14 < 0X18 ? 1 : 0;
    // 0x80801748: beq         $at, $zero, L_808018D4
    if (ctx->r1 == 0) {
        // 0x8080174C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808018D4;
    }
    // 0x8080174C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801750: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2CFC) << 16);
    // 0x80801754: addu        $at, $at, $t6
    gpr jr_addend_8080175C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801758: lw          $t6, 0x2CFC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2CFC));
    // 0x8080175C: jr          $t6
    // 0x80801760: nop

    switch (jr_addend_8080175C >> 2) {
        case 0: goto L_80801778; break;
        case 1: goto L_80801778; break;
        case 2: goto L_808017C4; break;
        case 3: goto L_8080183C; break;
        case 4: goto L_80801810; break;
        case 5: goto L_808018D4; break;
        case 6: goto L_808018D4; break;
        case 7: goto L_808018D4; break;
        case 8: goto L_808018D4; break;
        case 9: goto L_808018D4; break;
        case 10: goto L_808018D4; break;
        case 11: goto L_808018D4; break;
        case 12: goto L_808018D4; break;
        case 13: goto L_808018D4; break;
        case 14: goto L_808018D4; break;
        case 15: goto L_8080186C; break;
        case 16: goto L_80801894; break;
        case 17: goto L_80801894; break;
        case 18: goto L_80801894; break;
        case 19: goto L_80801894; break;
        case 20: goto L_80801894; break;
        case 21: goto L_80801894; break;
        case 22: goto L_80801894; break;
        case 23: goto L_808018A8; break;
        default: switch_error(__func__, 0x8080175C, 0x80802CFC);
    }
    // 0x80801760: nop

L_80801764:
    // 0x80801764: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801768: beq         $a3, $at, L_808018B4
    if (ctx->r7 == ctx->r1) {
        // 0x8080176C: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_808018B4;
    }
    // 0x8080176C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80801770: b           L_808018D8
    // 0x80801774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x80801774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801778:
    // 0x80801778: jal         0x800FDC28
    // 0x8080177C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x8080177C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80801780: jal         0x80802288
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802288_changlerboss(rdram, ctx);
        goto after_2;
    // 0x80801784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801788: jal         0x800F54E4
    // 0x8080178C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x8080178C: nop

    after_3:
    // 0x80801790: jal         0x800878F8
    // 0x80801794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80801794: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80801798: jal         0x800DA544
    // 0x8080179C: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080179C: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    after_5:
    // 0x808017A0: jal         0x80088178
    // 0x808017A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808017A4: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_6:
    // 0x808017A8: jal         0x808016A8
    // 0x808017AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016A8_changlerboss(rdram, ctx);
        goto after_7;
    // 0x808017AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808017B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017B4: jal         0x808012E0
    // 0x808017B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_8;
    // 0x808017B8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x808017BC: b           L_808018D8
    // 0x808017C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x808017C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017C4:
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C8: jal         0x808012E0
    // 0x808017CC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_9;
    // 0x808017CC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_9:
    // 0x808017D0: jal         0x800D395C
    // 0x808017D4: nop

    func_800D395C(rdram, ctx);
        goto after_10;
    // 0x808017D4: nop

    after_10:
    // 0x808017D8: beq         $v0, $zero, L_808017F8
    if (ctx->r2 == 0) {
        // 0x808017DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017F8;
    }
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017E0: jal         0x80802288
    // 0x808017E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802288_changlerboss(rdram, ctx);
        goto after_11;
    // 0x808017E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808017E8: jal         0x80088180
    // 0x808017EC: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x808017EC: nop

    after_12:
    // 0x808017F0: b           L_808018D8
    // 0x808017F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x808017F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017F8:
    // 0x808017F8: jal         0x80108B04
    // 0x808017FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80108B04(rdram, ctx);
        goto after_13;
    // 0x808017FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80801800: jal         0x800DA544
    // 0x80801804: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x80801804: addiu       $a0, $zero, 0x377
    ctx->r4 = ADD32(0, 0X377);
    after_14:
    // 0x80801808: b           L_808018D8
    // 0x8080180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x8080180C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801810:
    // 0x80801810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801814: jal         0x80802288
    // 0x80801818: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80802288_changlerboss(rdram, ctx);
        goto after_15;
    // 0x80801818: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_15:
    // 0x8080181C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801820: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801828: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x8080182C: jal         0x808012E0
    // 0x80801830: sh          $t7, 0x92($v1)
    MEM_H(0X92, ctx->r3) = ctx->r15;
    func_808012E0_changlerboss(rdram, ctx);
        goto after_16;
    // 0x80801830: sh          $t7, 0x92($v1)
    MEM_H(0X92, ctx->r3) = ctx->r15;
    after_16:
    // 0x80801834: b           L_808018D8
    // 0x80801838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x80801838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080183C:
    // 0x8080183C: jal         0x80802288
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802288_changlerboss(rdram, ctx);
        goto after_17;
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801844: jal         0x808016A8
    // 0x80801848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016A8_changlerboss(rdram, ctx);
        goto after_18;
    // 0x80801848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080184C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801850: jal         0x808012E0
    // 0x80801854: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_19;
    // 0x80801854: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_19:
    // 0x80801858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080185C: jal         0x80109FE8
    // 0x80801860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_20;
    // 0x80801860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80801864: b           L_808018D8
    // 0x80801868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x80801868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080186C:
    // 0x8080186C: jal         0x80802288
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802288_changlerboss(rdram, ctx);
        goto after_21;
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801878: jal         0x808012E0
    // 0x8080187C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_22;
    // 0x8080187C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_22:
    // 0x80801880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801884: jal         0x80109FE8
    // 0x80801888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_23;
    // 0x80801888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8080188C: b           L_808018D8
    // 0x80801890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x80801890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801894:
    // 0x80801894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801898: jal         0x808012E0
    // 0x8080189C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_808012E0_changlerboss(rdram, ctx);
        goto after_24;
    // 0x8080189C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_24:
    // 0x808018A0: b           L_808018D8
    // 0x808018A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x808018A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018A8:
    // 0x808018A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808018AC: b           L_808018D4
    // 0x808018B0: sb          $t8, 0x12D($v0)
    MEM_B(0X12D, ctx->r2) = ctx->r24;
        goto L_808018D4;
    // 0x808018B0: sb          $t8, 0x12D($v0)
    MEM_B(0X12D, ctx->r2) = ctx->r24;
L_808018B4:
    // 0x808018B4: blez        $t9, L_808018CC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x808018B8: nop
    
            goto L_808018CC;
    }
    // 0x808018B8: nop

    // 0x808018BC: jal         0x80088188
    // 0x808018C0: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x808018C0: nop

    after_25:
    // 0x808018C4: b           L_808018D8
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808018D8;
    // 0x808018C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018CC:
    // 0x808018CC: jal         0x80088180
    // 0x808018D0: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_26;
    // 0x808018D0: nop

    after_26:
L_808018D4:
    // 0x808018D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808018D8:
    // 0x808018D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808018DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018E0: jr          $ra
    // 0x808018E4: nop

    return;
    // 0x808018E4: nop

;}
RECOMP_FUNC void func_80800698_chpowerhut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800698: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080069C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006A0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808006A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006A8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808006AC: jal         0x80100094
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006B4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x808006B8: lh          $a2, 0xC($v0)
    ctx->r6 = MEM_H(ctx->r2, 0XC);
    // 0x808006BC: lbu         $a0, 0xE($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XE);
    // 0x808006C0: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x808006C4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1076, 0X9A0) << 16);
    // 0x808006C8: addiu       $a1, $v1, 0x18
    ctx->r5 = ADD32(ctx->r3, 0X18);
    // 0x808006CC: xori        $t6, $a2, 0x3
    ctx->r14 = ctx->r6 ^ 0X3;
    // 0x808006D0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808006D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808006DC: sltiu       $a2, $t6, 0x1
    ctx->r6 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808006E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808006E4: jal         0x80089D68
    // 0x808006E8: addiu       $a3, $a3, 0x9A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1076, 0X9A0));
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808006E8: addiu       $a3, $a3, 0x9A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1076, 0X9A0));
    after_1:
    // 0x808006EC: lh          $v1, 0xC($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC);
    // 0x808006F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808006F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006F8: beq         $v1, $at, L_80800720
    if (ctx->r3 == ctx->r1) {
        // 0x808006FC: sb          $v0, 0xE($s0)
        MEM_B(0XE, ctx->r16) = ctx->r2;
            goto L_80800720;
    }
    // 0x808006FC: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x80800700: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800704: beq         $v1, $at, L_80800750
    if (ctx->r3 == ctx->r1) {
        // 0x80800708: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800750;
    }
    // 0x80800708: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080070C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800710: beq         $v1, $at, L_808007CC
    if (ctx->r3 == ctx->r1) {
        // 0x80800714: nop
    
            goto L_808007CC;
    }
    // 0x80800714: nop

    // 0x80800718: b           L_80800860
    // 0x8080071C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800860;
    // 0x8080071C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800720:
    // 0x80800720: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80800724: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800728: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8080072C: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80800730: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80800734: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800738: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8080073C: nop

    // 0x80800740: bc1fl       L_80800860
    if (!c1cs) {
        // 0x80800744: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800860;
    }
    goto skip_0;
    // 0x80800744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800748: b           L_8080085C
    // 0x8080074C: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
        goto L_8080085C;
    // 0x8080074C: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
L_80800750:
    // 0x80800750: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1076, 0X9B4) << 16);
    // 0x80800754: jal         0x80089D18
    // 0x80800758: addiu       $a2, $a2, 0x9B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1076, 0X9B4));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800758: addiu       $a2, $a2, 0x9B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1076, 0X9B4));
    after_2:
    // 0x8080075C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80800760: sh          $t1, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r9;
    // 0x80800764: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800768: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1076, 0X964) << 16);
    // 0x8080076C: addiu       $a1, $a1, 0x964
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X964));
    // 0x80800770: lwc1        $f16, 0x10($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80800774: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x80800778: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8080077C: jal         0x800C8E84
    // 0x80800780: lw          $a0, 0x28($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x80800780: lw          $a0, 0x28($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X28);
    after_3:
    // 0x80800784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800788: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8080078C: jal         0x80018820
    // 0x80800790: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_4;
    // 0x80800790: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800794: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800798: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080079C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007A0: jal         0x800E15CC
    // 0x808007A4: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_5;
    // 0x808007A4: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_5:
    // 0x808007A8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x808007AC: jal         0x800DA544
    // 0x808007B0: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808007B0: lhu         $a0, 0x0($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X0);
    after_6:
    // 0x808007B4: addiu       $a0, $zero, 0x33D
    ctx->r4 = ADD32(0, 0X33D);
    // 0x808007B8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808007BC: jal         0x80101180
    // 0x808007C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x808007C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808007C4: b           L_80800860
    // 0x808007C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800860;
    // 0x808007C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007CC:
    // 0x808007CC: jal         0x800D9078
    // 0x808007D0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808007D0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_8:
    // 0x808007D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808007E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1076, 0X944) << 16);
    // 0x808007E4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x808007E8: jal         0x800DC298
    // 0x808007EC: lwc1        $f12, 0x944($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1076, 0X944));
    func_800DC298(rdram, ctx);
        goto after_9;
    // 0x808007EC: lwc1        $f12, 0x944($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1076, 0X944));
    after_9:
    // 0x808007F0: beq         $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x808007F4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1076, 0X948) << 16);
            goto L_80800834;
    }
    // 0x808007F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1076, 0X948) << 16);
    // 0x808007F8: lwc1        $f6, 0x948($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1076, 0X948));
    // 0x808007FC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800800: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800804: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800808: nop

    // 0x8080080C: bc1fl       L_80800838
    if (!c1cs) {
        // 0x80800810: lw          $t5, 0x38($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X38);
            goto L_80800838;
    }
    goto skip_1;
    // 0x80800810: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80800814: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800818: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080081C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800820: jal         0x800DC178
    // 0x80800824: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x80800824: nop

    after_10:
    // 0x80800828: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8080082C: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800830: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_80800834:
    // 0x80800834: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
L_80800838:
    // 0x80800838: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080083C: beq         $t5, $zero, L_80800854
    if (ctx->r13 == 0) {
        // 0x80800840: nop
    
            goto L_80800854;
    }
    // 0x80800840: nop

    // 0x80800844: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800848: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8080084C: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
    // 0x80800850: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
L_80800854:
    // 0x80800854: jal         0x80800870
    // 0x80800858: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800870_chpowerhut(rdram, ctx);
        goto after_11;
    // 0x80800858: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_11:
L_8080085C:
    // 0x8080085C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800860:
    // 0x80800860: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800864: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800868: jr          $ra
    // 0x8080086C: nop

    return;
    // 0x8080086C: nop

;}
RECOMP_FUNC void func_808003BC_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: jal         0x800A4CA8
    // 0x808003C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x808003C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003CC: jal         0x80089418
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003D8: bnel        $v0, $at, L_80800418
    if (ctx->r2 != ctx->r1) {
        // 0x808003DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800418;
    }
    goto skip_0;
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003E0: jal         0x800A4CA8
    // 0x808003E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800A4CA8(rdram, ctx);
        goto after_2;
    // 0x808003E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808003E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003EC: jal         0x80089408
    // 0x808003F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _ncba1p_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808003F0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x808003F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003FC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800400: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800404: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800408: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080040C: jal         0x8009C914
    // 0x80800410: nop

    yaw_setIdeal(rdram, ctx);
        goto after_4;
    // 0x80800410: nop

    after_4:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800418:
    // 0x80800418: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_808035C4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035C4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808035C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808035CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808035D0: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x808035D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808035D8: jal         0x80100094
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808035E0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x808035E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808035E8: jal         0x800DF744
    // 0x808035EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808035EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808035F0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x808035F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808035F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808035FC: lbu         $v0, 0x24($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X24);
    // 0x80803600: beq         $v0, $zero, L_80803708
    if (ctx->r2 == 0) {
        // 0x80803604: nop
    
            goto L_80803708;
    }
    // 0x80803604: nop

    // 0x80803608: beq         $v0, $at, L_808036AC
    if (ctx->r2 == ctx->r1) {
        // 0x8080360C: addiu       $a0, $sp, 0x60
        ctx->r4 = ADD32(ctx->r29, 0X60);
            goto L_808036AC;
    }
    // 0x8080360C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80803610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803614: beq         $v0, $at, L_8080362C
    if (ctx->r2 == ctx->r1) {
        // 0x80803618: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080362C;
    }
    // 0x80803618: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080361C: beql        $v0, $at, L_80803714
    if (ctx->r2 == ctx->r1) {
        // 0x80803620: addiu       $a0, $sp, 0x6C
        ctx->r4 = ADD32(ctx->r29, 0X6C);
            goto L_80803714;
    }
    goto skip_0;
    // 0x80803620: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    skip_0:
    // 0x80803624: b           L_80803738
    // 0x80803628: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
        goto L_80803738;
    // 0x80803628: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_8080362C:
    // 0x8080362C: jal         0x800E41CC
    // 0x80803630: nop

    func_800E41CC(rdram, ctx);
        goto after_2;
    // 0x80803630: nop

    after_2:
    // 0x80803634: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80803638: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080363C: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x80803640: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803644: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803648: jal         0x800EFA4C
    // 0x8080364C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x8080364C: nop

    after_3:
    // 0x80803650: jal         0x800EFD24
    // 0x80803654: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80803654: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x80803658: jal         0x800E3BAC
    // 0x8080365C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800E3BAC(rdram, ctx);
        goto after_5;
    // 0x8080365C: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_5:
    // 0x80803660: jal         0x800E3C30
    // 0x80803664: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800E3C30(rdram, ctx);
        goto after_6;
    // 0x80803664: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_6:
    // 0x80803668: jal         0x800E3CE8
    // 0x8080366C: nop

    func_800E3CE8(rdram, ctx);
        goto after_7;
    // 0x8080366C: nop

    after_7:
    // 0x80803670: jal         0x800E44FC
    // 0x80803674: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    func_800E44FC(rdram, ctx);
        goto after_8;
    // 0x80803674: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    after_8:
    // 0x80803678: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x8080367C: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x80803680: lui         $a2, 0xC334
    ctx->r6 = S32(0XC334 << 16);
    // 0x80803684: jal         0x800EFA4C
    // 0x80803688: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80803688: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x8080368C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80803690: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80803694: lui         $a2, 0xC334
    ctx->r6 = S32(0XC334 << 16);
    // 0x80803698: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080369C: jal         0x800EFA4C
    // 0x808036A0: lui         $a3, 0x4323
    ctx->r7 = S32(0X4323 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x808036A0: lui         $a3, 0x4323
    ctx->r7 = S32(0X4323 << 16);
    after_10:
    // 0x808036A4: b           L_80803738
    // 0x808036A8: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
        goto L_80803738;
    // 0x808036A8: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_808036AC:
    // 0x808036AC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808036B0: jal         0x800EE7F8
    // 0x808036B4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808036B4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_11:
    // 0x808036B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808036BC: jal         0x800EE7F8
    // 0x808036C0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x808036C0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x808036C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808036C8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808036CC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808036D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808036D4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x808036D8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808036DC: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x808036E0: lui         $a3, 0xC334
    ctx->r7 = S32(0XC334 << 16);
    // 0x808036E4: jal         0x800EF6A8
    // 0x808036E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_13;
    // 0x808036E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x808036EC: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x808036F0: jal         0x800EF04C
    // 0x808036F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x808036F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_14:
    // 0x808036F8: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808036FC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80803700: b           L_80803734
    // 0x80803704: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
        goto L_80803734;
    // 0x80803704: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
L_80803708:
    // 0x80803708: jal         0x800DF744
    // 0x8080370C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x8080370C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80803710: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
L_80803714:
    // 0x80803714: jal         0x800EE7F8
    // 0x80803718: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80803718: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x8080371C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80803720: jal         0x800EE7F8
    // 0x80803724: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80803724: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_17:
    // 0x80803728: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080372C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80803730: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
L_80803734:
    // 0x80803734: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_80803738:
    // 0x80803738: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080373C: bltz        $t9, L_8080374C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80803740: nop
    
            goto L_8080374C;
    }
    // 0x80803740: nop

    // 0x80803744: jal         0x808031C8
    // 0x80803748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808031C8_chflysaucer(rdram, ctx);
        goto after_18;
    // 0x80803748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_8080374C:
    // 0x8080374C: jal         0x80101970
    // 0x80803750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_19;
    // 0x80803750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80803754: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80803758: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x8080375C: jal         0x800DF47C
    // 0x80803760: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_20;
    // 0x80803760: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x80803764: jal         0x801018D8
    // 0x80803768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801018D8(rdram, ctx);
        goto after_21;
    // 0x80803768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080376C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80803770: jal         0x8010347C
    // 0x80803774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_22;
    // 0x80803774: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_22:
    // 0x80803778: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080377C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80803780: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80803784: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80803788: jal         0x800DE448
    // 0x8080378C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800DE448(rdram, ctx);
        goto after_23;
    // 0x8080378C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_23:
    // 0x80803790: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80803794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803798: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080379C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808037A0: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x808037A4: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x808037A8: sll         $t2, $t0, 19
    ctx->r10 = S32(ctx->r8 << 19);
    // 0x808037AC: bgezl       $t2, L_80803804
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808037B0: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80803804;
    }
    goto skip_1;
    // 0x808037B0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x808037B4: jal         0x801039E4
    // 0x808037B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_24;
    // 0x808037B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_24:
    // 0x808037BC: jal         0x800B27E0
    // 0x808037C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_25;
    // 0x808037C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x808037C4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808037C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037CC: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808037D0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x808037D4: jal         0x8080329C
    // 0x808037D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    func_8080329C_chflysaucer(rdram, ctx);
        goto after_26;
    // 0x808037D8: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    after_26:
    // 0x808037DC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x808037E0: jal         0x800AE080
    // 0x808037E4: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    func_800AE080(rdram, ctx);
        goto after_27;
    // 0x808037E4: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    after_27:
    // 0x808037E8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x808037EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808037F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808037F8: jal         0x800AE630
    // 0x808037FC: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    func_800AE630(rdram, ctx);
        goto after_28;
    // 0x808037FC: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    after_28:
    // 0x80803800: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80803804:
    // 0x80803804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803808: lbu         $t5, 0x24($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X24);
    // 0x8080380C: bnel        $t5, $at, L_80803828
    if (ctx->r13 != ctx->r1) {
        // 0x80803810: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80803828;
    }
    goto skip_2;
    // 0x80803810: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80803814: jal         0x800E4208
    // 0x80803818: nop

    func_800E4208(rdram, ctx);
        goto after_29;
    // 0x80803818: nop

    after_29:
    // 0x8080381C: jal         0x800E44FC
    // 0x80803820: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    func_800E44FC(rdram, ctx);
        goto after_30;
    // 0x80803820: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    after_30:
    // 0x80803824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803828:
    // 0x80803828: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080382C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80803830: jr          $ra
    // 0x80803834: nop

    return;
    // 0x80803834: nop

;}
RECOMP_FUNC void yaw_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C94C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C950: jal         0x800136E4
    // 0x8009C954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009C954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C958: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009C95C: lw          $t7, 0xF8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XF8);
    // 0x8009C960: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8009C964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C96C: jr          $ra
    // 0x8009C970: nop

    return;
    // 0x8009C970: nop

;}
RECOMP_FUNC void _chstatuebossbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086728: syscall     362
    recomp_syscall_handler(rdram, ctx, 0x80086728);
    return;
    // 0x8008672C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DE318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE318: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE31C: sw          $zero, -0x37DC($at)
    MEM_W(-0X37DC, ctx->r1) = 0;
    // 0x800DE320: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DE324: lwc1        $f4, 0x5D50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5D50);
    // 0x800DE328: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE32C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DE330: swc1        $f4, -0x37D4($at)
    MEM_W(-0X37D4, ctx->r1) = ctx->f4.u32l;
    // 0x800DE334: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE338: sw          $t6, -0x37D8($at)
    MEM_W(-0X37D8, ctx->r1) = ctx->r14;
    // 0x800DE33C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DE340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE344: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE348: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DE34C: swc1        $f6, -0x37D0($at)
    MEM_W(-0X37D0, ctx->r1) = ctx->f6.u32l;
    // 0x800DE350: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE354: sw          $zero, -0x37CC($at)
    MEM_W(-0X37CC, ctx->r1) = 0;
    // 0x800DE358: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE35C: sw          $zero, -0x37C8($at)
    MEM_W(-0X37C8, ctx->r1) = 0;
    // 0x800DE360: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE364: sw          $zero, -0x37C4($at)
    MEM_W(-0X37C4, ctx->r1) = 0;
    // 0x800DE368: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE36C: sw          $zero, -0x37BC($at)
    MEM_W(-0X37BC, ctx->r1) = 0;
    // 0x800DE370: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE374: sw          $zero, -0x37B8($at)
    MEM_W(-0X37B8, ctx->r1) = 0;
    // 0x800DE378: addiu       $v0, $v0, -0x36B8
    ctx->r2 = ADD32(ctx->r2, -0X36B8);
    // 0x800DE37C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DE380: addiu       $a2, $a2, -0x3658
    ctx->r6 = ADD32(ctx->r6, -0X3658);
    // 0x800DE384: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800DE388: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800DE38C: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800DE390: sb          $zero, 0x24($v0)
    MEM_B(0X24, ctx->r2) = 0;
    // 0x800DE394: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800DE398: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800DE39C: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x800DE3A0: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800DE3A4: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x800DE3A8: sw          $zero, 0x38($v0)
    MEM_W(0X38, ctx->r2) = 0;
    // 0x800DE3AC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800DE3B0: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800DE3B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE3B8: sw          $zero, -0x3648($at)
    MEM_W(-0X3648, ctx->r1) = 0;
    // 0x800DE3BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE3C0: sw          $zero, -0x35E8($at)
    MEM_W(-0X35E8, ctx->r1) = 0;
    // 0x800DE3C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DE3C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE3CC: addiu       $v1, $v1, -0x35C8
    ctx->r3 = ADD32(ctx->r3, -0X35C8);
    // 0x800DE3D0: sw          $zero, -0x35D8($at)
    MEM_W(-0X35D8, ctx->r1) = 0;
    // 0x800DE3D4: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800DE3D8: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x800DE3DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800DE3E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE3E4: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800DE3E8: lw          $t8, 0x3198($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X3198);
    // 0x800DE3EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE3F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE3F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800DE3F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800DE3FC: jal         0x800DF744
    // 0x800DE400: sw          $t8, -0x3074($at)
    MEM_W(-0X3074, ctx->r1) = ctx->r24;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x800DE400: sw          $t8, -0x3074($at)
    MEM_W(-0X3074, ctx->r1) = ctx->r24;
    after_0:
    // 0x800DE404: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800DE408: jal         0x800DF744
    // 0x800DE40C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x800DE40C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800DE410: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DE414: addiu       $v0, $v0, -0x3678
    ctx->r2 = ADD32(ctx->r2, -0X3678);
    // 0x800DE418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE41C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800DE420: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800DE424: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800DE428: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800DE42C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800DE430: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x800DE434: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x800DE438: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x800DE43C: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x800DE440: jr          $ra
    // 0x800DE444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800DE444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801B00_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801B0C: jal         0x80100094
    // 0x80801B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801B14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801B18: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801B1C: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x80801B20: sb          $t6, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r14;
    // 0x80801B24: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80801B28: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80801B2C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801B30: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
    // 0x80801B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801B3C: jr          $ra
    // 0x80801B40: nop

    return;
    // 0x80801B40: nop

;}
RECOMP_FUNC void func_800E4040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4048: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E404C: jal         0x800CA7AC
    // 0x800E4050: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA7AC(rdram, ctx);
        goto after_0;
    // 0x800E4050: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E4054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E405C: jr          $ra
    // 0x800E4060: nop

    return;
    // 0x800E4060: nop

;}
RECOMP_FUNC void func_800C59F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C59F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C59F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C59F8: jal         0x800C5968
    // 0x800C59FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800C5968(rdram, ctx);
        goto after_0;
    // 0x800C59FC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x800C5A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5A08: jr          $ra
    // 0x800C5A0C: nop

    return;
    // 0x800C5A0C: nop

;}
RECOMP_FUNC void func_80802844_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080284C: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80802850: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D88) << 16);
    // 0x80802854: lwc1        $f4, 0x2D88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D88));
    // 0x80802858: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x8080285C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80802860: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    // 0x80802864: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80802868: jal         0x800C8A98
    // 0x8080286C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x8080286C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802874: sw          $v0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r2;
    // 0x80802878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080287C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802880: jr          $ra
    // 0x80802884: nop

    return;
    // 0x80802884: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800410: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(392, 0X2130) << 16);
    // 0x80800414: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800418: jr          $ra
    // 0x8080041C: lw          $v0, 0x2130($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X2130));
    return;
    // 0x8080041C: lw          $v0, 0x2130($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(392, 0X2130));
;}
RECOMP_FUNC void func_808003D4_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808003E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808003E8: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x808003EC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808003F0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808003F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808003F8: nop

    // 0x808003FC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800400: beql        $t7, $zero, L_80800450
    if (ctx->r15 == 0) {
        // 0x80800404: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800450;
    }
    goto skip_0;
    // 0x80800404: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800408: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080040C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800410: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800414: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800418: nop

    // 0x8080041C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800420: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800424: nop

    // 0x80800428: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080042C: bne         $t7, $zero, L_80800444
    if (ctx->r15 != 0) {
        // 0x80800430: nop
    
            goto L_80800444;
    }
    // 0x80800430: nop

    // 0x80800434: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800438: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080043C: b           L_8080045C
    // 0x80800440: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8080045C;
    // 0x80800440: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800444:
    // 0x80800444: b           L_8080045C
    // 0x80800448: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8080045C;
    // 0x80800448: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080044C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800450:
    // 0x80800450: nop

    // 0x80800454: bltz        $t7, L_80800444
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800458: nop
    
            goto L_80800444;
    }
    // 0x80800458: nop

L_8080045C:
    // 0x8080045C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800460: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800464: beq         $at, $zero, L_808004C0
    if (ctx->r1 == 0) {
        // 0x80800468: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808004C0;
    }
    // 0x80800468: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080046C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XD14) << 16);
    // 0x80800470: addu        $at, $at, $t7
    gpr jr_addend_80800478 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800474: lw          $t7, 0xD14($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XD14));
    // 0x80800478: jr          $t7
    // 0x8080047C: nop

    switch (jr_addend_80800478 >> 2) {
        case 0: goto L_808004A0; break;
        case 1: goto L_808004A0; break;
        case 2: goto L_808004A0; break;
        case 3: goto L_808004A0; break;
        case 4: goto L_808004A0; break;
        case 5: goto L_808004A0; break;
        case 6: goto L_80800480; break;
        case 7: goto L_808004A0; break;
        default: switch_error(__func__, 0x80800478, 0x80800D14);
    }
    // 0x8080047C: nop

L_80800480:
    // 0x80800480: jal         0x800DA298
    // 0x80800484: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800484: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    after_0:
    // 0x80800488: bne         $v0, $zero, L_808004C0
    if (ctx->r2 != 0) {
        // 0x8080048C: addiu       $a0, $zero, 0x53
        ctx->r4 = ADD32(0, 0X53);
            goto L_808004C0;
    }
    // 0x8080048C: addiu       $a0, $zero, 0x53
    ctx->r4 = ADD32(0, 0X53);
    // 0x80800490: jal         0x800DA3B8
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800498: b           L_808004C4
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004C4;
    // 0x8080049C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004A0:
    // 0x808004A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004A4: jal         0x80089A68
    // 0x808004A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sumole_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x808004A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808004AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004B0: lbu         $t8, 0x72($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X72);
    // 0x808004B4: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x808004B8: ori         $t0, $t9, 0xC
    ctx->r8 = ctx->r25 | 0XC;
    // 0x808004BC: sb          $t0, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r8;
L_808004C0:
    // 0x808004C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004C4:
    // 0x808004C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void func_80801B44_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801B48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B50: lbu         $t6, 0x75($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X75);
    // 0x80801B54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B58: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x80801B5C: jal         0x8010A590
    // 0x80801B60: sb          $t7, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r15;
    func_8010A590(rdram, ctx);
        goto after_0;
    // 0x80801B60: sb          $t7, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r15;
    after_0:
    // 0x80801B64: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801B68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801B6C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80801B70: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B74: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801B78: jal         0x800DC178
    // 0x80801B7C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801B7C: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80801B80: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80801B84: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801B88: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80801B8C: jal         0x800DC178
    // 0x80801B90: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801B90: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80801B94: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80801B98: jal         0x80801B00
    // 0x80801B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B00_chstoneballcontrol(rdram, ctx);
        goto after_3;
    // 0x80801B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801BA0: jal         0x800EA05C
    // 0x80801BA4: nop

    func_800EA05C(rdram, ctx);
        goto after_4;
    // 0x80801BA4: nop

    after_4:
    // 0x80801BA8: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x80801BAC: beq         $v0, $at, L_80801BC0
    if (ctx->r2 == ctx->r1) {
        // 0x80801BB0: lui         $at, 0xC296
        ctx->r1 = S32(0XC296 << 16);
            goto L_80801BC0;
    }
    // 0x80801BB0: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80801BB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801BB8: b           L_80801BCC
    // 0x80801BBC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80801BCC;
    // 0x80801BBC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_80801BC0:
    // 0x80801BC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4ED4) << 16);
    // 0x80801BC4: lwc1        $f8, 0x4ED4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4ED4));
    // 0x80801BC8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80801BCC:
    // 0x80801BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801BD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801BD8: jr          $ra
    // 0x80801BDC: nop

    return;
    // 0x80801BDC: nop

;}
RECOMP_FUNC void func_800F64A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F64A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F64A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F64AC: jal         0x800F543C
    // 0x800F64B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F543C(rdram, ctx);
        goto after_0;
    // 0x800F64B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F64B4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F64B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F64BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F64C0: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x800F64C4: beq         $t7, $zero, L_800F64D4
    if (ctx->r15 == 0) {
        // 0x800F64C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800F64D4;
    }
    // 0x800F64C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800F64CC: b           L_800F64D4
    // 0x800F64D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800F64D4;
    // 0x800F64D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F64D4:
    // 0x800F64D4: jr          $ra
    // 0x800F64D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F64D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void baalarm_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x808000C0: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x808000C4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808000C8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808000CC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808000D0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000D4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000DC: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x808000E0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x808000E4: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x808000E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000EC: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x808000F0: beql        $t7, $zero, L_8080026C
    if (ctx->r15 == 0) {
        // 0x808000F4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8080026C;
    }
    goto skip_0;
    // 0x808000F4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x808000F8: jal         0x8009C128
    // 0x808000FC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808000FC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_0:
    // 0x80800100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800108: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8080010C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800110: c.lt.s      $f30, $f4
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f30.fl < ctx->f4.fl;
    // 0x80800114: nop

    // 0x80800118: bc1fl       L_80800188
    if (!c1cs) {
        // 0x8080011C: mtc1        $zero, $f22
        ctx->f22.u32l = 0;
            goto L_80800188;
    }
    goto skip_1;
    // 0x8080011C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    skip_1:
    // 0x80800120: c.eq.s      $f6, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f6.fl == ctx->f30.fl;
    // 0x80800124: nop

    // 0x80800128: bc1tl       L_8080026C
    if (c1cs) {
        // 0x8080012C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8080026C;
    }
    goto skip_2;
    // 0x8080012C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80800130: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80800134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800138: jal         0x80800294
    // 0x8080013C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    func_80800294_baalarm(rdram, ctx);
        goto after_1;
    // 0x8080013C: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    after_1:
    // 0x80800140: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800144: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80800148: jal         0x800C35E8
    // 0x8080014C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    func_800C35E8(rdram, ctx);
        goto after_2;
    // 0x8080014C: lbu         $a0, 0x0($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X0);
    after_2:
    // 0x80800150: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80800154: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    // 0x80800158: jal         0x800C301C
    // 0x8080015C: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    func_800C301C(rdram, ctx);
        goto after_3;
    // 0x8080015C: lbu         $a0, 0x0($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X0);
    after_3:
    // 0x80800160: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80800164: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x80800168: jal         0x800C3058
    // 0x8080016C: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    func_800C3058(rdram, ctx);
        goto after_4;
    // 0x8080016C: lbu         $a0, 0x0($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X0);
    after_4:
    // 0x80800170: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80800174: jal         0x800C3BDC
    // 0x80800178: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80800178: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    after_5:
    // 0x8080017C: b           L_8080026C
    // 0x80800180: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8080026C;
    // 0x80800180: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800184: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
L_80800188:
    // 0x80800188: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080018C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800190: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800194: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x80800198: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x8080019C: bc1fl       L_8080026C
    if (!c1cs) {
        // 0x808001A0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8080026C;
    }
    goto skip_3;
    // 0x808001A0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x808001A4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808001A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(447, 0X2E0) << 16);
    // 0x808001AC: lwc1        $f24, 0x2E0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X2E0));
    // 0x808001B0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
L_808001B4:
    // 0x808001B4: xori        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 ^ 0X1;
    // 0x808001B8: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x808001BC: nop

    // 0x808001C0: bc1fl       L_8080023C
    if (!c1cs) {
        // 0x808001C4: mfc1        $a2, $f28
        ctx->r6 = (int32_t)ctx->f28.u32l;
            goto L_8080023C;
    }
    goto skip_4;
    // 0x808001C4: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    skip_4:
    // 0x808001C8: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x808001CC: nop

    // 0x808001D0: bc1fl       L_8080023C
    if (!c1cs) {
        // 0x808001D4: mfc1        $a2, $f28
        ctx->r6 = (int32_t)ctx->f28.u32l;
            goto L_8080023C;
    }
    goto skip_5;
    // 0x808001D4: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    skip_5:
    // 0x808001D8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x808001DC: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x808001E0: jal         0x800C35E8
    // 0x808001E4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    func_800C35E8(rdram, ctx);
        goto after_6;
    // 0x808001E4: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    after_6:
    // 0x808001E8: beq         $s0, $zero, L_808001F8
    if (ctx->r16 == 0) {
        // 0x808001EC: addiu       $a1, $zero, 0x438
        ctx->r5 = ADD32(0, 0X438);
            goto L_808001F8;
    }
    // 0x808001EC: addiu       $a1, $zero, 0x438
    ctx->r5 = ADD32(0, 0X438);
    // 0x808001F0: b           L_808001F8
    // 0x808001F4: addiu       $a1, $zero, 0x41C
    ctx->r5 = ADD32(0, 0X41C);
        goto L_808001F8;
    // 0x808001F4: addiu       $a1, $zero, 0x41C
    ctx->r5 = ADD32(0, 0X41C);
L_808001F8:
    // 0x808001F8: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x808001FC: jal         0x800C301C
    // 0x80800200: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    func_800C301C(rdram, ctx);
        goto after_7;
    // 0x80800200: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    after_7:
    // 0x80800204: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80800208: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    // 0x8080020C: jal         0x800C3058
    // 0x80800210: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    func_800C3058(rdram, ctx);
        goto after_8;
    // 0x80800210: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    after_8:
    // 0x80800214: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80800218: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080021C: jal         0x80800294
    // 0x80800220: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    func_80800294_baalarm(rdram, ctx);
        goto after_9;
    // 0x80800220: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    after_9:
    // 0x80800224: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80800228: jal         0x800C3BDC
    // 0x8080022C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_10;
    // 0x8080022C: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_10:
    // 0x80800230: b           L_8080026C
    // 0x80800234: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8080026C;
    // 0x80800234: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800238: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
L_8080023C:
    // 0x8080023C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800240: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x80800244: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800248: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8080024C: jal         0x800F10B4
    // 0x80800250: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800250: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_11:
    // 0x80800254: sub.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x80800258: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1tl       L_808001B4
    if (c1cs) {
        // 0x80800264: lwc1        $f8, 0x7C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
            goto L_808001B4;
    }
    goto skip_6;
    // 0x80800264: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    skip_6:
    // 0x80800268: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8080026C:
    // 0x8080026C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800270: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800274: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800278: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080027C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800280: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800284: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80800288: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8080028C: jr          $ra
    // 0x80800290: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800290: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80802A9C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802AA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AA4: jal         0x80100094
    // 0x80802AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802AA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802AAC: lbu         $t6, 0x49D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49D);
    // 0x80802AB0: beql        $t6, $zero, L_80802ACC
    if (ctx->r14 == 0) {
        // 0x80802AB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802ACC;
    }
    goto skip_0;
    // 0x80802AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802AB8: jal         0x80085710
    // 0x80802ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80802ABC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802AC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802AC4: sb          $zero, 0x49D($v1)
    MEM_B(0X49D, ctx->r3) = 0;
    // 0x80802AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802ACC:
    // 0x80802ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802AD0: jr          $ra
    // 0x80802AD4: nop

    return;
    // 0x80802AD4: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C90: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C90);
    return;
    // 0x80083C94: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void gcnewoption_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801424: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80801428: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080142C: lh          $v0, 0xB0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XB0);
    // 0x80801430: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801434: jr          $ra
    // 0x80801438: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x80801438: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void _baeggcursor_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AE0: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AE0);
    return;
    // 0x80084AE4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void sukickball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: jal         0x800EA05C
    // 0x80800460: nop

    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800460: nop

    after_0:
    // 0x80800464: slti        $at, $v0, 0x12F
    ctx->r1 = SIGNED(ctx->r2) < 0X12F ? 1 : 0;
    // 0x80800468: bne         $at, $zero, L_8080049C
    if (ctx->r1 != 0) {
        // 0x8080046C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080049C;
    }
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800470: addiu       $at, $zero, 0x12F
    ctx->r1 = ADD32(0, 0X12F);
    // 0x80800474: beq         $v0, $at, L_808004D0
    if (ctx->r2 == ctx->r1) {
        // 0x80800478: addiu       $at, $zero, 0x130
        ctx->r1 = ADD32(0, 0X130);
            goto L_808004D0;
    }
    // 0x80800478: addiu       $at, $zero, 0x130
    ctx->r1 = ADD32(0, 0X130);
    // 0x8080047C: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x80800480: addiu       $at, $zero, 0x17F
        ctx->r1 = ADD32(0, 0X17F);
            goto L_808004D8;
    }
    // 0x80800480: addiu       $at, $zero, 0x17F
    ctx->r1 = ADD32(0, 0X17F);
    // 0x80800484: beq         $v0, $at, L_808004E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800488: addiu       $at, $zero, 0x180
        ctx->r1 = ADD32(0, 0X180);
            goto L_808004E0;
    }
    // 0x80800488: addiu       $at, $zero, 0x180
    ctx->r1 = ADD32(0, 0X180);
    // 0x8080048C: beq         $v0, $at, L_808004E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800490: nop
    
            goto L_808004E0;
    }
    // 0x80800490: nop

    // 0x80800494: b           L_808004F4
    // 0x80800498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004F4;
    // 0x80800498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080049C:
    // 0x8080049C: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808004A0: beq         $v0, $at, L_808004E8
    if (ctx->r2 == ctx->r1) {
        // 0x808004A4: addiu       $at, $zero, 0xC6
        ctx->r1 = ADD32(0, 0XC6);
            goto L_808004E8;
    }
    // 0x808004A4: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x808004A8: beq         $v0, $at, L_808004C8
    if (ctx->r2 == ctx->r1) {
        // 0x808004AC: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_808004C8;
    }
    // 0x808004AC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x808004B0: beq         $v0, $at, L_808004D0
    if (ctx->r2 == ctx->r1) {
        // 0x808004B4: addiu       $at, $zero, 0xC9
        ctx->r1 = ADD32(0, 0XC9);
            goto L_808004D0;
    }
    // 0x808004B4: addiu       $at, $zero, 0xC9
    ctx->r1 = ADD32(0, 0XC9);
    // 0x808004B8: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x808004BC: addiu       $at, $zero, 0x12E
        ctx->r1 = ADD32(0, 0X12E);
            goto L_808004D8;
    }
    // 0x808004BC: addiu       $at, $zero, 0x12E
    ctx->r1 = ADD32(0, 0X12E);
    // 0x808004C0: bnel        $v0, $at, L_808004F4
    if (ctx->r2 != ctx->r1) {
        // 0x808004C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004F4;
    }
    goto skip_0;
    // 0x808004C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_808004C8:
    // 0x808004C8: b           L_808004F4
    // 0x808004CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004F4;
    // 0x808004CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D0:
    // 0x808004D0: b           L_808004F4
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004F4;
    // 0x808004D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D8:
    // 0x808004D8: b           L_808004F4
    // 0x808004DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808004F4;
    // 0x808004DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808004E0:
    // 0x808004E0: b           L_808004F4
    // 0x808004E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808004F4;
    // 0x808004E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808004E8:
    // 0x808004E8: b           L_808004F4
    // 0x808004EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808004F4;
    // 0x808004EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808004F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004F4:
    // 0x808004F4: jr          $ra
    // 0x808004F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808004F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009DE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009DE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009DE1C: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009DE20: jal         0x800C3D78
    // 0x8009DE24: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    func_800C3D78(rdram, ctx);
        goto after_0;
    // 0x8009DE24: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    after_0:
    // 0x8009DE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009DE2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009DE30: jr          $ra
    // 0x8009DE34: nop

    return;
    // 0x8009DE34: nop

;}
RECOMP_FUNC void func_80802E30_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802E30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802E38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802E3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802E40: jal         0x80106790
    // 0x80802E44: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802E44: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802E48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802E4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802E50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802E54: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x80802E58: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80802E5C: beql        $t9, $at, L_80802E94
    if (ctx->r25 == ctx->r1) {
        // 0x80802E60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802E94;
    }
    goto skip_0;
    // 0x80802E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802E64: jal         0x80089AF8
    // 0x80802E68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80802E68: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80802E6C: beq         $v0, $zero, L_80802E90
    if (ctx->r2 == 0) {
        // 0x80802E70: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80802E90;
    }
    // 0x80802E70: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802E74: jal         0x800F5A00
    // 0x80802E78: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80802E78: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x80802E7C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80802E80: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80802E84: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80802E88: jal         0x80089B00
    // 0x80802E8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80802E8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
L_80802E90:
    // 0x80802E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802E94:
    // 0x80802E94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802E98: jr          $ra
    // 0x80802E9C: nop

    return;
    // 0x80802E9C: nop

;}
RECOMP_FUNC void bsstand_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808005F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005FC: jal         0x8008CABC
    // 0x80800600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800604: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800608: jal         0x8009EF10
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800610: bnel        $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x80800614: lw          $t7, 0x168($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X168);
            goto L_80800660;
    }
    goto skip_0;
    // 0x80800614: lw          $t7, 0x168($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X168);
    skip_0:
    // 0x80800618: jal         0x8009EF04
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_2;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800620: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800624: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800630: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800634: bc1fl       L_80800660
    if (!c1cs) {
        // 0x80800638: lw          $t7, 0x168($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X168);
            goto L_80800660;
    }
    goto skip_1;
    // 0x80800638: lw          $t7, 0x168($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X168);
    skip_1:
    // 0x8080063C: jal         0x8009C908
    // 0x80800640: sw          $t6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r14;
    yaw_setUpdateType(rdram, ctx);
        goto after_3;
    // 0x80800640: sw          $t6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r14;
    after_3:
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8080064C: jal         0x8009C99C
    // 0x80800650: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_4;
    // 0x80800650: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_4:
    // 0x80800654: b           L_80800690
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800690;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: lw          $t7, 0x168($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X168);
L_80800660:
    // 0x80800660: beql        $t7, $zero, L_80800680
    if (ctx->r15 == 0) {
        // 0x80800664: sw          $zero, 0x168($s0)
        MEM_W(0X168, ctx->r16) = 0;
            goto L_80800680;
    }
    goto skip_2;
    // 0x80800664: sw          $zero, 0x168($s0)
    MEM_W(0X168, ctx->r16) = 0;
    skip_2:
    // 0x80800668: jal         0x8009C984
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800670: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800674: jal         0x8009C914
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080067C: sw          $zero, 0x168($s0)
    MEM_W(0X168, ctx->r16) = 0;
L_80800680:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x8009C908
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_7;
    // 0x80800688: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800690:
    // 0x80800690: jal         0x80800038
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800038_bsstand(rdram, ctx);
        goto after_8;
    // 0x80800694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800698: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080069C: jal         0x80800000
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsstand(rdram, ctx);
        goto after_9;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006A4: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x808006A8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x808006AC: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x808006B0: andi        $t0, $v1, 0x8
    ctx->r8 = ctx->r3 & 0X8;
    // 0x808006B4: beq         $t0, $zero, L_808007A0
    if (ctx->r8 == 0) {
        // 0x808006B8: andi        $t3, $v1, 0x20
        ctx->r11 = ctx->r3 & 0X20;
            goto L_808007A0;
    }
    // 0x808006B8: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x808006BC: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x808006C0: beq         $t1, $zero, L_80800750
    if (ctx->r9 == 0) {
        // 0x808006C4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800750;
    }
    // 0x808006C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006C8: lui         $a1, 0x3DBA
    ctx->r5 = S32(0X3DBA << 16);
    // 0x808006CC: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    // 0x808006D0: jal         0x8008B348
    // 0x808006D4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x808006D4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_10:
    // 0x808006D8: beq         $v0, $zero, L_808006F0
    if (ctx->r2 == 0) {
        // 0x808006DC: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_808006F0;
    }
    // 0x808006DC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x8009D874
    // 0x808006E8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8009D874(rdram, ctx);
        goto after_11;
    // 0x808006E8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_11:
    // 0x808006EC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_808006F0:
    // 0x808006F0: lui         $a1, 0x3DBA
    ctx->r5 = S32(0X3DBA << 16);
    // 0x808006F4: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    // 0x808006F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006FC: jal         0x8008B348
    // 0x80800700: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    anctrl_isAt(rdram, ctx);
        goto after_12;
    // 0x80800700: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_12:
    // 0x80800704: beq         $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x80800708: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80800720;
    }
    // 0x80800708: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800714: jal         0x800A0CF4
    // 0x80800718: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800A0CF4(rdram, ctx);
        goto after_13;
    // 0x80800718: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_13:
    // 0x8080071C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80800720:
    // 0x80800720: lui         $a1, 0x3F2E
    ctx->r5 = S32(0X3F2E << 16);
    // 0x80800724: ori         $a1, $a1, 0x8A72
    ctx->r5 = ctx->r5 | 0X8A72;
    // 0x80800728: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080072C: jal         0x8008B348
    // 0x80800730: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    anctrl_isAt(rdram, ctx);
        goto after_14;
    // 0x80800730: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_14:
    // 0x80800734: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x80800738: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80800750;
    }
    // 0x80800738: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800744: jal         0x800A0CF4
    // 0x80800748: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800A0CF4(rdram, ctx);
        goto after_15;
    // 0x80800748: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_15:
    // 0x8080074C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
L_80800750:
    // 0x80800750: andi        $t2, $v1, 0x2
    ctx->r10 = ctx->r3 & 0X2;
    // 0x80800754: beq         $t2, $zero, L_808009BC
    if (ctx->r10 == 0) {
        // 0x80800758: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808009BC;
    }
    // 0x80800758: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080075C: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    // 0x80800760: jal         0x8008B348
    // 0x80800764: ori         $a1, $a1, 0xCFAB
    ctx->r5 = ctx->r5 | 0XCFAB;
    anctrl_isAt(rdram, ctx);
        goto after_16;
    // 0x80800764: ori         $a1, $a1, 0xCFAB
    ctx->r5 = ctx->r5 | 0XCFAB;
    after_16:
    // 0x80800768: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x8080076C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800778;
    }
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: jal         0x800A0CF4
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_17;
    // 0x80800774: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
L_80800778:
    // 0x80800778: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080077C: ori         $a1, $a1, 0xF972
    ctx->r5 = ctx->r5 | 0XF972;
    // 0x80800780: jal         0x8008B348
    // 0x80800784: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_18;
    // 0x80800784: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x80800788: beq         $v0, $zero, L_808009BC
    if (ctx->r2 == 0) {
        // 0x8080078C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009BC;
    }
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: jal         0x800A0CF4
    // 0x80800794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_19;
    // 0x80800794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800798: b           L_808009C0
    // 0x8080079C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
        goto L_808009C0;
    // 0x8080079C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_808007A0:
    // 0x808007A0: beq         $t3, $zero, L_808009AC
    if (ctx->r11 == 0) {
        // 0x808007A4: andi        $t4, $v1, 0x10
        ctx->r12 = ctx->r3 & 0X10;
            goto L_808009AC;
    }
    // 0x808007A4: andi        $t4, $v1, 0x10
    ctx->r12 = ctx->r3 & 0X10;
    // 0x808007A8: jal         0x8008B264
    // 0x808007AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getIndex(rdram, ctx);
        goto after_20;
    // 0x808007AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_20:
    // 0x808007B0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808007B4: bne         $v0, $at, L_8080082C
    if (ctx->r2 != ctx->r1) {
        // 0x808007B8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080082C;
    }
    // 0x808007B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: jal         0x80800274
    // 0x808007C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800274_bsstand(rdram, ctx);
        goto after_21;
    // 0x808007C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x808007C8: lui         $a1, 0x3EBD
    ctx->r5 = S32(0X3EBD << 16);
    // 0x808007CC: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808007D0: jal         0x8008B348
    // 0x808007D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_22;
    // 0x808007D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_22:
    // 0x808007D8: beql        $v0, $zero, L_808009C0
    if (ctx->r2 == 0) {
        // 0x808007DC: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_808009C0;
    }
    goto skip_3;
    // 0x808007DC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_3:
    // 0x808007E0: jal         0x8008AF24
    // 0x808007E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_reset(rdram, ctx);
        goto after_23;
    // 0x808007E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_23:
    // 0x808007E8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808007EC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808007F0: jal         0x8008B1C8
    // 0x808007F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8008B1C8(rdram, ctx);
        goto after_24;
    // 0x808007F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_24:
    // 0x808007F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007FC: jal         0x8008AED4
    // 0x80800800: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    anctrl_setIndex(rdram, ctx);
        goto after_25;
    // 0x80800800: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    after_25:
    // 0x80800804: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800808: jal         0x8008B1BC
    // 0x8080080C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_26;
    // 0x8080080C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_26:
    // 0x80800810: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800814: jal         0x8008B134
    // 0x80800818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_27;
    // 0x80800818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x8080081C: jal         0x8008B064
    // 0x80800820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_28;
    // 0x80800820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_28:
    // 0x80800824: b           L_808009C0
    // 0x80800828: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
        goto L_808009C0;
    // 0x80800828: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_8080082C:
    // 0x8080082C: lui         $a1, 0x3D8D
    ctx->r5 = S32(0X3D8D << 16);
    // 0x80800830: jal         0x8008B348
    // 0x80800834: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    anctrl_isAt(rdram, ctx);
        goto after_29;
    // 0x80800834: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    after_29:
    // 0x80800838: beq         $v0, $zero, L_80800854
    if (ctx->r2 == 0) {
        // 0x8080083C: lui         $a2, 0x3FB3
        ctx->r6 = S32(0X3FB3 << 16);
            goto L_80800854;
    }
    // 0x8080083C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800840: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800844: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800848: addiu       $a1, $zero, 0x434
    ctx->r5 = ADD32(0, 0X434);
    // 0x8080084C: jal         0x8009DF94
    // 0x80800850: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_30;
    // 0x80800850: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_30:
L_80800854:
    // 0x80800854: lui         $a1, 0x3E2B
    ctx->r5 = S32(0X3E2B << 16);
    // 0x80800858: ori         $a1, $a1, 0xB98C
    ctx->r5 = ctx->r5 | 0XB98C;
    // 0x8080085C: jal         0x8008B348
    // 0x80800860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_31;
    // 0x80800860: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_31:
    // 0x80800864: beq         $v0, $zero, L_8080087C
    if (ctx->r2 == 0) {
        // 0x80800868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080087C;
    }
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080086C: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x80800870: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800874: jal         0x8009DF94
    // 0x80800878: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_32;
    // 0x80800878: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_32:
L_8080087C:
    // 0x8080087C: lui         $a1, 0x3E79
    ctx->r5 = S32(0X3E79 << 16);
    // 0x80800880: ori         $a1, $a1, 0xF55A
    ctx->r5 = ctx->r5 | 0XF55A;
    // 0x80800884: jal         0x8008B348
    // 0x80800888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_33;
    // 0x80800888: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_33:
    // 0x8080088C: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x80800890: lui         $a2, 0x3F83
        ctx->r6 = S32(0X3F83 << 16);
            goto L_808008A8;
    }
    // 0x80800890: lui         $a2, 0x3F83
    ctx->r6 = S32(0X3F83 << 16);
    // 0x80800894: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080089C: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x808008A0: jal         0x8009DF94
    // 0x808008A4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_34;
    // 0x808008A4: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_34:
L_808008A8:
    // 0x808008A8: lui         $a1, 0x3EA0
    ctx->r5 = S32(0X3EA0 << 16);
    // 0x808008AC: ori         $a1, $a1, 0xD1B7
    ctx->r5 = ctx->r5 | 0XD1B7;
    // 0x808008B0: jal         0x8008B348
    // 0x808008B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_35;
    // 0x808008B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_35:
    // 0x808008B8: beq         $v0, $zero, L_808008D4
    if (ctx->r2 == 0) {
        // 0x808008BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D4;
    }
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: lui         $a2, 0x3F87
    ctx->r6 = S32(0X3F87 << 16);
    // 0x808008C4: ori         $a2, $a2, 0xAE14
    ctx->r6 = ctx->r6 | 0XAE14;
    // 0x808008C8: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x808008CC: jal         0x8009DF94
    // 0x808008D0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_36;
    // 0x808008D0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_36:
L_808008D4:
    // 0x808008D4: lui         $a1, 0x3EC5
    ctx->r5 = S32(0X3EC5 << 16);
    // 0x808008D8: ori         $a1, $a1, 0x94AF
    ctx->r5 = ctx->r5 | 0X94AF;
    // 0x808008DC: jal         0x8008B348
    // 0x808008E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_37;
    // 0x808008E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_37:
    // 0x808008E4: beq         $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008FC;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x808008F0: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x808008F4: jal         0x8009DF94
    // 0x808008F8: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    func_8009DF94(rdram, ctx);
        goto after_38;
    // 0x808008F8: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    after_38:
L_808008FC:
    // 0x808008FC: lui         $a1, 0x3ED3
    ctx->r5 = S32(0X3ED3 << 16);
    // 0x80800900: ori         $a1, $a1, 0xF7CF
    ctx->r5 = ctx->r5 | 0XF7CF;
    // 0x80800904: jal         0x8008B348
    // 0x80800908: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_39;
    // 0x80800908: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_39:
    // 0x8080090C: beq         $v0, $zero, L_80800924
    if (ctx->r2 == 0) {
        // 0x80800910: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800924;
    }
    // 0x80800910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800914: addiu       $a1, $zero, 0x41E
    ctx->r5 = ADD32(0, 0X41E);
    // 0x80800918: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080091C: jal         0x8009DF18
    // 0x80800920: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_40;
    // 0x80800920: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_40:
L_80800924:
    // 0x80800924: lui         $a1, 0x3F1E
    ctx->r5 = S32(0X3F1E << 16);
    // 0x80800928: ori         $a1, $a1, 0x6320
    ctx->r5 = ctx->r5 | 0X6320;
    // 0x8080092C: jal         0x8008B348
    // 0x80800930: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_41;
    // 0x80800930: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_41:
    // 0x80800934: beq         $v0, $zero, L_80800950
    if (ctx->r2 == 0) {
        // 0x80800938: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800950;
    }
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080093C: lui         $a2, 0x3FD9
    ctx->r6 = S32(0X3FD9 << 16);
    // 0x80800940: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800944: addiu       $a1, $zero, 0x445B
    ctx->r5 = ADD32(0, 0X445B);
    // 0x80800948: jal         0x8009DF94
    // 0x8080094C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_42;
    // 0x8080094C: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_42:
L_80800950:
    // 0x80800950: lui         $a1, 0x3F35
    ctx->r5 = S32(0X3F35 << 16);
    // 0x80800954: ori         $a1, $a1, 0xF6FD
    ctx->r5 = ctx->r5 | 0XF6FD;
    // 0x80800958: jal         0x8008B348
    // 0x8080095C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_43;
    // 0x8080095C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_43:
    // 0x80800960: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800964: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080097C;
    }
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x8080096C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800970: addiu       $a1, $zero, 0x445B
    ctx->r5 = ADD32(0, 0X445B);
    // 0x80800974: jal         0x8009DF94
    // 0x80800978: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_44;
    // 0x80800978: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_44:
L_8080097C:
    // 0x8080097C: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x80800980: ori         $a1, $a1, 0xEE63
    ctx->r5 = ctx->r5 | 0XEE63;
    // 0x80800984: jal         0x8008B348
    // 0x80800988: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_45;
    // 0x80800988: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_45:
    // 0x8080098C: beq         $v0, $zero, L_808009BC
    if (ctx->r2 == 0) {
        // 0x80800990: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009BC;
    }
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: addiu       $a1, $zero, 0x445B
    ctx->r5 = ADD32(0, 0X445B);
    // 0x80800998: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x8080099C: jal         0x8009DF94
    // 0x808009A0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF94(rdram, ctx);
        goto after_46;
    // 0x808009A0: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_46:
    // 0x808009A4: b           L_808009C0
    // 0x808009A8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
        goto L_808009C0;
    // 0x808009A8: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_808009AC:
    // 0x808009AC: beq         $t4, $zero, L_808009BC
    if (ctx->r12 == 0) {
        // 0x808009B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009BC;
    }
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B4: jal         0x80800274
    // 0x808009B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800274_bsstand(rdram, ctx);
        goto after_47;
    // 0x808009B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_47:
L_808009BC:
    // 0x808009BC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_808009C0:
    // 0x808009C0: ori         $a1, $a1, 0xF972
    ctx->r5 = ctx->r5 | 0XF972;
    // 0x808009C4: jal         0x8008B348
    // 0x808009C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_48;
    // 0x808009C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_48:
    // 0x808009CC: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x808009D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B30;
    }
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: jal         0x80800018
    // 0x808009D8: lw          $a1, 0x15C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X15C);
    func_80800018_bsstand(rdram, ctx);
        goto after_49;
    // 0x808009D8: lw          $a1, 0x15C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X15C);
    after_49:
    // 0x808009DC: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x808009E0: jal         0x80800000
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsstand(rdram, ctx);
        goto after_50;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808009E8: lw          $t5, 0x15C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X15C);
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x808009F4: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x808009F8: lbu         $v1, 0x0($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X0);
    // 0x808009FC: andi        $t7, $v1, 0x10
    ctx->r15 = ctx->r3 & 0X10;
    // 0x80800A00: beq         $t7, $zero, L_80800A34
    if (ctx->r15 == 0) {
        // 0x80800A04: andi        $t8, $v1, 0x40
        ctx->r24 = ctx->r3 & 0X40;
            goto L_80800A34;
    }
    // 0x80800A04: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x80800A08: jal         0x8008CCBC
    // 0x80800A0C: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_51;
    // 0x80800A0C: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_51:
    // 0x80800A10: jal         0x8008B064
    // 0x80800A14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_52;
    // 0x80800A14: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_52:
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: jal         0x800A0CF4
    // 0x80800A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_53;
    // 0x80800A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x80800A24: jal         0x80090A2C
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A2C(rdram, ctx);
        goto after_54;
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80800A2C: b           L_80800B30
    // 0x80800A30: nop

        goto L_80800B30;
    // 0x80800A30: nop

L_80800A34:
    // 0x80800A34: beq         $t8, $zero, L_80800A74
    if (ctx->r24 == 0) {
        // 0x80800A38: andi        $t9, $v1, 0x20
        ctx->r25 = ctx->r3 & 0X20;
            goto L_80800A74;
    }
    // 0x80800A38: andi        $t9, $v1, 0x20
    ctx->r25 = ctx->r3 & 0X20;
    // 0x80800A3C: lui         $a2, 0x4089
    ctx->r6 = S32(0X4089 << 16);
    // 0x80800A40: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A48: jal         0x8008CCBC
    // 0x80800A4C: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_55;
    // 0x80800A4C: addiu       $a1, $zero, 0xAE
    ctx->r5 = ADD32(0, 0XAE);
    after_55:
    // 0x80800A50: jal         0x8008B064
    // 0x80800A54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_56;
    // 0x80800A54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_56:
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: jal         0x800A0CF4
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_57;
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x80800A64: jal         0x80090A2C
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A2C(rdram, ctx);
        goto after_58;
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80800A6C: b           L_80800B30
    // 0x80800A70: nop

        goto L_80800B30;
    // 0x80800A70: nop

L_80800A74:
    // 0x80800A74: beq         $t9, $zero, L_80800AA8
    if (ctx->r25 == 0) {
        // 0x80800A78: andi        $t0, $v1, 0x8
        ctx->r8 = ctx->r3 & 0X8;
            goto L_80800AA8;
    }
    // 0x80800A78: andi        $t0, $v1, 0x8
    ctx->r8 = ctx->r3 & 0X8;
    // 0x80800A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A80: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x80800A84: jal         0x8008CCBC
    // 0x80800A88: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_59;
    // 0x80800A88: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_59:
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x800A0CF4
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_60;
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
    // 0x80800A98: jal         0x80090A2C
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A2C(rdram, ctx);
        goto after_61;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800AA0: b           L_80800B30
    // 0x80800AA4: nop

        goto L_80800B30;
    // 0x80800AA4: nop

L_80800AA8:
    // 0x80800AA8: beq         $t0, $zero, L_80800B30
    if (ctx->r8 == 0) {
        // 0x80800AAC: nop
    
            goto L_80800B30;
    }
    // 0x80800AAC: nop

    // 0x80800AB0: jal         0x8008B264
    // 0x80800AB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getIndex(rdram, ctx);
        goto after_62;
    // 0x80800AB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_62:
    // 0x80800AB8: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80800ABC: bnel        $v0, $at, L_80800AD8
    if (ctx->r2 != ctx->r1) {
        // 0x80800AC0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800AD8;
    }
    goto skip_4;
    // 0x80800AC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_4:
    // 0x80800AC4: jal         0x8008B2B4
    // 0x80800AC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_63;
    // 0x80800AC8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_63:
    // 0x80800ACC: b           L_80800AE4
    // 0x80800AD0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_80800AE4;
    // 0x80800AD0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800AD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800AD8:
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: jal         0x800909CC
    // 0x80800AE0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800909CC(rdram, ctx);
        goto after_64;
    // 0x80800AE0: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_64:
L_80800AE4:
    // 0x80800AE4: jal         0x8008AF24
    // 0x80800AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_reset(rdram, ctx);
        goto after_65;
    // 0x80800AE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_65:
    // 0x80800AEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF0: jal         0x8008AED4
    // 0x80800AF4: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    anctrl_setIndex(rdram, ctx);
        goto after_66;
    // 0x80800AF4: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    after_66:
    // 0x80800AF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AFC: jal         0x8008B1BC
    // 0x80800B00: lui         $a1, 0x40B0
    ctx->r5 = S32(0X40B0 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_67;
    // 0x80800B00: lui         $a1, 0x40B0
    ctx->r5 = S32(0X40B0 << 16);
    after_67:
    // 0x80800B04: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B08: jal         0x8008B134
    // 0x80800B0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_68;
    // 0x80800B0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_68:
    // 0x80800B10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B14: jal         0x8008B24C
    // 0x80800B18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setStart(rdram, ctx);
        goto after_69;
    // 0x80800B18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_69:
    // 0x80800B1C: jal         0x8008B064
    // 0x80800B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_start(rdram, ctx);
        goto after_70;
    // 0x80800B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_70:
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: jal         0x800A0CF4
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_71;
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_71:
L_80800B30:
    // 0x80800B30: jal         0x8008DD04
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_72;
    // 0x80800B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x80800B38: beq         $v0, $zero, L_80800B48
    if (ctx->r2 == 0) {
        // 0x80800B3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B48;
    }
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: addiu       $t1, $zero, 0x2F
    ctx->r9 = ADD32(0, 0X2F);
    // 0x80800B44: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_80800B48:
    // 0x80800B48: jal         0x8009E5C8
    // 0x80800B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_73;
    // 0x80800B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_73:
    // 0x80800B50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B5C: jr          $ra
    // 0x80800B60: nop

    return;
    // 0x80800B60: nop

;}
RECOMP_FUNC void func_800F3BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3BB8: jal         0x8009C128
    // 0x800F3BBC: nop

    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800F3BBC: nop

    after_0:
    // 0x800F3BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3BC8: jr          $ra
    // 0x800F3BCC: nop

    return;
    // 0x800F3BCC: nop

;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DB0: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084DB0);
    return;
    // 0x80084DB4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
