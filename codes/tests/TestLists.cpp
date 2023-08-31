#include <catch2/catch_test_macros.hpp>
#include <cstdint>

#include "arrayList.hpp"

uint32_t factorial(uint32_t number) {
  return number <= 1 ? number : factorial(number - 1) * number;
}

int getArraySize(ArrayList &arrayList) { return arrayList.getLength(); }

TEST_CASE("ArrayList is created", "[arrayList]") {
  ArrayList arrayList(5);
  REQUIRE(getArraySize(arrayList) == 0);

  arrayList.insert(1, 5);
  REQUIRE(arrayList.get(1) == 5);

  arrayList.insert(2, 6);
  arrayList.insert(3, 7);

  REQUIRE(arrayList.remove(3) == 7);

  arrayList.set(2, 10);
  REQUIRE(arrayList.get(2) == 10);

  REQUIRE(arrayList.search(10) == 2);
}
