$NetBSD: patch-cpan_ExtUtils-MakeMaker_lib_ExtUtils_MM__Unix.pm,v 1.1 2019/04/23 09:27:46 adam Exp $

* $Is{NetBSD} and $Is{Interix} are unified into $Is{BSD}.
* Ignore installed packlist when creating new packlist.

--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm.orig	2017-04-19 13:37:05.000000000 +0000
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm
@@ -28,8 +28,6 @@ BEGIN {
     $Is{VMS}     = $^O eq 'VMS';
     $Is{OSF}     = $^O eq 'dec_osf';
     $Is{IRIX}    = $^O eq 'irix';
-    $Is{NetBSD}  = $^O eq 'netbsd';
-    $Is{Interix} = $^O eq 'interix';
     $Is{SunOS4}  = $^O eq 'sunos';
     $Is{Solaris} = $^O eq 'solaris';
     $Is{SunOS}   = $Is{SunOS4} || $Is{Solaris};
@@ -1022,7 +1020,7 @@ sub xs_make_dynamic_lib {
     push(@m,"	\$(RM_F) \$\@\n");
 
     my $libs = '$(LDLOADLIBS)';
-    if (($Is{NetBSD} || $Is{Interix} || $Is{Android}) && $Config{'useshrplib'} eq 'true') {
+    if ($Is{BSD} && $Config{'useshrplib'} eq 'true') {
         # Use nothing on static perl platforms, and to the flags needed
         # to link against the shared libperl library on shared perl
         # platforms.  We peek at lddlflags to see if we need -Wl,-R
@@ -2264,7 +2262,7 @@ pure_vendor_install :: all
 	$(NOECHO) $(MOD_INSTALL) \
 };
     push @m,
-q{		read "}.$self->catfile('$(VENDORARCHEXP)','auto','$(FULLEXT)','.packlist').q{" \
+q{		read "" \
 		write "}.$self->catfile('$(DESTINSTALLVENDORARCH)','auto','$(FULLEXT)','.packlist').q{" \
 } unless $self->{NO_PACKLIST};
 
