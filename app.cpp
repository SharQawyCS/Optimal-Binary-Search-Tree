/**
 * ISA we will make a good documentation to publish this code
 * After finisihing the main task we may add GUI using web techs or simple C++ lib :)
 *
 * This is a good video to understand: https://www.youtube.com/watch?v=wAy6nDMPYAE&t=18s
 * Read about: Successful and unSuccessful search...
 * Learn: Trees => Binary Search => Binary Trees => Binary Search Trees =>  Optimal Binary Search Trees
 */
#include <iostream>
#include "CustomVector.h"

using namespace std;

void printRoot(int n, CustomVector<CustomVector<int>> root)
{
  cout << "\nRoot\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i - j > 0)
        cout << "-\t\t";
      else
        cout << root[i][j] << "\t\t";
    }
    cout << endl;
  }
}

void printProbability(int n, CustomVector<CustomVector<int>> w)
{
  cout << "\nW (Probability)\n";
  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i - j > 1)
        cout << "----\t\t";
      else
      {
        cout << w[i][j];
        if (j != n)
          cout << "0";
        cout << "\t\t";
      }
    }
    cout << endl;
  }
}

void printCost(int n, CustomVector<CustomVector<int>> e)
{
  cout << "E (Cost)\n";
  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i - j > 1)
        cout << "----\t\t";
      else
      {
        cout << e[i][j];
        if (j != n)
          cout << "0";
        cout << "\t\t";
      }
    }
    cout << endl;
  }
}

int main()
{
  std::cout << "Hi from main!" << std::endl;

  int n = 4;
  float p[5] = {0, 3 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0};
  float q[5] = {2 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0, 1 / 16.0};

  float e[n + 2][n + 2];
  float w[n + 2][n + 2];
  float root[n + 2][n + 2];

  for (int a = 1; a <= n; a++)
  {
    // normal init
    w[a][a - 1] = e[a][a - 1] = q[a - 1];
    // init to skip length 1 loop
    root[a][a] = a;
    w[a][a] = q[a - 1] + p[a] + q[a];
    e[a][a] = q[a - 1] + q[a] + w[a][a];
  }
  // done outside loop to avoid if condition inside previous loop (a = 1 -> n)
  w[n + 1][n] = e[n + 1][n] = q[n];

  // MAIN ALGO
  for (int l = 2; l <= n; l++)
  {
    for (int i = 1; i <= n - l + 1; i++)
    {
      int j = i + l - 1;
      e[i][j] = 30000;
      w[i][j] = w[i][j - 1] + p[j] + q[j];

      // usual: r = i -> j , length = l
      // now: r = root[i][j-1] -> root[i+1][j] , length = variable
      for (int r = root[i][j - 1]; r <= root[i + 1][j]; r++)
      {

        float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
        if (t < e[i][j])
        {
          e[i][j] = t;
          root[i][j] = r;
        }
      }
    }
  }

  cout << "E (Cost)\n";
  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i - j > 1)
        cout << "----\t\t";
      else
      {
        cout << e[i][j];
        if (j != n)
          cout << "0";
        cout << "\t\t";
      }
    }
    cout << endl;
  }

  cout << "\nW (Probability)\n";
  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i - j > 1)
        cout << "----\t\t";
      else
      {
        cout << w[i][j];
        if (j != n)
          cout << "0";
        cout << "\t\t";
      }
    }
    cout << endl;
  }

  cout << "\nRoot\n";
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i - j > 0)
        cout << "-\t\t";
      else
        cout << root[i][j] << "\t\t";
    }
    cout << endl;
  }

  return 0;
}
