# $NetBSD: Makefile,v 1.30 2020/02/10 15:13:06 adam Exp $

PKGNAME=	${DISTNAME:S/-/-client-/}
COMMENT=	Lightweight Directory Access Protocol libraries and client programs

CONFLICTS+=		openldap<2.3.23nb1

CONFIGURE_ARGS+=	--disable-slapd

#BUILD_DIRS=		include libraries clients
MAKE_DIRS=		${OPENLDAP_ETCDIR}
BUILD_DEFS+=		OPENLDAP_ETCDIR

CNFS=			ldap.conf

.include "options.mk"

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has sockelen_t definition in pthread.h of GNU pth.
CONFIGURE_ENV+=		ac_cv_type_socklen_t=yes
.endif

.include "../../databases/openldap/Makefile.common"
.include "../../mk/bsd.pkg.mk"
