// 1
// N-th Fibonacci number -- geeks

// 2 **
// Same as n-th fibonacci number
// Climbing Stairs (distinct way to reach n-th stair) -- leetcode 70

// 3 **
// Similar to Climbing Stairs -- Here we just need the min Value not the total distinct way
// Geek Jump -- Geeks
// Frog Jump -- Coding Ninjas

// 4 ***
// Minimum cost -- geeks
// Here constant space solution is not possible
// Frog Jump with k distance -- Coding Ninjas

// 5 **
// Maximum sum of non-adjacent elements
// House Robber -- leetcode 198

// 6 ***
// Same as previous question, here just the given array is cyclic
// So we need to find max between o to n-2 and 1 to n-1 index
// House Robber II -- leetcode 213

// 7 ***
// We can use index == 0 and index < 0 as a base case
// This question can be asked as K task
// Ninja's training ***

// 8 **
// Base condition can be (i==0 || j==0) return 1
// Another base condition can be (i==0 && j==0) return 1 && (i<0 || j<0) return 0
// In memoization approach, recursive stack space time complexity is O(n + m)
// Unique path -- leetcode 62

// 9 **
// In question 8, second base condition can be used in here and aditionally we need to check if the current pont has obstacles or not
// If yes then we need to return 0
// if(r<0 || c<0) return 0; if(obstacleGrid[r][c]==1) return 0; if(r==0 && c==0) return 1;
// Unique Path II -- leetcode 63

// 10 **
// Minimum Path Sum -- leetcode 64

// 11 ***
// Fixed starting point
// Here we will start from fixed starting point and base case will be when we will touch the last row
// Even we can start from the last row and end to the fixed starting point, but here we need to handle out of bound sell cases
// Minimum path sum in triangle -- leetcode 120

// 12
// Minimum falling path in rectangle -- leetcode 931 (Variable starting and ending point)

// 13
// Cherry Pickup II -- leetcode 1463

// 14
// Subset sum equal to K -- coding ninjas

// 15
// Partition equal subset sum -- leetcode 416

// 16
// Partition array into two subsets with minimum absolute sum difference -- coding ninja (leetcode 2035 need to try)

// 17
// Count subset with sum K -- Coding Ninjas

// 18
// Count Partition with given difference -- coding ninjas

// 19
// 0 1 Knapsack -- coding ninjas

// 20
// Coin Change -- leetcode 322

// 21
// Target Sum -- leetcode 494

// 25
// Longest Common Subsequence -- 1143

// 26
// Print LCS -- Coding Ninjas

// 27
// Longest Common Substring length -- Coding Ninjas

// 28
// Longest Palindromic Subsequence -- leetcode 516

// 29
// Minimum Insertion required to make a string palindrom -- leetcode 1312

// 30
// Minimum delete operation to convert one string to another -- leetcode 583

// 31
// Shortest common supersequence -- leetcode 1092

// 32
// Distinct Subsequence -- leetcode 115

// 33
// Edit distance -- leetcode 72

// 34
// Wild Card Matching -- leetcode 44 ***

// 35
// Best time to buy and sell stocks with single transaction -- leetcode 121

// 36
// Best time to buy and sell stocks II -- leetcode 122

// 37
// Best time to buy and sell stocks III -- leetcode 123

// 38   
// Best time to buy and sell stocks IV -- leetcode 188

// 41
// Longest Increasing Subsequence -- leetcode 300

// 42
// Print Longest Increasing Subsequence -- Coding Ninjas

// 43
// Largest Divisible subset -- leetcode 368

// 44
// Longest String Chain -- leetcode 1048

// 45
// Longest Biotonic subsequence -- Coding Ninjas

// 46
// Find Number of LIS -- leetcode 673

// 47
// Matrix Chain Multiplications -- Coding Ninjas

// 48
// Minimum Cost to Cut a stick -- leetcode 1547

// 49
// Max Coins for burst balloons -- leetcode 312

// 50
// Evaluate boolean expression to true -- Coding Ninjas

// 51
// Palindrome Partitioning II -- leetcode 132