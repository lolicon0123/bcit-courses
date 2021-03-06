/*
 * gui_funcs.c
 * Copyright (C) 2009 Doug Penner <darwinsurvivor@gmail.com>
 * Copyright (C) 2009 Brendan Neva <bneva1@my.bcit.ca>
 * Copyright (C) 2009 Steffen L. Norgren <ironix@trollop.org>
 * Copyright (C) 2009 Eddie Zhang <edisonhammer@gmail.com>
 * 
 * gui_funcs.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gui_funcs.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "spry.h"
#include "gui_funcs.h"

/**
 * SECTION:gui_funcs
 * @short_description: the GUI functions module
 * @stability: Stable
 * @include: gui_funcs.h
 *
 * This module handles all the GUI settings that can be changed via the
 * command line or via GUI interaction.
 */

/**
 * gui_apply_mode:
 * @conf: Spry configuration struct
 * 
 * Applies settings defined in the configuration struct
 **/
void
gui_apply_mode(SPRY_CONF* conf) {
    /* fullscreen */
    if (VISIBLE(conf, FULLSCREEN)) {
        gtk_window_fullscreen((GtkWindow*) conf->gtk_objects->main_window);
    } else {
        gtk_window_unfullscreen((GtkWindow*) conf->gtk_objects->main_window);
    }
    
    /* context menu */
    if (ENABLED(conf, CONTEXT_MENU_ENABLED)
        && VISIBLE(conf, CONTEXT)) {
        gtk_widget_show(conf->gtk_objects->context_menu);
        gtk_widget_hide(conf->gtk_objects->web_view_container);
    } else {
        gtk_widget_show(conf->gtk_objects->web_view_container);
        gtk_widget_hide(conf->gtk_objects->context_menu);
    }
    
    /* toolbar */
    if (ENABLED(conf, TOOLBAR_ENABLED)
        && VISIBLE(conf, TOOLBAR)
        && HIDDEN(conf, CONTEXT)) {
        gtk_widget_show(conf->gtk_objects->toolbar);
    } else {
        gtk_widget_hide(conf->gtk_objects->toolbar);
    }
    
    /* thinbar */
    if (ENABLED(conf, THINBAR_ENABLED)
        && !((ENABLED(conf, TOOLBAR_ENABLED)
                && VISIBLE(conf, TOOLBAR))
            ||  (ENABLED(conf, CONTEXT_MENU_ENABLED)
                && VISIBLE(conf, CONTEXT)))) {
        gtk_widget_show(conf->gtk_objects->thinbar);
    } else {
        gtk_widget_hide(conf->gtk_objects->thinbar);
    }
    
    /* minimize */
    if (VISIBLE(conf, MINIMIZE)) {
        gtk_window_iconify((GtkWindow*) conf->gtk_objects->main_window);
        HIDE(conf, MINIMIZE);
    }
}
