//
// Created by yannick lamprecht on 08.05.17.
//

#ifndef QTPLUGINTEST_IPLUGIN_H
#define QTPLUGINTEST_IPLUGIN_H


#include <string>
#include <QObject>

class IPlugin {


public:



    virtual ~IPlugin() {};

    virtual void onEnable() const =0;

    virtual void onDisable() const =0;

    virtual std::string getName() const  =0;

};
Q_DECLARE_INTERFACE(IPlugin,"de.ysl3000.IPlugin/1.0")

#endif //QTPLUGINTEST_IPLUGIN_H
