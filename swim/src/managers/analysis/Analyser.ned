package plasa.managers.analysis;


simple Analyser like IAnalyser
{
    parameters:

        bool simulateAnalysisDelay @mutable = default(true);
        
    @signal[analysisTime](type="double");
    @statistic[analysisTime](unit=msec; record=mean,max,vector);
        
    @signal[analysisDone](type="bool");

    @class(Analyser);
}
