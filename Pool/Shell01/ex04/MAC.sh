#!/bin/bash
ip addr show | grep link/ether | awk '{print $2}'
