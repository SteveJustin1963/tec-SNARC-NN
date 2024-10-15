### v1 proto

### v2
This code implements **Hebbian learning**, a simple algorithm inspired by how neurons strengthen their connections. 

---

### **Overview:**
- **Hebbian Learning**: The principle is often summarized as *"neurons that fire together, wire together."* In this case, it modifies the weights between neurons based on the correlation between inputs and outputs.
- **Goal**: This program iteratively updates the weights in a neural network based on random inputs and outputs, strengthening the connections when inputs and outputs are correlated.

---

## **Code Breakdown:**

### **1. Variables and Initialization:**

```mint
40 n !               // Store the number of neurons (n = 40)
100 /F * lr !        // Store the learning rate (0.01 scaled to 10000 for precision)
100 i !              // Store the number of iterations (i = 100)
```
- **`n`**: Number of neurons (40).
- **`lr`**: Learning rate (0.01), scaled to 10000 to work with MINT’s integer-only math.
- **`i`**: Number of iterations for the learning loop.

---

### **2. Helper Functions:**

```mint
:S " * #2710 / ;     // Scales a value by dividing it by 10000
:R #FFFF /K & ;      // Random number generator (bitwise operations)
```
- **`:S`**: This function scales values (useful since we scaled our learning rate earlier). It divides by 10000.
- **`:R`**: Generates random numbers using the maximum 16-bit integer value.

---

### **3. Initialize Weights and Arrays:**

```mint
n n * m !            // Calculate total number of weights (m = n * n)
[ ] w !              // Create an array for weights
m (0 w /A)           // Initialize all weights to 0

[ ] x ! [ ] y !      // Create arrays for inputs (x) and outputs (y)
n (0 x /A 0 y /A)    // Initialize both arrays with zeros
```
- **Weights (w)**: A 2D weight matrix flattened into a 1D array of size `n * n`.
- **Inputs (x)** and **Outputs (y)**: Arrays to store input and output values for each neuron.
- The weights are initialized to **0**.

---

### **4. Weight Update Function:**

```mint
:U                   // Define the weight update function
  m (
    R x /i n % ? S   // Random input, scaled, and stored in x
    R y /i n / ? S   // Random output, scaled, and stored in y
    * lr S           // Multiply input and output by the learning rate
    w /i ? +         // Add to the existing weight
    w /i !           // Store the updated weight back
  )
;
```
- **`:U`**: This function updates the weights between neurons:
  1. **`R x /i n % ?`**: Generates a random input for neuron `i`.
  2. **`R y /i n / ?`**: Generates a random output for neuron `i`.
  3. **`* lr`**: Multiplies the input and output with the learning rate.
  4. **`w /i ? +`**: Adds this result to the current weight value.
  5. **`w /i !`**: Saves the updated weight back into the weights array.

---

### **5. Main Hebbian Learning Loop:**

```mint
i (                   // Loop for 'i' iterations
  n (                 // Loop over 'n' neurons
    R x /i !          // Generate a random input and store in 'x'
    R y /i !          // Generate a random output and store in 'y'
  )
  U                   // Call the weight update function
  `Iteration ` /i 1 + . /N  // Print the iteration number
)
```
- **Outer Loop (`i`)**: Repeats the weight update process for `100` iterations.
- **Inner Loop (`n`)**: For each neuron, generates random input and output values, and stores them in the `x` and `y` arrays.
- **`U`**: Updates the weights using these random inputs and outputs.
- **`/N`**: Prints the current iteration number.

---

### **6. Displaying Final Weights:**

```mint
`Final weights:` /N   // Print a header
m (
  /i . `: ` w /i ? . /N  // For each weight, print the index and value
)
```
- This loop prints the **index** and **value** of each weight in the weights array after training completes.

---

## **How It Works:**

1. **Initialization:** 
   - Creates weights and arrays for storing inputs/outputs.
   - Sets a learning rate and iteration count.

2. **Random Inputs and Outputs:** 
   - Generates random input and output values for each neuron in each iteration.

3. **Updating Weights:** 
   - Updates the weight between each pair of neurons based on the correlation between random input and output values, scaled by the learning rate.

4. **Printing Results:** 
   - After all iterations, the program prints the final weights.

---

## **What This Code Achieves:**
- This is a **simulation of Hebbian learning** with random inputs and outputs.
- It **demonstrates how connections (weights)** between neurons change based on correlated activity, even though the inputs and outputs are random.
- The **final weights** reflect the cumulative changes after 100 iterations of learning.

---

### v3
