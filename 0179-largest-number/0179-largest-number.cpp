class Solution {
public:
    string largestNumber(vector<int>& nums) {
         // Convert int vector to string vector
        vector<string> nums_str;
        for (int num : nums) {
            nums_str.push_back(to_string(num));
        }
        
        // Custom sort based on the concatenation comparison
        sort(nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
            return a + b > b + a; // Sort descending based on concatenated strings
        });
        
        // Handle case where the largest number is "0"
        if (nums_str[0] == "0") {
            return "0";
        }
        
        // Concatenate sorted strings to form the largest number
        string largest_num;
        for (const string& num_str : nums_str) {
            largest_num += num_str;
        }
        
        return largest_num;
    }
};