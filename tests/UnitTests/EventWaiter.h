// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <mutex>
#include <condition_variable>

#pragma once

class EventWaiter {
private:
  std::mutex mtx;
  std::condition_variable cv;
  bool available;

public:
  EventWaiter() : available(false) {}

  void notify();
  void wait();
  bool wait_for(const std::chrono::milliseconds& rel_time);
};
