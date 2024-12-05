/**
 * TODO
 * ISA we will make a good documentation to publish this code
 * After finisihing the main task we may add GUI using web techs or simple C++ lib :)
 *
 * This is a good video to understand: https://www.youtube.com/watch?v=wAy6nDMPYAE&t=18s
 * Read about: Successful and unSuccessful search...
 * Learn: Trees => Binary Search => Binary Trees => Binary Search Trees =>  Optimal Binary Search Trees
 */

// TODO we may need to separate functions from .h to .cpp

#include <iostream>
#include "Vector.h"
#include "Utils.h"
#include "OptimalBST.h"

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

  OBST::initializeLoop(e, w, root, n, p, q);
  OBST::computeOBST(e, w, root, n, p, q);

  // Printing derived output...
  Utils::displayTwoDVec(e);
  Utils::displayTwoDVec(e);
  Utils::displayTwoDVec(root);

  return 0;
}
