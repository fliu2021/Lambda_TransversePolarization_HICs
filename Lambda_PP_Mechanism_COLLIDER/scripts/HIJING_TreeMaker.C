



void HIJING_TreeMaker(){
	//the address of input file generatered by HIJING 
	std::string In_file ="/Users/feng/Documents/physics_project/Software/hijing1411/test.out";
	std::ifstream infile(In_file);
	std::string line;
	if(!infile.is_open()){
		std::cout<<"Cann't open input file at:"<< In_file <<std::endl; 
		return ;
	}

	//Output to TTree 
	std::string Out_file="/Users/feng/Documents/physics_project/Lambda_AuAu/src/test_4_5GeV.root";
	TFile *fout = TFile::Open(Out_file.c_str(),"recreate");
	if(!fout){std::cout<<"Can't open output file at:"<<Out_file<<std::endl;return ; }
	TTree *genTree =new TTree("genEvent","genEvent");
	double  B_phi = 0; // the azimuthal angle of impart parameter
	std::vector<double> Px;
	std::vector<double> Py;
	std::vector<double> Pz;
	std::vector<double> E ;
	std::vector<int>    Mother_index  ;
	std::vector<int>    Status		  ;
	std::vector<int>    Particle_pid  ;

	genTree->Branch("b_phi",&B_phi);
	genTree->Branch("px",&Px);
	genTree->Branch("py",&Py);
	genTree->Branch("pz",&Pz);
	genTree->Branch("E" ,&E );
	genTree->Branch("mother_index",&Mother_index);
	genTree->Branch("status",&Status);
	genTree->Branch("pid",&Particle_pid);


	while(std::getline(infile,line)){
		if (line==" BEGINNINGOFEVENT"){
			//An event start in the next line
			break;
		}
	}

	//*************************START EVENT LOOP************************************
	while(1){
		std::getline(infile,line);
		std::istringstream iss(line);
		int event_index = 0;
		int number_particles = 0;
		double total_energy = 0 ; 
		iss >> event_index >> number_particles >> total_energy >> B_phi;
		if(event_index%100 == 0 ) std::cout<< "event_index:" << event_index << std::endl; 
		//*************************START Particle LOOP************************************
		for(int i_particle=0;i_particle<number_particles;i_particle++){
			double particle_index,px,py,pz,e,mother_index,status,pid;
			std::getline(infile,line);
			std::istringstream iss(line);
			iss >> particle_index >> pid >> mother_index >> status >> px >> py >> pz >> e ; 
			Px.push_back(px);
			Py.push_back(py);
			Pz.push_back(pz);
			E.push_back(e);
			Mother_index.push_back(mother_index);
			Status.push_back(status);
			Particle_pid.push_back(pid);
		}
		//*************************END Particle LOOP************************************
		
		genTree->Fill();

		// clear the vectors for next event
		B_phi = 0;
		Px.clear();
		Py.clear();
		Pz.clear();
		E.clear();
		Mother_index.clear();
		Status.clear();
		Particle_pid.clear();
		//
		if (!std::getline(infile,line)){break;}

	}
	//*************************END EVENT LOOP************************************


	genTree->Write();
	fout->Close();
	delete fout;

}
