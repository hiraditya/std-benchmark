
str.obj:     file format pe-x86-64

compiled with /Ob2 /Fo str.cpp

Disassembly of section .text$mn:

0000000000000000 <?t1@@YAHXZ>:
   0:	48 83 ec 58          	sub    $0x58,%rsp
   4:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # b <?t1@@YAHXZ+0xb>
   b:	48 33 c4             	xor    %rsp,%rax
   e:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  13:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 1a <?t1@@YAHXZ+0x1a>
  1a:	48 8d 4c 24 28       	lea    0x28(%rsp),%rcx
  1f:	e8 00 00 00 00       	callq  24 <?t1@@YAHXZ+0x24>
  24:	e8 00 00 00 00       	callq  29 <?t1@@YAHXZ+0x29>
  29:	c7 44 24 20 00 00 00 	movl   $0x0,0x20(%rsp)
  30:	00 
  31:	48 8d 4c 24 28       	lea    0x28(%rsp),%rcx
  36:	e8 00 00 00 00       	callq  3b <?t1@@YAHXZ+0x3b>
  3b:	8b 44 24 20          	mov    0x20(%rsp),%eax
  3f:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  44:	48 33 cc             	xor    %rsp,%rcx
  47:	e8 00 00 00 00       	callq  4c <?t1@@YAHXZ+0x4c>
  4c:	48 83 c4 58          	add    $0x58,%rsp
  50:	c3                   	retq   
  51:	cc                   	int3   
  52:	cc                   	int3   
  53:	cc                   	int3   
  54:	cc                   	int3   
  55:	cc                   	int3   
  56:	cc                   	int3   
  57:	cc                   	int3   
  58:	cc                   	int3   
  59:	cc                   	int3   
  5a:	cc                   	int3   
  5b:	cc                   	int3   
  5c:	cc                   	int3   
  5d:	cc                   	int3   
  5e:	cc                   	int3   
  5f:	cc                   	int3   

0000000000000060 <?t2@@YAHXZ>:
  60:	48 83 ec 58          	sub    $0x58,%rsp
  64:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 6b <?t2@@YAHXZ+0xb>
  6b:	48 33 c4             	xor    %rsp,%rax
  6e:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  73:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 7a <?t2@@YAHXZ+0x1a>
  7a:	48 8d 4c 24 28       	lea    0x28(%rsp),%rcx
  7f:	e8 00 00 00 00       	callq  84 <?t2@@YAHXZ+0x24>
  84:	b2 61                	mov    $0x61,%dl
  86:	48 8d 4c 24 28       	lea    0x28(%rsp),%rcx
  8b:	e8 00 00 00 00       	callq  90 <?t2@@YAHXZ+0x30>
  90:	c7 44 24 20 00 00 00 	movl   $0x0,0x20(%rsp)
  97:	00 
  98:	48 8d 4c 24 28       	lea    0x28(%rsp),%rcx
  9d:	e8 00 00 00 00       	callq  a2 <?t2@@YAHXZ+0x42>
  a2:	8b 44 24 20          	mov    0x20(%rsp),%eax
  a6:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  ab:	48 33 cc             	xor    %rsp,%rcx
  ae:	e8 00 00 00 00       	callq  b3 <?t2@@YAHXZ+0x53>
  b3:	48 83 c4 58          	add    $0x58,%rsp
  b7:	c3                   	retq   
  b8:	cc                   	int3   
  b9:	cc                   	int3   
  ba:	cc                   	int3   
  bb:	cc                   	int3   
  bc:	cc                   	int3   
  bd:	cc                   	int3   
  be:	cc                   	int3   
  bf:	cc                   	int3   

