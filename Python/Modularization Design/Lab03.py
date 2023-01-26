# 1. Name:
#      Martin Nkala
# 2. Assignment Name:
#      Lab 03 : Calendar Program
# 3. Assignment Description:
#      This program will display a calendar based on the month 
#      and year you pass in. If you put string an numbers that are out of range
#      in both month and year input a message will be displayed.
# 4. What was the hardest part? Be as specific as possible.
#      The compute offset function was the hardest part for me because I was getting any 
#      error with passing the year parameter. 
# 5. How long did it take for you to complete the assignment?
#      4 hours

# Get month function.

def get_month():
    
    month = 0
    
    is_done = False
    while not is_done:
        month = input(" Enter a month number: ")
        
        # checking to see if the input a number.
        if month.isdigit():
            month = int(month)
                   
            if month < 1 or month > 12:
                    print("Month must be between 1 and 12")
            else:   
                is_done = True 
        else:
            print("Must be an integer.")
            
        # The input must be in range  1 - 12.
                     
    return month   

# Get year function.

def get_year ():
    
    is_year = False
    year = 0
    while not is_year:
        year = input(" Enter year: ")
        
        if year.isdigit():
            year = int(year)
    
            if year < 1753:
                print("Year must be 1753 or later.")
            else:
                is_year = True             
        else:
            print("Must be an integer.")
    return year 

def is_leap_year(year):
    
    if year % 4 != 0:
        return False
    if year % 100 != 0:
        return True
    if year % 400 == 0:
        return True
    return False
                
def num_days_in_month(month, year):
    
  
    
    # This array contains months that have 31 days. 
    thirty_one_days_array = [1,3,5,7,8,10,12]
    
    # This array contains months that have 30 days. 
    thirty_days_array = [4,6,9,11]
     
    if month in thirty_one_days_array:
        # num_days = 31
        return 31
    
    elif month in thirty_days_array:
        # num_days = 30
        return 30 
    
    if month == 2:
        if is_leap_year(year):
            # num_days = 29
            return 29
        else:
            # num_days = 28
            return 28
    
# Checking for how many days are in a given year.    
def days_years(year):
    if is_leap_year(year):
        return 366
    else:
        return 365
    
def compute_offset(year, month):
    num_days = 0
    days = 0
    year = int(year)
    month = int(month)
    for year_count in range(1753, year):
        num_days += days_years(year_count)
        
    for month_count in range(1, month):
        days = num_days_in_month(month_count, year)
        match days:
            case 31:
                num_days +=31
            case 30:
                num_days +=30
            case 29:
                num_days +=29
            case 28:
                num_days +=28
        
    return (num_days + 1) % 7
    
def display_table(dow, num_days
                  ):
    '''Display a calendar table'''
    assert(type(num_days) == type(dow) == type(0))
    assert(0 <= dow <= 6)
    assert(28 <= num_days <= 31)

    # Display a nice table header
    print("  Su  Mo  Tu  We  Th  Fr  Sa")

    # Indent for the first day of the week
    for indent in range(dow):
        print("    ", end='')

    # Display the days of the month
    for dom in range(1, num_days + 1):
        print(repr(dom).rjust(4), end='')
        dow += 1
        # Newline after Saturdays
        if dow % 7 == 0:
            print("") # newline

    # We must end with a newline
    if dow % 7 != 0:
        print("") # newline

def main():
    while True:
        # function calls
        month = get_month()
        year = get_year()
        compute = compute_offset(year,month)
        display_table(compute,num_days_in_month(month, year))
    
main()