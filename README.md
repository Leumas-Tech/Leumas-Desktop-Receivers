# IR Desktop Controller Documentation

## Getting Started

### 1. Download the Code
- Navigate to our GitHub repository.
- Click the green "Code" button, then select "Download ZIP".
- Once downloaded, unzip the folder.

### 2. Selecting Your Version
Based on your hardware, you can choose between:
- **v1** - Just the IR receiver.
- **v2** - IR receiver with the screen.

### 3. Setup in Arduino IDE
- Open the desired version in the Arduino IDE.
- Ensure you've selected the correct board (Arduino Micro).
- Click on the upload button to send the code to your board.

## Programming the Controller for Custom Functions

You have access to 7 functions that allow various actions to be performed. Below is a breakdown of each function and how to use it:

### 1. `printstring(String str)`
Prints a string to the connected computer as if it was typed on a keyboard.
- **Usage**: `printstring("Hello World!");`

### 2. `printstringenter(String str)`
Prints a string and simulates pressing the Enter key.
- **Usage**: `printstringenter("This will be followed by an Enter key press.");`

### 3. `openapp(String appname)`
Simulates opening an application on the connected computer. It uses the system's search function to find and open the app.
- **Usage**: `openapp("Calculator");`

### 4. `searchWebFor(String browser, String url)`
Opens a browser and navigates to the provided URL.
- **Usage**: `searchWebFor("Google Chrome", "https://www.example.com");`

### 5. `keyshortcut2(uint8_t key1, uint8_t key2)`
Simulates a 2-key shortcut.
- **Usage**: `keyshortcut2(KEY_LEFT_CTRL, 'A'); // This selects all text.`

### 6. `keyshortcut3(uint8_t key1, uint8_t key2, uint8_t key3)`
Simulates a 3-key shortcut.
- **Usage**: `keyshortcut3(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 'N'); // This opens a new window in many browsers.`

### 7. `keyshortcut4(uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4)`
Simulates a 4-key shortcut.
**Usage**: `keyshortcut4(KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, 'K'); // Example usage.`

To chain functions or execute multiple commands with a single button press, simply place the desired functions in a sequence:

```cpp
case YOUR_IR_CODE:
  printstring("Hi, this is");
  delay(500); // Optional: Give a brief delay between commands.
  printstringenter("the IR Desktop Controller.");
  openapp("Notepad");
  break;
```cpp

Remote Programming
With v2, you can easily program your device with new remotes:

Point the remote at the IR Desktop Controller.
Press the desired button on the remote.
The IR code will be displayed on the screen.
Note down this code.
Update the main code's switch case with the new IR code to assign functions.
cpp
Copy code
case NOTED_DOWN_IR_CODE:
  printstring("Your custom command here.");
  break;
Additional Information
Our Website: https://www.leumas.tech
Contact: Contact Us
Other Devices: Refer to our website for other innovative devices.
Sources:
Wire Library
SSD1306Ascii
IRremote
Keyboard Library
Purpose
The IR Desktop Controller is designed with a vision to simplify daily computer tasks. With the expansion of technology, desktops are often cluttered with numerous applications and tasks. Our controller provides a unique solution to allow users to seamlessly control and manage their desktop environments with the press of a remote button.

Given the limitations of smaller, low-memory devices, we opted for a design that maximizes functionality without overburdening the system. This approach ensures fast response times, reliability, and the flexibility to be customized by users of all experience levels.

Important Notice
For optimal functionality, this code should be used with an Arduino Micro or another Arduino MCU that supports USB emulation through the Keyboard.h library.
