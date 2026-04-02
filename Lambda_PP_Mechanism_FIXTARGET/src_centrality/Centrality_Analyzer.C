#define Centrality_Analyzer_cxx
#include "Centrality_Analyzer.h"
#include <TH2D.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLorentzVector.h>
#include "Pythia8/Pythia.h"

using namespace Pythia8;

void Centrality_Analyzer::Loop(){
      double Centrality_Eta_low  = -2.0;
      double Centrality_Eta_high = 0.0;
      charged_multiplicity_Upper = 1000;
      //create PYTHIA8 object
      Pythia pythia;
      ParticleData& pdata = pythia.particleData;
      TH2D *h2D_chagred_multiplicity_impact_parameter = new TH2D("h2D_chagred_multiplicity_impact_parameter","h2D_chagred_multiplicity_impact_parameter",charged_multiplicity_Upper,0,charged_multiplicity_Upper,100,0,15);

      //**************************************ENTER FILE LOOP*********************************
      for(int iFile = 0 ; iFile < InputFiles.size(); iFile++){
         std::cout<<"current iFile: "<<iFile<<std::endl;
         TFile *fin = TFile::Open(InputFiles[iFile].c_str(),"READ");
         if (!fin){
            std::cout<<"Error: Cannot open file "<<std::endl;
            continue;
         }
         TTree * tree = (TTree*)fin->Get("genEvent");
         if (!tree) {
            cout << "Error: Cannot get tree from file!" << endl;
            fin->Close();
            continue;
         }


         Init(tree);
         //******Number of events********
         long long N_events = fChain->GetEntriesFast();
         //*********************************ENTER EVENT LOOP**********************************
         for(int iEvent=0;iEvent<N_events;iEvent++){
            if (iEvent%10000 == 0 ) std::cout<<"iEvent = " << iEvent <<std::endl;
            fChain->GetEntry(iEvent);
            //Number of particles 
            int N_particle = px->size();

            //chagred multiplicity for |eta| < Centrality_Eta_Cut
            int chagred_multi = 0;

            //*********************************ENTER PARTICLE LOOP*****************************
            for(int i_particle=0 ; i_particle < N_particle;i_particle++){
               TLorentzVector temp_particle( (*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle] );
               double temp_particle_eta = temp_particle.Eta();
               double temp_particle_charge = pdata.charge( (*pid)[i_particle]  );
               if( temp_particle_eta < Centrality_Eta_high && temp_particle_eta > Centrality_Eta_low && temp_particle_charge ){
                  chagred_multi ++;
               }
            }
            //*********************************END PARTICLE LOOP*****************************
            h2D_chagred_multiplicity_impact_parameter->Fill(chagred_multi,b);

         }
         //*********************************END EVENT LOOP**********************************
         fin->Close();
         delete fin;
      }
      //**************************************END FILE LOOP************************************

   
      TFile *fout = new TFile(OutputFile.c_str(),"RECREATE");
      h2D_chagred_multiplicity_impact_parameter->Write();
      fout->Close();
      delete fout;
         
}
// END define the Centrality_Analyzer::Loop()




