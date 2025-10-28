# Daud Ahmad Nisar
# Makefile to compile and link the Project 10 registration system with modular components


# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -std=c99 -Wall

# Target executable name
TARGET = project10_registration

# Object files
OBJS = project10_registration.o student.o

# Rule to build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build project10_registration.o
project10_registration.o: project10_registration.c student.h
	$(CC) $(CFLAGS) -c project10_registration.c

# Rule to build student.o
student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

# Rule to clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)

