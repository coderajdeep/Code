// Pascal Triangle

// Time complexity O(n^2)
// Space complexity O(n^2)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    if(numRows==1) return ans;
    ans[1] = vector<int>{1, 1};
    if(numRows==2) return ans;

    for(int numRow=2; numRow<numRows; ++numRow) {
        ans[numRow].resize(numRow+1);
        ans[numRow][0] = ans[numRow][numRow] = 1;
        for(int index=1; index<numRow; ++index) {
            ans[numRow][index] = (ans[numRow-1][index-1] + ans[numRow-1][index]);
        }
    }

    return ans;
}