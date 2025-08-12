# ⚡ Karatsuba Multiplication Algorithm (C Implementation)

Karatsuba's algorithm is a **divide-and-conquer** method for multiplying two large integers faster than the standard `O(n²)` gradeschool algorithm.  
It achieves a time complexity of approximately **O(n^1.585)**, making it significantly faster for large inputs.


## 🧠 Algorithm Overview

Given two `n`-digit numbers `x` and `y`, Karatsuba works as follows:

1. **Split** each number into two halves:
    - `x = a*10^n + b`
    - `y = c*10^n + d`
2. **Compute:**
- `ac` – product of the high parts
- `bd` – product of the low parts
- `(a + b)(c + d) - ac - bd` – the "cross term"
3. Combine results to get the final product.

This reduces the number of multiplications from **4** to **3**, giving a faster runtime.

## 📂 Files
- `add.c` - Large integer addition
- `karatsuba.c` - Core recursive algorithm
- `subtract.c` - Large integer subtraction
- `utils.c` - Helper functions (e.g., string trimming, padding)
- `main.c` - Entry point, handles input, output

## 🛠 Build & Run

### Build
```bash
cd ../..
make karatsuba
```
### Run
```bash
cd divide_and_conquer/karatsuba
./karatsuba < input.txt
```

**Note:** the input should end with a new line!
