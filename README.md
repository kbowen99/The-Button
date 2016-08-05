# The Button - Test Repo
 Ever wanted to enter a large amount of data (Like a Program or document) but without all that typing? We've got a program for you
 
## How It Works
 1. An Arduino Uno is Programmed with a sketch that allows it to understand HID Codes
 2. Said Arduino then has its USB Chip (ATMEL MEGA16U2) Flashed with a .HEX that makes it appear as an HID compliant Device
 3. Press Button
 
### Reprogramming\Changing Message
 - An Arduino that is already configured as a HID Device must be re-flashed to appear as an Arduino
 
### Goals
 - [x] Typing of PreProgrammed Strings
 - [x] Typing "Basic" Keystrokes (Single Key Presses)
 - [ ] Typing "Advanced" Keystrokes (2+ Key Presses)
 - [ ] Able to "Type" a large amount of characters without data loss
 