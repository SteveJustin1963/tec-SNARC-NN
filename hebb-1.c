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
