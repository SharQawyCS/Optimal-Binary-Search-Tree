#pragma once

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

/**
 * @class Tree
 * A class to represent a binary tree and provide utilities like displaying
 * the tree structure and cleaning up memory.
 */
class Tree
{
private:
  TreeNode *root; // Pointer to the root of the tree

  /**
   * @brief Helper function to display the tree in a sideways format.
   *
   * This function prints the tree starting from the rightmost node
   * (to represent the tree as if it's lying sideways).
   *
   * @param node Current node being processed.
   * @param depth Current depth in the tree (used for indentation).
   */
  void displayTreeHelper(TreeNode *node, int depth = 0) const
  {
    if (!node)
      return;

    // Display the right subtree first
    displayTreeHelper(node->right, depth + 1);

    // Print the current node with indentation proportional to depth
    std::cout << std::setw(4 * depth) << "" << node->key << std::endl;

    // Display the left subtree
    displayTreeHelper(node->left, depth + 1);
  }

  /**
   * @brief Helper function to delete the tree and free memory.
   *
   * This function is used to recursively delete all nodes in the tree.
   *
   * @param node Current node being processed for deletion.
   */
  void deleteTree(TreeNode *node)
  {
    if (!node)
      return;

    // Recursively delete left and right subtrees
    deleteTree(node->left);
    deleteTree(node->right);

    // Delete the current node
    delete node;
  }

public:
  /**
   * @brief Default constructor for the Tree class.
   *
   * Initializes the tree with an empty root.
   */
  Tree() : root(nullptr) {}

  /**
   * @brief Destructor for the Tree class.
   *
   * Automatically deletes all nodes in the tree to prevent memory leaks.
   */
  ~Tree()
  {
    deleteTree(root);
  }

  /**
   * @brief Set the root node of the tree.
   *
   * This function assigns a node to be the root of the tree.
   *
   * @param node Pointer to the new root node.
   */
  void setRoot(TreeNode *node)
  {
    root = node;
  }

  /**
   * @brief Display the tree structure in a sideways format.
   *
   * This function provides a visual representation of the tree,
   * showing the root at the left and branches going down.
   */
  void displayTree() const
  {
    displayTreeHelper(root);
  }
};
