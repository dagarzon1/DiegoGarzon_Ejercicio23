grafica.pdf:datos.txt
	python grafica.py
	rm datos.txt
datos.txt:onda.x
	./onda.x > datos.txt
	rm onda.x
onda.x:
	c++ onda.cpp -o onda.x
clean:
	rm *.pdf *.x *.txt
