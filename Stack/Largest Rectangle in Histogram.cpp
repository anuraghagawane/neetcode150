class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int l = st.empty() ? -1 : st.top();

                int width = i - l - 1;

                maxArea = max(maxArea, width * height);
            }
            st.push(i);
        }

        return maxArea;
    }
};