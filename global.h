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

#define __GLOBAL_H__

#ifndef __GTK_H__
#include <gtk/gtk.h>
#endif

/* area compartida */
void *shared_area;

/* ejecución del proceso hijo de DarkIce pid */
int pid;

/* descriptor de archivo usado por la pipeta de salida de Darkice */
int darkice_fd;

/* home de usuario */
char home[64];
char ml_streaming_cfg[64];
char darkice_cfg[64];
char ml_streaming_temp[64];
char show_detail;

/* Ventana de Widgets principales */
GtkWidget *window;
GtkWidget *button_start;
GtkWidget *button_stop;
GtkWidget *button_detail;
GtkWidget *label_status;
GtkWidget *table;

/* Caja de dialogo Acerca de... */
GtkWidget *dialog_about;

/* Caja de dialogo DarkIce no encontrado */
GtkWidget *dialog_darkdep;
GtkWidget *label_darkdep;
GtkWidget *button_darkdep;

/* Caja de dialogo "Matar darkice?" */
GtkWidget *dialog_darkkill;
GtkWidget *label_darkkill;
GtkWidget *button_yes_darkkill;
GtkWidget *button_no_darkkill;
GtkWidget *button_cancel_darkkill;

/* menu de opciones */
GtkWidget *menu_bar;
GtkWidget *menu_file;
GtkWidget *menu_item_file;
GtkWidget *menu_item_open;
GtkWidget *menu_item_save; 
GtkWidget *menu_item_quit_nd;
GtkWidget *menu_item_quit;
GtkWidget *menu_help;
GtkWidget *menu_item_help;
GtkWidget *menu_item_about;
GtkWidget *vbox;

/* abrir y grabar selectores de archivos */
GtkWidget *file_open;
GtkWidget *file_save;
GtkWidget *file_localdump;

/* opciones de áreas de notas */
GtkWidget *notebook;
GtkWidget *label_notebook_server;
GtkWidget *table_server;
GtkWidget *label_notebook_audio;
GtkWidget *table_audio;
GtkWidget *label_notebook_description;
GtkWidget *table_description;

/* Opciones de configuración de ml_streaming - botones + entradas */

GtkWidget *button_localdump;
GtkWidget *entry_localdump;
GtkWidget *checkbutton_adddate;
GtkWidget *label_remotedump;
GtkWidget *entry_remotedump;

/* Opciones de configuración de ml_streaming - etiquetas + entradas */
GtkWidget *label_server;
GtkWidget *entry_server;
GtkWidget *label_port;
GtkWidget *entry_port;
GtkWidget *label_mountpoint;
GtkWidget *entry_mountpoint;
GtkWidget *label_pass;
GtkWidget *entry_pass;
GtkWidget *label_radioname;
GtkWidget *entry_radioname;
GtkWidget *label_description;
GtkWidget *entry_description;
GtkWidget *label_url;
GtkWidget *entry_url;
GtkWidget *label_genre;
GtkWidget *entry_genre;

/* Opciones de configuración de ml_streaming - etiquetas + combo box */
GtkWidget *label_icecast;
GtkWidget *combo_icecast;
GtkWidget *label_format;
GtkWidget *combo_format;
GtkWidget *label_bitrate;
GtkWidget *combo_bitrate;
GtkWidget *label_bitratemode;
GtkWidget *combo_bitratemode;
GtkWidget *label_samplerate;
GtkWidget *combo_samplerate;
GtkWidget *label_quality;
GtkWidget *combo_quality;
GtkWidget *label_bitspersample;
GtkWidget *combo_bitspersample;
GtkWidget *label_channel;
GtkWidget *combo_channel;
GtkWidget *label_buffersize;
GtkWidget *combo_buffersize;
GtkWidget *label_device;
GtkWidget *combo_device;
GtkWidget *label_public;
GtkWidget *combo_public;
GtkWidget *label_verbosity;
GtkWidget *combo_verbosity;

/* opciones del text view  */
GtkWidget *text;
GtkTextBuffer *buffer;
GtkTextTagTable *tag_table;
GtkTextTag *tag;

/* scroleo del text view */
GtkWidget *scroll_text;

/* ToolTips del GTK */
GtkTooltip *tooltip;
