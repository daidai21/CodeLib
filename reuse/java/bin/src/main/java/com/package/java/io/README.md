
# `java.io.*`

**按照操作单元划分**

* 字符流: 读取单个字符，用来处理文本文件
    * Reader
        * BufferedReader
        * InputStreamReader
            * FileReader
        * PipedReader
        * CharArrayReader
        * FilterReader
            * PushbackReader
    * Writer
        * BufferedWriter
        * OutputStreamWriter
            * FileWriter
        * PrinterWriter
        * StringWriter
        * PipedWriter
        * CharArrayWriter
        * FilterWriter
* 字节流: 读取单个字节，用来处理二进制文件
    * InputStream
        * FileInputStream
        * FilterInputStream
            * BufferedInputStream
            * DataInputStream
            * PushbackInputSteam
        * ObjectInputStream
        * PipedInputStream
        * SequenceInputStream
        * StringBufferInputStream
        * ByteArrayInputStream
    * OutputStream
        * FileOutputStream
        * FilterOutputStream
            * BufferedOutputStream
            * DataOutputStream
            * PrintStream
        * ObjectOutputStream
        * PipedOutputStream
        * ByteArrayOutputStream

**按照流的角色划分**

* 处理流
    * 缓冲操作
    * 基本数据类型操作
    * 对象序列化操作
    * 转化控制
    * 打印控制
* 节点流
    * 文件操作
    * 管道操作
    * 数组操作


[ref](https://docs.oracle.com/javase/8/docs/api/java/io/package-summary.html)
