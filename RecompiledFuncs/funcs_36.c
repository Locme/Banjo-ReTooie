#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800478_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080047C: addiu       $at, $zero, 0x10B0
    ctx->r1 = ADD32(0, 0X10B0);
    // 0x80800480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800484: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800488: beq         $a1, $at, L_8080049C
    if (ctx->r5 == ctx->r1) {
        // 0x8080048C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080049C;
    }
    // 0x8080048C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800490: addiu       $at, $zero, 0x10B1
    ctx->r1 = ADD32(0, 0X10B1);
    // 0x80800494: bne         $a1, $at, L_808004AC
    if (ctx->r5 != ctx->r1) {
        // 0x80800498: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004AC;
    }
    // 0x80800498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080049C:
    // 0x8080049C: jal         0x800D1A04
    // 0x808004A0: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x808004A0: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_0:
    // 0x808004A4: b           L_808004B0
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808004B0;
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004AC:
    // 0x808004AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004B0:
    // 0x808004B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B4: jr          $ra
    // 0x808004B8: nop

    return;
    // 0x808004B8: nop

;}
RECOMP_FUNC void _chcauldronentrydoor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870B8: syscall     509
    recomp_syscall_handler(rdram, ctx, 0x800870B8);
    return;
    // 0x800870BC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800FA608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA608: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA60C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FA610: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FA614: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800FA618: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800FA61C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FA620: addiu       $s1, $s1, 0x3DC0
    ctx->r17 = ADD32(ctx->r17, 0X3DC0);
    // 0x800FA624: addiu       $s0, $s0, 0x3880
    ctx->r16 = ADD32(ctx->r16, 0X3880);
    // 0x800FA628: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
L_800FA62C:
    // 0x800FA62C: beql        $a0, $zero, L_800FA644
    if (ctx->r4 == 0) {
        // 0x800FA630: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800FA644;
    }
    goto skip_0;
    // 0x800FA630: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_0:
    // 0x800FA634: jal         0x8001BAFC
    // 0x800FA638: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800FA638: nop

    after_0:
    // 0x800FA63C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800FA640: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_800FA644:
    // 0x800FA644: bnel        $s0, $s1, L_800FA62C
    if (ctx->r16 != ctx->r17) {
        // 0x800FA648: lw          $a0, 0x18($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X18);
            goto L_800FA62C;
    }
    goto skip_1;
    // 0x800FA648: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x800FA64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FA650: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FA654: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA658: jr          $ra
    // 0x800FA65C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA65C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D3FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3FD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D3FD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3FDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D3FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3FE4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D3FE8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x800D3FEC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800D3FF0: jal         0x800D3E40
    // 0x800D3FF4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x800D3FF4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x800D3FF8: beq         $v0, $zero, L_800D406C
    if (ctx->r2 == 0) {
        // 0x800D3FFC: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_800D406C;
    }
    // 0x800D3FFC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800D4000: jal         0x800D42E8
    // 0x800D4004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_1;
    // 0x800D4004: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800D4008: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x800D400C: jal         0x800D42E8
    // 0x800D4010: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_2;
    // 0x800D4010: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800D4014: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800D4018: jal         0x800D42E8
    // 0x800D401C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_3;
    // 0x800D401C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800D4020: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800D4024: jal         0x800D42E8
    // 0x800D4028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_4;
    // 0x800D4028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800D402C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x800D4030: jal         0x800D42E8
    // 0x800D4034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_5;
    // 0x800D4034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800D4038: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800D403C: jal         0x800D42E8
    // 0x800D4040: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_6;
    // 0x800D4040: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800D4044: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800D4048: jal         0x800D42E8
    // 0x800D404C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D42E8(rdram, ctx);
        goto after_7;
    // 0x800D404C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800D4050: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D4054: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D4058: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D405C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800D4060: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800D4064: b           L_800D40F8
    // 0x800D4068: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_800D40F8;
    // 0x800D4068: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_800D406C:
    // 0x800D406C: jal         0x800D3E40
    // 0x800D4070: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800D3E40(rdram, ctx);
        goto after_8;
    // 0x800D4070: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x800D4074: beq         $v0, $zero, L_800D40C4
    if (ctx->r2 == 0) {
        // 0x800D4078: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_800D40C4;
    }
    // 0x800D4078: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800D407C: jal         0x800D4398
    // 0x800D4080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_9;
    // 0x800D4080: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x800D4084: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x800D4088: jal         0x800D4398
    // 0x800D408C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_10;
    // 0x800D408C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x800D4090: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800D4094: jal         0x800D4398
    // 0x800D4098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_11;
    // 0x800D4098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x800D409C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800D40A0: jal         0x800D4398
    // 0x800D40A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_12;
    // 0x800D40A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x800D40A8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x800D40AC: jal         0x800D4398
    // 0x800D40B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_13;
    // 0x800D40B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x800D40B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D40B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D40BC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800D40C0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
L_800D40C4:
    // 0x800D40C4: jal         0x800D3E40
    // 0x800D40C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D3E40(rdram, ctx);
        goto after_14;
    // 0x800D40C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
    // 0x800D40CC: beq         $v0, $zero, L_800D40F8
    if (ctx->r2 == 0) {
        // 0x800D40D0: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_800D40F8;
    }
    // 0x800D40D0: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800D40D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D40D8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800D40DC: jal         0x800D4398
    // 0x800D40E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_15;
    // 0x800D40E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x800D40E4: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800D40E8: jal         0x800D4398
    // 0x800D40EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D4398(rdram, ctx);
        goto after_16;
    // 0x800D40EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x800D40F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800D40F4: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_800D40F8:
    // 0x800D40F8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800D40FC: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800D4100: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4104: bne         $t3, $zero, L_800D4164
    if (ctx->r11 != 0) {
        // 0x800D4108: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800D4164;
    }
    // 0x800D4108: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D410C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D4110: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x800D4114: jal         0x800D433C
    // 0x800D4118: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    func_800D433C(rdram, ctx);
        goto after_17;
    // 0x800D4118: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    after_17:
    // 0x800D411C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x800D4120: jal         0x800D433C
    // 0x800D4124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_18;
    // 0x800D4124: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x800D4128: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800D412C: jal         0x800D433C
    // 0x800D4130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_19;
    // 0x800D4130: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_19:
    // 0x800D4134: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800D4138: jal         0x800D433C
    // 0x800D413C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_20;
    // 0x800D413C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_20:
    // 0x800D4140: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x800D4144: jal         0x800D433C
    // 0x800D4148: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_21;
    // 0x800D4148: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_21:
    // 0x800D414C: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800D4150: jal         0x800D433C
    // 0x800D4154: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_22;
    // 0x800D4154: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_22:
    // 0x800D4158: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800D415C: jal         0x800D433C
    // 0x800D4160: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D433C(rdram, ctx);
        goto after_23;
    // 0x800D4160: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_23:
L_800D4164:
    // 0x800D4164: bne         $s0, $zero, L_800D4174
    if (ctx->r16 != 0) {
        // 0x800D4168: addiu       $a0, $zero, 0x40
        ctx->r4 = ADD32(0, 0X40);
            goto L_800D4174;
    }
    // 0x800D4168: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x800D416C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800D4170: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_800D4174:
    // 0x800D4174: jal         0x800D4298
    // 0x800D4178: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800D4298(rdram, ctx);
        goto after_24;
    // 0x800D4178: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_24:
    // 0x800D417C: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    // 0x800D4180: jal         0x800D4298
    // 0x800D4184: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800D4298(rdram, ctx);
        goto after_25;
    // 0x800D4184: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_25:
    // 0x800D4188: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    // 0x800D418C: jal         0x800D4298
    // 0x800D4190: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800D4298(rdram, ctx);
        goto after_26;
    // 0x800D4190: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_26:
    // 0x800D4194: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x800D4198: jal         0x800D4298
    // 0x800D419C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800D4298(rdram, ctx);
        goto after_27;
    // 0x800D419C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_27:
    // 0x800D41A0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x800D41A4: jal         0x800D4298
    // 0x800D41A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800D4298(rdram, ctx);
        goto after_28;
    // 0x800D41A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_28:
    // 0x800D41AC: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x800D41B0: jal         0x800D4298
    // 0x800D41B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800D4298(rdram, ctx);
        goto after_29;
    // 0x800D41B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_29:
    // 0x800D41B8: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x800D41BC: jal         0x800D4298
    // 0x800D41C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D4298(rdram, ctx);
        goto after_30;
    // 0x800D41C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
    // 0x800D41C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D41C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D41CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D41D0: jr          $ra
    // 0x800D41D4: nop

    return;
    // 0x800D41D4: nop

;}
RECOMP_FUNC void func_808002FC_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800308: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x8080030C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1732, 0X4158) << 16);
    // 0x80800310: lui         $at, 0x3FFF
    ctx->r1 = S32(0X3FFF << 16);
    // 0x80800314: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800318: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8080031C: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80800320: lw          $v1, 0x4158($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1732, 0X4158));
    // 0x80800324: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800328: and         $t0, $v1, $at
    ctx->r8 = ctx->r3 & ctx->r1;
    // 0x8080032C: andi        $t1, $t0, 0x40
    ctx->r9 = ctx->r8 & 0X40;
    // 0x80800330: beq         $t1, $zero, L_80800350
    if (ctx->r9 == 0) {
        // 0x80800334: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80800350;
    }
    // 0x80800334: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80800338: jal         0x800DBFF8
    // 0x8080033C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800DBFF8(rdram, ctx);
        goto after_0;
    // 0x8080033C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800340: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80800344: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800348: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8080034C: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
