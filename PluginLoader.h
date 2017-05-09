//
// Created by yannick lamprecht on 08.05.17.
//

#ifndef QTPLUGINTEST_PLUGINLOADER_H
#define QTPLUGINTEST_PLUGINLOADER_H


#include <unordered_map>
#include <string>
#include <QString>
#include <QPluginLoader>
#include "IPlugin.h"

class PluginLoader {

struct PluginHandle{

    QPluginLoader* pluginLoader;
    IPlugin* plugin;

    void destroy(){
        delete(pluginLoader);
        delete(plugin);
    }

};

private:
    std::unordered_map<std::string, PluginHandle> pluginHandles;

    std::string pluginFolder;

    bool hasLoaded = false;


public:

    PluginLoader(std::string &pluginFolder);

    ~PluginLoader();

    void loadPlugins();

    void unloadPlugins();

    void enablePlugins();

    void disablePlugins();

    IPlugin& getPlugin(std::string pluginName);


};


#endif //QTPLUGINTEST_PLUGINLOADER_H
