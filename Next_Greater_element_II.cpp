// Time Complexity: O(n)
// Space Complexity: O(n)
// Did you run the code? Yes

// Approach:
// 1. Use a stack to keep track of the indices of the elements in the nums array.
// 2. Iterate through the nums array twice (2 * n) to handle the circular nature of the problem.
// 3. For each element, check if it is greater than the element at the index stored at the top of the stack.
// 4. If it is, pop the index from the stack and set the result for that index to the current element.
// 5. Push the current index onto the stack(DO NOT PUSH ELEMENTS IN SECOND ITERATION).
// 6. Continue this process until all elements have been processed.
// 7. Return the result array.

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size(); 
            vector<int> result(n, -1);
            stack<int> st;
            for(int i = 0; i < 2 * n; i++){
                int index = i % n;
                while(!st.empty() && nums[i % n] > nums[st.top()]){
                    int poppedIdx = st.top();
                    st.pop();
                    result[poppedIdx] = nums[index];
                }if(i < n){
                    st.push(i);
                }
                
            }
            return result;
        }
    };