#include <iostream>
#include <QApplication>
#include "PluginLoader.h"


int main(int argc, char **argv) {
    //QApplication app(argc,argv);


    std::string path("plugin");

    PluginLoader loader(path);

    loader.loadPlugins();
    loader.enablePlugins();

    loader.disablePlugins();
    loader.unloadPlugins();


    //app.aboutQt();

    return 0 ;//app.exec();
}