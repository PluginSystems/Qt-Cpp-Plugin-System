//
// Created by yannick lamprecht on 10.07.17.
//

#include "../TestCase.h"
#include "../../PluginLoader.h"

#ifndef QTPLUGINTEST_ENABLEDISABLETEST_H
#define QTPLUGINTEST_ENABLEDISABLETEST_H

#endif //QTPLUGINTEST_ENABLEDISABLETEST_H


class EnableAndDisableBenchmark : public TestCase{

protected:

    void runTest(unsigned long cycle) override {
        PluginLoader loader("plugin");
        loader.loadPlugins();

        startTimer();
        loader.enablePlugins();

        loader.disablePlugins();
        stopTimer();

        defineBenchmarkPoint(cycle,getName());
        resetTimer();

        loader.unloadPlugins();

    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }
};