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
    
    ofstream fout("likelihood.txt");
    vector<double> mus;
    vector<double> likelihoods;
    for(double m=0; m<=6; m+=0.1){
      double llh = prob(daten, m);
      fout << m << "\t" << llh << endl;
      mus.push_back(m);
      likelihoods.push_back(llh);
    }  
    fout.close();

    ofstream nll("nll.txt");
    vector<double> logLikelihoods;
    for(int i=0; i<mus.size(); ++i){
      double lllh = -2*log(likelihoods[i]);
      nll << mus[i] << "\t\t\t" << lllh << endl;
      logLikelihoods.push_back(lllh);
    }
    nll.close();

}