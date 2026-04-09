#include "constants.h"


void plot_y_m0p2(){

	   double sqrt_sNN = 3.0;
      //double alpha = 0.642;
      double alpha = 0.747;

	   int *centrality_charged_multi_higher; 
       int *centrality_charged_multi_lower ;

       int *centrality_centra_lower;
       int *centrality_centra_higher;

       // originally designed to do beam-energy scan...
	   if( sqrt_sNN > (3.0 - 0.0001) && sqrt_sNN < (3.0 + 0.0001) ){ //!!!!!!!!!!Here is a bug to be fixed!

        centrality_charged_multi_higher = &(centrality_sqrt_sNN_3_0_charged_multi_higher[0]);
        centrality_charged_multi_lower  = &(centrality_sqrt_sNN_3_0_charged_multi_lower[0]) ; 

        centrality_centra_lower  = &(centrality_sqrt_sNN_3_0_centra_lower[0])  ; 
        centrality_centra_higher = &(centrality_sqrt_sNN_3_0_centra_higher[0]);

      }


	  //TFile *fin=TFile::Open("JAM2_sqrt_sNN_3.00_80M_y_-1.0_1.0.root");
      TFile *fin=TFile::Open("JAM2_sqrt_sNN_3.00_60M_y_-0.2_1.root");

      TH1D *h1D_inclusive_particle_pT_distribution          = (TH1D*)fin->Get("h1D_inclusive_particle_pT_distribution");
      TH1D *h1D_lambda_pT_distribution                      = (TH1D*)fin->Get("h1D_lambda_pT_distribution");
      //rapidity distribution
      TH1D *h1D_inclusive_particle_rapidity_distribution    = (TH1D*)fin->Get("h1D_inclusive_particle_rapidity_distribution");
      TH1D *h1D_lambda_rapidity_distribution                = (TH1D*)fin->Get("h1D_lambda_rapidity_distribution");
      //rapidity distribution 
      TH1D *h1D_inclusive_particle_eta_distribution         = (TH1D*)fin->Get("h1D_inclusive_particle_eta_distribution");
      TH1D *h1D_lambda_eta_distribution                     = (TH1D*)fin->Get("h1D_lambda_eta_distribution");
      //lambda xF distribution 
      TH1D *h1D_lambda_xF_distribution                      = (TH1D*)fin->Get("h1D_lambda_xF_distribution");
      TH2D *h2D_lambda_xF_rapidity                          = (TH2D*)fin->Get("h2D_lambda_xF_rapidity");




      TH1D *h1D_inclusive_particle_delta_phi_RP[rapidity_bin];
      TH1D *h1D_inclusive_particle_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_inclusive_particle_delta_phi_EPDEP[rapidity_bin];
      TH1D *h1D_inclusive_particle_cos_delta_phi_EPDEP[rapidity_bin];
      //lambda 
      TH1D *h1D_lambda_delta_phi_RP[rapidity_bin];
      TH1D *h1D_lambda_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_lambda_delta_phi_EPDEP[rapidity_bin];
      TH1D *h1D_lambda_cos_delta_phi_EPDEP[rapidity_bin];
      //pion+ 
      TH1D *h1D_pion_plus_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_plus_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_plus_delta_phi_EPDEP[rapidity_bin];
      TH1D *h1D_pion_plus_cos_delta_phi_EPDEP[rapidity_bin];
      //pion-
      TH1D *h1D_pion_minus_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_minus_cos_delta_phi_RP[rapidity_bin];
      TH1D *h1D_pion_minus_delta_phi_EPDEP[rapidity_bin];
      TH1D *h1D_pion_minus_cos_delta_phi_EPDEP[rapidity_bin];

      //proton
      TH1D *h1D_proton_delta_phi_RP[rapidity_bin];
      TH1D *h1D_proton_cos_delta_phi_RP[rapidity_bin]; 
      TH1D *h1D_proton_delta_phi_EPDEP[rapidity_bin];
      TH1D *h1D_proton_cos_delta_phi_EPDEP[rapidity_bin];
      


   
      for(int i_temp = 0; i_temp < rapidity_bin;i_temp++){
         h1D_inclusive_particle_delta_phi_RP[i_temp]              =  (TH1D*)fin->Get(Form("h1D_inclusive_particle_delta_phi_RP_y_%d_%d"             ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 
         h1D_inclusive_particle_cos_delta_phi_RP[i_temp]          =  (TH1D*)fin->Get(Form("h1D_inclusive_particle_cos_delta_phi_RP_y_%d_%d"         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 
         h1D_inclusive_particle_delta_phi_EPDEP[i_temp]           =  (TH1D*)fin->Get(Form("h1D_inclusive_particle_delta_phi_EPDEP_y_%d_%d"          ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );         
         h1D_inclusive_particle_cos_delta_phi_EPDEP[i_temp]       =  (TH1D*)fin->Get(Form("h1D_inclusive_particle_cos_delta_phi_EPDEP_y_%d_%d"      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 

         h1D_lambda_delta_phi_RP[i_temp]                          =  (TH1D*)fin->Get(Form("h1D_lambda_delta_phi_RP_y_%d_%d"                         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );          
         h1D_lambda_cos_delta_phi_RP[i_temp]                      =  (TH1D*)fin->Get(Form("h1D_lambda_cos_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         h1D_lambda_delta_phi_EPDEP[i_temp]                       =  (TH1D*)fin->Get(Form("h1D_lambda_delta_phi_EPDEP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );    
         h1D_lambda_cos_delta_phi_EPDEP[i_temp]                   =  (TH1D*)fin->Get(Form("h1D_lambda_cos_delta_phi_EPDEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         
         //pion+
         h1D_pion_plus_delta_phi_RP[i_temp]                       =  (TH1D*)fin->Get(Form("h1D_pion_plus_delta_phi_RP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 
         h1D_pion_plus_cos_delta_phi_RP[i_temp]                   =  (TH1D*)fin->Get(Form("h1D_pion_plus_cos_delta_phi_RP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         h1D_pion_plus_delta_phi_EPDEP[i_temp]                    =  (TH1D*)fin->Get(Form("h1D_pion_plus_delta_phi_EPDEP_y_%d_%d"                   ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         h1D_pion_plus_cos_delta_phi_EPDEP[i_temp]                =  (TH1D*)fin->Get(Form("h1D_pion_plus_cos_delta_phi_EPDEP_y_%d_%d"               ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 
         
         
         //pion-
         h1D_pion_minus_delta_phi_RP[i_temp]                      =  (TH1D*)fin->Get(Form("h1D_pion_minus_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   ); 
         h1D_pion_minus_cos_delta_phi_RP[i_temp]                  =  (TH1D*)fin->Get(Form("h1D_pion_minus_cos_delta_phi_RP_y_%d_%d"                 ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );   
         h1D_pion_minus_delta_phi_EPDEP[i_temp]                   =  (TH1D*)fin->Get(Form("h1D_pion_minus_delta_phi_EPDEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );   
         h1D_pion_minus_cos_delta_phi_EPDEP[i_temp]               =  (TH1D*)fin->Get(Form("h1D_pion_minus_cos_delta_phi_EPDEP_y_%d_%d"              ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         
         
         //proton
         h1D_proton_delta_phi_RP[i_temp]                          =  (TH1D*)fin->Get(Form("h1D_proton_delta_phi_RP_y_%d_%d"                         ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );  
         h1D_proton_cos_delta_phi_RP[i_temp]                      =  (TH1D*)fin->Get(Form("h1D_proton_cos_delta_phi_RP_y_%d_%d"                     ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );      
         h1D_proton_delta_phi_EPDEP[i_temp]                       =  (TH1D*)fin->Get(Form("h1D_proton_delta_phi_EPDEP_y_%d_%d"                      ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );   
         h1D_proton_cos_delta_phi_EPDEP[i_temp]                   =  (TH1D*)fin->Get(Form("h1D_proton_cos_delta_phi_EPDEP_y_%d_%d"                  ,(int)(100*rapidity_bin_low[i_temp]), (int)(100*rapidity_bin_high[i_temp]) )   );     
         
       
      }





      //For v1 analysis, three-subevent methos. 
      //Phi (A) - Phi(B)
      TH1D *h1D_Delta_Phi_A_B_10_40 =(TH1D*)fin->Get("h1D_Delta_Phi_A_B_10_40");
      TH1D *h1D_Cos_Delta_Phi_A_B_10_40 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_A_B_10_40");
      //Phi (A) - Phi(C)
      TH1D *h1D_Delta_Phi_A_C_10_40 =(TH1D*)fin->Get("h1D_Delta_Phi_A_C_10_40" );
      TH1D *h1D_Cos_Delta_Phi_A_C_10_40 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_A_C_10_40" );
      //Phi (B) - Phi(C)
      TH1D *h1D_Delta_Phi_B_C_10_40 =(TH1D*)fin->Get("h1D_Delta_Phi_B_C_10_40");
      TH1D *h1D_Cos_Delta_Phi_B_C_10_40 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_B_C_10_40");


      //For global polarization analysis 
      TH1D *h1D_Delta_Phi_A_B_20_50 =(TH1D*)fin->Get("h1D_Delta_Phi_A_B_20_50");
      TH1D *h1D_Cos_Delta_Phi_A_B_20_50 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_A_B_20_50");
      //Phi (A) - Phi(C)
      TH1D *h1D_Delta_Phi_A_C_20_50 =(TH1D*)fin->Get("h1D_Delta_Phi_A_C_20_50");
      TH1D *h1D_Cos_Delta_Phi_A_C_20_50 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_A_C_20_50" );
      //Phi (B) - Phi(C)
      TH1D *h1D_Delta_Phi_B_C_20_50 =(TH1D*)fin->Get("h1D_Delta_Phi_B_C_20_50" );
      TH1D *h1D_Cos_Delta_Phi_B_C_20_50 =(TH1D*)fin->Get("h1D_Cos_Delta_Phi_B_C_20_50" );


      TH1D *h1D_Phi_1_A_10_40 =(TH1D*)fin->Get("h1D_Phi_1_A_10_40" );
      TH1D *h1D_Phi_1_B_10_40 =(TH1D*)fin->Get("h1D_Phi_1_B_10_40" );
      TH1D *h1D_Phi_1_C_10_40 =(TH1D*)fin->Get("h1D_Phi_1_C_10_40" );


      TH1D *h1D_Phi_1_A_20_50 =(TH1D*)fin->Get("h1D_Phi_1_A_20_50" );
      TH1D *h1D_Phi_1_B_20_50 =(TH1D*)fin->Get("h1D_Phi_1_B_20_50" );
      TH1D *h1D_Phi_1_C_20_50 =(TH1D*)fin->Get("h1D_Phi_1_C_20_50" );
     


      //resolution of event plane as a function of centrality
      //For v1 flow analysis 
      TH1D *h1D_Cos_Delta_Phi_A_B_v1[centrality_Nclass];
      TH1D *h1D_Cos_Delta_Phi_A_C_v1[centrality_Nclass];
      TH1D *h1D_Cos_Delta_Phi_B_C_v1[centrality_Nclass];

      //For Global Polarization analysis 
      TH1D *h1D_Cos_Delta_Phi_A_B_GP[centrality_Nclass];
      TH1D *h1D_Cos_Delta_Phi_A_C_GP[centrality_Nclass];
      TH1D *h1D_Cos_Delta_Phi_B_C_GP[centrality_Nclass];



     


      for(int i=0; i< centrality_Nclass;i++){
          h1D_Cos_Delta_Phi_A_B_v1[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_A_B_v1_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );
          h1D_Cos_Delta_Phi_A_C_v1[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_A_C_v1_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );
          h1D_Cos_Delta_Phi_B_C_v1[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_B_C_v1_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );

          h1D_Cos_Delta_Phi_A_B_GP[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_A_B_GP_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );
          h1D_Cos_Delta_Phi_A_C_GP[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_A_C_GP_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );
          h1D_Cos_Delta_Phi_B_C_GP[i]=(TH1D*)fin->Get( Form("h1D_Cos_Delta_Phi_B_C_GP_%d_%d",centrality_centra_lower[i],centrality_centra_higher[i]) );
      }


      




      TProfile *h2D_sin_phi_star_EP_un_weight_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_EP_un_weight_y_pos");
      TProfile *h2D_sin_phi_star_EP_un_weight_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_EP_un_weight_y_neg");
      TProfile *h2D_sin_phi_star_EP_un_weight_y     = (TProfile*)fin->Get("h2D_sin_phi_star_EP_un_weight_y"    );
    
      TProfile *h2D_sin_phi_star_RP_un_weight_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_RP_un_weight_y_pos");
      TProfile *h2D_sin_phi_star_RP_un_weight_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_RP_un_weight_y_neg");
      TProfile *h2D_sin_phi_star_RP_un_weight_y     = (TProfile*)fin->Get("h2D_sin_phi_star_RP_un_weight_y"    );
      
      TProfile *h2D_sin_phi_star_EP_weight_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_EP_weight_y_pos");
      TProfile *h2D_sin_phi_star_EP_weight_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_EP_weight_y_neg");
      TProfile *h2D_sin_phi_star_EP_weight_y     = (TProfile*)fin->Get("h2D_sin_phi_star_EP_weight_y"    );
    
      TProfile *h2D_sin_phi_star_RP_weight_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_RP_weight_y_pos");
      TProfile *h2D_sin_phi_star_RP_weight_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_RP_weight_y_neg");
      TProfile *h2D_sin_phi_star_RP_weight_y     = (TProfile*)fin->Get("h2D_sin_phi_star_RP_weight_y"    );
    

      TProfile *h2D_sin_phi_star_EP_sample_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_EP_sample_y_pos");
      TProfile *h2D_sin_phi_star_EP_sample_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_EP_sample_y_neg");
      TProfile *h2D_sin_phi_star_EP_sample_y     = (TProfile*)fin->Get("h2D_sin_phi_star_EP_sample_y"    );

      TProfile *h2D_sin_phi_star_RP_sample_y_pos = (TProfile*)fin->Get("h2D_sin_phi_star_RP_sample_y_pos");
      TProfile *h2D_sin_phi_star_RP_sample_y_neg = (TProfile*)fin->Get("h2D_sin_phi_star_RP_sample_y_neg");
      TProfile *h2D_sin_phi_star_RP_sample_y     = (TProfile*)fin->Get("h2D_sin_phi_star_RP_sample_y"    );
    
      
      
      
      //For the purpose of double check 
      TH1D *h1D_dN_dcos_thets_star_unweight = (TH1D*)fin->Get("h1D_dN_dcos_thets_star_unweight");
      TH1D *h1D_dN_dcos_thets_star_weight   = (TH1D*)fin->Get("h1D_dN_dcos_thets_star_weight"  );
      TH1D *h1D_dN_dcos_thets_star_sample   = (TH1D*)fin->Get("h1D_dN_dcos_thets_star_sample"  );

      TH1D *h1D_Cos_Phi_PP_Phi_EP_GP        = (TH1D*)fin->Get("h1D_Cos_Phi_PP_Phi_EP_GP");
      TH1D *h1D_Sin_Phi_PP_Phi_EP_GP        = (TH1D*)fin->Get("h1D_Sin_Phi_PP_Phi_EP_GP");















   
      //lambda angle between reaction plane Phi_RP and phi_proton_star
      TH1D *h1D_Phi_RP_phi_proton_star_polarized = (TH1D*)fin->Get("h1D_Phi_RP_phi_proton_star_polarized");
      TH1D *h1D_sin_Phi_RP_phi_proton_star_polarized = (TH1D*)fin->Get("h1D_sin_Phi_RP_phi_proton_star_polarized");
 
      //lambda angle between event plane Phi_EP and phi_proton_star
      TH1D *h1D_Phi_EP_phi_proton_star_polarized = (TH1D*)fin->Get("h1D_Phi_EP_phi_proton_star_polarized");
      TH1D *h1D_sin_Phi_EP_phi_proton_star_polarized = (TH1D*)fin->Get("h1D_sin_Phi_EP_phi_proton_star_polarized");


      
      


      //Distribution from weight 
      TH1D *h1D_sin_phi_star_EP_un_weight = (TH1D*)fin->Get("h1D_sin_phi_star_EP_un_weight");
      TH1D *h1D_sin_phi_star_RP_un_weight = (TH1D*)fin->Get("h1D_sin_phi_star_RP_un_weight");
      TH1D *h1D_sin_phi_star_EP_weight    = (TH1D*)fin->Get("h1D_sin_phi_star_EP_weight");
      TH1D *h1D_sin_phi_star_RP_weight    = (TH1D*)fin->Get("h1D_sin_phi_star_RP_weight");





      TLatex *text = new TLatex();
   	//text->SetTextFont(42);
      //text->SetTextFont(62);
      text->SetTextColor(kBlack);
    
   
    
    


    



      //resolution as a function of centrality
      
      double resolution_v1[centrality_Nclass];
      double resolution_error_v1[centrality_Nclass];

      double resolution_GP[centrality_Nclass];
      double resolution_error_GP[centrality_Nclass];

      double centrality_center[centrality_Nclass];
      double centrality_center_error[centrality_Nclass];

      for(int i=0; i< centrality_Nclass;i++){
      	resolution_v1[i] = TMath::Sqrt( h1D_Cos_Delta_Phi_A_B_v1[i]->GetMean() * h1D_Cos_Delta_Phi_A_C_v1[i]->GetMean() / h1D_Cos_Delta_Phi_B_C_v1[i]->GetMean() );
      	resolution_error_v1[i] = 0 ;

         resolution_GP[i] = TMath::Sqrt( h1D_Cos_Delta_Phi_A_B_GP[i]->GetMean() * h1D_Cos_Delta_Phi_A_C_GP[i]->GetMean() / h1D_Cos_Delta_Phi_B_C_GP[i]->GetMean() ) ;
         resolution_error_GP[i] = 0 ;

      	centrality_center[i] =  ( centrality_centra_lower[i] + centrality_centra_higher[i] ) /2.;
      	centrality_center_error[i] = 0;
      }
      //---------------------Global Lambda Poalrization Analysis: resolution of event plane as a function of centrality-----------------------------
      TCanvas *c1 = new TCanvas("c1","c1",800,600);
      c1->cd();
      c1->SetLeftMargin(0.12);
      c1->SetRightMargin(0.03);
      c1->SetBottomMargin(0.12);
      c1->SetTickx(1);
      c1->SetTicky(1);
      c1->SetTopMargin(0.03);
      c1->SetFrameLineWidth(2);
      TGraphErrors *gr1 = new TGraphErrors(centrality_Nclass,centrality_center,resolution_GP , centrality_center_error,resolution_error_GP);
      gr1->SetMarkerStyle(20);
      gr1->SetMarkerSize(1);
      gr1->GetXaxis()->SetTitle("Centrality most %");
      gr1->GetYaxis()->SetTitle("Res(#Psi_{1})");
      gr1->GetXaxis()->CenterTitle();
      gr1->GetYaxis()->CenterTitle();
      gr1->SetTitle();
      gr1->Draw("AP");
      text->DrawLatexNDC(0.75, 0.85, "JAM2");
      text->DrawLatexNDC(0.75, 0.75, "#sqrt{s_{NN}} = 3 GeV ");
      text->SetTextSize(0.045);
      c1->SaveAs("plot_y_m0p2/resolution_GP.png");
      c1->SaveAs("plot_y_m0p2/resolution_GP.pdf");
   	//----------------------------------------------------------------------------------------------------------------------------------------------
      
      //resoluton of 10-40% centrality for v1 analysis, resolution of 20-50% centrality for global lambda polarization at 3 GeV
      double Res_10_40 = TMath::Sqrt( h1D_Cos_Delta_Phi_A_B_10_40->GetMean() *h1D_Cos_Delta_Phi_A_C_10_40->GetMean() /h1D_Cos_Delta_Phi_B_C_10_40->GetMean() );
      double Res_10_40_error =0;//*TMath::Sqrt(2);
      double Res_20_50 = TMath::Sqrt( h1D_Cos_Delta_Phi_A_B_20_50->GetMean() *h1D_Cos_Delta_Phi_A_C_20_50->GetMean() /h1D_Cos_Delta_Phi_B_C_20_50->GetMean() );
      double Res_20_50_error =0;//*TMath::Sqrt(2);

      double v1_proton_EP[rapidity_bin];
      double v1_proton_EP_error[rapidity_bin];
      double v1_proton_RP[rapidity_bin];
      double v1_proton_RP_error[rapidity_bin];

      double v1_pion_plus_EP[rapidity_bin];
      double v1_pion_plus_EP_error[rapidity_bin];
      double v1_pion_plus_RP[rapidity_bin];
      double v1_pion_plus_RP_error[rapidity_bin];

      double v1_pion_minus_EP[rapidity_bin];
      double v1_pion_minus_EP_error[rapidity_bin];
      double v1_pion_minus_RP[rapidity_bin];
      double v1_pion_minus_RP_error[rapidity_bin];

      double v1_lambda_EP[rapidity_bin];
      double v1_lambda_EP_error[rapidity_bin];
      double v1_lambda_RP[rapidity_bin];
      double v1_lambda_RP_error[rapidity_bin];

      double y_center[rapidity_bin];
      double y_center_error[rapidity_bin];

      
      double v1_proton_data[10]={-0.383351,-0.334835,-0.296614,-0.256051,-0.214806,-0.172722,-0.129714,-0.0896846,-0.0531697,-0.018804};
      double v1_proton_data_error[10]={8.161e-05,7.05098e-05,6.36583e-05,6.15704e-05,6.07257e-05,6.09011e-05,6.03403e-05,6.04776e-05,6.00216e-05,5.99635e-05};

      double v1_pion_plus_data[10]={0.0477734,0.0388226,0.0310656,0.0233932,0.0175128,0.0121019,0.00830425,0.00483035,0.00245059,0.000567076};
      double v1_pion_plus_data_error[10]={0.000223887,0.000203687,0.000188181,0.000175411,0.000165529,0.000156161,0.000150849,0.000146659,0.000145267,0.000143636};
      
      double v1_pion_minus_data[10]={0.0213642,0.0125027,0.00497249,0.000645665,-0.00348652,-0.00534022,-0.00586919,-0.00439303,-0.00285665,-0.000890104};
      double v1_pion_minus_data_error[10]={0.00020652,0.00186329,0.00157993,0.00136173,0.00119062,0.00107715,0.000992708,0.000890147,0.000817796,0.000804245};

      double v1_lambda_data[10]={-0.378475,-0.354615,-0.292640,-0.238844,-0.197790,-0.149724,-0.110324,-0.0777701,-0.049115,-0.0239718}; 
      double v1_lambda_data_error[10]={0.0143209,0.00745014,0.0052098,0.00422052,0.00346067,0.00360102,0.0033436,0.00400631,0.0038511,0.00833567};
      
      double y_data[10]={-0.95 , -0.85 , -0.75 , -0.65 , -0.55 , -0.45 , -0.35 , -0.25 , -0.15 ,  -0.05 };
      double y_data_error[10]={0.0,0,0,0,0,0,0,0,0};
      
      for(int i =0;i<rapidity_bin;i++){
         
         v1_proton_EP[i]= h1D_proton_cos_delta_phi_EPDEP[i]->GetMean()/Res_10_40;
         v1_proton_EP_error[i]= TMath::Sqrt( TMath::Power(h1D_proton_cos_delta_phi_EPDEP[i]->GetMeanError()/Res_10_40,2) + TMath::Power(h1D_proton_cos_delta_phi_EPDEP[i]->GetMean()*Res_10_40_error/TMath::Power(Res_10_40,2),2) );
         v1_proton_RP[i]=h1D_proton_cos_delta_phi_RP[i]->GetMean();
         v1_proton_RP_error[i]=h1D_proton_cos_delta_phi_RP[i]->GetMeanError();
         
         v1_pion_plus_EP[i]= h1D_pion_plus_cos_delta_phi_EPDEP[i]->GetMean()/Res_10_40;
         v1_pion_plus_EP_error[i]= TMath::Sqrt( TMath::Power(h1D_pion_plus_cos_delta_phi_EPDEP[i]->GetMeanError()/Res_10_40,2) + TMath::Power(h1D_pion_plus_cos_delta_phi_EPDEP[i]->GetMean()*Res_10_40_error/TMath::Power(Res_10_40,2),2) );
         v1_pion_plus_RP[i]=h1D_pion_plus_cos_delta_phi_RP[i]->GetMean();
         v1_pion_plus_RP_error[i]=h1D_pion_plus_cos_delta_phi_RP[i]->GetMeanError();

         v1_pion_minus_EP[i]= h1D_pion_minus_cos_delta_phi_EPDEP[i]->GetMean()/Res_10_40;
         v1_pion_minus_EP_error[i]= TMath::Sqrt( TMath::Power(h1D_pion_minus_cos_delta_phi_EPDEP[i]->GetMeanError()/Res_10_40,2) + TMath::Power(h1D_pion_minus_cos_delta_phi_EPDEP[i]->GetMean()*Res_10_40_error/TMath::Power(Res_10_40,2),2) );
         v1_pion_minus_RP[i]=h1D_pion_minus_cos_delta_phi_RP[i]->GetMean();
         v1_pion_minus_RP_error[i]=h1D_pion_minus_cos_delta_phi_RP[i]->GetMeanError();

         v1_lambda_EP[i]= h1D_lambda_cos_delta_phi_EPDEP[i]->GetMean()/Res_10_40;
         v1_lambda_EP_error[i]= TMath::Sqrt( TMath::Power(h1D_lambda_cos_delta_phi_EPDEP[i]->GetMeanError()/Res_10_40,2) + TMath::Power(h1D_lambda_cos_delta_phi_EPDEP[i]->GetMean()*Res_10_40_error/TMath::Power(Res_10_40,2),2) );
         v1_lambda_RP[i]=h1D_lambda_cos_delta_phi_RP[i]->GetMean();
         v1_lambda_RP_error[i]=h1D_lambda_cos_delta_phi_RP[i]->GetMeanError();
         
         y_center[i]=(rapidity_bin_low[i]+rapidity_bin_high[i])/2.;
         y_center_error[i]=0;

      }

      
      //---------------------------------------------------------------------proton v1 flow wrt EP(event plane) & RP (reaction plane)---------------------------------------
      TCanvas *c3= new TCanvas("c3","c3",800,600);
      c3->cd();
      TGraphErrors *gr_proton_EP  = new TGraphErrors(10,y_center,v1_proton_EP,y_center_error,v1_proton_EP_error);
      gr_proton_EP->SetMarkerStyle(21);
      gr_proton_EP->SetMarkerColor(kRed);

      
      TGraphErrors *gr_proton_RP  = new TGraphErrors(10,y_center,v1_proton_RP,y_center_error,v1_proton_RP_error);
      gr_proton_RP->SetMarkerStyle(22);
      gr_proton_RP->SetMarkerColor(kBlue);
      
      
      TGraphErrors *gr_proton_data =new TGraphErrors(10,y_data,v1_proton_data,y_data_error,v1_proton_data_error);

	   gr_proton_data->SetMarkerStyle(20);
      gr_proton_data->SetMarkerColor(kBlack);
      
      TMultiGraph *mg3 = new TMultiGraph();
      mg3->SetTitle(";y;v_{1}");
      
      mg3->Add(gr_proton_EP);
      mg3->Add(gr_proton_RP);
      mg3->Add(gr_proton_data);
      mg3->Draw("AP");
      
      TLegend *leg3 = new TLegend(0.7,0.5,0.9,0.7);
      leg3->SetBorderSize(0);
      leg3->AddEntry(gr_proton_EP, "JAM2 v_{1}(EP)", "lp");
      leg3->AddEntry(gr_proton_RP, "JAM2 v_{1}(RP)", "lp");
      leg3->AddEntry(gr_proton_data, "STAR Data", "lp");
      leg3->Draw();
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.7, 0.4, "10 % - 40 %");
      text->DrawLatexNDC(0.7, 0.33, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.7, 0.26, "Proton");

      c3->SaveAs("plot_y_m0p2/proton_v1.png");






      //--------------------------------------------------------------------- pion- v1 flow wrt EP(event plane) & RP (reaction plane)---------------------------------------    
      TCanvas *c4= new TCanvas("c4","c4",800,600);
      c4->cd();
      TGraphErrors *gr_pion_minus_EP  = new TGraphErrors(10,y_center,v1_pion_minus_EP,y_center_error,v1_pion_minus_EP_error);
      gr_pion_minus_EP->SetMarkerStyle(21);
      gr_pion_minus_EP->SetMarkerColor(kRed);

      
      TGraphErrors *gr_pion_minus_RP  = new TGraphErrors(10,y_center,v1_pion_minus_RP,y_center_error,v1_pion_minus_RP_error);
      gr_pion_minus_RP->SetMarkerStyle(22);
      gr_pion_minus_RP->SetMarkerColor(kBlue);

      
      TGraphErrors *gr_pion_minus_data =new TGraphErrors(10,y_center,v1_pion_minus_data,y_center_error,v1_pion_minus_data_error);

      gr_pion_minus_data->SetMarkerStyle(20);
      gr_pion_minus_data->SetMarkerColor(kBlack);
      
      TMultiGraph *mg4 = new TMultiGraph();
      mg4->SetTitle(";y;v_{1}");
      
      mg4->Add(gr_pion_minus_EP);
      mg4->Add(gr_pion_minus_RP);
      mg4->Add(gr_pion_minus_data);
      mg4->Draw("AP");
      
      TLegend *leg4 = new TLegend(0.7,0.3,0.9,0.5);
      leg4->SetBorderSize(0);
      leg4->AddEntry(gr_pion_minus_EP, "JAM2 v_{1}(EP)", "lp");
      leg4->AddEntry(gr_pion_minus_RP, "JAM2 v_{1}(RP)", "lp");
      leg4->AddEntry(gr_pion_minus_data, "STAR Data", "lp");
      leg4->Draw();
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.45, 0.45, "10 % - 40 %");
      text->DrawLatexNDC(0.45, 0.38, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.45, 0.31, "#pi^{-}");

      c4->SaveAs("plot_y_m0p2/pion_minus_v1.png");
      
      //--------------------------------------------------------------------- pion+ v1 flow wrt EP(event plane) & RP (reaction plane)---------------------------------------    
 
      TCanvas *c5= new TCanvas("c5","c5",800,600);
      c5->cd();
      TGraphErrors *gr_pion_plus_EP  = new TGraphErrors(10,y_center,v1_pion_plus_EP,y_center_error,v1_pion_plus_EP_error);
      gr_pion_plus_EP->SetMarkerStyle(21);
      gr_pion_plus_EP->SetMarkerColor(kRed);

      
      TGraphErrors *gr_pion_plus_RP  = new TGraphErrors(10,y_center,v1_pion_plus_RP,y_center_error,v1_pion_plus_RP_error);
      gr_pion_plus_RP->SetMarkerStyle(22);
      gr_pion_plus_RP->SetMarkerColor(kBlue);
      
      
      TGraphErrors *gr_pion_plus_data =new TGraphErrors(10,y_center,v1_pion_plus_data,y_center_error,v1_pion_plus_data_error);

      gr_pion_plus_data->SetMarkerStyle(20);
      gr_pion_plus_data->SetMarkerColor(kBlack);
      
      TMultiGraph *mg5 = new TMultiGraph();
      mg5->SetTitle(";y;v_{1}");
      
      mg5->Add(gr_pion_plus_EP);
      mg5->Add(gr_pion_plus_RP);
      mg5->Add(gr_pion_plus_data);
      mg5->Draw("AP");
      
      TLegend *leg5 = new TLegend(0.7,0.3,0.9,0.5);
      leg5->SetBorderSize(0);
      leg5->AddEntry(gr_pion_plus_EP, "JAM2 v_{1}(EP)", "lp");
      leg5->AddEntry(gr_pion_plus_RP, "JAM2 v_{1}(RP)", "lp");
      leg5->AddEntry(gr_pion_plus_data, "STAR Data", "lp");
      leg5->Draw();
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.45, 0.45, "10 % - 40 %");
      text->DrawLatexNDC(0.45, 0.38, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.45, 0.31, "#pi^{+}");

      c5->SaveAs("plot_y_m0p2/pion_plus_v1.png");
      
      


      //--------------------------------------------------------------------- lambda v1 flow wrt EP(event plane) & RP (reaction plane)---------------------------------------    

      TCanvas *c6= new TCanvas("c6","c6",800,600);
      c6->cd();
      
      c6->SetLeftMargin(0.12);
      c6->SetRightMargin(0.03);
      c6->SetBottomMargin(0.12);
      c6->SetTickx(1);
      c6->SetTicky(1);
      c6->SetTopMargin(0.03);
      c6->SetFrameLineWidth(2);
      

      


      TGraphErrors *gr_lambda_EP  = new TGraphErrors(10,y_center,v1_lambda_EP,y_center_error,v1_lambda_EP_error);
      gr_lambda_EP->SetMarkerStyle(21);
      gr_lambda_EP->SetMarkerColor(kRed);
      gr_lambda_EP->SetLineColor(kRed);
      
      TGraphErrors *gr_lambda_RP  = new TGraphErrors(10,y_center,v1_lambda_RP,y_center_error,v1_lambda_RP_error);
      gr_lambda_RP->SetMarkerStyle(22);
      gr_lambda_RP->SetMarkerColor(kBlue);
      
      
      TGraphErrors *gr_lambda_data =new TGraphErrors(10,y_data,v1_lambda_data,y_data_error,v1_lambda_data_error);

      gr_lambda_data->SetMarkerStyle(20);
      gr_lambda_data->SetMarkerColor(kBlack);
      gr_lambda_data->SetLineColor(kBlack);
      TMultiGraph *mg6 = new TMultiGraph();
      mg6->SetTitle(";y;v_{1}");
      mg6->Add(gr_lambda_EP);
      //mg6->Add(gr_lambda_RP);
      mg6->Add(gr_lambda_data);
      mg6->Draw("AP");
      
      mg6->GetXaxis()->SetTitle("y");
      mg6->GetXaxis()->CenterTitle();
      mg6->GetYaxis()->SetTitle("v_{1}");
      mg6->GetYaxis()->CenterTitle();

      mg6->GetYaxis()->SetTitleSize(0.07);
      mg6->GetYaxis()->SetTitleOffset(0.79);

      mg6->GetXaxis()->SetTitleSize(0.07);
      mg6->GetXaxis()->SetTitleOffset(0.79);

      mg6->GetXaxis()->SetNdivisions(505);

      mg6->GetYaxis()->SetNdivisions(505);
      TLegend *leg6 = new TLegend(0.7,0.37,0.89,0.5);
      leg6->SetBorderSize(0);
      //leg6->AddEntry(gr_lambda_EP, "JAM2 v_{1}(EP)", "lp");
      leg6->AddEntry(gr_lambda_EP, "JAM2", "lp");
      //leg6->AddEntry(gr_lambda_RP, "JAM2 v_{1}(RP)", "lp");
      leg6->AddEntry(gr_lambda_data, "STAR", "lp");
      leg6->Draw();
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.7, 0.65, "10 % - 40 %");
      text->DrawLatexNDC(0.7, 0.58, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.7, 0.51, "#Lambda");

      c6->SaveAs("plot_y_m0p2/lambda_v1.png");
      c6->SaveAs("plot_y_m0p2/lambda_v1.pdf");
      
      
      //--------------------------------------------------------------------- lambda xF distribution----------------------------------------------------------------    

      TCanvas *c7 = new TCanvas("c7","c7",800,600);
      c7->cd();
      c7->SetLeftMargin(0.12);
      c7->SetRightMargin(0.03);
      c7->SetBottomMargin(0.12);
      c7->SetTickx(1);
      c7->SetTicky(1);
      c7->SetTopMargin(0.03);
      c7->SetFrameLineWidth(2);
      h1D_lambda_xF_distribution->SetStats(0);
      h1D_lambda_xF_distribution->Scale(1./h1D_lambda_xF_distribution->Integral(),"width");
      h1D_lambda_xF_distribution->SetTitle("");
      h1D_lambda_xF_distribution->GetXaxis()->SetTitleSize(0.07);
      h1D_lambda_xF_distribution->GetXaxis()->SetTitleOffset(0.70);
      h1D_lambda_xF_distribution->GetXaxis()->SetTitle("x_{F}");
      h1D_lambda_xF_distribution->GetXaxis()->CenterTitle();
      
      h1D_lambda_xF_distribution->GetYaxis()->SetTitle("#frac{1}{N} #frac{d N}{d x_{F}}");
      h1D_lambda_xF_distribution->GetYaxis()->CenterTitle();
      h1D_lambda_xF_distribution->GetYaxis()->SetNdivisions(505);
      

      h1D_lambda_xF_distribution->Rebin(5);
      h1D_lambda_xF_distribution->GetXaxis()->SetTitleSize(0.07);
      h1D_lambda_xF_distribution->GetXaxis()->SetTitleOffset(0.7);
      h1D_lambda_xF_distribution->GetYaxis()->SetTitleSize(0.05);
      h1D_lambda_xF_distribution->GetYaxis()->SetTitleOffset(0.7);
      h1D_lambda_xF_distribution->SetLineColor(kRed);
      h1D_lambda_xF_distribution->SetLineWidth(3);
      h1D_lambda_xF_distribution->GetXaxis()->SetRangeUser(0.01,1.0);
      //h1D_lambda_xF_distribution->Draw("hist C");
      h1D_lambda_xF_distribution->SetMarkerStyle(20);
      h1D_lambda_xF_distribution->SetMarkerColor(kRed);
      h1D_lambda_xF_distribution->SetMarkerSize(1.0);
      h1D_lambda_xF_distribution->Draw("EP");
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.65, 0.87, "#Lambda JAM2");
      text->DrawLatexNDC(0.65, 0.79, "20 % - 50 %");
      text->DrawLatexNDC(0.65, 0.71, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.65, 0.63, "P_{T, #Lambda} > 0.7 GeV/c, -0.2 < y_{#Lamv=bda} < 1.0");
      c7->SaveAs("plot_y_m0p2/lambda_xF.png");
      c7->SaveAs("plot_y_m0p2/lambda_xF.pdf");

      //--------------------------------------------------------------------- lambda pT distribution----------------------------------------------------------------    

      TCanvas *c8 = new TCanvas("c8","c8",800,600);
      c8->cd();
      h1D_lambda_pT_distribution->GetXaxis()->SetTitle("p_{T} [GeV/c]");
      h1D_lambda_pT_distribution->GetXaxis()->SetRangeUser(0,5);
      h1D_lambda_pT_distribution->GetYaxis()->SetTitle("Counts");
      h1D_lambda_pT_distribution->Draw();
      c8->SaveAs("plot_y_m0p2/lambda_pT.png");

      //--------------------------------------------------------------------- llambda Global polarization with STAR method for negative rapidity (neg), wrt event plane----------------------------------------------------------------    

      TF1 *fitFunc = new TF1("fitFunc","[0]+[1]*sin(x)",0,TMath::Pi()*2);
      fitFunc->SetParameters(0,0.5);


      
      TCanvas *c9 = new TCanvas("c9","c9",1500,500);
      c9->Divide(3,1);
      c9->cd(1);
      h2D_sin_phi_star_EP_un_weight_y_neg->Scale( 800/(alpha*TMath::Pi()*Res_20_50 ) );
      fitFunc->SetLineColor(kRed);
      fitFunc->SetLineWidth(4);
      h2D_sin_phi_star_EP_un_weight_y_neg->Fit(fitFunc,"0");
      TF1 *fit_unweight= (TF1*)fitFunc->Clone("unweighted");
      h2D_sin_phi_star_EP_un_weight_y_neg->Draw();

      text->DrawLatexNDC(0.15, 0.4, "Event Plane");
      text->DrawLatexNDC(0.15, 0.3, "No weight");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      //fitFunc->Draw("same");
      std::cout<<"Eevent Plane un weight: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;
      
      c9->cd(2);
      h2D_sin_phi_star_EP_weight_y_neg->Scale( 800/(alpha*TMath::Pi()*Res_20_50 ) );
      fitFunc->SetLineColor(kBlue);
      fitFunc->SetLineWidth(4);
      h2D_sin_phi_star_EP_weight_y_neg->Fit(fitFunc,"0");
      TF1 *fit_weight= (TF1*)fitFunc->Clone("weighted");
      h2D_sin_phi_star_EP_weight_y_neg->Draw();
      text->DrawLatexNDC(0.15, 0.4, "Event Plane");
      text->DrawLatexNDC(0.15, 0.3, "Weight");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      fitFunc->SetLineColor(kBlue);
      //fitFunc->Draw("same");
      std::cout<<"Event Plane weight: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;

      c9->cd(3);
      h2D_sin_phi_star_EP_sample_y_neg->Scale( 800/(alpha*TMath::Pi()*Res_20_50 ) );
      h2D_sin_phi_star_EP_sample_y_neg->Fit(fitFunc);
      h2D_sin_phi_star_EP_sample_y_neg->Draw();
      text->DrawLatexNDC(0.15, 0.4, "Event Plane");
      text->DrawLatexNDC(0.15, 0.3, "Sample");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      //fitFunc->Draw("same");
      std::cout<<"Event Plane sample: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;

      c9->SaveAs("plot_y_m0p2/GP_VS_u_EP.png");



      //--------------------------------------------------------------------- lambda global polarization,negative rapidity, for paper plot----------------------------------------------------------------    

      TCanvas *c9_1 = new TCanvas("c9_1","c9_1",1200,600);
      c9_1->cd();
      c9_1->SetLeftMargin(0.12);
      c9_1->SetRightMargin(0.03);
      c9_1->SetBottomMargin(0.12);
      c9_1->SetTickx(1);
      c9_1->SetTicky(1);
      c9_1->SetTopMargin(0.03);
      c9_1->SetFrameLineWidth(2);


      h2D_sin_phi_star_EP_un_weight_y_neg->GetXaxis()->SetTitle("#phi_{#Lambda}- #phi_{p}*");
      h2D_sin_phi_star_EP_un_weight_y_neg->GetXaxis()->SetTitleSize(0.045);
      h2D_sin_phi_star_EP_un_weight_y_neg->GetXaxis()->CenterTitle();
      h2D_sin_phi_star_EP_un_weight_y_neg->GetYaxis()->SetTitle("#frac{8}{#pi #alpha_{#Lambda}} #frac{1}{R^{(1)}_{EP}} #LT sin( #Psi_{EP}^{(1)} - #phi_{p}* ) #GT (%)");
      h2D_sin_phi_star_EP_un_weight_y_neg->GetYaxis()->SetTitleSize(0.045);
      h2D_sin_phi_star_EP_un_weight_y_neg->GetYaxis()->SetTitleOffset(0.91);
      h2D_sin_phi_star_EP_un_weight_y_neg->GetYaxis()->SetNdivisions(505);
      h2D_sin_phi_star_EP_un_weight_y_neg->GetYaxis()->CenterTitle();

      h2D_sin_phi_star_EP_un_weight_y_neg->SetStats(0);
      h2D_sin_phi_star_EP_un_weight_y_neg->SetMarkerStyle(4);
      h2D_sin_phi_star_EP_un_weight_y_neg->SetMarkerSize(1);
      h2D_sin_phi_star_EP_un_weight_y_neg->SetMarkerColor(kRed);
      h2D_sin_phi_star_EP_un_weight_y_neg->SetLineColor(kRed);
      
      h2D_sin_phi_star_EP_un_weight_y_neg->SetTitle("");
      h2D_sin_phi_star_EP_un_weight_y_neg->Draw("E");



      h2D_sin_phi_star_EP_weight_y_neg->GetXaxis()->SetTitle("#phi_{#Lambda}-#phi_{p}*");
      h2D_sin_phi_star_EP_weight_y_neg->GetXaxis()->CenterTitle();
      h2D_sin_phi_star_EP_weight_y_neg->GetYaxis()->SetTitleSize(0.045);
      h2D_sin_phi_star_EP_weight_y_neg->GetYaxis()->SetTitle("#frac{8}{#pi #alpha_{#Lambda}} #frac{1}{R^{(1)}_{EP}} #LT sin( #Psi_{EP}^{(1)} - #phi_{p}* ) #GT (%)");
      h2D_sin_phi_star_EP_weight_y_neg->GetYaxis()->CenterTitle();
      h2D_sin_phi_star_EP_weight_y_neg->GetYaxis()->SetTitleSize(0.045);
      h2D_sin_phi_star_EP_weight_y_neg->SetStats(0);

      h2D_sin_phi_star_EP_weight_y_neg->SetMarkerStyle(21);
      h2D_sin_phi_star_EP_weight_y_neg->SetMarkerSize(1);
      h2D_sin_phi_star_EP_weight_y_neg->SetMarkerColor(kBlue);
      h2D_sin_phi_star_EP_weight_y_neg->SetLineColor(kBlue);
      
      h2D_sin_phi_star_EP_weight_y_neg->SetTitle("");
      h2D_sin_phi_star_EP_weight_y_neg->Draw("E same");

      
      fit_unweight->SetLineStyle(4);fit_unweight->SetLineWidth(1);
      fit_weight->SetLineStyle(1);fit_weight->SetLineWidth(1);
      fit_unweight->Draw("same");
      fit_weight->Draw("same");
      TLegend *leg9_1 = new TLegend(0.65,0.75,0.81,0.93);
      leg9_1->SetBorderSize(0);
      leg9_1->AddEntry(h2D_sin_phi_star_EP_un_weight_y_neg, Form("Unpolarized"));//, #bar{P}^{(GP)}_{#Lambda} = %.2f %% #pm %.2f %%",fit_unweight->GetParameter(0),fit_unweight->GetParError(0) ), "p");
      leg9_1->AddEntry(h2D_sin_phi_star_EP_weight_y_neg, Form("Polarized"));//, #bar{P}^{(GP)}_{#Lambda} = %.2f %% #pm %.2f %%",fit_weight->GetParameter(0),fit_weight->GetParError(0) ), "p");
      leg9_1->Draw();


      TLegend *leg9_1_fit = new TLegend(0.65,0.47,0.86,0.65);
      leg9_1_fit->SetBorderSize(0);
      leg9_1_fit->AddEntry(fit_unweight, Form("#bar{P}^{(GP)}_{#Lambda} = %.2f%% #pm %.2f%%",fit_unweight->GetParameter(0),fit_unweight->GetParError(0)), "lp");
      leg9_1_fit->AddEntry(fit_weight, Form("#bar{P}^{(GP)}_{#Lambda} = %.2f%% #pm %.2f%%",fit_weight->GetParameter(0),fit_weight->GetParError(0)), "lp");
      leg9_1_fit->Draw();



      TAxis *xaxis = h2D_sin_phi_star_EP_un_weight_y_neg->GetXaxis();

      xaxis->SetNdivisions(4, false); 
      xaxis->SetLabelOffset(0.012);
      xaxis->ChangeLabel(1, -1, -1, -1, -1, -1, "0");
      //xaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#frac{#pi}{2}");
      xaxis->ChangeLabel(2, -1, -1, -1, -1, -1, "#pi/2");
      xaxis->ChangeLabel(3, -1, -1, -1, -1, -1, "#pi");
      //xaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "#frac{3#pi}{2}");
      xaxis->ChangeLabel(4, -1, -1, -1, -1, -1, "3#pi/2");
      xaxis->ChangeLabel(5, -1, -1, -1, -1, -1, "2#pi");
     


      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.20, 0.47, "#Lambda JAM2");
      text->DrawLatexNDC(0.20, 0.39, "20 % - 50 %");
      text->DrawLatexNDC(0.20, 0.31, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.20, 0.23, "P_{T,#Lambda} > 0.7 GeV/c, -0.2 < y_{#Lambda} < 0");
      text->DrawLatexNDC(0.68, 0.68, "Fit: #bar{P}_{#Lambda}^{(GP)} + c sin(#phi_{#Lambda} - #phi_{p}*)");

      c9_1->SaveAs("plot_y_m0p2/sin_phi_star_EP_y_neg.png");
      c9_1->SaveAs("plot_y_m0p2/sin_phi_star_EP_y_neg.pdf");









      //--------------------------------------------------------------------- lambda Global polarization with STAR method for negative rapidity (neg),wrt reaction plane ----------------------------------------------------------------    

      TCanvas *c10 = new TCanvas("c10","c10",1500,500);
      c10->Divide(3,1);
      c10->cd(1);
      h2D_sin_phi_star_RP_un_weight_y_neg->Scale( 800/(alpha*TMath::Pi()) );
      h2D_sin_phi_star_RP_un_weight_y_neg->Fit(fitFunc);
      h2D_sin_phi_star_RP_un_weight_y_neg->Draw();
      text->DrawLatexNDC(0.15, 0.4, "Reaction Plane");
      text->DrawLatexNDC(0.15, 0.3, "No weight");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      //fitFunc->Draw("same");
      std::cout<<"Reaction Plane un weight: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;
      
      


      c10->cd(2);
      h2D_sin_phi_star_RP_weight_y_neg->Scale( 800/(alpha*TMath::Pi()) );
      h2D_sin_phi_star_RP_weight_y_neg->Fit(fitFunc);
      h2D_sin_phi_star_RP_weight_y_neg->Draw();
      //fitFunc->Draw("same");
      text->DrawLatexNDC(0.15, 0.4, "Reaction Plane");
      text->DrawLatexNDC(0.15, 0.3, "weight");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      std::cout<<"Reaction Plane  weight: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;

      c10->cd(3);
      h2D_sin_phi_star_RP_sample_y_neg->Scale( 800/(alpha*TMath::Pi()) );
      h2D_sin_phi_star_RP_sample_y_neg->Fit(fitFunc);
      h2D_sin_phi_star_RP_sample_y_neg->Draw();
      //itFunc->Draw("same");
      text->DrawLatexNDC(0.15, 0.4, "Reaction Plane");
      text->DrawLatexNDC(0.15, 0.3, "Sample");
      text->DrawLatexNDC(0.15, 0.2, Form("%.3f + %.3f sin(#phi_{p}*-#phi_{#Lambda})",fitFunc->GetParameter(0),fitFunc->GetParameter(1) ) ) ;
      std::cout<<"Reaction Plane sample: x0 + x1 * sin(u)"<<std::endl;
      std::cout<<"x0="<<fitFunc->GetParameter(0)<<" +/- "<<fitFunc->GetParError(0)<<std::endl;
      std::cout<<"x1="<<fitFunc->GetParameter(1)<<" +/- "<<fitFunc->GetParError(1)<<std::endl;

      c10->SaveAs("plot_y_m0p2/GP_VS_u_RP_neg.png");




      //--------------------------------------------------------------------- lambda transverse polarization unweighted----------------------------------------------------------------    
      
      TCanvas *c11_1 = new TCanvas("c11_1","c11_1",800,600);
      //c11->Divide(3,1);
      c11_1->cd();
      c11_1->SetLeftMargin(0.12);
      c11_1->SetRightMargin(0.03);
      c11_1->SetBottomMargin(0.12);
      c11_1->SetTickx(1);
      c11_1->SetTicky(1);
      c11_1->SetTopMargin(0.03);
      c11_1->SetFrameLineWidth(2);
      text->DrawLatexNDC(0.3, 0.5, "No weight");
      h1D_dN_dcos_thets_star_unweight->Rebin(4);
      h1D_dN_dcos_thets_star_unweight->Scale(1./h1D_dN_dcos_thets_star_unweight->Integral(),"width");
      
      h1D_dN_dcos_thets_star_unweight->SetTitle("");
      h1D_dN_dcos_thets_star_unweight->SetStats(0);
      h1D_dN_dcos_thets_star_unweight->GetXaxis()->SetTitle("cos#theta *");
      h1D_dN_dcos_thets_star_unweight->GetXaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_unweight->GetXaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_unweight->GetXaxis()->SetTitleOffset(1.00);
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetTitleOffset(0.99);
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetTitle("#frac{1}{N} #frac{d N}{d cos#theta *}");
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetRangeUser(0.4,0.65);
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_unweight->SetLineColor(kRed);
      h1D_dN_dcos_thets_star_unweight->SetMarkerColor(kRed);
      h1D_dN_dcos_thets_star_unweight->SetMarkerStyle(21);
      h1D_dN_dcos_thets_star_unweight->SetMarkerSize(1.0);
      h1D_dN_dcos_thets_star_unweight->Draw("EP");
      

      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.65, 0.87, "#Lambda JAM2");
      text->DrawLatexNDC(0.65, 0.79, "20 % - 50 %");
      text->DrawLatexNDC(0.65, 0.71, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.65, 0.63, "P_{T} > 0.7 GeV/c, -0.2 <y_{#Lambda} < 1.0");


      TLegend *leg11_1 = new TLegend(0.63,0.27,0.89,0.37);
      leg11_1->SetBorderSize(0);
      leg11_1->AddEntry(h1D_dN_dcos_thets_star_unweight, "unweighted", "lp");
      leg11_1->Draw();


      c11_1->SaveAs("plot_y_m0p2/dN_dcos_theta_star_unweight.png");
      c11_1->SaveAs("plot_y_m0p2/dN_dcos_theta_star_unweight.pdf");


      //--------------------------------------------------------------------- lambda transver polarization weighted----------------------------------------------------------------    

      TCanvas *c11_2 = new TCanvas("c11_2","c11_2",800,600);
      c11_2->cd();
      c11_2->SetLeftMargin(0.12);
      c11_2->SetRightMargin(0.03);
      c11_2->SetBottomMargin(0.12);
      c11_2->SetTickx(1);
      c11_2->SetTicky(1);
      c11_2->SetTopMargin(0.03);
      c11_2->SetFrameLineWidth(2);
      text->DrawLatexNDC(0.3, 0.5, "Weight");

      h1D_dN_dcos_thets_star_weight->SetTitle("");
      h1D_dN_dcos_thets_star_weight->SetStats(0);
      h1D_dN_dcos_thets_star_weight->Rebin(4);
      h1D_dN_dcos_thets_star_weight->Scale(1./h1D_dN_dcos_thets_star_weight->Integral(),"width");
      h1D_dN_dcos_thets_star_weight->GetXaxis()->SetTitle("cos#theta *");
      h1D_dN_dcos_thets_star_weight->GetXaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_weight->GetXaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_weight->GetXaxis()->SetTitleOffset(1.00);
      h1D_dN_dcos_thets_star_weight->GetYaxis()->SetTitle("#frac{1}{N} #frac{d N}{d cos#theta *}");
      h1D_dN_dcos_thets_star_weight->GetYaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_weight->GetYaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_weight->GetYaxis()->SetTitleOffset(0.97);
      h1D_dN_dcos_thets_star_weight->GetYaxis()->SetRangeUser(0.4,0.65);
      h1D_dN_dcos_thets_star_weight->SetLineColor(kBlue);
      h1D_dN_dcos_thets_star_weight->SetMarkerColor(kBlue);
      h1D_dN_dcos_thets_star_weight->SetMarkerStyle(20);
      h1D_dN_dcos_thets_star_weight->SetMarkerSize(1.0);
      h1D_dN_dcos_thets_star_weight->Draw("EP");


      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.65, 0.87, "#Lambda JAM2");
      text->DrawLatexNDC(0.65, 0.79, "20 % - 50 %");
      text->DrawLatexNDC(0.65, 0.71, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.65, 0.63, "P_{T} > 0.7 GeV/c, -0.2 <y_{#Lambda} < 1.0");

      
      TLegend *leg11_2 = new TLegend(0.63,0.27,0.80,0.37);
      leg11_2->SetBorderSize(0);
      leg11_2->AddEntry(h1D_dN_dcos_thets_star_weight, "weighted", "lp");
      leg11_2->Draw();



      c11_2->SaveAs("plot_y_m0p2/dN_dcos_theta_star_weight.png");
      c11_2->SaveAs("plot_y_m0p2/dN_dcos_theta_star_weight.pdf");
      //--------------------------------------------------------------------- lambda transver polarization sample----------------------------------------------------------------    

      TCanvas *c11_3 = new TCanvas("c11_3","c11_3",800,600);
      c11_3->cd();
      c11_3->SetLeftMargin(0.12);
      c11_3->SetRightMargin(0.03);
      c11_3->SetBottomMargin(0.12);
      c11_3->SetTickx(1);
      c11_3->SetTicky(1);
      c11_3->SetTopMargin(0.03);
      c11_3->SetFrameLineWidth(2);
      text->DrawLatexNDC(0.3, 0.5, "Sample");
      h1D_dN_dcos_thets_star_sample->SetTitle("");
      h1D_dN_dcos_thets_star_sample->SetStats(0);
      h1D_dN_dcos_thets_star_sample->Rebin(4);
      h1D_dN_dcos_thets_star_sample->Scale(1./h1D_dN_dcos_thets_star_sample->Integral(),"width");
      h1D_dN_dcos_thets_star_sample->GetXaxis()->SetTitle("cos#theta *");
      h1D_dN_dcos_thets_star_sample->GetXaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_sample->GetXaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_sample->GetXaxis()->SetTitleOffset(1.00);
      h1D_dN_dcos_thets_star_sample->GetYaxis()->SetTitle("#frac{d N}{d cos#theta *}");
      h1D_dN_dcos_thets_star_sample->GetYaxis()->CenterTitle();
      h1D_dN_dcos_thets_star_sample->GetYaxis()->SetTitleSize(0.05);
      h1D_dN_dcos_thets_star_sample->GetYaxis()->SetTitleOffset(0.97);
      h1D_dN_dcos_thets_star_sample->GetYaxis()->SetRangeUser(0.4,0.65);
      h1D_dN_dcos_thets_star_sample->SetLineColor(kRed);
      h1D_dN_dcos_thets_star_sample->SetMarkerColor(kRed);
      h1D_dN_dcos_thets_star_sample->SetMarkerStyle(24);
      h1D_dN_dcos_thets_star_sample->SetMarkerSize(1.0);
      h1D_dN_dcos_thets_star_sample->Draw("EP");



      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.65, 0.87, "#Lambda JAM2");
      text->DrawLatexNDC(0.65, 0.79, "20 % - 50 %");
      text->DrawLatexNDC(0.65, 0.71, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.65, 0.63, "P_{T} > 0.7 GeV/c, -0.2 <y_{#Lambda} < 1.0");



      TLegend *leg11_3 = new TLegend(0.63,0.27,0.80,0.37);
      leg11_3->SetBorderSize(0);
      leg11_3->AddEntry(h1D_dN_dcos_thets_star_sample, "sampled", "lp");
      leg11_3->Draw();

      c11_3->SaveAs("plot_y_m0p2/dN_dcos_theta_star_sample.png");
      c11_3->SaveAs("plot_y_m0p2/dN_dcos_theta_star_sample.pdf");

      
      //--------------------------------------------------------------------- lambda transverse polarization for paper plot ----------------------------------------------------------------    

      TCanvas *c11 = new TCanvas("c11","c11",820,600);
      c11->cd();
      c11->SetLeftMargin(0.12);
      c11->SetRightMargin(0.03);
      c11->SetBottomMargin(0.12);
      c11->SetTickx(1);
      c11->SetTicky(1);
      c11->SetTopMargin(0.03);
      c11->SetFrameLineWidth(2);
      h1D_dN_dcos_thets_star_unweight->Draw("EP");
      h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetRangeUser(0.35,0.60);
      //h1D_dN_dcos_thets_star_unweight->GetYaxis()->SetRangeUser(0.45,0.56);
      h1D_dN_dcos_thets_star_weight->Draw("same EP");
      //h1D_dN_dcos_thets_star_sample->Draw("same EP");
      h1D_dN_dcos_thets_star_weight->GetXaxis()->SetTitleSize(0.06);
      h1D_dN_dcos_thets_star_weight->GetXaxis()->SetTitleOffset(0.90);

      TF1 *f11_1 = new TF1("f11_1","[0]*(1+[1]*x)",-1,1);f11_1->SetLineWidth(5);f11_1->SetLineColor(kBlue);f11_1->SetLineStyle(2);
      TF1 *f11_2 = new TF1("f11_2","[0]*(1+[1]*x)",-1,1);f11_2->SetLineWidth(5);f11_2->SetLineColor(kRed);f11_2->SetLineStyle(2);
      f11_1->SetParameters(0.5,0);
      f11_2->SetParameters(0.5,0);
      f11_2->SetLineStyle(4);f11_2->SetLineWidth(3);
      f11_1->SetLineStyle(1);f11_1->SetLineWidth(3);

      h1D_dN_dcos_thets_star_weight->Fit(f11_1);
      h1D_dN_dcos_thets_star_unweight->Fit(f11_2);



      

      TLegend *leg11 = new TLegend(0.55,0.7,0.85,0.92);
      leg11->SetBorderSize(0);
      leg11->AddEntry(h1D_dN_dcos_thets_star_unweight, "Unpolarized", "lp");
      leg11->AddEntry(h1D_dN_dcos_thets_star_weight, "Polarized", "lp");
      //leg11->AddEntry(h1D_dN_dcos_thets_star_sample, "Sampled", "lp");
      leg11->Draw();
      text->SetTextSize(0.04);
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.20, 0.50, "#Lambda JAM2");
      text->DrawLatexNDC(0.20, 0.42, "20 % - 50 %");
      text->DrawLatexNDC(0.20, 0.34, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.20, 0.26, "P_{T, #Lambda} > 0.7 GeV/c, -0.2 <y_{#Lambda} < 1.0");

      text->DrawLatexNDC(0.67, 0.45, "Linear Fit");
      TLegend *leg11_fit = new TLegend(0.55,0.2,0.95,0.42);
      leg11_fit->SetBorderSize(0);
      leg11_fit->AddEntry(f11_2, Form("P_{#Lambda}^{(TP)} = %.1f %% #pm %.1f %%",100*f11_2->GetParameter(1)/alpha,100*f11_2->GetParError(1)/alpha ), "lp");
      leg11_fit->AddEntry(f11_1, Form("P_{#Lambda}^{(TP)} = %.1f %% #pm %.1f %%",100*f11_1->GetParameter(1)/alpha,100*f11_1->GetParError(1)/alpha ), "lp");
      leg11_fit->Draw("same");


      c11->SaveAs("plot_y_m0p2/dN_dcos_theta_star.pdf");
      c11->SaveAs("plot_y_m0p2/dN_dcos_theta_star.png");



    //--------------------------------------------------------------------- relative angle between normal vectors of event plane(EP) and production plane(PP)  ----------------------------------------------------------------    
      /*TCanvas *c12 = new TCanvas("c12","c12",1000,500);
      c12->Divide(2,1);
      c12->cd(1);
      h1D_Cos_Phi_PP_Phi_EP_GP->GetXaxis()->SetTitle("cos(#phi_{TP}-#Psi_{1})");
      h1D_Cos_Phi_PP_Phi_EP_GP->Draw();
      c12->cd(2);
      h1D_Sin_Phi_PP_Phi_EP_GP->GetXaxis()->SetTitle("sin(#phi_{PP}-#Psi_{1})");
      h1D_Sin_Phi_PP_Phi_EP_GP->Draw();


      c12->SaveAs("plot_y_m0p2/angle_bt_PP_EP.png");
      */

      TCanvas *c12_2 = new TCanvas("c12_2","c12_2",800,600);
      c12_2->cd();
      c12_2->SetLeftMargin(0.12);
      c12_2->SetRightMargin(0.03);
      c12_2->SetBottomMargin(0.12);
      c12_2->SetTickx(1);
      c12_2->SetTicky(1);
      c12_2->SetTopMargin(0.03);
      c12_2->SetFrameLineWidth(2);
      h1D_Sin_Phi_PP_Phi_EP_GP->Scale(1./h1D_Sin_Phi_PP_Phi_EP_GP->Integral(),"width");
      h1D_Sin_Phi_PP_Phi_EP_GP->Rebin(4);
      h1D_Sin_Phi_PP_Phi_EP_GP->GetXaxis()->SetTitle("cos(#phi_{PP}- #phi_{EP})");
      h1D_Sin_Phi_PP_Phi_EP_GP->GetXaxis()->CenterTitle();
      h1D_Sin_Phi_PP_Phi_EP_GP->SetStats(0);
      h1D_Sin_Phi_PP_Phi_EP_GP->GetYaxis()->SetTitle("#frac{1}{N} #frac{d N}{d cos(#phi_{PP}- #phi_{EP}) }");
      h1D_Sin_Phi_PP_Phi_EP_GP->GetYaxis()->CenterTitle();
      h1D_Sin_Phi_PP_Phi_EP_GP->SetTitle("");
      h1D_Sin_Phi_PP_Phi_EP_GP->SetMarkerStyle(20);
      h1D_Sin_Phi_PP_Phi_EP_GP->SetMarkerColor(kRed);
      h1D_Sin_Phi_PP_Phi_EP_GP->SetMarkerSize(1);
      h1D_Sin_Phi_PP_Phi_EP_GP->SetLineColor(kRed);
      h1D_Sin_Phi_PP_Phi_EP_GP->GetXaxis()->SetTitleSize(0.05);
      h1D_Sin_Phi_PP_Phi_EP_GP->GetYaxis()->SetTitleSize(0.05);

      h1D_Sin_Phi_PP_Phi_EP_GP->Draw("E");
      text->SetTextSize(0.04);
      text->DrawLatexNDC(0.6, 0.87, "#Lambda JAM2");
      text->DrawLatexNDC(0.6, 0.79, "20 % - 50 %");
      text->DrawLatexNDC(0.6, 0.71, "#sqrt{s_{NN}} = 3.0 GeV");
      text->DrawLatexNDC(0.6, 0.63, "P_{T, #Lambda} > 0.7 GeV/c, -0.2 <y_{#Lambda} < 1.0");

      c12_2->SaveAs("plot_y_m0p2/sin_angle_bt_PP_EP.png");
      c12_2->SaveAs("plot_y_m0p2/sin_angle_bt_PP_EP.pdf");

      
      //------------------------------------------------------------------------------print the signal of global polarizaiton extracted with various methods--------------------------------------------------------------------------------------------------------------------
      std::cout<<"METHOD1"<<std::endl;
      std::cout<<"Global Porlarization incorporated by sampling"<<std::endl;
      double P_global_RP = h1D_sin_Phi_RP_phi_proton_star_polarized->GetMean()*8/(TMath::Pi()*alpha);
      double P_global_RP_error = h1D_sin_Phi_RP_phi_proton_star_polarized->GetMeanError()*8/(TMath::Pi()*alpha)  ;
      double P_global_EP = h1D_sin_Phi_EP_phi_proton_star_polarized->GetMean()*8/(TMath::Pi()*alpha*Res_20_50);
      double P_global_EP_error = TMath::Sqrt(  TMath::Power(h1D_sin_Phi_EP_phi_proton_star_polarized->GetMeanError()/Res_20_50,2) + TMath::Power(h1D_sin_Phi_EP_phi_proton_star_polarized->GetMean()*Res_20_50_error /(Res_20_50*Res_20_50),2)    )* 8 /(TMath::Pi()*alpha);
      std::cout<<"P_global_RP:"<<100*P_global_RP<<"%+/-"<<P_global_RP_error*100<<"%"<<std::endl;
      std::cout<<"P_global_EP:"<<100*P_global_EP<<"%+/-"<<P_global_EP_error*100<<"%"<<std::endl;

      std::cout<<"METHOD2"<<std::endl;
      std::cout<<"Global Porlarization incorporated by reweighting"<<std::endl;

      double P_global_EP_unweight = h1D_sin_phi_star_EP_un_weight->GetMean()*8/(TMath::Pi()*alpha*Res_20_50 );
      double P_global_RP_unweight = h1D_sin_phi_star_RP_un_weight->GetMean()*8/(TMath::Pi()*alpha);
      double P_global_EP_weight   = h1D_sin_phi_star_EP_weight ->GetMean()*8/(TMath::Pi()*alpha*Res_20_50 );
      double P_global_RP_weight   = h1D_sin_phi_star_RP_weight->GetMean()*8/(TMath::Pi()*alpha); 

      double P_global_EP_unweight_error = h1D_sin_phi_star_EP_un_weight->GetMeanError()*8/(TMath::Pi()*alpha*Res_20_50 );
      double P_global_RP_unweight_error = h1D_sin_phi_star_RP_un_weight->GetMeanError()*8/(TMath::Pi()*alpha);
      double P_global_EP_weight_error   = h1D_sin_phi_star_EP_weight ->GetMeanError()*8/(TMath::Pi()*alpha*Res_20_50 );
      double P_global_RP_weight_error   = h1D_sin_phi_star_RP_weight->GetMeanError()*8/(TMath::Pi()*alpha); 

      std::cout<<"P_global_RP_unweight:"<< P_global_RP_unweight*100 <<"%+/-"<< P_global_RP_unweight_error*100<<"%"<<std::endl;
      std::cout<<"P_global_EP_unweight:"<< P_global_EP_unweight*100 <<"%+/-"<< P_global_EP_unweight_error*100<<"%"<<std::endl;
      std::cout<<"P_global_RP_weight:"  << P_global_RP_weight*100   <<"%+/-"<< P_global_RP_weight_error*100  <<"%"<<std::endl;
      std::cout<<"P_global_EP_weight:"  << P_global_EP_weight*100   <<"%+/-"<< P_global_EP_weight_error*100  <<"%"<<std::endl;


}