Mdemon::~Mdemon(){
  MainFrame->Cleanup();
  delete MainFrame;
}
void Mdemon::Disable(){}
void Mdemon::Enable(){}
//#include "../Exe/include/HeaderGui.h"
void Mdemon::Refresh(){
  Canvas1->Update();
  Canvas1->Clear();
  Canvas1->Update();

  L1->Draw();
  L2->Draw();

  Canvas2->Update();
  Canvas2->Clear();
  Canvas2->Update();

  Canvas3->Update();
  Canvas3->Clear();
  Canvas3->Update();
  
  //  ButtonSimulate->SetText("&Simulate");
  ButtonExit->SetEnabled(kTRUE);
  //  ButtonClear->SetEnabled(kFALSE);

     //===========================================
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
  Int_t jj;
  for (jj = 0;jj<=GetNp();jj++){
    n[jj] = 0;
    r[jj].SetXYZ(0,0,0);
    v[jj].SetXYZ(0,0,0);
    r0[jj].SetXYZ(0,0,0);
    el[jj]= new TEllipse(0,0,0,0,0,0);
    lel[jj]=new TArrow(0,0,0,0,0,0);
    delete el[jj];
    delete lel[jj];
  }
  
  ButtonSimulate->SetEnabled(kTRUE);
  IsActive = -1;
  
}
void Mdemon::ButtonClearF(){
  
  Enable();
  Refresh();
}

