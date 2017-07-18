//
// Created by yannick lamprecht on 10.07.17.
//

#include "../TestCase.h"
#include "../../PluginLoader.h"

#ifndef QTPLUGINTEST_ENABLEDISABLETEST_H
#define QTPLUGINTEST_ENABLEDISABLETEST_H

#endif //QTPLUGINTEST_ENABLEDISABLETEST_H


class EnableAndDisableBenchmark : public TestCase{


public:

    EnableAndDisableBenchmark(PluginLoader& pluginLoader) : TestCase(pluginLoader) {

    }

    void setUp() override {
        loader.loadPlugins();
    }

    void tearDown() override {
        loader.unloadPlugins();
    }

protected:

    void runTest(unsigned long cycle) override {

        startTimer();

        loader.enablePlugins();

        loader.disablePlugins();

        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }
};