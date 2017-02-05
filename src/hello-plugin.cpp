/*
 * Copyright (C) 2017 Marcin Kedzierski <marcin.kedzierski@gmx.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <libxfce4panel/libxfce4panel.h>

class Plugin {
public:
  Plugin(XfcePanelPlugin* plugin) 
      : plugin_(plugin) {
    label_ = gtk_label_new("Hello");
    gtk_widget_show(label_);

    box_ = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    gtk_container_add(GTK_CONTAINER(box_), label_);
    gtk_widget_show(box_);

    gtk_container_add(GTK_CONTAINER(plugin_), box_);
  }

private:
  XfcePanelPlugin* plugin_;

  GtkWidget* box_;
  GtkWidget* label_;
};

extern "C" void hello_construct(XfcePanelPlugin*);
static void hello_free(XfcePanelPlugin*, Plugin*);

extern "C"
{
#include <libxfce4util/libxfce4util.h>
#include <libxfce4ui/libxfce4ui.h>
}

extern "C" void hello_construct(XfcePanelPlugin* plugin)
{
  xfce_textdomain(GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR, "UTF-8");
  new Plugin(plugin);

  g_signal_connect(plugin, "free-data", G_CALLBACK(hello_free), nullptr);
}

static void hello_free(XfcePanelPlugin*, Plugin* plugin)
{
  delete plugin;
}
