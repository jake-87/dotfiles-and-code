TARGET = ksmvm
all:
	cd vm-src && make && make cp
clean:
	cd vm-src && make clean
	rm -f $(TARGET) *.core
