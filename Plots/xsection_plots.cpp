
/*
def xsect_vs_mt(  x,  par ):
    # par[0] = m_ref
    # par[1] = sigma(m_ref)
    # par[2] = a_1
    # par[3] = a_2
    sigma= (par[1])*((par[0]/x[0])**4)*(1+par[2]*(x[0]-par[0])/(par[0]) + par[3]*(((x[0]-par[0])/(par[0]))**2) )
    return sigma_mt


def xsect_vs_sqrts(  x,  par ):
    from math import log
    sqrts = x[0] * 1000.
    logE  = log( sqrts/14000. )
    logE2 = logE*logE
    sigma_s = par[0] + sqrts * ( par[1] + par[3] * logE + par[4] * logE2 ) + sqrts * sqrts * ( par[2] + par[5] * logE + par[6] * logE2 )
    return sigma_s
*/
double xsec_mass(double x,double sigma_ref,double mass_ref,double a1,double a2){
    double sigma_mt;
    sigma_mt = sigma_ref*pow((mass_ref/x),4.0)*(1+ a1*((x-mass_ref)/mass_ref) + a2*pow(((x-mass_ref)/mass_ref),2));
    return sigma_mt;

}  


double xsec_roots(double x,double a0,double a1,double a2,double a3,double a4,double a5,double a6){
    double sigma_s;
    x = x*1000.;
    double logE = log(x/14000.);
    double logE2 = pow(logE,2);

    sigma_s = a0 + x*(a1 + a3*logE + a4*logE2) + x*x*(a2 + a5*logE + a6*logE2);
    return sigma_s;

}  

void xsection_plots(){

    double sigma_tt_energy = xsec_roots(13,-18.8,0.0039,4.95e-6,-0.004820,0.00193168,1.68e-6,-1.799e-6);
    double sigma_tt = xsec_mass(172,854.390,172.5,-0.710201,0.152875);
    sigma_tt = xsec_mass(172,843.483,172.5,-0.745047,0.127417);
    cout<<sigma_tt_energy<<endl;


}


/*
   auto c1 = new TCanvas("c1","A Simple Graph with asymmetric error bars",200,10,700,500);
   c1->SetFillColor(42);
   c1->SetGrid();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   const Int_t n = 10;
   Double_t x[n]   = {-0.22, 0.05, 0.25, 0.35, 0.5, 0.61,0.7,0.85,0.89,0.95};
   Double_t y[n]   = {1,2.9,5.6,7.4,9,9.6,8.7,6.3,4.5,1};
   Double_t exl[n] = {.05,.1,.07,.07,.04,.05,.06,.07,.08,.05};
   Double_t eyl[n] = {.8,.7,.6,.5,.4,.4,.5,.6,.7,.8};
   Double_t exh[n] = {.02,.08,.05,.05,.03,.03,.04,.05,.06,.03};
   Double_t eyh[n] = {.6,.5,.4,.3,.2,.2,.3,.4,.5,.6};
   auto gr = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
   gr->SetTitle("TGraphAsymmErrors Example");
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->Draw("ALP");
*/