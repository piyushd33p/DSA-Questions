class Solution {

private: 
    bool checkRotate(string A, string B, int rotate){
        for(int i = 0 ; i< A.size(); i++ ){
            if(A[i] != B[(i+rotate) % A.size()])    return false;
        }
        return true;
    }
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();

        if( n != m) return false;

        if(!n)  return true;

        for(int k = 0 ; k < n ; k++){
            if(checkRotate(s, goal, k))     return true;
        }
        return false;


    }
};