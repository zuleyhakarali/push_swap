#!/bin/bash

# push_swap ve checker yolunu belirt
PUSHSWAP="./push_swap"
CHECKER="./checker_linux"

test_permutation() {
    local arr=("$@")
    local output
    local sorted

    output=$($PUSHSWAP "${arr[@]}")
    sorted=$($PUSHSWAP "${arr[@]}" | $CHECKER "${arr[@]}")
    
    if [ "$sorted" = "OK" ]; then
        echo "OK: ${arr[*]}"
        return 0
    else
        echo "KO: ${arr[*]}"
        return 1
    fi
}

# Permütasyon üretme fonksiyonu
permute() {
    local -n arr=$1
    local n=${#arr[@]}

    if [ $n -le 1 ]; then
        test_permutation "${arr[@]}"
    else
        for ((i=0; i<n; i++)); do
            local tmp=("${arr[@]}")
            local elem=${tmp[i]}
            tmp=("${tmp[@]:0:i}" "${tmp[@]:i+1}")
            permute tmp
        done
    fi
}

# 3,4,5 elemanlı tüm permütasyonlar
for size in 3 4 5; do
    echo "Testing all permutations of size $size..."
    numbers=($(seq 1 $size))
    permute numbers
done