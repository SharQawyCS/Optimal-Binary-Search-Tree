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
#include "Utils.h"

using namespace std;

/* ==== Global variables ==== */
// Data should input by the user
int n = 4;              // NO. of nodes in the tree
Vector<float> p(n + 1); // Probability of succesful searches
Vector<float> q(n + 1); // Probability of un-succesful searches
Vector<string> lables(n);

// Arrays to hold data for the app
int arrSize = n + 2; // Make it a little bit bigger to prevent errors
Vector<Vector<float>> e = Utils::create2D<float>(arrSize, arrSize);
Vector<Vector<float>> w = Utils::create2D<float>(arrSize, arrSize);
Vector<Vector<float>> root = Utils::create2D<float>(arrSize, arrSize);

// MAIN
int main()
{
  std::cout << "APP STARTED..." << std::endl;

  // Dammy data //TODO DELETE THIS
  //  float p[5] = {0, 3 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0};
  //  float q[5] = {2 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0, 1 / 16.0};

  Utils::getDataFromUser(lables, n, p, q);

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
  Utils::displayTwoDVec(e);
  Utils::displayTwoDVec(e);
  Utils::displayTwoDVec(root);

  return 0;
}
