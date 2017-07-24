//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef QTPLUGINTEST_STRINGFACE_H
#define QTPLUGINTEST_STRINGFACE_H


#include <string>

class StringFace {

public:
    virtual void printMessage(std::string message)=0;

    virtual std::string modifyMessage(std::string message)=0;


};


#endif //QTPLUGINTEST_STRINGFACE_H
