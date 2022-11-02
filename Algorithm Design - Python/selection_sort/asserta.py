def average_gpa(gpas):  
    ''' Find the average GPA from the list '''

    # Add them up.
    sum = 0
    assert (sum > 0)
    
    for gpa in gpas:
        assert (gpa >= 0)
        sum += gpa

    # Compute the average and return.
    assert len(gpa > 0)
    average = sum / len(gpas)
    return average