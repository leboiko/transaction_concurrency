CC       = gcc
CFLAGS   = -Wall
LDFLAGS  =
OBJFILES = auxFunctions.o escalona.o
TARGET   = escalona

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~
