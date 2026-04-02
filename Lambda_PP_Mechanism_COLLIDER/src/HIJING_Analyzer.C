#define HIJING_Analyzer_cxx
#include "HIJING_Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include "P_Lambda.h"
#include "constants.h"
void HIJING_Analyzer::Loop(){
   //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''Histogram stuff'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
   TH1D *h1D_inclusive_particle_pT_distribution          = new TH1D("h1D_inclusive_particle_pT_distribution","h1D_inclusive_particle_pT_distribution",400,0,100);
   TH1D *h1D_lambda_pT_distribution                      = new TH1D("h1D_lambda_pT_distribution","h1D_lambda_pT_distribution",400,0,100);
   TH1D *h1D_inclusive_particle_rapidity_distribution    = new TH1D("h1D_inclusive_particle_rapidity_distribution","h1D_inclusive_particle_rapidity_distribution",100,-10,10); 
   TH1D *h1D_lambda_rapidity_distribution                = new TH1D("h1D_lambda_rapidity_distribution","h1D_lambda_rapidity_distribution",100,-10,10);
   

   TH1D *h1D_inclusive_particle_eta_distribution         = new TH1D("h1D_inclusive_particle_eta_distribution","h1D_inclusive_particle_eta_distribution",200,-20,20);
   TH1D *h1D_lambda_eta_distribution                     = new TH1D("h1D_lambda_eta_distribution","h1D_lambda_eta_distribution",200,-20,20);  
   TH1D *h1D_lambda_xF_distribution                      = new TH1D("h1D_lambda_xF_distribution","h1D_lambda_xF_distribution",200,-1,1);
   

   //inclusive_particle_delta_phi = phi_particle - phi_b 
   TH1D *h1D_inclusive_particle_delta_phi[rapidity_bin];
   //lambda_particle_delta_phi = phi_lambda - phi_b
   TH1D *h1D_lambda_delta_phi[rapidity_bin];

   //inclusive_particle cos(delta_phi) 
   TH1D *h1D_inclusive_particle_cos_delta_phi[rapidity_bin];
   //lambda cos(delta)
   TH1D *h1D_lambda_cos_delta_phi[rapidity_bin];


   
   for(int i_temp = 0; i_temp < rapidity_bin;i_temp++){
      h1D_inclusive_particle_delta_phi[i_temp]      =  new TH1D(Form("h1D_inclusive_particle_delta_phi_y_%d_%d"     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_delta_phi_y_%d_%d"     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
      h1D_lambda_delta_phi[i_temp]                  =  new TH1D(Form("h1D_lamdba_delta_phi_y_%d_%d"                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lamdba_delta_phi_y_%d_%d"                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
      h1D_inclusive_particle_cos_delta_phi[i_temp]  =  new TH1D(Form("h1D_inclusive_particle_cos_delta_phi_y_%d_%d" ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_cos_delta_phi_y_%d_%d" ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
      h1D_lambda_cos_delta_phi[i_temp]              =  new TH1D(Form("h1D_lambda_cos_delta_phi_y_%d_%d"             ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_cos_delta_phi_y_%d_%d"             ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
   }
   
   //lambda angle between event plane Phi_1 and phi_proton_star
   TH1D *h1D_Phi_1_phi_proton_star_polarized = new TH1D("h1D_Phi_1_phi_proton_star_polarized","h1D_Phi_1_phi_proton_star_polarized",20,0,2*TMath::Pi());
   TH1D *h1D_sin_Phi_1_phi_proton_star_polarized = new TH1D("h1D_sin_Phi_1_phi_proton_star_polarized","h1D_sin_Phi_1_phi_proton_star_polarized",200,-1,1);
 
   //h1D_sin_Phi_1_phi_proton_star_polarized ->Fill(0);

   //std::vector<std::string> InputFiles;
   //Initialize Lambda_decay_RestFrame;
   Lambda_decay_RestFrame lamda_decay_RF;

   TVector3 n_beam(0.,0.,1.0);
   double sqrt_sNN = 200; //[GeV]

   TRandom3 rnd(0);
   //**************************************ENTER FILE LOOP*********************************
   for(int iFile = 0 ; iFile < InputFiles.size(); iFile++){
      std::cout<<"current iFile: "<<iFile<<std::endl;
      double p_beam = sqrt_sNN/2.0 * 197 ; //[GeV]
      TFile *fin = TFile::Open(InputFiles[iFile].c_str(),"READ");
      if (!fin){
         std::cout<<"Error: Cannot open file "<<std::endl;
      }
      TTree * tree = (TTree*)fin->Get("genEvent");
      if (!tree) {
         cout << "Error: Cannot get tree from file!" << endl;
      }


      Init(tree);
      //******Number of events********
      long long N_events = fChain->GetEntriesFast();
      //*********************************ENTER EVENT LOOP**********************************
      for(int iEvent=0;iEvent<100;iEvent++){
         if (iEvent%1000 == 0 ) std::cout<<"iEvent = " << iEvent <<std::endl;
         fChain->GetEntry(iEvent);
         //Number of particles 
         int N_particle = px->size();
         
         std::vector<TLorentzVector> Lambda_4momentum;
         std::vector<int> Lambda_Index;

         //*********************************ENTER PARTICLE LOOP*****************************
         for(int i_particle=0 ; i_particle < N_particle;i_particle++){
            if( (*status)[i_particle] == 1 ){
               TLorentzVector temp_particle( (*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle] );
               h1D_inclusive_particle_pT_distribution       ->Fill( temp_particle.Pt()        );
               h1D_inclusive_particle_rapidity_distribution ->Fill( temp_particle.Rapidity()  );
               h1D_inclusive_particle_eta_distribution      ->Fill( temp_particle.Eta()       );
               //'''''''''''''''''''''''''''''''''''''''''''''''''
               double delta_phi = temp_particle.Phi() - b_phi ;  
               double cos_delta_phi = TMath::Cos(delta_phi);
               //'''''''''''''''''''''''''''''''''''''''''''''''''

               for(int i_rapidity = 0 ; i_rapidity < rapidity_bin ; i_rapidity++){
                  if( temp_particle.Rapidity() > rapidity_bin_low[i_rapidity] && temp_particle.Rapidity() < rapidity_bin_high[i_rapidity] ){
                     h1D_inclusive_particle_delta_phi[i_rapidity]->Fill(delta_phi);
                     h1D_inclusive_particle_cos_delta_phi[i_rapidity]->Fill(cos_delta_phi);
                  }
               }



            }




            if ( (*pid)[i_particle] == 3122  ){
               TLorentzVector lambda_momentum((*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle]) ;
               Lambda_4momentum.push_back( lambda_momentum  );
               Lambda_Index.push_back(i_particle);
               h1D_lambda_pT_distribution->Fill(       lambda_momentum.Pt()          );
               h1D_lambda_rapidity_distribution->Fill( lambda_momentum.Rapidity()    );
               h1D_lambda_eta_distribution->Fill(      lambda_momentum.Eta()         );
               //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
               double lambda_delta_phi     = lambda_momentum.Phi()-b_phi; 
               double lambda_cos_delta_phi = TMath::Cos(lambda_delta_phi);
               //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            }
         }
         //*********************************END PARTICLE LOOP*****************************
         
         //*********************************ENETR LAMBDA LOOP*****************************
         for(int i_lambda=0;i_lambda<Lambda_Index.size();i_lambda++){
            //calculate the n_polarization of the lambda 
            TVector3 Lambda_3momentum(Lambda_4momentum[i_lambda].X(),Lambda_4momentum[i_lambda].Y(),Lambda_4momentum[i_lambda].Z());
            TVector3 Polarization_direction = ( n_beam.Cross(Lambda_3momentum) ).Unit();
            //calculate the boost vector 
            TVector3 beta(Lambda_4momentum[i_lambda].X()/Lambda_4momentum[i_lambda].T(),Lambda_4momentum[i_lambda].Y()/Lambda_4momentum[i_lambda].T(),Lambda_4momentum[i_lambda].Z()/Lambda_4momentum[i_lambda].T() );



            //calculate xF of the lambda: 
            double xF = TMath::Abs ( Lambda_4momentum[i_lambda].Pz()/p_beam ) ; 
            if (xF>1) std::cout<<"xF = "<<xF << " Pz() "<< Lambda_4momentum[i_lambda].Pz()<<std::endl;
            h1D_lambda_xF_distribution->Fill(xF);
            //calculate the mass of the lambda;
            
            double M_lambda = Lambda_4momentum[i_lambda].M();
            
            // Set Lambda mass and xF
            lamda_decay_RF.set_xF(xF);
            lamda_decay_RF.set_mass_lambda(M_lambda);
            
            double t = lamda_decay_RF.calculate_theta(); // t = cos(\theta)
           
            double theta_proton = TMath::ACos(t);
            
            double phi_proton = rnd.Uniform(0,2*TMath::Pi());

            //construct proton and pion- in the rest frame of lambda, and the direction of z is the p_beam X p_lambda;
            TLorentzVector proton( lamda_decay_RF.P_proton * TMath::Sin(theta_proton) * TMath::Cos(phi_proton),
                                   lamda_decay_RF.P_proton * TMath::Sin(theta_proton) * TMath::Sin(phi_proton),
                                   lamda_decay_RF.P_proton * TMath::Cos(theta_proton)                         , 
                                   lamda_decay_RF.E_proton  
                                 );


            
            TLorentzVector pion_minus( -1.*lamda_decay_RF.P_proton * TMath::Sin(theta_proton) * TMath::Cos(phi_proton),
                                       -1.*lamda_decay_RF.P_proton * TMath::Sin(theta_proton) * TMath::Sin(phi_proton),
                                       -1.*lamda_decay_RF.P_proton * TMath::Cos(theta_proton)                         ,
                                       lamda_decay_RF.E_pion_minus     
                                     );
            
            // Rotate the proton and pion_minus 
            proton.RotateUz(Polarization_direction);
            pion_minus.RotateUz(Polarization_direction);
            //Boost the proton and pion_minus back to the lab frame
            //proton.Boost(beta);
            //pion_minus.Boost(beta);
            // Calculate global polarization
            double phi_proton_star_polarized = proton.Phi();
            //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
            h1D_Phi_1_phi_proton_star_polarized->Fill( b_phi - phi_proton_star_polarized );
            h1D_sin_Phi_1_phi_proton_star_polarized->Fill(  TMath::Sin(b_phi - phi_proton_star_polarized) );
            //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

         }
         //*********************************END LAMBDA LOOP*****************************
         
      }
      //*********************************END EVENT LOOP**********************************
      fin->Close();
      delete fin;
   }
   //**************************************END FILE LOOP************************************

   
   TFile *fout = new TFile(Form("HIJING_sqrt_sNN_%d.root",(int)sqrt_sNN),"RECREATE");
  
   h1D_inclusive_particle_pT_distribution->Write(); 
   
   h1D_lambda_pT_distribution->Write();   
        
   h1D_inclusive_particle_rapidity_distribution->Write();  
   
   h1D_lambda_rapidity_distribution->Write();
     
   
   h1D_inclusive_particle_eta_distribution->Write(); 
   
   h1D_lambda_eta_distribution->Write();
   h1D_lambda_xF_distribution->Write();
   
   
   for(int i_temp = 0; i_temp < rapidity_bin;i_temp++){
      h1D_inclusive_particle_delta_phi[i_temp]     ->Write();
      h1D_lambda_delta_phi[i_temp]                 ->Write();
      h1D_inclusive_particle_cos_delta_phi[i_temp] ->Write();
      h1D_lambda_cos_delta_phi[i_temp]             ->Write();        
   }
   h1D_Phi_1_phi_proton_star_polarized             ->Write();
   h1D_sin_Phi_1_phi_proton_star_polarized         ->Write();
   
   
   
}
