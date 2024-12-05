/**
 * This Class for utilities
 */

#pragma once

#include <iostream>
#include <cstdio>
#include <string>
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

  // TODO: these two functions need to be impelemented and tested well
  /*
    void getDataFromUser(Vector<std::string> &DataLables, int &N, Vector<float> &P, Vector<float> &Q)
    {
      // Getting number of nodes...
      std::cout << "Enter n: ";
      scanf("%d", &N); // std::cin >> N;

      // Getting probability of successful search (p)...
      P = Vector<float>(N + 1);
      std::cout << "Enter p: ";
      P[0] = 0;
      for (size_t i = 1; i <= N; i++)
      {
        float in;
        scanf("%f", &in); // std::cin >> in;
        P[i] = in;
      }

      // Getting probability of un-successful search (q)...
      Q = Vector<float>(N + 1);
      std::cout << "Enter q: ";
      for (size_t i = 0; i <= N; i++)
      {
        float in;
        scanf("%f", &in); // std::cin >> in;
        Q[i] = in;
      }

      // TODO: Get lables code should be here..
      DataLables = Vector<std::string>(N);

      for (int i = 0; i < N; i++)
      {
        DataLables[i] = "Node " + std::to_string(i + 1);
      }

      // std::cout << "Enter lables: ";
      // // get lables with spaces and without std::cin >>
      // std::cin.ignore();
      // for (size_t i = 0; i < N; i++)
      // {
      //   std::string in;
      //   // getline(std::cin, in);
      //   std::cin >> in;
      //   DataLables[i] = in;
      // }
    }

    void getStaticData(Vector<std::string> &DataLables, int &N, Vector<float> &P, Vector<float> &Q)
    {
      N = 4;
      P = Vector<float>({0, 0.15, 0.10, 0.05, 0.10});
      Q = Vector<float>({0.05, 0.10, 0.05, 0.05, 0.05});
      DataLables = Vector<std::string>(N);

      for (int i = 0; i < N; i++)
      {
        DataLables[i] = "Node " + std::to_string(i + 1);
      }
    }
    */
}