L_80800350:
    // 0x80800350: andi        $t4, $v1, 0x1000
    ctx->r12 = ctx->r3 & 0X1000;
    // 0x80800354: beq         $t4, $zero, L_80800368
    if (ctx->r12 == 0) {
        // 0x80800358: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800368;
    }
    // 0x80800358: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080035C: jal         0x80105DFC
    // 0x80800360: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80105DFC(rdram, ctx);
        goto after_1;
    // 0x80800360: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800364: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80800368:
    // 0x80800368: andi        $t5, $v1, 0x20
    ctx->r13 = ctx->r3 & 0X20;
    // 0x8080036C: beql        $t5, $zero, L_8080038C
    if (ctx->r13 == 0) {
        // 0x80800370: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080038C;
    }
    goto skip_0;
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800374: jal         0x800AE020
    // 0x80800378: nop

    func_800AE020(rdram, ctx);
        goto after_2;
    // 0x80800378: nop

    after_2:
    // 0x8080037C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800380: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800384: sh          $v0, 0x10($t7)
    MEM_H(0X10, ctx->r15) = ctx->r2;
    // 0x80800388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080038C:
    // 0x8080038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895D0: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895D0);
    return;
    // 0x800895D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chfog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800CF494
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CF494(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void sufade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800080: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800084: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800088: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080008C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800090: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800098: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080009C: jal         0x800B28C4
    // 0x808000A0: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x808000A0: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    after_0:
    // 0x808000A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808000A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000AC: jal         0x800B296C
    // 0x808000B0: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x808000B0: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    after_1:
    // 0x808000B4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_80800100
    if (ctx->r1 == 0) {
        // 0x808000BC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800100;
    }
    // 0x808000BC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808000C0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3378, 0X160) << 16);
    // 0x808000C4: addiu       $s1, $s1, 0x160
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3378, 0X160));
    // 0x808000C8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_808000CC:
    // 0x808000CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000D0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808000D4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x808000D8: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x808000DC: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x808000E0: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x808000E4: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x808000E8: jal         0x800B99CC
    // 0x808000EC: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    func_800B99CC(rdram, ctx);
        goto after_2;
    // 0x808000EC: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    after_2:
    // 0x808000F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000F4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808000F8: bnel        $at, $zero, L_808000CC
    if (ctx->r1 != 0) {
        // 0x808000FC: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_808000CC;
    }
    goto skip_0;
    // 0x808000FC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_0:
L_80800100:
    // 0x80800100: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800104: jal         0x800B28B8
    // 0x80800108: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    vector_clear(rdram, ctx);
        goto after_3;
    // 0x80800108: lw          $a0, 0x7EF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF4);
    after_3:
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800110: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800114: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800120: jr          $ra
    // 0x80800124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801784_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801784: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801788: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080178C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801790: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80801794: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801798: jal         0x808016F0
    // 0x8080179C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_808016F0_subaddierouteDll(rdram, ctx);
        goto after_0;
    // 0x8080179C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808017A0: beq         $v0, $zero, L_808017B8
    if (ctx->r2 == 0) {
        // 0x808017A4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808017B8;
    }
    // 0x808017A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808017A8: beq         $v0, $at, L_80801808
    if (ctx->r2 == ctx->r1) {
        // 0x808017AC: nop
    
            goto L_80801808;
    }
    // 0x808017AC: nop

    // 0x808017B0: b           L_80801828
    // 0x808017B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801828;
    // 0x808017B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808017B8:
    // 0x808017B8: jal         0x80106790
    // 0x808017BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808017BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808017C0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808017C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808017C8: jal         0x800EC708
    // 0x808017CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800EC708(rdram, ctx);
        goto after_2;
    // 0x808017CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x808017D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3230, 0X18CC) << 16);
    // 0x808017D4: lwc1        $f4, 0x18CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3230, 0X18CC));
    // 0x808017D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017DC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808017E0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x808017E4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808017E8: jal         0x800EE7F8
    // 0x808017EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808017EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808017F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808017F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F8: jal         0x800EF11C
    // 0x808017FC: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    func_800EF11C(rdram, ctx);
        goto after_4;
    // 0x808017FC: addiu       $a1, $a1, 0x1E
    ctx->r5 = ADD32(ctx->r5, 0X1E);
    after_4:
    // 0x80801800: b           L_80801828
    // 0x80801804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801828;
    // 0x80801804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801808:
    // 0x80801808: jal         0x8008FE3C
    // 0x8080180C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008FE3C(rdram, ctx);
        goto after_5;
    // 0x8080180C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801810: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080181C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801820: b           L_80801828
    // 0x80801824: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_80801828;
    // 0x80801824: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80801828:
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
RECOMP_FUNC void func_80012194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012194: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80012198: lw          $t6, -0x166C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X166C);
    // 0x8001219C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800121A0: addiu       $t7, $t7, 0x7390
    ctx->r15 = ADD32(ctx->r15, 0X7390);
    // 0x800121A4: jr          $ra
    // 0x800121A8: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    return;
    // 0x800121A8: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CF0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CF0);
    return;
    // 0x80083CF4: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void func_80800414_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080041C: jal         0x80800374
    // 0x80800420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800374_chmasterjiggy(rdram, ctx);
        goto after_0;
    // 0x80800420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800424: beql        $v0, $zero, L_80800470
    if (ctx->r2 == 0) {
        // 0x80800428: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800470;
    }
    goto skip_0;
    // 0x80800428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080042C: jal         0x800DA298
    // 0x80800430: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800430: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    after_1:
    // 0x80800434: bne         $v0, $zero, L_80800454
    if (ctx->r2 != 0) {
        // 0x80800438: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800454;
    }
    // 0x80800438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: jal         0x808001D0
    // 0x80800440: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_2;
    // 0x80800440: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800444: beq         $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x80800448: nop
    
            goto L_80800454;
    }
    // 0x80800448: nop

    // 0x8080044C: jal         0x800DA544
    // 0x80800450: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800450: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    after_3:
L_80800454:
    // 0x80800454: jal         0x808003D4
    // 0x80800458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808003D4_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x80800458: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x8080045C: beq         $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800460: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080046C;
    }
    // 0x80800460: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800464: jal         0x80800220
    // 0x80800468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800220_chmasterjiggy(rdram, ctx);
        goto after_5;
    // 0x80800468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_8080046C:
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800470:
    // 0x80800470: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void gclightsDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080008C: jal         0x800B2D28
    // 0x80800090: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    vector_free(rdram, ctx);
        goto after_0;
    // 0x80800090: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80800DE0_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800DE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800DEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800DF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DF4: jal         0x80100094
    // 0x80800DF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DFC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800E00: jal         0x800A16BC
    // 0x80800E04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_1;
    // 0x80800E04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800E08: jal         0x80088368
    // 0x80800E0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800E0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x80800E10: blez        $v0, L_80800E7C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800E14: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_80800E7C;
    }
    // 0x80800E14: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80800E18: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E1C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80800E20: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x80800E24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800E28: addu        $s1, $v0, $t7
    ctx->r17 = ADD32(ctx->r2, ctx->r15);
    // 0x80800E2C: addu        $s2, $v0, $t6
    ctx->r18 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E30: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_80800E34:
    // 0x80800E34: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
    // 0x80800E38: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x80800E3C: sw          $zero, 0x48($s1)
    MEM_W(0X48, ctx->r17) = 0;
    // 0x80800E40: jal         0x800F53D0
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_3;
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E4C: jal         0x800946C4
    // 0x80800E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_4;
    // 0x80800E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800E54: addiu       $a0, $s0, 0xC3
    ctx->r4 = ADD32(ctx->r16, 0XC3);
    // 0x80800E58: jal         0x800D2748
    // 0x80800E5C: addiu       $a1, $s0, 0x5B
    ctx->r5 = ADD32(ctx->r16, 0X5B);
    func_800D2748(rdram, ctx);
        goto after_5;
    // 0x80800E5C: addiu       $a1, $s0, 0x5B
    ctx->r5 = ADD32(ctx->r16, 0X5B);
    after_5:
    // 0x80800E60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800E64: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800E68: jal         0x80088368
    // 0x80800E6C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800E6C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    after_6:
    // 0x80800E70: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800E74: bnel        $at, $zero, L_80800E34
    if (ctx->r1 != 0) {
        // 0x80800E78: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_80800E34;
    }
    goto skip_0;
    // 0x80800E78: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_0:
L_80800E7C:
    // 0x80800E7C: jal         0x8008A0A0
    // 0x80800E80: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _subaddiemulti_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800E80: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x80800E84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800E94: jr          $ra
    // 0x80800E98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800E98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8001DA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DA00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001DA04: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001DA08: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001DA0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001DA10: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001DA14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001DA18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001DA1C: sw          $zero, -0x27F0($at)
    MEM_W(-0X27F0, ctx->r1) = 0;
    // 0x8001DA20: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8001DA24: beq         $s0, $zero, L_8001DA44
    if (ctx->r16 == 0) {
        // 0x8001DA28: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8001DA44;
    }
    // 0x8001DA28: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8001DA2C:
    // 0x8001DA2C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8001DA30: jal         0x8001D800
    // 0x8001DA34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_8001D800(rdram, ctx);
        goto after_0;
    // 0x8001DA34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x8001DA38: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8001DA3C: bne         $s0, $zero, L_8001DA2C
    if (ctx->r16 != 0) {
        // 0x8001DA40: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8001DA2C;
    }
    // 0x8001DA40: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8001DA44:
    // 0x8001DA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001DA48: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001DA4C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001DA50: jr          $ra
    // 0x8001DA54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001DA54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A9318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9318: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A931C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A9320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A9324: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A9328: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A932C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9330: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A9334: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A9338: addiu       $s2, $s2, 0x76F0
    ctx->r18 = ADD32(ctx->r18, 0X76F0);
    // 0x800A933C: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A9340: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
