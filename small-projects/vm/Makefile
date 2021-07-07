TARGET = vm
all:
	cd vm-src && make && make cp
clean:
	cd vm-src && make clean
	rm -f $(TARGET)
ex1:
	./vm examples/hwreal 
