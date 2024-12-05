/**
 * TODO
 * ISA we will make a good documentation to publish this code
 * After finisihing the main task we may add GUI using web techs or simple C++ lib :)
 *
 * This is a good video to understand: https://www.youtube.com/watch?v=wAy6nDMPYAE&t=18s
 * Read about: Successful and unSuccessful search...
 * Learn: Trees => Binary Search => Binary Trees => Binary Search Trees =>  Optimal Binary Search Trees
 */
#include <iostream>
#include "Vector.h"

using namespace std;

// TODO make util class for static methods
/* ==== Functions prototypes ==== */
void getDataFromUser();
void printRoot();
void printProbability(); // TODO replace it with a display function in the Vector.h
void printCost();
template <typename T>
Vector<Vector<T>> create2D(size_t rows, size_t cols);

/* ==== Global variables ==== */
// Data should input by the user
int n = 4; // NO. of nodes in the tree
Vector<float> p(n + 1);
Vector<float> q(n + 1);

// Arrays to hold data for the app
int arrSize = n + 2; // Make it a little bit bigger to prevent errors
Vector<Vector<float>> e = create2D<float>(arrSize, arrSize);
Vector<Vector<float>> w = create2D<float>(arrSize, arrSize);
Vector<Vector<float>> root = create2D<float>(arrSize, arrSize);

/* ==== Functions implementation ==== */
void getDataFromUser()
{
  cout << "Enter n: ";
  cin >> n;

  cout << "Enter p: ";
  p[0] = 0;
  for (size_t i = 1; i <= n; i++)
  {
    float in;
    cin >> in;
    p[i] = in;
  }

  cout << "Enter q: ";
  for (size_t i = 0; i <= n; i++)
  {
    float in;
    cin >> in;
    q[i] = in;
  }
}

// For printing derived data
void printRoot()
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

void printProbability()
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

void printCost()
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

// MAIN
int main()
{
  std::cout << "APP STARTED..." << std::endl;

  // Dammy data //TODO DELETE THIS
  //  float p[5] = {0, 3 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0};
  //  float q[5] = {2 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0, 1 / 16.0};

  getDataFromUser();

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

  // Printing derived output...
  printCost();
  printProbability();
  printRoot();

  return 0;
}
