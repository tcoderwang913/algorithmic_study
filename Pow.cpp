/**
Implement Pow(x,n)
*/

class Solution {
public:
    double pow(double x, int n) {
        if (n ==0) return 1.0;
	
	    double temp = pow(x, n/2);
	
	    if (n %2 ==0) return temp * temp;
	    else {
		    if (n >0) return temp * temp *x;
		    else return (temp*temp)/x;
	    }
    }
};