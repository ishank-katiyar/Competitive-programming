for ((i = 1; i <= 10000; i++)) do
	echo $i
	./gen > INT1
	time diff <( < INT1) <( < INT1) || break;
	# time ./solve < INT1 > /dev/null
	# break loop if assertion failed
	# if [ $? -gt 0 ]; then
	# 	break;
	# fi
done