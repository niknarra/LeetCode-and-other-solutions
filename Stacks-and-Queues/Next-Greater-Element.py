# Finding the next greater element for an element in an array

nums = [1,3,4,2,5,6,2,8,9]
ans = [] # list to hold the answer
st = [] # Monotonic Stack to keep track of next greatest element

for i in range(len(nums)-1,-1,-1): # We will start from the end
    while st and st[-1] <= nums[i]: # As long as the stack is not empty and the top most element is less than current element
        st.pop() # We keep popping the stack

    if st: # Then, if the stack is not empty,
        ans.append(st[-1]) # We push the top most element

    else: # If not, we push -1 to the ans
        ans.append(-1)

    st.append(nums[i]) # We push the current element to the stack

print(ans[::-1]) # Reverse the ans list and we're done!
