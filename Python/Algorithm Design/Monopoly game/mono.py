# # 1. Name: 
# #      Martin Nkala
# # 2. Assignment Name: 
# #      Monopoly-design
# # 3. Assignment Description:
# #      The main goal is to make sure that we place a hotel in pe
# # 4. What was the hardest part? Be as specific as possible.
# #      I struggled to structure my code so that the prompts would ne sequential.
# #      doing the calculations was so difficult for me?
# # 5. How long did it take for you to complete the assignment?
# #    8 hours

#     # You need to habe all three properties to play the game.
# color_group = input("Do you own all the green properties? (y/n) ")
# if color_group == 'n':
#     print("\tYou cannot purchase a hotel until you own\n" +
#             "all the properties of a given color group.")

# # Determine what is built on each property. 
# # If there is already a hotel on Pennsylvania, you cannot build another.
# num_pc_houses = int(input("What is on Pennsylvania Avenue? " + 
#                                     "(0:nothing, 1:one house, ... 5:a hotel) "))
# if num_pc_houses == 5:
#     print("\tYou cannot purchase a hotel if the property already has one.")

# # You might just be able to swap a hotel with North Carolina if it already has one.
# num_nc_houses = int(input("What is on North Carolina Avenue? " +
#                                     "(0:nothing, 1:one house, ... 5:a hotel) "))
# if num_nc_houses == 5:
#     assert(num_pc_houses == 4)
#     print("Swap North Carolina's hotel with Pennsylvania's 4 houses.")

# # swap hotel with 4 houese
# pacific_property = int(input("What is on Pacific Avenue? " "(0:nothing, 1:one house, ... 5:a hotel) "))
# if pacific_property == 5:
#     if num_pc_houses == 4:       
#         print("Swap Pacific's hotel with Pennsylvania's 4 houses.")

# # checking for how houses each propert will need.
# nc_needs = 4 - num_nc_houses
# pacific_needs = 4 - pacific_property
# pennsylvania_needs = 5 - num_pc_houses

# # checkign to see if there's enough money to buy hotels.
# cash_available = int(input("How much cash do you have to spend? "))
# cash_needed = (nc_needs + pacific_needs + pennsylvania_needs) * 200
# if cash_available < cash_needed:
#     print("You do not have sufficient funds to purchase a hotel at this time.")

# # checking for availabilty of houses and hotels
# houses_available = int(input("How many houses are there to purchase? "))
# available_hotels = int(input("How many hotels are there to purchase? "))

# # checking to see if there's enough money to buy houses.
# needed_houses = nc_needs + pacific_needs - num_pc_houses
# if needed_houses <= houses_available and 1 <= available_hotels:
#     print("Add", nc_needs, "house(s) to North Carolina,")
#     print("add", pacific_needs,        "house(s) to Pacific, ")
#     print("and put 1 hotel on Pennsylvania.")
#     print(f"This will cost $ {cash_needed}.")

# # Go for the two-hotel plan. Either North Carolina or Pacific needs to be a hotel. 
# # It does not matter which...
# nc_needs = 5 - num_nc_houses
# needed_houses = max(pacific_needs - num_pc_houses - 
#                         num_nc_houses, 0)
# money_cost = (nc_needs + pacific_needs + pennsylvania_needs) * 200
# if cash_available >= cash_needed and needed_houses <= houses_available and 2 <= available_hotels:
#     print("Add", pacific_needs, "house(s) to Pacific,")
#     print("\tput 1 hotel on North Carolina,")
#     print("and put 1 hotel on Pennsylvania.")
#     print(f"This will cost ${cash_needed}.")

#     # Go for the three-hotel plan. 
#     pacific_needs = max(5 - pacific_property, 0)
#     cash_needed = (nc_needs + pacific_needs + pennsylvania_needs) * 200
#     if cash_available >= cash_needed:
#         if available_hotels >= 3:
#             print("Put 1 hotel on Pacific,")
#             print("1 hotel on North Carolina,")
#             print("and 1 hotel on Pennsylvania.")
#             print(f"This will cost ${cash_needed}.")
#         else:
#             print("\tThere are not enough hotels available for purchase at this time.")
#     print("\tYou do not have sufficient funds to purchase a hotel at this time.")


# from ast import If
# from gzip import WRITE
# from pickle import GET, PUT


numbers =[9, 8, 7, 1, 2, 3, 4, 5, 6, 10 ]
print(numbers.sort())

idx = 0
for number in numbers:
    idx =+ 1
    idx_num = numbers[idx] + 1
print(idx_num)


            
            
                # PUT
                # WRITE
                # GET
                # SWITCH/case
                # WHILE 
                # FOR 
                # IF