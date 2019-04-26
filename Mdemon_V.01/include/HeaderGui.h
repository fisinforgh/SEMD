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
#ifndef ROOT_Mdemon
#define ROOT_Mdemon
#include "HeaderValues.h"
#include<time.h>
#include <ctime>

//Declarar la clase para la interfaz y simulacion
class Mdemon{
 private:
  //Declarando objetos de la clase Mdemon que pertenecen a la construccion de la interfaz
  RQ_OBJECT("Mdemon");
  TGMainFrame *MainFrame;
  TGCompositeFrame *MCompositeF1;
  TGCompositeFrame *MCompositeF2;
  TGCompositeFrame *MainFrame0;
  TGCompositeFrame *MainFrame2;
  TGCompositeFrame *fMainFrame1130;
  TGCompositeFrame *fMainFrame1476;
  TGVerticalFrame *fVerticalFrame556;
  TGHorizontalFrame *HFS;
  TGTab *Tab1;
  TGCompositeFrame *CompositeFrame1,*CompositeFrame2,*CompositeFrame3,*CompositeFrame4,*CompositeFrame5;
  TRootEmbeddedCanvas *RootEmbeddedCanvas1;
  TCanvas *Canvas1,*Canvas2,*Canvas3,*Canvas4,*Canvas5;
  TRootEmbeddedCanvas *CanvSimul,*CanvSimul2,*CanvSimul3,*CanvSimul4;
  //==============================================================================================================================
  TGGroupFrame *FirstGroupFrame;
  TGLabel *Label1,*Label2,*Label3,*Label4,*Label5,*Label6,*Label7;
  TGLabel *Label8,*Label9,*Label10,*Label11,*Label12,*Label13,*Label14;
  TGNumberEntry *Num1,*Num2,*Num3,*Num4,*Num5,*Num6,*Num7,*Num8,*Num9,*Num10,*Num11,*Num12,*Num13,*Num14;
  TGLabel *LabelUnits11,*LabelUnits12,*LabelUnits13,*LabelUnits14,*LabelUnits15,*LabelUnits16;
  TGLabel *LabelUnits17,*LabelUnits21,*LabelUnits22,*LabelUnits23,*LabelUnits24,*LabelUnits25,*LabelUnits26,*LabelUnits27;
  //==============================================================================================================================

  TGGroupFrame *fGroupFrame860;
  TGRadioButton *Arrows;
  TGLabel *Pref1;
  TGNumberEntry *NumPf1;
  TGLabel *Pref1LabelUnits;

  //==============================================================================================================================
  TGGroupFrame *fGroupFrame868;
  TGGroupFrame *LastGroupFrame;
  TGLabel *Pref2;
  TGNumberEntry *NumPf2;
  TGLabel *Pref2LabelUnit;
  //==============================================================================================================================

  TGNumberEntry *NMol1,*NMol2,*NTotal;
  TGNumberEntry *Temp1,*Temp2;
  TGLabel *ContN1,*ContN2,*ContNTotal;
  TGIcon *DemonIcon;
  TGLabel *TF1,*TF2;
  //==============================================================================================================================

  TGHorizontalFrame *HFB;
  TGTextButton *ButtonClear,*ButtonSimulate,*ButtonExit;
  TGCheckButton *ArrowsCheck;
  //==============================================================================================================================
  //===========================Declarando objetos de la simulacion================================================================
  TGraph *g1;
  TTimer *cont;
  Int_t IsActive;
  TGraph *G1;
  
  TEllipse *el[np];  
  TArrow *lel[np];  
  TVector3 r0[np];
  TVector3 r[np];
  TVector3 v[np];
  Int_t n[np];
  
  TLine *L1; 
  TLine *L2;
  Double_t t;
  Int_t ii;
  Int_t i=0;
  Int_t fx;
  Int_t fy;
  Double_t dt;
  Double_t temp1,  temp2, Pressure1, Pressure2, Volume1, Volume2;

  
  
  TEllipse *n1;
  //Declarando Funciones
  void Disable(){}
  void Enable(){}
  Double_t GetNp(){
    return NTotal->GetNumber();
  }  
  Double_t Np;
  
 public:
  

  Mdemon(const TGWindow *p, UInt_t w, UInt_t h){


    //Marco principal
   MainFrame = new TGMainFrame(gClient->GetRoot(),885,615,kMainFrame | kVerticalFrame);
   MainFrame->SetName("MainFrame");
   MainFrame->SetWindowName("Maxwell's Demon");
   MainFrame->SetLayoutBroken(kTRUE);
   MainFrame->SetWMSizeHints(885,615,100,100,0,0);
   MainFrame->Connect("CloseWindow()","Mdemon",this,"ButtonExitF()");
   MainFrame -> SetIconPixmap("Imagenes/DEMON1.png"); 

   // Marco secundario
   MCompositeF1 = new TGCompositeFrame(MainFrame,902,615,kVerticalFrame);
   MCompositeF1->SetName("MCompositeF1");
   MCompositeF1->SetLayoutBroken(kTRUE);

   // Marco secundario
   MCompositeF2 = new TGCompositeFrame(MCompositeF1,902,615,kVerticalFrame);
   MCompositeF2->SetName("MCompositeF2");
   MCompositeF2->SetLayoutBroken(kTRUE);

   // Marco secundario
   MainFrame0 = new TGCompositeFrame(MCompositeF2,906,613,kVerticalFrame);
   MainFrame0->SetName("MainFrame");
   MainFrame0->SetLayoutBroken(kTRUE);

   // Marco secundario
   MainFrame2 = new TGCompositeFrame(MainFrame,902,607,kVerticalFrame);
   MainFrame2->SetName("MainFrame2");
   MainFrame2->SetLayoutBroken(kTRUE);

   // Marco secundario
   fMainFrame1130 = new TGCompositeFrame(MainFrame2,896,611,kVerticalFrame);
   fMainFrame1130->SetName("fMainFrame1130");
   fMainFrame1130->SetLayoutBroken(kTRUE);

   // Marco secundario
   fMainFrame1476 = new TGCompositeFrame(fMainFrame1130,901,614,kVerticalFrame);
   fMainFrame1476->SetName("fMainFrame1476");
   //=====================================================
   //============Marco Vertical===========================
   // vertical frame
   fVerticalFrame556 = new TGVerticalFrame(fMainFrame1476,892,604,kVerticalFrame); 
   fVerticalFrame556->SetName("fVerticalFrame556");

   //====================================================================
   
   // Marco Horizontal
   HFS = new TGHorizontalFrame(fVerticalFrame556,888,552,kHorizontalFrame);
   HFS->SetName("HFS");
   HFS->SetLayoutBroken(kTRUE);

   //=====================================================================

   //====================================================================
   // Pestañas para los lienzos
   Tab1 = new TGTab(HFS,584,510);
   //====================================================================
   //  Contenedor de la primer pestaña

   CompositeFrame1 = Tab1->AddTab("Simulation");
   CompositeFrame1->SetLayoutManager(new TGVerticalLayout(CompositeFrame1));

   // Canvas
   RootEmbeddedCanvas1 = new TRootEmbeddedCanvas(0,CompositeFrame1,576,520,kSunkenFrame);
   Int_t wRootEmbeddedCanvas1 = RootEmbeddedCanvas1->GetCanvasWindowId();
   
   Canvas1 = new TCanvas("Canvas1", 10, 10, wRootEmbeddedCanvas1);
   RootEmbeddedCanvas1->AdoptCanvas(Canvas1);
   CompositeFrame1->AddFrame(RootEmbeddedCanvas1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));

