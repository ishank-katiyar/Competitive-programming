for ((i = 1; i <= 1000; i++)) do
	echo $i
	./gen > INT
	diff <(./solve1 < INT) <(./solve < INT) || break
done