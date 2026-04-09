# Lambda_TransversePolarization_HICs
This simulation and analysis aims to investigate the connection between lambda global poalrization in HICs and transverse polarization initially seen in pA collisions. 

The basic idea here is that, the v1 flow , if has correct sign can result in the alignment between production plane and reaction plane. Therefore, the transverse polarization can be mainfested as a kind of global polarization. 


## Generate MC Sample 
There are two pieces in this production plane mechanism: (1) v1 flow (2) transverse plarization. The two should be coupled in a proper way. 

For the v1 flow, JAM2 with lambda potential can reproduce the v1 flow of lambda observed by STAR. To use the JAM2, see https://github.com/fliu2021/JAM2. 

Follow the instructions, a sample of heavy ion collisions can be produced in the format of .dat file. To make the analysis indepent of file type, "scripts/JAM2_TreeMarker.C" can convert the .dat file into .root file. 

Depending on the STAR collisions mode, different "JAM2_TreeMarker.C" should be used. 
```
Lambda_PP_Mechanism_COLLIDER/scripts/JAM2_TreeMarker.C
```
is the file than can convert the .dat file (the kinematics is defined in the center of mass frame) to .root file (the kinematics is in the center of mass frame). 


```
Lambda_PP_Mechanism_FIXTARGET/scripts/JAM2_TreeMarker.C
```
is the file than can convert the .dat file (everything is defined in the center of mass frame) to .root file (the kinematics is in the fix target frame). 

Once the .root is produced, the analysis including the v1 flow and global polarization can be performed. 

## Analyze the MC Sample 
The code to find the centrality is in the folder: 
```
src_centrality
```

Here, there are four files: 
```
Centrality_Analyzer.h and Centrality_Analyzer.C
```

define the class used to find centrality,while 

```
main_Centrality 
```
is the main file, and 

```
makefile
```

is used to complie the source file. You may need to change the compile flag (depending on the version of complier you can use). 

The "main_Cenntrality" can produce the plot of distribution of number of charged particles, with this



After determing the centrality, input the boundaried of centrality into the
```
src/constants.h
```

Then, the main analysis codes are: 
```
src/JAM2_Analyzer.C JAM2_Analyzer.h
```
which define the class used to do analysis, while 

```
src/main_JAM2Analyzer.C
```

is the main file, where the directory of input files and output files are defined. And 

```
P_Lambda.h
```
defines the class used to incorporate the transverse polarization. Specifically. the magnitude of transverse polarization is calculated as a function of xF by fitting to global data, and the corresponding code is the: 
```
scripts/fit_Polarization.C
```

To complile the source file, use the make file in the folder: 

```
src/make
```

You may also need to modify the flag depending on the vertion of compiler. 


## Plot the Result

After running the analysis code, all histograms will be stored in a .root file. This .root file is then input into the code for plot:

```
plot_FIXTARGET/plot.C 
```
,which is used to plot the 3GeV AuAu collisions for rapidity of -1 < y < 1.0 .


```
plot_FIXTARGET/plot_y_m0p2.C
```
,which is used to plot the 3GeV AuAu collisions for rapidity of -0.2 < y < 1.0. 










