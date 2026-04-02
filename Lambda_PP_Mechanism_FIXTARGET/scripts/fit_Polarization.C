void fit_Polarization(){
	double xF_bin_center[14]={0.000281,    0.00075  ,   0.001925  ,0.02  , 0.054   , 0.099   ,0.247  ,0.331  ,  0.405  ,  0.479  ,  0.553  ,  0.628  ,  0.702  ,  0.777  };
	double xF_bin_low[14] ={0.0       ,    0.0005   ,   0.00105   ,0.01  , 0.04    , 0.07    ,0      ,0      ,  0      ,  0      ,  0      ,  0      ,  0      ,  0      };
	double xF_bin_high[14]={0.0005    ,    0.00105  ,   0.01      ,0.04  , 0.07    , 0.15    ,0      ,0      ,  0      ,  0      ,  0      ,  0      ,  0      ,  0      };



	double polarization_center[14]           ={0.005,-0.012,-0.005,0.018,-0.017,-0.046 ,-0.063 ,-0.09 , -0.124 , -0.179, -0.222, -0.25, -0.248, -0.326};
	double polarization_stat_uncertainty[14] ={0.009,0.009 ,0.01  ,0.026,0.031 ,0.031  ,0.004  ,0.004 , 0.005  , 0.007 , 0.011 , 0.019, 0.034 , 0.068 };
	double polarization_sys_uncertainty[14]  ={0.006,0.008 ,0.008 ,0.022,0.022 ,0.022  ,0.     ,0.    , 0.     , 0.    , 0.    , 0.   , 0.    , 0.    };

	TGraphErrors *gr = new TGraphErrors(14,xF_bin_center,polarization_center,nullptr,polarization_stat_uncertainty);
	//gr->GetXaxis()->SetRangeUser(0.00008,2.1);
	gr->SetMarkerStyle(20);
	gr->SetMarkerSize(1);
	gr->SetTitle("");


	

	TF1* func  = new TF1("quadratic fit","[0]+[1]*x+[2]*x*x",0.00008,2.1);
	func->SetParameters(1,1,1);
	func->SetLineColor(kRed);
	func->SetLineWidth(5);
	TCanvas *c1 =new TCanvas("c1","quadratic fit",800,600);

	c1->SetLeftMargin(0.1);   
    c1->SetRightMargin(0.02);  
    c1->SetBottomMargin(0.1); 
    c1->SetTopMargin(0.06);    
	    
    gStyle->SetPadTickX(1);  
    gStyle->SetPadTickY(1);  
	c1->SetLogx(1);
	c1->SetFrameLineWidth(2);
	
	
	gr->Fit(func);

	
	std::cout<< "Chi^2/ NDF" << func->GetChisquare()<< "/" <<func->GetNDF() <<std::endl;
	std::cout<< "Model function:[0]+[1]*x+[2]*x*x" << std::endl;
	std::cout<< "[0] = " << func->GetParameter(0) << "+/-" << func->GetParError(0) << std::endl;
	std::cout<< "[1] = " << func->GetParameter(1) << "+/-" << func->GetParError(1) << std::endl;
	std::cout<< "[2] = " << func->GetParameter(2) << "+/-" << func->GetParError(2) << std::endl;

	double x_F_pre[1] = {1.0};
	double P_pre[1]   = {func->GetParameter(0)+func->GetParameter(1)+func->GetParameter(2)};
	TGraphErrors *gr2 = new TGraphErrors(1,x_F_pre,P_pre,nullptr,nullptr);
	gr2->SetMarkerStyle(41);
	gr2->SetMarkerSize(3);


	
    TMultiGraph *mg = new TMultiGraph();
    mg->SetTitle(";x_{F};P_{#Lambda}");
    mg->Add(gr);
    mg->Add(gr2);
    func->Draw("same");
   	mg->GetXaxis()->CenterTitle();
	mg->GetYaxis()->CenterTitle();
   	mg->Draw("AP");
    c1->SaveAs("lambda_P_lambda_xF.png");


}