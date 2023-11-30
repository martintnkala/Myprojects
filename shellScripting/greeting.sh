#! /bin/bash

read -p 'Enter name : ' name
read -sp 'Password: ' password
if [ "$password" = "Martin" ];
then
    echo "Hello $name, welcome to shell scripting."
else
    echo "Invalid password"
fi