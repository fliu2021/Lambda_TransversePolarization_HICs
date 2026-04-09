

void plot_summary(){

	double p_y_0_1 = 513857./(513857. + 176427.); 
	double p_y_m0p2_0 = 176427. /(513857. + 176427.) ;



	//fit unweight EP----------------------------------
	double P_GP_EP_fit_unweighted_y_pos = 0.359961;
	double P_GP_EP_fit_unweighted_y_pos_error = 0.291161;

	double P_GP_EP_fit_unweighted_y_neg = 0.40677  ;
	double P_GP_EP_fit_unweighted_y_neg_error = 0.577614;

	double P_GP_EP_fit_unweighted = p_y_0_1 * P_GP_EP_fit_unweighted_y_pos + p_y_m0p2_0 * P_GP_EP_fit_unweighted_y_neg;
	double P_GP_EP_fit_unweighted_error = TMath::Sqrt( TMath::Power(p_y_0_1 * P_GP_EP_fit_unweighted_y_pos_error,2) + TMath::Power(p_y_m0p2_0 * P_GP_EP_fit_unweighted_y_neg,2) );


	//std::cout<<P_GP_EP_fit_unweighted<<"+/-"<<P_GP_EP_fit_unweighted_error<<std::endl;

	
	//fit unweight RP----------------------------------
	double P_GP_RP_fit_unweighted_y_pos = 0.396677;
	double P_GP_RP_fit_unweighted_y_pos_error =  0.268021;

	double P_GP_RP_fit_unweighted_y_neg = 0.100246;
	double P_GP_RP_fit_unweighted_y_neg_error =  0.533399;
	
	double P_GP_RP_fit_unweighted = p_y_0_1 * P_GP_RP_fit_unweighted_y_pos + p_y_m0p2_0 * P_GP_RP_fit_unweighted_y_neg;
	double P_GP_RP_fit_unweighted_error = TMath::Sqrt( TMath::Power(p_y_0_1 * P_GP_RP_fit_unweighted_y_pos_error,2) + TMath::Power(p_y_m0p2_0 * P_GP_RP_fit_unweighted_y_neg,2) );

	//std::cout<<P_GP_RP_fit_unweighted<<"+/-"<<P_GP_RP_fit_unweighted_error<<std::endl;
	
	//fit weight EP----------------------------------
	
	double P_GP_EP_fit_weighted_y_pos = 1.39193;
	double P_GP_EP_fit_weighted_y_pos_error = 0.291555;

	double P_GP_EP_fit_weighted_y_neg = 0.429166;
	double P_GP_EP_fit_weighted_y_neg_error = 0.577616;

	double P_GP_EP_fit_weighted = p_y_0_1 * P_GP_EP_fit_weighted_y_pos + p_y_m0p2_0 * P_GP_EP_fit_weighted_y_neg;
	double P_GP_EP_fit_weighted_error = TMath::Sqrt( TMath::Power(p_y_0_1 * P_GP_EP_fit_weighted_y_pos_error,2) + TMath::Power(p_y_m0p2_0 * P_GP_EP_fit_weighted_y_neg,2) );

	//std::cout<<P_GP_EP_fit_weighted<<"+/-"<<P_GP_EP_fit_weighted_error<<std::endl;

	
	//fit weight RP----------------------------------
	double P_GP_RP_fit_weighted_y_pos = 1.63421;
	double P_GP_RP_fit_weighted_y_pos_error = 0.268387;

	double P_GP_RP_fit_weighted_y_neg = 0.123251;
	double P_GP_RP_fit_weighted_y_neg_error = 0.533405;
	

	double P_GP_RP_fit_weighted = p_y_0_1 * P_GP_RP_fit_weighted_y_pos + p_y_m0p2_0 * P_GP_RP_fit_weighted_y_neg;
	double P_GP_RP_fit_weighted_error = TMath::Sqrt( TMath::Power(p_y_0_1 * P_GP_RP_fit_weighted_y_pos_error,2) + TMath::Power(p_y_m0p2_0 * P_GP_RP_fit_weighted_y_neg,2) );


	//std::cout<<P_GP_RP_fit_weighted<<"+/-"<<P_GP_RP_fit_weighted_error<<std::endl;
	//star date 
	double P_GP_EP_star = 4.91;
	double P_GP_EP_star_error = 0.81;

	


	double P_EP_star[1] 		= {P_GP_EP_star        };
	double P_EP_star_error[1]=   {P_GP_EP_star_error   }; 
	double y_EP_star[1] = {1};


	double P_EP_weighted[1] 		= {P_GP_EP_fit_weighted};
	double P_EP_weighted_error[1]= {  P_GP_EP_fit_weighted_error}; 
	double y_EP_weighted[1] = {3};


	double P_EP_unweighted[1] 		= { P_GP_EP_fit_unweighted        };
	double P_EP_unweighted_error[1]= {P_GP_EP_fit_unweighted_error    }; 
	double y_EP_unweighted[1] = {4};



	double P_RP_weighted[1] 		= {P_GP_RP_fit_weighted};
	double P_RP_weighted_error[1]= {  P_GP_RP_fit_weighted_error}; 
	double y_RP_weighted[1] = {3};


	double P_RP_unweighted[1] 		= { P_GP_RP_fit_unweighted        };
	double P_RP_unweighted_error[1]= {P_GP_RP_fit_unweighted_error    }; 
	double y_RP_unweighted[1] = {4};


	double P_RP_direct_average[1] = {2.42331};
	double P_RP_direct_average_error[1] ={0.270085};
	double y_RP_direct_average[1] = {2};

	double P_EP_direct_average[1] = {2.40225};
	double P_EP_direct_average_error[1] ={0.292805};
	double y_EP_direct_average[1] = {2};


	double P_GP_EP_star_total_error = TMath::Sqrt( TMath::Power(P_GP_EP_star_error,2) + TMath::Power(0.15,2)  );

	std::cout << "STAR Measurement:"<<P_GP_EP_star << " +/ -" <<P_GP_EP_star_total_error<<std::endl;
	std::cout <<  "JAM + TP, fit, EP:"<<P_GP_EP_fit_weighted << "+/-" << P_GP_EP_fit_weighted_error  <<std::endl;
	std::cout <<  "JAM + TP, fit, RP:"<<P_GP_RP_fit_weighted << "+/-" << P_GP_RP_fit_weighted_error  <<std::endl;
	std::cout <<  "JAM + TP, direct average,EP:" <<  "2.40225 +/- 0.292805" <<std::endl;
	std::cout <<  "JAM + TP, direct average,RP:" <<  "2.42331 +/- 0.270085" <<std::endl; 
	std::cout <<  "JAM,EP:"  << P_GP_EP_fit_unweighted << "+/-" << P_GP_EP_fit_unweighted_error <<std::endl;
	std::cout <<  "JAM,RP:"  << P_GP_RP_fit_unweighted << "+/-" << P_GP_RP_fit_unweighted_error <<std::endl;



	std::cout<<"------------------------------------------"<<std::endl;
	double fit_fraction = P_GP_EP_fit_weighted/P_GP_EP_star;
	double fit_fraction_error = fit_fraction * TMath::Sqrt( TMath::Power(P_GP_EP_fit_weighted_error/P_GP_EP_fit_weighted,2) + TMath::Power(P_GP_EP_star_total_error/P_GP_EP_star,2)  );


	std::cout<<"Fit Method, JAM2/STAR:"<<fit_fraction<<"+/-"<<fit_fraction_error<<std::endl;
	//std::cout<<fit_fraction<<"+/-"<<fit_fraction_error<<std::endl;
	double average_fraction = P_EP_direct_average[0]/ P_GP_EP_star;
	double average_fraction_error = average_fraction * TMath::Sqrt( TMath::Power(P_EP_direct_average_error[0]/P_EP_direct_average[0],2) + TMath::Power(P_GP_EP_star_total_error/P_GP_EP_star,2)   );


	std::cout<<"Average Method, JAM/STAR"<<average_fraction<<"+/-"<<average_fraction_error<<std::endl;
	//std::cout<<average_fraction<<"+/-"<<average_fraction_error<<std::endl;
	std::cout<<"------------------------------------------"<<std::endl;

	TGraphErrors *gr_EP_star = new TGraphErrors(1,P_EP_star,y_EP_star,P_EP_star_error,0);
	gr_EP_star->SetMarkerStyle(29);
	gr_EP_star->SetMarkerColor(kBlack);
	gr_EP_star->SetLineColor(kBlack);
	gr_EP_star->SetMarkerSize(3);
	gr_EP_star->SetLineWidth(3);

	TGraphErrors *gr_EP_weighted = new TGraphErrors(1,P_EP_weighted,y_EP_weighted,P_EP_weighted_error,0);
	gr_EP_weighted->SetMarkerStyle(21);
	gr_EP_weighted->SetMarkerColor(kRed);
	gr_EP_weighted->SetLineColor(kRed);
	gr_EP_weighted->SetMarkerSize(2);
	gr_EP_weighted->SetLineWidth(3);

	TGraphErrors *gr_EP_unweighted = new TGraphErrors(1,P_EP_unweighted,y_EP_unweighted,P_EP_unweighted_error,0);
	gr_EP_unweighted->SetMarkerStyle(20);
	gr_EP_unweighted->SetMarkerColor(kBlue);
	gr_EP_unweighted->SetLineColor(kBlue);
	gr_EP_unweighted->SetMarkerSize(2);
	gr_EP_unweighted->SetLineWidth(3);





	TGraphErrors *gr_RP_weighted = new TGraphErrors(1,P_RP_weighted,y_RP_weighted,P_RP_weighted_error,0);
	gr_RP_weighted->SetMarkerStyle(25);
	gr_RP_weighted->SetMarkerColor(kRed);
	gr_RP_weighted->SetLineColor(kRed);
	gr_RP_weighted->SetMarkerSize(2);
	gr_RP_weighted->SetLineWidth(1);

	TGraphErrors *gr_RP_unweighted = new TGraphErrors(1,P_RP_unweighted,y_RP_unweighted,P_RP_unweighted_error,0);
	gr_RP_unweighted->SetMarkerStyle(4);
	gr_RP_unweighted->SetMarkerColor(kBlue);
	gr_RP_unweighted->SetLineColor(kBlue);
	gr_RP_unweighted->SetMarkerSize(2);
	gr_RP_unweighted->SetLineWidth(1);


	TGraphErrors *gr_RP_direct_average = new TGraphErrors(1,P_RP_direct_average,y_RP_direct_average,P_RP_direct_average_error,0);
	gr_RP_direct_average->SetMarkerStyle(26);
	gr_RP_direct_average->SetMarkerColor(kViolet);
	gr_RP_direct_average->SetLineColor(kViolet);
	gr_RP_direct_average->SetMarkerSize(2);
	gr_RP_direct_average->SetLineWidth(1);

	TGraphErrors *gr_EP_direct_average = new TGraphErrors(1,P_EP_direct_average,y_EP_direct_average,P_EP_direct_average_error,0);
	gr_EP_direct_average->SetMarkerStyle(22);
	gr_EP_direct_average->SetMarkerColor(kViolet);
	gr_EP_direct_average->SetLineColor(kViolet);
	gr_EP_direct_average->SetMarkerSize(2);
	gr_EP_direct_average->SetLineWidth(3);





	/*
	TGraphErrors *gr_EP = new TGraphErrors(3,P_EP,y_EP,P_EP_error,0);
	gr_EP->SetMarkerStyle(20);
	gr_EP->SetMarkerColor(kRed);
	gr_EP->SetLineColor(kRed);
	gr_EP->SetMarkerSize(2);
	TGraphErrors *gr_RP = new TGraphErrors(2,P_RP,y_RP,P_RP_error,0);
	gr_RP->SetMarkerStyle(20);
	gr_RP->SetMarkerColor(kBlue);
	gr_RP->SetLineColor(kBlue);
	gr_RP->SetMarkerSize(2);
	*/


	TMultiGraph* mg = new TMultiGraph();
	mg->Add(gr_EP_star);
	mg->Add(gr_EP_weighted);
	mg->Add(gr_EP_unweighted);
	mg->Add(gr_RP_weighted);
	mg->Add(gr_RP_unweighted);


	mg->Add(gr_RP_direct_average);

	mg->Add(gr_EP_direct_average);
	//mg->Add(gr_RP);

	mg->GetXaxis()->SetTitle("#bar{P}_{#Lambda}^{(GP)} (%)");
	mg->GetXaxis()->CenterTitle();
	mg->GetXaxis()->SetTitleSize(0.065);
	mg->GetXaxis()->SetTitleOffset(0.69);

	mg->GetYaxis()->SetTitle("");
    mg->GetYaxis()->SetLabelSize(0);
    mg->GetYaxis()->SetNdivisions(0);
    mg->GetYaxis()->SetRangeUser(0.5,4.25);
    mg->GetXaxis()->SetLimits(-0.2,12);

    TCanvas *c1 = new TCanvas("c1","c1",1500,600);
	c1->SetLeftMargin(0.12);
    //c1->SetRightMargin(0.01);
    c1->SetRightMargin(0.12);
    c1->SetBottomMargin(0.12);
    c1->SetTickx(1);
    c1->SetTicky(1);
    c1->SetTopMargin(0.03);
    c1->SetFrameLineWidth(2);

	mg->Draw("AP");

    TString systems[5] = {"STAR","(Direct Average)","JAM2 + TP","JAM2 + TP","JAM2"};

    double x[5] = {1,1.8,2,3,4};

    TLatex *lat = new TLatex();
    lat->SetTextFont(42);
    lat->SetTextAlign(22);
    lat->SetTextSize(0.040);
    
    for (int i = 0; i < 5; i++) {
        lat->DrawLatex(-1.13, x[i], systems[i]);
    }

    //TLegend *leg = new TLegend(0.67,0.52,0.69,0.82);
    TLegend *leg = new TLegend(0.60,0.17,0.62,0.47);
    leg->SetBorderSize(0);
    //leg->AddEntry(gr_RP, "Reaction Plane", "lp");
    /*
    leg->AddEntry(gr_EP_star, "Data","p");
    leg->AddEntry(gr_EP_unweighted, "JAM2","p");
    leg->AddEntry(gr_EP_weighted, "JAM2, v1 + Transverse Polarization","p");
    leg->AddEntry( gr_EP_direct_average, "JAM2, v1 + Transverse Polarization (Direct Average)","p");

	*/


    leg->AddEntry(gr_EP_unweighted, " ","p");
    leg->AddEntry(gr_EP_weighted, " ","p");
    leg->AddEntry( gr_EP_direct_average, " ","p");
    leg->AddEntry(gr_EP_star, " ","p");


    TLegend *leg_RP = new TLegend(0.78,0.245,0.80,0.47);
    leg_RP->SetBorderSize(0);
    //leg->AddEntry(gr_RP, "Reaction Plane", "lp");
    /*
    leg->AddEntry(gr_EP_star, "Data","p");
    leg->AddEntry(gr_EP_unweighted, "JAM2","p");
    leg->AddEntry(gr_EP_weighted, "JAM2, v1 + Transverse Polarization","p");
    leg->AddEntry( gr_EP_direct_average, "JAM2, v1 + Transverse Polarization (Direct Average)","p");

	*/


    leg_RP->AddEntry(gr_RP_unweighted, " ","p");
    leg_RP->AddEntry(gr_RP_weighted, " ","p");
    leg_RP->AddEntry( gr_RP_direct_average, " ","p");

    leg_RP->Draw();
    leg->Draw();
    /*
     TLegend *leg2 = new TLegend(0.7,0.75,0.95,0.905);
    leg2->SetBorderSize(0);
    leg2->AddEntry(gr_EP_weighted, "Event Plane","p");
    leg2->AddEntry(gr_RP_weighted, "Reaction Plane","p");


  	leg->SetTextSizePixels(25);
  	leg2->SetTextSizePixels(25);

    
    leg2->Draw();
	*/
     TLatex *text = new TLatex();
     text->DrawLatexNDC(0.55, 0.5, "Event Plane ");
     text->DrawLatexNDC(0.72, 0.5, "Reaction Plane ");
   	//text->SetTextFont(42);
      text->SetTextFont(62);
     text->SetTextColor(kBlack);
	 //text->SetTextSize(0.037);
     text->DrawLatexNDC(0.55 , 0.855, "#sqrt{S_{NN}} = 3 GeV    20 % - 50 %");
     text->DrawLatexNDC(0.55, 0.755, "P_{T, #Lambda} > 0.7 GeV/c");
     text->DrawLatexNDC(0.55, 0.655, "-0.2 < y_{#Lambda} < 1.0 ");




    TBox *box = new TBox(4.91-0.15, 1+0.1, 
                         4.91+0.15, 1-0.1);
    box->SetFillColor(kBlack);
    box->SetFillStyle(0); 
    box->SetLineColor(kBlack);
    box->Draw("same");
	

	TLine *line = new TLine(6., 0.5, 6., 4.24); 
	line->SetLineStyle(2); 
	line->SetLineColor(kBlack);
	line->Draw("same"); 

     


 	c1->SaveAs("plot_summary/summary.png");
 	c1->SaveAs("plot_summary/summary.pdf");




}