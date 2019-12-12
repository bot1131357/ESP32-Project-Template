# ESP32-Project-Template

Something that sucked hours of my time trying to figure out how to set up esp-idf with vs code, so I'm sharing it here. 
This work is based on [this example](https://github.com/VirgiliaBeatrice/esp32-devenv-vscode/blob/master/tutorial.md)

To run this:
1) modify two variables:
    ESPRESSIF_INSTALL_LOCATION - where espressif tools are installed
    IDF_PATH - where esp-id source and examples are installed 
2) run startVS.sh on console ". startVS.sh"

## Build commands
In VS code, you can access the build commands through Ctrl+Shift+B where you can select "build, clean, flash, flash and monitor".

## Key takeaways:
### task.json
The build commands are specified in task.json. You can inspect how it's configured and customise it accordingly. 

### To build your own project
Modify main.cpp, and if you need to add other files, be sure to add the src file in CMakeLists.txt (using idf_component_register()).

## Lastly
Have fun!


