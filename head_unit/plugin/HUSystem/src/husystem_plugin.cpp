#include "husystem_plugin.h"

#include "husystem.h"
#include <QtQml>

void HUSystemPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<HUSystem>(uri, 1, 0, "HUSystem");
}