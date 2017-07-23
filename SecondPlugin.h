//
// Created by yannick lamprecht on 23.07.17.
//

#ifndef QTPLUGINTEST_SECONDPLUGIN_H
#define QTPLUGINTEST_SECONDPLUGIN_H


#include <QObject>
#include "IPlugin.h"

class SecondPlugin :public QObject, public IPlugin {

Q_OBJECT
Q_INTERFACES(IPlugin)
Q_PLUGIN_METADATA(IID "de.ysl3000.cpp.qt.SecondPlugin")

public:
void onEnable() const;

void onDisable() const;

std::string getName() const;
};


#endif //QTPLUGINTEST_SECONDPLUGIN_H
