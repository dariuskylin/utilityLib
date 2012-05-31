FLAGS := -g -Wall
CC    := g++
all: server client
server: reactor.cc event_demultiplexer.cc reactor_server_test.cc
	$(CC) $(FLAGS) reactor.cc event_demultiplexer.cc reactor_server_test.cc -o $@
client: reactor.cc event_demultiplexer.cc reactor_client_test.cc
	$(CC) $(FLAGS) reactor.cc event_demultiplexer.cc reactor_client_test.cc -o $@
clean:
	rm server ; rm client
