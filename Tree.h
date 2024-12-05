#pragma once

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

class Tree
{
private:
  TreeNode *root;

  // Helper function to display the tree (recursively, using in-order traversal)
  void displayTreeHelper(TreeNode *node, int depth = 0) const
  {
    if (!node)
      return;

    // Print right subtree first (for better tree visualization)
    displayTreeHelper(node->right, depth + 1);

    // Indentation to represent tree structure
    std::cout << std::setw(4 * depth) << "" << node->key << std::endl;

    // Print left subtree
    displayTreeHelper(node->left, depth + 1);
  }

  // Helper function to delete the tree (for cleanup)
  void deleteTree(TreeNode *node)
  {
    if (!node)
      return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }

public:
  Tree() : root(nullptr) {}

  ~Tree()
  {
    deleteTree(root);
  }

  // Set the root of the tree
  void setRoot(TreeNode *node)
  {
    root = node;
  }

  // Display the tree
  void displayTree() const
  {
    displayTreeHelper(root);
  }
};