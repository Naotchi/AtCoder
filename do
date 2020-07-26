#!/bin/sh
if [ "$#" -ne 1 ];then
    echo "usage:$0 [question ID]"
    exit 1
fi
cd "$1"
mv main.cpp "$1.cpp"
code "$1.cpp"
