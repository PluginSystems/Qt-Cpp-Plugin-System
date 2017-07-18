#include <iostream>
#include <sstream>
#include <fstream>
#include "PluginLoader.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"


int main(int argc, char **argv) {

    std::list<std::shared_ptr<TestCase>> benchmarks;


    PluginLoader loader("plugin");


    benchmarks.push_back(std::make_shared<LoadAndUnloadBenchmark>(LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::make_shared<EnableAndDisableBenchmark>(EnableAndDisableBenchmark(loader)));


    int count = 100;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->runTestFully(count);
        std::cout << "Test run finished" << std::endl;
    }


    std::stringstream  filename;


    filename << "result_"<< count << "_" << std::chrono::system_clock::now().time_since_epoch().count() << ".csv";


    std::fstream resultFile;


    resultFile.open(filename.str());




    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(resultFile);
    }

    resultFile.close();

    return 0;
}