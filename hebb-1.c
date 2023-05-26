#include <stdio.h>

#define NUM_INPUT_NEURONS 8
#define NUM_HIDDEN_NEURONS 4
#define NUM_OUTPUT_NEURONS 1

#define DECAY_FACTOR_LOW 990 // Decay factor for neurons with low weights (0.99 in integer format)
#define DECAY_FACTOR_HIGH 9990 // Decay factor for neurons with high weights (0.999 in integer format)
#define THRESHOLD 500 // Threshold to determine low-weight neurons (0.5 in integer format)

void initialize_weights(int weights[], int num_weights, int init_value) {
    for (int i = 0; i < num_weights; i++) {
        weights[i] = init_value;
    }
}

int dot_product(int vec1[], int vec2[], int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += (vec1[i] * vec2[i]) / 1000;
    }
    return result;
}

void updateWeights(int weights[], int inputs[], int output, int num_weights) {
    for (int i = 0; i < num_weights; i++) {
        int w_old = weights[i];
        int x = inputs[i];
        int y = output;

        int decay_factor = (w_old < THRESHOLD) ? DECAY_FACTOR_LOW : DECAY_FACTOR_HIGH;

        int decayed_weight = (w_old * decay_factor + x * y) / 1000;

        weights[i] = decayed_weight;
    }
}

int main() {
    int input_pattern[NUM_INPUT_NEURONS] = {1000, 500, 200, 800, 400, 600, 900, 300};
    int hidden_weights[NUM_HIDDEN_NEURONS];
    int output_weights[NUM_OUTPUT_NEURONS];
    int hidden_output[NUM_HIDDEN_NEURONS], final_output;

    initialize_weights(hidden_weights, NUM_HIDDEN_NEURONS, 1000); 
    initialize_weights(output_weights, NUM_OUTPUT_NEURONS, 500); 

    // Forward pass
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
        hidden_output[i] = dot_product(input_pattern, hidden_weights, NUM_INPUT_NEURONS);
    }
    final_output = dot_product(hidden_output, output_weights, NUM_HIDDEN_NEURONS);

    // Calculate error signal or delta_out (depends on the specific problem)

    // Update weights
    for (int i = 0; i < NUM_HIDDEN_NEURONS; i++) {
        updateWeights(hidden_weights, input_pattern, hidden_output[i], NUM_INPUT_NEURONS);
    }
    updateWeights(output_weights, hidden_output, final_output, NUM_HIDDEN_NEURONS

);

    return 0;
}


\\\\\\\\\\\\\\\\\\\\
sudo code

CONSTANTS:
  NUM_INPUT_NEURONS = 8
  NUM_HIDDEN_NEURONS = 4
  NUM_OUTPUT_NEURONS = 1

  DECAY_FACTOR_LOW = 990
  DECAY_FACTOR_HIGH = 9990
  THRESHOLD = 500

PROCEDURE initialize_weights(weights, num_weights, init_value):
  FOR i FROM 0 TO num_weights:
    weights[i] = init_value
  ENDFOR

PROCEDURE dot_product(vec1, vec2, len):
  result = 0
  FOR i FROM 0 TO len:
    result = result + ((vec1[i] * vec2[i]) / 1000)
  ENDFOR
  RETURN result

PROCEDURE updateWeights(weights, inputs, output, num_weights):
  FOR i FROM 0 TO num_weights:
    w_old = weights[i]
    x = inputs[i]
    y = output
    decay_factor = IF w_old < THRESHOLD THEN DECAY_FACTOR_LOW ELSE DECAY_FACTOR_HIGH
    decayed_weight = ((w_old * decay_factor) + (x * y)) / 1000
    weights[i] = decayed_weight
  ENDFOR

PROCEDURE main:
  input_pattern = ARRAY[1000, 500, 200, 800, 400, 600, 900, 300]
  hidden_weights = ARRAY of size NUM_HIDDEN_NEURONS
  output_weights = ARRAY of size NUM_OUTPUT_NEURONS
  hidden_output = ARRAY of size NUM_HIDDEN_NEURONS
  
  initialize_weights(hidden_weights, NUM_HIDDEN_NEURONS, 1000)
  initialize_weights(output_weights, NUM_OUTPUT_NEURONS, 500)

  // Forward pass
  FOR i FROM 0 TO NUM_HIDDEN_NEURONS:
    hidden_output[i] = dot_product(input_pattern, hidden_weights, NUM_INPUT_NEURONS)
  ENDFOR
  final_output = dot_product(hidden_output, output_weights, NUM_HIDDEN_NEURONS)

  // Calculate error signal or delta_out (depends on the specific problem)

  // Update weights
  FOR i FROM 0 TO NUM_HIDDEN_NEURONS:
    updateWeights(hidden_weights, input_pattern, hidden_output[i], NUM_INPUT_NEURONS)
  ENDFOR
  updateWeights(output_weights, hidden_output, final_output, NUM_HIDDEN_NEURONS)

  RETURN 0