L_800A9344:
    // 0x800A9344: beql        $a0, $zero, L_800A9358
    if (ctx->r4 == 0) {
        // 0x800A9348: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9358;
    }
    goto skip_0;
    // 0x800A9348: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800A934C: jal         0x8010FE34
    // 0x800A9350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8010FE34(rdram, ctx);
        goto after_0;
    // 0x800A9350: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800A9354: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A9358:
    // 0x800A9358: bnel        $s0, $s2, L_800A9344
    if (ctx->r16 != ctx->r18) {
        // 0x800A935C: lw          $a0, 0x58($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X58);
            goto L_800A9344;
    }
    goto skip_1;
    // 0x800A935C: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x800A9360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A9364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A9368: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A936C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A9370: jr          $ra
    // 0x800A9374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A9374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808011A8_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808011AC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808011B0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808011B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808011B8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808011BC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808011C0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808011C4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808011C8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808011CC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808011D0: jal         0x800B5BE4
    // 0x808011D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808011D4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_0:
    // 0x808011D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X12A4) << 16);
    // 0x808011DC: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(1092, 0X15A0) << 16);
    // 0x808011E0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1092, 0X15EC) << 16);
    // 0x808011E4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808011E8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x808011EC: addiu       $s1, $s1, 0x15EC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1092, 0X15EC));
    // 0x808011F0: addiu       $s5, $s5, 0x15A0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(1092, 0X15A0));
    // 0x808011F4: lwc1        $f20, 0x12A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X12A4));
    // 0x808011F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808011FC: lwc1        $f4, 0x38($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X38);
L_80801200:
    // 0x80801200: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80801204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801208: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8080120C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801210: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801214: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80801218: jal         0x800BABB8
    // 0x8080121C: nop

    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x8080121C: nop

    after_1:
    // 0x80801220: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801224: slt         $at, $s0, $s3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80801228: bnel        $at, $zero, L_80801200
    if (ctx->r1 != 0) {
        // 0x8080122C: lwc1        $f4, 0x38($s4)
        ctx->f4.u32l = MEM_W(ctx->r20, 0X38);
            goto L_80801200;
    }
    goto skip_0;
    // 0x8080122C: lwc1        $f4, 0x38($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X38);
    skip_0:
    // 0x80801230: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801234: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801238: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080123C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80801240: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80801244: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80801248: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8080124C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80801250: jr          $ra
    // 0x80801254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801254: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801258: nop

    // 0x8080125C: nop

;}
RECOMP_FUNC void func_800ED79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED79C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ED7A0: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800ED7A4: sll         $t7, $a3, 4
    ctx->r15 = S32(ctx->r7 << 4);
    // 0x800ED7A8: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x800ED7AC: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    // 0x800ED7B0: lwc1        $f6, 0x9C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x800ED7B4: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800ED7B8: lwc1        $f8, 0x94($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X94);
    // 0x800ED7BC: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED7C0: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED7C4: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800ED7C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED7CC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800ED7D0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800ED7D4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800ED7D8: beq         $at, $zero, L_800ED7F0
    if (ctx->r1 == 0) {
        // 0x800ED7DC: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED7F0;
    }
L_800ED7DC:
    // 0x800ED7DC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED7E0: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED7E4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED7E8: bne         $at, $zero, L_800ED7DC
    if (ctx->r1 != 0) {
        // 0x800ED7EC: sb          $v0, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r2;
            goto L_800ED7DC;
    }
    // 0x800ED7EC: sb          $v0, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r2;
L_800ED7F0:
    // 0x800ED7F0: jr          $ra
    // 0x800ED7F4: nop

    return;
    // 0x800ED7F4: nop

;}
RECOMP_FUNC void func_80804394_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080439C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808043A0: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x808043A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808043A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808043AC: beq         $v0, $zero, L_808043C4
    if (ctx->r2 == 0) {
        // 0x808043B0: nop
    
            goto L_808043C4;
    }
    // 0x808043B0: nop

    // 0x808043B4: beq         $v0, $at, L_80804404
    if (ctx->r2 == ctx->r1) {
        // 0x808043B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804404;
    }
    // 0x808043B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043BC: b           L_80804448
    // 0x808043C0: nop

        goto L_80804448;
    // 0x808043C0: nop

L_808043C4:
    // 0x808043C4: jal         0x8008CABC
    // 0x808043C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808043C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808043CC: jal         0x8008B324
    // 0x808043D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_1;
    // 0x808043D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808043D4: beq         $v0, $zero, L_80804448
    if (ctx->r2 == 0) {
        // 0x808043D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804448;
    }
    // 0x808043D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808043E0: jal         0x80085338
    // 0x808043E4: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    _batimer_set(rdram, ctx);
        goto after_2;
    // 0x808043E4: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_2:
    // 0x808043E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808043F0: jal         0x800A38F0
    // 0x808043F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_3;
    // 0x808043F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808043F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808043FC: b           L_80804448
    // 0x80804400: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80804448;
    // 0x80804400: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80804404:
    // 0x80804404: jal         0x800852F0
    // 0x80804408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_4;
    // 0x80804408: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8080440C: beq         $v0, $zero, L_80804448
    if (ctx->r2 == 0) {
        // 0x80804410: nop
    
            goto L_80804448;
    }
    // 0x80804410: nop

    // 0x80804414: jal         0x800D3948
    // 0x80804418: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x80804418: nop

    after_5:
    // 0x8080441C: beq         $v0, $zero, L_80804438
    if (ctx->r2 == 0) {
        // 0x80804420: addiu       $a0, $zero, 0x2C4
        ctx->r4 = ADD32(0, 0X2C4);
            goto L_80804438;
    }
    // 0x80804420: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80804424: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    // 0x80804428: jal         0x80101180
    // 0x8080442C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x8080442C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x80804430: b           L_80804444
    // 0x80804434: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
        goto L_80804444;
    // 0x80804434: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80804438:
    // 0x80804438: jal         0x80085200
    // 0x8080443C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x8080443C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80804440: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_80804444:
    // 0x80804444: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80804448:
    // 0x80804448: jal         0x80809198
    // 0x8080444C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809198_bsfirstp(rdram, ctx);
        goto after_8;
    // 0x8080444C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80804450: jal         0x80809250
    // 0x80804454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809250_bsfirstp(rdram, ctx);
        goto after_9;
    // 0x80804454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80804458: jal         0x80807D48
    // 0x8080445C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_10;
    // 0x8080445C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80804460: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804464: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804468: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080446C: jr          $ra
    // 0x80804470: nop

    return;
    // 0x80804470: nop

