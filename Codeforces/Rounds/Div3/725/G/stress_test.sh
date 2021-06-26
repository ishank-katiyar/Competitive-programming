for ((i = 1; i <= 10000; i++)) do
	echo $i
	./gen > INT1
	diff <(./neal_solve < INT1) <(./solve < INT1)
	#  || break;
	# time ./solve < INT1 > /dev/null
	# break loop if assertion failed
	if [ $? -gt 0 ]; then
		break;
	fi
done