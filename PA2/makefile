CFLAGS = -g -Wno-deprecated

image.o:	image.h image.cpp
	g++ -c $(CFLAGS) image.cpp

Driver:	image.h image.o \
		driver.cpp
	g++ -o Driver $(CFLAGS) image.o \
				driver.cpp
