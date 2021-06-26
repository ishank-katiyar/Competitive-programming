for ((i = 1; i <= 10000; i++)) do
	echo $i
	./gen > INT1
	time ./solve < INT1 > /dev/null
	if [ $? -gt 0 ]; then
		break;
	fi
done