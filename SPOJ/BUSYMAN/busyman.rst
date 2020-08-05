BUSYMAN
=======

Input
-----
The first line consists of an integer T, the number of test cases. For each test case the first line consists of an integer N, the number of activities. 
Then the next N lines contains two integers m and n, the start and end time of each activity.

| 1 <= T <=10
| 1 <= N <= 100000
| 0 <= start < end <= 1000000

Output
------
For each test case find the maximum number of activities that you can do.

Approach
--------
This problem is solved using a greedy approach. In order to get maximum activities done, we consider the activities which end first. Then the next activity is selected if it starts after the ending time of the previous activity selected.
