# this is where espressif tools are installed
ESPRESSIF_INSTALL_LOCATION=/home/ytan86/.espressif
# this is where esp-id source and examples are installed 
IDF_PATH=/home/ytan86/esp/esp-idf

cd $IDF_PATH
. add_path.sh

# run vs code with XTENSA_ESP32_ELF_PATH
XTENSA_ESP32_ELF_PATH=$ESPRESSIF_INSTALL_LOCATION/tools/xtensa-esp32-elf/esp32-2019r1-8.2.0/xtensa-esp32-elf code

# sanity check
#echo $XTENSA_ESP32_ELF_PATH
