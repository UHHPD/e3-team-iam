#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double poisson(double mu, int k) {
    return pow(mu,k)*exp(-mu)/tgamma(k+1);
}

double prob(vector<int> daten, double mu){
  double likelihood = 1;
  for(int k : daten){
    likelihood *= poisson(mu, k);
  }
  return likelihood;
}


int main() 
{

    vector<int> daten;
    ifstream fin("datensumme.txt");
    int zahl;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> zahl;
        daten.push_back(zahl);
    }
    fin.close();

    double mean = 3.11538;
    double likelihood_mean;
    likelihood_mean = prob(daten, mean);
    cout << likelihood_mean << endl;
    
}