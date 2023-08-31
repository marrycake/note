#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <array>
#include <memory>
#include <vector>

class ArrayList {
public:
  ArrayList() = default;
  explicit ArrayList(int n);
  ~ArrayList() = default;

  void createList(int n);
  void destroyList();

  void insert(int i, int e);
  int remove(int i);
  [[nodiscard]] int get(int i) const;
  void set(int i, int e);
  [[nodiscard]] const int search(int e) const;

  [[nodiscard]] const int getLength() const;
  [[nodiscard]] const int getCapacity() const;

private:
  std::unique_ptr<int[]> array;
  int current;
  int capacity;
};

#endif // ARRAYLIST_H