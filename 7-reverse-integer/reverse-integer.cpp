class Solution {
public:
    int reverse(int x) {
        long long num = 0;

        while(x!=0){
            num = num*10 + x%10;
            x = x/10;

            if(num < INT_MIN || num >INT_MAX) return 0;  
        }

        return (int)num;
    }
};