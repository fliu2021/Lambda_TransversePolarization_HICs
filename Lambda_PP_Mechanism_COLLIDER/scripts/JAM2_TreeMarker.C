

void JAM2_TreeMarker(){
	std::vector<std::string> Infiles;
	// define input file array 
	for(int i =0 ; i < 1000;i++){
	  Infiles.push_back(Form("/Users/feng/Documents/physics_project/test_EG/forFeng2_SMode/JAM1_Smode_7p7_%d.dat",i));
	}
	//Infiles.push_back("/Users/feng/Documents/physics_project/test_EG/jam2/JAM2_sqrt_sNN_3p0.dat");
	//end define input file array

	int N_DAT = 1; // Convert N_DAT .dat file into one rootfile 
	int i_temp_dat = 0 ;
	TTree *tree = new TTree("genEvent","genEvent");
	double impact_parameter = 0;
	std::vector<double> Px;
	std::vector<double> Py;
	std::vector<double> Pz;
	std::vector<double> E ;
	std::vector<double> Mass;
	std::vector<int>    Pid;

	tree->Branch("px",&Px);
	tree->Branch("py",&Py);
	tree->Branch("pz",&Pz);
	tree->Branch("E", &E );
	tree->Branch("mass",&Mass);
	tree->Branch("pid",&Pid);
 	tree->Branch("b", &impact_parameter);

 	//temp variable to store a line read from dat file 
	std::string line;
 	
	TH1D *h1_number_events_distribution = new TH1D("h1D_number_events_distribution","h1D_number_events_distribution",1000,0,1000);
	
	//*********************************ENTER INPUT FILE LOOP************************************
	for(int i_file=0;i_file < Infiles.size();i_file++){
		// reset tree, if enter a new rootfile 
		std::cout<< "Current i_file: "<<i_file <<std::endl;
		if (i_file % N_DAT == 0 ){
			tree->Reset();
			i_temp_dat = 0 ;
		}

		//OPEN DAT FILE,and read data for the i_file
		std::ifstream infile(Infiles[i_file]);
		if(!infile.is_open()){
			std::cout<<"Cann't Open input file:"<<Infiles[i_file] << std::endl;
			std::cout<<"Skip this file ! "<<std::endl;
			continue;
		}

		
		//Read the first line
		if(!std::getline(infile,line)){
			std::cout<<"Wrong file header, skip this file" <<std::endl;
			continue;
		};
		std::istringstream iss(line);
		std::string temp_hash;
		int N_events = 0; 
		double y_cm = 0 ;
		double gammaA = 0;
		double gammaB = 0; 
		iss >> temp_hash >> N_events >> y_cm >> gammaA >> gammaB;
		
		//***********************ENTER EVENT LOOP****************************************
		for(int i_event = 0 ;i_event< N_events; i_event++ ){
			//READ the first line of i_event
			if(i_event%1000 == 0){
				std::cout<<"i_event = " << i_event <<std::endl;
			}
			if (i_event == (N_events-1)){h1_number_events_distribution->Fill(i_event);}
			if(!std::getline(infile,line)){
				// Not generated expected number of events, go to next file
				h1_number_events_distribution->Fill(i_event);
				break;
			}; 
			std::string temp_hash2;
			//int event_index = 0;
			//int N_particles = 0; // Number of particles in this event
			//int N_part      = 0; // Number of participant particles in this event
			//int N_coll      = 0; // Number of collisions  in this event 
			
			int event_index = 0; 
			int N_particles = 0;
			int ncollG      = 0;  
			int npartG      = 0;
			int npart       = 0;
			int ncoll       = 0;
			int nollBB      = 0;     


			std::istringstream iss2(line);
			//iss2 >> temp_hash2 >>event_index >> N_particles >> N_part >> N_coll >> impact_parameter; 
			iss2 >> temp_hash2 >>event_index >> N_particles >> ncollG >> npartG >> impact_parameter >> npart >> ncoll >> nollBB;
			//Clear the vectors 
			Px.clear();
			Py.clear();
			Pz.clear();
			E.clear();
			Mass.clear();
			Pid.clear();

			int good_event_flag =1; // To jugde if all events are printed 
			
			//*************************ENTER PARTICLE LOOP********************
			for(int i_particle=0; i_particle < N_particles ; i_particle++){
				//read a line from dat file 
				if(!std::getline(infile,line)){
					std::cout<<"Error: Not all particles in this event are printed, drop this event. "<<std::endl;
					good_event_flag = 0;
					break;
				};
				std::istringstream iss3(line);
				int temp_status =0;
				int temp_pid = 0;
				int temp_N_collisions_suffered = 0; 
				double temp_mass = 0;
				double temp_px = 0;
				double temp_py = 0;
				double temp_pz = 0;
				double temp_E  = 0; 
				double temp_x  = 0;
				double temp_y  = 0;
				double temp_z  = 0;
				double temp_t  = 0;
				double temp_tf = 0;
				//iss3 >> temp_status >> temp_pid >> temp_N_collisions_suffered >> temp_mass >> temp_px >> temp_py >> temp_pz >> temp_E ; 
				iss3 >> temp_status >> temp_pid >> temp_N_collisions_suffered >> temp_mass >> temp_px >> temp_py >> temp_pz >> temp_E >> temp_x >> temp_y >> temp_z >> temp_t >> temp_tf;
				Px.push_back(temp_px);
				Py.push_back(temp_py);
				Pz.push_back(temp_pz);
				E.push_back(temp_E);
				Mass.push_back(temp_mass);
				Pid.push_back(temp_pid);
			}
			
			//*************************END   PARTICLE LOOP********************
			if(good_event_flag == 1 ) {tree->Fill();}//only all particles are printed, we fill this event. 


		}
		//***********************END EVENT LOOP  ****************************************

		i_temp_dat ++; 
		if (i_temp_dat == N_DAT){
			TFile *fout = new TFile("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM2/3_0GeV/JAM2_3p0.root","RECREATE");
			tree->Write();
			fout ->Close();
			delete fout;
		}


	}
	//*********************************END INPUT FILE LOOP************************************

	
	TFile *fout_stat = new TFile("/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM2/3_0GeV/stat.root","RECREATE");
	h1_number_events_distribution->Write();
	fout_stat->Close();
	delete fout_stat;





}