   //===========================================================
   L1 = new TLine(0.5,1, 0.5, 0);
   L2 = new TLine(0.51,1, 0.51, 0);
   L1->SetLineWidth(6);
   L1->SetLineStyle(1);
   L2->SetLineWidth(6);
   L2->SetLineStyle(1);
   L1->Draw();
   L2->Draw();
   //===========================================================
   // Contenedor de la pestaña 2

   CompositeFrame2 = Tab1->AddTab("Graph1");
   CompositeFrame2->SetLayoutManager(new TGVerticalLayout(CompositeFrame2));

   // Canvas
   CanvSimul = new TRootEmbeddedCanvas(0,CompositeFrame2,576,490,kSunkenFrame);
   Int_t wRootEmbeddedCanvas2 = CanvSimul->GetCanvasWindowId();
   Canvas2 = new TCanvas("Canvas2", 10, 10, wRootEmbeddedCanvas2);
   CanvSimul->AdoptCanvas(Canvas2);
   CompositeFrame2->AddFrame(CanvSimul, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));

   //==========================================================

   
   // Contenedor de la pestaña 3

   CompositeFrame3 = Tab1->AddTab("Graph2");
   CompositeFrame3->SetLayoutManager(new TGVerticalLayout(CompositeFrame3));

   //Canvas
   CanvSimul2 = new TRootEmbeddedCanvas(0,CompositeFrame3,576,490,kSunkenFrame);
   Int_t wRootEmbeddedCanvas3 = CanvSimul2->GetCanvasWindowId();
   
   Canvas3 = new TCanvas("Canvas3", 10, 10, wRootEmbeddedCanvas3);
   CanvSimul2->AdoptCanvas(Canvas3);
   CompositeFrame3->AddFrame(CanvSimul2, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));

   //=============================================================
   // Contenedor de la pestaña 4

   CompositeFrame4 = Tab1->AddTab("Graph3");
   CompositeFrame4->SetLayoutManager(new TGVerticalLayout(CompositeFrame4));

   // Canvas
   CanvSimul3 = new TRootEmbeddedCanvas(0,CompositeFrame4,536,490,kSunkenFrame);
   Int_t wRootEmbeddedCanvas4 = CanvSimul3->GetCanvasWindowId();
   
   Canvas4 = new TCanvas("Canvas3", 10, 10, wRootEmbeddedCanvas4);
   CanvSimul3->AdoptCanvas(Canvas4);
   CompositeFrame4->AddFrame(CanvSimul3, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,2,2,2,2));


   Tab1->SetTab(0);
   Tab1->Resize(Tab1->GetDefaultSize());
   HFS->AddFrame(Tab1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Tab1->MoveResize(144,2,584,510);
      //=============================================================
   // Contenedor de la pestaña 5

   CompositeFrame5 = Tab1->AddTab("Graph4");
   CompositeFrame5->SetLayoutManager(new TGVerticalLayout(CompositeFrame5));

   //Canvas
   CanvSimul4 = new TRootEmbeddedCanvas(0,CompositeFrame5,576,490,kSunkenFrame);
   Int_t wRootEmbeddedCanvas5 = CanvSimul4->GetCanvasWindowId();
   
   Canvas5 = new TCanvas("Canvas3", 10, 10, wRootEmbeddedCanvas5);
   CanvSimul4->AdoptCanvas(Canvas5);
   CompositeFrame5->AddFrame(CanvSimul4, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));


   Tab1->SetTab(0);
   Tab1->Resize(Tab1->GetDefaultSize());
   HFS->AddFrame(Tab1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Tab1->MoveResize(144,2,584,510);

   //===========================================================================================================
   //=============================Marco de condiciones iniciales para las moleculas lentas======================
   //===========================================================================================================


   //Primer Grupo de condiciones
   FirstGroupFrame = new TGGroupFrame(HFS,"BoundaryConditions1");
   FirstGroupFrame->SetLayoutBroken(kTRUE);
   
   Label1 = new TGLabel(FirstGroupFrame,"N=");
   Label1->SetTextJustify(36);
   Label1->SetMargins(0,0,0,0);
   Label1->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(Label1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label1->MoveResize(8,24,32,21);
   
   Label2 = new TGLabel(FirstGroupFrame,"P=");
   Label2->SetTextJustify(36);
   Label2->SetMargins(0,0,0,0);
   Label2->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(Label2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label2->MoveResize(8,64,32,21);
   
   Label3 = new TGLabel(FirstGroupFrame,"T=");
   Label3->SetTextJustify(36);
   Label3->SetMargins(0,0,0,0);
   Label3->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(Label3, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label3->MoveResize(8,104,32,21);
   
   Label4 = new TGLabel(FirstGroupFrame,"V=");
   Label4->SetTextJustify(36);
   Label4->SetMargins(0,0,0,0);
   Label4->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(Label4, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label4->MoveResize(8,144,32,21);
   
   Label5 = new TGLabel(FirstGroupFrame,"U_i=");
   Label5->SetTextJustify(36);
   Label5->SetMargins(0,0,0,0);
   Label5->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(Label5, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label5->MoveResize(8,184,32,32);
   
   Num1 = new TGNumberEntry(FirstGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   FirstGroupFrame->AddFrame(Num1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num1->MoveResize(47,24,64,25);
   
   Num2 = new TGNumberEntry(FirstGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   FirstGroupFrame->AddFrame(Num2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num2->MoveResize(45,64,64,25);

   Num3 = new TGNumberEntry(FirstGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   FirstGroupFrame->AddFrame(Num3, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num3->MoveResize(45,104,64,25);
   
   Num4 = new TGNumberEntry(FirstGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   FirstGroupFrame->AddFrame(Num4, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num4->MoveResize(45,144,64,25);
   
   Num5 = new TGNumberEntry(FirstGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   FirstGroupFrame->AddFrame(Num5, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num5->MoveResize(45,189,64,25);

   LabelUnits11 = new TGLabel(FirstGroupFrame,"N");
   LabelUnits11->SetTextJustify(36);
   LabelUnits11->SetMargins(0,0,0,0);
   LabelUnits11->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(LabelUnits11, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits11->MoveResize(112,24,16,24);
    
   LabelUnits12 = new TGLabel(FirstGroupFrame,"atm");
   LabelUnits12->SetTextJustify(36);
   LabelUnits12->SetMargins(0,0,0,0);
   LabelUnits12->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(LabelUnits12, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits12->MoveResize(112,64,16,24);

   LabelUnits13 = new TGLabel(FirstGroupFrame,"K");
   LabelUnits13->SetTextJustify(36);
   LabelUnits13->SetMargins(0,0,0,0);
   LabelUnits13->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(LabelUnits13, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits13->MoveResize(112,104,16,24);
   
   
   LabelUnits14 = new TGLabel(FirstGroupFrame,"L");
   LabelUnits14->SetTextJustify(36);
   LabelUnits14->SetMargins(0,0,0,0);
   LabelUnits14->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(LabelUnits14, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits14->MoveResize(112,144,16,24);
      
   LabelUnits15 = new TGLabel(FirstGroupFrame,"J");
   LabelUnits15->SetTextJustify(36);
   LabelUnits15->SetMargins(0,0,0,0);
   LabelUnits15->SetWrapLength(-1);
   FirstGroupFrame->AddFrame(LabelUnits15, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits15->MoveResize(112,189,16,21);
   
   FirstGroupFrame->SetLayoutManager(new TGVerticalLayout(FirstGroupFrame));
   FirstGroupFrame->Resize(136,272);
   HFS->AddFrame(FirstGroupFrame, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   FirstGroupFrame->MoveResize(0,0,136,272);
   

   //===========================================================================================================
   //==============================Marco primero final==========================================================
   //===========================================================================================================


   fGroupFrame860 = new TGGroupFrame(HFS,"Output1");
   fGroupFrame860->SetLayoutBroken(kTRUE);
   
   ArrowsCheck = new TGCheckButton(fGroupFrame860,"Vectors");
   ArrowsCheck->MoveResize(8,176,106,24);
   ArrowsCheck->SetTextJustify(36);
   ArrowsCheck->SetMargins(0,0,0,0);
   ArrowsCheck->SetWrapLength(-1);
   fGroupFrame860->AddFrame(ArrowsCheck, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ArrowsCheck->SetState(kButtonUp);


   //=========================Primera salida numerica=============================================================
   Pref1 = new TGLabel(fGroupFrame860,"P=");
   Pref1->SetTextJustify(36);
   Pref1->SetMargins(0,0,0,0);
   Pref1->SetWrapLength(-1);
   fGroupFrame860->AddFrame(Pref1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Pref1->MoveResize(8,24,32,21);
   
   NumPf1 = new TGNumberEntry(fGroupFrame860, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame860->AddFrame(NumPf1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   NumPf1->MoveResize(48,24,56,25);
   
   Pref1LabelUnits = new TGLabel(fGroupFrame860,"atm");
   Pref1LabelUnits->SetTextJustify(36);
   Pref1LabelUnits->SetMargins(0,0,0,0);
   Pref1LabelUnits->SetWrapLength(-1);
   fGroupFrame860->AddFrame(Pref1LabelUnits, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Pref1LabelUnits->MoveResize(112,24,16,21);

   Label6 = new TGLabel(fGroupFrame860,"U_f=");
   Label6->SetTextJustify(36);
   Label6->SetMargins(0,0,0,0);
   Label6->SetWrapLength(-1);
   fGroupFrame860->AddFrame(Label6, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label6->MoveResize(8,84,32,21);
   
   Label7 = new TGLabel(fGroupFrame860,"S_fi=");
   Label7->SetTextJustify(36);
   Label7->SetMargins(0,0,0,0);
   Label7->SetWrapLength(-1);
   fGroupFrame860->AddFrame(Label7, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label7->MoveResize(8,144,32,24);

   Num6 = new TGNumberEntry(fGroupFrame860, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame860->AddFrame(Num6, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num6->MoveResize(45,84,56,25);
   
   Num7 = new TGNumberEntry(fGroupFrame860, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame860->AddFrame(Num7, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num7->MoveResize(45,144,56,25);

   LabelUnits16 = new TGLabel(fGroupFrame860,"J");
   LabelUnits16->SetTextJustify(36);
   LabelUnits16->SetMargins(0,0,0,0);
   LabelUnits16->SetWrapLength(-1);
   fGroupFrame860->AddFrame(LabelUnits16, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits16->MoveResize(112,84,16,24);
   
   LabelUnits17 = new TGLabel(fGroupFrame860,"J/K");
   LabelUnits17->SetTextJustify(36);
   LabelUnits17->SetMargins(0,0,0,0);
   LabelUnits17->SetWrapLength(-1);
   fGroupFrame860->AddFrame(LabelUnits17, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits17->MoveResize(112,144,16,24);


   

   
   fGroupFrame860->SetLayoutManager(new TGVerticalLayout(fGroupFrame860));
   fGroupFrame860->Resize(136,240);
   HFS->AddFrame(fGroupFrame860, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame860->MoveResize(2,280,136,240);


   //===========================================================================================================
   //======================================Etiqueta moleculas mas rapidas=======================================
   //===========================================================================================================

  
   fGroupFrame868 = new TGGroupFrame(HFS,"BoundaryConditions2");
   fGroupFrame868->SetLayoutBroken(kTRUE);
   
   Label8 = new TGLabel(fGroupFrame868,"NN=");
   Label8->SetTextJustify(36);
   Label8->SetMargins(0,0,0,0);
   Label8->SetWrapLength(-1);
   fGroupFrame868->AddFrame(Label8, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label8->MoveResize(8,24,32,21);
   
   Label9 = new TGLabel(fGroupFrame868,"P=");
   Label9->SetTextJustify(36);
   Label9->SetMargins(0,0,0,0);
   Label9->SetWrapLength(-1);
   fGroupFrame868->AddFrame(Label9, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label9->MoveResize(8,64,32,21);
     
   Label10 = new TGLabel(fGroupFrame868,"T=");
   Label10->SetTextJustify(36);
   Label10->SetMargins(0,0,0,0);
   Label10->SetWrapLength(-1);
   fGroupFrame868->AddFrame(Label10, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label10->MoveResize(8,104,32,21);
   
   Label11 = new TGLabel(fGroupFrame868,"V=");
   Label11->SetTextJustify(36);
   Label11->SetMargins(0,0,0,0);
   Label11->SetWrapLength(-1);
   fGroupFrame868->AddFrame(Label11, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label11->MoveResize(8,144,32,24);
   
   Label12 = new TGLabel(fGroupFrame868,"U_i=");
   Label12->SetTextJustify(36);
   Label12->SetMargins(0,0,0,0);
   Label12->SetWrapLength(-1);
   fGroupFrame868->AddFrame(Label12, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label12->MoveResize(8,189,32,21);

   Num8 = new TGNumberEntry(fGroupFrame868, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame868->AddFrame(Num8, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num8->MoveResize(47,24,64,25);
   
   Num9 = new TGNumberEntry(fGroupFrame868, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame868->AddFrame(Num9, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num9->MoveResize(47,64,64,25);
   
   Num10 = new TGNumberEntry(fGroupFrame868, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame868->AddFrame(Num10, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num10->MoveResize(47,104,64,25);
   
   Num11 = new TGNumberEntry(fGroupFrame868, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame868->AddFrame(Num11, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num11->MoveResize(47,144,64,25);
   
   Num12 = new TGNumberEntry(fGroupFrame868, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   fGroupFrame868->AddFrame(Num12, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num12->MoveResize(47,189,64,25);

   LabelUnits21 = new TGLabel(fGroupFrame868,"N");
   LabelUnits21->SetTextJustify(36);
   LabelUnits21->SetMargins(0,0,0,0);
   LabelUnits21->SetWrapLength(-1);
   fGroupFrame868->AddFrame(LabelUnits21, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits21->MoveResize(112,24,16,24);
   
   LabelUnits22 = new TGLabel(fGroupFrame868,"atm");
   LabelUnits22->SetTextJustify(36);
   LabelUnits22->SetMargins(0,0,0,0);
   LabelUnits22->SetWrapLength(-1);
   fGroupFrame868->AddFrame(LabelUnits22, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits22->MoveResize(112,64,16,24);
   
   LabelUnits23 = new TGLabel(fGroupFrame868,"K");
   LabelUnits23->SetTextJustify(36);
   LabelUnits23->SetMargins(0,0,0,0);
   LabelUnits23->SetWrapLength(-1);
   fGroupFrame868->AddFrame(LabelUnits23, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits23->MoveResize(112,104,16,24);
   
   LabelUnits24 = new TGLabel(fGroupFrame868,"L");
   LabelUnits24->SetTextJustify(36);
   LabelUnits24->SetMargins(0,0,0,0);
   LabelUnits24->SetWrapLength(-1);
   fGroupFrame868->AddFrame(LabelUnits24, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits24->MoveResize(112,144,16,24);
   
   LabelUnits25 = new TGLabel(fGroupFrame868,"J");
   LabelUnits25->SetTextJustify(36);
   LabelUnits25->SetMargins(0,0,0,0);
   LabelUnits25->SetWrapLength(-1);
   fGroupFrame868->AddFrame(LabelUnits25, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits25->MoveResize(112,189,16,24);

   fGroupFrame868->SetLayoutManager(new TGVerticalLayout(fGroupFrame868));
   fGroupFrame868->Resize(136,272);
   HFS->AddFrame(fGroupFrame868, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   fGroupFrame868->MoveResize(744,0,136,272);
   //==============================================================================================================
   //================================Salida Numerica 2=============================================================
   //==============================================================================================================

   LastGroupFrame = new TGGroupFrame(HFS,"Output2");
   LastGroupFrame->SetLayoutBroken(kTRUE);
   
   Pref2 = new TGLabel(LastGroupFrame,"P=");
   Pref2->SetTextJustify(36);
   Pref2->SetMargins(0,0,0,0);
   Pref2->SetWrapLength(-1);
   LastGroupFrame->AddFrame(Pref2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Pref2->MoveResize(8,24,24,24);

   Label13 = new TGLabel(LastGroupFrame,"U_f=");
   Label13->SetTextJustify(36);
   Label13->SetMargins(0,0,0,0);
   Label13->SetWrapLength(-1);
   LastGroupFrame->AddFrame(Label13, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label13->MoveResize(8,84,32,21);
   
   Label14 = new TGLabel(LastGroupFrame,"S_fi=");
   Label14->SetTextJustify(36);
   Label14->SetMargins(0,0,0,0);
   Label14->SetWrapLength(-1);
   LastGroupFrame->AddFrame(Label14, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Label14->MoveResize(8,144,32,21);
   
   NumPf2 = new TGNumberEntry(LastGroupFrame, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   LastGroupFrame->AddFrame(NumPf2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   NumPf2->MoveResize(40,24,61,25);

   Num13 = new TGNumberEntry(LastGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   LastGroupFrame->AddFrame(Num13, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num13->MoveResize(40,84,64,25);
   
   Num14 = new TGNumberEntry(LastGroupFrame, (Double_t) 0,6,-1,(TGNumberFormat::EStyle) 5);
   LastGroupFrame->AddFrame(Num14, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Num14->MoveResize(40,144,64,25);
   
   Pref2LabelUnit = new TGLabel(LastGroupFrame,"atm");
   Pref2LabelUnit->SetTextJustify(36);
   Pref2LabelUnit->SetMargins(0,0,0,0);
   Pref2LabelUnit->SetWrapLength(-1);
   LastGroupFrame->AddFrame(Pref2LabelUnit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Pref2LabelUnit->MoveResize(104,24,24,21);


   LabelUnits26 = new TGLabel(LastGroupFrame,"J");
   LabelUnits26->SetTextJustify(36);
   LabelUnits26->SetMargins(0,0,0,0);
   LabelUnits26->SetWrapLength(-1);
   LastGroupFrame->AddFrame(LabelUnits26, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits26->MoveResize(104,84,16,24);
   
   LabelUnits27 = new TGLabel(LastGroupFrame,"J/K");
   LabelUnits27->SetTextJustify(36);
   LabelUnits27->SetMargins(0,0,0,0);
   LabelUnits27->SetWrapLength(-1);
   LastGroupFrame->AddFrame(LabelUnits27, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LabelUnits27->MoveResize(104,144,16,24);

   LastGroupFrame->SetLayoutManager(new TGVerticalLayout(LastGroupFrame));
   LastGroupFrame->Resize(136,229);
   HFS->AddFrame(LastGroupFrame, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LastGroupFrame->MoveResize(744,288,136,229);
   //===========================================================================================================  
   NMol1 = new TGNumberEntry(HFS, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   NMol1->SetName("NMol1");
   HFS->AddFrame(NMol1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   NMol1->MoveResize(185,520,61,25);
   
   Temp1 = new TGNumberEntry(HFS, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   Temp1->SetName("Temp1");
   
   HFS->AddFrame(Temp1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Temp1->MoveResize(296,520,61,25);


   //============================================================================================================
   NTotal = new TGNumberEntry(HFS, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 0);
   NTotal->SetName("NTotal");
   HFS->AddFrame(NTotal, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   NTotal->MoveResize(420,520,61,25);
   
   ContNTotal = new TGLabel(HFS,"NT=");
   ContNTotal->SetTextJustify(36);
   ContNTotal->SetMargins(0,0,0,0);
   ContNTotal->SetWrapLength(-1);
   HFS->AddFrame(ContNTotal, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ContNTotal->MoveResize(380,520,32,24);

 
   //===========================================================================================================

   
   NMol2 = new TGNumberEntry(HFS, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   NMol2->SetName("NMol2");
   HFS->AddFrame(NMol2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   NMol2->MoveResize(557,520,61,25);
   
   Temp2 = new TGNumberEntry(HFS, (Double_t) 0,5,-1,(TGNumberFormat::EStyle) 5);
   Temp2->SetName("Temp2");
   HFS->AddFrame(Temp2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   Temp2->MoveResize(656,520,61,25);
   
   ContN1 = new TGLabel(HFS,"N1=");
   ContN1->SetTextJustify(36);
   ContN1->SetMargins(0,0,0,0);
   ContN1->SetWrapLength(-1);
   HFS->AddFrame(ContN1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ContN1->MoveResize(152,520,32,24);
   
   TF1 = new TGLabel(HFS,"T1=");
   TF1->SetTextJustify(36);
   TF1->SetMargins(0,0,0,0);
   TF1->SetWrapLength(-1);
   HFS->AddFrame(TF1, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   TF1->MoveResize(258,520,32,24);
   
   ContN2 = new TGLabel(HFS,"N2=");
   ContN2->SetTextJustify(36);
   ContN2->SetMargins(0,0,0,0);
   ContN2->SetWrapLength(-1);
   HFS->AddFrame(ContN2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ContN2->MoveResize(522,520,32,24);
   
   TF2 = new TGLabel(HFS,"T2=");
   TF2->SetTextJustify(36);
   TF2->SetMargins(0,0,0,0);
   TF2->SetWrapLength(-1);
   HFS->AddFrame(TF2, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   TF2->MoveResize(635,520,16,24);

   fVerticalFrame556->AddFrame(HFS, new TGLayoutHints(kLHintsNormal));
   //=========================================================================================================
   //=======================================Botones=====================================================
   //=========================================================================================================
   
   HFB = new TGHorizontalFrame(fVerticalFrame556,888,48,kHorizontalFrame);
   HFB->SetName("HFB");
   HFB->SetLayoutBroken(kTRUE);
   
   ButtonSimulate = new TGTextButton(HFB,"Simulate",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   ButtonSimulate->SetTextJustify(36);
   ButtonSimulate->SetMargins(0,0,0,0);
   ButtonSimulate->SetWrapLength(-1);
   ButtonSimulate->Resize(200,40);
   HFB->AddFrame(ButtonSimulate, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ButtonSimulate->MoveResize(8,8,200,40);
   
   ButtonClear = new TGTextButton(HFB,"Clear",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   ButtonClear->SetTextJustify(36);
   ButtonClear->SetMargins(0,0,0,0);
   ButtonClear->SetWrapLength(-1);
   ButtonClear->Resize(200,40);
   HFB->AddFrame(ButtonClear, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ButtonClear->MoveResize(337,8,200,40);

   ButtonExit = new TGTextButton(HFB,"Exit",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   ButtonExit->SetTextJustify(36);
   ButtonExit->SetMargins(0,0,0,0);
   ButtonExit->SetWrapLength(-1);
   ButtonExit->Resize(200,40);
   HFB->AddFrame(ButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ButtonExit->MoveResize(677,8,200,40);

   fVerticalFrame556->AddFrame(HFB, new TGLayoutHints(kLHintsNormal));

   fMainFrame1476->AddFrame(fVerticalFrame556, new TGLayoutHints(kLHintsNormal));

   fMainFrame1130->AddFrame(fMainFrame1476, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1476->MoveResize(0,0,901,614);

   MainFrame2->AddFrame(fMainFrame1130, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   fMainFrame1130->MoveResize(0,0,896,611);

   MainFrame0->AddFrame(MainFrame2, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   MainFrame2->MoveResize(0,0,902,607);

   MCompositeF2->AddFrame(MainFrame0, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   MainFrame0->MoveResize(0,0,906,613);

   MCompositeF1->AddFrame(MCompositeF2, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   MCompositeF2->MoveResize(0,0,902,615);

   MainFrame->AddFrame(MCompositeF1, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
   MCompositeF1->MoveResize(0,0,902,615);

   MainFrame->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   MainFrame->MapSubwindows();

   MainFrame->Resize(MainFrame->GetDefaultSize());
   MainFrame->MapWindow();
   MainFrame->Resize(899,615);
 

   //====================================================================================================
  
   
   TLine *L3=new TLine(1,1, 1, 1);
   L3->SetLineWidth(6);
   L3->SetLineStyle(1);
   L3->Draw();
   ButtonExit->Connect("Clicked()","Mdemon",this,"ButtonExitF()");
   ButtonClear->Connect("Clicked()","Mdemon",this,"ButtonClearF()");
   ButtonSimulate->Connect("Clicked()","Mdemon",this,"ButtonPlayF()");
   ButtonSimulate->SetEnabled(kTRUE);
   ButtonClear->SetEnabled(kFALSE);
   
   Num1 ->SetState(kFALSE);
   Num2 ->SetState(kFALSE);
   Num3 ->SetState(kFALSE);
   Num4 ->SetState(kFALSE);
   Num5 ->SetState(kFALSE);
   Num6 ->SetState(kFALSE);
   Num7 ->SetState(kFALSE);
   Num8 ->SetState(kFALSE);
   Num9 ->SetState(kFALSE);
   Num10->SetState(kFALSE);
   Num11->SetState(kFALSE);
   Num12->SetState(kFALSE);
   Num13->SetState(kFALSE);
   Num14->SetState(kFALSE);
   NMol1->SetState(kFALSE);
   NMol2->SetState(kFALSE);
   Temp1->SetState(kFALSE);
   Temp2->SetState(kFALSE);
   NumPf1->SetState(kFALSE);
   NumPf2->SetState(kFALSE);

   //Contador
   
   cont= new TTimer(100);
   cont->Connect("Timeout()","Mdemon",this,"ButtonPlayF()");
   g1=new TGraph();
   IsActive = -1;
   
  }

  //Destructor
  virtual ~Mdemon(){
    MainFrame->Cleanup();
    delete MainFrame;
}
  void SimulateF(){
    ButtonClear->SetEnabled(kTRUE);    
    NTotal->SetState(kFALSE);
    ButtonSimulate->SetEnabled(kFALSE);
    /*    clock_t start = clock();
    algorithm();
    clock_t end = clock();
    double time = (double)(end-start)/ CLOCKS_PER_SEC*1000.0;*/
    time_t now = time(0);
    char* dh = ctime(&now);
    cout<<dh;
    if(GetNp()<=3000 && GetNp()>0){
      
      cont->Start(200000, kTRUE);
      //====================================================================================
      i=0;
      fx=0;
      fy=0;
      Int_t hx=0;
      Int_t hy=0;
      ofstream file;
      file.open("Velocity.txt");
      
      while(i < GetNp() ){
	
	Values *b= new Values();
	n[i] = 0;
	r0[i].SetXYZ(b->X0(),b->Y0(),0);
	r[i].SetXYZ(b->X0(),b->Y0(),0);
	v[i].SetXYZ(b->VX0(),b->VY0(),0);
	file << v[i].Mag() << endl;
	
	if(r0[i].X() < xMax/Div )
	  {
	    hx=hx+1;
	  }
	else{
	  hy=hy+1;
	}
	
	if(v[i].Mag() < vMean){
	  fx=fx+1;
	}
	else{
	  fy=fy+1;
	}
	
	i++; 
      }
      
      file.close();
      
      //===================================================================================================
      //SIMULACION DISTRIBUCION DE MAXWELL
      
      Canvas2->cd();
      Canvas2->Update();
      Canvas2->Modified();
      Float_t x,y,z;      
      Axis_t v1,v2,v3;
      Double_t w1,w2,w3;
      TFormula *hmodel;
      TF3 *maxbolt;
      
      hmodel = new TFormula("MB"," (4*TMath::Pi()*100000 *(pow(x,2)+pow(y,2)+pow(z,2) )*exp(-1*(pow(x,2)+pow(y,2)+pow(z,2) ))/1)");
      maxbolt = new TF3("Maxwell-Boltzmann","MB",-10,10,-10,10,-10,10);
      
      TH3F *t1 = new TH3F("t1","gaussian",100,-5,5,100,-5,5,100,-5,5); 
      TH1F *speed = new TH1F("Velocities Right-Side","Maxwell-Boltzman Distribution Histogram Right-Side",100,0,2500);
      TH1F *w = new TH1F("w1","Speed",100,0,5);
      t1->FillRandom("Maxwell-Boltzmann",1000000);
      
      for(Int_t i=0; i< fx; i++)
	{
	  
	  t1->GetRandom3(v1,v2,v3);
	  Float_t vel = 500*sqrt(pow(v1,2)+pow(v2,2)+pow(v3,2))+100;
	  speed->Fill(vel);
	  maxbolt->GetRandom3(w1,w2,w3);
	  vel = sqrt(pow(w1,2)+pow(w2,2)+pow(w3,2));
	  w->Fill(vel+1); 
	  
	}
      
      maxbolt->SetNpx(200);
      maxbolt->SetNpy(200);
      maxbolt->SetNpz(200);
      speed->Draw();
      w->Draw("same");
      string e = "molecules";
      //gStyle->SetOptStat("men");
      gStyle->SetOptStat("men");
      gStyle->SetTitleYOffset(1.2);
      gStyle->SetTextSize(0.1);
      /*TPaveStats *s = (TPaveStats*) gPad->GetPrimitive("stats");
      //s->SetTextSize(0.1);
      //s->SetX1NDC(0.5);
      //s->SetY1NDC(0.5);
      s = (TPaveStats*)Canvas2->GetPrimitive("stats");
      TList *listOfLines = s->GetListOfLines();
      TLatex *myt = new TLatex(0,0,"Test = 10");
      myt ->SetTextFont(42);
      myt ->SetTextSize(0.04);
      myt ->SetTextColor(kRed);
      listOfLines->Add(myt);
      w->SetStats("men");
      */
      speed->GetXaxis()->SetTitle("Velocity(m/s)");
      speed->GetYaxis()->SetTitle("Frequency");
      speed->GetXaxis()->CenterTitle();
      speed->GetYaxis()->CenterTitle();
      
      Canvas2->cd();
      Canvas2->Update();
      Canvas2->Modified();
      //===================================================================================================
      //SIMULACION DISTRIBUCION DE MAXWELL
      
      Canvas3->cd();
      Canvas3->Update();
      Canvas3->Modified();
      Float_t xx,yy,zz;      
      Axis_t vv1,vv2,vv3;
      Double_t ww1,ww2,ww3;
      TFormula *hmodel2;
      TF3 *maxbolt2;
      
      hmodel2 = new TFormula("MB","(4*TMath::Pi()*100000 *(pow(x,2)+pow(y,2)+pow(z,2))*exp(-1*(pow(x,2)+pow(y,2)+pow(z,2) ))/1)");
      maxbolt2 = new TF3("Maxwell-Boltzmann","MB",-10,10,-10,10,-10,10);
      TH3F *tt1 = new TH3F("tt1","gaussian",100,-5,5,100,-5,5,100,-5,5); 
      TH1F *sspeed = new TH1F("Velocities Left-Side","Maxwell-Boltzman Distribution Histogram Left-Side",100,0,2500);
      TH1F *ww = new TH1F("w2","Speed2",100,0,5);
      tt1->FillRandom("Maxwell-Boltzmann",1000000);
      //=====================================================
      for(Int_t i=0; i< fy; i++)
	{
	  tt1->GetRandom3(v1,v2,v3);
	  Float_t vvel = 100*sqrt(pow(v1,2)+pow(v2,2)+pow(v3,2))+100;
	  sspeed->Fill(vvel);	  
	  maxbolt2->GetRandom3(w1,w2,w3);
	  vvel = sqrt(pow(w1,2)+pow(w2,2)+pow(w3,2));
	  ww->Fill(vvel+1); 
	  
	}
      
      maxbolt2->SetNpx(200);
      maxbolt2->SetNpy(200);
      maxbolt2->SetNpz(200);
      if(ButtonClear->IsEnabled()==true){
	sspeed->Draw();
	ww->Draw("same");}
      sspeed->GetXaxis()->SetTitle("Velocity(m/s)");
      sspeed->GetYaxis()->SetTitle("Frequency");
      sspeed->GetXaxis()->CenterTitle();
      sspeed->GetYaxis()->CenterTitle();

      Canvas3->cd();
      Canvas3->Update();
      Canvas3->Modified();

      delete t1;
      delete tt1;
      delete w;
      delete ww;
       
      //===================================================================================================
      //Expresiones y algoritmo que calculan las cantidades fisica
      //===================================================================================================
      Double_t dS;
      Double_t dW;
      Double_t Ent,Entdos;
      Double_t U1,U2,U3,U4;
      Double_t Tmp1,Tmp2,V;
      Double_t Pini1,Pini2,Pfin1,Pfin2;
      long double max;
      long double m;
      
      V=0.00005;
      m=4.8173e-23;
      
      temp1 = ((0.5*m*433)/(TMath::K()));;
      temp2 = ((0.5*m* sspeed->GetMean() )/(TMath::K()));; 
      
      Tmp1 = ((0.5*m*533)/(TMath::K()));
      Tmp2 = ((0.5*m*speed->GetMean()) /(TMath::K()));      
      
      Pini1=     hx*TMath::K()*temp1/V;
      Pini2=     hy*TMath::K()*temp2/V;
      Pfin1=     fx*TMath::K()*Tmp1/V;
      Pfin2=     fy*TMath::K()*Tmp2/V;
      
      Ent    = fx*TMath::K()*( log((temp1)/(temp2))+log((Pini1) / (Pini2)));
      Entdos = fy*TMath::K()*(log((Tmp1)/(Tmp2))+log((Pfin1)/(Pfin2)) );      
      
      U1=hx*temp1*TMath::K();
      U2=hy*temp2*TMath::K();
      U3=hx*Tmp1*TMath::K();
      U4=hx*Tmp2*TMath::K();
      //================================================================
      //==================Numeros de entrada y salida===================
      //================================================================
      
      Num1->SetNumber(hx);
      Num2->SetNumber(Pini1);
      Num3->SetNumber(temp1);
      Num4->SetNumber(V);
      Num5->SetNumber(U1);
      Num6->SetNumber(U3);
      Num7->SetNumber(Ent);
      Num8->SetNumber(hy);
      
      Num9->SetNumber(Pini1);
      Num10->SetNumber(Tmp1);
      Num11->SetNumber(V);
      Num12->SetNumber(U2);
      Num13->SetNumber(U4);
      Num14->SetNumber(Entdos);      
      
      NMol1->SetNumber(fy);
      NMol2->SetNumber(fx);
      Temp1->SetNumber(temp2);
      Temp2->SetNumber(Tmp2);
      NumPf1->SetNumber(Pfin1);
      NumPf2->SetNumber(Pfin2);      
      
      //================================================================
      //==========Diagrama T-s lado izquierdo===========================
      //================================================================
      Canvas4 -> cd();
      Canvas4 -> Update();
      Canvas4 -> Modified();
      Canvas4 -> SetGrid();
      Double_t KK;
      TGraph *dts;
      dts=new TGraph();
      Int_t NN;
      NN=0;
      Double_t DS;
      for (KK=temp1+1; KK<=1000; KK+=0.1)
	{
	  Ent    = fx*TMath::K()*( log((temp1)/(KK))+log((Pini1) / (KK) ));
	  dts->SetPoint(NN,Ent,KK);
	  dts->SetMarkerColor(2);
	  NN++;
	}
      dts->SetTitle(" T-S Diagram Left Side");
      dts->GetXaxis()->SetTitle("S(J/K)");
      dts->SetLineWidth(2);
      dts->GetYaxis()->SetTitle("T(K)");      
      dts->Draw("APL");
      dts->GetXaxis()->CenterTitle();
      dts->GetYaxis()->CenterTitle();
      dts->GetYaxis()->SetLabelSize(0.03);
      dts->GetXaxis()->SetLabelSize(0.03); 
      Canvas4->cd();
      Canvas4->Update();
      Canvas4->Modified();
      //================================================================
      //==========Diagrama T-s para el lado derecho=====================
      //================================================================
      
      Canvas5 -> cd();
      Canvas5 -> Update();
      Canvas5 -> Modified();
      Canvas5 -> SetGrid();
      
      Double_t LL;
      TGraph *dts2;
      dts2=new TGraph();
      Int_t MM;
      MM=0;
      Double_t DS2;
      for (LL=Tmp1; LL<=1000; LL+=0.1)
	{
	  Entdos = fy*TMath::K()*(log((Tmp1)/(LL))+log((Pfin1)/(LL)) );
	  dts2->SetPoint(MM,Entdos,LL);
	  dts2->SetMarkerColor(2);
	  MM++;
	}
      dts2->SetTitle("T-S Diagram Rigth Side");
      dts2->GetXaxis()->SetTitle("S(J/K)");
      dts2->SetLineWidth(2);
      dts2->GetYaxis()->SetTitle("T(K)");
      dts2->Draw("APL");
      dts2->GetXaxis()->CenterTitle();
      dts2->GetYaxis()->CenterTitle();
      dts2->GetYaxis()->SetLabelSize(0.03);
      dts2->GetXaxis()->SetLabelSize(0.03); 

      Canvas5->cd();
      Canvas5->Update();
      Canvas5->Modified();
      Canvas5->Resize();
      
      //====================================================================================
      //Para dibujar las moleculas
      
      while(n>=0)
	{
	  
	  if(ButtonClear->IsEnabled()==false){
	    break;
	    
	  }
	  
	  ii=0;
	  
	  while(ii < GetNp()){
	    
	    gSystem->ProcessEvents();
	    n[ii]++;
	    //=========================================================
	    //el tiempo va corriendo de acuerdo al numero de moleculas
	    //=========================================================
	    if(GetNp()<=100){
	      dt=0.001;
	    }
	    else {
	      dt=0.001;
	    }
	    t = t0 + n[ii]*dt;
	    //====================================================================================
	    //Configurando el constructor para generar las elipses y flechas
	    
	    r[ii].SetX(r0[ii].X() + v[ii].X()*t);
	    r[ii].SetY(r0[ii].Y() + v[ii].Y()*t);
	    el[ii] = new TEllipse(r[ii].X(),r[ii].Y(), r1, r1, 0, 360, 0);
	    lel[ii] = new TArrow(r[ii].X(),r[ii].Y(),r[ii].X() + v[ii].X()*scl*dt,r[ii].Y() + v[ii].Y()*scl*dt,arrSize,"|>");
	    //======================================================================================================
	    //Si la magnitud del vector es menor que vMean=2.5 pintelas de (2) sino de (3)
	    // EL MAG ME CALCULA EL RADIO EN COORDENADAS ESFERICAS
	    
	    if(v[ii].Mag() < vMean){
	      gSystem->ProcessEvents();
	      el[ii]->SetFillColor(2);
	      lel[ii]->SetLineColor(2);
	    }
	    else{
	      gSystem->ProcessEvents();
	      el[ii]->SetFillColor(3);
	      lel[ii]->SetFillColor(3);
	    }
	    
	    //====================================================================================
	    //SI LA COMPONENTE EN X ES MAYOR QUE 1/2 - 0.004 Y MENOR O IGUAL QUE 1/2
	    // SI LA VELOCIDAD ES MAYOR QUE 0
	    // Moleculas del lado izquierdo
	    
	    if((r[ii].X() > (xMax/Div - bWidth)) && (r[ii].X() <= xMax/Div)){
	      gSystem->ProcessEvents();
	      
	      if(v[ii].X() > 0){
		gSystem->ProcessEvents();
		
		if(v[ii].Mag() < vMean){
		  gSystem->ProcessEvents();
		  v[ii].SetX(-v[ii].X());
		  r0[ii].SetX(xMax/Div);
		  r0[ii].SetY(r[ii].Y());
		  n[ii] = 0;
		}
		
	      }      
	    }
	    //====================================================================================
	    //SI LA COMPONENTE EN X ES MENOR O IGUAL QUE 1/2 +0.004 Y MAYOR QUE 1/2
	    //SI LA VELOCIDAD ES MENOR QUE 0
	    //Moleculas del lado derecho
	    //====================================================================================
	    
	    if((r[ii].X() <= (xMax/Div + bWidth)) && (r[ii].X() > xMax/Div)){
	      gSystem->ProcessEvents();
	      
	      if(v[ii].X() < 0){
		gSystem->ProcessEvents();
		
		if(v[ii].Mag() >= vMean){
		  gSystem->ProcessEvents();
		  v[ii].SetX(-v[ii].X());
		  r0[ii].SetX(xMax/Div);
		  r0[ii].SetY(r[ii].Y());
		  n[ii] = 0;
		}
	      }      
	    }
	    
	    //====================================================================================
	    //====si la magnitud de x es mayor que xmax haga lo siguiente igual para los demas====
	    //====================================================================================
	    if(r[ii].X() > xMax){
	      gSystem->ProcessEvents();
	      v[ii].SetX(-v[ii].X());
	      r0[ii].SetX(xMax);
	      r0[ii].SetY(r[ii].Y());
	      n[ii] = 0;
	    }
	    
	    if(r[ii].X() < xMin/2.0){
	      gSystem->ProcessEvents();
	      v[ii].SetX(-v[ii].X());
	      r0[ii].SetX(xMin);
	      r0[ii].SetY(r[ii].Y());
	      n[ii] = 0;
	    }
	    if(r[ii].Y() > yMax){
	      gSystem->ProcessEvents();
	      v[ii].SetY(-v[ii].Y());
	      r0[ii].SetY(yMax);
	      r0[ii].SetX(r[ii].X());
	      n[ii] = 0;
	    }
	    
	    if(r[ii].Y() < yMin){
	      gSystem->ProcessEvents();
	      v[ii].SetY(-v[ii].Y());
	      r0[ii].SetY(yMin);
	      r0[ii].SetX(r[ii].X());
	      n[ii] = 0;
	    }
	    
	    el[ii]->Draw();
	    if( ArrowsCheck->IsDown() )
	      {
		lel[ii]->Draw();
		
	      }
	    ii++;
	  }
	  
	  //=======================================================
	  //Updating Canvas
	  //=======================================================
	  Canvas1->cd();
	  Canvas1->Update();
	  Canvas1->Modified();
	    
	  //=======================================================
	  //Eliminando los arreglos para limpiar memoria
	  //=======================================================
	  for(int iiii = 0; iiii < GetNp(); iiii++){
	    delete el[iiii];
	    delete lel[iiii];
	  }
	}
    }
    
    //============================================================================================
    //Cuando el numero de moleculas es mayor a 3000


    else{
      
      //Avisos de advertencia para volver al estado inicial  
      
      Canvas1->cd();
      TPaveText *ct = new TPaveText(.05,.1,.95,.9);
      ct->AddText("Simulation are not able to run");
      ct->AddText("Max 3000 particles");
      ct->Draw();
      ct->SetLabel("Maxwell's Demon");
      Canvas1->Update();
      
      Canvas2->cd();
      ct = new TPaveText(.05,.1,.95,.9);
      ct->AddText("Simulation are not able to run");
      ct->AddText("Max 3000 particles");
      ct->Draw();
      ct->SetLabel("Maxwell's Demon");
      Canvas2->Update();
      
      Canvas3->cd();
      ct = new TPaveText(.05,.1,.95,.9);
      ct->AddText("Simulation are not able to run");
      ct->AddText("Max 3000 particles");
      ct->Draw();
      ct->SetLabel("Maxwell's Demon");
      Canvas3->Update();
      
      Canvas4->cd();
      ct = new TPaveText(.05,.1,.95,.9);
      ct->AddText("Simulation are not able to run");
      ct->AddText("Max 3000 particles");
      ct->Draw();
      ct->SetLabel("Maxwell's Demon");
      Canvas4->Update();
      
      Canvas5->cd();
      ct = new TPaveText(.05,.1,.95,.9);
      ct->AddText("Simulation are not able to run");
      ct->AddText("Max 3000 particles");
      ct->Draw();
      ct->SetLabel("Maxwell's Demon");
      Canvas5->Update();
      
      ButtonSimulate->SetEnabled(kFALSE);
      Num2 ->SetState(kFALSE);
      Num3 ->SetState(kFALSE);
      Num4 ->SetState(kFALSE);
      Num5 ->SetState(kFALSE);
      Num6 ->SetState(kFALSE);
      Num7 ->SetState(kFALSE);
      Num8 ->SetState(kFALSE);
      Num9 ->SetState(kFALSE);
      Num10->SetState(kFALSE);
      Num11->SetState(kFALSE);
      Num12->SetState(kFALSE);
      Num13->SetState(kFALSE);
      Num14->SetState(kFALSE);
      NMol1->SetState(kFALSE);
      NMol2->SetState(kFALSE);
      Temp1->SetState(kFALSE);
      Temp2->SetState(kFALSE);
      NumPf1->SetState(kFALSE);
      NumPf2->SetState(kFALSE);
      
    }
    if(ButtonClear->IsEnabled()==false){
      
      for (Int_t cl=0;cl<GetNp(); cl++){
	r0[cl].SetXYZ(0,0,0);
	r[cl].SetXYZ(0,0,0);
	v[cl].SetXYZ(0,0,0);
      }
    }
    
    
  }
  void ButtonPlayF(){ 
    
    Disable();
    Num2 ->SetState(kTRUE);
    Num3 ->SetState(kTRUE);
    Num4 ->SetState(kTRUE);
    Num5 ->SetState(kTRUE);
    Num6 ->SetState(kTRUE);
    Num7 ->SetState(kTRUE);
    Num9 ->SetState(kTRUE);
    Num10->SetState(kTRUE);
    Num11->SetState(kTRUE);
    Num12->SetState(kTRUE);
    Num13->SetState(kTRUE);
    Num14->SetState(kTRUE);
    NMol1->SetState(kTRUE);
    NMol2->SetState(kTRUE);
    Temp1->SetState(kTRUE);
    Temp2->SetState(kTRUE);
    NumPf1->SetState(kTRUE);
    NumPf2->SetState(kTRUE);
    
    t=t0;
    L1->Draw();
    L2->Draw();    
    SimulateF();
  }
  void ButtonClearF(){
    Enable();
    Refresh();
  }
  void ButtonExitF(){  
    gSystem->Exit(0,kTRUE);
    gApplication->Terminate(0);
  }
  void BMode(){}
  void Refresh(){
    
    ButtonSimulate->SetEnabled(kTRUE);
    
    Canvas1->Clear();
    Canvas1->Update();
    Canvas1->Update();
    
    L1->Draw();
    L2->Draw();
    
    Canvas2->Update();
    Canvas2->Clear();
    Canvas2->Update();
    
    Canvas3->Update();
    Canvas3->Clear();
    Canvas3->Update();

    Canvas4->Update();
    Canvas4->Clear();
    Canvas4->Update();

    Canvas5->Update();
    Canvas5->Clear();
    Canvas5->Update();
    
    ButtonExit->SetEnabled(kTRUE);
    ButtonClear->SetEnabled(kFALSE);
    
    //===========================================
    //Configurar los numeros en 0 para el estado inicial
    Num1->SetNumber(0.0);
    Num2->SetNumber(0.0);
    Num3->SetNumber(0.0);
    Num4->SetNumber(0.0);
    Num5->SetNumber(0.0);
    Num6->SetNumber(0.0);
    Num7->SetNumber(0.0);
    Num8->SetNumber(0.0);
    Num9->SetNumber(0.0);
    Num10->SetNumber(0.0);
    Num11->SetNumber(0.0);
    Num12->SetNumber(0.0);
    Num13->SetNumber(0.0);
    Num14->SetNumber(0.0);
    NMol1->SetNumber(0.0);
    NMol2->SetNumber(0.0);
    Temp1->SetNumber(0.0);
    Temp2->SetNumber(0.0);
    NTotal->SetNumber(0.0);
    NumPf1->SetNumber(0.0);
    NumPf2->SetNumber(0.0);
    NTotal->SetState(kTRUE);    
    IsActive=-1;
  
  }
  
};
#endif
