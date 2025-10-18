#!/bin/bash
for a in {1..5}; do
  for b in {1..5}; do
    if [ "$a" -ne "$b" ]; then
      for c in {1..5}; do
        if [ "$c" -ne "$a" ] && [ "$c" -ne "$b" ]; then
          for d in {1..5}; do
            if [[ "$d" -ne "$a" && "$d" -ne "$b" && "$d" -ne "$c" ]]; then
              for e in {1..5}; do
                if [[ "$e" -ne "$a" && "$e" -ne "$b" && "$e" -ne "$c" && "$e" -ne "$d" ]]; then
                  ./push_swap $a $b $c $d $e | ./checker_linux $a $b $c $d $e | grep -q KO && echo "KO: $a $b $c $d $e"
                fi
              done
            fi
          done
        fi
      done
    fi
  done
done

