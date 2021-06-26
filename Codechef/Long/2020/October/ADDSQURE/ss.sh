for ((i = 1;i <= 1000;i++)) do
 echo $i
 ./gen > INT
 #cat INT
#./solve < INT > OUT
 diff <(./solve < INT) <(./brute < INT) || break
done
