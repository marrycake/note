#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <iostream>
#include <string>

#include "linkList.hpp"

TEST_CASE("LinkListTest", "[linkList]") {
  LinkList<std::string> linkList;
  linkList.create();

  REQUIRE(linkList.getCapacity() == 0);

  linkList.insert(1, "aaa");

  REQUIRE(linkList.get(1) == "aaa");

  linkList.insert(2, "bbb");
  REQUIRE(linkList.get(2) == "bbb");

  REQUIRE(linkList.search("bbb") == 2);

  linkList.set(2, "ccc");
  REQUIRE(linkList.search("ccc") == 2);

  linkList.remove(1);
  REQUIRE(linkList.getCapacity() == 1);
}