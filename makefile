CC = g++
CFLAGS = -Wall -Wextra -std=c++11
# LDFLAGS = -static-libstdc++
# LIBS = -L/usr/local/opt/mesa/lib -lGL -L/usr/local/opt/glew/lib -lGLEW -L/usr/local/opt/freeglut/lib -lglut
LIBS = -lGL -lGLEW -lglut

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = image_viewer

.PHONY: all clean run test watch

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

run: $(EXEC)
	./$(EXEC)

test: $(EXEC)
	./$(EXEC)

watch:
	while true; do \
		make test; \
		inotifywait -qre modify $(SRCS); \
	done

