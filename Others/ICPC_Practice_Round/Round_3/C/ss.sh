for ((i = 1; i <= 10; i++)) do
	echo $i
	./gen > INT
	cat INT
	./solve < INT > /dev/null
done