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
#ifndef ROOT_Headers
#include"include/Headers.h"
#endif

#ifndef ROOT_HeaderValues
#include"include/HeaderValues.h"
#endif

#ifndef ROOT_HeaderGui
#include"include/HeaderGui.h"
#endif

void Demon(){

  new Mdemon(gClient -> GetRoot(),20,20);
 }
int main(int argc, char **argv)
{
  
  TApplication App("App",&argc,argv);
  Demon();
  App.Run();
  return 0;
} 
