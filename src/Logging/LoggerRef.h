// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "ILogger.h"
#include "LoggerMessage.h"

namespace Logging {

class LoggerRef {
public:
  LoggerRef(ILogger& logger, const std::string& category);
  LoggerMessage operator()(Level level = INFO, const std::string& color = DEFAULT) const;
  ILogger& getLogger() const;

private:
  ILogger* logger;
  std::string category;
};

}