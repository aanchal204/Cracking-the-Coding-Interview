/*
Boolean Evaluation : Given a boolean expression with symbols 0(false), 1(true), &(AND), |(OR) and ^(XOR),
and a desired boolean result value "result", implement a function to count the number of ways
of parenthesizing the expression such that it evaluates to the "result".
*/
#include<iostream>
#include<map>
using namespace std;
int val(string s){
	if(s[0] == '0')
		return 0;
	return 1;
}
int booleanEval(string expression, int result, map<string, int> hashMap){
	if(expression.length() == 0)
		return 0;
	if(expression.length() == 1){
		return result == val(expression) ? 1 : 0;
	}
	map<string, int>::iterator it = hashMap.find(expression+to_string(result));
	if(it!=hashMap.end())
		return it->second;
	int ways = 0;
	for(int i=1;i<expression.length();i+=2){
		char oper = expression[i];
		string left = expression.substr(0,i);
		string right = expression.substr(i+1);
		int leftTrue = booleanEval(left , 1, hashMap);
		int leftFalse = booleanEval(left , 0 , hashMap);
		int rightTrue = booleanEval(right , 1, hashMap);
		int rightFalse = booleanEval(right , 0 , hashMap);
		int total = (leftFalse + leftTrue) * (rightTrue + rightFalse);
		int totalTrue = 0;
		if(oper == '&')
			totalTrue = leftTrue * rightTrue;
		else if(oper == '|')
			totalTrue = (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
		else if(oper == '^')
			totalTrue = (leftTrue * rightFalse) + (leftFalse * rightTrue);
		ways += (result ? totalTrue : (total - totalTrue));
	}
	 hashMap[expression + to_string(result)] = ways;
	return ways;
}
int count(string expression, int result){
	map<string , int> hashMap;
	return booleanEval(expression, result, hashMap);
}
int main(void){
	string expression;
	cin>>expression;
	int result;
	cin>>result;
	cout<<count(expression,result)<<endl;
	return 0;
}
/*
0&0&0&1^1|0
1
*/