// Infix to Postfix Expression

int prec(char& ch) {
	if(ch == '+' || ch == '-') {
		return 0;
	}
	else if(ch == '*' || ch == '/') {
		return 1;
	}
	else if(ch == '*' || ch == '/') {
		return 2;
	}
	else if(ch == '^') {
		return 3;
	}
	else {
		return -1;
	}
}
string infixToPostfix(string& exp){
	string postfix = "";
	stack<char>stk;
	for(char ch : exp) {
		if((ch>='0' && ch<='9') || (ch>='a' && ch<='z')) {
			postfix.push_back(ch);
		}
		else if(ch=='(') {
			stk.push(ch);
		}
		else if(ch==')') {
			while(!stk.empty() && stk.top()!='(') {
				postfix.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
		}
		else if(stk.empty()) {
			stk.push(ch);
		}
		else if(prec(stk.top())<prec(ch)) {
			stk.push(ch);
		}
		else {
			while(!stk.empty() && prec(stk.top())>=prec(ch)) {
				postfix.push_back(stk.top());
				stk.pop();
			}
			stk.push(ch);
		}
	}
	while(!stk.empty()) {
		postfix.push_back(stk.top());
		stk.pop();
	}
	return postfix;
}