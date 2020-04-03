#!/bin/bash


sudo apt-get install hwloc
# sudo apt-get install quota


echo "--------------------------------------------------"
echo "| Operation System Information                   |"
echo "--------------------------------------------------"
# base
echo "----->>----->> OS version and name:"
uname -a

# Computer Information
echo "----->>----->> process tree:"
pstree -a -A -c -l -n -p -u -U -Z
echo "----->>----->> CPU infor:"
lscpu

echo "----->>----->> hostname:"
hostname -s
echo "----->>----->> IP address infor:"
ip addr show
echo "----->>----->> Firewall status:"
sudo ufw status

echo "----->>----->> Port status:"
lsof

# Storage Information
echo "----->>----->> memory infor:"
free -m
echo "----->>----->> disk size:"
df -h


echo "----->>----->> "

