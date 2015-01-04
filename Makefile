# ML-Streaming - Interfaz de usuario para darkice
#
#  Copyright (C) 2004-2005 Rafael Diniz <rafael@riseup.net>
# 
#  This source code is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Public License as published 
#  by the Free Software Foundation; either version 2 of the License,
#  or (at your option) any later version.
#
#  This source code is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#  Please refer to the GNU Public License for more details.
#
# You should have received a copy of the GNU Public License along with
# this source code; if not, write to:
# Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
#
# Adaptación de Jaime Ernesto Mora (jemora@medioslibres.org.ve)

# ml_streaming Makefile
PREFIX=/usr/local
INTLPREFIX=/usr/local
CC=gcc
VERSION=0.7.1
#CFLAGS+=-Wall -DGTK_DISABLE_DEPRECATED=1
CFLAGS+=-Wall
INSTALL=install
ARCH=`uname -m`

#set debugging symbols:
#CFLAGS+= -g 

#set funny messages
#CFLAGS+= -DFUNNY 

# use tooltips
CFLAGS+= -DUSE_TOOLTIP

all: ml_streaming

ml_streaming: ml_streaming.o interface.o config_files.o tooltips.o man_gzip
        $(CC) ml_streaming.o interface.o config_files.o tooltips.o -o ml_streaming  -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0 -lglib-2.0   -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -DVERSION="\"$(VERSION)\""

ml_streaming.o: ml_streaming.c
        $(CC) $(FUNNY) -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -DINTLPREFIX="\"$(INTLPREFIX)\"" -DVERSION="\"$(VERSION)\"" -c ml_streaming.c -o ml_streaming.o

interface.o: interface.c
	$(CC) $(CFLAGS) $(FUNNY) -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -DINTLPREFIX="\"$(INTLPREFIX)\"" -DVERSION="\"$(VERSION)\"" -c interface.c -o interface.o

config_files.o: config_files.c
	$(CC) $(CFLAGS) $(FUNNY) -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -DINTLPREFIX="\"$(INTLPREFIX)\"" -DVERSION="\"$(VERSION)\"" -c config_files.c -o config_files.o

tooltips.o: tooltips.c
	$(CC) $(CFLAGS) $(FUNNY) -pthread -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12   -DINTLPREFIX="\"$(INTLPREFIX)\"" -DVERSION="\"$(VERSION)\"" -c tooltips.c -o tooltips.o

man_gzip:
        gzip -c man/ml_streaming.1 > man/ml_streaming.1.gz

clean:
        rm -f *.o *~ ml_streaming man/ml_streaming.1.gz
        rm -rf slack ml_streaming.tgz

install: ml_streaming
        $(INSTALL) -D --mode=0755 ml_streaming $(PREFIX)/bin/ml_streaming
        $(INSTALL) -D --mode=0644 documentation/CHANGES $(PREFIX)/share/ml_streaming/changelog
        $(INSTALL) -D --mode=0644 po/pt_BR.mo $(PREFIX)/share/locale/pt_BR/LC_MESSAGES/ml_streaming.mo
        $(INSTALL) -D --mode=0644 icon/ml_streaming_icon.png $(PREFIX)/share/icons/hicolor/32x32/apps/ml_streaming.png
        $(INSTALL) -D --mode=0644 man/ml_streaming.1.gz $(PREFIX)/share/man/man1/ml_streaming.1.gz

make_pkg: ml_streaming
        echo "Recuerda ejecutar esta opción como root!"
	rm -rf slack
        $(INSTALL) -D --mode=0755 ml_streaming slack$(PREFIX)/bin/ml_streaming
        $(INSTALL) -D --mode=0644 icon/ml_streaming_icon.png slack$(PREFIX)/share/icons/ml_streaming.png
        $(INSTALL) -D --mode=0644 po/pt_BR.mo slack$(PREFIX)/share/locale/pt_BR/LC_MESSAGES/ml_streaming.mo
        $(INSTALL) -D --mode=0644 documentation/CHANGES slack$(PREFIX)/doc/ml_streaming/CHANGES
        $(INSTALL) -D --mode=0644 documentation/LICENSE slack$(PREFIX)/doc/ml_streaming/LICENSE
        $(INSTALL) -D --mode=0644 documentation/README.en slack$(PREFIX)/doc/ml_streaming/README.en
        $(INSTALL) -D --mode=0644 documentation/README.pt_BR slack$(PREFIX)/doc/ml_streaming/README.pt_BR
        $(INSTALL) -D --mode=0644 documentation/CHANGES slack$(PREFIX)/doc/ml_streaming/CHANGES
	$(INSTALL) -D --mode=0644 documentation/slack-desc slack/install/slack-desc
        cd slack; makepkg -c y -l n  ../ml_streaming-$(VERSION)-$(ARCH)-1rd.tgz
        echo "Recuerda ejecutar esta opción como root!"

install_pkg: make_pkg
        /sbin/installpkg ml_streaming-*-1rd.tgz

upgrade_pkg: make_pkg
        /sbin/upgradepkg ml_streaming-*-1rd.tgz

dist-clean: clean
        rm aclocal.m4 config.status config.log man/ml_streaming.1.gz Makefile
	rm -r autom4te.cache
