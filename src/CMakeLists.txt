set(HELLO-PLUGIN_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${HELLO-PLUGIN_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${HELLO-PLUGIN_FLAGS} -std=c++11")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0>=3.12)
pkg_check_modules(libxfce4panel REQUIRED libxfce4panel-2.0>=4.11)
pkg_check_modules(libxfce4ui REQUIRED libxfce4ui-2>=4.11)
pkg_check_modules(libxfce4util REQUIRED libxfce4util-1.0>=4.11)

include_directories(
	${GTK3_INCLUDE_DIRS}
	${libxfce4panel_INCLUDE_DIRS}
	${libxfce4ui_INCLUDE_DIRS}
	${libxfce4util_INCLUDE_DIRS})

link_directories(
	${GTK3_LIBRARY_DIRS}
	${libxfce4panel_LIBRARY_DIRS}
	${libxfce4ui_LIBRARY_DIRS}
	${libxfce4util_LIBRARY_DIRS})

add_definitions(
  -DGETTEXT_PACKAGE="xfce4-hello-plugin"
  -DPACKAGE_LOCALE_DIR="${CMAKE_INSTALL_FULL_LOCALEDIR}")

add_library(hello-plugin MODULE
	hello-plugin.cpp
        register-plugin.c)
