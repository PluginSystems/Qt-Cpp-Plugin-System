//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef QTPLUGINTEST_CONTEXTSWITCHRETURNTYPE_H
#define QTPLUGINTEST_CONTEXTSWITCHRETURNTYPE_H


#include "../TestCase.h"
#include "../../PluginLoader.h"
#include "../../FirstPlugin.h"

class ContextSwitchReturnTypeBenchmark : public TestCase{
public:
    explicit ContextSwitchReturnTypeBenchmark(PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

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
            std::cout << face->modifyMessage(getName()) << std::endl;
        }



        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

    std::string getName() override {
        return "ContextSwitchReturnTypeBenchmark";
    }

};





#endif //QTPLUGINTEST_CONTEXTSWITCHRETURNTYPE_H
