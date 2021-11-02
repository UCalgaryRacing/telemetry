# Makefile for tinydtls
#
# Copyright (c) 2011, 2012, 2013, 2014, 2015 Olaf Bergmann (TZI) and others.
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

abs_builddir = /home/parallels/Desktop/git/mangOH/build/red_wp85/component/2ed5bc898d41050998169ccc96d9c6fd/sha2
top_builddir = ..
top_srcdir:= ..

SOURCES:= sha2.c
HEADERS:=sha2.h
OBJECTS:= $(patsubst %.c, %.o, $(SOURCES))
CPPFLAGS= -DDTLSv12 -DWITH_SHA256 -I$(top_srcdir)
CFLAGS=-Wall -std=c99 -pedantic -w -std=gnu99 -DSIERRA -DWITH_SHA256 -I/home/parallels/legato_framework/legato/3rdParty/Lwm2mCore/include/platform-specific/linux -fPIC --sysroot=/opt/swi/y17-ext-SWI9X15Y_07.14.01.00/sysroots/armv7a-neon-poky-linux-gnueabi -O2 -DLEGATO_DATA_CONNECTION_DELAY -DPCM_IF=AUX -DI2S_IF=PRI -DUSB_IF=AFE_PCM -DCODEC_IF=PRI -DMM_1_ALSA_MIXER_CTRL=MultiMedia1 -DMM_1_ALSA_PCM_DEVICE_ID=0 -DMM_2_ALSA_MIXER_CTRL=MultiMedia2 -DMM_2_ALSA_PCM_DEVICE_ID=1 -DADC_BEGIN_NUM=0 -DADC_COUNT=4 -DPDP_MAX_PROFILE=16 -DPDP_MAX_MULTIPDP=8 -I build/red_wp85 -I/home/parallels/legato_framework/legato/interfaces -I/home/parallels/legato_framework/legato/framework/include -I. -I/home/parallels/legato_framework/legato/interfaces/modemServices -I/home/parallels/legato_framework/legato/interfaces/positioning -I/home/parallels/legato_framework/legato/interfaces/atServices -I/home/parallels/Desktop/git/mangOH/interfaces -I/home/parallels/Desktop/git/mangOH/apps/LedService -I/home/parallels/Desktop/git/mangOH/apps/DataHub -I/home/parallels/Desktop/git/mangOH/apps/BatteryService -I/home/parallels/Desktop/git/mangOH/apps/RedSensorToCloud/interfaces
LDLIBS=
FILES:=Makefile.in $(SOURCES) $(HEADERS) README sha2prog.c sha2speed.c sha2test.pl 
DISTDIR=$(top_builddir)/tinydtls-0.8.6

.PHONY: all dirs clean install dist distclean .gitignore doc

.SUFFIXES:
.SUFFIXES:      .c .o

all:

check:	
	echo DISTDIR: $(DISTDIR)
	echo top_builddir: $(top_builddir)

clean:
	@rm -f $(PROGRAMS) main.o $(LIB) $(OBJECTS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean ; \
	done

distclean:	clean
	@rm -rf $(DISTDIR)
	@rm -f *~ $(DISTDIR).tar.gz

dist:	$(FILES)
	test -d $(DISTDIR)/sha2 || mkdir $(DISTDIR)/sha2
	cp -p $(FILES) $(DISTDIR)/sha2
	test -d $(DISTDIR)/sha2/testvectors || mkdir $(DISTDIR)/sha2/testvectors
	cp -pr testvectors $(DISTDIR)/sha2/testvectors

install:	$(HEADERS)
	test -d $(includedir)/sha2 || mkdir -p $(includedir)/sha2
	$(install) $(HEADERS) $(includedir)/sha2

.gitignore:
	echo "core\n*~\n*.[oa]\n*.gz\n*.cap\n$(PROGRAM)\n$(DISTDIR)\n.gitignore" >$@
