#!/bin/bash

# SUNGUR Optimized GStreamer Pipeline Template
# Jetson/Orin serisi cihazlarda donanım hızlandırmalı video işleme için tasarlanmıştır.

# 1. USB Kamera üzerinden NVMM (Donanım Belleği) kullanarak 1080p@30fps H.264 Yayını
# udpsink ile yer istasyonuna veri gönderir.

DEVICE="/dev/video0"
REMOTE_IP="192.168.1.100"
REMOTE_PORT=5000

echo "SUNGUR Video Pipeline başlatılıyor: $DEVICE -> $REMOTE_IP:$REMOTE_PORT"

gst-launch-1.0 v4l2src device=$DEVICE ! \
    "video/x-raw, width=1920, height=1080, framerate=30/1" ! \
    nvvidconv ! \
    "video/x-raw(memory:NVMM), format=NV12" ! \
    nvv4l2h264enc bitrate=4000000 insert-sps-pps=true ! \
    rtph264pay ! \
    udpsink host=$REMOTE_IP port=$REMOTE_PORT sync=false
