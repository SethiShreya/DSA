#include <iostream>
using namespace std;
#define MAX 10

class stack{
    public:
    // declaring variables and functions
    int arr[MAX];
    int push(int x);
    int pop();
    int top= -1;
    bool isEmpty();
    void print_stack();
    void top();
    
};
int stack::push(int x){
    top++;
    arr[top]= x;
    return top;
}

int stack::pop(){
    if (top<0){
        cout<<"Stack is undervalued"<<endl;
        return top;
    }else{
        top--;
        return top;
    }
    
}

bool stack::isEmpty(){
    if (top<0){
        return true;
    }
    else{
        return false;
    }
    return false;
}

void stack::print_stack(){
    for (int i=0; i<=top; i++){
        cout<<arr[(top-i)]<<endl;
    }
}
void stack::top(){
    cout<<"Value of top is "<<top;
    }

int main() {
	class stack obj;
	obj.push(4);
	obj.push(89);
	obj.push(9);
	obj.print_stack();
    cout<<"Values after popped: "<<endl;
	obj.pop();
	obj.print_stack();
	return EXIT_SUCCESS;
}