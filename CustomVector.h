/**
 * This is a custom vector impelementation becase it is not allowed to use std::vector
 */

#include <iostream>
#include <stdexcept> // For exceptions
using namespace std;

// A basic implementation of a dynamic array (custom vector)
template <typename T>
class CustomVector
{
private:
  T *data;         // Pointer to the dynamically allocated array
  size_t capacity; // Current capacity of the array
  size_t size;     // Current number of elements

  void resizeIfNeeded()
  {
    if (size >= capacity)
    {
      // Double the capacity
      capacity *= 2;
      T *newData = new T[capacity];

      // Copy old data to new array
      for (size_t i = 0; i < size; i++)
      {
        newData[i] = data[i];
      }

      // Delete old data and reassign
      delete[] data;
      data = newData;
    }
  }

public:
  // Constructor
  CustomVector(size_t initialCapacity = 4)
      : capacity(initialCapacity), size(0)
  {
    data = new T[capacity];
  }

  // Destructor
  ~CustomVector()
  {
    delete[] data;
  }

  // Add an element at the end
  void push_back(const T &value)
  {
    resizeIfNeeded();
    data[size++] = value;
  }

  // Access element by index (read/write)
  T &operator[](size_t index)
  {
    if (index >= size)
    {
      throw out_of_range("Index out of bounds");
    }
    return data[index];
  }

  // Access element by index (read-only)
  const T &operator[](size_t index) const
  {
    if (index >= size)
    {
      throw out_of_range("Index out of bounds");
    }
    return data[index];
  }

  // Get the current number of elements
  size_t getSize() const
  {
    return size;
  }

  // Resize the vector to a specific size and initialize new elements
  void resize(size_t newSize, const T &defaultValue = T())
  {
    if (newSize > capacity)
    {
      while (capacity < newSize)
      {
        capacity *= 2;
      }
      T *newData = new T[capacity];
      for (size_t i = 0; i < size; i++)
      {
        newData[i] = data[i];
      }
      for (size_t i = size; i < newSize; i++)
      {
        newData[i] = defaultValue;
      }
      delete[] data;
      data = newData;
    }
    else
    {
      for (size_t i = size; i < newSize; i++)
      {
        data[i] = defaultValue;
      }
    }
    size = newSize;
  }
};
