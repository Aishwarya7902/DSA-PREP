// problem : https://www.geeksforgeeks.org/problems/reverse-coding2452/1

/*

parametized way
*/

#include <iostream>
using namespace std;

void findSum(int n,int &sum){
    if(n<1)return;
    
    sum+=n;
    findSum(n-1,sum);
}

int main() {
    int n;
    cin >> n;

    // code here
    int sum=0;
    findSum(n,sum);
    cout<<sum;

    return 0;
}

/*
functional way
*/


#include <iostream>
using namespace std;

int findSum(int n){
    if(n==0)return 0;
    
    
   return n+findSum(n-1);
}

int main() {
    int n;
    cin >> n;

    // code here
    
    cout<<findSum(n);
    

    return 0;
}
