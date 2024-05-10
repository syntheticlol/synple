# Hexadecimal to Executable Converter and Runner

Reconstruct hexadecimal representation of binary data into an executable file and execute it.

### How it works:
1. **Input Format:** Expects an input file containing a single line representing the hexadecimal data.
   
    ```bash
    ./pe2hex.exe -i file.exe -o output
    ```

2. **Conversion:** Converts the hexadecimal string into binary data and stores it in a vector.

3. **Writing to File:** Writes the binary data to an output file named "remade.exe".

4. **Execution:** Attempts to execute the newly created executable essentially letting you have a fileless download executor.

### Usage:
```bash
./file.exe -i <bin_with_hex>
```
Replace <bin_with_hex> with the path to the file containing the hexadecimal representation of binary data.

Note: Assumes the hexadecimal input corresponds to executable binary data. Incorrect or malformed input may lead to unexpected behavior.
