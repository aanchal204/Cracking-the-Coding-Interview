#include<vector>
using namespace std;
typedef struct stack{
	vector<int> arr;
	int top;
}stack;
#define SIZE 100
stack* init(void);
void push(stack *st, int val);
int pop(stack *st);
bool isEmpty(stack *st);
int peek(stack *st);