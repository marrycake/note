#include "arrayList.hpp"

#include <memory>
#include <vector>

ArrayList::ArrayList(int n)
    : array(std::make_unique<int[]>(n)), capacity(n), current(0) {}

void ArrayList::createList(int n) {
  array = std::make_unique<int[]>(n);
  capacity = n;
  current = 0;
}

void ArrayList::destroyList() {
  array.reset();
  capacity = 0;
  current = 0;
}

void ArrayList::insert(int i, int e) {
  if (i > capacity | current >= capacity) {
    return;
  }

  for (int index = current; index >= i; --index) {
    array[index] = array[index - 1];
  }

  array[i - 1] = e;
  current++;
}

int ArrayList::remove(int i) {
  if (i <= 0 || i > current) {
    return -1;
  }

  int e = array[i - 1];

  for (int index = i - 1; index < current; index++) {
    array[index] = array[++index];
  }

  current--;
  return e;
}

void ArrayList::set(int i, int e) {
  if (i <= 0 || i > capacity) {
    return;
  }

  array[i - 1] = e;
}

int ArrayList::get(int i) const { return array[i - 1]; }

const int ArrayList::search(int e) const {
  for (int index = 0; index < current; index++) {
    if (array[index] == e) {
      return index + 1;
    }
  }
  return -1;
}

const int ArrayList::getLength() const { return current; }
const int ArrayList::getCapacity() const { return capacity; }