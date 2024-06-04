#include "music_plugin.h"

#include "music.h"
#include <QtQml>

void MusicPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<Music>(uri, 1, 0, "Music");
}
