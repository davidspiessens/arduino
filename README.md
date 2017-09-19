# Programming the Arduino without the Arduino IDE
I use a Mac and an Arduino UNO R3. The makefiles work for my setup but might need modification for your setup.
## Installation
### Linux installation (debian)
#### AVR GCC
```
sudo apt install gcc-avr binutils-avr avr-libc
```
#### AVRDUDE
```
sudo apt install avrdude
```
### Mac installation
#### AVR GCC
https://github.com/osx-cross/homebrew-avr/
```
brew tap osx-cross/avr
brew install avr-gcc
```
#### AVRDUDE
``` 
brew install avrdude
```
## Usage
 * cd into the sub-project directory
 * run make to build
 * run make install to copy the build onto the Arduino
```
	cd blink
	make
	make install
```