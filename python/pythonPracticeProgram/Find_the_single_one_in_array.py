"""Given a non-empty array of integers nums, every element appears twice except for one.
Find that single one.

Input: nums = [2,2,1]
Output: 1

Input: nums = [4,1,2,1,2]
Output: 4

Input: nums = [1]
Output: 1"""

nums = eval(input("Enter the list: "))

i = 0
while i < len(nums):
    if nums.count(nums[i]) == 1:
        print(nums[i])
    i += 1
