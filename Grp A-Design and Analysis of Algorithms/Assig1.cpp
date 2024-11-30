// Write a non-recursive and recursive program to calculate Fibonacci numbers and find its step count

#include<iostream>
using namespace std;

//non recursive
int fibonacci(int n,int &stepcount){
    int fib0=0,fib1=1,fibN;
    if(n<=1)
        return n;
    for(int i=2;i<=n;i++)
    {
        fibN=fib0+fib1;
        fib0=fib1;
        fib1=fibN;
        stepcount++;
    }
    return fibN;
}

int stepcount=0;
//recursive
int rec_fibonacci(int n)
{
    stepcount++;
    if(n<=1)
    { return n;}
    return rec_fibonacci(n-1)+rec_fibonacci(n-2);
}

int main()
{
    int n,choice;
    cout<<"Enter the number of terms in fibonacci series: ";
    cin>>n;

    cout << "Choose method:\n";
    cout << "1. Non-Recursive\n";
    cout << "2. Recursive\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    int result = 0;
    stepcount = 0; // Reset step count before each calculation

    switch (choice) {
        case 1:
            result = fibonacci(n, stepcount);
            cout << "Using Non-Recursive method.\n";
            break;
        case 2:
            result = rec_fibonacci(n);
            cout << "Using Recursive method.\n";
            break;
        default:
            cout << "Invalid choice.\n";
            return 1; // Exit if the choice is invalid
    }

    cout<<"the "<<n<<"th fibonacci number is "<<result<<endl;
    cout<<"Number of iterations required: "<<stepcount;

    return 0;
}



