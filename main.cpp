#include <iostream>
#include "PluginLoader.h"


int main(int argc, char **argv) {

    PluginLoader loader("plugin");

    loader.loadPlugins();
    loader.enablePlugins();

    loader.disablePlugins();
    loader.unloadPlugins();


    return 0 ;
}