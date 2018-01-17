// Copyright (c) 2018, The Bitcoin Note Developers.
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <CryptoNote.h>
#include <functional>

namespace CryptoNote {

enum class TransactionMessageType {
  AddTransactionType,
  DeleteTransactionType
};

// immutable messages
struct AddTransaction {
  Crypto::Hash hash;
};

struct DeleteTransaction {
  Crypto::Hash hash;
};

class TransactionPoolMessage {
public:
  TransactionPoolMessage(const AddTransaction& at);
  TransactionPoolMessage(const DeleteTransaction& at);

  // pattern matchin API
  void match(std::function<void(const AddTransaction&)>&&, std::function<void(const DeleteTransaction&)>&&);

  // API with explicit type handling
  TransactionMessageType getType() const;
  AddTransaction  getAddTransaction() const;
  DeleteTransaction getDeleteTransaction() const;

private:
  const TransactionMessageType type;
  union {
    const AddTransaction addTransaction;
    const DeleteTransaction deleteTransaction;
  };
};

TransactionPoolMessage makeAddTransaction(const Crypto::Hash& hash);
TransactionPoolMessage makeDelTransaction(const Crypto::Hash& hash);
}
