//
// Created by yannick lamprecht on 08.05.17.
//

#ifndef QTPLUGINTEST_PLUGINLOADER_H
#define QTPLUGINTEST_PLUGINLOADER_H


#include <unordered_map>
#include <string>
#include <QString>
#include <QDir>
#include <QPluginLoader>
#include "IPlugin.h"

class PluginLoader {

struct PluginHandle{

    QLibrary* pluginLoader;
    IPlugin* plugin;

    void destroy(){
        delete(plugin);
        pluginLoader->unload();
        //delete(pluginLoader);
    }

};

private:
    std::unordered_map<std::string, PluginHandle> pluginHandles;

    QDir pluginFolder;

    bool hasLoaded = false;


public:

    PluginLoader(const std::string &pluginFolder);

    ~PluginLoader();

    void loadPlugins();

    void unloadPlugins();

    void enablePlugins();

    void disablePlugins();

    IPlugin& getPlugin(std::string pluginName);
};


#endif //QTPLUGINTEST_PLUGINLOADER_H
