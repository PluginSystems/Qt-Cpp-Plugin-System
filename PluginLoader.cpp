//
// Created by yannick lamprecht on 08.05.17.
//

#include <QPluginLoader>
#include <QDir>
#include <iostream>
#include "PluginLoader.h"


PluginLoader::PluginLoader(std::string &pluginFolder) {
    this->pluginFolder = pluginFolder;

    if(!QDir(QString::fromStdString(pluginFolder)).exists()){
        std::cout << "Creating folder: " << pluginFolder << std::endl;
        QDir().mkdir(QString::fromStdString(pluginFolder));
    }

}

PluginLoader::~PluginLoader() {

    if (hasLoaded) {
        unloadPlugins();
    }

}

void PluginLoader::loadPlugins() {


    QDir dir = QDir::root();

    dir.cd(QString::fromStdString(pluginFolder));


    QStringList files = dir.entryList();


    for (QString file : files) {

        QPluginLoader* loader = new QPluginLoader(file);

        QObject *qpl = loader->instance();

        if (qpl) {

            std::cout << "file loaded" << std::endl;

            IPlugin* iPlugin = qobject_cast<IPlugin *>(qpl);

            if(iPlugin){


                PluginHandle handle;

                handle.pluginLoader = loader;
                handle.plugin = iPlugin;

                pluginHandles[iPlugin->getName()] = handle;
            }
            delete(iPlugin);

        } else {
            delete (qpl);
        }
    }

    hasLoaded = true;

}


IPlugin& PluginLoader::getPlugin(std::string pluginName) {
    return *pluginHandles[pluginName].plugin;
}


void PluginLoader::unloadPlugins() {

    for (std::unordered_map<std::string,PluginHandle>::iterator it=pluginHandles.begin(); it!=pluginHandles.end();){
        it->second.pluginLoader->unload();
        it->second.destroy();
        pluginHandles.erase(it++);
    }


    pluginHandles.clear();
    hasLoaded = false;
}

void PluginLoader::disablePlugins() {

    for (auto &pluginEntry: pluginHandles) {
        pluginEntry.second.plugin->onDisable();
    }

}

void PluginLoader::enablePlugins() {
    for (auto &pluginEntry: pluginHandles) {
        pluginEntry.second.plugin->onEnable();
    }
}
