.text
.global gcm128_encrypt_opt_save_ghash
gcm128_encrypt_opt_save_ghash:
  push %r15
  push %r14
  push %r13
  push %r12
  push %rsi
  push %rdi
  push %rbp
  push %rbx
  mov 144(%rsp), %rbp
  mov %rcx, %r13
  lea 32(%r9), %r9
  mov 72(%rsp), %rbx
  mov %rdx, %rcx
  imul $16, %rcx
  mov $579005069656919567, %r10
  pinsrq $0, %r10, %xmm9
  mov $283686952306183, %r10
  pinsrq $1, %r10, %xmm9
  pxor %xmm8, %xmm8
  mov %rdi, %r11
  jmp L55
.balign 16
L54:
  add $80, %r11
  movdqu -32(%r9), %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  movdqu %xmm1, %xmm4
  movdqu -16(%r9), %xmm1
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 16(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 64(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 80(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  vpxor %xmm1, %xmm4, %xmm4
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  pxor %xmm3, %xmm3
  mov $3254779904, %r10
  pinsrd $3, %r10d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  add $96, %r11
  sub $6, %rdx
.balign 16
L55:
  cmp $6, %rdx
  jae L54
  cmp $0, %rdx
  jbe L56
  mov %rdx, %r10
  sub $1, %r10
  imul $16, %r10
  add %r10, %r11
  movdqu -32(%r9), %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  cmp $1, %rdx
  jne L58
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu %xmm1, %xmm4
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  jmp L59
L58:
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  movdqu %xmm1, %xmm4
  movdqu -16(%r9), %xmm1
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  movdqu %xmm1, %xmm5
  cmp $2, %rdx
  je L60
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 16(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  cmp $3, %rdx
  je L62
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  cmp $4, %rdx
  je L64
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 64(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  jmp L65
L64:
L65:
  jmp L63
L62:
L63:
  jmp L61
L60:
L61:
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  vpxor %xmm1, %xmm4, %xmm4
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
L59:
  pxor %xmm3, %xmm3
  mov $3254779904, %r10
  pinsrd $3, %r10d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  jmp L57
L56:
L57:
  mov %rsi, %r15
  cmp %rcx, %rsi
  jbe L66
  movdqu 0(%rbx), %xmm0
  mov %rsi, %r10
  and $15, %r10
  cmp $8, %r10
  jae L68
  mov $0, %rcx
  pinsrq $1, %rcx, %xmm0
  mov %r10, %rcx
  shl $3, %rcx
  mov $1, %r11
  shl %cl, %r11
  sub $1, %r11
  pextrq $0, %xmm0, %rcx
  and %r11, %rcx
  pinsrq $0, %rcx, %xmm0
  jmp L69
L68:
  mov %r10, %rcx
  sub $8, %rcx
  shl $3, %rcx
  mov $1, %r11
  shl %cl, %r11
  sub $1, %r11
  pextrq $1, %xmm0, %rcx
  and %r11, %rcx
  pinsrq $1, %rcx, %xmm0
L69:
  pshufb %xmm9, %xmm0
  movdqu -32(%r9), %xmm5
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu %xmm1, %xmm4
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  pxor %xmm3, %xmm3
  mov $3254779904, %r11
  pinsrd $3, %r11d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  jmp L67
L66:
L67:
  mov 80(%rsp), %rdi
  mov 88(%rsp), %rsi
  mov 96(%rsp), %rdx
  mov %r13, %rcx
  movdqu %xmm9, %xmm0
  movdqu 0(%r8), %xmm1
  movdqu %xmm1, 0(%rbp)
  pxor %xmm10, %xmm10
  mov $1, %r11
  pinsrq $0, %r11, %xmm10
  vpaddd %xmm10, %xmm1, %xmm1
  cmp $0, %rdx
  jne L70
  vpshufb %xmm0, %xmm1, %xmm1
  movdqu %xmm1, 32(%rbp)
  jmp L71
L70:
  movdqu %xmm8, 32(%rbp)
  add $128, %rcx
  pextrq $0, %xmm1, %rbx
  and $255, %rbx
  vpshufb %xmm0, %xmm1, %xmm1
  lea 96(%rsi), %r14
  movdqu -128(%rcx), %xmm4
  pxor %xmm2, %xmm2
  mov $72057594037927936, %r11
  pinsrq $1, %r11, %xmm2
  movdqu -112(%rcx), %xmm15
  mov %rcx, %r12
  sub $96, %r12
  vpxor %xmm4, %xmm1, %xmm9
  add $6, %rbx
  cmp $256, %rbx
  jae L72
  vpaddd %xmm2, %xmm1, %xmm10
  vpaddd %xmm2, %xmm10, %xmm11
  vpxor %xmm4, %xmm10, %xmm10
  vpaddd %xmm2, %xmm11, %xmm12
  vpxor %xmm4, %xmm11, %xmm11
  vpaddd %xmm2, %xmm12, %xmm13
  vpxor %xmm4, %xmm12, %xmm12
  vpaddd %xmm2, %xmm13, %xmm14
  vpxor %xmm4, %xmm13, %xmm13
  vpaddd %xmm2, %xmm14, %xmm1
  vpxor %xmm4, %xmm14, %xmm14
  jmp L73
L72:
  sub $256, %rbx
  vpshufb %xmm0, %xmm1, %xmm6
  pxor %xmm5, %xmm5
  mov $1, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm10
  pxor %xmm5, %xmm5
  mov $2, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm11
  vpaddd %xmm5, %xmm10, %xmm12
  vpshufb %xmm0, %xmm10, %xmm10
  vpaddd %xmm5, %xmm11, %xmm13
  vpshufb %xmm0, %xmm11, %xmm11
  vpxor %xmm4, %xmm10, %xmm10
  vpaddd %xmm5, %xmm12, %xmm14
  vpshufb %xmm0, %xmm12, %xmm12
  vpxor %xmm4, %xmm11, %xmm11
  vpaddd %xmm5, %xmm13, %xmm1
  vpshufb %xmm0, %xmm13, %xmm13
  vpxor %xmm4, %xmm12, %xmm12
  vpshufb %xmm0, %xmm14, %xmm14
  vpxor %xmm4, %xmm13, %xmm13
  vpshufb %xmm0, %xmm1, %xmm1
  vpxor %xmm4, %xmm14, %xmm14
L73:
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -96(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -80(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -64(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -48(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -32(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -16(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu 0(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu 16(%rcx), %xmm15
  movdqu 32(%rcx), %xmm3
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor 0(%rdi), %xmm3, %xmm4
  vaesenc %xmm15, %xmm10, %xmm10
  vpxor 16(%rdi), %xmm3, %xmm5
  vaesenc %xmm15, %xmm11, %xmm11
  vpxor 32(%rdi), %xmm3, %xmm6
  vaesenc %xmm15, %xmm12, %xmm12
  vpxor 48(%rdi), %xmm3, %xmm8
  vaesenc %xmm15, %xmm13, %xmm13
  vpxor 64(%rdi), %xmm3, %xmm2
  vaesenc %xmm15, %xmm14, %xmm14
  vpxor 80(%rdi), %xmm3, %xmm3
  lea 96(%rdi), %rdi
  vaesenclast %xmm4, %xmm9, %xmm9
  vaesenclast %xmm5, %xmm10, %xmm10
  vaesenclast %xmm6, %xmm11, %xmm11
  vaesenclast %xmm8, %xmm12, %xmm12
  vaesenclast %xmm2, %xmm13, %xmm13
  vaesenclast %xmm3, %xmm14, %xmm14
  movdqu %xmm9, 0(%rsi)
  movdqu %xmm10, 16(%rsi)
  movdqu %xmm11, 32(%rsi)
  movdqu %xmm12, 48(%rsi)
  movdqu %xmm13, 64(%rsi)
  movdqu %xmm14, 80(%rsi)
  lea 96(%rsi), %rsi
  vpshufb %xmm0, %xmm9, %xmm8
  vpshufb %xmm0, %xmm10, %xmm2
  movdqu %xmm8, 112(%rbp)
  vpshufb %xmm0, %xmm11, %xmm4
  movdqu %xmm2, 96(%rbp)
  vpshufb %xmm0, %xmm12, %xmm5
  movdqu %xmm4, 80(%rbp)
  vpshufb %xmm0, %xmm13, %xmm6
  movdqu %xmm5, 64(%rbp)
  vpshufb %xmm0, %xmm14, %xmm7
  movdqu %xmm6, 48(%rbp)
  movdqu -128(%rcx), %xmm4
  pxor %xmm2, %xmm2
  mov $72057594037927936, %r11
  pinsrq $1, %r11, %xmm2
  movdqu -112(%rcx), %xmm15
  mov %rcx, %r12
  sub $96, %r12
  vpxor %xmm4, %xmm1, %xmm9
  add $6, %rbx
  cmp $256, %rbx
  jae L74
  vpaddd %xmm2, %xmm1, %xmm10
  vpaddd %xmm2, %xmm10, %xmm11
  vpxor %xmm4, %xmm10, %xmm10
  vpaddd %xmm2, %xmm11, %xmm12
  vpxor %xmm4, %xmm11, %xmm11
  vpaddd %xmm2, %xmm12, %xmm13
  vpxor %xmm4, %xmm12, %xmm12
  vpaddd %xmm2, %xmm13, %xmm14
  vpxor %xmm4, %xmm13, %xmm13
  vpaddd %xmm2, %xmm14, %xmm1
  vpxor %xmm4, %xmm14, %xmm14
  jmp L75
L74:
  sub $256, %rbx
  vpshufb %xmm0, %xmm1, %xmm6
  pxor %xmm5, %xmm5
  mov $1, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm10
  pxor %xmm5, %xmm5
  mov $2, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm11
  vpaddd %xmm5, %xmm10, %xmm12
  vpshufb %xmm0, %xmm10, %xmm10
  vpaddd %xmm5, %xmm11, %xmm13
  vpshufb %xmm0, %xmm11, %xmm11
  vpxor %xmm4, %xmm10, %xmm10
  vpaddd %xmm5, %xmm12, %xmm14
  vpshufb %xmm0, %xmm12, %xmm12
  vpxor %xmm4, %xmm11, %xmm11
  vpaddd %xmm5, %xmm13, %xmm1
  vpshufb %xmm0, %xmm13, %xmm13
  vpxor %xmm4, %xmm12, %xmm12
  vpshufb %xmm0, %xmm14, %xmm14
  vpxor %xmm4, %xmm13, %xmm13
  vpshufb %xmm0, %xmm1, %xmm1
  vpxor %xmm4, %xmm14, %xmm14
L75:
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -96(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -80(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -64(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -48(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -32(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -16(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu 0(%rcx), %xmm15
  vaesenc %xmm15, %xmm9, %xmm9
  vaesenc %xmm15, %xmm10, %xmm10
  vaesenc %xmm15, %xmm11, %xmm11
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu 16(%rcx), %xmm15
  movdqu 32(%rcx), %xmm3
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor 0(%rdi), %xmm3, %xmm4
  vaesenc %xmm15, %xmm10, %xmm10
  vpxor 16(%rdi), %xmm3, %xmm5
  vaesenc %xmm15, %xmm11, %xmm11
  vpxor 32(%rdi), %xmm3, %xmm6
  vaesenc %xmm15, %xmm12, %xmm12
  vpxor 48(%rdi), %xmm3, %xmm8
  vaesenc %xmm15, %xmm13, %xmm13
  vpxor 64(%rdi), %xmm3, %xmm2
  vaesenc %xmm15, %xmm14, %xmm14
  vpxor 80(%rdi), %xmm3, %xmm3
  lea 96(%rdi), %rdi
  vaesenclast %xmm4, %xmm9, %xmm9
  vaesenclast %xmm5, %xmm10, %xmm10
  vaesenclast %xmm6, %xmm11, %xmm11
  vaesenclast %xmm8, %xmm12, %xmm12
  vaesenclast %xmm2, %xmm13, %xmm13
  vaesenclast %xmm3, %xmm14, %xmm14
  movdqu %xmm9, 0(%rsi)
  movdqu %xmm10, 16(%rsi)
  movdqu %xmm11, 32(%rsi)
  movdqu %xmm12, 48(%rsi)
  movdqu %xmm13, 64(%rsi)
  movdqu %xmm14, 80(%rsi)
  lea 96(%rsi), %rsi
  sub $12, %rdx
  movdqu 32(%rbp), %xmm8
  pxor %xmm2, %xmm2
  mov $72057594037927936, %r11
  pinsrq $1, %r11, %xmm2
  vpxor %xmm4, %xmm4, %xmm4
  movdqu -128(%rcx), %xmm15
  vpaddd %xmm2, %xmm1, %xmm10
  vpaddd %xmm2, %xmm10, %xmm11
  vpaddd %xmm2, %xmm11, %xmm12
  vpaddd %xmm2, %xmm12, %xmm13
  vpaddd %xmm2, %xmm13, %xmm14
  vpxor %xmm15, %xmm1, %xmm9
  movdqu %xmm4, 16(%rbp)
  jmp L77
.balign 16
L76:
  add $6, %rbx
  cmp $256, %rbx
  jb L78
  mov $579005069656919567, %r11
  pinsrq $0, %r11, %xmm0
  mov $283686952306183, %r11
  pinsrq $1, %r11, %xmm0
  vpshufb %xmm0, %xmm1, %xmm6
  pxor %xmm5, %xmm5
  mov $1, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm10
  pxor %xmm5, %xmm5
  mov $2, %r11
  pinsrq $0, %r11, %xmm5
  vpaddd %xmm5, %xmm6, %xmm11
  movdqu -32(%r9), %xmm3
  vpaddd %xmm5, %xmm10, %xmm12
  vpshufb %xmm0, %xmm10, %xmm10
  vpaddd %xmm5, %xmm11, %xmm13
  vpshufb %xmm0, %xmm11, %xmm11
  vpxor %xmm15, %xmm10, %xmm10
  vpaddd %xmm5, %xmm12, %xmm14
  vpshufb %xmm0, %xmm12, %xmm12
  vpxor %xmm15, %xmm11, %xmm11
  vpaddd %xmm5, %xmm13, %xmm1
  vpshufb %xmm0, %xmm13, %xmm13
  vpshufb %xmm0, %xmm14, %xmm14
  vpshufb %xmm0, %xmm1, %xmm1
  sub $256, %rbx
  jmp L79
L78:
  movdqu -32(%r9), %xmm3
  vpaddd %xmm14, %xmm2, %xmm1
  vpxor %xmm15, %xmm10, %xmm10
  vpxor %xmm15, %xmm11, %xmm11
L79:
  movdqu %xmm1, 128(%rbp)
  vpclmulqdq $16, %xmm3, %xmm7, %xmm5
  vpxor %xmm15, %xmm12, %xmm12
  movdqu -112(%rcx), %xmm2
  vpclmulqdq $1, %xmm3, %xmm7, %xmm6
  vaesenc %xmm2, %xmm9, %xmm9
  movdqu 48(%rbp), %xmm0
  vpxor %xmm15, %xmm13, %xmm13
  vpclmulqdq $0, %xmm3, %xmm7, %xmm1
  vaesenc %xmm2, %xmm10, %xmm10
  vpxor %xmm15, %xmm14, %xmm14
  vpclmulqdq $17, %xmm3, %xmm7, %xmm7
  vaesenc %xmm2, %xmm11, %xmm11
  movdqu -16(%r9), %xmm3
  vaesenc %xmm2, %xmm12, %xmm12
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $0, %xmm3, %xmm0, %xmm5
  vpxor %xmm4, %xmm8, %xmm8
  vaesenc %xmm2, %xmm13, %xmm13
  vpxor %xmm5, %xmm1, %xmm4
  vpclmulqdq $16, %xmm3, %xmm0, %xmm1
  vaesenc %xmm2, %xmm14, %xmm14
  movdqu -96(%rcx), %xmm15
  vpclmulqdq $1, %xmm3, %xmm0, %xmm2
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor 16(%rbp), %xmm8, %xmm8
  vpclmulqdq $17, %xmm3, %xmm0, %xmm3
  movdqu 64(%rbp), %xmm0
  vaesenc %xmm15, %xmm10, %xmm10
  movbeq 88(%r14), %r13
  vaesenc %xmm15, %xmm11, %xmm11
  movbeq 80(%r14), %r12
  vaesenc %xmm15, %xmm12, %xmm12
  movq %r13, 32(%rbp)
  vaesenc %xmm15, %xmm13, %xmm13
  movq %r12, 40(%rbp)
  movdqu 16(%r9), %xmm5
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -80(%rcx), %xmm15
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vaesenc %xmm15, %xmm10, %xmm10
  vpxor %xmm3, %xmm7, %xmm7
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vaesenc %xmm15, %xmm11, %xmm11
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 80(%rbp), %xmm0
  vaesenc %xmm15, %xmm12, %xmm12
  vaesenc %xmm15, %xmm13, %xmm13
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -64(%rcx), %xmm15
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $0, %xmm1, %xmm0, %xmm2
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $16, %xmm1, %xmm0, %xmm3
  vaesenc %xmm15, %xmm10, %xmm10
  movbeq 72(%r14), %r13
  vpxor %xmm5, %xmm7, %xmm7
  vpclmulqdq $1, %xmm1, %xmm0, %xmm5
  vaesenc %xmm15, %xmm11, %xmm11
  movbeq 64(%r14), %r12
  vpclmulqdq $17, %xmm1, %xmm0, %xmm1
  movdqu 96(%rbp), %xmm0
  vaesenc %xmm15, %xmm12, %xmm12
  movq %r13, 48(%rbp)
  vaesenc %xmm15, %xmm13, %xmm13
  movq %r12, 56(%rbp)
  vpxor %xmm2, %xmm4, %xmm4
  movdqu 64(%r9), %xmm2
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -48(%rcx), %xmm15
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $0, %xmm2, %xmm0, %xmm3
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm2, %xmm0, %xmm5
  vaesenc %xmm15, %xmm10, %xmm10
  movbeq 56(%r14), %r13
  vpxor %xmm1, %xmm7, %xmm7
  vpclmulqdq $1, %xmm2, %xmm0, %xmm1
  vpxor 112(%rbp), %xmm8, %xmm8
  vaesenc %xmm15, %xmm11, %xmm11
  movbeq 48(%r14), %r12
  vpclmulqdq $17, %xmm2, %xmm0, %xmm2
  vaesenc %xmm15, %xmm12, %xmm12
  movq %r13, 64(%rbp)
  vaesenc %xmm15, %xmm13, %xmm13
  movq %r12, 72(%rbp)
  vpxor %xmm3, %xmm4, %xmm4
  movdqu 80(%r9), %xmm3
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu -32(%rcx), %xmm15
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm3, %xmm8, %xmm5
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $1, %xmm3, %xmm8, %xmm1
  vaesenc %xmm15, %xmm10, %xmm10
  movbeq 40(%r14), %r13
  vpxor %xmm2, %xmm7, %xmm7
  vpclmulqdq $0, %xmm3, %xmm8, %xmm2
  vaesenc %xmm15, %xmm11, %xmm11
  movbeq 32(%r14), %r12
  vpclmulqdq $17, %xmm3, %xmm8, %xmm8
  vaesenc %xmm15, %xmm12, %xmm12
  movq %r13, 80(%rbp)
  vaesenc %xmm15, %xmm13, %xmm13
  movq %r12, 88(%rbp)
  vpxor %xmm5, %xmm6, %xmm6
  vaesenc %xmm15, %xmm14, %xmm14
  vpxor %xmm1, %xmm6, %xmm6
  movdqu -16(%rcx), %xmm15
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm2, %xmm4, %xmm4
  pxor %xmm3, %xmm3
  mov $13979173243358019584, %r11
  pinsrq $1, %r11, %xmm3
  vaesenc %xmm15, %xmm9, %xmm9
  vpxor %xmm8, %xmm7, %xmm7
  vaesenc %xmm15, %xmm10, %xmm10
  vpxor %xmm5, %xmm4, %xmm4
  movbeq 24(%r14), %r13
  vaesenc %xmm15, %xmm11, %xmm11
  movbeq 16(%r14), %r12
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  movq %r13, 96(%rbp)
  vaesenc %xmm15, %xmm12, %xmm12
  movq %r12, 104(%rbp)
  vaesenc %xmm15, %xmm13, %xmm13
  vaesenc %xmm15, %xmm14, %xmm14
  movdqu 0(%rcx), %xmm1
  vaesenc %xmm1, %xmm9, %xmm9
  movdqu 16(%rcx), %xmm15
  vaesenc %xmm1, %xmm10, %xmm10
  vpsrldq $8, %xmm6, %xmm6
  vaesenc %xmm1, %xmm11, %xmm11
  vpxor %xmm6, %xmm7, %xmm7
  vaesenc %xmm1, %xmm12, %xmm12
  vpxor %xmm0, %xmm4, %xmm4
  movbeq 8(%r14), %r13
  vaesenc %xmm1, %xmm13, %xmm13
  movbeq 0(%r14), %r12
  vaesenc %xmm1, %xmm14, %xmm14
  movdqu 32(%rcx), %xmm1
  vaesenc %xmm15, %xmm9, %xmm9
  movdqu %xmm7, 16(%rbp)
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vaesenc %xmm15, %xmm10, %xmm10
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor 0(%rdi), %xmm1, %xmm2
  vaesenc %xmm15, %xmm11, %xmm11
  vpxor 16(%rdi), %xmm1, %xmm0
  vaesenc %xmm15, %xmm12, %xmm12
  vpxor 32(%rdi), %xmm1, %xmm5
  vaesenc %xmm15, %xmm13, %xmm13
  vpxor 48(%rdi), %xmm1, %xmm6
  vaesenc %xmm15, %xmm14, %xmm14
  vpxor 64(%rdi), %xmm1, %xmm7
  vpxor 80(%rdi), %xmm1, %xmm3
  movdqu 128(%rbp), %xmm1
  vaesenclast %xmm2, %xmm9, %xmm9
  pxor %xmm2, %xmm2
  mov $72057594037927936, %r11
  pinsrq $1, %r11, %xmm2
  vaesenclast %xmm0, %xmm10, %xmm10
  vpaddd %xmm2, %xmm1, %xmm0
  movq %r13, 112(%rbp)
  lea 96(%rdi), %rdi
  vaesenclast %xmm5, %xmm11, %xmm11
  vpaddd %xmm2, %xmm0, %xmm5
  movq %r12, 120(%rbp)
  lea 96(%rsi), %rsi
  movdqu -128(%rcx), %xmm15
  vaesenclast %xmm6, %xmm12, %xmm12
  vpaddd %xmm2, %xmm5, %xmm6
  vaesenclast %xmm7, %xmm13, %xmm13
  vpaddd %xmm2, %xmm6, %xmm7
  vaesenclast %xmm3, %xmm14, %xmm14
  vpaddd %xmm2, %xmm7, %xmm3
  sub $6, %rdx
  add $96, %r14
  cmp $0, %rdx
  jbe L80
  movdqu %xmm9, -96(%rsi)
  vpxor %xmm15, %xmm1, %xmm9
  movdqu %xmm10, -80(%rsi)
  movdqu %xmm0, %xmm10
  movdqu %xmm11, -64(%rsi)
  movdqu %xmm5, %xmm11
  movdqu %xmm12, -48(%rsi)
  movdqu %xmm6, %xmm12
  movdqu %xmm13, -32(%rsi)
  movdqu %xmm7, %xmm13
  movdqu %xmm14, -16(%rsi)
  movdqu %xmm3, %xmm14
  movdqu 32(%rbp), %xmm7
  jmp L81
L80:
  vpxor 16(%rbp), %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
L81:
.balign 16
L77:
  cmp $0, %rdx
  ja L76
  movdqu 32(%rbp), %xmm7
  movdqu %xmm1, 32(%rbp)
  pxor %xmm4, %xmm4
  movdqu %xmm4, 16(%rbp)
  movdqu -32(%r9), %xmm3
  vpclmulqdq $0, %xmm3, %xmm7, %xmm1
  vpclmulqdq $16, %xmm3, %xmm7, %xmm5
  movdqu 48(%rbp), %xmm0
  vpclmulqdq $1, %xmm3, %xmm7, %xmm6
  vpclmulqdq $17, %xmm3, %xmm7, %xmm7
  movdqu -16(%r9), %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $0, %xmm3, %xmm0, %xmm5
  vpxor %xmm4, %xmm8, %xmm8
  vpxor %xmm5, %xmm1, %xmm4
  vpclmulqdq $16, %xmm3, %xmm0, %xmm1
  vpclmulqdq $1, %xmm3, %xmm0, %xmm2
  vpxor 16(%rbp), %xmm8, %xmm8
  vpclmulqdq $17, %xmm3, %xmm0, %xmm3
  movdqu 64(%rbp), %xmm0
  movdqu 16(%r9), %xmm5
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpxor %xmm3, %xmm7, %xmm7
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 80(%rbp), %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $0, %xmm1, %xmm0, %xmm2
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $16, %xmm1, %xmm0, %xmm3
  vpxor %xmm5, %xmm7, %xmm7
  vpclmulqdq $1, %xmm1, %xmm0, %xmm5
  vpclmulqdq $17, %xmm1, %xmm0, %xmm1
  movdqu 96(%rbp), %xmm0
  vpxor %xmm2, %xmm4, %xmm4
  movdqu 64(%r9), %xmm2
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $0, %xmm2, %xmm0, %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm2, %xmm0, %xmm5
  vpxor %xmm1, %xmm7, %xmm7
  vpclmulqdq $1, %xmm2, %xmm0, %xmm1
  vpxor 112(%rbp), %xmm8, %xmm8
  vpclmulqdq $17, %xmm2, %xmm0, %xmm2
  vpxor %xmm3, %xmm4, %xmm4
  movdqu 80(%r9), %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm3, %xmm8, %xmm5
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $1, %xmm3, %xmm8, %xmm1
  vpxor %xmm2, %xmm7, %xmm7
  vpclmulqdq $0, %xmm3, %xmm8, %xmm2
  vpclmulqdq $17, %xmm3, %xmm8, %xmm8
  vpxor %xmm5, %xmm6, %xmm6
  vpxor %xmm1, %xmm6, %xmm6
  vpxor %xmm2, %xmm4, %xmm4
  pxor %xmm3, %xmm3
  mov $3254779904, %rax
  pinsrd $3, %eax, %xmm3
  vpxor %xmm8, %xmm7, %xmm7
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  mov $579005069656919567, %r12
  pinsrq $0, %r12, %xmm0
  mov $283686952306183, %r12
  pinsrq $1, %r12, %xmm0
  movdqu %xmm9, -96(%rsi)
  vpshufb %xmm0, %xmm9, %xmm9
  vpxor %xmm7, %xmm1, %xmm1
  movdqu %xmm10, -80(%rsi)
  vpshufb %xmm0, %xmm10, %xmm10
  movdqu %xmm11, -64(%rsi)
  vpshufb %xmm0, %xmm11, %xmm11
  movdqu %xmm12, -48(%rsi)
  vpshufb %xmm0, %xmm12, %xmm12
  movdqu %xmm13, -32(%rsi)
  vpshufb %xmm0, %xmm13, %xmm13
  movdqu %xmm14, -16(%rsi)
  vpshufb %xmm0, %xmm14, %xmm14
  pxor %xmm4, %xmm4
  movdqu %xmm14, %xmm7
  movdqu %xmm4, 16(%rbp)
  movdqu %xmm13, 48(%rbp)
  movdqu %xmm12, 64(%rbp)
  movdqu %xmm11, 80(%rbp)
  movdqu %xmm10, 96(%rbp)
  movdqu %xmm9, 112(%rbp)
  movdqu -32(%r9), %xmm3
  vpclmulqdq $0, %xmm3, %xmm7, %xmm1
  vpclmulqdq $16, %xmm3, %xmm7, %xmm5
  movdqu 48(%rbp), %xmm0
  vpclmulqdq $1, %xmm3, %xmm7, %xmm6
  vpclmulqdq $17, %xmm3, %xmm7, %xmm7
  movdqu -16(%r9), %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $0, %xmm3, %xmm0, %xmm5
  vpxor %xmm4, %xmm8, %xmm8
  vpxor %xmm5, %xmm1, %xmm4
  vpclmulqdq $16, %xmm3, %xmm0, %xmm1
  vpclmulqdq $1, %xmm3, %xmm0, %xmm2
  vpxor 16(%rbp), %xmm8, %xmm8
  vpclmulqdq $17, %xmm3, %xmm0, %xmm3
  movdqu 64(%rbp), %xmm0
  movdqu 16(%r9), %xmm5
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpxor %xmm3, %xmm7, %xmm7
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 80(%rbp), %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpclmulqdq $0, %xmm1, %xmm0, %xmm2
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $16, %xmm1, %xmm0, %xmm3
  vpxor %xmm5, %xmm7, %xmm7
  vpclmulqdq $1, %xmm1, %xmm0, %xmm5
  vpclmulqdq $17, %xmm1, %xmm0, %xmm1
  movdqu 96(%rbp), %xmm0
  vpxor %xmm2, %xmm4, %xmm4
  movdqu 64(%r9), %xmm2
  vpxor %xmm3, %xmm6, %xmm6
  vpclmulqdq $0, %xmm2, %xmm0, %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm2, %xmm0, %xmm5
  vpxor %xmm1, %xmm7, %xmm7
  vpclmulqdq $1, %xmm2, %xmm0, %xmm1
  vpxor 112(%rbp), %xmm8, %xmm8
  vpclmulqdq $17, %xmm2, %xmm0, %xmm2
  vpxor %xmm3, %xmm4, %xmm4
  movdqu 80(%r9), %xmm3
  vpxor %xmm5, %xmm6, %xmm6
  vpclmulqdq $16, %xmm3, %xmm8, %xmm5
  vpxor %xmm1, %xmm6, %xmm6
  vpclmulqdq $1, %xmm3, %xmm8, %xmm1
  vpxor %xmm2, %xmm7, %xmm7
  vpclmulqdq $0, %xmm3, %xmm8, %xmm2
  vpclmulqdq $17, %xmm3, %xmm8, %xmm8
  vpxor %xmm5, %xmm6, %xmm6
  vpxor %xmm1, %xmm6, %xmm6
  vpxor %xmm2, %xmm4, %xmm4
  pxor %xmm3, %xmm3
  mov $3254779904, %rax
  pinsrd $3, %eax, %xmm3
  vpxor %xmm8, %xmm7, %xmm7
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  sub $128, %rcx
L71:
  movdqu 32(%rbp), %xmm11
  mov %rcx, %r8
  mov 104(%rsp), %rax
  mov 112(%rsp), %rdi
  mov 120(%rsp), %rdx
  mov %rdx, %r14
  mov $579005069656919567, %r12
  pinsrq $0, %r12, %xmm9
  mov $283686952306183, %r12
  pinsrq $1, %r12, %xmm9
  pshufb %xmm9, %xmm11
  pxor %xmm10, %xmm10
  mov $1, %rbx
  pinsrd $0, %ebx, %xmm10
  mov %rax, %r11
  mov %rdi, %r10
  mov $0, %rbx
  jmp L83
.balign 16
L82:
  movdqu %xmm11, %xmm0
  pshufb %xmm9, %xmm0
  movdqu 0(%r8), %xmm2
  pxor %xmm2, %xmm0
  movdqu 16(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 32(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 48(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 64(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 80(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 96(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 112(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 128(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 144(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 160(%r8), %xmm2
  aesenclast %xmm2, %xmm0
  pxor %xmm2, %xmm2
  movdqu 0(%r11), %xmm2
  pxor %xmm0, %xmm2
  movdqu %xmm2, 0(%r10)
  add $1, %rbx
  add $16, %r11
  add $16, %r10
  paddd %xmm10, %xmm11
.balign 16
L83:
  cmp %rdx, %rbx
  jne L82
  mov %rdi, %r11
  jmp L85
.balign 16
L84:
  add $80, %r11
  movdqu -32(%r9), %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  movdqu %xmm1, %xmm4
  movdqu -16(%r9), %xmm1
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 16(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 64(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 80(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  vpxor %xmm1, %xmm4, %xmm4
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  pxor %xmm3, %xmm3
  mov $3254779904, %r10
  pinsrd $3, %r10d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  add $96, %r11
  sub $6, %rdx
.balign 16
L85:
  cmp $6, %rdx
  jae L84
  cmp $0, %rdx
  jbe L86
  mov %rdx, %r10
  sub $1, %r10
  imul $16, %r10
  add %r10, %r11
  movdqu -32(%r9), %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  cmp $1, %rdx
  jne L88
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu %xmm1, %xmm4
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  jmp L89
L88:
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  movdqu %xmm1, %xmm4
  movdqu -16(%r9), %xmm1
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  movdqu %xmm1, %xmm5
  cmp $2, %rdx
  je L90
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 16(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  cmp $3, %rdx
  je L92
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 32(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  cmp $4, %rdx
  je L94
  sub $16, %r11
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu 0(%r11), %xmm0
  pshufb %xmm9, %xmm0
  vpxor %xmm1, %xmm4, %xmm4
  movdqu 64(%r9), %xmm1
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
  movdqu %xmm1, %xmm5
  jmp L95
L94:
L95:
  jmp L93
L92:
L93:
  jmp L91
L90:
L91:
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  vpxor %xmm1, %xmm4, %xmm4
  vpxor %xmm2, %xmm6, %xmm6
  vpxor %xmm3, %xmm6, %xmm6
  vpxor %xmm5, %xmm7, %xmm7
L89:
  pxor %xmm3, %xmm3
  mov $3254779904, %r10
  pinsrd $3, %r10d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  jmp L87
L86:
L87:
  add 96(%rsp), %r14
  imul $16, %r14
  mov 136(%rsp), %r13
  cmp %r14, %r13
  jbe L96
  mov 128(%rsp), %rax
  mov %r13, %r10
  and $15, %r10
  movdqu %xmm11, %xmm0
  pshufb %xmm9, %xmm0
  movdqu 0(%r8), %xmm2
  pxor %xmm2, %xmm0
  movdqu 16(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 32(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 48(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 64(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 80(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 96(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 112(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 128(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 144(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 160(%r8), %xmm2
  aesenclast %xmm2, %xmm0
  pxor %xmm2, %xmm2
  movdqu 0(%rax), %xmm4
  pxor %xmm4, %xmm0
  movdqu %xmm0, 0(%rax)
  cmp $8, %r10
  jae L98
  mov $0, %rcx
  pinsrq $1, %rcx, %xmm0
  mov %r10, %rcx
  shl $3, %rcx
  mov $1, %r11
  shl %cl, %r11
  sub $1, %r11
  pextrq $0, %xmm0, %rcx
  and %r11, %rcx
  pinsrq $0, %rcx, %xmm0
  jmp L99
L98:
  mov %r10, %rcx
  sub $8, %rcx
  shl $3, %rcx
  mov $1, %r11
  shl %cl, %r11
  sub $1, %r11
  pextrq $1, %xmm0, %rcx
  and %r11, %rcx
  pinsrq $1, %rcx, %xmm0
L99:
  pshufb %xmm9, %xmm0
  movdqu -32(%r9), %xmm5
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu %xmm1, %xmm4
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  pxor %xmm3, %xmm3
  mov $3254779904, %r11
  pinsrd $3, %r11d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  jmp L97
L96:
L97:
  mov %r15, %r11
  pxor %xmm0, %xmm0
  mov %r11, %rax
  imul $8, %rax
  pinsrq $1, %rax, %xmm0
  mov %r13, %rax
  imul $8, %rax
  pinsrq $0, %rax, %xmm0
  movdqu -32(%r9), %xmm5
  vpxor %xmm0, %xmm8, %xmm0
  vpclmulqdq $0, %xmm5, %xmm0, %xmm1
  vpclmulqdq $16, %xmm5, %xmm0, %xmm2
  vpclmulqdq $1, %xmm5, %xmm0, %xmm3
  vpclmulqdq $17, %xmm5, %xmm0, %xmm5
  movdqu %xmm1, %xmm4
  vpxor %xmm3, %xmm2, %xmm6
  movdqu %xmm5, %xmm7
  pxor %xmm3, %xmm3
  mov $3254779904, %r11
  pinsrd $3, %r11d, %xmm3
  vpslldq $8, %xmm6, %xmm5
  vpxor %xmm5, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm0
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpsrldq $8, %xmm6, %xmm6
  vpxor %xmm6, %xmm7, %xmm7
  vpxor %xmm0, %xmm4, %xmm4
  vpalignr $8, %xmm4, %xmm4, %xmm8
  vpclmulqdq $16, %xmm3, %xmm4, %xmm4
  vpxor %xmm7, %xmm8, %xmm8
  vpxor %xmm4, %xmm8, %xmm8
  movdqu 0(%rbp), %xmm0
  pshufb %xmm9, %xmm0
  movdqu 0(%r8), %xmm2
  pxor %xmm2, %xmm0
  movdqu 16(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 32(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 48(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 64(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 80(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 96(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 112(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 128(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 144(%r8), %xmm2
  aesenc %xmm2, %xmm0
  movdqu 160(%r8), %xmm2
  aesenclast %xmm2, %xmm0
  pxor %xmm2, %xmm2
  pshufb %xmm9, %xmm8
  mov 160(%rsp), %r15   # address of ghash
  movdqu %xmm8, 0(%r15) # Saving ghash
  pxor %xmm0, %xmm8
  mov 152(%rsp), %r15
  movdqu %xmm8, 0(%r15)
  pop %rbx
  pop %rbp
  pop %rdi
  pop %rsi
  pop %r12
  pop %r13
  pop %r14
  pop %r15
  ret
