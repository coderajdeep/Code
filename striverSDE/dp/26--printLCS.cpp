// Time complexity O(n*m) + O(n+m)
// Space complexity O(n*m)

string findLCS(int n, int m, string &s1, string &s2){
	int dp[n+1][m+1];
	for(int i=0; i<=n; ++i) dp[i][0] = 0;
	for(int i=0; i<=m; ++i) dp[0][i] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	string str(dp[n][m], '#');
	int i=n, j=m, index = (dp[n][m]-1);
	while(i>0 && j>0 && index>=0) {
		if(s1[i-1]==s2[j-1]) {
			str[index--] = s1[i-1];
			i = i-1;
			j = j-1;
		}
		else {
			if(dp[i][j-1] < dp[i-1][j]) {
				i = i-1;
			}
			else {
				j = j-1;
			}
		}
	}
	return str;
}