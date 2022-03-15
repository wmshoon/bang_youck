void loop(){
    if (!mfrc.PICC_IsNewCardPresent() || !mfrc.PICC_ReadCardSerial()){
        delay(500);
        return;
    }

    Serial.print("Card UID:")

    for (byte i=0; i<4; i++) {
        Serial.print(mfrc.uid.uidByte[i]);
        Serial.print(" ");
    }
    Serial.println();
    }
}