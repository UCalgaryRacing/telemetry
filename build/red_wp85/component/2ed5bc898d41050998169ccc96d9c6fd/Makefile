# Makefile for tinydtls
#
#
# Copyright (c) 2011, 2012, 2013, 2014, 2015, 2016 Olaf Bergmann (TZI) and others.
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v1.0
# and Eclipse Distribution License v. 1.0 which accompanies this distribution.
#
# The Eclipse Public License is available at http://www.eclipse.org/legal/epl-v10.html
# and the Eclipse Distribution License is available at 
# http://www.eclipse.org/org/documents/edl-v10.php.
#
# Contributors:
#    Olaf Bergmann  - initial API and implementation
#

# the library's version
VERSION:=0.8.6

# tools

SHELL = /bin/sh
MKDIR = mkdir
ETAGS = /bin/false

prefix = /home/parallels/legato_framework/legato/build/wp85/3rdParty/tinydtls
exec_prefix = ${prefix}
abs_builddir = /home/parallels/Desktop/git/mangOH/build/red_wp85/component/2ed5bc898d41050998169ccc96d9c6fd
top_builddir = .
libdir = ${exec_prefix}/lib
includedir = ${prefix}/include/tinydtls
package = tinydtls-0.8.6

install := cp

# files and flags
SOURCES:= dtls.c crypto.c ccm.c hmac.c netq.c peer.c dtls_time.c session.c dtls_debug.c
SUB_OBJECTS:=aes/rijndael.o  ecc/ecc.o sha2/sha2.o
OBJECTS:= $(patsubst %.c, %.o, $(SOURCES)) $(SUB_OBJECTS)
HEADERS:=dtls.h hmac.h dtls_debug.h dtls_config.h uthash.h numeric.h crypto.h global.h ccm.h \
 netq.h alert.h utlist.h prng.h peer.h state.h dtls_time.h session.h \
 tinydtls.h
CFLAGS:=-Wall -pedantic -std=c99 -w -std=gnu99 -DSIERRA -DWITH_SHA256 -I/home/parallels/legato_framework/legato/3rdParty/Lwm2mCore/include/platform-specific/linux -fPIC --sysroot=/opt/swi/y17-ext-SWI9X15Y_07.14.01.00/sysroots/armv7a-neon-poky-linux-gnueabi -O2 -DLEGATO_DATA_CONNECTION_DELAY -DPCM_IF=AUX -DI2S_IF=PRI -DUSB_IF=AFE_PCM -DCODEC_IF=PRI -DMM_1_ALSA_MIXER_CTRL=MultiMedia1 -DMM_1_ALSA_PCM_DEVICE_ID=0 -DMM_2_ALSA_MIXER_CTRL=MultiMedia2 -DMM_2_ALSA_PCM_DEVICE_ID=1 -DADC_BEGIN_NUM=0 -DADC_COUNT=4 -DPDP_MAX_PROFILE=16 -DPDP_MAX_MULTIPDP=8 -I build/red_wp85 -I/home/parallels/legato_framework/legato/interfaces -I/home/parallels/legato_framework/legato/framework/include -I. -I/home/parallels/legato_framework/legato/interfaces/modemServices -I/home/parallels/legato_framework/legato/interfaces/positioning -I/home/parallels/legato_framework/legato/interfaces/atServices -I/home/parallels/Desktop/git/mangOH/interfaces -I/home/parallels/Desktop/git/mangOH/apps/LedService -I/home/parallels/Desktop/git/mangOH/apps/DataHub -I/home/parallels/Desktop/git/mangOH/apps/BatteryService -I/home/parallels/Desktop/git/mangOH/apps/RedSensorToCloud/interfaces
CPPFLAGS:= -DDTLSv12 -DWITH_SHA256 -DDTLS_CHECK_CONTENTTYPE
SUBDIRS:=tests doc platform-specific sha2 aes ecc
DISTSUBDIRS:=$(SUBDIRS)
DISTDIR=$(top_builddir)/$(package)
FILES:=Makefile.in configure configure.in dtls_config.h.in tinydtls.h.in \
  Makefile.tinydtls $(SOURCES) $(HEADERS)
LIB:=libtinydtls.a
LDFLAGS:=
ARFLAGS:=cru
doc:=doc

.PHONY: all dirs clean install dist distclean .gitignore doc TAGS

ifneq ("", "1")
.SUFFIXES:
.SUFFIXES:      .c .o

all:	$(LIB) dirs

check:	
	echo DISTDIR: $(DISTDIR)
	echo top_builddir: $(top_builddir)
	$(MAKE) -C tests check

dirs:	$(SUBDIRS)
	for dir in $^; do \
		$(MAKE) -C $$dir ; \
	done

$(SUB_OBJECTS)::
	$(MAKE) -C $(@D) $(@F)

$(LIB):	$(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^ 
	ranlib $@

clean:
	@rm -f $(PROGRAM) main.o $(LIB) $(OBJECTS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean ; \
	done
endif # WITH_CONTIKI

doc:	
	$(MAKE) -C doc

distclean:	clean
	@rm -rf $(DISTDIR)
	@rm -f *~ $(DISTDIR).tar.gz

dist:	$(FILES) $(DISTSUBDIRS)
	test -d $(DISTDIR) || mkdir $(DISTDIR)
	cp $(FILES) $(DISTDIR)
	for dir in $(DISTSUBDIRS); do \
		$(MAKE) -C $$dir dist; \
	done
	tar czf $(package).tar.gz $(DISTDIR)

install:	$(LIB) $(HEADERS) $(SUBDIRS)
	test -d $(libdir) || mkdir -p $(libdir)
	test -d $(includedir) || mkdir -p $(includedir)
	$(install) $(LIB) $(libdir)/
	$(install) $(HEADERS) $(includedir)/
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir install="$(install)" includedir=$(includedir) install; \
	done

TAGS:	
	$(ETAGS) -o $@.new $(SOURCES) 
	$(ETAGS) -a -o $@.new $(HEADERS) 
	mv $@.new $@

# files that should be ignored by git
GITIGNOREDS:= core \*~ \*.[oa] \*.gz \*.cap \*.pcap Makefile \
 autom4te.cache/ config.h config.log config.status configure \
 doc/Doxyfile doc/doxygen.out doc/html/ $(LIB) tests/ccm-test \
 tests/dtls-client tests/dtls-server tests/prf-test $(package) \
 $(DISTDIR)/ TAGS \*.patch .gitignore ecc/testecc ecc/testfield \
 \*.d \*.hex \*.elf \*.map obj_\* tinydtls.h dtls_config.h \
 $(addprefix \*., $(notdir $(wildcard ../../platform/*))) \
 .project

.gitignore:
	echo $(GITIGNOREDS) | sed 's/ /\n/g' > $@