00000000000000c0 <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z>:
  c0:	44 89 44 24 18       	mov    %r8d,0x18(%rsp)
  c5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
  ca:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
  cf:	48 83 ec 38          	sub    $0x38,%rsp
  d3:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  d8:	c7 44 24 24 00 00 00 	movl   $0x0,0x24(%rsp)
  df:	00 
  e0:	eb 0a                	jmp    ec <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x2c>
  e2:	8b 44 24 24          	mov    0x24(%rsp),%eax
  e6:	ff c0                	inc    %eax
  e8:	89 44 24 24          	mov    %eax,0x24(%rsp)
  ec:	8b 44 24 50          	mov    0x50(%rsp),%eax
  f0:	39 44 24 24          	cmp    %eax,0x24(%rsp)
  f4:	7d 3d                	jge    133 <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x73>
  f6:	45 33 c0             	xor    %r8d,%r8d
  f9:	48 8b 54 24 48       	mov    0x48(%rsp),%rdx
  fe:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 103:	e8 00 00 00 00       	callq  108 <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x48>
 108:	48 63 4c 24 24       	movslq 0x24(%rsp),%rcx
 10d:	48 3b c1             	cmp    %rcx,%rax
 110:	75 0a                	jne    11c <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x5c>
 112:	c7 44 24 28 01 00 00 	movl   $0x1,0x28(%rsp)
 119:	00 
 11a:	eb 08                	jmp    124 <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x64>
 11c:	c7 44 24 28 00 00 00 	movl   $0x0,0x28(%rsp)
 123:	00 
 124:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
 129:	0b 44 24 28          	or     0x28(%rsp),%eax
 12d:	88 44 24 20          	mov    %al,0x20(%rsp)
 131:	eb af                	jmp    e2 <?foo1@@YAHAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0H@Z+0x22>
 133:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
 138:	48 83 c4 38          	add    $0x38,%rsp
 13c:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z>:
   0:	4c 89 4c 24 20       	mov    %r9,0x20(%rsp)
   5:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   a:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   f:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
  14:	48 83 ec 38          	sub    $0x38,%rsp
  18:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  1d:	48 39 44 24 60       	cmp    %rax,0x60(%rsp)
  22:	77 17                	ja     3b <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x3b>
  24:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  29:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  2e:	48 2b c8             	sub    %rax,%rcx
  31:	48 8b c1             	mov    %rcx,%rax
  34:	48 39 44 24 50       	cmp    %rax,0x50(%rsp)
  39:	76 0c                	jbe    47 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x47>
  3b:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  42:	e9 be 00 00 00       	jmpq   105 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x105>
  47:	48 83 7c 24 60 00    	cmpq   $0x0,0x60(%rsp)
  4d:	75 0a                	jne    59 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x59>
  4f:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  54:	e9 ac 00 00 00       	jmpq   105 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x105>
  59:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  5e:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  63:	48 2b c8             	sub    %rax,%rcx
  66:	48 8b c1             	mov    %rcx,%rax
  69:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
  6e:	48 8d 44 01 01       	lea    0x1(%rcx,%rax,1),%rax
  73:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  78:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  7d:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
  82:	48 03 c8             	add    %rax,%rcx
  85:	48 8b c1             	mov    %rcx,%rax
  88:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  8d:	eb 0d                	jmp    9c <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x9c>
  8f:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  94:	48 ff c0             	inc    %rax
  97:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  9c:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  a1:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  a6:	48 2b c8             	sub    %rax,%rcx
  a9:	48 8b c1             	mov    %rcx,%rax
  ac:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
  b1:	0f be 09             	movsbl (%rcx),%ecx
  b4:	4c 8b c0             	mov    %rax,%r8
  b7:	8b d1                	mov    %ecx,%edx
  b9:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  be:	e8 00 00 00 00       	callq  c3 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0xc3>
  c3:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  c8:	48 83 7c 24 20 00    	cmpq   $0x0,0x20(%rsp)
  ce:	75 09                	jne    d9 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0xd9>
  d0:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  d7:	eb 2c                	jmp    105 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x105>
  d9:	4c 8b 44 24 60       	mov    0x60(%rsp),%r8
  de:	48 8b 54 24 58       	mov    0x58(%rsp),%rdx
  e3:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  e8:	e8 00 00 00 00       	callq  ed <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0xed>
  ed:	85 c0                	test   %eax,%eax
  ef:	75 12                	jne    103 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x103>
  f1:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
  f6:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  fb:	48 2b c8             	sub    %rax,%rcx
  fe:	48 8b c1             	mov    %rcx,%rax
 101:	eb 02                	jmp    105 <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x105>
 103:	eb 8a                	jmp    8f <??$_Traits_find@U?$char_traits@D@std@@@std@@YA_KQEBD_K101@Z+0x8f>
 105:	48 83 c4 38          	add    $0x38,%rsp
 109:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@QEBD@Z>:
   0:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   5:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   a:	48 83 ec 48          	sub    $0x48,%rsp
   e:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  13:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  18:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  1d:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  22:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  27:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  2e:	00 
  2f:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  34:	48 c7 40 18 00 00 00 	movq   $0x0,0x18(%rax)
  3b:	00 
  3c:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
  41:	e8 00 00 00 00       	callq  46 <??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@QEBD@Z+0x46>
  46:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
  4b:	e8 00 00 00 00       	callq  50 <??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@QEBD@Z+0x50>
  50:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  55:	4c 8b 44 24 30       	mov    0x30(%rsp),%r8
  5a:	48 8b 54 24 58       	mov    0x58(%rsp),%rdx
  5f:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
  64:	e8 00 00 00 00       	callq  69 <??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA@QEBD@Z+0x69>
  69:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  6e:	48 83 c4 48          	add    $0x48,%rsp
  72:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Allocate@std@@YAPEAX_K0_N@Z>:
   0:	44 88 44 24 18       	mov    %r8b,0x18(%rsp)
   5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   a:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   f:	48 83 ec 48          	sub    $0x48,%rsp
  13:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  1a:	00 00 
  1c:	48 83 7c 24 50 00    	cmpq   $0x0,0x50(%rsp)
  22:	75 0a                	jne    2e <?_Allocate@std@@YAPEAX_K0_N@Z+0x2e>
  24:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  29:	e9 c5 00 00 00       	jmpq   f3 <?_Allocate@std@@YAPEAX_K0_N@Z+0xf3>
  2e:	33 d2                	xor    %edx,%edx
  30:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  37:	48 f7 74 24 58       	divq   0x58(%rsp)
  3c:	48 3b 44 24 50       	cmp    0x50(%rsp),%rax
  41:	73 05                	jae    48 <?_Allocate@std@@YAPEAX_K0_N@Z+0x48>
  43:	e8 00 00 00 00       	callq  48 <?_Allocate@std@@YAPEAX_K0_N@Z+0x48>
  48:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  4d:	48 0f af 44 24 58    	imul   0x58(%rsp),%rax
  53:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  58:	0f b6 44 24 60       	movzbl 0x60(%rsp),%eax
  5d:	85 c0                	test   %eax,%eax
  5f:	74 71                	je     d2 <?_Allocate@std@@YAPEAX_K0_N@Z+0xd2>
  61:	48 81 7c 24 28 00 10 	cmpq   $0x1000,0x28(%rsp)
  68:	00 00 
  6a:	72 66                	jb     d2 <?_Allocate@std@@YAPEAX_K0_N@Z+0xd2>
  6c:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  71:	48 83 c0 27          	add    $0x27,%rax
  75:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  7a:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  7f:	48 39 44 24 38       	cmp    %rax,0x38(%rsp)
  84:	77 05                	ja     8b <?_Allocate@std@@YAPEAX_K0_N@Z+0x8b>
  86:	e8 00 00 00 00       	callq  8b <?_Allocate@std@@YAPEAX_K0_N@Z+0x8b>
  8b:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  90:	e8 00 00 00 00       	callq  95 <?_Allocate@std@@YAPEAX_K0_N@Z+0x95>
  95:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  9a:	48 83 7c 24 30 00    	cmpq   $0x0,0x30(%rsp)
  a0:	75 05                	jne    a7 <?_Allocate@std@@YAPEAX_K0_N@Z+0xa7>
  a2:	e8 00 00 00 00       	callq  a7 <?_Allocate@std@@YAPEAX_K0_N@Z+0xa7>
  a7:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  ac:	48 83 c0 27          	add    $0x27,%rax
  b0:	48 83 e0 e0          	and    $0xffffffffffffffe0,%rax
  b4:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  b9:	b8 08 00 00 00       	mov    $0x8,%eax
  be:	48 6b c0 ff          	imul   $0xffffffffffffffff,%rax,%rax
  c2:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  c7:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
  cc:	48 89 14 01          	mov    %rdx,(%rcx,%rax,1)
  d0:	eb 1c                	jmp    ee <?_Allocate@std@@YAPEAX_K0_N@Z+0xee>
  d2:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  d7:	e8 00 00 00 00       	callq  dc <?_Allocate@std@@YAPEAX_K0_N@Z+0xdc>
  dc:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  e1:	48 83 7c 24 20 00    	cmpq   $0x0,0x20(%rsp)
  e7:	75 05                	jne    ee <?_Allocate@std@@YAPEAX_K0_N@Z+0xee>
  e9:	e8 00 00 00 00       	callq  ee <?_Allocate@std@@YAPEAX_K0_N@Z+0xee>
  ee:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  f3:	48 83 c4 48          	add    $0x48,%rsp
  f7:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z>:
   0:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   5:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   a:	48 81 ec c8 00 00 00 	sub    $0xc8,%rsp
  11:	48 c7 84 24 a8 00 00 	movq   $0xfffffffffffffffe,0xa8(%rsp)
  18:	00 fe ff ff ff 
  1d:	48 c7 44 24 58 ff ff 	movq   $0xffffffffffffffff,0x58(%rsp)
  24:	ff ff 
  26:	48 83 7c 24 58 01    	cmpq   $0x1,0x58(%rsp)
  2c:	77 0b                	ja     39 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x39>
  2e:	48 c7 44 24 60 01 00 	movq   $0x1,0x60(%rsp)
  35:	00 00 
  37:	eb 0d                	jmp    46 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x46>
  39:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  3e:	48 ff c8             	dec    %rax
  41:	48 89 44 24 60       	mov    %rax,0x60(%rsp)
  46:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  4b:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  50:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  55:	48 39 84 24 d8 00 00 	cmp    %rax,0xd8(%rsp)
  5c:	00 
  5d:	76 05                	jbe    64 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x64>
  5f:	e8 00 00 00 00       	callq  64 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x64>
  64:	48 8b 84 24 d0 00 00 	mov    0xd0(%rsp),%rax
  6b:	00 
  6c:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  71:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  76:	48 8b 40 18          	mov    0x18(%rax),%rax
  7a:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  7f:	48 8b 84 24 d8 00 00 	mov    0xd8(%rsp),%rax
  86:	00 
  87:	48 83 c8 0f          	or     $0xf,%rax
  8b:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  90:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  95:	48 39 44 24 48       	cmp    %rax,0x48(%rsp)
  9a:	73 0f                	jae    ab <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0xab>
  9c:	48 8b 84 24 d8 00 00 	mov    0xd8(%rsp),%rax
  a3:	00 
  a4:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  a9:	eb 7b                	jmp    126 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x126>
  ab:	33 d2                	xor    %edx,%edx
  ad:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  b2:	b9 02 00 00 00       	mov    $0x2,%ecx
  b7:	48 f7 f1             	div    %rcx
  ba:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
  bf:	33 d2                	xor    %edx,%edx
  c1:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  c6:	b9 03 00 00 00       	mov    $0x3,%ecx
  cb:	48 f7 f1             	div    %rcx
  ce:	48 8b 4c 24 68       	mov    0x68(%rsp),%rcx
  d3:	48 3b c8             	cmp    %rax,%rcx
  d6:	77 02                	ja     da <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0xda>
  d8:	eb 4c                	jmp    126 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x126>
  da:	33 d2                	xor    %edx,%edx
  dc:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  e1:	b9 02 00 00 00       	mov    $0x2,%ecx
  e6:	48 f7 f1             	div    %rcx
  e9:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  ee:	48 2b c8             	sub    %rax,%rcx
  f1:	48 8b c1             	mov    %rcx,%rax
  f4:	48 39 44 24 30       	cmp    %rax,0x30(%rsp)
  f9:	77 21                	ja     11c <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x11c>
  fb:	33 d2                	xor    %edx,%edx
  fd:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
 102:	b9 02 00 00 00       	mov    $0x2,%ecx
 107:	48 f7 f1             	div    %rcx
 10a:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
 10f:	48 03 c8             	add    %rax,%rcx
 112:	48 8b c1             	mov    %rcx,%rax
 115:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
 11a:	eb 0a                	jmp    126 <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x126>
 11c:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
 121:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
 126:	48 8b 84 24 d0 00 00 	mov    0xd0(%rsp),%rax
 12d:	00 
 12e:	48 89 84 24 b0 00 00 	mov    %rax,0xb0(%rsp)
 135:	00 
 136:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
 13b:	48 ff c0             	inc    %rax
 13e:	41 b0 01             	mov    $0x1,%r8b
 141:	ba 01 00 00 00       	mov    $0x1,%edx
 146:	48 8b c8             	mov    %rax,%rcx
 149:	e8 00 00 00 00       	callq  14e <?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z+0x14e>
 14e:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
 153:	eb 00                	jmp    155 <$LN16>