void Mdemon::ButtonExitF(){
  cont->TurnOff();
  gApplication->Terminate(0);
}
void Mdemon::ButtonPlayF(){
  if(IsActive == -1){

    GetNp();
    Disable();
    //    ButtonSimulate->SetText("&Pause");
    ButtonSimulate->SetEnabled(kFALSE);
    // ButtonClear->SetEnabled(kTRUE);
    //    Num1 ->SetState(kFALSE);
    Num2 ->SetState(kTRUE);
    Num3 ->SetState(kTRUE);
    Num4 ->SetState(kTRUE);
    Num5 ->SetState(kTRUE);
    Num6 ->SetState(kTRUE);
    Num7 ->SetState(kTRUE);
    // Num8 ->SetState(kFALSE);
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

    cont->TurnOn();
    t=t0;
    // Volume1 = 0.5;
    //Volume2 = 0.5;
    L1->Draw();
    L2->Draw();
    IsActive = 0;
    
}
  
  if (IsActive==0){


}
}
void Mdemon::BMode(){
  gApplication->Terminate(0);
  
}
    void Mdemon::SimulateF(){

      
      
      if(GetNp()<=3000){
		
	
	//=================================
	//=======Aqui iban las posiciones
	cont->Start(200000, kTRUE);// 20 seconds single-shot
	cont->SetCommand("gSystem->ProccessEvents()");
	//======================================    
	i=0;
	fx=0;
	fy=0;
	Int_t hx=0;
	Int_t hy=0;
	
	
	ofstream file;
	file.open("dos.txt");
	
	
	//=================================
	while(i < GetNp() ){
	  gSystem->ProcessEvents();
	  gClient->HandleInput();
	  
	  Values *b= new Values();
	  n[i] = 0;
	  r0[i].SetXYZ(b->X0(),b->Y0(),0);
	  r[i].SetXYZ(b->X0(),b->Y0(),0);
	  v[i].SetXYZ(b->VX0(),b->VY0(),0);
	  //      cout << v[i].Mag() << endl;
	  file << v[i].Mag() << endl;
      
	  if(r0[i].X() < xMax/Div )
	    //if(( r0[i].X() <=(xMax/Div + bWidth)) && (r0[i].X() >  xMax/Div)  )
	    {
	      hx=hx+1;
	      cout<<i<<" "<< v[i].Mag()<<endl;
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
	//    cout<<hx<<" "<<hy<<endl;
    file.close();

	//===================================================================================================
	//===================================================================================================
	//===================================================================================================
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
      
      hmodel = new TFormula("MB"," ( 4*TMath::Pi()*100000 *(pow(x,2)+pow(y,2)+pow(z,2)  )* exp (-1*(pow(x,2)+pow(y,2)+pow(z,2) )) / 1 )");
      maxbolt = new TF3("Maxwell-Boltzmann","MB",-10,10,-10,10,-10,10);
      
      TH3F *t1 = new TH3F("t1","gaussian",100,-5,5,100,-5,5,100,-5,5); 
      TH1F *speed = new TH1F(" ","Maxwell-Boltzman Distribution Histogram Left-Side",100,0,2500);
      TH1F *w = new TH1F("w1","Speed",100,0,5);
      t1->FillRandom("Maxwell-Boltzmann",1000000);
      //=====================================================
      for(Int_t i=0; i< fx; i++)
{

      t1->GetRandom3(v1,v2,v3);
      Float_t vel = 600*sqrt(pow(v1,2)+pow(v2,2)+pow(v3,2))+100;
      speed->Fill(vel);
      
      maxbolt->GetRandom3(w1,w2,w3);
      vel = sqrt(pow(w1,2)+pow(w2,2)+pow(w3,2));
      w->Fill(vel+1); //Shifts w distribution to make differences obvious
      
 }

      maxbolt->SetNpx(200);
      maxbolt->SetNpy(200);
      maxbolt->SetNpz(200);
      speed->Draw();
      w->Draw("same");	
      Canvas2->cd();
      Canvas2->Update();
      Canvas2->Modified();
      //      cout<<"Este es el valor medio"<<speed->GetMean()<<endl;
      //===================================================================================================
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
      
      hmodel2 = new TFormula("MB"," ( 4*TMath::Pi()*100000 *(pow(x,2)+pow(y,2)+pow(z,2)  )* exp (-1*(pow(x,2)+pow(y,2)+pow(z,2) )) / 1 )");
      maxbolt2 = new TF3("Maxwell-Boltzmann","MB",-10,10,-10,10,-10,10);
      
      TH3F *tt1 = new TH3F("t1","gaussian",100,-5,5,100,-5,5,100,-5,5); 
      TH1F *sspeed = new TH1F(" ","Maxwell-Boltzman Distribution Histogram Rigth-Side",100,0,2500);
      TH1F *ww = new TH1F("w1","Speed",100,0,5);
      tt1->FillRandom("Maxwell-Boltzmann",1000000);
      //=====================================================
      for(Int_t i=0; i< fy; i++)
	{
	  
	  tt1->GetRandom3(v1,v2,v3);
	  Float_t vvel = 100*sqrt(pow(v1,2)+pow(v2,2)+pow(v3,2))+100;
	  sspeed->Fill(vvel);
	  
	  maxbolt2->GetRandom3(w1,w2,w3);
	  vvel = sqrt(pow(w1,2)+pow(w2,2)+pow(w3,2));
	  ww->Fill(vvel+1); //Shifts w distribution to make differences obvious
	  
	}
      
      maxbolt2->SetNpx(200);
      maxbolt2->SetNpy(200);
      maxbolt2->SetNpz(200);
      sspeed->Draw();
      ww->Draw("same");	
      Canvas3->cd();
      Canvas3->Update();
      Canvas3->Modified();
      //===================================================================================================
      //===================================================================================================

    


    
	//=======================================================
	//Values to compute in the code
	//=======================================================
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
	//dW=dS*Tmp;
	temp1 = ((0.5*m*433)/(TMath::K()));;
	temp2 = ((0.5*m* speed->GetMean()  )/(TMath::K()));; 
	//	cout<<vel<<" que chimba"<<temp2<<endl;
	Tmp1 = ((0.5*m*533)/(TMath::K()));
	Tmp2 = ((0.5*m*sspeed->GetMean() )/(TMath::K()));

	
	Pini1=     hx*TMath::K()*temp1/V;
	Pini2=     hy*TMath::K()*temp2/V;
	Pfin1=     fx*TMath::K()*Tmp1/V;
	Pfin2=     fy*TMath::K()*Tmp2/V;
	
	Ent    = fx*TMath::K()*( log((temp1)/(temp2))+log((Pini1) / (Pini2)));
	Entdos = fy*TMath::K()*(log((Tmp1)/(Tmp2))+log((Pfin1)/(Pfin2)) );
	

	U1=hx*temp1*TMath::K();
	U2=hy*temp2*TMath::K();
	U3=hx*Tmp1*TMath::K();;
	U4=hx*Tmp2*TMath::K();;
	
	
	//	cout<<"el valor de Ent es "<<" "<<Ent<<endl; 	 
	 //cout<<dW<<endl;

	//================================================================
	//==========Graph T-s One=========================================
	//================================================================
	//	Canvas4 -> Divide(2,1);
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

	    // DS=fx*TMath::K()*(log(KK/(KK+2))+log(KK/(KK+4)));
	   
	    //cout<<KK<<" "<<DS<<endl;
	    // DS=fx*TMath::K()*( pow(log(KK), (5/2))+log(KK));
	    dts->SetPoint(NN,Ent,KK);
	    dts->SetMarkerColor(2);
	    //cout<<KK<<endl;
	    NN++;
	  }
	dts->SetTitle(" T-S Diagram Left Side");
	dts->GetXaxis()->SetTitle("S(J/K)");
	dts->SetLineWidth(2);
	dts->GetYaxis()->SetTitle("T(K)");
	//	Canvas4->GetFrame()->SetFillColor(2);
	//Canvas4->GetFrame()->SetBorderSize(2);
	
	
	dts->Draw("APL");
	
	Canvas4->cd();
	Canvas4->Update();
	Canvas4->Modified();
	//================================================================
	//==========Graph T-s Two=========================================
	//================================================================

	//	Canvas4 -> Divide(2,1);
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
	    
	    //	    DS2=fy*TMath::K()*(log(LL/(LL+2))+log(LL/(LL+4)));
	    Entdos = fy*TMath::K()*(log((Tmp1)/(LL))+log((Pfin1)/(LL)) );

	    dts2->SetPoint(MM,Entdos,LL);
	    dts2->SetMarkerColor(2);
	    //cout<<KK<<endl;
	    MM++;
	  }
	dts2->SetTitle("T-S Diagram Rigth Side");
	dts2->GetXaxis()->SetTitle("S(J/K)");
	dts2->SetLineWidth(2);
	dts2->GetYaxis()->SetTitle("T(K)");
	//Canvas4->GetFrame()->SetFillColor(2);
	//Canvas4->GetFrame()->SetBorderSize(2);
	
	
	dts2->Draw("APL");
	
	Canvas5->cd();
	Canvas5->Update();
	Canvas5->Modified();
	Canvas5->Resize();
	
	//================================================================
	//====================NumberInputsOutputs=========================
	//================================================================

	Num1->SetNumber(hx);
	//	Num1->SetState(kFALSE);
	
	Num2->SetNumber(Pini1);
	
	Num3->SetNumber(temp1);
	Num4->SetNumber(V);
	Num5->SetNumber(U1);
	Num6->SetNumber(U3);
	Num7->SetNumber(Ent);
	Num8->SetNumber(hy);
	//	 Num8->SetState(kFALSE);
	
	Num9->SetNumber(Pini1);
	Num10->SetNumber(Tmp1);
	Num11->SetNumber(V);
	Num12->SetNumber(U2);
	Num13->SetNumber(U4);
	Num14->SetNumber(Entdos);
	
	
	//cout<<"lentas"<<x<<endl;
	//cout<<"rapidas"<<y<<endl;
	NMol1->SetNumber(fx);
	NMol2->SetNumber(fy);
	Temp1->SetNumber(temp2);
	Temp2->SetNumber(Tmp2);
	NumPf1->SetNumber(Pfin1);
	NumPf2->SetNumber(Pfin2);
	
	
    //=======================================================
    //Finding positions out,Simulation, drawing molecules.
    //=======================================================
	 while(n>=0){
	   gSystem->ProcessEvents();
	   //  gClient->HandleInput();
      //==============================================
      //hacer un "while" para las moleculas
      //Making a "while" for  molecules
      //==============================================
	   ii=0;
      while(ii < GetNp()){
	gSystem->ProcessEvents();
	//gClient->HandleInput();
	n[ii]++;
	//=========================================================
	//el tiempo va corriendo de acuerdo al numero de moleculas
	//time runs depending on the number of molecules.
	//=========================================================
	if(GetNp()<=500){
	  dt=0.001;
	}
	else {
	  dt=0.001;
	}
	t = t0 + n[ii]*dt;
	r[ii].SetX(r0[ii].X() + v[ii].X()*t);
	r[ii].SetY(r0[ii].Y() + v[ii].Y()*t);

	el[ii] = new TEllipse(r[ii].X(),r[ii].Y(), r1, r1, 0, 360, 0);
	
	lel[ii] = new TArrow(r[ii].X(),r[ii].Y(),r[ii].X() + v[ii].X()*scl*dt,r[ii].Y() + v[ii].Y()*scl*dt,arrSize,"|>");
	//======================================================================================================
	//If the magnitude of the vector is less than vMean=2.5 color them
	//Si la magnitud del vector es menor que vMean=2.5 pintelas de (2) sino de (3)
	//MAG COMPUTES THE RADIO IN SPHERICAL COORDINATES/ EL MAG ME CALCULA EL RADIO EN COORDENADAS ESFERICAS
	//How many molecules there are.
      //======================================================================================================

      if(v[ii].Mag() < vMean){
	 gSystem->ProcessEvents();
	   // gClient->HandleInput();
	   el[ii]->SetFillColor(2);
	   lel[ii]->SetLineColor(2);
	
      }
      else{
	gSystem->ProcessEvents();
	//gClient->HandleInput();
	el[ii]->SetFillColor(3);
       	lel[ii]->SetFillColor(3);
	//y=y+1;
	//cout<<"rapidass"<<y<<endl;
      }
      //IF X COMPONENT IS HIGHER.GREATER THAN 1/2-0.004 AND LESS THAN 1/2  /SI LA COMPONENTE EN X ES MAYOR QUE 1/2 - 0.004 Y MENOR O IGUAL QUE 1/2
      //IF THE VELOCITY IS HIGHER THAN 0/ SI LA VELOCIDAD ES MAYOR QUE 0
      //LEFT slow particles
      if((r[ii].X() > (xMax/Div - bWidth)) && (r[ii].X() <= xMax/Div)){
	gSystem->ProcessEvents();
	//gClient->HandleInput();
	
	if(v[ii].X() > 0){
	  gSystem->ProcessEvents();
	   // gClient->HandleInput();
	   
	   if(v[ii].Mag() < vMean){
	     gSystem->ProcessEvents();
	     //gClient->HandleInput();
	     
	     v[ii].SetX(-v[ii].X());
	     r0[ii].SetX(xMax/Div);
	     r0[ii].SetY(r[ii].Y());
	     n[ii] = 0;
	     }

	 }      
       }

       //IF X COMPONENT IS LESS OR EQUAL THAN 1/2+0.004 AND HIGHER THAN 1/2 / SI LA COMPONENTE EN X ES MENOR O IGUAL QUE 1/2 +0.004 Y MAYOR QUE 1/2
       
       //IF THE VELOCITY IS LESS THAN 0/  SI LA VELOCIDAD ES MENOR QUE 0
       
       //RIGTH slow particles

       
       if((r[ii].X() <= (xMax/Div + bWidth)) && (r[ii].X() > xMax/Div)){
	 gSystem->ProcessEvents();
	 //gClient->HandleInput();
	 
	 if(v[ii].X() < 0){
	   gSystem->ProcessEvents();
	   //gClient->HandleInput();
	   
	   if(v[ii].Mag() >= vMean){
	     gSystem->ProcessEvents();
	     //gClient->HandleInput();
	     
	     v[ii].SetX(-v[ii].X());
	     r0[ii].SetX(xMax/Div);
	     r0[ii].SetY(r[ii].Y());
	     n[ii] = 0;
	   }
	 }      
       }
       //si la magnitud de x es mayor que xmax haga lo siguiente igual para los demas 
       if(r[ii].X() > xMax){
	 gSystem->ProcessEvents();
	 //gClient->HandleInput();
	 
	 v[ii].SetX(-v[ii].X());
	 r0[ii].SetX(xMax);
	 r0[ii].SetY(r[ii].Y());
	 n[ii] = 0;
       }

       
       
       if(r[ii].X() < xMin/2.0){
	 gSystem->ProcessEvents();
	 //gClient->HandleInput();
	 
	 v[ii].SetX(-v[ii].X());
	 r0[ii].SetX(xMin);
	 r0[ii].SetY(r[ii].Y());
	 n[ii] = 0;
       }
       if(r[ii].Y() > yMax){
	 gSystem->ProcessEvents();
	 //gClient->HandleInput();
	 
	 v[ii].SetY(-v[ii].Y());
	 r0[ii].SetY(yMax);
	 r0[ii].SetX(r[ii].X());
	 n[ii] = 0;
       }

       
       if(r[ii].Y() < yMin){
	 gSystem->ProcessEvents();
	 // gClient->HandleInput();
	 
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
       
       
       //=======================================================
    }
       
    //=======================================================
    //Updating Canvas
    //=======================================================
      if(ii%100 == 0)
	{
	  Canvas1->cd();
	  Canvas1->Update();
	  Canvas1->Modified();
	}
      
    
    //=======================================================
    //deleting
    //=======================================================
      for(int iiii = 0; iiii < GetNp(); iiii++){
	delete el[iiii];
	delete lel[iiii];
	      }
      //=======================================================
  

      }

	 
	 

  
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////When np is higher than 200 //////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  else{
   

  
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
    }
