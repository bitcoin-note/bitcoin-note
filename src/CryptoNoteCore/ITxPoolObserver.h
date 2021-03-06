// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

namespace CryptoNote {
class ITxPoolObserver {
public:
  virtual ~ITxPoolObserver() {
  }

  virtual void txDeletedFromPool() = 0;
};
}
