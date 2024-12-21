/**
 * This class represents a dynamic array (vector) that can grow in size as needed.
 * It supports basic operations such as resizing, accessing elements, and displaying the contents.
 */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
  T *data;    // Pointer to the array of elements
  size_t cap; // Capacity of the vector (maximum number of elements it can hold)
  size_t len; // Current size of the vector (number of elements currently stored)

public:
  /**
   * @brief Constructor to initialize a vector with a specified size.
   *
   * If an initial size is provided, the vector is created with that many elements, each default-initialized.
   * If no size is provided, an empty vector is created.
   *
   * @param initial_size The initial size of the vector (default is 0).
   */
  Vector(size_t initial_size = 0)
      : cap(initial_size), len(initial_size), data(initial_size ? new T[initial_size] : nullptr) {}

  /**
   * @brief Constructor to initialize a vector with a list of values.
   *
   * This constructor creates a vector with the specified elements from an initializer list.
   *
   * @param list An initializer list of elements.
   */
  Vector(std::initializer_list<T> list)
      : cap(list.size()), len(list.size()), data(new T[list.size()])
  {
    size_t i = 0;
    for (const T &elem : list)
    {
      data[i++] = elem;
    }
  }

  /**
   * @brief Destructor to clean up memory allocated for the vector.
   *
   * The destructor frees the dynamically allocated memory for the vector's elements.
   */
  ~Vector()
  {
    if (len)
    {
      len = 0;
      delete[] data;
    }
  }

  /**
   * @brief Access element at the specified index.
   *
   * This function returns a reference to the element at the specified index. If the index is out of bounds,
   * an exception is thrown.
   *
   * @param index The index of the element to access.
   * @return A reference to the element at the specified index.
   * @throws std::out_of_range If the index is out of bounds.
   */
  T &operator[](size_t index)
  {
    if (index >= len)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  /**
   * @brief Access element at the specified index (const version).
   *
   * This function returns a const reference to the element at the specified index. If the index is out of bounds,
   * an exception is thrown.
   *
   * @param index The index of the element to access.
   * @return A const reference to the element at the specified index.
   * @throws std::out_of_range If the index is out of bounds.
   */
  const T &operator[](size_t index) const
  {
    if (index >= len)
    {
      throw std::out_of_range("Index out of bounds");
    }
    return data[index];
  }

  /**
   * @brief Resize the vector to a new size.
   *
   * This function resizes the vector to the specified size. If the new size is greater than the current capacity,
   * the capacity is increased. New elements are default-initialized if the new size is larger than the current size.
   *
   * @param new_size The new size for the vector.
   */
  void resize(size_t new_size)
  {
    if (new_size > cap)
    {
      // If the new size exceeds the current capacity, allocate new memory
      T *new_data = new T[new_size];
      for (size_t i = 0; i < len; ++i)
      {
        new_data[i] = data[i]; // Copy existing elements to the new array
      }
      delete[] data;   // Free the old array
      data = new_data; // Point to the new array
      cap = new_size;  // Update the capacity
    }
    // Default-initialize new elements if resizing to a larger size
    for (size_t i = len; i < new_size; ++i)
    {
      data[i] = T();
    }
    len = new_size; // Update the current size
  }

  /**
   * @brief Get the current size of the vector.
   *
   * This function returns the current size of the vector (the number of elements stored in the vector).
   *
   * @return The number of elements currently stored in the vector.
   */
  size_t size() const
  {
    return len;
  }

  /**
   * @brief Display the elements of the vector.
   *
   * This function prints all the elements of the vector to the console.
   */
  void display(bool printFirstElement = true, std::string sep = " ")
  {
    if (printFirstElement)
    {
      std::cout << data[0];
      std::cout << sep;
    }

    for (int i = 1; i < len - 1; ++i)
      std::cout << data[i] << sep;

    if (len > 0)
      std::cout << data[len - 1];

    std::cout << std::endl;
  }

  int findOne(T key) const
  {
    for (int i = 0; i < len; ++i)
    {
      if (data[i] == key)
        return i;
    }
    return -1;
  }
};
