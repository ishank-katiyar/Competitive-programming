for ((i = 1; i <= 1000; i++)) do
	echo $i
	./gen > INT2
	diff <(./fft < INT2) <(./brute < INT2) || break
	# time ./fft < INT2 > /dev/null
done