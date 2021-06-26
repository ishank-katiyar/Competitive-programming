for ((i = 1;i <= 100000;i++)) do
    echo $i
    ./gen > INT
    diff <(./solve < INT) <(./brute < INT) || break
    # time ./solve < INT
done
