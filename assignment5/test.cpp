#include <iostream>
using namespace std;
//This is the function prototype
int calc_sum(int, int);
int main(void) {
	int lower_bound, upper_bound, total_sum;
	cout << "Type two integer values: ";
	cin >> lower_bound >> upper_bound;
	total_sum = calc_sum(lower_bound, upper_bound);
	cout <<endl<<"The sum is: ";
	cout <<"The sum of numbers between "<<lower_bound<<" and "<<upper_bound<<" are: "<< total_sum<<endl;
	return 0;
}
//Here we define calc_sum recursive function
int calc_sum(int lower_bound, int upper_bound) {
	int temp;
	if (lower_bound > upper_bound) {
		temp = lower_bound;
		lower_bound = upper_bound;
		upper_bound = temp;
	}
	int sum;
	//This is the termination condition of recursion
	if (lower_bound == upper_bound)
		return upper_bound;
	//Here the function calls itself
	sum = calc_sum(lower_bound, upper_bound - 1) + upper_bound;
	cout <<"The sum of numbers between "<<lower_bound<<" and "<<upper_bound<<" are: "<< sum<<endl;
	return(sum);
}
