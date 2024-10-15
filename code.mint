
```mint
// Constants
40 n !               // Number of neurons
100 /F * lr !        // Learning rate 0.01 (scaled by 10000)
100 i !              // Number of iterations

// Helper functions
:S " * #2710 / ;     // Scale and divide by 10000
:R #FFFF /K & ;      // Simple random number generator

// Initialize weights as a flattened n*n array
n n * m !            // Total number of weights
[ ] w !              // Weights array
m (0 w /A)           // Initialize all weights to 0

// Initialize inputs and outputs arrays
[ ] x ! [ ] y !
n (0 x /A 0 y /A)    // Initialize with zeros

// Weight update function
:U                   // Update weights
  m (
    R x /i n % ? S   // Random * input
    R y /i n / ? S   // Random * output
    * lr S           // * learning rate
    w /i ? +         // Add to existing weight
    w /i !           // Store back into weights
  )
;

// Main Hebbian learning loop
i (
  n (R x /i ! R y /i !)  // Generate random inputs and outputs
  U                      // Update weights
  `Iteration ` /i 1 + . /N  // Print iteration number
)

// Print final weights
`Final weights:` /N
m (
  /i . `: ` w /i ? . /N  // Print index and weight
)

```
