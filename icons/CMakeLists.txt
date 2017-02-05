set(INSTALL_ICONDIR ${CMAKE_INSTALL_DATADIR}/icons/hicolor)

install(FILES hello-plugin.png
        DESTINATION ${INSTALL_ICONDIR}/256x256/apps
        RENAME xfce4-hello-plugin.png)
