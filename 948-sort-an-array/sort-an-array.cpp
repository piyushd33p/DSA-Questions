class Solution {
private:

    void merge(vector<int>& nums, int low, int mid, int high){
        int i = low;
        int j = mid +1;
        vector<int> temp;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while( j <= high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i = low; i<= high; i++){
            nums[i] = temp[i-low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high){
        if(high <= low){
            return;
        }

        int mid = low + (high - low)/2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);

        merge(nums, low, mid, high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return nums;
    }
};