ENDPROCEDURE

\\\\\\\\\\\\\\\\\\\\\\\
forth

variable NUM_INPUT_NEURONS
variable NUM_HIDDEN_NEURONS
variable NUM_OUTPUT_NEURONS

variable DECAY_FACTOR_LOW
variable DECAY_FACTOR_HIGH
variable THRESHOLD

8 NUM_INPUT_NEURONS !
4 NUM_HIDDEN_NEURONS !
1 NUM_OUTPUT_NEURONS !

990 DECAY_FACTOR_LOW !
9990 DECAY_FACTOR_HIGH !
500 THRESHOLD !

: initialize_weights ( weights num_weights init_value -- )
  over ! swap 0 do over over ! cell + loop drop ;

: dot_product ( vec1 vec2 len -- result )
  0 over over 0 do over @ over @ * 1000 / + swap cell + swap cell + loop drop ;

: updateWeights ( weights inputs output num_weights -- )
  0 do over @ THRESHOLD @ < if DECAY_FACTOR_LOW @ else DECAY_FACTOR_HIGH @ then
      over @ * over @ over @ * + 1000 / swap cell + swap cell + loop drop ;

: main
  NUM_INPUT_NEURONS @ cells allocate drop
  NUM_HIDDEN_NEURONS @ cells allocate drop
  NUM_OUTPUT_NEURONS @ cells allocate drop
  NUM_HIDDEN_NEURONS @ cells allocate drop
  NUM_HIDDEN_NEURONS @ cells allocate drop

  NUM_HIDDEN_NEURONS @ 1000 initialize_weights
  NUM_OUTPUT_NEURONS @ 500 initialize_weights

  NUM_HIDDEN_NEURONS @ 0 do over over NUM_INPUT_NEURONS @ dot_product swap cell + loop
  NUM_HIDDEN_NEURONS @ dot_product

  NUM_HIDDEN_NEURONS @ 0 do over over over @ updateWeights swap cell + loop
  NUM_HIDDEN_NEURONS @ updateWeights

  0 ;
\\\\\\\\\\\\\\\\

another


\ Constant Definitions
8 CONSTANT NUM_INPUT_NEURONS
4 CONSTANT NUM_HIDDEN_NEURONS
1 CONSTANT NUM_OUTPUT_NEURONS
990 CONSTANT DECAY_FACTOR_LOW \ Decay factor for neurons with low weights (0.99 in integer format)
9990 CONSTANT DECAY_FACTOR_HIGH \ Decay factor for neurons with high weights (0.999 in integer format)
500 CONSTANT THRESHOLD \ Threshold to determine low-weight neurons (0.5 in integer format)

\ Variable Definitions
VARIABLE hidden_weights NUM_HIDDEN_NEURONS CELLS
VARIABLE output_weights NUM_OUTPUT_NEURONS CELLS
VARIABLE hidden_output NUM_HIDDEN_NEURONS CELLS
VARIABLE final_output

: initialize_weights ( weights addr num-weights init-value -- )
  0 DO
    I CELLS + 0 SWAP !
  LOOP ;

: dot_product ( vec1 addr1 vec2 addr2 len -- result )
  0 SWAP ! \ Initialize result to 0
  0 DO
    I CELLS + @ I CELLS + @ * 1000 / SWAP +
  LOOP ;

: updateWeights ( weights addr1 inputs addr2 output num-weights -- )
  0 DO
    I CELLS + @ DUP THRESHOLD < IF DECAY_FACTOR_LOW ELSE DECAY_FACTOR_HIGH THEN
    I CELLS + @ OVER ROT * + 1000 / SWAP I CELLS + @ * ROT + SWAP !
  LOOP ;

\ Main Function
: main
  \ Variable Definitions
  8 CELLS ALLOT CONSTANT input_pattern
  1000 500 200 800 400 600 900 300 input_pattern NUM_INPUT_NEURONS CELLS ! \ Initialize input pattern

  \ Initialize weights
  hidden_weights NUM_HIDDEN_NEURONS CELLS 1000 initialize_weights
  output_weights NUM_OUTPUT_NEURONS CELLS 500 initialize_weights

  \ Forward pass
  0 DO
    input_pattern hidden_weights NUM_INPUT_NEURONS dot_product
    I CELLS + hidden_output I CELLS + !
  LOOP
  hidden_output NUM_HIDDEN_NEURONS CELLS dot_product final_output !

  \ Calculate error signal or delta_out (depends on the specific problem)

  \ Update weights
  0 DO
    input_pattern hidden_weights NUM_INPUT_NEURONS hidden_output I CELLS + @ updateWeights
  LOOP
  hidden_output NUM_HIDDEN_NEURONS CELLS output_weights NUM_HIDDEN_NEURONS CELLS updateWeights

  0 \ Return value
;

main \ Execute the main function


\\\\\\\\\\\\\\

