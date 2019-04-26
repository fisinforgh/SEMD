///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2018                              //
//        Brayan Yepes¹        -           Julian Salamanca²             //
//                                                                       //
//                bsyepesg@correo.udistrital.edu.co¹                     //
//                    jasalamanca@udistrital.edu.co²                     //                  
//                                                                       //
//      ¹²Grupo de Física e Informática (FISINFOR) Universidad           //
//                  Distrital Francisco José de Caldas                   //
//                                                                       //
//                                                                       //
//                https://github.com/fisinforgh/SEMD                     //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//               http://www.gnu.org/copyleft/gpl.html                    //
//                                                                       //
///////////////////////////////////////////////////////////////////////////
#ifndef ROOT_HeaderValues
#define ROOT_HeaderValues

class Values{
 private:
  //  Double_t fx0, fy0, fvx0, fvy0;
  //TVector3 r0[np];
  // TVector3 r[np];
  //TVector3 v[np];
  //Int_t n[np];
     
 public:
  
  double X0(){gRandom->SetSeed(0);
  return gRandom->Uniform(0.001,0.999);}
  double Y0(){gRandom->SetSeed(0);
   return gRandom->Uniform(0.001, 0.999);}
  double VX0(){gRandom->SetSeed(0);
  return gRandom->Gaus(2, 1.0);}
  double VY0(){gRandom->SetSeed(0);
  return gRandom->Gaus(-2, 1.0);}
};


#endif
