#ifndef LOGGERFACTORY_HPP
# define LOGGERFACTORY_HPP

#include <memory>
#include <string>

#include "ILogger.hpp"

std::unique_ptr<ILogger> CreateLogger(const std::string &type,
		const std::string &filePath = "", int minLevel = Level::INFO);


#endif
