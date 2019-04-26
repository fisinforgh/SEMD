//#include "../include/HeaderValues.h"
double Values::X0(){
  gRandom->SetSeed(0);
  return gRandom->Uniform(0.001,0.999);
  
}
double Values::Y0(){
  gRandom->SetSeed(0);
   return gRandom->Uniform(0.001, 0.999);
}
double Values::VX0(){
  gRandom->SetSeed(0);
  return gRandom->Gaus(2, 1.0);
}
double Values::VY0(){
  gRandom->SetSeed(0);
  return gRandom->Gaus(-2, 1.0);
  
}
