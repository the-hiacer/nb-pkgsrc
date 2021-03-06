# $NetBSD: Makefile,v 1.20 2020/05/13 11:18:35 jperkin Exp $

R_PKGNAME=	Rcpp
R_PKGVER=	1.0.4.6
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Seamless R and C++ integration
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
TEST_DEPENDS+=	R-inline-[0-9]*:../../devel/R-inline
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-pkgKitten-[0-9]*:../../devel/R-pkgKitten
TEST_DEPENDS+=	R-rbenchmark-[0-9]*:../../benchmarks/R-rbenchmark

USE_LANGUAGES+=	c++

REPLACE_R+=		inst/examples/*/*.r
REPLACE_R+=		inst/examples/SugarPerformance/sugarBenchmarks.R

REPLACE_RSCRIPT+=	inst/discovery/cxx0x.R

REPLACE_SH+=		inst/examples/ConvolveBenchmarks/buildAndRun.sh
REPLACE_SH+=		inst/examples/ConvolveBenchmarks/overhead.sh

REPLACE_INTERPRETER+=	R
REPLACE.R.old=		/usr/bin/env r
REPLACE.R.new=		${PREFIX}/bin/R
REPLACE_FILES.R=	${REPLACE_R}

REPLACE_INTERPRETER+=	Rscript
REPLACE.Rscript.old=	.*Rscript
REPLACE.Rscript.new=	${PREFIX}/bin/Rscript
REPLACE_FILES.Rscript=	${REPLACE_RSCRIPT}

CHECK_SSP_SKIP+=	lib/R/library/Rcpp/*/bin/*/*.deb
CHECK_RELRO_SKIP+=	${CHECK_SSP_SKIP}

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