;}
RECOMP_FUNC void func_800B1508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1508: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800B150C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B1510: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B1514: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B1518: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B151C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B1520: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B1524: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B1528: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B152C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B1530: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B1534: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B1538: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x800B153C: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x800B1540: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x800B1544: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B1548: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x800B154C: lwc1        $f20, 0x114($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800B1550: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B1554: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B1558: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B155C: addu        $fp, $t7, $a0
    ctx->r30 = ADD32(ctx->r15, ctx->r4);
    // 0x800B1560: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x800B1564: sltu        $at, $s0, $fp
    ctx->r1 = ctx->r16 < ctx->r30 ? 1 : 0;
    // 0x800B1568: beq         $at, $zero, L_800B1934
    if (ctx->r1 == 0) {
        // 0x800B156C: addiu       $s7, $sp, 0x78
        ctx->r23 = ADD32(ctx->r29, 0X78);
            goto L_800B1934;
    }
    // 0x800B156C: addiu       $s7, $sp, 0x78
    ctx->r23 = ADD32(ctx->r29, 0X78);
    // 0x800B1570: addiu       $s6, $sp, 0xC8
    ctx->r22 = ADD32(ctx->r29, 0XC8);
    // 0x800B1574: addiu       $s5, $sp, 0xEC
    ctx->r21 = ADD32(ctx->r29, 0XEC);
    // 0x800B1578: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x800B157C: addiu       $s3, $sp, 0xA8
    ctx->r19 = ADD32(ctx->r29, 0XA8);
    // 0x800B1580: addiu       $s2, $sp, 0xB4
    ctx->r18 = ADD32(ctx->r29, 0XB4);
    // 0x800B1584: lw          $s1, 0x110($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X110);
    // 0x800B1588: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
L_800B158C:
    // 0x800B158C: lw          $t0, 0x118($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X118);
    // 0x800B1590: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B1594: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B1598: sllv        $t9, $t8, $v0
    ctx->r25 = S32(ctx->r24 << (ctx->r2 & 31));
    // 0x800B159C: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800B15A0: bne         $t1, $zero, L_800B1924
    if (ctx->r9 != 0) {
        // 0x800B15A4: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800B1924;
    }
    // 0x800B15A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B15A8: jal         0x800EE88C
    // 0x800B15AC: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800B15AC: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_0:
    // 0x800B15B0: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800B15B4: jal         0x800EE88C
    // 0x800B15B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x800B15B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800B15BC: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x800B15C0: jal         0x800EE88C
    // 0x800B15C4: addiu       $a1, $s0, 0x6
    ctx->r5 = ADD32(ctx->r16, 0X6);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x800B15C4: addiu       $a1, $s0, 0x6
    ctx->r5 = ADD32(ctx->r16, 0X6);
    after_2:
    // 0x800B15C8: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x800B15CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B15D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800B15D4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B15D8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x800B15DC: bgez        $t2, L_800B15F0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B15E0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B15F0;
    }
    // 0x800B15E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B15E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B15E8: nop

    // 0x800B15EC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B15F0:
    // 0x800B15F0: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800B15F4: lbu         $t3, 0x13($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X13);
    // 0x800B15F8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B15FC: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800B1600: bgez        $t3, L_800B1614
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1604: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800B1614;
    }
    // 0x800B1604: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B1608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B160C: nop

    // 0x800B1610: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800B1614:
    // 0x800B1614: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x800B1618: lbu         $t4, 0x14($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X14);
    // 0x800B161C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B1620: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B1624: bgez        $t4, L_800B1638
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B1628: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B1638;
    }
    // 0x800B1628: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B162C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1630: nop

    // 0x800B1634: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800B1638:
    // 0x800B1638: jal         0x800EF334
    // 0x800B163C: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x800B163C: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x800B1640: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x800B1644: jal         0x800ADE2C
    // 0x800B1648: lb          $a1, 0x16($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X16);
    func_800ADE2C(rdram, ctx);
        goto after_4;
    // 0x800B1648: lb          $a1, 0x16($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X16);
    after_4:
    // 0x800B164C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B1650: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800B1654: jal         0x80019AA0
    // 0x800B1658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_5;
    // 0x800B1658: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800B165C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B1660: jal         0x80019994
    // 0x800B1664: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_80019994(rdram, ctx);
        goto after_6;
    // 0x800B1664: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_6:
    // 0x800B1668: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B166C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x800B1670: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    // 0x800B1674: jal         0x80019480
    // 0x800B1678: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    func_80019480(rdram, ctx);
        goto after_7;
    // 0x800B1678: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    after_7:
    // 0x800B167C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B1680: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x800B1684: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    // 0x800B1688: jal         0x80019480
    // 0x800B168C: lw          $a3, 0xDC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XDC);
    func_80019480(rdram, ctx);
        goto after_8;
    // 0x800B168C: lw          $a3, 0xDC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XDC);
    after_8:
    // 0x800B1690: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B1694: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B1698: jal         0x800EFB24
    // 0x800B169C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800B169C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_9:
    // 0x800B16A0: jal         0x800EF2A0
    // 0x800B16A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_10;
    // 0x800B16A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x800B16A8: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x800B16AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B16B0: jal         0x800EFB24
    // 0x800B16B4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x800B16B4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_11:
    // 0x800B16B8: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B16BC: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B16C0: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B16C4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B16C8: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B16CC: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B16D0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800B16D4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B16D8: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B16DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B16E0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B16E4: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800B16E8: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800B16EC: c.le.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl <= ctx->f16.fl;
    // 0x800B16F0: nop

    // 0x800B16F4: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B16F8: nop
    
            goto L_800B191C;
    }
    // 0x800B16F8: nop

    // 0x800B16FC: jal         0x800EFB24
    // 0x800B1700: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x800B1700: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_12:
    // 0x800B1704: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1708: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B170C: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1710: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B1714: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B1718: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B171C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x800B1720: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B1724: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1728: lw          $a1, 0xD4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD4);
    // 0x800B172C: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    // 0x800B1730: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B1734: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B1738: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B173C: neg.s       $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = -ctx->f4.fl;
    // 0x800B1740: c.le.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl <= ctx->f16.fl;
    // 0x800B1744: nop

    // 0x800B1748: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B174C: nop
    
            goto L_800B191C;
    }
    // 0x800B174C: nop

    // 0x800B1750: jal         0x80019480
    // 0x800B1754: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    func_80019480(rdram, ctx);
        goto after_13;
    // 0x800B1754: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    after_13:
    // 0x800B1758: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B175C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800B1760: jal         0x800EFB24
    // 0x800B1764: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x800B1764: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_14:
    // 0x800B1768: jal         0x800EF2A0
    // 0x800B176C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_15;
    // 0x800B176C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_15:
    // 0x800B1770: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B1774: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B1778: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B177C: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B1780: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800B1784: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B1788: mul.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B178C: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1790: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B1794: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B1798: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B179C: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B17A0: c.le.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl <= ctx->f10.fl;
    // 0x800B17A4: nop

    // 0x800B17A8: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B17AC: nop
    
            goto L_800B191C;
    }
    // 0x800B17AC: nop

    // 0x800B17B0: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B17B4: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B17B8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800B17BC: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800B17C0: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B17C4: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x800B17C8: lw          $a2, 0xD8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD8);
    // 0x800B17CC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800B17D0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B17D4: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B17D8: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B17DC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800B17E0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800B17E4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B17E8: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800B17EC: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B17F0: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800B17F4: lwc1        $f6, 0xB8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B17F8: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B17FC: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x800B1800: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800B1804: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B1808: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B180C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B1810: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B1814: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800B1818: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x800B181C: nop

    // 0x800B1820: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B1824: nop
    
            goto L_800B191C;
    }
    // 0x800B1824: nop

    // 0x800B1828: jal         0x80019480
    // 0x800B182C: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    func_80019480(rdram, ctx);
        goto after_16;
    // 0x800B182C: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    after_16:
    // 0x800B1830: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800B1834: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B1838: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800B183C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B1840: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800B1844: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B1848: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800B184C: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800B1850: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x800B1854: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B1858: sub.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800B185C: swc1        $f8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f8.u32l;
    // 0x800B1860: jal         0x800EF2A0
    // 0x800B1864: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    func_800EF2A0(rdram, ctx);
        goto after_17;
    // 0x800B1864: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    after_17:
    // 0x800B1868: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800B186C: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B1870: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B1874: lwc1        $f16, 0xB8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B1878: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B187C: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B1880: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B1884: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1888: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800B188C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B1890: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B1894: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B1898: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x800B189C: nop

    // 0x800B18A0: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B18A4: nop
    
            goto L_800B191C;
    }
    // 0x800B18A4: nop

    // 0x800B18A8: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B18AC: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800B18B0: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B18B4: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800B18B8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800B18BC: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B18C0: sub.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800B18C4: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800B18C8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B18CC: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x800B18D0: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B18D4: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B18D8: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800B18DC: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800B18E0: lwc1        $f10, 0xB8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800B18E4: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B18E8: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x800B18EC: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B18F0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B18F4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B18F8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B18FC: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B1900: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x800B1904: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x800B1908: nop

    // 0x800B190C: bc1t        L_800B191C
    if (c1cs) {
        // 0x800B1910: nop
    
            goto L_800B191C;
    }
    // 0x800B1910: nop

    // 0x800B1914: b           L_800B1938
    // 0x800B1918: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
        goto L_800B1938;
    // 0x800B1918: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
L_800B191C:
    // 0x800B191C: jal         0x80018DAC
    // 0x800B1920: nop

    mlMtxPop(rdram, ctx);
        goto after_18;
    // 0x800B1920: nop

    after_18:
L_800B1924:
    // 0x800B1924: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800B1928: sltu        $at, $s0, $fp
    ctx->r1 = ctx->r16 < ctx->r30 ? 1 : 0;
    // 0x800B192C: bnel        $at, $zero, L_800B158C
    if (ctx->r1 != 0) {
        // 0x800B1930: lbu         $v0, 0x15($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X15);
            goto L_800B158C;
    }
    goto skip_0;
    // 0x800B1930: lbu         $v0, 0x15($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15);
    skip_0:
L_800B1934:
    // 0x800B1934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1938:
    // 0x800B1938: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B193C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B1940: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B1944: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B1948: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B194C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B1950: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B1954: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B1958: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B195C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1960: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B1964: jr          $ra
    // 0x800B1968: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x800B1968: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_800B5698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5698: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B569C: lbu         $t6, 0x7F1D($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7F1D);
    // 0x800B56A0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B56A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B56A8: beq         $t6, $zero, L_800B56C0
    if (ctx->r14 == 0) {
        // 0x800B56AC: nop
    
            goto L_800B56C0;
    }
    // 0x800B56AC: nop

    // 0x800B56B0: lh          $t7, 0x7F1A($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7F1A);
    // 0x800B56B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B56B8: jr          $ra
    // 0x800B56BC: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x800B56BC: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
L_800B56C0:
    // 0x800B56C0: jr          $ra
    // 0x800B56C4: nop

    return;
    // 0x800B56C4: nop

    // 0x800B56C8: nop

    // 0x800B56CC: nop

;}
RECOMP_FUNC void func_800DD07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD07C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DD080: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DD084: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800DD088: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800DD08C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800DD090: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800DD094: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800DD098: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800DD09C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800DD0A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800DD0A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DD0A8: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DD0AC: lui         $s7, 0xDE00
    ctx->r23 = S32(0XDE00 << 16);
    // 0x800DD0B0: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800DD0B4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800DD0B8: sw          $s7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r23;
    // 0x800DD0BC: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x800DD0C0: addiu       $fp, $fp, -0x36B8
    ctx->r30 = ADD32(ctx->r30, -0X36B8);
    // 0x800DD0C4: lw          $t8, 0x18($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X18);
    // 0x800DD0C8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800DD0CC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800DD0D0: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800DD0D4: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800DD0D8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800DD0DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800DD0E0: jal         0x8002E330
    // 0x800DD0E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_0;
    // 0x800DD0E4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x800DD0E8: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x800DD0EC: jal         0x80018C28
    // 0x800DD0F0: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_1;
    // 0x800DD0F0: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    after_1:
    // 0x800DD0F4: lh          $t9, 0xA($s6)
    ctx->r25 = MEM_H(ctx->r22, 0XA);
    // 0x800DD0F8: addiu       $s1, $s3, 0x2
    ctx->r17 = ADD32(ctx->r19, 0X2);
    // 0x800DD0FC: addiu       $s2, $s6, 0x2
    ctx->r18 = ADD32(ctx->r22, 0X2);
    // 0x800DD100: beq         $t9, $zero, L_800DD15C
    if (ctx->r25 == 0) {
        // 0x800DD104: lui         $s5, 0xDA38
        ctx->r21 = S32(0XDA38 << 16);
            goto L_800DD15C;
    }
    // 0x800DD104: lui         $s5, 0xDA38
    ctx->r21 = S32(0XDA38 << 16);
    // 0x800DD108: ori         $s5, $s5, 0x2
    ctx->r21 = ctx->r21 | 0X2;
    // 0x800DD10C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800DD110:
    // 0x800DD110: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x800DD114: lw          $t0, 0x4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X4);
    // 0x800DD118: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800DD11C: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x800DD120: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800DD124: sw          $s7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r23;
    // 0x800DD128: lh          $t1, 0x8($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X8);
    // 0x800DD12C: lw          $t3, 0x18($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X18);
    // 0x800DD130: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800DD134: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800DD138: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800DD13C: jal         0x8002E330
    // 0x800DD140: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800DD140: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_2:
    // 0x800DD144: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800DD148: lh          $t4, 0xA($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA);
    // 0x800DD14C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800DD150: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800DD154: bnel        $t4, $zero, L_800DD110
    if (ctx->r12 != 0) {
        // 0x800DD158: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800DD110;
    }
    goto skip_0;
    // 0x800DD158: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
