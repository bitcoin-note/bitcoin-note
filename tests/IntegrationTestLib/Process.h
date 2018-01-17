// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include <vector>

namespace Tests {

  class Process {
  public:

    void startChild(const std::string& executablePath, const std::vector<std::string>& args = {});
    void wait();

  private:

    size_t m_pid = 0;

  };
}
