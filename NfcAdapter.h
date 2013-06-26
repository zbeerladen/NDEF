#ifndef NfcAdapter_h
#define NfcAdapter_h

#include <Adafruit_NFCShield_I2C.h>
#include <NfcTag.h>
#include <Ndef.h>

// Drivers
#include <MifareClassic.h>
#include <MifareUltralight.h>

#define TAG_TYPE_MIFARE_CLASSIC (0)
#define TAG_TYPE_1 (1)
#define TAG_TYPE_2 (2)
#define TAG_TYPE_3 (3)
#define TAG_TYPE_4 (4)
#define TAG_TYPE_UNKNOWN (99)

#define IRQ   (2)
#define RESET (3)  // Not connected by default on the NFC Shield

class NfcAdapter {
  public:
    NfcAdapter(void);
    ~NfcAdapter(void); 
    void begin(void);
    boolean tagPresent(); // tagAvailable
    NfcTag read();
    boolean write(NdefMessage& ndefMessage);
    // FUTURE boolean share(NdefMessage& ndefMessage);
    // FUTURE boolean unshare();
    // FUTURE boolean erase();
    // FUTURE boolean format();
  private:
    Adafruit_NFCShield_I2C* shield;
    uint8_t uid[7];    // Buffer to store the returned UID
    uint8_t uidLength; // Length of the UID (4 or 7 bytes depending on ISO14443A card type)
    uint8_t guessTagType();
  };

#endif