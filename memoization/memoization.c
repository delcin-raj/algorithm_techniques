#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define N 30
long int cache[N+1];

void init() {
	cache[0] = 1;
	cache[1] = 1;
	for (int i = 2; i <= N; i++) {
		cache[i] = 0;
	}
}

long int fib_rec(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib_rec(n-1) + fib_rec(n-2);
}	

long int fib_mem(int n) {
	if (cache[n] != 0) {
		return cache[n];
	}
	cache[n] = fib_mem(n-1) + fib_mem(n-2);
	return cache[n];
}	

long int fib_dp(int n) {
	long int* dp = malloc(sizeof(long int) * (n + 1));
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main() {
	clock_t start,time_taken;

	start = clock();
	printf("fib recursive %d = %ld\n",N,fib_rec(N));
	time_taken = clock() - start;
	printf("time taken for recursion %ld \n",time_taken);

	start = clock();
	init();
	printf("fib memoized %d = %ld\n",N,fib_mem(N));
	time_taken = clock() - start;
	printf("time taken for momoization %ld \n",time_taken);

	start = clock();
	printf("fib dynamic programming %d = %ld\n",N,fib_dp(N));
	time_taken = clock() - start;
	printf("time taken for dynamic programming %ld \n",time_taken);
}
