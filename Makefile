TARGET=add-nbo

all: $(TARGET)

$(TARGET): add-nbo.c
	gcc -o $@ $^

clean:
	rm -f $(TARGET)


