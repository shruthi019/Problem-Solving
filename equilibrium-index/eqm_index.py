# Problem: Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
# Write a function int equilibrium(int[] arr, int n); that given a sequence arr[] of size n, returns an equilibrium index (if any) or -1 if no equilibrium indexes exist.

def equilibrium(a: [int]) -> int:
	total = sum(a)
	left_sum = 0
	for i, x in enumerate(a):
		total -= x
		if left_sum == total:
			return i
		left_sum += x
	return -1

a = list(map(int, input().strip().split()))
eqm_index = equilibrium(a)

if eqm_index == -1:
	print("No equilibrium index")
else:
	print("Equilibrium index is", eqm_index)
