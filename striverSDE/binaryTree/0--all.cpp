// 1
// Number of nodes in N-th level

// 2
// Construct tree from a array [Array length is seven and elements are in level order]
// What if array length is variable? ***

// 3
// Binary Tree traversal

// 4
// Preorder Traversal - recursive and iterative - leetcode 144

// 5
// Inorder Traversal - leetcode 94

// 6
// Postorder Traversal - leetcode 145

// 7
// Level order traversal - leetcode 102

// 8
// Height of binary tree - leetcode 104

// 9 *
// height Balanced binary tree - leetcode 110

// 10 *
// Diameter of Binary Tree - leetcode 543

// 11 ***
// Max Path Sum -- leetcode 124

// 12
// Is Identical/Same Tree -- leetcode 100

// 13
// Binary Tree - Zigzag level order traversal

// 14 **
// Boundary Traversal of a Binary Tree -- Coding Ninjas

// 15 ***
// Vertical Order Traversal of a binary Tree -- 987

// 16 *
// Top View of binary Tree -- Coding Ninjas

// 17 *
// Bottom View of binary Tree -- Geeks

// 18 ***
// Boundary traversal solution will not work
// Right View of binary tree -- leetcode 199

// 19 **
// Better condition handling in striver solution for isMirror(t1, t2)
// Is Symmetric Tree or Mirror Tree -- leetcode 101

// 20 ***
// leetcode question is trees + string manipulation
// Root to Leaf all paths  -- leetcode 257

// 21 ***
// Limitation of this method is, this will only work if both the nodes are present
// If only one is present then also this method return this node as a LCA
// LCA of a binary tree -- leetcode 236

// 22 ***
// When we subtract the first width index from all same level value and push their childs into queues, still working fine
// left --> x right --> y
// if we dont subtract
// then width will be
// 2*y+2 - 2*x+1 --> 2*(y-x) + 1
// if we do subtract
// then width will be
// 2*(y-x)+2 - 1 --> 2*(y-x) + 1
// Both are same
// So we need to subtract for integer overflow
// Max Width of binary tree -- leetcode 662

// 23 **
// Children Sum Property -- Coding Ninjas / Geeks

// 24 ***
// Very Very important
// Need to store the parent node all of the nodes
// Then need to do level order traversal and also maintain a hash of all of the visited nodes
// If the target is given as an integer, but not a treenode, then all of nodes should be distinct
// Print all nodes at distance k from a given node

// 25 ***
// Similar to question 24
// Time to completely burn a binary tree from a given node -- coding ninjas / geeks

// 26 ***
// Find leftHeight and rightHeight, if they are equal then answer is 2^(h+1) - 1
// Otherwise recursively find leftTreeCount and rightTreeCount 
// Count Total nodes in complete binary tree -- leetcode 222

// 27
// Is Unique Binary Tree Possible

// 28 ***
// We can do optimization by hashing the inorder traversal
// Construct Binary Tree from inorder and preorder traversal

// 29
// Similar to above question, but here we have to use from last to first in postorder traversal
// and need to first right sub-tree first then left subtree
// Construct Binary Tree from inorder and postorder traversal

// 30
// Serialize and Deserialize binary tree -- leetcode 297

// Q1
// Invert Binary Tree -- leetcode 226s

// Q2 ***   
// Path to given Node -- InterviewBit

// Q3
// Convert a binary such that the tree will follow the children sum property