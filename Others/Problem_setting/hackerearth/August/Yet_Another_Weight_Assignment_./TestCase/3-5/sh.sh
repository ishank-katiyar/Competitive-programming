for ((i = 3; i <= 5; i++)); do
	./gen > in0${i}.txt
	../../solve < in0${i}.txt > out0${i}.txt
done