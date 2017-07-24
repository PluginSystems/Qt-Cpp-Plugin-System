//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef QTPLUGINTEST_CONTEXTSWITCHBENCHMARK_H
#define QTPLUGINTEST_CONTEXTSWITCHBENCHMARK_H


#include <iostream>
#include "../TestCase.h"
#include "../../PluginLoader.h"
#include "../../StringFace.h"

class ContextSwitchBenchmark : public TestCase {
public:
    explicit ContextSwitchBenchmark(PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

    void setUp() override {
        loader.loadPlugins();
        loader.enablePlugins();
    }

    void tearDown() override {
        loader.disablePlugins();
        loader.unloadPlugins();
    }

protected:

    void runTest(unsigned long cycle) override {

        startTimer();

        IPlugin& plugin = loader.getPlugin("FirstPlugin");

        if(StringFace* face = dynamic_cast<StringFace *>(&plugin)){
            face->printMessage(getName());
        }



        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

    std::string getName() override {
        return "ContextSwitchReturnTypeBenchmark";
    }

};








#endif //QTPLUGINTEST_CONTEXTSWITCHBENCHMARK_H

