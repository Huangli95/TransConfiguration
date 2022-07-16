#include <iostream>
#include <g3log/g3log.hpp>
#include <g3log/logworker.hpp>
#include <filesystem>
#define DEFAULT_LOG_DIR "/tmp/tc/log/"

using namespace std;

namespace {
    std::string MyCustomFormatting(const g3::LogMessage& msg) {
        return msg.message();
    }
}

class MySink {
public:
    void ReceiveLogEntry(g3::LogMessageMover message) {
        // std::cout << "receive message" << std::endl;
        // std::string formatted = message.get().toString(&MyCustomFormatting);
        cout << message.get().toString() << endl;
    }
};

std::unique_ptr<g3::LogWorker> worker;
void logInit(const string& prefix, const string& logDir)
{
    worker = g3::LogWorker::createLogWorker();
    auto handle = worker->addDefaultLogger(prefix, logDir);
    auto handle2 = worker->addSink(std::make_unique<MySink>(), &MySink::ReceiveLogEntry);
    g3::initializeLogging(worker.get());
}

void logShutdown()
{
    g3::internal::shutDownLogging();
}

int main(int argc, char* argv[])
{
#ifdef RUNTIME_LOG_DIR
    string path = RUNTIME_LOG_DIR;
#else
    string path = DEFAULT_LOG_DIR;
#endif
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directories(path);
    }

    cout << "11111111111111111111" << endl;
    logInit("tc", path);

    LOGF(INFO, "prefix %s", argv[0]);
    LOGF(INFO, "path %s", path.c_str());
    logShutdown();
    return 0;
}