L_800DD15C:
    // 0x800DD15C: lw          $t5, 0x4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X4);
    // 0x800DD160: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x800DD164: addiu       $t6, $t5, 0x40
    ctx->r14 = ADD32(ctx->r13, 0X40);
    // 0x800DD168: sw          $t6, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r14;
    // 0x800DD16C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DD170: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800DD174: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800DD178: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800DD17C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD180: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800DD184: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800DD188: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800DD18C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD190: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DD194: jr          $ra
    // 0x800DD198: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800DD198: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80801268_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080126C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801270: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801274: jal         0x808005F0
    // 0x80801278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80801278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080127C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80801280: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801288: addiu       $a1, $zero, 0x132
    ctx->r5 = ADD32(0, 0X132);
    // 0x8080128C: jal         0x8008CD30
    // 0x80801290: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_1;
    // 0x80801290: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_1:
    // 0x80801294: jal         0x8008CABC
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_2;
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080129C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012A0: jal         0x8008B134
    // 0x808012A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x808012A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808012A8: jal         0x8080009C
    // 0x808012AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_bskaztorpedo(rdram, ctx);
        goto after_4;
    // 0x808012AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808012B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012B4: jal         0x80095760
    // 0x808012B8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x808012B8: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_5:
    // 0x808012BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808012C0: nop

    // 0x808012C4: swc1        $f4, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f4.u32l;
    // 0x808012C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808012CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012D4: jr          $ra
    // 0x808012D8: nop

    return;
    // 0x808012D8: nop

;}
RECOMP_FUNC void chfantasylakebits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2376, 0XAF0) << 16);
    // 0x808008F4: jr          $ra
    // 0x808008F8: addiu       $v0, $v0, 0xAF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2376, 0XAF0));
    return;
    // 0x808008F8: addiu       $v0, $v0, 0xAF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2376, 0XAF0));
    // 0x808008FC: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800738: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(128, 0XFA8) << 16);
    // 0x8080073C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800740: jr          $ra
    // 0x80800744: lw          $v0, 0xFA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFA8));
    return;
    // 0x80800744: lw          $v0, 0xFA8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(128, 0XFA8));
;}
RECOMP_FUNC void func_808037C0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808037C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808037C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808037C8: jal         0x808036F8
    // 0x808037CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808037CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808037D0: beql        $v0, $zero, L_80803878
    if (ctx->r2 == 0) {
        // 0x808037D4: addiu       $v0, $zero, 0xA1
        ctx->r2 = ADD32(0, 0XA1);
            goto L_80803878;
    }
    goto skip_0;
    // 0x808037D4: addiu       $v0, $zero, 0xA1
    ctx->r2 = ADD32(0, 0XA1);
    skip_0:
    // 0x808037D8: jal         0x80088538
    // 0x808037DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _glsavegame_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808037DC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808037E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808037E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037E8: jal         0x800DAC78
    // 0x808037EC: addiu       $a1, $zero, 0x441
    ctx->r5 = ADD32(0, 0X441);
    func_800DAC78(rdram, ctx);
        goto after_2;
    // 0x808037EC: addiu       $a1, $zero, 0x441
    ctx->r5 = ADD32(0, 0X441);
    after_2:
    // 0x808037F0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808037F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808037F8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x808037FC: jal         0x800D046C
    // 0x80803800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800D046C(rdram, ctx);
        goto after_3;
    // 0x80803800: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80803804: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803808: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080380C: jal         0x800DAC78
    // 0x80803810: addiu       $a1, $zero, 0x360
    ctx->r5 = ADD32(0, 0X360);
    func_800DAC78(rdram, ctx);
        goto after_4;
    // 0x80803810: addiu       $a1, $zero, 0x360
    ctx->r5 = ADD32(0, 0X360);
    after_4:
    // 0x80803814: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80803818: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080381C: bne         $v1, $zero, L_8080383C
    if (ctx->r3 != 0) {
        // 0x80803820: nop
    
            goto L_8080383C;
    }
    // 0x80803820: nop

    // 0x80803824: beq         $t6, $zero, L_8080383C
    if (ctx->r14 == 0) {
        // 0x80803828: nop
    
            goto L_8080383C;
    }
    // 0x80803828: nop

    // 0x8080382C: bne         $v0, $zero, L_8080383C
    if (ctx->r2 != 0) {
        // 0x80803830: nop
    
            goto L_8080383C;
    }
    // 0x80803830: nop

    // 0x80803834: b           L_80803878
    // 0x80803838: addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
        goto L_80803878;
    // 0x80803838: addiu       $v0, $zero, 0xA4
    ctx->r2 = ADD32(0, 0XA4);
L_8080383C:
    // 0x8080383C: beq         $v1, $zero, L_80803854
    if (ctx->r3 == 0) {
        // 0x80803840: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80803854;
    }
    // 0x80803840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803844: beq         $v0, $zero, L_80803854
    if (ctx->r2 == 0) {
        // 0x80803848: nop
    
            goto L_80803854;
    }
    // 0x80803848: nop

    // 0x8080384C: b           L_80803878
    // 0x80803850: addiu       $v0, $zero, 0xA5
    ctx->r2 = ADD32(0, 0XA5);
        goto L_80803878;
    // 0x80803850: addiu       $v0, $zero, 0xA5
    ctx->r2 = ADD32(0, 0XA5);
L_80803854:
    // 0x80803854: jal         0x800DB83C
    // 0x80803858: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_800DB83C(rdram, ctx);
        goto after_5;
    // 0x80803858: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_5:
    // 0x8080385C: blez        $v0, L_8080386C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80803860: addiu       $v1, $zero, 0xA2
        ctx->r3 = ADD32(0, 0XA2);
            goto L_8080386C;
    }
    // 0x80803860: addiu       $v1, $zero, 0xA2
    ctx->r3 = ADD32(0, 0XA2);
    // 0x80803864: b           L_80803878
    // 0x80803868: addiu       $v0, $zero, 0xA3
    ctx->r2 = ADD32(0, 0XA3);
        goto L_80803878;
    // 0x80803868: addiu       $v0, $zero, 0xA3
    ctx->r2 = ADD32(0, 0XA3);
L_8080386C:
    // 0x8080386C: b           L_80803878
    // 0x80803870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80803878;
    // 0x80803870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80803874: addiu       $v0, $zero, 0xA1
    ctx->r2 = ADD32(0, 0XA1);
L_80803878:
    // 0x80803878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080387C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803880: jr          $ra
    // 0x80803884: nop

    return;
    // 0x80803884: nop

;}
RECOMP_FUNC void func_80800FFC_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FFC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801008: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8080100C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801010: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801014: jal         0x80100094
    // 0x80801018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080101C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801020: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80801024: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801028: nop

    // 0x8080102C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801030: nop

    // 0x80801034: bc1fl       L_80801070
    if (!c1cs) {
        // 0x80801038: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80801070;
    }
    goto skip_0;
    // 0x80801038: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8080103C: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x80801040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801044: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80801048: bltzl       $t8, L_80801070
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080104C: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80801070;
    }
    goto skip_1;
    // 0x8080104C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80801050: jal         0x80100094
    // 0x80801054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801058: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080105C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801060: jal         0x800DC128
    // 0x80801064: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80801064: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80801068: sh          $v0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r2;
    // 0x8080106C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_80801070:
    // 0x80801070: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801074: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801078: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8080107C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801080: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80801084: nop

    // 0x80801088: bc1f        L_808010A0
    if (!c1cs) {
        // 0x8080108C: nop
    
            goto L_808010A0;
    }
    // 0x8080108C: nop

    // 0x80801090: jal         0x80100094
    // 0x80801094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801098: b           L_808010A0
    // 0x8080109C: lh          $s0, 0xA($v0)
    ctx->r16 = MEM_H(ctx->r2, 0XA);
        goto L_808010A0;
    // 0x8080109C: lh          $s0, 0xA($v0)
    ctx->r16 = MEM_H(ctx->r2, 0XA);
L_808010A0:
    // 0x808010A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808010A4: jal         0x800DF744
    // 0x808010A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808010A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808010AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010B0: jal         0x80089CD8
    // 0x808010B4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808010B4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x808010B8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808010BC: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x808010C0: sltu        $s0, $zero, $a0
    ctx->r16 = 0 < ctx->r4 ? 1 : 0;
    // 0x808010C4: beql        $s0, $zero, L_808010DC
    if (ctx->r16 == 0) {
        // 0x808010C8: lbu         $t1, 0x74($s1)
        ctx->r9 = MEM_BU(ctx->r17, 0X74);
            goto L_808010DC;
    }
    goto skip_2;
    // 0x808010C8: lbu         $t1, 0x74($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X74);
    skip_2:
    // 0x808010CC: jal         0x800C9044
    // 0x808010D0: nop

    func_800C9044(rdram, ctx);
        goto after_6;
    // 0x808010D0: nop

    after_6:
    // 0x808010D4: sltu        $s0, $zero, $v0
    ctx->r16 = 0 < ctx->r2 ? 1 : 0;
    // 0x808010D8: lbu         $t1, 0x74($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X74);
