#!/usr/bin/env bash

# =============================================================================
# File Name: docker_un_sudo.sh
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 21 Nov 2019 10:46:58 PM CST
# =============================================================================


set -x
# set -e


sudo usermod -aG docker $USER
sudo groupadd docker
sudo gpasswd -a $USER docker
sudo service docker restart
newgrp docker

