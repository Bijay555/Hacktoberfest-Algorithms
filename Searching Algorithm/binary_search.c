//Name: Pedro Perez
//GitHub: https://github.com/pedrousp

#include<stdlib.h>
#include<stdio.h>

//Input array function
long int *input_array(long int);

//Recursive binary search
long int recursive_binary_search(long*, long, long, long);

//Iterative binary search
long int iterative_binary_search(long*, long, long);

int main(int argc, char** argv){
    long size_array, key, key_position;
    
    printf("Input the size of the array: ");
    scanf("%ld", &size_array);
    
    long *array = input_array(size_array);

    printf("Input the key to be found: ");
    scanf("%ld", &key);

    //Use the one you like the most

    //key_position = recursive_binary_search(array, key, 0, size_array);

    //key_position = iterative_binary_search(array, key, size_array);
    
    if(key_position == -1)
        printf("Key not found\n");
    else
        printf("Key found in position: %ld\n", key_position);

    free(array);
    return 0;
}

long *input_array(long int size){
    long *array = malloc(size * sizeof(long int));
    for(long i = 0; i < size; i++){
        printf("Input the %ldº number of the array: ", i+1);
        scanf("%ld", &array[i]);
    }
    return array;
}

long recursive_binary_search(long *array, long key, long begin, long end){
    long middle = (long)((begin + end) / 2);
    if(middle >= end)
        return -1;
    if(key == array[middle])
        return middle;
    if(key < array[middle])
        return recursive_binary_search(array, key, begin, middle);
    return recursive_binary_search(array, key, middle+1, end);    
}

long iterative_binary_search(long *array, long key, long end){
    long begin;
    for(begin = 0; begin < end;){
        long int middle = (long int)((begin + end) / 2);
        if(key == array[middle])
            return middle;
        if(key > array[middle])
            begin = middle + 1;
        else
            end = middle;
    }
    return -1;
}
