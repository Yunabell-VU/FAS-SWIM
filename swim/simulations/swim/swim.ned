//******************************************************************************
// Simulator of Web Infrastructure and Management
// Copyright (c) 2016 Carnegie Mellon University.
// All Rights Reserved.
//  
// THIS SOFTWARE IS PROVIDED "AS IS," WITH NO WARRANTIES WHATSOEVER. CARNEGIE
// MELLON UNIVERSITY EXPRESSLY DISCLAIMS TO THE FULLEST EXTENT PERMITTED BY LAW
// ALL EXPRESS, IMPLIED, AND STATUTORY WARRANTIES, INCLUDING, WITHOUT
// LIMITATION, THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE, AND NON-INFRINGEMENT OF PROPRIETARY RIGHTS.
//  
// Released under a BSD license, please see license.txt for full terms.
// DM-0003883
//******************************************************************************

package plasa.simulations.swim;

import org.omnetpp.queueing.Classifier;
import org.omnetpp.queueing.Router;
import org.omnetpp.queueing.Source;
import org.omnetpp.queueing.Sink;
import org.omnetpp.queueing.SourceOnce;
import plasa.externalControl.AdaptInterface;
import plasa.managers.monitor.SimProbe;
import plasa.managers.monitor.SimpleMonitor;
import plasa.modules.AppServer;
import plasa.modules.ArrivalMonitor;
import plasa.modules.PredictableSource;
import plasa.modules.PredictableRandomSource;
import plasa.model.Model;
import plasa.managers.execution.ExecutionManager;
import plasa.managers.analysis.Analyser;
import plasa.managers.analysis.QualityModel;
import plasa.managers.analysis.MacroOption;
import plasa.managers.analysis.ModelVerifier;
import plasa.model.AdaptationGoal;
import plasa.managers.plan.Planner;


network SWIM
{
    parameters:
        double bootDelay @mutable = default(0);
        double evaluationPeriod @mutable = default(10);
        int initialServers @mutable  = default(1);
        int maxServers @mutable = default(3);
        int numberOfBrownoutLevels @mutable;
        double dimmerMargin @mutable = default(0.0);
        double responseTimeThreshold @mutable @unit(s) = default(1s);
        double maxServiceRate;



        int serverLowerLimit = default(1); 
        int serverUpperLimit = default(3); 
        double dimmerLowerLimit = default(0.1);
        double dimmerUpperLimit = default(1.0);
        int serverStep = default(1);
        double dimmerStep = default(0.1);


        double responseTimeCoefficient = default(0.3);
        double serverCostCoefficient = default(0.4);
        double revenueCoefficient = default(0.3);
        double normalRevenueCoefficient = default(0.8);
        double optRevenueCoefficient = default(1);
        
    submodules:
        sink: Sink {
            @display("p=522,211");
        }
        loadBalancer: Router {
            @display("p=302,159");
            routingAlgorithm = "roundRobin";
        }
        arrivalMonitor: ArrivalMonitor {
            @display("p=187,152");
        }
        source: PredictableSource {
            @display("p=54,165");
        }
        classifier: Classifier {
            @display("p=431,165");
        }
        sinkLow: Sink {
            @display("p=522,142");
        }
        adaptInterface: AdaptInterface {
            @display("p=440,32");
        }
        model: Model {
            @display("p=127,26");
        }
        monitor: SimpleMonitor {
            @display("p=210,26");
        }
        qualityModel: QualityModel {
            @display("p=210,26");
        }
        executionManager: ExecutionManager {
            @display("p=302,26");
        }
        adaptationGoal: AdaptationGoal{
            @display("p=128,26");
        }
        modelVerifier: ModelVerifier{
            @display("p=128,26");
        }
        analyser: Analyser {
            @display("p=302,26");
        }
        macroOption: MacroOption {
            @display("p=302,26");
        }
        planner: Planner {
            @display("p=402,26");
        }
        probe: SimProbe {
            @display("p=141,94");
        }

    connections:
        arrivalMonitor.out --> loadBalancer.in++;
        source.out --> arrivalMonitor.in;
        classifier.out++ --> sink.in++;
        classifier.rest --> sinkLow.in++;
        probe.out++ --> adaptInterface.probe;
        probe.out++ --> monitor.probe;
}