0000000000000155 <$LN16>:
 155:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 15a:	48 83 78 18 10       	cmpq   $0x10,0x18(%rax)
 15f:	72 0a                	jb     16b <$LN16+0x16>
 161:	c7 44 24 38 01 00 00 	movl   $0x1,0x38(%rsp)
 168:	00 
 169:	eb 08                	jmp    173 <$LN16+0x1e>
 16b:	c7 44 24 38 00 00 00 	movl   $0x0,0x38(%rsp)
 172:	00 
 173:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
 178:	85 c0                	test   %eax,%eax
 17a:	74 7f                	je     1fb <$LN16+0xa6>
 17c:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 181:	48 8b 00             	mov    (%rax),%rax
 184:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
 189:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 18e:	48 8b 40 10          	mov    0x10(%rax),%rax
 192:	48 ff c0             	inc    %rax
 195:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
 19a:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 19f:	48 89 84 24 80 00 00 	mov    %rax,0x80(%rsp)
 1a6:	00 
 1a7:	4c 8b 44 24 70       	mov    0x70(%rsp),%r8
 1ac:	48 8b 54 24 78       	mov    0x78(%rsp),%rdx
 1b1:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
 1b8:	00 
 1b9:	e8 00 00 00 00       	callq  1be <$LN16+0x69>
 1be:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 1c3:	48 8b 00             	mov    (%rax),%rax
 1c6:	48 89 84 24 88 00 00 	mov    %rax,0x88(%rsp)
 1cd:	00 
 1ce:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
 1d3:	48 ff c0             	inc    %rax
 1d6:	41 b8 01 00 00 00    	mov    $0x1,%r8d
 1dc:	48 8b d0             	mov    %rax,%rdx
 1df:	48 8b 8c 24 88 00 00 	mov    0x88(%rsp),%rcx
 1e6:	00 
 1e7:	e8 00 00 00 00       	callq  1ec <$LN16+0x97>
 1ec:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 1f1:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 1f6:	48 89 08             	mov    %rcx,(%rax)
 1f9:	eb 78                	jmp    273 <$LN16+0x11e>
 1fb:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 200:	48 8b 40 10          	mov    0x10(%rax),%rax
 204:	48 ff c0             	inc    %rax
 207:	48 89 84 24 90 00 00 	mov    %rax,0x90(%rsp)
 20e:	00 
 20f:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 214:	48 89 84 24 98 00 00 	mov    %rax,0x98(%rsp)
 21b:	00 
 21c:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 221:	4c 8b 84 24 90 00 00 	mov    0x90(%rsp),%r8
 228:	00 
 229:	48 8b d0             	mov    %rax,%rdx
 22c:	48 8b 8c 24 98 00 00 	mov    0x98(%rsp),%rcx
 233:	00 
 234:	e8 00 00 00 00       	callq  239 <$LN16+0xe4>
 239:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 23e:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
 243:	48 83 7c 24 50 00    	cmpq   $0x0,0x50(%rsp)
 249:	74 1c                	je     267 <$LN16+0x112>
 24b:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 250:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 255:	48 89 08             	mov    %rcx,(%rax)
 258:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 25d:	48 89 84 24 a0 00 00 	mov    %rax,0xa0(%rsp)
 264:	00 
 265:	eb 0c                	jmp    273 <$LN16+0x11e>
 267:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
 26e:	00 00 00 00 00 
 273:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 278:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
 27d:	48 89 48 18          	mov    %rcx,0x18(%rax)
 281:	48 81 c4 c8 00 00 00 	add    $0xc8,%rsp
 288:	c3                   	retq   

