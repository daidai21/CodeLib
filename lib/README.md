
- `c/`
depend on POSIX (exclude STL), all code file suffix name is `.c` or `.h`
- `cc/`

depend STL and POSIX


```bash
gcc -std=c99 -Wall
gcc -std=c11 -Wall
g++ -std=c++11 -Wall -lglog -lpthread -lpthread -lgtest
g++ -std=c++98 -Wall -lglog -lpthread -lpthread -lgtest
```
