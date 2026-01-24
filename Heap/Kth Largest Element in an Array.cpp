class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;

        while(true) {
            int ind = partition(nums, left, right);

            if(ind == k - 1) return nums[ind];
            
            if(ind + 1 > k) {
                right = ind - 1;
            }
            else {
                left = ind + 1;
            }
        }

        return 0;
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int l = left;
        int r = right - 1;

        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }

        swap(nums[right], nums[l]);

        return l;
    }
};