Disassembly of section .text$x:

0000000000000000 <?catch$0@?0??_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z@4HA>:
   0:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   5:	55                   	push   %rbp
   6:	48 83 ec 20          	sub    $0x20,%rsp
   a:	48 8b ea             	mov    %rdx,%rbp

000000000000000d <__catch$?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z$0>:
   d:	48 8b 85 d8 00 00 00 	mov    0xd8(%rbp),%rax
  14:	48 89 45 28          	mov    %rax,0x28(%rbp)
  18:	48 8b 45 28          	mov    0x28(%rbp),%rax
  1c:	48 ff c0             	inc    %rax
  1f:	41 b0 01             	mov    $0x1,%r8b
  22:	ba 01 00 00 00       	mov    $0x1,%edx
  27:	48 8b c8             	mov    %rax,%rcx
  2a:	e8 00 00 00 00       	callq  2f <__catch$?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z$0+0x22>
  2f:	48 89 45 40          	mov    %rax,0x40(%rbp)
  33:	48 8d 05 00 00 00 00 	lea    0x0(%rip),%rax        # 3a <__catch$?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z$0+0x2d>
  3a:	48 83 c4 20          	add    $0x20,%rsp
  3e:	5d                   	pop    %rbp
  3f:	c3                   	retq   
  40:	cc                   	int3   

Disassembly of section .text$mn:

