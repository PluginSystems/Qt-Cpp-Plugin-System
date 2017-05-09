//
// Created by yannick lamprecht on 09.05.17.
//

#ifndef QTPLUGINTEST_TESTPLUGIN_H
#define QTPLUGINTEST_TESTPLUGIN_H


#include <iostream>
#include <QtPlugin>
#include "../IPlugin.h"

class TestPlugin : public QObject, public IPlugin {

Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_PLUGIN_METADATA(IID
                              "de.ysl3000.TestPlugin")

public:
    void onEnable() const;

    void onDisable() const;

    std::string getName() const;

};


#endif //QTPLUGINTEST_TESTPLUGIN_H
