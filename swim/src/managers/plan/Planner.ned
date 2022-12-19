package plasa.managers.plan;

simple Planner like IPlanner
{
    parameters:
        bool simulatePlanDelay @mutable = default(true);
        
        @signal[planTime](type="double");
        @statistic[planTime](unit=msec; record=mean,max,vector);

    @class(Planner);
}
