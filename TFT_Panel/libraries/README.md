# Arduino UTFT libraries_
## 需要做哪些事

將三個目錄 - "UTFT  UTFT_Buttons  UTouch" 複製到arduino的libraries裡面

For example:

以arduino-1.6.9為例

ls $HOME/arduino-1.6.9
*********************************
arduino  arduino-builder  dist  examples  hardware  install.sh  java  lib  libraries  reference  revisions.txt  tools  tools-builder  uninstall.sh
*********************************

cp -ar libraries\UTFT $HOME/arduino-1.6.9/libraries/
cp -ar libraries\UTFT_Buttons $HOME/arduino-1.6.9/libraries/
cp -ar libraries\UTouch $HOME/arduino-1.6.9/libraries/
