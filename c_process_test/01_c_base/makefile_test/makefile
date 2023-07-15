CC = gcc
CFLAGS = -O2 -g
TARGET = cacu
OBJS = ./add/add_float.o ./add/add_int.o ./sub/sub_float.o ./sub/sub_int.o cacu.o
RM = rm -rf

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS)

$(OBJS):%o:%c
	$(CC) -c $< -o $@ $(CFLAGS)
clean:
	$(RM) $(OBJS) $(TARGET)
