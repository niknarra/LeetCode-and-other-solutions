class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int area = 0;

        while(i<j){
            int curr_area = min(height[i], height[j]) * (j - i);
            area = max(area, curr_area);

            if(height[i]<height[j]){
                i += 1;
            }
            else{
                j -= 1;
            }
        }
        return area;
    }
};
