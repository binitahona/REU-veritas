plot(){
	gSystem.Load("/mnt/sda2/binita/EventDisplay_483/EventDisplay_v4/lib/libVAnaSum.so"); 
        VPlotAnasumHistograms a("file location/file name");
	TCanvas * c = a.plot_radec( 0, -2, -5, 5);
	a.plot_excludedRegions(c);
	a.plot_catalogue(c, "Hipparcos_MAG7_1997.dat"); //Use this to add the excluded source names
	a.plot_significanceDistributions();

        VEnergySpectrum b("file location/file name");
        b.setSignificanceParameters(1, 0.1);
        b.setEnergyBinning(0.15);
        b.setPlottingYaxis(1e-18, 1.e-6);
        b.plot();
        b.plotEventNumbers(0.02);
        b.setSpectralFitRangeLin( 0.2, 10); //This value might need slight adjustments, 10 sometimes lead to a d.o.f=9
        b.setPlottingUpperLimits();
        b.fitEnergySpectrum();
        b.plotFitValues();
        b.printDifferentialFluxes();
}
