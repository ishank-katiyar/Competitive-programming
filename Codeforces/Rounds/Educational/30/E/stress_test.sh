for ((i = 1; i <= 10000; i++)) do
	echo $i
	# ./gen > INT
	# diff <(./solve < INT) <(./brute < INT) || break
	# time ./solve < INT1 > /dev/null
	# break loop if assertion failed
	./gen > INT && ./brute < INT > out_brute && ./solve < INT > out_solve
	./checker INT out_solve out_brute 
	if [ $? -gt 0 ]; then
		break;
	fi
done