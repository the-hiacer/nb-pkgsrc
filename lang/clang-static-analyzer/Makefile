# $NetBSD: Makefile,v 1.18 2020/06/02 08:24:12 adam Exp $

PKGREVISION= 1
.include "../../lang/clang/Makefile.common"

PKGNAME=	${DISTNAME:S/clang/clang-static-analyzer/:S/.src//}

DEPENDS+=	clang-${PKGVERSION_NOREV}{,nb*}:../../lang/clang

USE_TOOLS+=	perl:run

DISTINFO_FILE?=	${.CURDIR}/../../lang/clang/distinfo
PATCHDIR?=	${.CURDIR}/../../lang/clang/patches

BUILD_TARGET=	clang-check scan-build scan-view
INSTALL_DIRS=	../build/tools/clang-check ../build/tools/scan-build ../build/tools/scan-view

CMAKE_ARGS+=	-DCLANG_ENABLE_STATIC_ANALYZER=ON

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 5.0.1

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
