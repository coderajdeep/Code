// Infix to Prefix -- coding ninjas

int prec(char& ch) {
	if(ch=='+' || ch=='-') {
		return 1;
	}
	else if(ch=='*' || ch=='/') {
		return 2;
	}
	else if(ch=='^') {
		return 3;
	}
	else {
		return 0;
	}
}
string infixToPostfix(string& exp){
	stack<char> stk;
	string postfix;
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
		else {
			while(!stk.empty() && (prec(ch)<=prec(stk.top()))) {
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

string infixToPrefix(string& exp) {
    int n = exp.size();
    int start = 0, end = n-1;
    while(start<end) {
        if(exp[start]=='(') {
            exp[start] = ')';
        }
        else if(exp[start]==')') {
            exp[start] = '(';
        }
        if(exp[end]=='(') {
            exp[end] = ')';
        }
        else if(exp[end]==')') {
            exp[end] = '(';
        }
        swap(exp[start++], exp[end--]);
    }

	// when size of the exp is odd then only we need to do this
	// if we don't want to do this then we need to reverse the expression first then need to interchange 'C' and ')'
	// https://takeuforward.org/data-structure/infix-to-prefix/
	if(n & 1) {
		if(exp[start+(end-start)/2]=='(') exp[start+(end-start)/2] = ')';
    	else if(exp[start+(end-start)/2]==')') exp[start+(end-start)/2] = '(';
	}

    string prefix = infixToPostfix(exp);

    start = 0, end = n-1;
    while(start<end) {
        swap(prefix[start++], prefix[end--]);
    }

    return prefix;
}