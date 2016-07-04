esptool.py -p /dev/ttyUSB0 erase_flash
esptool.py -p /dev/ttyUSB0 -b 460800 write_flash --flash_size=4m 0 firmware-combined.bin
