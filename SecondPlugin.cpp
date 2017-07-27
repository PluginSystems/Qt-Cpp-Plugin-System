//
// Created by yannick lamprecht on 23.07.17.
//

#include <iostream>
#include "SecondPlugin.h"


void SecondPlugin::onEnable() const {
    std::cout << getName() <<" in QT is enabled" << std::endl;
}


void SecondPlugin::onDisable() const {
    std::cout << getName()<<" in QT is disabled" << std::endl;

}


std::string SecondPlugin::getName() const {
    return "SecondPlugin";
}

