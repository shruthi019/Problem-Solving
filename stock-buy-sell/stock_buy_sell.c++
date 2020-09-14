#include <iostream>
using namespace std;

/*
Problem: The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 
For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. 
Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.
*/

int max_profit(int price[], int s, int e) {
	// Simple solution

	if (s >= e) {
		return 0;
	}

	int profit = 0;
	for (int i = s; i < e; i++) {
		for (int j = i + 1; j <= e; j++) {
			if (price[j] > price[i]) {
				int curr_profit = price[j] - price[i] + max_profit(price, s, i - 1) + max_profit(price, j + 1, e);
				profit = max(profit, curr_profit);
			}
		}
	}

	return profit;
}

int max_profit_efficient(int price[], int n) {
	// O(n) time complexity
	
	if (n == 1) {
		return 0;
	}

	int i = 0;
	int profit = 0;
	while (i < n - 1) {
		while (i < n - 1 && price[i + 1] <= price[i]) {
			i++;
		}

		// if we are at the end of array then no profit is possible
		if (i == n - 1) {
			return 0;
		}

		int buy = i++;

		// example to understand: 5 4 3 4 5 6 7
		while (i < n && price[i] >= price[i - 1]) {
			profit += price[i] - price[i - 1];
			i++;
		}

		int sell = i - 1;

		// buy and sell store the indices of the days when to buy and sell
		// in this case we aren't using them anywhere but they can be used if required
	}

	return profit;
}

int main() {
	int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(price) / sizeof(price[0]);

    cout << max_profit(price, 0, n - 1) << endl;
    cout << max_profit_efficient(price, n) << endl;	

	return 0;
}
