class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int R = n-1;

        double NcR = 1;

        for(int i = 1; i <= R; i++){
            NcR = NcR* (N-R+ i)/ i;
        }

        return (int)NcR;

    }
};