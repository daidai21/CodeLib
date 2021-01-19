# 动态库

1. 生成目标文件 `g++ -fPIC -c say.cpp`
2. 生成动态库，此时要加链接器选项-shared `g++ -shared -o libsay.so say.o`
step1和step2可以合为一个命令：`g++ -fPIC -shared -o libsay.so say.cpp`
3. 使用`g++ main.cpp -L./ -lsay`
