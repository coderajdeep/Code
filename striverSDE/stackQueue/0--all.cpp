// [1-6] Basic implementation problem
// [3-4] need to know, otherwise hard to come up with solution

// TODO
// Need to implement circular queue

// Validate a prefix, infix or postfix expression

// 1
// Implement stack class -- coding ninjas

// 2
// Implement queue class -- coding ninjas

// 3 **
// Approach 1 push(X) : insert X into Q2, insert all elements from Q1 to Q2 one by one (initially single entered element will be on top), 
// Then swap Q1 and Q2
// Approach 2 push(x) : Insert into Q, then insert size - 1 element pop and push to the queue
// Implement stack using queue -- leetcode 225

// 4 **
// Approach 1 push(x) : Insert from S1 to S2 one by one, then insert X into S1, then again insert from S2 to S1 one by one
// Approach 2 is very easy and optimize also
// Implement queue using stack -- leetcode 232

// 5
// Need to maintain top as head of linkedlist
// Implement stack class using Linkedlist -- coding ninjas

// 6
// Need to maintain front as head and rear as tail of linked list
// Implement queue using linkedlist -- coding ninjas

// 7 **
// Stack based solution 
// https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
// Constant space solution, but the string will be modified
// Checked for balanced paranthesis -- leetcode 20

// 8 ***
// Very very important problem
// O(n) solution is tricky
// Implement Minimum stack -- leetcode 155

// Very Very important
// https://leetcode.com/problems/basic-calculator/solutions/414898/infix-to-postfix-a-general-approach-to-similar-questions/
// 9 **
// Infix to postfix expression  -- coding ninjas

// 10
// Prefix to infix expression -- coding ninjas

// 11
// Prefix to postfix -- coding ninjas

// 12
// Postfix to prefix -- coding ninjas

// 13
// Postfix to Infix -- coding ninjas

// 14 **
// This is tricky
// Infix to Prefix -- coding ninjas

// 15
// Next greater element -- leetcode 496

// 16
// Have better method
// Next greater element -- leetcode 503

// 17
// Next smalletr element  -- InterviewBit

// 18
// Number of NGE -- Coding Ninjas

// 19
// Tapping Rainwater -- leetcode 42

// 20
// Sum of subarray minimum -- leetcode 907

// 21
// Asteroid Collision -- leetcode 735

// 22
// Sum of subarray ranges -- leetcode 2104

// 23
// Remove K digits -- leetcode 402

// 19
// Need to do this in one pass
// Largest Rectangle in histogram -- leetcode 84