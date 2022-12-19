package plasa.model;


simple AdaptationGoal like IAdaptationGoal
{
    parameters:
        double allowedResponseTime = default(1.0); 
        double serverCost  = default(0.0);
        double optRevenue = default(0.0);
        double utility = default(0.0);


    @class(AdaptationGoal);
}
