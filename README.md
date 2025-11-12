# get_next_line
A function that reads a line from a file descriptor efficiently.  
This is the **fourth project at 1337 (42 Network) school**.

## 🧠 Goal
Implement `get_next_line(int fd)` that returns one line from a file descriptor each time it’s called.  
It must handle:
- Multiple file descriptors at once  
- Arbitrary line lengths  
- Partial reads based on `BUFFER_SIZE`

## ⚙️ Build
```bash
make          # builds get_next_line.o and get_next_line_utils.o
make clean    # removes object files
make fclean   # removes objects + library
make re       # rebuilds everything
