// Time Complexity: O(n)
// Space Complexity: O(n)
// Did you run the code? Yes

//Approach: 
// 1. Use a stack to keep track of the indices of the temperatures array.
// 2. Iterate through the temperatures array. For each temperature, check if it is greater than the temperature at the index stored at the top of the stack.
// 3. If it is, pop the index from the stack and calculate the difference between the current index and the popped index. This difference is the number of days until a warmer temperature.
// 4. Push the current index onto the stack.
// 5. Continue this process until all temperatures have been processed.

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> st;
            vector<int> result(temperatures.size(), 0);
            for(int i = 0; i < temperatures.size(); i++){
                int curr = temperatures[i];
                while(!st.empty() && curr > temperatures[st.top()]){
                    int index = st.top();
                    st.pop();
                    result[index] = i - index;
                }
                st.push(i);
            }
            return result;
        }
    };