L_808010DC:
    // 0x808010DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x808010E4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x808010E8: beq         $t2, $zero, L_80801100
    if (ctx->r10 == 0) {
        // 0x808010EC: addiu       $a2, $zero, 0xFF
        ctx->r6 = ADD32(0, 0XFF);
            goto L_80801100;
    }
    // 0x808010EC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x808010F0: jal         0x80089CF0
    // 0x808010F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    _subaddiefade_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x808010F4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x808010F8: b           L_80801124
    // 0x808010FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80801124;
    // 0x808010FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801100:
    // 0x80801100: beq         $s0, $zero, L_80801120
    if (ctx->r16 == 0) {
        // 0x80801104: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80801120;
    }
    // 0x80801104: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80801108: lw          $a0, 0x14($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X14);
    // 0x8080110C: jal         0x800C8900
    // 0x80801110: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8900(rdram, ctx);
        goto after_8;
    // 0x80801110: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x80801114: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801118: jal         0x80089CE8
    // 0x8080111C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x8080111C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
L_80801120:
    // 0x80801120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801124:
    // 0x80801124: jal         0x80101870
    // 0x80801128: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_80101870(rdram, ctx);
        goto after_10;
    // 0x80801128: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x8080112C: bne         $s0, $zero, L_80801144
    if (ctx->r16 != 0) {
        // 0x80801130: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801144;
    }
    // 0x80801130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801134: lbu         $t4, 0x74($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X74);
    // 0x80801138: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8080113C: beql        $t5, $zero, L_80801150
    if (ctx->r13 == 0) {
        // 0x80801140: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801150;
    }
    goto skip_3;
    // 0x80801140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_80801144:
    // 0x80801144: jal         0x80089CE8
    // 0x80801148: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80801148: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x8080114C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801150:
    // 0x80801150: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801154: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801158: jr          $ra
    // 0x8080115C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080115C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80091110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091114: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80091118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009111C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80091120: jal         0x800D9078
    // 0x80091124: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80091124: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    after_0:
    // 0x80091128: jal         0x800F40EC
    // 0x8009112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F40EC(rdram, ctx);
        goto after_1;
    // 0x8009112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80091130: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091134: bnel        $v0, $at, L_80091280
    if (ctx->r2 != ctx->r1) {
        // 0x80091138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80091280;
    }
    goto skip_0;
    // 0x80091138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8009113C: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80091140: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80091144: lbu         $t7, 0xE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XE);
    // 0x80091148: beql        $t7, $at, L_80091280
    if (ctx->r15 == ctx->r1) {
        // 0x8009114C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80091280;
    }
    goto skip_1;
    // 0x8009114C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80091150: jal         0x800D8FF8
    // 0x80091154: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80091154: nop

    after_2:
    // 0x80091158: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8009115C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80091160: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x80091164: beql        $t8, $zero, L_800911D0
    if (ctx->r24 == 0) {
        // 0x80091168: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_800911D0;
    }
    goto skip_2;
    // 0x80091168: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x8009116C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80091170: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80091174: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80091178: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8009117C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80091180: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80091184: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80091188: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8009118C: nop

    // 0x80091190: bc1fl       L_800911D0
    if (!c1cs) {
        // 0x80091194: lwc1        $f16, 0x4($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
            goto L_800911D0;
    }
    goto skip_3;
    // 0x80091194: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    skip_3:
    // 0x80091198: lwc1        $f12, 0x4D20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4D20);
    // 0x8009119C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800911A0: jal         0x800DC178
    // 0x800911A4: lwc1        $f14, 0x4D24($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D24);
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x800911A4: lwc1        $f14, 0x4D24($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X4D24);
    after_3:
    // 0x800911A8: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800911AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800911B0: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x800911B4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800911B8: lbu         $t0, 0xC($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XC);
    // 0x800911BC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800911C0: jal         0x80090E48
    // 0x800911C4: sb          $t1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r9;
    func_80090E48(rdram, ctx);
        goto after_4;
    // 0x800911C4: sb          $t1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r9;
    after_4:
    // 0x800911C8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800911CC: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
L_800911D0:
    // 0x800911D0: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800911D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800911D8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800911DC: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800911E0: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800911E4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800911E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800911EC: nop

    // 0x800911F0: bc1tl       L_80091280
    if (c1cs) {
        // 0x800911F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80091280;
    }
    goto skip_4;
    // 0x800911F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800911F8: lbu         $t2, 0xE($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XE);
    // 0x800911FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80091200: bne         $t2, $at, L_80091218
    if (ctx->r10 != ctx->r1) {
        // 0x80091204: nop
    
            goto L_80091218;
    }
    // 0x80091204: nop

    // 0x80091208: jal         0x80091030
    // 0x8009120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80091030(rdram, ctx);
        goto after_5;
    // 0x8009120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80091210: b           L_80091224
    // 0x80091214: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_80091224;
    // 0x80091214: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80091218:
    // 0x80091218: jal         0x80090F38
    // 0x8009121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090F38(rdram, ctx);
        goto after_6;
    // 0x8009121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80091220: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80091224:
    // 0x80091224: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091228: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8009122C: lbu         $t3, 0xE($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XE);
    // 0x80091230: bne         $t3, $at, L_80091240
    if (ctx->r11 != ctx->r1) {
        // 0x80091234: nop
    
            goto L_80091240;
    }
    // 0x80091234: nop

    // 0x80091238: b           L_8009127C
    // 0x8009123C: sb          $t4, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r12;
        goto L_8009127C;
    // 0x8009123C: sb          $t4, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r12;
L_80091240:
    // 0x80091240: jal         0x800DC0C0
    // 0x80091244: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x80091244: nop

    after_7:
    // 0x80091248: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009124C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80091250: nop

    // 0x80091254: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80091258: nop

    // 0x8009125C: bc1fl       L_80091274
    if (!c1cs) {
        // 0x80091260: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_80091274;
    }
    goto skip_5;
    // 0x80091260: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_5:
    // 0x80091264: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x80091268: b           L_8009127C
    // 0x8009126C: sb          $zero, 0xD($t5)
    MEM_B(0XD, ctx->r13) = 0;
        goto L_8009127C;
    // 0x8009126C: sb          $zero, 0xD($t5)
    MEM_B(0XD, ctx->r13) = 0;
    // 0x80091270: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_80091274:
    // 0x80091274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80091278: sb          $t6, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r14;
L_8009127C:
    // 0x8009127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80091280:
    // 0x80091280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80091284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091288: jr          $ra
    // 0x8009128C: nop

    return;
    // 0x8009128C: nop

;}
RECOMP_FUNC void func_80090434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009043C: jal         0x800F54E4
    // 0x80090440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090448: jal         0x800F796C
    // 0x8009044C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F796C(rdram, ctx);
        goto after_1;
    // 0x8009044C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090458: jr          $ra
    // 0x8009045C: nop

    return;
    // 0x8009045C: nop

;}
RECOMP_FUNC void glreflight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80800004: lw          $v0, -0x24AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X24AC);
    // 0x80800008: lui         $at, 0xACC9
    ctx->r1 = S32(0XACC9 << 16);
    // 0x8080000C: ori         $at, $at, 0x3EE
    ctx->r1 = ctx->r1 | 0X3EE;
    // 0x80800010: xor         $t6, $v0, $at
    ctx->r14 = ctx->r2 ^ ctx->r1;
    // 0x80800014: jr          $ra
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800018: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void chfiregen_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X1644) << 16);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $v0, $v0, 0x1644
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1644));
    return;
    // 0x808000C4: addiu       $v0, $v0, 0x1644
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X1644));
;}
RECOMP_FUNC void func_800E7A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7A90: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E7A94: addiu       $t1, $t1, -0x2A30
    ctx->r9 = ADD32(ctx->r9, -0X2A30);
    // 0x800E7A98: lh          $t6, 0x8($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X8);
    // 0x800E7A9C: bnel        $a1, $t6, L_800E7AD0
    if (ctx->r5 != ctx->r14) {
        // 0x800E7AA0: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800E7AD0;
    }
    goto skip_0;
    // 0x800E7AA0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_0:
    // 0x800E7AA4: lh          $t7, 0xA($t1)
    ctx->r15 = MEM_H(ctx->r9, 0XA);
    // 0x800E7AA8: bnel        $a2, $t7, L_800E7AD0
    if (ctx->r6 != ctx->r15) {
        // 0x800E7AAC: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800E7AD0;
    }
    goto skip_1;
    // 0x800E7AAC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_1:
    // 0x800E7AB0: lh          $t8, 0xC($t1)
    ctx->r24 = MEM_H(ctx->r9, 0XC);
    // 0x800E7AB4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800E7AB8: bnel        $a3, $t8, L_800E7AD0
    if (ctx->r7 != ctx->r24) {
        // 0x800E7ABC: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800E7AD0;
    }
    goto skip_2;
    // 0x800E7ABC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_2:
    // 0x800E7AC0: lh          $t9, 0xE($t1)
    ctx->r25 = MEM_H(ctx->r9, 0XE);
    // 0x800E7AC4: beq         $v0, $t9, L_800E7B80
    if (ctx->r2 == ctx->r25) {
        // 0x800E7AC8: nop
    
            goto L_800E7B80;
    }
    // 0x800E7AC8: nop

    // 0x800E7ACC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_800E7AD0:
    // 0x800E7AD0: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800E7AD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800E7AD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E7ADC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E7AE0: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800E7AE4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800E7AE8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800E7AEC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E7AF0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E7AF4: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800E7AF8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800E7AFC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800E7B00: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E7B04: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800E7B08: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800E7B0C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800E7B10: andi        $t5, $t4, 0xFFF
    ctx->r13 = ctx->r12 & 0XFFF;
    // 0x800E7B14: sll         $t6, $t5, 12
    ctx->r14 = S32(ctx->r13 << 12);
    // 0x800E7B18: addu        $t4, $a1, $a3
    ctx->r12 = ADD32(ctx->r5, ctx->r7);
    // 0x800E7B1C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800E7B20: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800E7B24: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x800E7B28: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x800E7B2C: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x800E7B30: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E7B34: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800E7B38: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800E7B3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E7B40: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800E7B44: nop

    // 0x800E7B48: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E7B4C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800E7B50: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E7B54: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800E7B58: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800E7B5C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800E7B60: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x800E7B64: andi        $t4, $t3, 0xFFF
    ctx->r12 = ctx->r11 & 0XFFF;
    // 0x800E7B68: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800E7B6C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800E7B70: sh          $a1, 0x8($t1)
    MEM_H(0X8, ctx->r9) = ctx->r5;
    // 0x800E7B74: sh          $a2, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r6;
    // 0x800E7B78: sh          $a3, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r7;
    // 0x800E7B7C: sh          $v0, 0xE($t1)
    MEM_H(0XE, ctx->r9) = ctx->r2;
