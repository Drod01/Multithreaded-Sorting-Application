CC = gcc
CFLAGS = -Wall -pthread

JC = javac
JFLAGS = -Xlint:unchecked

.SUFFIXES: .c .java .class

# Source directories and file names
C_SRC_DIR = c_src
C_SRCS = $(wildcard $(C_SRC_DIR)/*.c)
C_OBJS = $(patsubst $(C_SRC_DIR)/%.c, $(C_SRC_DIR)/%.o, $(C_SRCS))

JAVA_SRC_DIR = java_src
JAVA_SRCS = $(wildcard $(JAVA_SRC_DIR)/*.java)
JAVA_CLASSES = $(patsubst $(JAVA_SRC_DIR)/%.java, $(JAVA_SRC_DIR)/%.class, $(JAVA_SRCS))

# Executable names
C_EXEC = prog
JAVA_EXEC = prog_j

# Default target
all: $(C_EXEC) $(JAVA_EXEC)

# Build C program
$(C_EXEC): $(C_OBJS)
	$(CC) $(CFLAGS) -o $@ $(C_OBJS)

$(C_SRC_DIR)/%.o: $(C_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build Java program
$(JAVA_EXEC): $(JAVA_CLASSES)

$(JAVA_SRC_DIR)/%.class: $(JAVA_SRC_DIR)/%.java
	$(JC) $(JFLAGS) $<

# Clean build files
clean:
	rm -f $(C_EXEC) $(C_OBJS) $(JAVA_CLASSES)

.PHONY: all clean