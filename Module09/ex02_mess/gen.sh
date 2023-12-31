#!/bin/bash

# Function to shuffle an array
shuffle_array() {
    local array=("$@")
    local len=${#array[@]}
    for ((i = len - 1; i > 0; i--)); do
        j=$((RANDOM % (i + 1)))
        tmp=${array[i]}
        array[i]=${array[j]}
        array[j]=$tmp
    done
    echo "${array[@]}"
}

# Generate a list of arguments (positive integers from 1 to 10)
args=({1..1000})

# Shuffle the array of arguments
shuffled_args=($(shuffle_array "${args[@]}"))

# Print the shuffled array (optional)
echo "Shuffled Array: ${shuffled_args[@]}"

./PmergeMe "${shuffled_args[@]}"