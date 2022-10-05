while True:
    color_group = str(input("Do you own all the green properties? (y/n): "))
    # print(color_group == 'y')
    if color_group != 'y':
        # print("No Properties.")
        print("You cannot purchase a hotel until you own all the properties of a given color group.")
    else:
        # if color_group == 'y':
        num_pa_properties = int(input("What is on Pennsylvania Avenue? (0:nothing, 1:one house, ... 5:a hotel): "))
        # print(num_pa_properties == 5)
        if num_pa_properties == 5:
            print("One hotel.")
            print("You cannot purchase a hotel if the property already has one.")
        else:
            num_pc_properties = int(input("What is on Pacific Avenue? (0:nothing, 1:one house, ... 5:a hotel): "))
            if num_pc_properties == 5:
                if num_pa_properties == 4:
                    print("Swap Pacific's hotel with Pennsylvania's 4 houses.")
            else:
                num_nc_properties = int(input("What is on North Carolina Avenue? (0:nothing, 1:one house, ... 5:a hotel)"))
