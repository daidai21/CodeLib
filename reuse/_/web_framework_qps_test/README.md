# 

```sh
brew install wrk
```

### Py

##### fastapi

```sh
>>> uvicorn fastapi_example:app --reload --log-level critical

>>> wrk http://127.0.0.1:8000
Running 10s test @ http://127.0.0.1:8000
  2 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     2.64ms  341.26us   5.18ms   83.42%
    Req/Sec     1.90k   215.43     3.86k    83.58%
  38036 requests in 10.10s, 5.15MB read
Requests/sec:   3765.96
Transfer/sec:    522.24KB
```

##### flask

```sh
>>> export FLASK_APP=flask_example.py
>>> flask run

>>> wrk http://127.0.0.1:5000/
Running 10s test @ http://127.0.0.1:5000/
  2 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    11.14ms   14.74ms 131.61ms   94.19%
    Req/Sec   472.67    255.04     1.09k    70.47%
  9244 requests in 10.02s, 1.47MB read
  Socket errors: connect 0, read 3, write 0, timeout 0
Requests/sec:    922.69
Transfer/sec:    150.48KB

>>> unset FLASK_APP
```

##### django

```sh
>>> python3 hello/manage.py runserver

>>> wrk http://127.0.0.1:5000/
Running 10s test @ http://127.0.0.1:8000/
  2 threads and 10 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency     8.45ms    5.48ms  90.14ms   97.86%
    Req/Sec   628.93     77.62   707.00     90.00%
  12528 requests in 10.01s, 3.02MB read
Requests/sec:   1251.51
Transfer/sec:    309.22KB
```

##### Java

随便上w吧....


##### go

比java能快 一半以上吧

##### cpp

TODO
