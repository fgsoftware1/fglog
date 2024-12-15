#include "Logger.hpp"

int main() {
	Logger logger;

	logger.Init();

	logger.Info(LogChannel::Engine, "Hello World!");
	logger.Warn(LogChannel::Engine, "Hello World!");
	logger.Error(LogChannel::Engine, "Hello World!");
	logger.Critical(LogChannel::Engine, "Hello World!");
	logger.Debug(LogChannel::Engine, "Hello World!");
	logger.Trace(LogChannel::Engine, "Hello World!");

    return 0;
}