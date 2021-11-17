#!/bin/bash

for i in {1..1000}; do
                  echo "All your base are belong to us.
0 1 1 2 3 5
1 52 3 4
108 2 DrEvil
DDDDD@
3 2 4 5 1 6
$i 
" | ./bomb >/dev/null
                  if [ $? -eq 0 ]; then
                     echo $i 

                     # exit
                  fi

done