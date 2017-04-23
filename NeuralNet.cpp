#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <math.h>

using namespace std;


class Neuron;

typedef vector<Neuron> Layer;


//+++++++++++++++++++++++Connections.h++++++++++++++++++
/*
Connection Prototype, two double fields with two return methods
getWieght (returns the wieght) getDelta (returns the rate of change
in wieht)
*/

class Connections
{
public:
  Connections();
  double getWeight(void) const;
  double getDelta (void) const;
  void setWeight(double newWeight);
  void setDelta(double newDelta);
  void applyDelta(double delta);

private:

  double weight;
  double delta;

};

//++++++++++++++++++++++Connections.cpp++++++++++++++++++++++
/*
Implementation of Connection Prototype
*/

Connections::Connections() { weight = rand() / double(RAND_MAX);}

double Connections::getWeight() const { return weight;}

double Connections::getDelta() const { return delta;}

void Connections::setWeight(double newWeight) { weight = newWeight;}

void Connections::setDelta(double newDelta) { delta = newDelta;}

void Connections::applyDelta(double delta) { weight += delta; }

//+++++++++++++++++++++++++Neuron.h++++++++++++++++++++++
/*
Neuron Prototype, 3 members: output value, a list of outward Connections outputWieghts.
and an index assigned on construcion. 5 methods, feedForward , setOutput, getOutputVal,
getOutputWieghts, getIndex.
*/
class Neuron
{
public:
    Neuron(unsigned numOutputs, unsigned index);
    void feedForward(const Layer &prevLayer);
    void setOutput(double val);
    double getOutputVal(void) const;
    vector<Connections> getOutputWieghts(void) const;
    int getIndex(void) const;
    void calcOutputGradients (double targetVal);
    void calcHiddenGradients (const Layer &nextLayer);
    double getGradient(void) const;
    void updateInputWeights(Layer &prevLayer);

private:
    static double transferFunction(double x);
    static double transferFunctionDerivative(double x);
    static double eta;     // overall net learning rate [0.0....1.0]
    static double alpha;   // momentum [0.0...n] multiplier of last weight change
    double sumDow(const Layer &nextLayer);
    double output;
    vector<Connections> outputWieghts;
    unsigned int n_index;
    double gradient;

};

//+++++++++++++++++++++++++Neuron.cpp+++++++++++++++++++++++

double Neuron::eta = .15;   // Overall net learning rate [0.0-1.0]
double Neuron::alpha = .5;   // momentum multipler of last delta [0.0...n]S

//Private Functions
double Neuron::transferFunction(double x)
{
  //hyoerbolic tangent activation function tanh - output [-1.0 -- 1.0]
  return tanh(x);
}

double Neuron::transferFunctionDerivative(double x)
{
  return 1.0 - pow(x, 2);
}

double Neuron::sumDow(const Layer &nextLayer)
{
  double sum = 0.0;
  // Sum all contributions of the errors to the nodes being fed.

  for(unsigned n = 0; n < nextLayer.size() -1 ; ++n)
  {
    sum += outputWieghts[n].getWeight() * nextLayer[n].getGradient();
  }
  return sum;
}

//Public Functions and Constructor

Neuron::Neuron(unsigned numOutputs, unsigned index)
{
  for(unsigned con = 0; con < numOutputs; ++con)
  {
    outputWieghts.push_back(Connections());
  }

  n_index = index;
}

void Neuron::feedForward(const Layer &prevLayer)
{
  double sum = 0.0;

  for (unsigned n = 0; n <prevLayer.size(); ++n)
  {
    sum += prevLayer[n].getOutputVal() *
            prevLayer[n].getOutputWieghts()[n_index].getDelta();
  }

  output = Neuron::transferFunction(sum);
}

void Neuron::calcOutputGradients (double targetVal)
{
  double delta = targetVal - output;
  gradient = delta * Neuron::transferFunctionDerivative(output);

}


void Neuron::calcHiddenGradients (const Layer &nextLayer)
{
  double dow = sumDow(nextLayer);
  gradient = dow * Neuron::transferFunction(output);
}


void Neuron::updateInputWeights(Layer &prevLayer)
{
  for(unsigned n = 0; n < prevLayer.size(); ++n)
  {
    Neuron &neuron = prevLayer[n];
    double oldDelta = neuron.getOutputWieghts()[neuron.getIndex()].getDelta();

    double newDelta =
     eta * neuron.getOutputVal() * gradient + alpha * oldDelta;

     neuron.getOutputWieghts()[neuron.getIndex()].setDelta(newDelta);
     neuron.getOutputWieghts()[neuron.getIndex()].applyDelta(newDelta);

  }
}


