#!/bin/sh
# Ejecute esta opción para configurar la construcción del sistema de: configure, makefiles, etc.
# (basado en la versión especificada del cvs)
# Jaime Ernesto Mora - Colectivo mediosLibres Venezuela
# Adaptación basada en Darksnow para IceCast

package="darkice-gui"

srcdir=`dirname $0`
test -z "$srcdir" && srcdir=.

cd "$srcdir"
DIE=0

(autoheader --version) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "Se necesita tener autoconf instalado para compilar $package."
    echo "Descargue el paquete apropiado para su distribución,"
    echo "u obtenga el código fuente en ftp://ftp.gnu.org/pub/gnu/"
    DIE=1
}

(autoconf --version) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "Se necesita tener autoconf instalado para compilar $package."
    echo "Descargue el paquete apropiado para su distribución,"
    echo "u obtenga el código fuente en ftp://ftp.gnu.org/pub/gnu/"
    DIE=1
}

(automake --version) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "Necesita tener automake instalado para compilar $package."
    echo "Descargue el paquete adecuado para su Distribución,"
    echo "u obtenga el código fuente de los sitios GNU"
    echo "listados en http://www.gnu.org/order/ftp.html"
    DIE=1
}

(libtool --help) < /dev/null > /dev/null 2>&1 || {
    echo
    echo "Necesita tener libtool instalado para compilar $package."
    echo "Descargue el paquete adecuado para su Distribución,"
    echo "u obtenga el código fuente de los sitios GNU"
    echo "listados en http://www.gnu.org/order/ftp.html"
    DIE=1
}

if test "$DIE" -eq 1; then
    exit 1
fi

if test -z "$*"; then
    echo "Voy a correr ./configure sin argumentos - si lo desea "
    echo "por favor especificarlos en la $0 línea de comandos."
fi

echo "Generación de archivos de configuración por $package, por favor espere ...."

echo "  aclocal $ACLOCAL_FLAGS"
aclocal $ACLOCAL_FLAGS
echo "  autoheader"
autoheader
echo "  libtoolize --automake"
libtoolize --automake
echo "  automake --add-missing $AUTOMAKE_FLAGS"
automake --add-missing $AUTOMAKE_FLAGS 
echo "  autoconf"
autoconf

$srcdir/configure "$@" && echo
