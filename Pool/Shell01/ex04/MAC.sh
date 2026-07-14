#!bin/sh
ip addr show | grep link/ether | awk '{print $2}'
