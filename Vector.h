#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
  T *data;
  size_t cap;
  size_t len;

public:
  Vector(size_t initial_size = 0)
      : cap(initial_size), len(initial_size), data(initial_size ? new T[initial_size] : nullptr) {}

  Vector(std::initializer_list<T> list)
      : cap(list.size()), len(list.size()), data(new T[list.size()])
  {
    size_t i = 0;
    for (const T &elem : list)
    {
      data[i++] = elem;
    }
  }

  ~Vector()
  {
    delete[] data;
  }

  T &operator[](size_t index)
  {
    if (index >= len)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  const T &operator[](size_t index) const
  {
    if (index >= len)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  void resize(size_t new_size)
  {
    if (new_size > cap)
    {
      T *new_data = new T[new_size];
      for (size_t i = 0; i < len; ++i)
      {
        new_data[i] = data[i];
      }
      delete[] data;
      data = new_data;
      cap = new_size;
    }
    for (size_t i = len; i < new_size; ++i)
    {
      data[i] = T();
    }
    len = new_size;
  }

  size_t size() const
  {
    return len;
  }

  void display()
  {
    for (int i = 0; i < len; ++i)
      std::cout << data[i] << " ";

    std::cout << std::endl;
  }
};
