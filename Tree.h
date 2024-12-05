#pragma once

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

class Tree
{
private:
  TreeNode *root;

  // Helper function to display the tree
  void displayTreeHelper(TreeNode *node, int depth = 0) const
  {
    if (!node)
      return;

    // Display right subtree
    displayTreeHelper(node->right, depth + 1);

    // Display current node with indentation
    std::cout << std::setw(4 * depth) << "" << node->key << std::endl;

    // Display left subtree
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

  // Display tree in sideways format
  void displayTree() const
  {
    displayTreeHelper(root);
  }
};