/**
 * @file main.cpp
 * @brief Entry point for the Optimal Binary Search Tree (OBST) project.
 *
 * @project University Project - Optimal Binary Search Tree (OBST)
 * @university Ain Shams University - Faculty of Engineering
 * This project is a practical implementation of the Optimal Binary Search Tree (OBST) algorithm as part of
 * a university assignment. It is designed to demonstrate key concepts in data structures and algorithms,
 * focusing on the optimization of binary search tree structures for efficient retrieval operations.
 *
 * @features
 * - Interactive user input for probabilities and keys.
 * - Implementation of the OBST algorithm using dynamic programming.
 * - Display of intermediate calculations such as cost, weight, and root tables.
 * - Modular code with utilities for input handling and matrix operations.
 *
 * @future_plans and todos
 * TODO:
 * - Enhance the project documentation for possible publication as a learning resource.
 * - Add a graphical user interface (GUI) to improve usability:
 *   - Options include modern web technologies (React, Angular, etc.) or lightweight C++ GUI libraries (e.g., Qt, ImGui).
 * - Separate the logic into `.h` and `.cpp` files for cleaner structure and reusability.
 * - Explore advanced applications of OBST in real-world scenarios, such as database indexing.
 *
 * Concepts to Learn:
 * - Trees => Binary Search Trees => Optimal Binary Search Trees.
 * - Successful and Unsuccessful search probabilities in trees.
 *
 * References:
 * - Excellent explanatory video: https://www.youtube.com/watch?v=wAy6nDMPYAE&t=18s
 */

#include <iostream>
#include "Vector.h"
#include "Utils.h"
#include "OptimalBST.h"
#include "Tree.h"

using namespace std;

/* ==== Global Variables ==== */
// Data to be input by the user
int n = 4;                // Number of nodes in the tree
Vector<float> p(n + 1);   // Probabilities of successful searches
Vector<float> q(n + 1);   // Probabilities of unsuccessful searches
Vector<string> labels(n); // Labels for nodes (keys)

// Arrays to hold intermediate calculations for the OBST algorithm
int arrSize = n + 2;                                                   // Array size is slightly larger to handle edge cases
Vector<Vector<float>> e = Utils::create2D<float>(arrSize, arrSize);    // Cost table
Vector<Vector<float>> w = Utils::create2D<float>(arrSize, arrSize);    // Weight table
Vector<Vector<float>> root = Utils::create2D<float>(arrSize, arrSize); // Root table

/**
 * @brief Main function for test the Optimal Binary Search Tree (OBST) application.
 *
 * Steps:
 * 1. Collects input data (probabilities and labels) from the user.
 * 2. Executes the OBST algorithm to compute:
 *    - Cost matrix (e): Minimum search costs.
 *    - Weight matrix (w): Accumulated probabilities.
 *    - Root matrix (root): Optimal root nodes for subtrees.
 * 3. Displays results in matrix form for educational analysis.
 *
 * @return int Exit code (0 for success).
 */
int main()
{
  std::cout << "==== Optimal Binary Search Tree Application ====" << std::endl;

  // TODO: Remove dummy data after completing the implementation
  // Example:
  // float p[5] = {0, 3 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0};
  // float q[5] = {2 / 16.0, 3 / 16.0, 1 / 16.0, 1 / 16.0, 1 / 16.0};

  // Input data
  Utils::getDataFromUser(labels, n, p, q);

  // TODO Dummy lables until we update the function to get them
  labels[0] = "l1";
  labels[1] = "l2";
  labels[2] = "l3";
  labels[3] = "l4";

  // Compute the OBST
  OBST::initializeLoop(e, w, root, n, p, q); // Initialize tables
  OBST::computeOBST(e, w, root, n, p, q);    // Compute optimal cost and root structure

  // Display results
  std::cout << "\nDerived Outputs:\n";
  std::cout << "Cost Table (e):" << std::endl;
  Utils::displayTwoDVec(e);

  std::cout << "Weight Table (w):" << std::endl;
  Utils::displayTwoDVec(w);

  std::cout << "Root Table:" << std::endl;
  Utils::displayTwoDVec(root);

  Tree myTree = OBST::convertToTree(root, labels, n);

  std::cout << "MY TREE....." << std::endl;
  myTree.displayTree();

  std::cout << "MY TREE....." << std::endl;
  myTree.displayHorizontalTree();

  std::cout
      << "==== Execution Complete ====" << std::endl;

  return 0;
}
