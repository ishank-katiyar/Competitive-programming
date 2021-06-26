for ((i = 1;i <= 1000;i++)) do
 echo $i
 ./gen > int
 diff <(./solve < int) <(./brute < int) || break
done

