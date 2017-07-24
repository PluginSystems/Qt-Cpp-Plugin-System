//
// Created by yannick lamprecht on 09.05.17.
//

#include "FirstPlugin.h"

void FirstPlugin::onEnable() const {
    std::cout << getName() <<" first plugin in QT is enabled" << std::endl;
}


void FirstPlugin::onDisable() const {
    std::cout << getName()<<" first plugin in QT is disabled" << std::endl;

}


std::string FirstPlugin::getName() const {
    return "FirstPlugin";
}

std::string FirstPlugin::modifyMessage(std::string message) {
    return getName() + " returning: "+ message;
}

void FirstPlugin::printMessage(std::string message) {
    std::cout << getName() << " saying: " << message << std::endl;
}