0000000000000000 <?_Deallocate@std@@YAXPEAX_K1@Z>:
   0:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   a:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   f:	48 83 ec 48          	sub    $0x48,%rsp
  13:	33 d2                	xor    %edx,%edx
  15:	48 c7 c0 ff ff ff ff 	mov    $0xffffffffffffffff,%rax
  1c:	48 f7 74 24 60       	divq   0x60(%rsp)
  21:	48 39 44 24 58       	cmp    %rax,0x58(%rsp)
  26:	76 05                	jbe    2d <?_Deallocate@std@@YAXPEAX_K1@Z+0x2d>
  28:	e8 00 00 00 00       	callq  2d <?_Deallocate@std@@YAXPEAX_K1@Z+0x2d>
  2d:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  32:	48 0f af 44 24 60    	imul   0x60(%rsp),%rax
  38:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  3d:	48 81 7c 24 30 00 10 	cmpq   $0x1000,0x30(%rsp)
  44:	00 00 
  46:	0f 82 89 00 00 00    	jb     d5 <?_Deallocate@std@@YAXPEAX_K1@Z+0xd5>
  4c:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  51:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  56:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  5b:	48 83 e0 1f          	and    $0x1f,%rax
  5f:	48 85 c0             	test   %rax,%rax
  62:	74 05                	je     69 <?_Deallocate@std@@YAXPEAX_K1@Z+0x69>
  64:	e8 00 00 00 00       	callq  69 <?_Deallocate@std@@YAXPEAX_K1@Z+0x69>
  69:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  6e:	48 83 e8 08          	sub    $0x8,%rax
  72:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  77:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
  7c:	48 8b 00             	mov    (%rax),%rax
  7f:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  84:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  89:	48 39 44 24 28       	cmp    %rax,0x28(%rsp)
  8e:	72 05                	jb     95 <?_Deallocate@std@@YAXPEAX_K1@Z+0x95>
  90:	e8 00 00 00 00       	callq  95 <?_Deallocate@std@@YAXPEAX_K1@Z+0x95>
  95:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  9a:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  9f:	48 2b c8             	sub    %rax,%rcx
  a2:	48 8b c1             	mov    %rcx,%rax
  a5:	48 83 f8 08          	cmp    $0x8,%rax
  a9:	73 05                	jae    b0 <?_Deallocate@std@@YAXPEAX_K1@Z+0xb0>
  ab:	e8 00 00 00 00       	callq  b0 <?_Deallocate@std@@YAXPEAX_K1@Z+0xb0>
  b0:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  b5:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  ba:	48 2b c8             	sub    %rax,%rcx
  bd:	48 8b c1             	mov    %rcx,%rax
  c0:	48 83 f8 27          	cmp    $0x27,%rax
  c4:	76 05                	jbe    cb <?_Deallocate@std@@YAXPEAX_K1@Z+0xcb>
  c6:	e8 00 00 00 00       	callq  cb <?_Deallocate@std@@YAXPEAX_K1@Z+0xcb>
  cb:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  d0:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
  d5:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
  da:	e8 00 00 00 00       	callq  df <?_Deallocate@std@@YAXPEAX_K1@Z+0xdf>
  df:	48 83 c4 48          	add    $0x48,%rsp
  e3:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z>:
   0:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   5:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   a:	48 83 ec 48          	sub    $0x48,%rsp
   e:	48 83 7c 24 58 00    	cmpq   $0x0,0x58(%rsp)
  14:	75 4e                	jne    64 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z+0x64>
  16:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  1b:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  20:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  25:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  2a:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  31:	00 
  32:	33 c0                	xor    %eax,%eax
  34:	48 6b c0 01          	imul   $0x1,%rax,%rax
  38:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  3d:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  42:	e8 00 00 00 00       	callq  47 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z+0x47>
  47:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  4c:	48 03 c1             	add    %rcx,%rax
  4f:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  54:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
  59:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
  5e:	88 08                	mov    %cl,(%rax)
  60:	32 c0                	xor    %al,%al
  62:	eb 21                	jmp    85 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z+0x85>
  64:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  69:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
  6e:	48 39 48 18          	cmp    %rcx,0x18(%rax)
  72:	73 0f                	jae    83 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z+0x83>
  74:	48 8b 54 24 58       	mov    0x58(%rsp),%rdx
  79:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
  7e:	e8 00 00 00 00       	callq  83 <?_Grow@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAA_N_K@Z+0x83>
  83:	b0 01                	mov    $0x1,%al
  85:	48 83 c4 48          	add    $0x48,%rsp
  89:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAPEADXZ>:
   0:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   5:	48 83 ec 28          	sub    $0x28,%rsp
   9:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
   e:	48 83 78 18 10       	cmpq   $0x10,0x18(%rax)
  13:	72 09                	jb     1e <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAPEADXZ+0x1e>
  15:	c7 04 24 01 00 00 00 	movl   $0x1,(%rsp)
  1c:	eb 07                	jmp    25 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAPEADXZ+0x25>
  1e:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
  25:	0f b6 04 24          	movzbl (%rsp),%eax
  29:	85 c0                	test   %eax,%eax
  2b:	74 19                	je     46 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAPEADXZ+0x46>
  2d:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  32:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  37:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  3c:	48 8b 00             	mov    (%rax),%rax
  3f:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  44:	eb 0a                	jmp    50 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEAAPEADXZ+0x50>
  46:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  4b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  50:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  55:	48 83 c4 28          	add    $0x28,%rsp
  59:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ>:
   0:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   5:	48 83 ec 28          	sub    $0x28,%rsp
   9:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
   e:	48 83 78 18 10       	cmpq   $0x10,0x18(%rax)
  13:	72 09                	jb     1e <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ+0x1e>
  15:	c7 04 24 01 00 00 00 	movl   $0x1,(%rsp)
  1c:	eb 07                	jmp    25 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ+0x25>
  1e:	c7 04 24 00 00 00 00 	movl   $0x0,(%rsp)
  25:	0f b6 04 24          	movzbl (%rsp),%eax
  29:	85 c0                	test   %eax,%eax
  2b:	74 19                	je     46 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ+0x46>
  2d:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  32:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  37:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  3c:	48 8b 00             	mov    (%rax),%rax
  3f:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  44:	eb 0a                	jmp    50 <?_Myptr@?$_String_val@U?$_Simple_types@D@std@@@std@@QEBAPEBDXZ+0x50>
  46:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  4b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  50:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  55:	48 83 c4 28          	add    $0x28,%rsp
  59:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ>:
   0:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   5:	48 83 ec 58          	sub    $0x58,%rsp
   9:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
   e:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  13:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  18:	48 83 78 18 10       	cmpq   $0x10,0x18(%rax)
  1d:	72 0a                	jb     29 <?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ+0x29>
  1f:	c7 44 24 24 01 00 00 	movl   $0x1,0x24(%rsp)
  26:	00 
  27:	eb 08                	jmp    31 <?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ+0x31>
  29:	c7 44 24 24 00 00 00 	movl   $0x0,0x24(%rsp)
  30:	00 
  31:	0f b6 44 24 24       	movzbl 0x24(%rsp),%eax
  36:	85 c0                	test   %eax,%eax
  38:	74 3d                	je     77 <?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ+0x77>
  3a:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  3f:	48 8b 00             	mov    (%rax),%rax
  42:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  47:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  4c:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  51:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  56:	48 8b 40 18          	mov    0x18(%rax),%rax
  5a:	48 ff c0             	inc    %rax
  5d:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  62:	41 b8 01 00 00 00    	mov    $0x1,%r8d
  68:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
  6d:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  72:	e8 00 00 00 00       	callq  77 <?_Tidy_deallocate@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ+0x77>
  77:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  7c:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  83:	00 
  84:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  89:	48 c7 40 18 0f 00 00 	movq   $0xf,0x18(%rax)
  90:	00 
  91:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  96:	b8 01 00 00 00       	mov    $0x1,%eax
  9b:	48 6b c0 00          	imul   $0x0,%rax,%rax
  9f:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  a4:	0f b6 54 24 20       	movzbl 0x20(%rsp),%edx
  a9:	88 14 01             	mov    %dl,(%rcx,%rax,1)
  ac:	48 83 c4 58          	add    $0x58,%rsp
  b0:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Tidy_init@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXXZ>:
   0:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   5:	48 83 ec 18          	sub    $0x18,%rsp
   9:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
   e:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  13:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  18:	48 c7 40 10 00 00 00 	movq   $0x0,0x10(%rax)
  1f:	00 
  20:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  25:	48 c7 40 18 0f 00 00 	movq   $0xf,0x18(%rax)
  2c:	00 
  2d:	c6 04 24 00          	movb   $0x0,(%rsp)
  31:	b8 01 00 00 00       	mov    $0x1,%eax
  36:	48 6b c0 00          	imul   $0x0,%rax,%rax
  3a:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  3f:	0f b6 14 24          	movzbl (%rsp),%edx
  43:	88 14 01             	mov    %dl,(%rcx,%rax,1)
  46:	48 83 c4 18          	add    $0x18,%rsp
  4a:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ>:
   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # b <?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ+0xb>
   b:	e8 00 00 00 00       	callq  10 <?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ+0x10>
  10:	48 83 c4 28          	add    $0x28,%rsp
  14:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ>:
   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # b <?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ+0xb>
   b:	e8 00 00 00 00       	callq  10 <?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ+0x10>
  10:	48 83 c4 28          	add    $0x28,%rsp
  14:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z>:
   0:	4c 89 4c 24 20       	mov    %r9,0x20(%rsp)
   5:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   a:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   f:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
  14:	48 83 ec 78          	sub    $0x78,%rsp
  18:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
  1f:	00 
  20:	48 8b 8c 24 90 00 00 	mov    0x90(%rsp),%rcx
  27:	00 
  28:	48 39 48 10          	cmp    %rcx,0x10(%rax)
  2c:	73 05                	jae    33 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x33>
  2e:	e8 00 00 00 00       	callq  33 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x33>
  33:	48 8b 84 24 98 00 00 	mov    0x98(%rsp),%rax
  3a:	00 
  3b:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  40:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
  47:	00 
  48:	48 8b 8c 24 90 00 00 	mov    0x90(%rsp),%rcx
  4f:	00 
  50:	48 8b 40 10          	mov    0x10(%rax),%rax
  54:	48 2b c1             	sub    %rcx,%rax
  57:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  5c:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  61:	48 39 44 24 28       	cmp    %rax,0x28(%rsp)
  66:	73 0c                	jae    74 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x74>
  68:	48 8d 44 24 28       	lea    0x28(%rsp),%rax
  6d:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  72:	eb 0a                	jmp    7e <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x7e>
  74:	48 8d 44 24 30       	lea    0x30(%rsp),%rax
  79:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  7e:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
  83:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  88:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  8d:	48 8b 00             	mov    (%rax),%rax
  90:	48 89 84 24 98 00 00 	mov    %rax,0x98(%rsp)
  97:	00 
  98:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
  9f:	00 
  a0:	48 39 84 24 80 00 00 	cmp    %rax,0x80(%rsp)
  a7:	00 
  a8:	75 42                	jne    ec <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0xec>
  aa:	48 8b 84 24 98 00 00 	mov    0x98(%rsp),%rax
  b1:	00 
  b2:	48 8b 8c 24 90 00 00 	mov    0x90(%rsp),%rcx
  b9:	00 
  ba:	48 03 c8             	add    %rax,%rcx
  bd:	48 8b c1             	mov    %rcx,%rax
  c0:	48 8b d0             	mov    %rax,%rdx
  c3:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  ca:	00 
  cb:	e8 00 00 00 00       	callq  d0 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0xd0>
  d0:	4c 8b 84 24 90 00 00 	mov    0x90(%rsp),%r8
  d7:	00 
  d8:	33 d2                	xor    %edx,%edx
  da:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  e1:	00 
  e2:	e8 00 00 00 00       	callq  e7 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0xe7>
  e7:	e9 b8 00 00 00       	jmpq   1a4 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x1a4>
  ec:	48 8b 94 24 98 00 00 	mov    0x98(%rsp),%rdx
  f3:	00 
  f4:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  fb:	00 
  fc:	e8 00 00 00 00       	callq  101 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x101>
 101:	0f b6 c0             	movzbl %al,%eax
 104:	85 c0                	test   %eax,%eax
 106:	0f 84 98 00 00 00    	je     1a4 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x1a4>
 10c:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
 113:	00 
 114:	48 8b c8             	mov    %rax,%rcx
 117:	e8 00 00 00 00       	callq  11c <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x11c>
 11c:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
 121:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
 128:	00 
 129:	48 8b c8             	mov    %rax,%rcx
 12c:	e8 00 00 00 00       	callq  131 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x131>
 131:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
 136:	48 8b 84 24 90 00 00 	mov    0x90(%rsp),%rax
 13d:	00 
 13e:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
 143:	48 03 c8             	add    %rax,%rcx
 146:	48 8b c1             	mov    %rcx,%rax
 149:	4c 8b 84 24 98 00 00 	mov    0x98(%rsp),%r8
 150:	00 
 151:	48 8b d0             	mov    %rax,%rdx
 154:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
 159:	e8 00 00 00 00       	callq  15e <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x15e>
 15e:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
 165:	00 
 166:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
 16b:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
 170:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 175:	48 8b 8c 24 98 00 00 	mov    0x98(%rsp),%rcx
 17c:	00 
 17d:	48 89 48 10          	mov    %rcx,0x10(%rax)
 181:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 186:	e8 00 00 00 00       	callq  18b <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z+0x18b>
 18b:	48 03 84 24 98 00 00 	add    0x98(%rsp),%rax
 192:	00 
 193:	48 89 44 24 60       	mov    %rax,0x60(%rsp)
 198:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
 19d:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
 1a2:	88 08                	mov    %cl,(%rax)
 1a4:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
 1ab:	00 
 1ac:	48 83 c4 78          	add    $0x78,%rsp
 1b0:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z>:
   0:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   a:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   f:	48 83 ec 68          	sub    $0x68,%rsp
  13:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  18:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  1d:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  22:	e8 00 00 00 00       	callq  27 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x27>
  27:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  2c:	48 8b 44 24 78       	mov    0x78(%rsp),%rax
  31:	48 39 44 24 30       	cmp    %rax,0x30(%rsp)
  36:	77 25                	ja     5d <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x5d>
  38:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  3d:	48 8b 40 10          	mov    0x10(%rax),%rax
  41:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  46:	48 03 c8             	add    %rax,%rcx
  49:	48 8b c1             	mov    %rcx,%rax
  4c:	48 39 44 24 78       	cmp    %rax,0x78(%rsp)
  51:	73 0a                	jae    5d <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x5d>
  53:	c7 44 24 24 01 00 00 	movl   $0x1,0x24(%rsp)
  5a:	00 
  5b:	eb 08                	jmp    65 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x65>
  5d:	c7 44 24 24 00 00 00 	movl   $0x0,0x24(%rsp)
  64:	00 
  65:	0f b6 44 24 24       	movzbl 0x24(%rsp),%eax
  6a:	85 c0                	test   %eax,%eax
  6c:	74 41                	je     af <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0xaf>
  6e:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  73:	48 8b c8             	mov    %rax,%rcx
  76:	e8 00 00 00 00       	callq  7b <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x7b>
  7b:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  80:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
  85:	48 8b 4c 24 78       	mov    0x78(%rsp),%rcx
  8a:	48 2b c8             	sub    %rax,%rcx
  8d:	48 8b c1             	mov    %rcx,%rax
  90:	4c 8b 8c 24 80 00 00 	mov    0x80(%rsp),%r9
  97:	00 
  98:	4c 8b c0             	mov    %rax,%r8
  9b:	48 8b 54 24 70       	mov    0x70(%rsp),%rdx
  a0:	48 8b 4c 24 70       	mov    0x70(%rsp),%rcx
  a5:	e8 00 00 00 00       	callq  aa <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0xaa>
  aa:	e9 8a 00 00 00       	jmpq   139 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x139>
  af:	48 8b 94 24 80 00 00 	mov    0x80(%rsp),%rdx
  b6:	00 
  b7:	48 8b 4c 24 70       	mov    0x70(%rsp),%rcx
  bc:	e8 00 00 00 00       	callq  c1 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0xc1>
  c1:	0f b6 c0             	movzbl %al,%eax
  c4:	85 c0                	test   %eax,%eax
  c6:	74 6c                	je     134 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x134>
  c8:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  cd:	48 8b c8             	mov    %rax,%rcx
  d0:	e8 00 00 00 00       	callq  d5 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0xd5>
  d5:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  da:	4c 8b 84 24 80 00 00 	mov    0x80(%rsp),%r8
  e1:	00 
  e2:	48 8b 54 24 78       	mov    0x78(%rsp),%rdx
  e7:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  ec:	e8 00 00 00 00       	callq  f1 <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0xf1>
  f1:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  f6:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  fb:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
 100:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
 105:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
 10c:	00 
 10d:	48 89 48 10          	mov    %rcx,0x10(%rax)
 111:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
 116:	e8 00 00 00 00       	callq  11b <?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@QEBD_K@Z+0x11b>
 11b:	48 03 84 24 80 00 00 	add    0x80(%rsp),%rax
 122:	00 
 123:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
 128:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 12d:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
 132:	88 08                	mov    %cl,(%rax)
 134:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
 139:	48 83 c4 68          	add    $0x68,%rsp
 13d:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z>:
   0:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   a:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   f:	48 83 ec 68          	sub    $0x68,%rsp
  13:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  18:	48 8b 4c 24 78       	mov    0x78(%rsp),%rcx
  1d:	48 39 48 10          	cmp    %rcx,0x10(%rax)
  21:	73 05                	jae    28 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x28>
  23:	e8 00 00 00 00       	callq  28 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x28>
  28:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  2d:	48 8b 4c 24 78       	mov    0x78(%rsp),%rcx
  32:	48 8b 40 10          	mov    0x10(%rax),%rax
  36:	48 2b c1             	sub    %rcx,%rax
  39:	48 3b 84 24 80 00 00 	cmp    0x80(%rsp),%rax
  40:	00 
  41:	77 42                	ja     85 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x85>
  43:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  48:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  4d:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  52:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  57:	48 8b 4c 24 78       	mov    0x78(%rsp),%rcx
  5c:	48 89 48 10          	mov    %rcx,0x10(%rax)
  60:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  65:	e8 00 00 00 00       	callq  6a <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x6a>
  6a:	48 03 44 24 78       	add    0x78(%rsp),%rax
  6f:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  74:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  79:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
  7e:	88 08                	mov    %cl,(%rax)
  80:	e9 af 00 00 00       	jmpq   134 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x134>
  85:	48 83 bc 24 80 00 00 	cmpq   $0x0,0x80(%rsp)
  8c:	00 00 
  8e:	0f 84 a0 00 00 00    	je     134 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x134>
  94:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  99:	48 8b c8             	mov    %rax,%rcx
  9c:	e8 00 00 00 00       	callq  a1 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0xa1>
  a1:	48 03 44 24 78       	add    0x78(%rsp),%rax
  a6:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  ab:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  b0:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  b7:	00 
  b8:	48 8b 40 10          	mov    0x10(%rax),%rax
  bc:	48 2b c1             	sub    %rcx,%rax
  bf:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  c4:	48 8b 44 24 78       	mov    0x78(%rsp),%rax
  c9:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  ce:	48 2b c8             	sub    %rax,%rcx
  d1:	48 8b c1             	mov    %rcx,%rax
  d4:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  db:	00 
  dc:	48 8b 54 24 38       	mov    0x38(%rsp),%rdx
  e1:	48 03 d1             	add    %rcx,%rdx
  e4:	48 8b ca             	mov    %rdx,%rcx
  e7:	4c 8b c0             	mov    %rax,%r8
  ea:	48 8b d1             	mov    %rcx,%rdx
  ed:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  f2:	e8 00 00 00 00       	callq  f7 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0xf7>
  f7:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
  fc:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
 101:	c6 44 24 21 00       	movb   $0x0,0x21(%rsp)
 106:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 10b:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
 110:	48 89 48 10          	mov    %rcx,0x10(%rax)
 114:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 119:	e8 00 00 00 00       	callq  11e <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K0@Z+0x11e>
 11e:	48 03 44 24 28       	add    0x28(%rsp),%rax
 123:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
 128:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 12d:	0f b6 4c 24 21       	movzbl 0x21(%rsp),%ecx
 132:	88 08                	mov    %cl,(%rax)
 134:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
 139:	48 83 c4 68          	add    $0x68,%rsp
 13d:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K@Z>:
   0:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   5:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   a:	48 83 ec 48          	sub    $0x48,%rsp
   e:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  13:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
  18:	48 39 48 10          	cmp    %rcx,0x10(%rax)
  1c:	73 05                	jae    23 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K@Z+0x23>
  1e:	e8 00 00 00 00       	callq  23 <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K@Z+0x23>
  23:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  28:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  2d:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  32:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  37:	48 8b 4c 24 58       	mov    0x58(%rsp),%rcx
  3c:	48 89 48 10          	mov    %rcx,0x10(%rax)
  40:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  45:	e8 00 00 00 00       	callq  4a <?erase@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@_K@Z+0x4a>
  4a:	48 03 44 24 58       	add    0x58(%rsp),%rax
  4f:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  54:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  59:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
  5e:	88 08                	mov    %cl,(%rax)
  60:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  65:	48 83 c4 48          	add    $0x48,%rsp
  69:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?find@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBA_KAEBV12@_K@Z>:
   0:	4c 89 44 24 18       	mov    %r8,0x18(%rsp)
   5:	48 89 54 24 10       	mov    %rdx,0x10(%rsp)
   a:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   f:	48 83 ec 48          	sub    $0x48,%rsp
  13:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  18:	48 8b c8             	mov    %rax,%rcx
  1b:	e8 00 00 00 00       	callq  20 <?find@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBA_KAEBV12@_K@Z+0x20>
  20:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  25:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  2a:	48 8b c8             	mov    %rax,%rcx
  2d:	e8 00 00 00 00       	callq  32 <?find@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBA_KAEBV12@_K@Z+0x32>
  32:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  37:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
  3c:	48 8b 40 10          	mov    0x10(%rax),%rax
  40:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  45:	4c 8b 4c 24 30       	mov    0x30(%rsp),%r9
  4a:	4c 8b 44 24 60       	mov    0x60(%rsp),%r8
  4f:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
  54:	48 8b 50 10          	mov    0x10(%rax),%rdx
  58:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  5d:	e8 00 00 00 00       	callq  62 <?find@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEBA_KAEBV12@_K@Z+0x62>
  62:	48 83 c4 48          	add    $0x48,%rsp
  66:	c3                   	retq   

