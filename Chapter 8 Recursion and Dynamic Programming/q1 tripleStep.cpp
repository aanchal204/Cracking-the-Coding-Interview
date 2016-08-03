/*
Triple Step :  A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps 
at a time. Implement a method to count how many possible ways the child can run up the stairs.
*/
#include<iostream>
#define SIZE 1000
typedef long long int ll;
using namespace std;
ll tripleStep(int n){
	ll steps[SIZE];
	/*base cases */
	steps[1] = 1;
	steps[2] = 2;
	steps[3] = 4;
	//to reach step n, the child can take 1 step from n-1, 2 steps from n-2 and 3 steps from n-3
	for(int i=4;i<=n;i++)
		steps[i] = steps[i-1] + steps[i-2] + steps[i-3];
	return steps[n];
}
int main(void){
	int n;
	cin>>n;
	cout<<tripleStep(n)<<endl;
	return 0;
}