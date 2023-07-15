# print(__debug__)

# if __debug__:
#     print('Python Debug is enabled')
    
# print('Python Debug is disabled')

# Starting array with values in it.
source = [31, 72, 32, 10, 95, 50, 25, 18]

# Empty array that takes in 8 numbers.

for num in range(0, len(source)-1):
    print(source[num])
# destination = []*8

start_idx = 0
next_idx = 1


if source[start_idx] < source[next_idx]:
    current_idx = next_idx +1
    destination = [source[start_idx], source[next_idx]]
    print(destination)
    
 