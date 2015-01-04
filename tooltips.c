/* ML-Streaming - Interfaz de usuario para darkice
 * Copyright (C) 2004-2005 Rafael Diniz <rafael@riseup.net>
 *
 * This source code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Public License as published 
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 *
 * This source code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * Please refer to the GNU Public License for more details.
 *
 * You should have received a copy of the GNU Public License along with
 * this source code; if not, write to:
 * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

#ifndef __GLOBAL_H__
#include "global.h"
#endif

#ifdef USE_TOOLTIP
#define TOOLTIP 1
#else 
#define TOOLTIP 0
#endif

#include <stdio.h>
#include <stdlib.h>
#include <libintl.h>

void set_all_tooltips(){


  if (TOOLTIP) {
    gtk_widget_set_tooltip_text ( entry_server, gettext("Este campo indica el nombre del servidor\n Ejemplo: radio.medioslibres.org.ve"));
    gtk_widget_set_tooltip_text ( entry_port, gettext("Este campo indica en número de puerto en el servidor al que se conectará\n Ejemplo: 8000"));
    gtk_widget_set_tooltip_text ( entry_mountpoint, gettext("Este campo indica el punto de montaje para el stream.\nEjemplo: radio_x.ogg\n Recuerde colocar el \".ogg\" al final del punto de montaje si usted va a usar ogg/vorbis!"));
    gtk_widget_set_tooltip_text ( entry_pass, gettext("Este campo indica la contraseña para el stream, esta se la da el administrador del servidor."));
    gtk_widget_set_tooltip_text ( entry_remotedump, gettext("Este campo indica el archivo el servidor IceCast debe volcar el contenido de esta corriente en su lado (lado del servidor) \nEjemplo:. nombre_archivo_remoto.mp3"));
    gtk_widget_set_tooltip_text ( entry_localdump, gettext("Campo que indica el archivo donde se volcarán los mismos datos que se envían a la corriente \nejemplo:. local_file_name.mp3 "));
    gtk_widget_set_tooltip_text ( checkbutton_adddate, gettext("Si usted desea insertar automáticamente una cadena de fecha en el nombre Archivo de volcado local, marque esta opción."));
    gtk_widget_set_tooltip_text ( combo_verbosity, gettext("Campo que indica el nivel de detalle de DarkIce. \nUse un valor mayor que 0 si desea más información en 'Detalles Window'."));
    gtk_widget_set_tooltip_text ( combo_device, gettext("Para grabar desde dispositivos OSS DSP (Por ejemplo /dev/dsp), utilice /dev/dsp_ (ejemplo. /dev/dsp), para ALSA, use hw:_,_ (ejemplo hw:0,0), y para crear una \
entrada sin conectar \
puerto en toma, utilice 'jack', o usar 'jack_auto' para hacer automáticamente Jack conectar \
a la primera fuente. (si elige jack debe establecer la tasa de muestreo de la misma samplerate toma!) "));

  }
    
}
