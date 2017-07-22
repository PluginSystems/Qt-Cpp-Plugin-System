//
// Created by yannick lamprecht on 08.05.17.
//

#include <QPluginLoader>
#include <QDir>
#include <iostream>
#include "PluginLoader.h"


PluginLoader::PluginLoader(const std::string &pluginFolder) {
    this->pluginFolder = QDir(QString::fromStdString(pluginFolder));

    if (!this->pluginFolder.exists()) {
        std::cout << "Creating folder: " << pluginFolder << std::endl;
        QDir().mkdir(this->pluginFolder.path());
    }

}

PluginLoader::~PluginLoader() {

    if (hasLoaded) {
        unloadPlugins();
    }

}

void PluginLoader::loadPlugins() {


    QStringList files = pluginFolder.entryList(QStringList() << "*.dylib" << "*.so" << "*.dll");


    for (QString &file : files) {

        QLibrary lib(file);
        typedef IPlugin* (*create)();
        create create1  = (create)lib.resolve("create");

        if(create1){

            PluginHandle handle;

            handle.pluginLoader = &lib;
            handle.plugin = create1();

            pluginHandles[handle.plugin->getName()] = handle;
            handle.plugin->onEnable();
            handle.plugin->onDisable();

            std::cout << "file " << handle.plugin->getName() << " loaded " << std::endl;
        }
    }

    hasLoaded = true;

}

IPlugin &PluginLoader::getPlugin(std::string pluginName) {
    return *pluginHandles[pluginName].plugin;
}


void PluginLoader::unloadPlugins() {

    for (std::unordered_map<std::string, PluginHandle>::iterator it = pluginHandles.begin();
         it != pluginHandles.end();) {
        it->second.destroy(); // the function destroy in struct handles unloading of the plugin
        pluginHandles.erase(it++);
    }
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
