/**
 * This class contains utility functions that are commonly used across the application.
 * It includes functions for creating 2D vectors and displaying them.
 */

#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include "Vector.h"

namespace Utils
{
  /**
   * @brief Creates a 2D vector with specified dimensions.
   *
   * This function creates and returns a 2D vector of type T with the specified number of rows and columns.
   *
   * @tparam T The type of elements stored in the vector.
   * @param rows The number of rows in the 2D vector.
   * @param cols The number of columns in the 2D vector.
   * @return A 2D vector of size [rows][cols].
   */
  template <typename T>
  Vector<Vector<T>> create2D(size_t rows, size_t cols)
  {
    Vector<Vector<T>> result(rows); // Create outer vector with 'rows' number of elements
    for (size_t i = 0; i < rows; ++i)
    {
      result[i].resize(cols); // Resize each inner vector to have 'cols' elements
    }
    return result;
  }

  /**
   * @brief Displays a 2D vector in a readable format.
   *
   * This function displays a 2D vector, with values printed in tabular format.
   * Values that represent invalid data (where i - j > 0) are displayed as a dash ('-').
   *
   * @tparam T The type of elements stored in the vector.
   * @param vec The 2D vector to be displayed.
   */
  template <typename T>
  static void displayTwoDVec(const Vector<Vector<T>> &vec)
  {
    int n = vec.size() - 1;

    // Loop through rows
    for (int i = 1; i <= n; i++)
    {
      // Loop through columns
      for (int j = 1; j <= n; j++)
      {
        // Display a dash for invalid data or the actual value if valid
        if (i - j > 0)
          std::cout << "-\t\t";
        else
          std::cout << vec[i][j] << "\t\t";
      }
      std::cout << std::endl;
    }
  }

  void getDataFromUser(Vector<std::string> &DataLables, int &N, Vector<float> &P, Vector<float> &Q)
  {
    // Getting number of nodes...
    std::cout << "Enter number of nodes: ";
    std::cin >> N;
    std::cin.ignore();

    // DataLables = Vector<std::string>(N);
    DataLables.resize(N);
    std::cout << "Entering data labels....\n";
    for (size_t i = 0; i < N; i++)
    {
      std::string in;
      std::cout << "Enter label " << i + 1 << ": ";
      std::cin >> in;
      std::cin.ignore();
      DataLables[i] = in;
    }

    // Getting probability of successful search (p)...
    // P = Vector<float>(N + 1);
    P.resize(N + 1);
    std::cout << "Entering probability of successful search....\n";
    P[0] = 0;
    for (size_t i = 1; i <= N; i++)
    {
      float in;
      std::cout << "Enter p[" << i << "]: ";
      std::cin >> in;
      std::cin.ignore();
      P[i] = in;
    }

    // Getting probability of un-successful search (q)...
    // Q = Vector<float>(N + 1);
    Q.resize(N + 1);
    std::cout << "Entering probability of un-successful search....\n";
    for (size_t i = 0; i <= N; i++)
    {
      float in;
      std::cout << "Enter q[" << i << "]: ";
      std::cin >> in;
      std::cin.ignore();
      Q[i] = in;
    }
  }

  template <typename T>
  void swapTwo(T &a, T &b)
  {
    T temp = a;
    a = b;
    b = temp;
  }
}
