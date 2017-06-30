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

        QPluginLoader *loader = new QPluginLoader(file);

        QObject *qpl = loader->instance();

        if (qpl) {

            std::cout << "file " << file.toStdString() << " loaded " << std::endl;

            IPlugin *iPlugin = qobject_cast<IPlugin *>(qpl);

            if (iPlugin) {


                PluginHandle handle;

                handle.pluginLoader = loader;
                handle.plugin = iPlugin;

                pluginHandles[iPlugin->getName()] = handle;
            } else {
                delete (iPlugin);
                loader->unload();
                delete (loader);

                std::cout << "Plugin not a IPlugin" << std::endl;
            }

        } else {

            std::cout << " not a Plugin file " << file.toStdString() << std::endl;
            delete (qpl);
            loader->unload();
            delete (loader);
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
