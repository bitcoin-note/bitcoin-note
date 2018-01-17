// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <vector>

namespace CryptoNote {

class WriteBatch;
class ReadBatch;

class IKeyValueStorage {
public:
  virtual ~IKeyValueStorage() {
  }

  virtual bool insert(const WriteBatch& batch, bool sync = false) = 0;
  virtual void read(const ReadBatch& batch) const = 0;
};
}
