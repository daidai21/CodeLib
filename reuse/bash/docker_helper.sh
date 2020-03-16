#!/usr/bin/env bash


set -x
# set -e


echo "needn't sudo"
sudo usermod -aG docker $USER
sudo groupadd docker
sudo gpasswd -a $USER docker
sudo service docker restart
newgrp docker
sudo chmod 777 /var/run/docker.sock


echo "install docker GUI"
docker volume create portainer_data
docker run -d -p 9000:9000 -p 8000:8000 --name portainer --restart always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer

