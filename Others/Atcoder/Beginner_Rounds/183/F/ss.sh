for ((i = 1;i <= 1000;i++)) do
    echo $i
    ./gen > INT
    time ./solve < INT > /dev/null
    # diff <(./solve < INT) <(./brute < INT) || break
done
