#define JAM1_Analyzer_cxx
#include "JAM1_Analyzer.h"
#include <TH2D.h>
#include <TH1D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLorentzVector.h>
#include "P_Lambda.h"
#include "constants.h"
#include "Pythia8/Pythia.h"

using namespace Pythia8;

void JAM1_Analyzer::Loop(){
      Pythia pythia;
      ParticleData& pdata = pythia.particleData;
      int centrality_10 = 0;
      int centrality_20 = 0;
      int centrality_40 = 0;
      int centrality_50 = 0;
      if( sqrt_sNN > (7.7 - 0.0001) && sqrt < (7.7 + 0.0001) ){
         centrality_10 = centrality_10_sqrt_sNN_7_7;
         centrality_20 = centrality_20_sqrt_sNN_7_7;
         centrality_40 = centrality_40_sqrt_sNN_7_7;
         centrality_50 = centrality_50_sqrt_sNN_7_7;

      }

      if( sqrt_sNN > (11.5 - 0.0001) && sqrt < (11.5 + 0.0001) ){
         centrality_10 = centrality_10_sqrt_sNN_11_5;
         centrality_20 = centrality_20_sqrt_sNN_11_5;
         centrality_40 = centrality_40_sqrt_sNN_11_5;
         centrality_50 = centrality_50_sqrt_sNN_11_5;

      }

      //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''Histogram stuff'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
      //pT distribution 
      TH1D *h1D_inclusive_particle_pT_distribution          = new TH1D("h1D_inclusive_particle_pT_distribution","h1D_inclusive_particle_pT_distribution",100,0,10);
      TH1D *h1D_lambda_pT_distribution                      = new TH1D("h1D_lambda_pT_distribution","h1D_lambda_pT_distribution",100,0,10);
      //rapidity distribution
      TH1D *h1D_inclusive_particle_rapidity_distribution    = new TH1D("h1D_inclusive_particle_rapidity_distribution","h1D_inclusive_particle_rapidity_distribution",100,-10,10); 
      TH1D *h1D_lambda_rapidity_distribution                = new TH1D("h1D_lambda_rapidity_distribution","h1D_lambda_rapidity_distribution",100,-10,10);
      //rapidity distribution 
      TH1D *h1D_inclusive_particle_eta_distribution         = new TH1D("h1D_inclusive_particle_eta_distribution","h1D_inclusive_particle_eta_distribution",100,-10,10);
      TH1D *h1D_lambda_eta_distribution                     = new TH1D("h1D_lambda_eta_distribution","h1D_lambda_eta_distribution",100,-10,10);  
      //lambda xF distribution 
      TH1D *h1D_lambda_xF_distribution                      = new TH1D("h1D_lambda_xF_distribution","h1D_lambda_xF_distribution",200,-0.1,1.0);
      TH2D *h2D_lambda_xF_rapidity                          = new TH2D("h2D_lambda_xF_rapidity","h2D_lambda_xF_rapidity",200,-0.1,1.0,100,-10,10);




      // in JAM1 generated sample, phi_b = 0 
      //inclusive_particle_delta_phi = phi_particle - phi_b. The following stuffs are determined by reaction plane. 
      TH1D *h1D_inclusive_particle_delta_phi_RP[rapidity_bin];
      //inclusive_particle cos(delta_phi) 
      TH1D *h1D_inclusive_particle_cos_delta_phi_RP[rapidity_bin];
      //The following stuffs are determined by BBC event plane Psi_1(BBC).
      TH1D *h1D_inclusive_particle_delta_phi_BBCEP[rapidity_bin];
      TH1D *h1D_inclusive_particle_cos_delta_phi_BBCEP[rapidity_bin];
      //lambda 
      TH1D *h1D_lambda_delta_phi_RP[rapidity_bin];
      TH1D *h1D_lambda_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_lambda_delta_phi_BBCEP[rapidity_bin];
      TH1D *h1D_lambda_cos_delta_phi_BBCEP[rapidity_bin];
      //pion+ 
      TH1D *h1D_pion_plus_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_plus_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_plus_delta_phi_BBCEP[rapidity_bin];
      TH1D *h1D_pion_plus_cos_delta_phi_BBCEP[rapidity_bin];
      //pion-
      TH1D *h1D_pion_minus_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_minus_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_minus_delta_phi_BBCEP[rapidity_bin];
      TH1D *h1D_pion_minus_cos_delta_phi_BBCEP[rapidity_bin];

      //proton
      TH1D *h1D_proton_delta_phi_RP[rapidity_bin];
      TH1D *h1D_proton_cos_delta_phi_RP[rapidity_bin]; 
      TH1D *h1D_proton_delta_phi_BBCEP[rapidity_bin];
      TH1D *h1D_proton_cos_delta_phi_BBCEP[rapidity_bin];
      
     
      TH1D *h1D_inclusive_particle_y[rapidity_bin];
      TH1D *h1D_lambda_y[rapidity_bin];
      TH1D *h1D_pion_plus_y[rapidity_bin];
      TH1D *h1D_pion_minus_y[rapidity_bin];
      TH1D *h1D_proton_y[rapidity_bin];


   
      for(int i_temp = 0; i_temp < rapidity_bin;i_temp++){
         h1D_inclusive_particle_delta_phi_RP[i_temp]              =  new TH1D(Form("h1D_inclusive_particle_delta_phi_RP_y_%d_%d"             ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_delta_phi_RP_y_%d_%d"           ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_inclusive_particle_cos_delta_phi_RP[i_temp]          =  new TH1D(Form("h1D_inclusive_particle_cos_delta_phi_RP_y_%d_%d"         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_cos_delta_phi_RP_y_%d_%d"       ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         h1D_inclusive_particle_delta_phi_BBCEP[i_temp]           =  new TH1D(Form("h1D_inclusive_particle_delta_phi_BBCEP_y_%d_%d"          ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_delta_phi_BBCEP_y_%d_%d"        ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_inclusive_particle_cos_delta_phi_BBCEP[i_temp]       =  new TH1D(Form("h1D_inclusive_particle_cos_delta_phi_BBCEP_y_%d_%d"      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_cos_delta_phi_BBCEP_y_%d_%d"    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );

         h1D_lambda_delta_phi_RP[i_temp]                          =  new TH1D(Form("h1D_lambda_delta_phi_RP_y_%d_%d"                         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_delta_phi_RP_y_%d_%d"                       ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_lambda_cos_delta_phi_RP[i_temp]                      =  new TH1D(Form("h1D_lambda_cos_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_cos_delta_phi_RP_y_%d_%d"                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         h1D_lambda_delta_phi_BBCEP[i_temp]                       =  new TH1D(Form("h1D_lambda_delta_phi_BBCEP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_delta_phi_BBCEP_y_%d_%d"                    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_lambda_cos_delta_phi_BBCEP[i_temp]                   =  new TH1D(Form("h1D_lambda_cos_delta_phi_BBCEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_cos_delta_phi_BBCEP_y_%d_%d"                ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         
         //pion+
         h1D_pion_plus_delta_phi_RP[i_temp]                       =  new TH1D(Form("h1D_pion_plus_delta_phi_RP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_plus_delta_phi_RP_y_%d_%d"                    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_pion_plus_cos_delta_phi_RP[i_temp]                   =  new TH1D(Form("h1D_pion_plus_cos_delta_phi_RP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_plus_cos_delta_phi_RP_y_%d_%d"                ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         h1D_pion_plus_delta_phi_BBCEP[i_temp]                    =  new TH1D(Form("h1D_pion_plus_delta_phi_BBCEP_y_%d_%d"                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_plus_delta_phi_BBCEP_y_%d_%d"                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_pion_plus_cos_delta_phi_BBCEP[i_temp]                =  new TH1D(Form("h1D_pion_plus_cos_delta_phi_BBCEP_y_%d_%d"               ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_plus_cos_delta_phi_BBCEP_y_%d_%d"             ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         
         
         //pion-
         h1D_pion_minus_delta_phi_RP[i_temp]                      =  new TH1D(Form("h1D_pion_minus_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_minus_delta_phi_RP_y_%d_%d"                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_pion_minus_cos_delta_phi_RP[i_temp]                  =  new TH1D(Form("h1D_pion_minus_cos_delta_phi_RP_y_%d_%d"                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_minus_cos_delta_phi_RP_y_%d_%d"               ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         h1D_pion_minus_delta_phi_BBCEP[i_temp]                   =  new TH1D(Form("h1D_pion_minus_delta_phi_BBCEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_minus_delta_phi_BBCEP_y_%d_%d"                ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_pion_minus_cos_delta_phi_BBCEP[i_temp]               =  new TH1D(Form("h1D_pion_minus_cos_delta_phi_BBCEP_y_%d_%d"              ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_minus_cos_delta_phi_BBCEP_y_%d_%d"            ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         
         
         //proton
         h1D_proton_delta_phi_RP[i_temp]                          =  new TH1D(Form("h1D_proton_delta_phi_RP_y_%d_%d"                         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_proton_delta_phi_RP_y_%d_%d"                       ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_proton_cos_delta_phi_RP[i_temp]                      =  new TH1D(Form("h1D_proton_cos_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_proton_cos_delta_phi_RP_y_%d_%d"                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         h1D_proton_delta_phi_BBCEP[i_temp]                       =  new TH1D(Form("h1D_proton_delta_phi_BBCEP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_proton_delta_phi_BBCEP_y_%d_%d"                    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 20  , 0  , 2*TMath::Pi() );
         h1D_proton_cos_delta_phi_BBCEP[i_temp]                   =  new TH1D(Form("h1D_proton_cos_delta_phi_BBCEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_proton_cos_delta_phi_BBCEP_y_%d_%d"                ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 200 , -1 , 1             );
         
         h1D_inclusive_particle_y[i_temp]                         =  new TH1D(Form("h1D_inclusive_particle_y_%d_%d"                          ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_inclusive_particle_y_%d_%d"                        ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 100  , -1  ,1            );
         h1D_lambda_y[i_temp]                                     =  new TH1D(Form("h1D_lambda_y_%d_%d"                                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_lambda_y_%d_%d"                                    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 100  , -1  ,1            );
         h1D_pion_plus_y[i_temp]                                  =  new TH1D(Form("h1D_pion_plus_y_%d_%d"                                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_plus_y_%d_%d"                                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 100  , -1  ,1            );
         h1D_pion_minus_y[i_temp]                                 =  new TH1D(Form("h1D_pion_minus_y_%d_%d"                                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_pion_minus_y_%d_%d"                                ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 100  , -1  ,1            );
         h1D_proton_y[i_temp]                                     =  new TH1D(Form("h1D_proton_y_%d_%d"                                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )     , Form("h1D_proton_y_%d_%d"                                    ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp])    )   , 100  , -1  ,1            );

      }
   
      //lambda angle between reaction plane Phi_RP and phi_proton_star
      TH1D *h1D_Phi_RP_phi_proton_star_polarized = new TH1D("h1D_Phi_RP_phi_proton_star_polarized","h1D_Phi_RP_phi_proton_star_polarized",20,0,2*TMath::Pi());
      TH1D *h1D_sin_Phi_RP_phi_proton_star_polarized = new TH1D("h1D_sin_Phi_RP_phi_proton_star_polarized","h1D_sin_Phi_RP_phi_proton_star_polarized",200,-1,1);
 
      //lambda angle between event plane Phi_EP and phi_proton_star
      TH1D *h1D_Phi_EP_phi_proton_star_polarized = new TH1D("h1D_Phi_EP_phi_proton_star_polarized","h1D_Phi_EP_phi_proton_star_polarized",20,0,2*TMath::Pi());
      TH1D *h1D_sin_Phi_EP_phi_proton_star_polarized = new TH1D("h1D_sin_Phi_EP_phi_proton_star_polarized","h1D_sin_Phi_EP_phi_proton_star_polarized",200,-1,1);


      //mass distribution of reconstructed lambda from decayed daughters
      TH1D *h1D_reconstructed_lambda_mass_distribution = new TH1D("h1D_reconstructed_lambda_mass_distribution","h1D_reconstructed_lambda_mass_distribution",50,1.1,1.13);
      //mass distribution of lambda 
      TH1D *h1D_lambda_mass_distribution = new TH1D("h1D_lambda_mass_distribution","h1D_lambda_mass_distribution",50,1.1,1.13);
      TH1D *h1D_lambda_mass_distribution_direct = new TH1D("h1D_lambda_mass_distribution_direct","h1D_lambda_mass_distribution_direct",50,1.1,1.13);
      //Full Event Plane 
      TH1D *h1D_Full_BBCEP_Phi = new TH1D("h1D_Full_BBCEP_Phi","h1D_Full_BBCEP_Phi",100,0,TMath::Pi()*2 );
      //Phi (+BBC) - Phi(-BBC)
      TH1D *h1D_Delta_Phi_BBCP_BBCN =new TH1D("h1D_Delta_Phi_BBCP_BBCN","h1D_Delta_Phi_BBCP_BBCN",100,0,TMath::Pi()*2 );
      //Cos ( Phi(+BBC)-Phi(-BBC) )
      TH1D *h1D_Cos_Delta_Phi_BBCP_BBCN =new TH1D("h1D_Cos_Delta_Phi_BBCP_BBCN","h1D_Cos_Delta_Phi_BBCP_BBCN",100,-1,1);


   
      //Initialize Lambda_decay_RestFrame;
      Lambda_decay_RestFrame lamda_decay_RF;

      TVector3 pos_beam(0.,0., 1.0);
      TVector3 neg_beam(0.,0.,-1.0);
      //double sqrt_sNN = 7.7; //[GeV]
      double p_beam = TMath::Sqrt( (sqrt_sNN/2.0)*(sqrt_sNN/2.0)-0.938*0.928 )* 1 ; //[GeV]

      TRandom3 rnd(0);
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
            if (iEvent%100 == 0 ) std::cout<<"iEvent = " << iEvent <<std::endl;
            fChain->GetEntry(iEvent);
            //Number of particles 
            int N_particle = px->size();
         
            std::vector<TLorentzVector> Lambda_4momentum;
            std::vector<int> Lambda_Index;


            int mid_eta_Charged_Multiplicity = 0 ; //used to determine centrality
            double Qx_pos = 0 ;
            double Qy_pos = 0 ; 
            double Qx_neg = 0 ; 
            double Qy_neg = 0 ; 
            
            //Loop particle to determine middle rapidity charged multiplicity,thus centrality
            for(int i_particle=0; i_particle < N_particle;i_particle++){
               TLorentzVector temp_particle( (*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle] );
               double temp_particle_eta = temp_particle.Eta();
               double temp_particle_charge = pdata((*pid)[i_particle]);

                //'''''''''''''''''''''''Determine charged multiplicity at |eta| < 0.5'''''''''''' 
               if( temp_particle_eta > Centrality_eta_low && temp_particle_eta < Centrality_eta_high && temp_particle_charge ){
                  mid_eta_Charged_Multiplicity ++ ;
               }

            }

            //*********************************ENTER PARTICLE LOOP*****************************
            for(int i_particle=0 ; i_particle < N_particle;i_particle++){
               TLorentzVector temp_particle( (*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle] );
               double temp_particle_eta = temp_particle.Eta();
               double temp_particle_charge = pdata((*pid)[i_particle]);
               //'''''''''''''''''''''''''''''Fill Basic Distribution ''''''''''''''''''''''''
               h1D_inclusive_particle_pT_distribution       ->Fill( temp_particle.Pt()        );
               h1D_inclusive_particle_rapidity_distribution ->Fill( temp_particle.Rapidity()  );
               h1D_inclusive_particle_eta_distribution      ->Fill( temp_particle_eta         );


               // The range of phi obtained from TLorentzVector.Phi(): (-pi, pi], convert this range into [0,2pi)
               //''''''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE(fixed)
               double delta_phi = std::fmod(temp_particle.Phi()+2*TMath::Pi(),TMath::Pi()*2) - 0.0;           //''
               double cos_delta_phi = TMath::Cos(delta_phi);     //''
               //''''''''''''''''''''''''''''''''''''''''''''''''''''
               for(int i_rapidity = 0 ; i_rapidity < rapidity_bin ; i_rapidity++){
                  if( temp_particle.Rapidity() > rapidity_bin_low[i_rapidity] && temp_particle.Rapidity() < rapidity_bin_high[i_rapidity] ){
                     if (  temp_particle.Pt() > charged_track_v1_pT_lowCut && TMath::Abs(temp_particle_eta) < TPC_eta ){
                        h1D_inclusive_particle_delta_phi_RP[i_rapidity]->Fill(delta_phi);
                        h1D_inclusive_particle_cos_delta_phi_RP[i_rapidity]->Fill(cos_delta_phi);
                        h1D_inclusive_particle_y[i_rapidity]->Fill(temp_particle.Rapidity());
                     }
                     //lambda
                     if( (*pid)[i_particle] == 3122 && temp_particle.Pt() < lambda_v1_pt_highCut &&  temp_particle.Pt() > lambda_v1_pt_lowCut ) { // no additional cut on eta
                        h1D_lambda_delta_phi_RP[i_rapidity]->Fill(delta_phi);
                        h1D_lambda_cos_delta_phi_RP[i_rapidity]->Fill(cos_delta_phi);
                        h1D_lambda_y[i_rapidity]->Fill(temp_particle.Rapidity());
                     }
                     //Pion+ 
                     if( (*pid)[i_particle] ==  211 && temp_particle.Pt() > charged_pion_v1_pt_lowCut && temp_particle.P() < charged_pion_v1_p_highCut && TMath::Abs(temp_particle_eta) < TPC_eta  ){
                        h1D_pion_plus_delta_phi_RP[i_rapidity]->Fill(delta_phi);
                        h1D_pion_plus_cos_delta_phi_RP[i_rapidity]->Fill(cos_delta_phi);
                        h1D_pion_plus_y[i_rapidity]->Fill(temp_particle.Rapidity());
                     }
                     //Pion- 
                     if( (*pid)[i_particle] == -211 && temp_particle.Pt() > charged_pion_v1_pt_lowCut && temp_particle.P() < charged_pion_v1_p_highCut && TMath::Abs(temp_particle_eta) < TPC_eta  ){
                        h1D_pion_minus_delta_phi_RP[i_rapidity]->Fill(delta_phi);
                        h1D_pion_minus_cos_delta_phi_RP[i_rapidity]->Fill(cos_delta_phi);
                        h1D_pion_minus_y[i_rapidity]->Fill(temp_particle.Rapidity());
                     }
                     //Proton
                     if( (*pid)[i_particle] == 2212 && temp_particle.Pt() > proton_v1_pt_lowCut  && temp_particle.Pt() < proton_v1_pt_highCut && TMath::Abs(temp_particle_eta) < TPC_eta ){
                        h1D_proton_delta_phi_RP[i_rapidity]->Fill(delta_phi);                         
                        h1D_proton_cos_delta_phi_RP[i_rapidity]->Fill(cos_delta_phi); 
                        h1D_proton_y[i_rapidity]->Fill(temp_particle.Rapidity());
                     }

                  }
               }


               //'''''''''''''''''''''''Determine Event Plane Q-vector Using BBC'''''''''''''''''
               //'''''''''''''''''''''''Use energy of particle as weight'''''''''''''''''''''''''
               if( temp_particle_eta > BBCpos_eta_low && temp_particle_eta < BBCpos_eta_high ){
                  Qx_pos = Qx_pos + temp_particle.E() * TMath::Cos( temp_particle.Phi() );
                  Qy_pos = Qy_pos + temp_particle.E() * TMath::Sin( temp_particle.Phi() );
               }

               if( temp_particle_eta > BBCneg_eta_high && temp_particle_eta < BBCneg_eta_low ){
                  Qx_neg = Qx_neg + temp_particle.E() * TMath::Cos( temp_particle.Phi() );
                  Qy_neg = Qy_neg + temp_particle.E() * TMath::Sin( temp_particle.Phi() );
               }
               



               //''''''''''''''''''''''''''''''Identify Lambda Particle '''''''''''''''''''''''
               if ( (*pid)[i_particle] == 3122  ){ // no any cuts here 
                  Lambda_4momentum.push_back( temp_particle  );
                  Lambda_Index.push_back(i_particle);
                  h1D_lambda_pT_distribution->Fill(       temp_particle.Pt()          );
                  h1D_lambda_rapidity_distribution->Fill( temp_particle.Rapidity()    );
                  h1D_lambda_eta_distribution->Fill(      temp_particle.Eta()         );
                  //h1D_lambda_mass_distribution_direct->Fill( (*mass)[i_particle] );
               }

            }
            //*********************************END PARTICLE LOOP*****************************
         
            //**********************************Determine Event plane angle useing Q-vector********************************
            //''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE''''''(fixed)
            //flip the sign of Qy_neg and Qx_neg
            Qy_neg = Qy_neg*(-1);
            Qx_neg = Qx_neg*(-1);
            double Phi_1_pos = TMath::ATan(Qy_pos/Qx_pos); 
            if( Qy_pos >=0 && Qx_pos < 0 ) { Phi_1_pos = Phi_1_pos +   TMath::Pi();}
            if( Qy_pos <=0 && Qx_pos > 0 ) { Phi_1_pos = Phi_1_pos + 2*TMath::Pi();}
            if( Qy_pos <=0 && Qx_pos < 0 ) { Phi_1_pos = Phi_1_pos +   TMath::Pi();}
            double Phi_1_neg = TMath::ATan(Qy_neg/Qx_neg); 
            if( Qy_neg >=0 && Qx_neg < 0 ) { Phi_1_neg = Phi_1_neg +   TMath::Pi();}
            if( Qy_neg <=0 && Qx_neg > 0 ) { Phi_1_neg = Phi_1_neg + 2*TMath::Pi();}
            if( Qy_neg <=0 && Qx_neg < 0 ) { Phi_1_neg = Phi_1_neg +   TMath::Pi();}
            //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''




            // The event plane determined by positive BBC - The event plane determined by negative BBC (flipping the sign)
            //''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE (fixed)
            double Phi_pos_Phi_neg = std::fmod(Phi_1_pos - Phi_1_neg + 2*TMath::Pi(), 2*TMath::Pi() )  ;//''
            //''''''''''''''''''''''''''''''''''''''''''''''''
            // cos (Phi_pos_Phi_neg), used to determine resolution. 
            double Cos_Phi_pos_Phi_neg = TMath::Cos(Phi_pos_Phi_neg);


            //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE (fixed)
            double temp_Qy = Qy_pos+Qy_neg;
            double temp_Qx = Qx_pos+Qx_neg;
            double Phi_EP1 = TMath::ATan( temp_Qy/temp_Qx );
            if( temp_Qy >=0 && temp_Qx < 0 ) { Phi_EP1 = Phi_EP1 +   TMath::Pi();}
            if( temp_Qy <=0 && temp_Qx > 0 ) { Phi_EP1 = Phi_EP1 + 2*TMath::Pi();}
            if( temp_Qy <=0 && temp_Qx < 0 ) { Phi_EP1 = Phi_EP1 +   TMath::Pi();}
            //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

            h1D_Full_BBCEP_Phi ->Fill(Phi_EP1);
            h1D_Delta_Phi_BBCP_BBCN ->Fill(Phi_pos_Phi_neg);
            h1D_Cos_Delta_Phi_BBCP_BBCN ->Fill(Cos_Phi_pos_Phi_neg);



            //*********************************ReENTER PARTICLE LOOP*****************************************************
            for(int i_particle = 0; i_particle < N_particle; i_particle ++){
               TLorentzVector temp_particle( (*px)[i_particle],(*py)[i_particle],(*pz)[i_particle],(*E)[i_particle] );
               double temp_particle_eta = temp_particle.Eta();
               //''''''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE(fixed)
               double temp_particle_Phi = std::fmod(temp_particle.Phi() + TMath::Pi()*2, TMath::Pi()*2 );
               double delta_phi = std::fmod(temp_particle_Phi - Phi_EP1  + TMath::Pi()*2, TMath::Pi()*2  );           //''
               double cos_delta_phi = TMath::Cos(delta_phi);     //''
               //''''''''''''''''''''''''''''''''''''''''''''''''''''
               for(int i_rapidity = 0 ; i_rapidity < rapidity_bin ; i_rapidity++){
                  if( temp_particle.Rapidity() > rapidity_bin_low[i_rapidity] && temp_particle.Rapidity() < rapidity_bin_high[i_rapidity] ){
                     if (  temp_particle.Pt() > charged_track_v1_pT_lowCut && TMath::Abs(temp_particle_eta) < TPC_eta ){
                        h1D_inclusive_particle_delta_phi_BBCEP[i_rapidity]->Fill(delta_phi);
                        h1D_inclusive_particle_cos_delta_phi_BBCEP[i_rapidity]->Fill(cos_delta_phi);
                     }

                     //Pion+ 
                     if( (*pid)[i_particle] ==  211 && temp_particle.Pt() > charged_pion_v1_pt_lowCut && temp_particle.P() < charged_pion_v1_p_highCut && TMath::Abs(temp_particle_eta) < TPC_eta  ){
                        h1D_pion_plus_delta_phi_BBCEP[i_rapidity]->Fill(delta_phi);
                        h1D_pion_plus_cos_delta_phi_BBCEP[i_rapidity]->Fill(cos_delta_phi);
                     }
                     //Pion- 
                     if( (*pid)[i_particle] == -211 && temp_particle.Pt() > charged_pion_v1_pt_lowCut && temp_particle.P() < charged_pion_v1_p_highCut && TMath::Abs(temp_particle_eta) < TPC_eta  ){
                        h1D_pion_minus_delta_phi_BBCEP[i_rapidity]->Fill(delta_phi);
                        h1D_pion_minus_cos_delta_phi_BBCEP[i_rapidity]->Fill(cos_delta_phi);
                     }
                     //Proton
                     if( (*pid)[i_particle] == 2212 && temp_particle.Pt() > proton_v1_pt_lowCut  && temp_particle.Pt() < proton_v1_pt_highCut && TMath::Abs(temp_particle_eta) < TPC_eta ){
                        h1D_proton_delta_phi_BBCEP[i_rapidity]->Fill(delta_phi);                         
                        h1D_proton_cos_delta_phi_BBCEP[i_rapidity]->Fill(cos_delta_phi); 
                     }

                  }
               }



            }
            //*********************************ReEND   PARTICLE LOOP*****************************************************






            //*********************************ENETR LAMBDA LOOP*****************************
            for(int i_lambda=0;i_lambda<Lambda_Index.size();i_lambda++){

               //calculate the n_polarization of the lambda 
               TVector3 Lambda_3momentum(Lambda_4momentum[i_lambda].X(),Lambda_4momentum[i_lambda].Y(),Lambda_4momentum[i_lambda].Z());
               TVector3 Polarization_direction = ( pos_beam.Cross(Lambda_3momentum) ).Unit();
               if(Lambda_4momentum[i_lambda].Z() < 0. ){ Polarization_direction = Polarization_direction*(-1); }
               //else {TVector3 Polarization_direction = ( neg_beam.Cross(Lambda_3momentum) ).Unit();}
               //calculate the boost vector 
               TVector3 beta(Lambda_4momentum[i_lambda].X()/Lambda_4momentum[i_lambda].T(),Lambda_4momentum[i_lambda].Y()/Lambda_4momentum[i_lambda].T(),Lambda_4momentum[i_lambda].Z()/Lambda_4momentum[i_lambda].T() );



               //calculate xF of the lambda: 
               double xF = TMath::Abs ( Lambda_4momentum[i_lambda].Pz()/p_beam ) ; 
               //if (xF>1) std::cout<<"xF = "<<xF << " Pz() "<< Lambda_4momentum[i_lambda].Pz()<<" Pt() "<<Lambda_4momentum[i_lambda].Pt()<<std::endl;
               //h1D_lambda_xF_distribution->Fill(xF);
               //h2D_lambda_xF_rapidity->Fill(xF , Lambda_4momentum[i_lambda].Rapidity());
               
            
               double M_lambda = Lambda_4momentum[i_lambda].M();
               h1D_lambda_mass_distribution->Fill(M_lambda);
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
               //''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEED HERE(fixed)
               double phi_proton_star_polarized = std::fmod ( proton.Phi() + 2*TMath::Pi(),TMath::Pi()*2 );
               //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
               //Boost the proton and pion_minus back to the lab frame
               proton.Boost(beta);
               pion_minus.Boost(beta);
               // Calculate Global Polarization
               //if( TMath::Abs( Lambda_4momentum[i_lambda].Rapidity() ) < lambda_GlobalPol_yCut && Lambda_4momentum[i_lambda].Pt() > lambda_GlobalPol_pT_lowCut  &&  Lambda_4momentum[i_lambda].Pt() < lambda_GlobalPol_pT_highCut && TMath::Abs(proton.Rapidity()) < TPC_eta && TMath::Abs(pion_minus.Rapidity()) < TPC_eta && proton.Pt() > track_pt_low_cut && pion_minus.Pt() > track_pt_low_cut  ){
               if( TMath::Abs( Lambda_4momentum[i_lambda].Rapidity() ) < lambda_GlobalPol_yCut && Lambda_4momentum[i_lambda].Pt() > lambda_GlobalPol_pT_lowCut  &&  Lambda_4momentum[i_lambda].Pt() < lambda_GlobalPol_pT_highCut){
                  // Calculate global polarization
                  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEEDED HERE(fixed)
                  h1D_Phi_EP_phi_proton_star_polarized->Fill( std::fmod (Phi_EP1 - phi_proton_star_polarized + 2*TMath::Pi(),2*TMath::Pi() )  );                     //''
                  h1D_sin_Phi_EP_phi_proton_star_polarized->Fill(  TMath::Sin(Phi_EP1 - phi_proton_star_polarized) );    //''
 
                  h1D_Phi_RP_phi_proton_star_polarized->Fill( std::fmod ( 0  - phi_proton_star_polarized + 2*TMath::Pi(),2*TMath::Pi() ) );
                  h1D_sin_Phi_RP_phi_proton_star_polarized->Fill(  TMath::Sin(0 - phi_proton_star_polarized) );
                  //''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                  h1D_lambda_xF_distribution->Fill(xF);
                  h2D_lambda_xF_rapidity->Fill(xF , Lambda_4momentum[i_lambda].Rapidity());
               }
               // Calculate v1 of lambda 
               if ( Lambda_4momentum[i_lambda].Pt() > lambda_v1_pt_lowCut  && Lambda_4momentum[i_lambda].Pt() < lambda_v1_pt_highCut  ){
                  for(int i_rapidity = 0 ; i_rapidity < rapidity_bin ; i_rapidity++){
                     if( Lambda_4momentum[i_lambda].Rapidity() > rapidity_bin_low[i_rapidity] && Lambda_4momentum[i_lambda].Rapidity() < rapidity_bin_high[i_rapidity] ){
                        //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''MORE ACTION NEEDED HERE (fixed)
                        double temp_Lambda_Phi = std::fmod(Lambda_4momentum[i_lambda].Phi()+TMath::Pi()*2,TMath::Pi()*2);
                        double temp_Lambda_delta_phi_EP = std::fmod(temp_Lambda_Phi -Phi_EP1+TMath::Pi()*2,TMath::Pi()*2);
                        h1D_lambda_delta_phi_BBCEP[i_rapidity]->Fill(                  temp_Lambda_delta_phi_EP      );       //''
                        h1D_lambda_cos_delta_phi_BBCEP[i_rapidity]->Fill(  TMath::Cos( temp_Lambda_delta_phi_EP )    );       //''
                        //'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
                     }
                  }
               }
               //Calculate reconstructed lambda mass 
               h1D_reconstructed_lambda_mass_distribution->Fill( (proton+pion_minus).M()   );

              

            }
            //*********************************END LAMBDA LOOP*****************************
         }
         //*********************************END EVENT LOOP**********************************
         fin->Close();
         delete fin;
      }
      //**************************************END FILE LOOP************************************

   
      TFile *fout = new TFile(OutputFile.c_str(),"RECREATE");
  
      h1D_inclusive_particle_pT_distribution->Write(); 
   
      h1D_lambda_pT_distribution->Write();   
        
      h1D_inclusive_particle_rapidity_distribution->Write();  
   
      h1D_lambda_rapidity_distribution->Write();
     
   
      h1D_inclusive_particle_eta_distribution->Write(); 
   
      h1D_lambda_eta_distribution->Write();
      h1D_lambda_xF_distribution->Write();
      h2D_lambda_xF_rapidity ->Write();
   
      for(int i_temp = 0; i_temp < rapidity_bin;i_temp++){
         h1D_inclusive_particle_delta_phi_RP[i_temp]->Write();
         h1D_inclusive_particle_cos_delta_phi_RP[i_temp]->Write();
         h1D_inclusive_particle_delta_phi_BBCEP[i_temp]->Write();
         h1D_inclusive_particle_cos_delta_phi_BBCEP[i_temp]->Write();
         //lambda 
         h1D_lambda_delta_phi_RP[i_temp]->Write();
         h1D_lambda_cos_delta_phi_RP[i_temp]->Write();
         h1D_lambda_delta_phi_BBCEP[i_temp]->Write();
         h1D_lambda_cos_delta_phi_BBCEP[i_temp]->Write();
         //pion+ 
         h1D_pion_plus_delta_phi_RP[i_temp]->Write();
         h1D_pion_plus_cos_delta_phi_RP[i_temp]->Write();
         h1D_pion_plus_delta_phi_BBCEP[i_temp]->Write();
         h1D_pion_plus_cos_delta_phi_BBCEP[i_temp]->Write();
         //pion-
         h1D_pion_minus_delta_phi_RP[i_temp]->Write();
         h1D_pion_minus_cos_delta_phi_RP[i_temp]->Write();
         h1D_pion_minus_delta_phi_BBCEP[i_temp]->Write();
         h1D_pion_minus_cos_delta_phi_BBCEP[i_temp]->Write();
         //proton
         h1D_proton_delta_phi_RP[i_temp]->Write();
         h1D_proton_cos_delta_phi_RP[i_temp]->Write(); 
         h1D_proton_delta_phi_BBCEP[i_temp]->Write();
         h1D_proton_cos_delta_phi_BBCEP[i_temp]->Write();



         h1D_inclusive_particle_y[i_temp]->Write();
         h1D_lambda_y[i_temp]->Write();
         h1D_pion_plus_y[i_temp]->Write();
         h1D_pion_minus_y[i_temp]->Write();
         h1D_proton_y[i_temp]->Write();
      }


      h1D_Phi_RP_phi_proton_star_polarized->Write();
      h1D_sin_Phi_RP_phi_proton_star_polarized->Write();
 
      
      h1D_Phi_EP_phi_proton_star_polarized->Write();
      h1D_sin_Phi_EP_phi_proton_star_polarized->Write();
      h1D_reconstructed_lambda_mass_distribution->Write();
      h1D_lambda_mass_distribution->Write();
      h1D_lambda_mass_distribution_direct->Write();
      h1D_Full_BBCEP_Phi ->Write();
      h1D_Delta_Phi_BBCP_BBCN ->Write();
      h1D_Cos_Delta_Phi_BBCP_BBCN ->Write();

      fout->Close();
      delete fout;
      
      



   
}
// END define the JAM_ANAlyzer::Loop()




