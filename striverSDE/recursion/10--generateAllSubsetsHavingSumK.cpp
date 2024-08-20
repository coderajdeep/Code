// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, int sum, vector<int> &arr, vector<int> &subset, vector<vector<int>> &subsets) {
    if(index == n) {
        if(sum == 0) {
            subsets.push_back(subset);
        }
        return;
    }
    solve(index+1, n, sum, arr, subset, subsets);
    subset.push_back(arr[index]);
    solve(index+1, n, sum-arr[index], arr, subset, subsets);
    subset.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> subset;
    vector<vector<int>> subsets;
    solve(0, n, k, arr, subset, subsets);
    return subsets;
}