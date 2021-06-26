for((i = 1; i <= 1000; i++)) do
 echo $i
 ./gen $i > in
 diff <(./solve < in) <(./brute < in) || break
done