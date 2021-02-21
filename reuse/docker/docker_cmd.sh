

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

# 运行Ubuntu镜像
docker run -it ubuntu /bin/bash

# 查看本地已有的镜像
docker images

# 查看本地已有的镜像
docker image ls

# 查看某个镜像的详细信息
docker inspect <image_name>
