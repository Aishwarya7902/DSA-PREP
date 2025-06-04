//Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.

// functional approach

//tc :o(n)
//sc :o(n)

class Solution{	
	public:
		int SumOfFirstN_Numbers(int N){
			//your code goes here

            if(N==0)return 0;

            return N+SumOfFirstN_Numbers(N-1);
		}
};

//paramete approach

class Solution{	
	public:
		int sumFirstN(int i,int &sum){
			if(i<1)return ;

            sumFirstN(i-1,sum+i);
		}
};

int sum=0;

sumFirstN(n,sum)
