package plasa.managers.analysis;


simple Analyser like IAnalyser
{
    parameters:
        int serverLowerLimit = default(1); 
        int serverUpperLimit = default(1); 
        double dimmerLowerLimit = default(1.0);
        double dimmerUpperLimit = default(1.0);

        int serverStep = default(1);
        double dimmerStep = default(0.1);

        bool simulateAnalysisDelay @mutable = default(true);
        
    @signal[analysisTime](type="double");
    @statistic[analysisTime](unit=msec; record=mean,max,vector);
        
    @signal[analysisDone](type="bool");

    @class(Analyser);
}
