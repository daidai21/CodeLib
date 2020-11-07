

# MySQL
# start
docker run -itd --name mysql-test\
    -p 3306:3306\
    -e MYSQL_ROOT_PASSWORD=123456 mysql
# enter
docker run --name mysql -p 3306:3306 -e MYSQL_ROOT_PASSWORD=Lzslov123! -d mysql


# 停止的容器可以通过 docker restart 重启
docker restart <容器 ID>


# 停止一个容器
docker stop <容器 ID>


#进入容器
docker exec -it mysql bash
