//Button Keyboard!
bool debug = false;
int programButton = 12;
uint8_t buf[8] = { 
  0 };
  
void setup() {
  Serial.begin(9600);
  pinMode(programButton, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  if (digitalRead(programButton) == HIGH) {
    digitalWrite(13, LOW); //Button Not Pressed
  } else {
    digitalWrite(13, HIGH); //Button Pressed
    printChar('K');
    printChar('u');
    printChar('r');
    printChar('t');
    printChar('s');
    printChar(' ');
    printChar('A');
    printChar('r');
    printChar('d');
    printChar('u');
    printChar('i');
    printChar('n');
    printChar('o');
    printChar(' ');
  }
}

void printChar(char CHR){
  bool shift = true;
  int numHID = 0;
  int SHIFT_KEY = 225;

  if (CHR > 96){
    if (CHR < 126){
      shift = false; //Lowercase Range
    }
  } else {
    if (CHR > 64){
      if (CHR < 91){
        CHR = CHR + 32; //Only 'lowercase' uppercase letters
      }
    }
  }

  //Array used to find HID #
  char key[73] = {
    '`', //0 - Nothing
    '`', //1
    '`', //2
    '`', //3
    'a', //4
    'b', //5
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    '0',
    '`', //40 - Return
    '`', //41 - Escape
    '`', //42 - Delete
    '`', //43 - Tab
    ' ', //44 - Space
    '-', //45
    '=', //46
    '[', //47
    ']', //48
    '`', //49 - "\"
    '`', //50 - Non US
    ';', //51
    '`', //52 - '
    '~', //53
    ',', //54
    '.', //55
    '/', //56
    '`', //57 - CAPS
    //-----------------------
    //Custom Added (SHIFTERS)
    //-----------------------
    '_', //58 - Underscore: 58 -> SHIFT + 45
    '+', //59 - Plus: 59 -> SHIFT + 46
    '{', //60 - Curl: 60 -> SHIFT + 47
    '}', //61 - Curl: 61 -> SHIFT + 48
    '!', //62 - EXCLAM: 62 -> SHIFT + 30
    '@', //63 - AT: 63 -> SHIFT + 31
    '#', //64 - NUM: 64 -> SHIFT + 32
    '$', //65 - DOL: 65 -> SHIFT + 33
    '%', //66 - PER: 66 -> SHIFT + 34
    '^', //67 - CAR: 67 -> SHIFT + 35
    '&', //68 - AMP: 68 -> SHIFT + 36
    '*', //69 - AST: 69 -> SHIFT + 37
    '(', //70 - PAR: 70 -> SHIFT + 38
    ')', //71 - PAR: 71 -> SHIFT + 39
    ':', //72 - Col: 72 -> SHIFT + 51
  };

  //Find char in Array
  for(int i = 0; i < 73; i++){
    if (debug){
      Serial.print("CHAR: ");
      Serial.print(CHR);
      Serial.print(" curKey: ");
      Serial.println(key[i]);
    }
    if (CHR == key[i]){
      numHID = i;
      break;
    }
  }

  if (debug)
    Serial.print(numHID);

  if (!debug){
    //Determine HID Out
    if (numHID < 57){ //'Normal' Mappings
      if (shift){ //Capital
        sendHID(SHIFT_KEY);
        sendHID(numHID);
        releaseKey();
      } else { //Lower
        sendHID(numHID);
        releaseKey();
      }
    } else { //'Custom' Mappings
      //Not Yet Implemented... (Types a ~ in place)
      sendHID(53);
      releaseKey();
    }
  }
}

void sendHID(int key){
  buf[2] = key;
  Serial.write(buf, 8);
  releaseKey();
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);  // Release key  
}


