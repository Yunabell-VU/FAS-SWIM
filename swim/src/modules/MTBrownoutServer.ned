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

package plasa.modules;

//
// TODO auto-generated module
//
simple MTBrownoutServer extends MTServer
{
    parameters:
        @signal[serviceTime](type="double");
        @statistic[serviceTime](record=vector);
        
		double brownoutFactor @mutable = default(0.0);
		volatile double lowFidelityServiceTime @mutable @unit(s); // service time of a low fidelity job
		bool cacheLow @mutable = default(true); // if low fidelity requests are affected by caching effects
		int cacheRequestCount @mutable = default(6750); // how many requests before cache is fully warmed up
		double cacheDelta @mutable = default(0.050); // exec time increase for cold cache
		double cacheDeltaLow @mutable = default(0.0019); // exec time increase for cold cache for low fidelity requests
		double cachePrecision @mutable = default(0.05); // controls shape of exec time decay and how close it gets to fully warmed
		bool cacheClearsWhenReboot @mutable = default(false);
	
	@class(MTBrownoutServer);
}

