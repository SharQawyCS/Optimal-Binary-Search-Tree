/**
 * This class for the optimal binary search tree
 */
#pragma once

#include <iostream>
#include "Vector.h"
#include "TreeNode.h"
#include "Tree.h"

namespace OBST
{
  // To set up the base cases for e, w, root
  void initializeLoop(Vector<Vector<float>> &E, Vector<Vector<float>> &W, Vector<Vector<float>> &Root,
                      const int &N, const Vector<float> &P, const Vector<float> &Q)
  {
    for (int a = 1; a <= N; a++)
    {
      // normal init
      W[a][a - 1] = E[a][a - 1] = Q[a - 1];
      // init to skip length 1 loop
      Root[a][a] = a;
      W[a][a] = Q[a - 1] + P[a] + Q[a];
      E[a][a] = Q[a - 1] + Q[a] + W[a][a];
    }
    // done outside loop to avoid if condition inside previous loop (a = 1 -> n)
    W[N + 1][N] = E[N + 1][N] = Q[N];
  }

  // To run the main dynamic programming algorithm
  void computeOBST(Vector<Vector<float>> &E, Vector<Vector<float>> &W, Vector<Vector<float>> &Root,
                   const int &N, const Vector<float> &P, const Vector<float> &Q)
  {
    for (int l = 2; l <= N; l++)
    {
      for (int i = 1; i <= N - l + 1; i++)
      {
        int j = i + l - 1;
        E[i][j] = 30000;
        W[i][j] = W[i][j - 1] + P[j] + Q[j];

        // usual: r = i -> j , length = l
        // now: r = root[i][j-1] -> root[i+1][j] , length = variable
        for (int r = Root[i][j - 1]; r <= Root[i + 1][j]; r++)
        {

          float t = E[i][r - 1] + E[r + 1][j] + W[i][j];
          if (t < E[i][j])
          {
            E[i][j] = t;
            Root[i][j] = r;
          }
        }
      }
    }
  }

  // Take root vector and lables and returns a OBST (A helper functions )
  TreeNode *buildTreeFromRoot(const Vector<Vector<float>> &root, const Vector<std::string> &labels, int i, int j)
  {
    if (i > j || root[i][j] == 0)
      return nullptr;

    // Find the root of this subtree
    int r = static_cast<int>(root[i][j]);
    TreeNode *node = new TreeNode(labels[r - 1]); // Adjusting 1-based indexing to 0-based

    // Recursively build left and right subtrees
    node->left = buildTreeFromRoot(root, labels, i, r - 1);
    node->right = buildTreeFromRoot(root, labels, r + 1, j);

    return node;
  }

  // Wrapper to create the tree object
  Tree convertToTree(const Vector<Vector<float>> &root, const Vector<std::string> &labels, int n)
  {
    Tree tree;
    tree.setRoot(buildTreeFromRoot(root, labels, 1, n));
    return tree;
  }

}