void Neuron::setOutput(double val){output = val; }

double Neuron::getOutputVal(void) const { return output;}

vector<Connections> Neuron::getOutputWieghts(void) const { return outputWieghts;}

int Neuron::getIndex(void) const {return n_index;}

double Neuron::getGradient(void) const { return gradient;}

//+++++++++++++++++++++++++NeuralNet.h+++++++++++++++++

class NeuralNet
{
public:
  NeuralNet(vector<unsigned> &depth);
  void feedForward(const vector<double> &input);
  void backPropagation(const vector<double> &targets);
  void getResults(vector<double> &results) const;

private:
  vector<Layer> net_layers; // net_layers[layerNum][neruonNum]
  double netError;

};

//+++++++++++++++++++++++++NeuralNet.cpp++++++++++++++++++

NeuralNet::NeuralNet(vector<unsigned> &depth)
{
  unsigned numLayers = depth.size();
  for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
  {
    net_layers.push_back(Layer());
    unsigned numOutputs = layerNum == depth.size() - 1 ? 0: depth[layerNum + 1];

    for(unsigned neuronNum = 0; neuronNum <= depth[layerNum]; ++neuronNum)
    {
      net_layers.back().push_back(Neuron(numOutputs, neuronNum));
      cout<< "Nueron Bitch!!" << endl;
    }
  }
  net_layers.back().back().setOutput(1.0);
}

void NeuralNet::feedForward(const vector<double> &input)
{
  assert(input.size() == net_layers[0].size()-1);
  // Fix input values to input neurons.
  for(unsigned i = 0; i< input.size(); ++i)
  {
    net_layers[0][i].setOutput(input[i]);
  }
  //Forward Propagate values through layers.
  for(unsigned layerNum = 1; layerNum < net_layers.size(); ++layerNum)
  {
    Layer &prevLayer = net_layers[layerNum - 1];
    for (unsigned n = 0; n < net_layers[layerNum].size(); ++n)
    {
      net_layers[layerNum][n].feedForward(prevLayer);
    }
  }
}

void NeuralNet::backPropagation(const vector<double> &targets)
{
  // Calculate overall net erro (RMS of output neuron errors)

  Layer &outputLayer = net_layers.back();
  netError = 0.0;
  for(unsigned int n = 0; n < outputLayer.size() - 1; ++n)
  {
    double delta = targets[n] - outputLayer[n].getOutputVal();
    netError += delta;
  }
  netError /= outputLayer.size() - 1;
  netError = sqrt(netError);

  // Calculate output layer gradients.
  for(unsigned n = 0; n < outputLayer.size()-1; ++n)
  {
    outputLayer[n].calcOutputGradients(targets[n]);
  }

  // Calculate gradients of hidden layers
  for(unsigned layerNum = net_layers.size() -2; layerNum > 0; --layerNum)
  {
    Layer &hiddenLayer = net_layers[layerNum];
    Layer &nextLayer = net_layers[layerNum + 1];

    for(unsigned n = 0; n < hiddenLayer.size(); ++n )
    {
        hiddenLayer[n].calcHiddenGradients(nextLayer);
    }
  }

  // Update connection wieghts in all hidden layers
  for(unsigned layerNum = net_layers.size() -1; layerNum > 0; --layerNum)
  {
    Layer &layer = net_layers[layerNum];
    Layer &prevLayer = net_layers[layerNum - 1];

    for(unsigned n = 0; n < layer.size()-1; ++n)
    {
      layer[n].updateInputWeights(prevLayer);
    }
  }
}

void NeuralNet::getResults(vector<double> &results) const
{
  results.clear();
  for (unsigned n = 0; n<net_layers.back().size() - 1; ++n)
  {
    results.push_back(net_layers.back()[n].getOutputVal());
  }
}


//++++++++++++++++++++++++main.cpp++++++++++++++++++++++++

int main()
{
  // depth = {1,2,3}
  vector<unsigned> depth;
  depth.push_back(3);
  depth.push_back(2);
  depth.push_back(1);
  NeuralNet net(depth);
//Training for NeuralNet needs to be in a loop
  vector<double> input;
  input.push_back(4.0);
  input.push_back(2.0);
  input.push_back(1.0);             //input list
  net.feedForward(input);

  vector<double> targets;             //targetValue list
  net.backPropagation(targets);

  vector<double> results;             //result list
  net.getResults(results);

};
