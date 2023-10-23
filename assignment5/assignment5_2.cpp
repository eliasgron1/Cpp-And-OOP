#include <iostream>
using namespace std;



float calculateSum(int n, int i){
float sum = 1.0/(i*2.0);


if(i <= n){
cout << "1/2*" << i << " = " << sum << endl;
sum += calculateSum(n, i+1);
return sum;
}
return 0;
}



float calculateMultiplication(int n, int i){
float mul = -1.0/(2.0*i+1.0);


if(i <= n){
cout << "-1/(" << i << "*2)+1" << " = " << mul << endl;
mul *= calculateMultiplication(n, i+1);
return mul;
}
return 1;
}




int main(){
int max_iterations=0, i=1;
float total_sum, total_mul;


cout << "Give amount of iterations: ";
    cin >> max_iterations;


cout << calculateSum(max_iterations, i) << endl;
cout << "------------------------------" << endl;
cout << calculateMultiplication(max_iterations, i) << endl;


return 0;
}
