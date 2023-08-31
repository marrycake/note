#ifndef LINKLIST_H
#define LINKLIST_H

#include <memory>

template <typename T>
struct LNode;

template <typename T>
using PLinkNode = LNode<T>*;

template <typename T>
using DLinkNode = LNode<T>;

template <typename T>
struct LNode {
  T data;
  struct LNode<T>* next;

  LNode<T>(T data, LNode<T>* next) : data(data), next(next) {}
};

template <typename T>
class LinkList {
 public:
  LinkList() = default;
  ~LinkList() {
    if (header) {
      destroy();
      delete header;
    }
  };

  void create() {
    capacity = 0;
    header = new LNode<T>{"", nullptr};
  }
  void destroy() {
    if (header) {
      PLinkNode<T> p = header->next;
      while (p != nullptr) {
        PLinkNode<T> node = p;
        p = node->next;
        delete node;
      }
    }
    capacity = 0;
  };

  void insert(int i, T e) {
    if (i <= 0 || i > capacity + 1) {
      return;
    }

    PLinkNode<T> p = header;
    int j = 1;
    while (j < i) {
      p = p->next;
      j++;
    }

    PLinkNode<T> node = new LNode<T>(e, p->next);
    p->next = node;

    capacity++;
  }
  T remove(int i) {
    if (i <= 0 || i > capacity) {
      return 0;
    }

    PLinkNode<T> p = header;
    int j = 1;
    while (j < i) {
      p = p->next;
      j++;
    }

    std::unique_ptr<LNode<T>> node(p->next);

    T result = node->data;
    p->next = p->next->next;

    capacity--;
    return result;
  }
  void set(int i, T e) {
    if (i <= 0 || i > capacity) {
      return;
    }

    PLinkNode<T> p = header;
    int j = 0;
    while (j < i) {
      p = p->next;
      j++;
    }

    p->data = e;
  }
  [[nodiscard]] const T get(int i) const {
    if (i <= 0 || i > capacity) {
      return nullptr;
    }

    PLinkNode<T> p = header;
    int j = 0;
    while (j < i) {
      p = p->next;
      j++;
    }

    return p->data;
  }
  [[nodiscard]] const int search(T e) const {
    PLinkNode<T> p = header->next;
    int index = 1;
    while (p != nullptr) {
      if (p->data == e) {
        return index;
      }
      index++;
      p = p->next;
    }
    return -1;
  }
  [[nodiscard]] const int getCapacity() const { return capacity; }

 private:
  PLinkNode<T> header;
  int capacity;
};

#endif  // LINKLIST_H