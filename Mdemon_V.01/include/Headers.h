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
#define ROOT_Headers
#include "TList.h"
#include "TLatex.h"
#include "TPaveStats.h"
#include "TStyle.h"
#include "TApplication.h"
#include "TVector3.h"
#include "TLine.h"
#include "TArrow.h"
#include "TEllipse.h"
#include "TGraph.h"
#include "RQ_OBJECT.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TPaveText.h"
#include "TH3F.h"
#include "TF3.h"
#include "TFormula.h"
using namespace std;
#include <iostream>
#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif

#include "Riostream.h"

 #include "TROOT.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TSystem.h"
#include "TDirectory.h"
#include "Math/QuantFuncMathCore.h"
#include "TUUID.h"




//const Double_t dt = 0.001;
//const Double_t r1 = 0.005;

const Double_t r1 = 0.005;
const Double_t r2 = r1;
const Double_t t0 = 0.0;
const Double_t tf = 10.0; //segundos
const Double_t xMax = 1.0;
const Double_t yMax = 1.0;
const Double_t xMin = 0.0;
const Double_t yMin = 0.0;
//const Int_t np = 10;
const Double_t Div = 2.0;
const Double_t bWidth = 0.004;  // barrier width It should be less than 
const Double_t vMean = 3.0;
const Float_t arrSize = 0.01;
const Double_t scl = 20;

const Int_t np = 10000;

#endif
