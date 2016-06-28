
/*
 * If you connect NB and arduino TX/RX by RS232( or usb to rs232)
 * You will get /dev/ttyUSB1 if the system will detect the hardware (USB to RS232)
 * You can use the command "lsusb" to check and you will get the information "Bus 006 Device 003: ID 067b:2303 Prolific Technology, Inc. PL2303 Serial Port"
 * 
 * Arduino device will be detected to /dev/ttyUSB0
 * 
 * Open gtkterm to show the message from NB to arduino, then arduino to NB
 * gtkterm -p /dev/ttyUSB1 -s 9600&
 * 
 * Send the message to /dev/ttyUSB1, then arduino will get such the information and pass to NB
 * echo "I am Nelson" > /dev/ttyUSB1
 */

int incomingByte = 0;   // for incoming serial data

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    // For TX1, RX1
    Serial1.begin(9600);
    // For TX2, RX2
    Serial2.begin(9600);
    // For TX3, RX3
    Serial3.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:
    if ( Serial.available() > 0 ){
        incomingByte = Serial.read();
        Serial.print("I recevied: ");
        Serial1.print(incomingByte, HEX);
        Serial1.print("\n");
    }

    //一次針對三個Serial1, 2, 3都使用available偵測是否有資料進來，如果有，就用write的方式，將讀到的值寫回去。
    if ( Serial1.available() > 0 ){
        incomingByte = Serial1.read();
        Serial1.write(incomingByte);
    }

    if ( Serial2.available() > 0 ){
        incomingByte = Serial2.read();
        Serial2.write(incomingByte);
    }

    //Serial3.print("test"); //no any write to NB
    if ( Serial3.available() > 0 ){
        incomingByte = Serial3.read();
        Serial3.write(incomingByte);
    }
}
