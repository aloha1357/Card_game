#pragma once
#include <string>
class ICard {
public:
  virtual std::string getSuit() const = 0;
  virtual std::string getRank() const = 0;
  virtual ~ICard() {}
};