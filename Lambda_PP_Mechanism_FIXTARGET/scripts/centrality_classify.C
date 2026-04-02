void centrality_classify(){

	TFile *fin=TFile::Open("charged_multiplicity.root");
	//TFile *fin=TFile::Open("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/charged_multiplicity.root");
	TH2D *h2D_chagred_multiplicity_impact_parameter = (TH2D *)fin->Get("h2D_chagred_multiplicity_impact_parameter");
	TH1D *h1D_charged_multiplicity = (TH1D *)h2D_chagred_multiplicity_impact_parameter->ProjectionX();
	int charged_multi_max = h1D_charged_multiplicity->GetXaxis()->GetXmax();
	//h1D_charged_multiplicity->GetXaxis()->SetRangeUser(1,charged_multi_max);

	int N_bins = h1D_charged_multiplicity->GetNbinsX();
	std::vector<double> fraction_print ={0.05,0.1,0.20,0.30,0.40,0.50,0.60,0.70,0.80,0.90,0.100};
	long long N_events = h1D_charged_multiplicity->GetEntries() - h1D_charged_multiplicity->GetBinContent(1);
	//long long accumulation = 0;
	double fraction = 0;
	for(int i = N_bins; i > 1 ; i--){
		//accumulation += h1D_charged_multiplicity->GetBinContent(i);
		double delta_fraction=( h1D_charged_multiplicity->GetBinContent(i)*1.0 )/(N_events*1.0);

		for(int f=0;f<fraction_print.size();f++){
			if(fraction<fraction_print[f] && (fraction+delta_fraction) >= fraction_print[f]){
				std::cout<<"0-"<<fraction_print[f]*100<<"%"<<" chagred multiplicity(|eta|<0.5):" << (h1D_charged_multiplicity->GetBinCenter(i)) <<std::endl;
			}
		}
		fraction = fraction + delta_fraction;
	}

	TText *text = new TText();
   	text->SetTextFont(42);
    text->SetTextSize(0.05);
    text->SetTextColor(kBlack);

    TCanvas *c1= new TCanvas("c1","c1",800,600);
    c1->cd();
    h1D_charged_multiplicity->GetXaxis()->SetTitle("Chagred Multiplicity within |#eta| < 0.5");
    h1D_charged_multiplicity->GetXaxis()->SetRangeUser(0,400);
    h1D_charged_multiplicity->GetYaxis()->SetTitle("Number of events");
    h1D_charged_multiplicity->Draw();
    text->DrawTextNDC(0.5, 0.73, "sqrt{s_{NN}} = 7.7 GeV");

    TCanvas *c2= new TCanvas("c2","c2",800,600);
    c2->cd();
    h2D_chagred_multiplicity_impact_parameter->GetXaxis()->SetTitle("Chagred Multiplicity within |#eta| < 0.5");
    //h2D_chagred_multiplicity_impact_parameter->GetXaxis()->SetRangeUser(0,400);
    h2D_chagred_multiplicity_impact_parameter->GetYaxis()->SetTitle("Impact Parameters b [fm]");
    h2D_chagred_multiplicity_impact_parameter->Draw();
    text->DrawTextNDC(0.5, 0.73, "sqrt{s_{NN}} = 7.7 GeV");


}
