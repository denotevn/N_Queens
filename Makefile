CC		= g++
TARGET	= NQueens
SRC		= NQueensMain.cpp NQueens.cpp

$(TARGET): $(SRC)
	$(CC) -o $(TARGET) $(SRC)

.PHONY: clean
clean:
	rm -f $(TARGET)