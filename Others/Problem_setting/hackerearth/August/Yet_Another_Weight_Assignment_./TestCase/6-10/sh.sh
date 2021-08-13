for ((i = 6; i <= 10; i++)); do
	./gen > in0${i}.txt
	../../solve < in0${i}.txt > out0${i}.txt
done