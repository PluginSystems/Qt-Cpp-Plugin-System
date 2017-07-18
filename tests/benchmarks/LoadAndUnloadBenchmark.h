//
// Created by yannick lamprecht on 10.07.17.
//

#ifndef QTPLUGINTEST_LOADANDUNLOADBENCHMARK_H
#define QTPLUGINTEST_LOADANDUNLOADBENCHMARK_H


#include "../TestCase.h"

class LoadAndUnloadBenchmark : public TestCase {

protected:

public:
    LoadAndUnloadBenchmark(PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

protected:
    void runTest(unsigned long cycle) override {
        startTimer();
        loader.loadPlugins();


        loader.unloadPlugins();

        stopTimer();
        defineBenchmarkPoint(cycle,getName()+"_"+std::to_string(cycle+1));
        resetTimer();
    }

    std::string getName() override {
        return "LoadAndUnloadBenchmark";
    }
};


#endif //QTPLUGINTEST_LOADANDUNLOADBENCHMARK_H
