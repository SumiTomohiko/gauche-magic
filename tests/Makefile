#
# $Id: template.Makefile.in,v 1.7 2007/08/10 06:16:44 shirok Exp $
#

# General info
SHELL       = /bin/bash
prefix      = /home/tom
exec_prefix = ${prefix}
bindir      = ${exec_prefix}/bin
libdir      = ${exec_prefix}/lib
datadir     = ${datarootdir}
datarootdir = ${prefix}/share
srcdir      = .


# These may be overridden by make invocators
DESTDIR        =
GOSH           = /home/tom/bin/gosh
GAUCHE_CONFIG  = /home/tom/bin/gauche-config
GAUCHE_PACKAGE = /home/tom/bin/gauche-package
INSTALL        = /home/tom/bin/gauche-install

# Other parameters
SOEXT  = so
OBJEXT = o
EXEEXT = 

# Module-specific stuff
PACKAGE   = magic

ARCHFILES = magic.$(SOEXT)
SCMFILES  = $(srcdir)/magic.scm
HEADERS   = 

TARGET    = $(ARCHFILES)
GENERATED = 
CONFIG_GENERATED = Makefile config.cache config.log config.status \
		   configure.lineno autom4te*.cache $(PACKAGE).gpd

GAUCHE_PKGINCDIR  = $(DESTDIR)${libdir}/gauche/site/include
GAUCHE_PKGLIBDIR  = $(DESTDIR)${datadir}/gauche/site/lib
GAUCHE_PKGARCHDIR = $(DESTDIR)${libdir}/gauche/site/0.8.13/i686-pc-linux-gnu

magic_SRCS = $(srcdir)/magic.c $(srcdir)/magiclib.stub

all : $(TARGET)

magic.$(SOEXT): $(magic_SRCS)
	$(GAUCHE_PACKAGE) compile --libs=-lmagic --verbose magic $(magic_SRCS)

check : all
	@rm -f test.log
	$(GOSH) -I. -I$(srcdir) $(srcdir)/test.scm > test.log

install : all
	$(INSTALL) -m 444 -T $(GAUCHE_PKGINCDIR) $(HEADERS)
	$(INSTALL) -m 444 -T $(GAUCHE_PKGLIBDIR) $(SCMFILES) 
	$(INSTALL) -m 555 -T $(GAUCHE_PKGARCHDIR) $(ARCHFILES)
	$(INSTALL) -m 444 -T $(GAUCHE_PKGLIBDIR)/.packages $(PACKAGE).gpd

uninstall :
	$(INSTALL) -U $(GAUCHE_PKGINCDIR) $(HEADERS)
	$(INSTALL) -U $(GAUCHE_PKGLIBDIR) $(SCMFILES) 
	$(INSTALL) -U $(GAUCHE_PKGARCHDIR) $(ARCHFILES)
	$(INSTALL) -U $(GAUCHE_PKGLIBDIR)/.packages $(PACKAGE).gpd

clean :
	$(GAUCHE_PACKAGE) compile --clean magic $(magic_SRCS)
	rm -rf core $(TARGET) $(GENERATED) *~ test.log so_locations

distclean : clean
	rm -rf $(CONFIG_GENERATED)

maintainer-clean : clean
	rm -rf $(CONFIG_GENERATED) configure VERSION
