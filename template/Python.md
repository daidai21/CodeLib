# Python Project Guide

There are some Python project sample in different branch.

- Python project directory structure sample. [link](https://github.com/daidai21/Python-Project-Guide/tree/project)
- Python project ML/DL (kaggle/tianchi) code and directory structure sample. [link](https://github.com/daidai21/Python-Project-Guide/tree/competition)

### Environment Management

- `conda`
- `pyenv`
- `virtualenv`

### Code Style

You can read the following two documents:

- [Python社区官方建议采用的Python编码风格:PEP8](https://www.python.org/dev/peps/pep-0008/)  [中文版](http://wiki.woodpecker.org.cn/moin/PythonCodingRule)
- [Google SoC 建议的 Python 编码风格:Google Python Style Guide](http://google-styleguide.googlecode.com/svn/trunk/pyguide.html) [中文版](http://www.elias.cn/Python/PythonStyleGuide)

There are some tools can help you.

- Flake8
    - Pyflakes
    - mccabe
    - pycodestyle (pep8)
- Yapf
- Pylint (not good)

### Coverage

check test coverage rate

TODO

### Catelog

### [Code File Structure](./Python.py)

### Main Lib

- Operator System
  - `multiprocessing`
  - `threading`
  - `asyncio`
  - `gc`
  - `sys`
  - `os`
- Network
  - `socket`
- Platform
  - `platform`
- Data Structure
  - `collections`
  - `queue`
  - `numpy`
  - `pandas`
- OOP
  - `abc`
- CPython Version
  - `__future__`
- Test
  - `unittest`
  - `docstest`
  - `line_profiler`
  - `memory_profiler`
  - `profile`
  - `cProfile`
- Compute
  - `decimal`
- Time
  - `time`
- Log
  - `logging`
- Other
  - `warnings`
  - `argparse`
  - `itertools`
  - `hashlib`
  - `contextlib`
  - `tqdm`
  - `dis`
  - `cffi`

### Special Annotation

- `XXX` Warning about possible pitfalls.
- `HACK` Not very well written or malformed code to circumvent a problem/bug. 
- `FIXME` This works, sort of, but it could be done better. (usually code written in a hurry that needs rewriting).
- `TODO` There are functions that are not completed.

Python alone possess

- `# noqu`  No Quality Assurance

### Unit Testing

There are some tools can help you.

- mypy(static type checking)
- PyUnit
- Pytest
- etc.


### Performance Bottleneck Testing

- `timeit`
- `profile`
- `cProfile`
- `line_profile`
- `memory_profiler`
- `objgraph`

### Pack

Python has a dedicated module packaging system named [distutils](http://docs.python.org/library/distutils.html). You can use this mechanism to package and distribute your code to [Pypi](http://pypi.python.org/pypi), So anyone can install your module with `pip` or `easy_install`. Of course, you can also refer to [Python 打包指南](https://www.ibm.com/developerworks/cn/opensource/os-pythonpackaging/) or [Creating a Source Distribution](https://docs.python.org/release/3.1.5/distutils/sourcedist.html#manifest).

### ReadTheDocs

Using ReadTheDocs record.

### Version Named

`Major_Version_Number.Minor_Version_Number[.Revision_Number[.Build_Number]]`

- `Major`: Under the same name, but program with different Major Version Number are not interchangeable.
- `Minor`: Backward compatibility
- `Build`: Recompilation of the same source
- `Revision`: repair bug

### Reference Link

- [Sample Module Repository](https://github.com/kennethreitz/samplemod)
- [结构化您的工程](https://pythonguidecn.readthedocs.io/zh/latest/writing/structure.html)
- [python空项目](https://github.com/onlytiancai/pyempty)
- [如何编写高质量的python程序](https://github.com/onlytiancai/codesnip/blob/master/mypost/How_to_write_high-quality_python_program.md#%E5%A6%82%E4%BD%95%E7%BC%96%E5%86%99%E9%AB%98%E8%B4%A8%E9%87%8F%E7%9A%84python%E7%A8%8B%E5%BA%8F)
- [Web.py](https://github.com/webpy/webpy)
- [Python单元测试框架](http://pyunit.sourceforge.net/pyunit_cn.html)

### CopyRight

You can look, fork or reprint, but the copyright belongs to individual, reprint please indicate the source.`daidai21@github`
