// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "StdInputStream.h"

namespace Common {

StdInputStream::StdInputStream(std::istream& in) : in(in) {
}

size_t StdInputStream::readSome(void* data, size_t size) {
  in.read(static_cast<char*>(data), size);
  return in.gcount();
}

}
