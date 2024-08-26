#!/bin/sh

if [ $# -eq 0 ]; then
  echo "Error: An argument is required."
  echo "Usage: $0 [mount|umount]"
  exit 1
fi

DISK=/dev/`diskutil list | grep Keyball | awk '{print $5}'`
MOUNT=/Volumes/keyball

case "$1" in
  "mount")
    sudo mkdir -p $MOUNT
    sudo mount -t msdos $DISK $MOUNT
    ;;
  "umount")
    sudo umount $MOUNT
    ;;
  "help")
    echo "Usage: $0 [mount|umount]"
    ;;
  *)
    echo "Invalid argument: $1"
    echo "Usage: $0 [mount|umount]"
    exit 2
    ;;
esac


