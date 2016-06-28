
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
char data[21];

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
        Serial.print(incomingByte, HEX);
        Serial.print("\n");
    }

    //一次針對三個Serial1, 2, 3都使用available偵測是否有資料進來，如果有，就用write的方式，將讀到的值寫回去。
    //用Serial1好像會怪怪的
    while ( Serial2.available() > 0 ){
        //int number_of_bytes_received = Serial2.readBytesUntil (13,data,20);
        int number_of_bytes_received = Serial2.readBytesUntil ('0',data,20);
        data[number_of_bytes_received]=0;
        bool result = strcmp (data, "IamNelson");
        if (result == 0)
        {
            Serial2.write("ok\n");
        } 
        else 
        {
            Serial2.write("not ok\n");
        }

    }
}
