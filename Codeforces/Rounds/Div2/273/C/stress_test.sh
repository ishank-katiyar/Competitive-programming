for ((i = 1; i <= 10000; i++)) do
	echo $i
	./gen > INT
	diff <(./brute < INT) <(./solve1 < INT)
	# time ./solve < INT1 > /dev/null
	# break loop if assertion failed
	if [ $? -gt 0 ]; then
		break;
	fi
done