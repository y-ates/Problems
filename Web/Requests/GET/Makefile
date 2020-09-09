CC=g++
CFLAGS=-I -O3 -Wall -lcurl
DEPS =

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

GET: GET.cc
	$(CC) GET.cc -o curl_GET $(CFLAGS)
