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


#define __INTERFACE_H__

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

/* Devolución de llamada para click en button_start */
void dark_start (GtkWidget *widget, gpointer data);

/* Devolución de llamada para click en button_stop */
void dark_stop (GtkWidget *widget, gpointer data);

/* Devolución de llamada para click en button_load */
void dark_load (GtkWidget *widget, gpointer data);

/* Devolución de llamada para el botón Aceptar del selector de archivos "Abrir archivo", mostrada por dark_open */
void dark_put_in_box (GtkWidget *widget, gint response_id, gpointer data);

/* Devolución de llamada para el botón Aceptar del selector de archivos "Guardar archivo", mostrada por dark_save */
void dark_write_config ( GtkWidget *widget, gint response_id, gpointer data );

/* Devolución de llamada para la selección de archivos vertedero local del botón 'ok' */
void dark_localdump (GtkWidget *widget, gint response_id,  gpointer data);

/* Limpia el buffer dentro del cuadro de vista */
void clean_text_view_memory();

/* La función que actualiza el estado de streaming */
gboolean status_loop (gboolean foo);

/* La función que actualiza la ventana de salida DarkIce, cuando la opción == 1, significa que      */
/* la bandera "streaming_started" será ignorado, si la opción == 0, el "streaming_started"          */
/* bandera no será ignorada y la ventana de depuración no se actualizará.                           */
gboolean text_box_loop (int option);

/* Devolución de llamada que llamar a gtk_main_quit() */
gboolean delete_event (GtkWidget *widget, GdkEvent *event, gpointer data );

/* Devolución de llamada que llamar a gtk_main_quit() sin matar DarkIce */
gboolean delete_event_nd (GtkWidget *widget, GdkEvent *event, gpointer data );

/* Devolución de llamada que muestra un cuadro de diálogo preguntando si mata o no a DarkIce antes de salir */
gboolean main_quit (GtkWidget *widget, GdkEvent  *event, gpointer data);

/* funcioón darkice no encontrada */
void darkice_not_found();

/* función de devolución de llamada que se llama cuando se hace clic en el botón Detalle */
void dark_detail (GtkWidget *widget, gpointer data);
