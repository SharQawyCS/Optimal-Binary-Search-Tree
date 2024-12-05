/**
 * This Class for utilities
 */

#pragma once
#include "Vector.h"

// TODO: A function to get the input from the user (cin not enough becuase we need better data validation )

namespace Utils
{
  // A function to return a 2D Vector with specified sizes
  template <typename T>
  Vector<Vector<T>> create2D(size_t rows, size_t cols)
  {
    Vector<Vector<T>> result(rows);
    for (size_t i = 0; i < rows; ++i)
    {
      result[i].resize(cols);
    }
    return result;
  }

  template <typename T>
  static void displayTwoDVec(const Vector<Vector<T>> &vec)
  {
    std::cout << "\nYOUR VEC IS...\n";
    int n = vec.size() - 2;

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i - j > 0)
          std::cout << "-\t\t";
        else
          std::cout << vec[i][j] << "\t\t";
      }
      std::cout << std::endl;
    }
  }

  template <typename T>
  void getDataFromUser(Vector<T> &DataLables, int &N, Vector<float> &P, Vector<float> &Q)
  {
    // TODO: Get lables code should be here..

    // Getting number of nodes...
    std::cout << "Enter n: ";
    std::cin >> N;

    // Getting probability of successful search (p)...
    std::cout << "Enter p: ";
    P[0] = 0;
    for (size_t i = 1; i <= N; i++)
    {
      float in;
      std::cin >> in;
      P[i] = in;
    }

    // Getting probability of un-successful search (q)...
    std::cout << "Enter q: ";
    for (size_t i = 0; i <= N; i++)
    {
      float in;
      std::cin >> in;
      Q[i] = in;
    }
  }
}