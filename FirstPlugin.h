//
// Created by yannick lamprecht on 09.05.17.
//

#ifndef QTPLUGINTEST_TESTPLUGIN_H
#define QTPLUGINTEST_TESTPLUGIN_H


#include <iostream>
#include <QtPlugin>
#include "IPlugin.h"
#include "StringFace.h"

class FirstPlugin : public QObject, public IPlugin, public StringFace {

Q_OBJECT
    Q_INTERFACES(IPlugin)
    Q_PLUGIN_METADATA(IID "de.ysl3000.cpp.qt.FirstPlugin")

public:
    void onEnable() const override;

    void onDisable() const override;

    std::string getName() const override;


    void test() override ;

};


#endif //QTPLUGINTEST_TESTPLUGIN_H
