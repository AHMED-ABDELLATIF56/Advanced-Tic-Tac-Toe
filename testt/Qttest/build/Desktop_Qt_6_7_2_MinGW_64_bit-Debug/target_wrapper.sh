#!/bin/sh
PATH=/C/qtt/6.7.2/mingw_64/bin:$PATH
export PATH
QT_PLUGIN_PATH=/C/qtt/6.7.2/mingw_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
