class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long newN = n;
        if(newN<0) newN = -1 * newN;

        while(newN){
            if(newN % 2 == 0 ){
                x = x*x;
                newN = newN/2;
            }
            else{
                ans *= x;
                newN = newN-1;
            }
        }
        
        // for(int i = 1; i<=t ; i++){
        //     ans *= x;
        // }

        if(n < 0)   ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};