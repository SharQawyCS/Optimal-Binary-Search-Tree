#pragma once

#include <iostream>
#include <string>

/**
 * @class TreeNode
 * Represents a node in a binary tree. Each node stores a key and pointers to its left and right child nodes.
 */
class TreeNode
{
public:
  std::string key; ///< The value or label of the node.
  TreeNode *left;  ///< Pointer to the left child node.
  TreeNode *right; ///< Pointer to the right child node.

  /**
   * @brief Constructor for the TreeNode class.
   *
   * Initializes the node with a given key and sets its child pointers to null.
   *
   * @param key The value or label to be assigned to the node.
   */
  TreeNode(const std::string &key) : key(key), left(nullptr), right(nullptr) {}
};
