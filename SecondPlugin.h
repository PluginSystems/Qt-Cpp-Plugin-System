//
// Created by yannick lamprecht on 23.07.17.
//

#ifndef QTPLUGINTEST_SECONDPLUGIN_H
#define QTPLUGINTEST_SECONDPLUGIN_H


#include <QObject>
#include "IPlugin.h"
#include "StringFace.h"

class SecondPlugin :public QObject, public IPlugin, public StringFace {

Q_OBJECT
Q_INTERFACES(IPlugin)
Q_PLUGIN_METADATA(IID "de.ysl3000.cpp.qt.SecondPlugin")

public:
void onEnable() const override;

void onDisable() const override;

std::string getName() const override;

    void printMessage(std::string message) override;
    std::string modifyMessage(std::string message) override;
};


#endif //QTPLUGINTEST_SECONDPLUGIN_H