L_800E7B80:
    // 0x800E7B80: jr          $ra
    // 0x800E7B84: nop

    return;
    // 0x800E7B84: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801318: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x8080131C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801320: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x80801324: ori         $t8, $t7, 0x6
    ctx->r24 = ctx->r15 | 0X6;
    // 0x80801328: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080132C: jal         0x8080134C
    // 0x80801330: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    sumumbofx_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80801330: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    after_0:
    // 0x80801334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080133C: jr          $ra
    // 0x80801340: nop

    return;
    // 0x80801340: nop

;}
RECOMP_FUNC void func_80107320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107324: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80107328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010732C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80107330: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80107334: addiu       $a0, $a0, 0x6F00
    ctx->r4 = ADD32(ctx->r4, 0X6F00);
    // 0x80107338: jal         0x800B3044
    // 0x8010733C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x8010733C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80107340: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80107344: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80107348: jal         0x8002D6E0
    // 0x8010734C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _bzero(rdram, ctx);
        goto after_1;
    // 0x8010734C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_1:
    // 0x80107350: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80107354: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80107358: lhu         $t0, 0x94($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X94);
    // 0x8010735C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80107360: andi        $t9, $t8, 0x3FF0
    ctx->r25 = ctx->r24 & 0X3FF0;
    // 0x80107364: andi        $t1, $t0, 0xC00F
    ctx->r9 = ctx->r8 & 0XC00F;
    // 0x80107368: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8010736C: jal         0x80107200
    // 0x80107370: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    func_80107200(rdram, ctx);
        goto after_2;
    // 0x80107370: sh          $t2, 0x94($a0)
    MEM_H(0X94, ctx->r4) = ctx->r10;
    after_2:
    // 0x80107374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107378: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8010737C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107380: jr          $ra
    // 0x80107384: nop

    return;
    // 0x80107384: nop

;}
RECOMP_FUNC void func_80803528_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080352C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803530: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803538: jal         0x80100094
    // 0x8080353C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080353C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803540: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x80803544: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80803548: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080354C: bnel        $t6, $zero, L_808035C4
    if (ctx->r14 != 0) {
        // 0x80803550: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808035C4;
    }
    goto skip_0;
    // 0x80803550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80803554: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80803558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080355C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80803560: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80803564: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80803568: nop

    // 0x8080356C: bc1fl       L_808035C4
    if (!c1cs) {
        // 0x80803570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808035C4;
    }
    goto skip_1;
    // 0x80803570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80803574: jal         0x800EFC7C
    // 0x80803578: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x80803578: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080357C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4558) << 16);
    // 0x80803580: lwc1        $f8, 0x4558($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4558));
    // 0x80803584: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803588: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080358C: nop

    // 0x80803590: bc1fl       L_808035C4
    if (!c1cs) {
        // 0x80803594: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808035C4;
    }
    goto skip_2;
    // 0x80803594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80803598: lh          $a0, 0x78($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X78);
    // 0x8080359C: jal         0x80803B48
    // 0x808035A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80803B48_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x808035A0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x808035A4: beq         $v0, $zero, L_808035C0
    if (ctx->r2 == 0) {
        // 0x808035A8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808035C0;
    }
    // 0x808035A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808035AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808035B0: sb          $t7, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r15;
    // 0x808035B4: lh          $a0, 0x78($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X78);
    // 0x808035B8: jal         0x800F82D4
    // 0x808035BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_3;
    // 0x808035BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
L_808035C0:
    // 0x808035C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808035C4:
    // 0x808035C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808035C8: jr          $ra
    // 0x808035CC: nop

    return;
    // 0x808035CC: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C20: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C20);
    return;
    // 0x80089C24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F9A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F9A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F9A74: jal         0x800878A8
    // 0x800F9A78: nop

    _plsu_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800F9A78: nop

    after_0:
    // 0x800F9A7C: beq         $v0, $zero, L_800F9A94
    if (ctx->r2 == 0) {
        // 0x800F9A80: nop
    
            goto L_800F9A94;
    }
    // 0x800F9A80: nop

    // 0x800F9A84: jal         0x800F9488
    // 0x800F9A88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800F9488(rdram, ctx);
        goto after_1;
    // 0x800F9A88: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x800F9A8C: b           L_800F9AA0
    // 0x800F9A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F9AA0;
    // 0x800F9A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9A94:
    // 0x800F9A94: jal         0x800F9488
    // 0x800F9A98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800F9488(rdram, ctx);
        goto after_2;
    // 0x800F9A98: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x800F9A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F9AA0:
    // 0x800F9AA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F9AA4: jr          $ra
    // 0x800F9AA8: nop

    return;
    // 0x800F9AA8: nop

;}
RECOMP_FUNC void func_808001B8_chlavaarchgrill3switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C0: addiu       $t6, $zero, 0x5E
    ctx->r14 = ADD32(0, 0X5E);
    // 0x808001C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001C8: jal         0x80800020
    // 0x808001CC: addiu       $a3, $zero, 0x5D
    ctx->r7 = ADD32(0, 0X5D);
    func_80800020_chlavaarchgrill3switches(rdram, ctx);
        goto after_0;
    // 0x808001CC: addiu       $a3, $zero, 0x5D
    ctx->r7 = ADD32(0, 0X5D);
    after_0:
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_800260EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800260EC: jr          $ra
    // 0x800260F0: nop

    return;
    // 0x800260F0: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088630: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088630);
    return;
    // 0x80088634: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void baflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001CC: jal         0x80800088
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800088_baflamethrower(rdram, ctx);
        goto after_0;
    // 0x808001D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001DC: jr          $ra
    // 0x808001E0: nop

    return;
    // 0x808001E0: nop

;}
RECOMP_FUNC void func_80800704_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800708: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080070C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800714: beq         $a2, $at, L_8080073C
    if (ctx->r6 == ctx->r1) {
        // 0x80800718: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080073C;
    }
    // 0x80800718: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080071C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800720: beq         $a2, $at, L_80800758
    if (ctx->r6 == ctx->r1) {
        // 0x80800724: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800758;
    }
    // 0x80800724: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800728: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080072C: beq         $a2, $at, L_80800770
    if (ctx->r6 == ctx->r1) {
        // 0x80800730: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800770;
    }
    // 0x80800730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800734: b           L_80800784
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800784;
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080073C:
    // 0x8080073C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800740: jal         0x80108B04
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80800744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800748: jal         0x800DA544
    // 0x8080074C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x8080074C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x80800750: b           L_80800784
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800784;
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800758:
    // 0x80800758: jal         0x80108B04
    // 0x8080075C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x8080075C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800760: jal         0x800DA544
    // 0x80800764: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800764: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800768: b           L_80800784
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800784;
    // 0x8080076C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800770:
    // 0x80800770: jal         0x800DA544
    // 0x80800774: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800774: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800778: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080077C: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x80800780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800784:
    // 0x80800784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800788: jr          $ra
    // 0x8080078C: nop

    return;
    // 0x8080078C: nop

;}
RECOMP_FUNC void func_80800DAC_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800DB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800DB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DBC: jal         0x8008CABC
    // 0x80800DC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800DC0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800DC4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DCC: jal         0x80091A30
    // 0x80800DD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x80800DD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800DD4: beq         $v0, $zero, L_80800E04
    if (ctx->r2 == 0) {
        // 0x80800DD8: nop
    
            goto L_80800E04;
    }
    // 0x80800DD8: nop

    // 0x80800DDC: jal         0x8009BB50
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x80800DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800DE8: nop

    // 0x80800DEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800DF0: nop

    // 0x80800DF4: bc1f        L_80800E04
    if (!c1cs) {
        // 0x80800DF8: nop
    
            goto L_80800E04;
    }
    // 0x80800DF8: nop

    // 0x80800DFC: jal         0x8009BC6C
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800E04:
    // 0x80800E04: jal         0x808001D4
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_4;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E0C: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800E10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E18: beq         $v0, $at, L_80800E48
    if (ctx->r2 == ctx->r1) {
        // 0x80800E1C: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_80800E48;
    }
    // 0x80800E1C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800E20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E24: beq         $v0, $at, L_80800ED0
    if (ctx->r2 == ctx->r1) {
        // 0x80800E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED0;
    }
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E30: beq         $v0, $at, L_80800F10
    if (ctx->r2 == ctx->r1) {
        // 0x80800E34: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800F10;
    }
    // 0x80800E34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E38: beq         $v0, $at, L_80800F58
    if (ctx->r2 == ctx->r1) {
        // 0x80800E3C: nop
    
            goto L_80800F58;
    }
    // 0x80800E3C: nop

    // 0x80800E40: b           L_80800FD4
    // 0x80800E44: nop

        goto L_80800FD4;
    // 0x80800E44: nop

L_80800E48:
    // 0x80800E48: jal         0x8008CB10
    // 0x80800E4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800E4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_5:
    // 0x80800E50: beq         $v0, $zero, L_80800E6C
    if (ctx->r2 == 0) {
        // 0x80800E54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E6C;
    }
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E58: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80800E5C: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x80800E60: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800E64: jal         0x8009D7A4
    // 0x80800E68: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_8009D7A4(rdram, ctx);
        goto after_6;
    // 0x80800E68: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_6:
