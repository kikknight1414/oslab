#!/bin/bash
echo "enter"
read a
r=$(($a%2))
if [ $r -eq 0 ]
then
echo "evem"
else
echo "odd"
fi
