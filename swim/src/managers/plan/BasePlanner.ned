package plasa.managers.plan;

//
// TODO auto-generated module
//
simple BasePlanner like IBasePlanner
{
    parameters:
        bool simulatePlanDelay @mutable = default(true);
        
        @signal[planTime](type="double");
        @statistic[planTime](unit=msec; record=mean,max,vector);

    @class(BasePlanner);
}
