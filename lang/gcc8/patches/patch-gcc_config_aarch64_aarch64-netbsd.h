$NetBSD: patch-gcc_config_aarch64_aarch64-netbsd.h,v 1.2 2019/04/18 19:18:02 rillig Exp $

AArch64 support for NetBSD.

--- /dev/null	2018-11-09 09:25:57.929086649 +0000
+++ gcc/config/aarch64/aarch64-netbsd.h	2018-11-09 09:23:18.308262443 +0000
@@ -0,0 +1,97 @@
+/* Definitions for AArch64 running NetBSD
+   Copyright (C) 2016-2017 Free Software Foundation, Inc.
+
+   This file is part of GCC.
+
+   GCC is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 3, or (at your option)
+   any later version.
+
+   GCC is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with GCC; see the file COPYING3.  If not see
+   <http://www.gnu.org/licenses/>.  */
+
+#ifndef GCC_AARCH64_NETBSD_H
+#define GCC_AARCH64_NETBSD_H
+
+#define TARGET_LINKER_BIG_EMULATION "aarch64nbsdb"
+#define TARGET_LINKER_LITTLE_EMULATION "aarch64nbsd"
+
+#if TARGET_BIG_ENDIAN_DEFAULT
+#define TARGET_LINKER_EMULATION  TARGET_LINKER_BIG_EMULATION
+#else
+#define TARGET_LINKER_EMULATION  TARGET_LINKER_LITTLE_EMULATION
+#endif
+
+#undef  SUBTARGET_EXTRA_LINK_SPEC
+#define SUBTARGET_EXTRA_LINK_SPEC " -m" TARGET_LINKER_EMULATION
+
+#define NETBSD_ENTRY_POINT "__start"
+
+#define NETBSD_TARGET_LINK_SPEC  "%{h*}			\
+   -X %{mbig-endian:-EB -m " TARGET_LINKER_BIG_EMULATION "} \
+   %{mlittle-endian:-EL -m " TARGET_LINKER_LITTLE_EMULATION "} \
+   %(netbsd_link_spec)"
+
+#if TARGET_FIX_ERR_A53_835769_DEFAULT
+#define CA53_ERR_835769_SPEC \
+  " %{!mno-fix-cortex-a53-835769:--fix-cortex-a53-835769}"
+#else
+#define CA53_ERR_835769_SPEC \
+  " %{mfix-cortex-a53-835769:--fix-cortex-a53-835769}"
+#endif
+
+#ifdef TARGET_FIX_ERR_A53_843419_DEFAULT
+#define CA53_ERR_843419_SPEC \
+  " %{!mno-fix-cortex-a53-843419:--fix-cortex-a53-843419}"
+#else
+#define CA53_ERR_843419_SPEC \
+  " %{mfix-cortex-a53-843419:--fix-cortex-a53-843419}"
+#endif
+
+#undef  LINK_SPEC
+#define LINK_SPEC NETBSD_LINK_SPEC_ELF 		\
+		  NETBSD_TARGET_LINK_SPEC	\
+                  CA53_ERR_835769_SPEC		\
+                  CA53_ERR_843419_SPEC
+
+#undef TARGET_OS_CPP_BUILTINS
+#define TARGET_OS_CPP_BUILTINS()		\
+  do						\
+    {						\
+      NETBSD_OS_CPP_BUILTINS_ELF();		\
+    }						\
+  while (0)
+
+#undef SUBTARGET_CPP_SPEC
+#define SUBTARGET_CPP_SPEC NETBSD_CPP_SPEC
+
+#if 0
+#define TARGET_ASM_FILE_END file_end_indicate_exec_stack
+#endif
+
+#if 0
+/* Uninitialized common symbols in non-PIE executables, even with
+   strong definitions in dependent shared libraries, will resolve
+   to COPY relocated symbol in the executable.  See PR65780.  */
+#undef TARGET_BINDS_LOCAL_P
+#define TARGET_BINDS_LOCAL_P default_binds_local_p_2
+#endif
+
+#if 0
+#undef MCOUNT_NAME
+#define MCOUNT_NAME ".mcount"
+#endif
+
+#undef EXTRA_SPECS
+#define EXTRA_SPECS \
+  { "asm_cpu_spec",             ASM_CPU_SPEC }, \
+  NETBSD_SUBTARGET_EXTRA_SPECS
+
+#endif  /* GCC_AARCH64_NETBSD_H */
