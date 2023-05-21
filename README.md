

"Marvin Minsky's SNARC, Possibly the First Artificial Self-Learning Machine
1952

![image](https://github.com/SteveJustin1963/tec_NN-SNARC/assets/58069246/3a54d71d-01f3-4297-a941-c6657b89cd1c)


In 1951, Marvin Minsky and Dean Edmonds developed SNARC, the first artificial neural network. It simulated a rat navigating a maze and had 40 neurons that adjusted synapse weights using Hebbian learning. The machine had a random wiring design and allowed multiple rats to interact and learn from each other. SNARC used reinforcement to reward correct choices and observers could monitor progress through a light network. Minsky's machine was built before digital computers and he initially doubted their learning potential.

![image](https://github.com/SteveJustin1963/tec-NN-SNARC/assets/58069246/e24943a2-ae61-4d13-9720-baf880d076fe)

## Hebbian learning
Hebbian learning is an important rule used in artificial neural networks, inspired by how our brains work. It was developed by Donald Hebb, a psychologist, in 1949.

The main idea behind Hebbian learning is that the strength of connections between neurons is adjusted based on their coordinated activity. In simple terms, "neurons that fire together wire together." When one neuron consistently fires just before another neuron, the connection between them becomes stronger.

The mathematical formula for Hebbian learning can vary, but a common representation is:

`Δw = η * x_pre * x_post`

Here's what it means:

- Δw represents the change in the strength of the connection, known as the synaptic weight.
- η is the learning rate, which determines how much the weight should change.
- x_pre is the output of the neuron sending the signal, called the presynaptic neuron.
- x_post is the output of the neuron receiving the signal, called the postsynaptic neuron.

or The Hebbian rule is based on the rule that the weight vector increases proportionally to the input and learning signal i.e. the output. The weights are incremented by adding the product of the input and output to the old weight. `W (new) = w (old) +x*y`

This rule suggests that if both the presynaptic and postsynaptic neurons are active at the same time, the weight between them increases. This means that the presynaptic neuron will have a stronger influence on the postsynaptic neuron's future activity.

Hebbian learning is commonly used in unsupervised learning, where neural networks learn patterns and associations without specific targets. It helps networks capture statistical regularities and correlations in the data.

However, Hebbian learning has some limitations. One challenge is its potential to amplify noise or irrelevant patterns in the data, as it reinforces any coincidental connections. This is known as the stability-plasticity dilemma.

To overcome this challenge, researchers have proposed modifications to the basic Hebbian learning rule. These modifications include introducing a decay factor to prevent excessive growth of connection strengths, setting activation thresholds to control learning, or implementing competition among neurons to select the most relevant connections.

These modifications aim to find a balance between maintaining stable learned representations and adapting to new patterns and inputs.
## code
`hebb-1.c`





## REF
- https://www.historyofinformation.com/detail.php?entryid=4343
- https://en.wikipedia.org/wiki/Stochastic_Neural_Analog_Reinforcement_Calculator

