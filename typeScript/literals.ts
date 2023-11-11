type Gender = 'Male' | 'Female' | 'Unknown';

let gender: Gender;


function notify (message: string, gender: Gender){
    if (gender === 'Female'){
        console.log(" You nurture your kids. ")
    }
    else if (gender === 'Male'){
        console.log('You provide for your family"s needs. ')
    }
    else{
        console.log(" You can do all work. ")
    }
}