class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        // stack<int> st;

        // for(int i = 0; i < height.size(); i++) {
        //     while(!st.empty() && height[st.top()] < height[i]) {
        //         int mid = height[st.top()];
        //         st.pop();
        //         if(!st.empty()) {
        //             int right = height[i];
        //             int left = height[st.top()];
        //             int h = min(right, left) - mid;
        //             int w = i - st.top() - 1;
        //             ans += h * w;
        //         }
        //     }
        //     st.push(i);
        // }

        int l = 0;
        int r = n - 1;
        int lm = height[l];
        int rm = height[r];
        while(l < r) {
            if(height[l] < height[r]) {
                lm = max(lm, height[l]);
                ans += lm - height[l];
                l++;
            }
            else {
                rm = max(rm, height[r]);
                ans += rm - height[r];
                r--;
            }
        }

        return ans;
    }
};