L_80800E6C:
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E70: jal         0x8008DF8C
    // 0x80800E74: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_7;
    // 0x80800E74: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_7:
    // 0x80800E78: bnel        $v0, $zero, L_80800E90
    if (ctx->r2 != 0) {
        // 0x80800E7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E90;
    }
    goto skip_0;
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800E80: jal         0x80800AA4
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA4_bsbansack(rdram, ctx);
        goto after_8;
    // 0x80800E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800E88: beq         $v0, $zero, L_80800EA0
    if (ctx->r2 == 0) {
        // 0x80800E8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EA0;
    }
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E90:
    // 0x80800E90: jal         0x80800AF4
    // 0x80800E94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_9;
    // 0x80800E94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800E98: b           L_80800EBC
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800EBC;
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EA0:
    // 0x80800EA0: jal         0x8008B324
    // 0x80800EA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_10;
    // 0x80800EA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80800EA8: beq         $v0, $zero, L_80800EB8
    if (ctx->r2 == 0) {
        // 0x80800EAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EB8;
    }
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB0: jal         0x80800AF4
    // 0x80800EB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_11;
    // 0x80800EB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
L_80800EB8:
    // 0x80800EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EBC:
    // 0x80800EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EC0: jal         0x80800000
    // 0x80800EC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_bsbansack(rdram, ctx);
        goto after_12;
    // 0x80800EC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80800EC8: b           L_80800FD4
    // 0x80800ECC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800FD4;
    // 0x80800ECC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800ED0:
    // 0x80800ED0: jal         0x8008DF8C
    // 0x80800ED4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_13;
    // 0x80800ED4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_13:
    // 0x80800ED8: bnel        $v0, $zero, L_80800EF0
    if (ctx->r2 != 0) {
        // 0x80800EDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF0;
    }
    goto skip_1;
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800EE0: jal         0x80800AA4
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA4_bsbansack(rdram, ctx);
        goto after_14;
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800EE8: beq         $v0, $zero, L_80800EF8
    if (ctx->r2 == 0) {
        // 0x80800EEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF8;
    }
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EF0:
    // 0x80800EF0: jal         0x80800AF4
    // 0x80800EF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_15;
    // 0x80800EF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
L_80800EF8:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F00: jal         0x80800000
    // 0x80800F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_bsbansack(rdram, ctx);
        goto after_16;
    // 0x80800F04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80800F08: b           L_80800FD4
    // 0x80800F0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800FD4;
    // 0x80800F0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800F10:
    // 0x80800F10: jal         0x80800368
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800368_bsbansack(rdram, ctx);
        goto after_17;
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800F18: jal         0x8008E078
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_18;
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800F20: bnel        $v0, $zero, L_80800F38
    if (ctx->r2 != 0) {
        // 0x80800F24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F38;
    }
    goto skip_2;
    // 0x80800F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800F28: jal         0x8008E35C
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_19;
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800F30: beq         $v0, $zero, L_80800F40
    if (ctx->r2 == 0) {
        // 0x80800F34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F40;
    }
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F38:
    // 0x80800F38: jal         0x80800AF4
    // 0x80800F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800AF4_bsbansack(rdram, ctx);
        goto after_20;
    // 0x80800F3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
L_80800F40:
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F48: jal         0x80800000
    // 0x80800F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_bsbansack(rdram, ctx);
        goto after_21;
    // 0x80800F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80800F50: b           L_80800FD4
    // 0x80800F54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_80800FD4;
    // 0x80800F54: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800F58:
    // 0x80800F58: jal         0x80800368
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800368_bsbansack(rdram, ctx);
        goto after_22;
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800F60: jal         0x8008B324
    // 0x80800F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_23;
    // 0x80800F64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x80800F68: beq         $v0, $zero, L_80800FBC
    if (ctx->r2 == 0) {
        // 0x80800F6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F70: jal         0x8009BB00
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_24;
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800F78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800F7C: addiu       $t6, $zero, 0x166
    ctx->r14 = ADD32(0, 0X166);
    // 0x80800F80: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800F84: nop

    // 0x80800F88: bc1f        L_80800F98
    if (!c1cs) {
        // 0x80800F8C: nop
    
            goto L_80800F98;
    }
    // 0x80800F8C: nop

    // 0x80800F90: b           L_80800FC4
    // 0x80800F94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
        goto L_80800FC4;
    // 0x80800F94: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800F98:
    // 0x80800F98: jal         0x8008E35C
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800FA0: beq         $v0, $zero, L_80800FB4
    if (ctx->r2 == 0) {
        // 0x80800FA4: addiu       $t8, $zero, 0x165
        ctx->r24 = ADD32(0, 0X165);
            goto L_80800FB4;
    }
    // 0x80800FA4: addiu       $t8, $zero, 0x165
    ctx->r24 = ADD32(0, 0X165);
    // 0x80800FA8: addiu       $t7, $zero, 0x167
    ctx->r15 = ADD32(0, 0X167);
    // 0x80800FAC: b           L_80800FC4
    // 0x80800FB0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80800FC4;
    // 0x80800FB0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800FB4:
    // 0x80800FB4: b           L_80800FC4
    // 0x80800FB8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_80800FC4;
    // 0x80800FB8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800FBC:
    // 0x80800FBC: jal         0x8009B9B0
    // 0x80800FC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_26;
    // 0x80800FC0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_26:
L_80800FC4:
    // 0x80800FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC8: jal         0x80800084
    // 0x80800FCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800084_bsbansack(rdram, ctx);
        goto after_27;
    // 0x80800FCC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_27:
    // 0x80800FD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800FD4:
    // 0x80800FD4: jal         0x8008E260
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_28;
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800FDC: beq         $v0, $zero, L_80800FEC
    if (ctx->r2 == 0) {
        // 0x80800FE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FEC;
    }
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: addiu       $t9, $zero, 0x3D
    ctx->r25 = ADD32(0, 0X3D);
    // 0x80800FE8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800FEC:
    // 0x80800FEC: jal         0x8009E5C8
    // 0x80800FF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x80800FF0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_29:
    // 0x80800FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801000: jr          $ra
    // 0x80801004: nop

    return;
    // 0x80801004: nop

;}
RECOMP_FUNC void func_80800548_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800548: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080054C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800550: jal         0x800F6BE4
    // 0x80800554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F6BE4(rdram, ctx);
        goto after_0;
    // 0x80800554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800558: beq         $v0, $zero, L_80800590
    if (ctx->r2 == 0) {
        // 0x8080055C: lui         $at, 0x433E
        ctx->r1 = S32(0X433E << 16);
            goto L_80800590;
    }
    // 0x8080055C: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80800560: jal         0x800F693C
    // 0x80800564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F693C(rdram, ctx);
        goto after_1;
    // 0x80800564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800568: beq         $v0, $zero, L_80800580
    if (ctx->r2 == 0) {
        // 0x8080056C: lui         $at, 0x433E
        ctx->r1 = S32(0X433E << 16);
            goto L_80800580;
    }
    // 0x8080056C: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x80800570: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800574: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800578: b           L_80800598
    // 0x8080057C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80800598;
    // 0x8080057C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800580:
    // 0x80800580: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800584: nop

    // 0x80800588: b           L_80800598
    // 0x8080058C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80800598;
    // 0x8080058C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800590:
    // 0x80800590: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800594: nop

L_80800598:
    // 0x80800598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080059C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005A0: jr          $ra
    // 0x808005A4: nop

    return;
    // 0x808005A4: nop

;}
RECOMP_FUNC void boot___osGetCause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void ncbadolly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x2C
    ctx->r2 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800184_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800190: jal         0x8009E6EC
    // 0x80800194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800198: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x8080019C: bne         $v0, $at, L_808001CC
    if (ctx->r2 != ctx->r1) {
        // 0x808001A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001CC;
    }
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A4: jal         0x800995B8
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800995B8(rdram, ctx);
        goto after_1;
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8009E5C8
    // 0x808001B4: addiu       $a1, $zero, 0x15B
    ctx->r5 = ADD32(0, 0X15B);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808001B4: addiu       $a1, $zero, 0x15B
    ctx->r5 = ADD32(0, 0X15B);
    after_2:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x8009E830
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x808001C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808001C4: b           L_808001D8
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001D8;
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001CC:
    // 0x808001CC: jal         0x80099B94
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_4;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D8:
    // 0x808001D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E0: jr          $ra
    // 0x808001E4: nop

    return;
    // 0x808001E4: nop

;}
RECOMP_FUNC void func_800908F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800908F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800908F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800908F8: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x800908FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80090900: bne         $a1, $at, L_8009091C
    if (ctx->r5 != ctx->r1) {
        // 0x80090904: sb          $a1, 0x9($t6)
        MEM_B(0X9, ctx->r14) = ctx->r5;
            goto L_8009091C;
    }
    // 0x80090904: sb          $a1, 0x9($t6)
    MEM_B(0X9, ctx->r14) = ctx->r5;
    // 0x80090908: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8009090C: jal         0x8009ADF0
    // 0x80090910: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80090910: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80090914: b           L_8009092C
    // 0x80090918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009092C;
    // 0x80090918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009091C:
    // 0x8009091C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80090920: jal         0x8009ADF0
    // 0x80090924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x80090924: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80090928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009092C:
    // 0x8009092C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090930: jr          $ra
    // 0x80090934: nop

    return;
    // 0x80090934: nop

;}
RECOMP_FUNC void ncbafly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800B90_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B98: jal         0x8010A624
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A624(rdram, ctx);
        goto after_0;
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BA0: jal         0x8010A590
    // 0x80800BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800BA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BAC: addiu       $a1, $zero, 0x610
    ctx->r5 = ADD32(0, 0X610);
    // 0x80800BB0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800BB4: jal         0x80103140
    // 0x80800BB8: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x80800BB8: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_2:
    // 0x80800BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BC4: jr          $ra
    // 0x80800BC8: nop

    return;
    // 0x80800BC8: nop

;}
