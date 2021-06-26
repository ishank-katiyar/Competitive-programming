for ((i = 1; i <= 1000; i++)) do
	echo $i
	./gen > INT2
	time diff <(../del3/fft < INT2) <(./ntt < INT2) || break
	# time ./fft < INT2 > /dev/null
done