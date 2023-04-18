# CaesarsCipher
The Caesars Cipher algorithm is very simple, it takes in a phrase and encodes it using a certain key, and returns an encoded version of the phrase. Then to get the correct decoded phrase you must enter the encoded phrase and the key that was used to encode it and you will get your original phrase back. It does this by taking each character in the phrase and mapping it to an integer value and, depending on the key, add a certain number to it mapping it to a different character, to get the original character back you simply subtract the number specified by the key. In this project the user will enter their phrase into the terminal running on the ARM processor, choosing whether to encode or decode. Then they will set the key by using the first four switches, the key will be displayed on the first two 7 segment displays (using a BCD decoder to display the correct numbers). Then the program will map each character in the phrase to a number, turn that number to binary, and pass the number to the FPGA where the Caesars Cipher algorithm (which will just be a parallel adder/subtractor) using 8 GPIO pins, as well as another to select whether encoding or decoding. Then the program will read the output pins from the FPGA to get the encoded value, map the new number to its new character, and build the new phrase.
# System Design:
<img width="720" alt="image" src="https://user-images.githubusercontent.com/82002017/226688870-25771f0c-45cb-4b68-b303-8fecd08ccc5f.png">

# Application Design:
<img width="403" alt="image" src="https://user-images.githubusercontent.com/82002017/226689014-3ee1a5a4-46af-4c3d-85e5-e64f9e2de7c7.png">

# Final Circuit Diagrams:
<img width="494" alt="image" src="https://user-images.githubusercontent.com/82002017/226689122-73fbe544-c9f2-40cc-b60f-f0e85b68433d.png">
<img width="720" alt="image" src="https://user-images.githubusercontent.com/82002017/226689145-674d35b8-7fb9-4eab-b505-e1fefe439507.png">

# Pin Assignments:
<img width="363" alt="image" src="https://user-images.githubusercontent.com/82002017/226689203-a2a0e0ed-0d55-4e52-816b-98ef6f11df1c.png">

# Resources:
DE10-Standard Intel Board
