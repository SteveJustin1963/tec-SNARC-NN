#include <stdio.h>

#define NUM_INPUT_NEURONS 8
#define NUM_HIDDEN_NEURONS 4
#define NUM_OUTPUT_NEURONS 1

#define DECAY_FACTOR_LOW 990 // Decay factor for neurons with low weights (0.99 in integer format)
#define DECAY_FACTOR_HIGH 9990 // Decay factor for neurons with high weights (0.999 in integer format)
#define THRESHOLD 500 // Threshold to determine low-weight neurons (0.5 in integer format)

// Function to update weights using the Hebbian rule
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
    int hidden_weights[NUM_HIDDEN_NEURONS] = {1000}; // Initialize hidden layer weights (1.0 in integer format)
    int output_weights[NUM_OUTPUT_NEURONS] = {500}; // Initialize output layer weights (0.5 in integer format)
    int hidden_output, final_output;

    // Forward pass
    hidden_output = (input_pattern[0] * hidden_weights[0]) / 1000;
    final_output = (hidden_output * output_weights[0]) / 1000;

    // Calculate error signal or delta_out (depends on the specific problem)

    // Update weights
    updateWeights(hidden_weights, input_pattern, final_output, NUM_HIDDEN_NEURONS);
    updateWeights(output_weights, &hidden_output, final_output, NUM_OUTPUT_NEURONS);

    return 0;
}
