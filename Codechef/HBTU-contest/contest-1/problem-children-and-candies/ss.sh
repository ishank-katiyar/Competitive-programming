for ((i = 1; i <= 1000; i++)) do
 echo $i
 ./gen > INT
 # time ./solve < INT > OUT
 # time ./brute < INT > OUT
 # time python3 solve.py < INT > OUT
 # ./gen > INT
 # diff <(./brute < INT) <(./solve < INT) || break
 diff <(./solve < INT) <(python3 solve.py < INT) || break
done