Disassembly of section .text$mn:

0000000000000000 <?push_back@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXD@Z>:
   0:	88 54 24 10          	mov    %dl,0x10(%rsp)
   4:	48 89 4c 24 08       	mov    %rcx,0x8(%rsp)
   9:	48 83 ec 58          	sub    $0x58,%rsp
   d:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  12:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  17:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  1c:	48 83 c0 10          	add    $0x10,%rax
  20:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  25:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  2a:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  2f:	48 8b 49 18          	mov    0x18(%rcx),%rcx
  33:	48 39 08             	cmp    %rcx,(%rax)
  36:	75 18                	jne    50 <?push_back@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXD@Z+0x50>
  38:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  3d:	48 8b 00             	mov    (%rax),%rax
  40:	48 ff c0             	inc    %rax
  43:	48 8b d0             	mov    %rax,%rdx
  46:	48 8b 4c 24 60       	mov    0x60(%rsp),%rcx
  4b:	e8 00 00 00 00       	callq  50 <?push_back@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXD@Z+0x50>
  50:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  55:	e8 00 00 00 00       	callq  5a <?push_back@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAXD@Z+0x5a>
  5a:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  5f:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  64:	48 8b 00             	mov    (%rax),%rax
  67:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  6c:	48 03 c8             	add    %rax,%rcx
  6f:	48 8b c1             	mov    %rcx,%rax
  72:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  77:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
  7c:	0f b6 4c 24 68       	movzbl 0x68(%rsp),%ecx
  81:	88 08                	mov    %cl,(%rax)
  83:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  88:	48 8b 00             	mov    (%rax),%rax
  8b:	48 ff c0             	inc    %rax
  8e:	48 8b 4c 24 28       	mov    0x28(%rsp),%rcx
  93:	48 89 01             	mov    %rax,(%rcx)
  96:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  9b:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  a0:	48 8b 00             	mov    (%rax),%rax
  a3:	48 8b 4c 24 38       	mov    0x38(%rsp),%rcx
  a8:	48 03 c8             	add    %rax,%rcx
  ab:	48 8b c1             	mov    %rcx,%rax
  ae:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  b3:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  b8:	0f b6 4c 24 20       	movzbl 0x20(%rsp),%ecx
  bd:	88 08                	mov    %cl,(%rax)
  bf:	48 83 c4 58          	add    $0x58,%rsp
  c3:	c3                   	retq   
