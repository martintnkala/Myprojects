nums = [10,30,40,50,60]

i_first = 0
i_last = len(nums)-1
i_mid = (i_first + i_last)//2

for num in nums:
    print(num)
if nums != None:
    temp = nums[i_first] 
    nums[i_first] = nums[i_last]
    nums[i_last] = temp

    
if len(nums) % 2 != 0:
    nums[i_mid] = nums[i_mid]
    # print(nums[i_mid])
print(nums)
    
