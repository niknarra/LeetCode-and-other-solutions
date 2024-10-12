# Finding the smaller element on the left for an element in an array

nums = [1,3,4,2,5,6,2,8,9]
ans = [] # list to hold the answer
st = [] # Monotonic Stack to keep track of smaller elements

print(nums)

for i in range(0,len(nums)): # Start from the 0th element and go to the right
    while st and st[-1] > nums[i]: # While stack is not empty and the top is greater than the current element
        st.pop() # Keep Popping

    if st: # If stack is not empty,
        ans.append(st[-1]) # Add the top to the ans
    else: # If not,
        ans.append(-1) # Add -1 to the ans

    st.append(nums[i]) # Add the current element to the stack

print(ans) # Print answer list and we're done!

# Finding the smaller element on the right for an element in an array

nums = [1,3,4,2,5,6,2,8,9]
ans = [] # list to hold the answer
st = [] # Monotonic Stack to keep track of smaller elements

for i in range(len(nums)-1,-1,-1): # Start from the nth element and go to the left
    while st and st[-1] >= nums[i]: # While stack is not empty and the top is greater than or equal the current element
        st.pop() # Keep Popping

    if st: # If stack is not empty,
        ans.append(st[-1]) # Add the top to the ans
    else: # If not,
        ans.append(-1) # Add -1 to the ans

    st.append(nums[i]) # Add the current element to the stack

print(ans[::-1]) # Reverse the answer list and we're done!
