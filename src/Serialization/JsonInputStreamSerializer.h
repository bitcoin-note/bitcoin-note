// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <iosfwd>
#include <string>
#include <vector>
#include "../Common/JsonValue.h"
#include "JsonInputValueSerializer.h"

namespace CryptoNote {

//deserialization
class JsonInputStreamSerializer : public JsonInputValueSerializer {
public:
  JsonInputStreamSerializer(std::istream& stream);
  virtual ~JsonInputStreamSerializer();
};

}
