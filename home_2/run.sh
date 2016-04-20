#!/bin/bash
rm -rf input_a input_2
for ((i=1; i<=100; i++))
do
    echo "$i" >out
    ./a.out <out >>input_a
    ./2.out <out >>input_2 
done
rm -rf out
