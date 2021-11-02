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

abs_builddir = /home/parallels/Desktop/git/mangOH/build/red_wp85/component/2ed5bc898d41050998169ccc96d9c6fd/tests
top_builddir = ..
top_srcdir:= ..

# files and flags
SOURCES:= dtls-server.c ccm-test.c prf-test.c \
  dtls-client.c
  #cbc_aes128-test.c #dsrv-test.c
OBJECTS:= $(patsubst %.c, %.o, $(SOURCES))
PROGRAMS:= $(patsubst %.c, %, $(SOURCES))
HEADERS:=
CFLAGS:=-Wall -w -std=gnu99 -DSIERRA -DWITH_SHA256 -I/home/parallels/legato_framework/legato/3rdParty/Lwm2mCore/include/platform-specific/linux -fPIC --sysroot=/opt/swi/y17-ext-SWI9X15Y_07.14.01.00/sysroots/armv7a-neon-poky-linux-gnueabi -O2 -DLEGATO_DATA_CONNECTION_DELAY -DPCM_IF=AUX -DI2S_IF=PRI -DUSB_IF=AFE_PCM -DCODEC_IF=PRI -DMM_1_ALSA_MIXER_CTRL=MultiMedia1 -DMM_1_ALSA_PCM_DEVICE_ID=0 -DMM_2_ALSA_MIXER_CTRL=MultiMedia2 -DMM_2_ALSA_PCM_DEVICE_ID=1 -DADC_BEGIN_NUM=0 -DADC_COUNT=4 -DPDP_MAX_PROFILE=16 -DPDP_MAX_MULTIPDP=8 -I build/red_wp85 -I/home/parallels/legato_framework/legato/interfaces -I/home/parallels/legato_framework/legato/framework/include -I. -I/home/parallels/legato_framework/legato/interfaces/modemServices -I/home/parallels/legato_framework/legato/interfaces/positioning -I/home/parallels/legato_framework/legato/interfaces/atServices -I/home/parallels/Desktop/git/mangOH/interfaces -I/home/parallels/Desktop/git/mangOH/apps/LedService -I/home/parallels/Desktop/git/mangOH/apps/DataHub -I/home/parallels/Desktop/git/mangOH/apps/BatteryService -I/home/parallels/Desktop/git/mangOH/apps/RedSensorToCloud/interfaces 
CPPFLAGS:=-I$(top_srcdir)  -DDTLSv12 -DWITH_SHA256
LDFLAGS:=-L$(top_builddir) 
LDLIBS:=-ltinydtls 
DISTDIR=$(top_builddir)/tinydtls-0.8.6
FILES:=Makefile.in $(SOURCES) ccm-testdata.c #cbc_aes128-testdata.c

.PHONY: all dirs clean distclean .gitignore doc

.SUFFIXES:
.SUFFIXES:      .c .o

all:	$(PROGRAMS)

check:	
	echo DISTDIR: $(DISTDIR)
	echo top_builddir: $(top_builddir)

clean:
	@rm -f $(PROGRAMS) main.o $(LIB) $(OBJECTS)
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean ; \
	done

doc:	
	$(MAKE) -C doc

distclean:	clean
	@rm -rf $(DISTDIR)
	@rm -f *~ $(DISTDIR).tar.gz

dist:	$(FILES)
	test -d $(DISTDIR)/tests || mkdir $(DISTDIR)/tests
	cp $(FILES) $(DISTDIR)/tests

# this directory contains no installation candidates
install:
	:

.gitignore:
	echo "core\n*~\n*.[oa]\n*.gz\n*.cap\n$(PROGRAM)\n$(DISTDIR)\n.gitignore" >$@
