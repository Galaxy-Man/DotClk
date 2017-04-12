#ifndef __CONFIG_H__
#define __CONFIG_H__

typedef char FONTNAME[13 + 1];

<<<<<<< HEAD
typedef struct tagConfigItems
{
=======
>>>>>>> b9b16bd08536ed072f5316c149b5112e4d1fb5d9
    int cfgDST;
    int cfgTimeFormat;
    int cfgBrightness;
    int cfgClockDelay;
    FONTNAME cfgClockFont;
    int cfgDotColour;
} ConfigItems;

class Config
{
  private:
    int cfgCntItems;
    ConfigItems cfgItems;

  private:
    bool readEeprom();
    bool writeEeprom();
    int readBytes(int address, byte *data, size_t len);
    int writeBytes(int address, byte *data, size_t  len);

  public:
<<<<<<< HEAD
    static const int CntItems = 6;
=======
>>>>>>> b9b16bd08536ed072f5316c149b5112e4d1fb5d9

  // DST
  enum {
    CFG_DST_OFF = 0,
    CFG_DST_ON = 1,
  };
  
  // TIME FORMAT
  enum {
    CFG_TF_24HOUR = 0,
    CFG_TF_12HOUR = 1,
    CFG_TF_12HAMPM = 2,  
  };
  
  // CLOCK DELAY
  enum {
    CFG_CD_5SECS = 0,
    CFG_CD_10SECS,
    CFG_CD_15SECS,
    CFG_CD_30SECS,
    CFG_CD_1MIN,
    CFG_CD_2MINS,
    CFG_CD_5MINS,
  };

  // DOT COLOUR
  enum {
    CFG_DC_RED = 0,    
  };
  
  public:
    Config();
    const ConfigItems& GetCfgItems();
    bool SetCfgItems(ConfigItems& cfgItems, bool write = true);
};

extern Config config;

#endif
