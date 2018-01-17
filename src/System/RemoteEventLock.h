// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

namespace System {

class Dispatcher;
class Event;

class RemoteEventLock {
public:
  RemoteEventLock(Dispatcher& dispatcher, Event& event);
  ~RemoteEventLock();

private:
  Dispatcher& dispatcher;
  Event& event;
};

}
