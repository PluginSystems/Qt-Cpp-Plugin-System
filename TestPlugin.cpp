//
// Created by yannick lamprecht on 09.05.17.
//

#include "TestPlugin.h"

void TestPlugin::onEnable() const {
    std::cout << "Shitty first plugin in QT is enabled" << std::endl;
}


void TestPlugin::onDisable() const {
    std::cout << "Shitty first plugin in QT is disabled" << std::endl;

}


std::string TestPlugin::getName() const {
    return "ShittyPlugin";
}