_allTriggers = allMissionObjects "EmptyDetector";

_objTriggers = [];

//Get objective list

{
_string = str(_x) splitString "_";
if ((_string select 0) == "objective") then {
		_objTriggers pushBack _x;
	};
} forEach _allTriggers;

//Create objectives

{

_string = str(_x) splitString "_";
_type = (_string select 1);
_string deleteRange [0,2];
_name = (_string joinString " ");
_objArea = triggerArea _x;

createMarker [(str(_string joinString "_") + "_zone"),(getPosATL _x)];									//define zone marker
createMarker [(str(_string joinString "_") + "_type"),(getPosATL _x)];									//define type marker
_markerZone = (str(_string joinString "_") + "_zone");
_markerType = (str(_string joinString "_") + "_type");

_markerZone setMarkerShape "ELLIPSE";
_markerZone setMarkerColor "colorOPFOR";
_markerZone setMarkerBrush "FDiagonal";
_markerZone setMarkerSize [_objArea select 0, _objArea select 1];						//create zone marker

switch (_type) do {
case "t": 
	{
	_markerType setMarkerType "n_art";
	_markerType setMarkerColor "colorOPFOR";
	};
case "c": 
	{
	_markerType setMarkerType "n_service";
	_markerType setMarkerDir 270;
	_markerType setMarkerColor "colorOpfor";
	};
case "s": 
	{
	_markerType setMarkerType "loc_Fuelstation";
	_markerType setMarkerColor "colorOpfor";
	};
case "f": 
	{
	_markerType setMarkerType "o_installation";
	};
case "a": 
	{
	_markerType setMarkerType "o_hq";
	};
case "r": 
	{
	_markerType setMarkerType "loc_Transmitter";
	_markerType setMarkerColor "colorOpfor";
	};																				//create type marker based on type
default {"b_unknown"};
};

_markerType setMarkerText _name;

} 
forEach _objTriggers;

//t = town
//c = city
//s = supply
//f = fob
//a = airfield
//r = radiotower
